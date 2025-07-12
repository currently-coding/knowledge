#include <string>
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <fstream>

enum class Option
{
    a,
    q,
    h,
    unknown,
};

class TagDB
{
private:
    // attributes
    std::string filepath;
    std::pair<Option, std::vector<std::string>> arguments; // stores arguments with respective values

    // functions
    std::vector<std::string> tag_to_vector(std::string &tags);
    Option string_to_option(std::string option_str);

public:
    TagDB(std::string filepath, int argc, const char *argv[]);

    std::pair<Option, std::vector<std::string>> create_pair(int argc, const char *argv[]);
    void help();
    void add(std::string tags, std::string data);
    void query(std::string tag);
    void process();
};

TagDB::TagDB(std::string filepath, int argc, const char *argv[]) : filepath(filepath)

{
    // put all logic here
    arguments = create_pair(argc, argv);
    process();
};

std::vector<std::string> TagDB::tag_to_vector(std::string &tags)
{
    int start(0), length(0);
    std::vector<std::string> result;

    int size = tags.size();
    for (int i(0); i <= size; i++)
    {
        if (tags[i] == ',' || i == size)
        {
            result.push_back(tags.substr(start, length));
            start = i + 1;
            length = 0;
        }
        else
        {
            length++;
        }
    }
    return result;
}

void TagDB::add(std::string tags, std::string data)
{
    std::cout << "Adding new entry to database..." << std::endl;
    std::cout << "Tags: " << tags << std::endl;
    std::cout << "Data: " << data << std::endl;
    std::ofstream ofile(filepath, std::ios::app);
    if (!ofile.is_open())
    {
        std::cerr << "Unable to open file. add()" << std::endl;
        return;
    }
    ofile << tags << " " << data << std::endl;
    ofile.close();
}

void TagDB::query(std::string search_tag)
{
    std::ifstream ifile(filepath);
    if (!ifile.is_open())
    {
        std::cerr << "Unable to open file for reading. query()" << std::endl;
        return;
    }

    std::string line;
    std::string data_tag;
    std::vector<std::vector<std::string>> result;

    while (std::getline(ifile, line))
    {
        std::istringstream iss(line);
        std::string data;
        iss >> data_tag;
        std::vector<std::string> line_data;
        if (data_tag.find(search_tag) != std::string::npos)
        {
            while (iss >> data)
            {
                line_data.push_back(data);
            }
        }
        result.push_back(line_data);
    }
    std::cout << "Searching for data with tag '" << search_tag << "'..." << std::endl;
    for (const auto &outer : result)
    {
        for (const auto &inner : outer)
        {
            std::cout << inner << " ";
        }
        std::cout << std::endl;
    }
}

void TagDB::help()
{
    const std::string help =
        "Usage: ./tagdb option arguments...\n"
        "A simple tag database\n"
        "-h, --help Show this help text\n"
        "-a, --add <tag(,tag)*> <content> Associates provided tag(s) with content\n"
        "-q, --query <tag> Prints all contents associated with provided tag\n";
    std::cout << help << std::endl;
};

Option TagDB::string_to_option(std::string option_str)
{
    Option option;
    if (option_str == "-a" || option_str == "--add")
        option = Option::a;
    else if (option_str == "-q" || option_str == "--query")
        option = Option::q;
    else if (option_str == "-h" || option_str == "--help")
        option = Option::h;
    else
    {
        std::cerr << "Unknown input data -> can't convert to Option type" << std::endl;
    }
    return option;
}

std::pair<Option, std::vector<std::string>> TagDB::create_pair(int argc, const char *argv[])
{
    // remove first entry
    std::string option_str = argv[1];
    Option option = string_to_option(option_str);
    std::string input("");

    if (option == Option::a)
    {
        // A: <Option, {<tags>, <data>}>
        std::vector<std::string> data(argv + 3, argv + argc);
        for (auto &it : data)
        {
            input += it;
            input += " ";
        }
        input.pop_back(); // remove trailing whitespace
        std::vector<std::string> result{std::string(argv[2]), input};
        return std::make_pair(option, result);
    }
    else if (option == Option::q)
    {
        // Q: <Option, {<tag>}>
        std::vector<std::string> result{argv[2]};
        return std::make_pair(option, result);
    }
    else
    {
        // H: <Option, {<>}>
        std::vector<std::string> result{};
        return std::make_pair(option, result);
    }
}

void TagDB::process()
{
    Option option = arguments.first;
    if (option == Option::a)
    {
        add(arguments.second[0], arguments.second[1]); // add error handling
    }
    else if (option == Option::q)
    {
        query(arguments.second[0]);
    }
    else
    {
        help();
    }
}

int main(int argc, const char *argv[])
{
    int argc2 = 2;
    const char *argv2[]{"tagdb", "-h"};
    TagDB db1("database.txt", argc, argv);

    return 0;
}

// database entry format: database.txt
// <tag> <data>
