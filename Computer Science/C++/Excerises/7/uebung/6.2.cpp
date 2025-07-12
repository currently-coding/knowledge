#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include <string>

std::map<std::string, std::string> file_to_map(std::ifstream &in_file)
{
    std::map<std::string, std::string> result;
    std::string line;
    while (std::getline(in_file, line))
    {
        std::istringstream iss(line);
        std::string key, value;
        if (!(iss >> key >> value))
        {
            std::cerr << "file_to_map(ifstream &in_file) -> Unable to parse lines." << std::endl;
        }
        result[key] = value;
    }
    return result;
}

std::string translate(std::map<std::string, std::string> dict, std::string text)
{
    std::string out;
    std::istringstream iss(text);
    std::string word;

    while (iss)
    {
        iss >> word;
        if (dict.find(word) != dict.end())
        {
            out += dict.at(word);
            std::cout << "1: " << dict.at(word) << std::endl;
        }
        else
        {
            out += word;
            std::cout << "2: " << word << std::endl;
        }
        out += " ";
    }
    if (!out.empty())
    {
        out.pop_back();
    }
    return out;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./" << argv[0] << " <dictionary> < <file_to_translate>" << std::endl;
        return 1;
    }

    std::ifstream in_file_dict(argv[1]);
    if (!in_file_dict)
    {
        std::cerr << "Error opening dictionary file: " << argv[1] << std::endl;
        return 1;
    }

    std::string text;
    std::string line;
    while (std::getline(std::cin, line))
    {
        text += line + '\n';
    }

    std::map<std::string, std::string> dict = file_to_map(in_file_dict);
    std::string result = translate(dict, text);
    std::cout << result << std::endl;

    in_file_dict.close();

    return 0;
}