#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

void processs(istream &input, ostream &output)
{
    unsigned short quantity;
    string product;
    float price;
    float subtotal;
    float total(0.0F);

    string line;
    while (getline(input, line))
    {
        istringstream iss(line);
        if (iss >> quantity >> product >> price)
        {
            subtotal = price * quantity;
            total += subtotal;
            output << quantity << " " << product << " kosten insgesamt " << subtotal << endl;
        }
        else
        {
            cerr << "Unable to parse line" << line << endl;
        }
    }
    output << "--------------\nKosten insgesamt: " << total << endl;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "Invalid number of arguments. Correct: 1, Given: " << argc - 1 << endl;
        return 1;
    }
    std::string filepath = argv[1];

    ifstream file(filepath);

    if (!file)
    {
        cerr << "File Not Found." << filepath << endl;
        return 2;
    }
    processs(file, cout);

    return 0;
}
