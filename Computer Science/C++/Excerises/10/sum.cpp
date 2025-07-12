#include <iostream>
#include <vector>

template <typename T>
T sum(std::vector<T> t)
{
	T result{};
	for (T &element : t)
	{
		result += element;
	}
	return result;
}

int main()
{
	using namespace std;
	vector<int> ints = {1, 2, 3, 4};
	vector<double> doubles = {0.1, 0.5, 2.0, 5.0};
	vector<string> strings = {"Templates ", "Are ", "Great ", "!"};
	int sum_ints = sum<int>(ints);
	double sum_doubles = sum<double>(doubles);
	string sum_strings = sum<string>(strings);
	cout << sum_ints << "\n"
		 << sum_doubles << "\n"
		 << sum_strings << endl;
}
