#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    using namespace std;
    int num_modules = 0;
    cout << "Number of modules: ";
    cin >> num_modules;
    vector<int> grades;
    string module_name;
    unsigned short module_grade = 0;
    for (int i = 0; i < num_modules; i++) {
        cout << "Name of Module: " << i;
        cin >> module_name;
        cout << endl << "Grade in Module " << module_name << ": ";
        cin >> module_grade;
        cout << endl;
        grades.push_back(module_grade);
    }
    return 0;
}