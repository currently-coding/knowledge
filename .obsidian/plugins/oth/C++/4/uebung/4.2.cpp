#include <string>
#include <cmath>
#include <iostream>

struct SequenceGenerator {
    int min;
    int max;
    int step;
    int current;
    int (*transform)(int x) = nullptr;

    SequenceGenerator(int mini, int maxi, int stepi) : min(mini), max(maxi), step(stepi), current(mini) {}

    int next() {
        int result = current;
        current += step;
        return result; // Return the current value before transformation
    }

    bool has_next() {
        return current <= max;
    }
};

inline int square(int x) { return x*x; }

int cube(int x) { 
    if (x >= 0) { 
        return std::pow(x, 3);
    } else {
        return (-1 * std::pow((x*-1), 3));
    }
}

int sign(int x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

int (*arg_to_func(const std::string& option))(int) {
    if (option == "cube") {
        return cube;
    } else if (option == "square") {
        return square;
    } else {
        return sign;
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 5) { 
        std::cout << "Invalid argc";
        return 1; 
    }

    int min = std::stoi(argv[1]);
    int max = std::stoi(argv[2]);
    int step = std::stoi(argv[3]);
    std::string input = argv[4];

    int (*function)(int) = arg_to_func(input);
    SequenceGenerator seq(min, max, step);

    while (seq.has_next()) {
        std::cout << function(seq.next()) << " ";
    }
    std::cout << std::endl;

    return 0;
}
