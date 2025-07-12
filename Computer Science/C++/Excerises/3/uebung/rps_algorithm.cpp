#include <iostream>
#include <ctime>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <map>

enum struct Result
{
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW,
    UNDEFINED,
};

enum struct Item
{
    rock,
    paper,
    scissors,
};

struct Score
{
    int player1;
    int player2;

    void final_result(int mode)
    {
        using namespace std;

        cout << "*** Final Score: ";

        short result = player1 - player2;

        if (result == 0)
        {
            cout << "DRAW";
        }
        else if (result > 0)
        {
            cout << "Player1 wins";
        }
        else if (result < 0)
        {
            if (mode == 1)
            {
                cout << "Computer wins";
            }
            else
            {
                cout << "Player2 wins";
            }
        }
        cout << " ***" << endl;
    }
};

struct Move
{
    Item player_1_move;
    Item player_2_move;

    int to_int(int player)
    {
        switch (player)
        {
        case 1:
            switch (player_1_move)
            {
            case Item::rock:
                return 1;
            case Item::paper:
                return 2;
            case Item::scissors:
                return 3;
            default:
                break;
            }
        case 2:
            switch (player_2_move)
            {
            case Item::rock:
                return 1;
            case Item::paper:
                return 2;
            case Item::scissors:
                return 3;
            default:
                break;
            }
        default:
            throw std::runtime_error("Error in `move.to_int(int player)`. Player unknown(x != 1, x != 2)");
        }
    }
};

struct Game
{
    Move move;

    Result res;

    Score score;

    int round_number;

    void output_result(Score *score)
    {
        switch (res)
        {
        case Result::DRAW:
            std::cout << "\nResult: Draw...\n\n";
            score->player1++;
            score->player2++;
            break;
        case Result::PLAYER_1_WINS:
            std::cout << "\nResult: Player 1 won\n\n";
            score->player1++;
            break;
        case Result::PLAYER_2_WINS:
            std::cout << "\nResult: Player 2 won\n\n";
            score->player2++;
            break;
        default:
            throw "\n\nError in function `main()` Unknown Game Result.";
        }
        // std::cout << "Score: " << score->player1 << ":" << score->player2 << "\n" << std::endl; // uncomment to see score during game
    }

    Result simulate_move()
    {
        if (move.player_1_move == move.player_2_move)
        {
            return Result::DRAW;
        }
        switch (move.player_1_move)
        {
        case Item::rock:
            if (move.player_2_move == Item::scissors)
            {
                return Result::PLAYER_1_WINS;
            }
            else
            {
                return Result::PLAYER_2_WINS;
            }
            break;
        case Item::scissors:
            if (move.player_2_move == Item::paper)
            {
                return Result::PLAYER_1_WINS;
            }
            else
            {
                return Result::PLAYER_2_WINS;
            }
            break;
        case Item::paper:
            if (move.player_2_move == Item::rock)
            {
                return Result::PLAYER_1_WINS;
            }
            else
            {
                return Result::PLAYER_2_WINS;
            }
        default:
            throw std::runtime_error("Error in function `play_items(i1, i2)`: Result unknown.");
        }
        return Result::DRAW; // FIX: Shouldn't be needed
    }
};

struct MoveProbability
{
    int move;
    float probability;
};

struct Probabilities
{
    // map result to map of computer move to vector of human moves
    std::map<Result, std::map<int, std::vector<MoveProbability>>> probabilties;

    std::map<Result, std::map<int, std::map<int, int>>> values; // holds total number of values for each move in each category

    void add(Game game)
    {
        int human_move = game.move.to_int(1);
        int computer_move = game.move.to_int(2);
        Result result = game.res;

        int result_number = 0;

        // incrementing values maps
        values[result][computer_move][human_move]++;

        this->update(human_move, computer_move, result);
    }

    void update(int human_move, int computer_move, Result result)
    {
        // Updates Probabilities using the values map

        // Human Move Probability calculation: How many moves in this category and this computer move are followed by this specific human move ? Divide that by the total number of moves within this category
        int group_total(0);
        int human_move_total(0);
        int human_plus_one_move_total(0);
        int human_plus_two_move_total(0);

        for (auto &entry : values[result][computer_move])
        {
            group_total += entry.second;
            if (!group_total) continue; // avoid ZeroDivisionError

            if (entry.first == human_move)
            {
                human_move_total = entry.second;
            }
            else if (entry.first == (human_move + 1) % 3)
            {
                human_plus_one_move_total = entry.second;
            }
            else if (entry.first == (human_move + 2) % 3)
            {
                human_plus_two_move_total = entry.second;
            }
        }

        for (auto &move : probabilties[result][computer_move])
        {
            if (move.move == human_move)
            {
                move.probability = human_move_total / group_total;
            }
            else if (move.move == human_plus_one_move_total)
            {
                move.probability = human_plus_one_move_total / group_total;
            }
            else if (move.move == human_plus_two_move_total)
            {
                move.probability = human_plus_two_move_total / group_total;
            }
        }
    }
};

void printGameData(std::vector<Game> &game_data)
{
    for (auto &game : game_data)
    {
        int humanMove = game.move.to_int(1);
        int computerMove = game.move.to_int(2);
        int result = 0;

        if (game.res == Result::PLAYER_1_WINS)
        {
            result = 1; // Human wins
        }
        else if (game.res == Result::PLAYER_2_WINS)
        {
            result = -1; // Computer wins
        }

        std::cout << "(" << computerMove << ", " << humanMove << ", " << result << "), ";
    }
    std::cout << std::endl;
};

void printMoveProbability(const MoveProbability &moveProbability)
{
    std::cout << "Human Response: " << moveProbability.move << ", Probability: " << moveProbability.probability << std::endl;
}

void printProbabilities(const Probabilities &probabilities)
{
    for (const auto &resultEntry : probabilities.probabilties)
    {
        Result result = resultEntry.first;
        std::cout << "Result: ";
        switch (result)
        {
        case Result::PLAYER_1_WINS:
            std::cout << "Human Win";
            break;
        case Result::PLAYER_2_WINS:
            std::cout << "Computer win";
            break;
        case Result::DRAW:
            std::cout << "Draw";
            break;
        case Result::UNDEFINED:
            std::cout << "Undefined";
            break;
        }
        std::cout << std::endl;

        for (const auto &computerMoveEntry : resultEntry.second)
        {
            int computerMove = computerMoveEntry.first;
            std::cout << "Computer Move: " << computerMove << std::endl;

            for (const auto &moveProbability : computerMoveEntry.second)
            {
                printMoveProbability(moveProbability);
            }
        }
    }
}

Item beats(Item to_beat) {
    switch (to_beat) {
        case Item::paper:
            return Item::scissors;
        case Item::rock:
            return Item::paper;
        case Item::scissors:
            return Item::rock;
        default:
            throw std::runtime_error("Unknown Item to convert");
    }
}


Item int_to_item(int num)
{
    switch (num)
    {
    case 1:
        std::cout << "ROCK.\n";
        return Item::rock;
    case 2:
        std::cout << "PAPER.\n";
        return Item::paper;
    case 3:
        std::cout << "SCISSORS.\n";
        return Item::scissors;
    default:
        throw std::runtime_error("Error in function `int_to_item(num)`: Item unknown.");
    }
}

Item genetic_algorithm()
{
    return Item::paper;
}

Item calculate_based_on_prior_moves(std::vector<Game> game_data, Probabilities& probabilities)
{
    using namespace std;

    // read through game data - store last computer move and last human move;
    int last_computer_move = game_data[game_data.size()].move.to_int(2);
    int last_human_move = game_data[game_data.size()].move.to_int(1);
    Result last_result = game_data[game_data.size()].res;

    vector<MoveProbability> possible_moves = probabilities.probabilties[last_result][last_computer_move];

    float highest_probability = 0.0f;
    int next_human_move(0);

    for (auto& entry : possible_moves) {
        if (entry.probability >= highest_probability) {
            highest_probability = entry.probability;
            next_human_move = entry.move;
        }
    }

    Item next_human_move_item = int_to_item(next_human_move);
    Item next_computer_move = beats(next_human_move_item);

    return next_computer_move;

    return Item::paper;
}

Item read_item(int player)
{
    using namespace std;

    int choice(0);

    cout << "\nPlayer " << player << ": Rock(1), Paper(2), Scissors(3) ... Shoot: ";

    cin >> choice;

    cout << "Player " << player << " plays ";

    Item item = int_to_item(choice);

    return item;
}

Item random_item()
{
    int r = rand() % 3; // random value (0, 1 or 2)
    std::cout << "\nComputer plays ";
    return int_to_item(++r);
}

int choose_gamemode()
{
    using namespace std;
    int mode(0);
    cout << "Welcome!\n\nPlease choose a gamemode:\n(1) Human vs Computer\n(2) Human vs Human\n\nChoice: ";
    cin >> mode;
    return mode;
}

int get_rounds()
{
    using namespace std;
    int num_rounds(0);
    cout << "How many rounds do you wish to play ? Rounds: ";
    cin >> num_rounds;
    return num_rounds;
}

int main()
{
    srand(time(NULL)); // initialize the random generator

    int mode = 0; // 1 = ComputerVsHuman, 2 = HumanVsHuman
    Score score = {0, 0};
    int algorithm = 0;
    std::vector<Score> score_data;
    Probabilities probabilities{{Result::PLAYER_1_WINS, {0, {{0, 0.33}, {1, 0.33}, {2, 0.33}}},{1, {{0, 0.33}, {1, 0.33}, {2, 0.33}}}, {2, {{0, 0.33}, {1, 0.33}, {2, 0.33}}}}, {Result::PLAYER_2_WINS, {0, {{0, 0.33}, {1, 0.33}, {2, 0.33}}},{1, {{0, 0.33}, {1, 0.33}, {2, 0.33}}}, {2, {{0, 0.33}, {1, 0.33}, {2, 0.33}}}}, {Result::DRAW, {0, {{0, 0.33}, {1, 0.33}, {2, 0.33}},{1, {{0, 0.33}, {1, 0.33}, {2, 0.33}}}, {2, {{0, 0.33}, {1, 0.33}, {2, 0.33}}}}}};



    mode = choose_gamemode();

    if (mode < 1 || mode > 2)
    {
        throw std::runtime_error("Error in function `main()`: Unknown Mode.");
    }

    int num_rounds = get_rounds();

    for (int rounds_played(1); rounds_played <= num_rounds; rounds_played++)
    { // repeat for every round
        std::cout << "\n*c** Round " << rounds_played << " ***" << std::endl;

        Item i1 = read_item(1);
        Item i2 = (mode == 2) ? read_item(2) : (algorithm == 0) ? random_item() : (algorithm == 1) ? calculate_based_on_prior_moves(game_data, probabilities) : genetic_algorithm();

        // Create game object and calculate everything
        Game game = {Move{i1, i2}, Result::UNDEFINED, score, rounds_played};

        game.res = game.simulate_move();
        game.output_result(&score);
        game.score = score;

        // Add struct with all data to vector (modify vector declaration)
        probabilities.add(game);
        std::cout << "\n\nData:" << std::endl;
        printProbabilities(probabilities);
    }
    score.final_result(mode);
}
// TODO:
// fix printProbabtilities fn
    
// use that data to feed the calculate next move fn