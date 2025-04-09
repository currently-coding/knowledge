#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

int main(int argc, char const *argv[])
{

    std::ifstream file("testfile.txt");
    std::string line;
    std::getline(file, line);

    std::istringstream iss(line);
    std::string one;
    std::string two;
    iss >> one >> two;
    std::cout << one << two << std::endl;

    return 0;
}
