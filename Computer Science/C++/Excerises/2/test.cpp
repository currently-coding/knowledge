#include <iostream>

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = ++i+i++;
    int l = i++ + ++i;
    std::cout << j << "\n" << l << std::endl;
    return 0;
}
