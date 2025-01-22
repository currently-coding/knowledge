#include <iostream>
#include <iomanip>

int main()
{
    double pi = 3.141592653589793;
    std::cout << "Default: " << pi << std::endl;
    std::cout << "Fixed: " << std::fixed << std::setprecision(4) << pi << std::endl;
    std::cout << "Scientific: " << std::scientific << pi << std::endl;

    double num = pi;
    std::cout << "Default width: " << num << std::endl;
    std::cout << "Width 10: " << std::setw(10) << num << "10chars" << std::endl;
    std::cout << "Width 10 with fill: " << std::setw(10) << std::setfill('*') << num << std::endl;

    return 0;
}