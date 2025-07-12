#include <iostream>
#include <cmath>

enum struct Operator {
    addition,
    subtraction,
    multiplication,
    division,
    potenzieren,
    error
};

Operator string_to_op(const std::string& s) {
    // using enum Operator;
    if (s == "+") {return Operator::addition;}
    else if (s == "-") {return Operator::subtraction;}
    else if (s == "x") {return Operator::multiplication;}
    else if (s == "/") {return Operator::division;}
    else if (s == "^") {return Operator::potenzieren;}
    else {std::cout << "Invalid Operator: " << s << std::endl; return Operator::error;}
}

double calculate(double operand1, Operator op, double operand2) {
    switch (op) {
        case Operator::addition:
            return operand1 + operand2;
        case Operator::subtraction:
            return operand1 - operand2;
        case Operator::division:
            return operand1 / operand2;
        case Operator::multiplication:
            return operand1 * operand2;
        case Operator::potenzieren:
            return std::pow(operand1, operand2);
        default:
            return 0.0;
    }
}


int main(int argc, char const *argv[])
{
    if (argc != 4) {
        std::cerr << "Invalid number of arguments.\nUsage: ./<filename> <num1> <operator> <num2>" << std::endl;
        return 1;
    }

    std::string optr = argv[2];
    Operator op = string_to_op(optr);
    int operand1 = std::stod(argv[1]);
    int operand2 = std::stod(argv[3]);

    std::cout << "Result: " << calculate(operand1, op, operand2) << std::endl;

    return 0;
}