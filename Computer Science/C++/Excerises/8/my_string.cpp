#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

class my_string
{
private:
	int len_;
	char *data_;

public:
	my_string(const char *data);			  // standard
	my_string(const my_string &s);			  // copy
	my_string(my_string &&s);				  // move
	my_string &operator=(const my_string &s); // copy
	my_string &operator=(my_string &&s);	  // move
	~my_string();
};

my_string::~my_string()
{
	delete[] data_;
	std::cout << "Destructor" << std::endl;
}

my_string::my_string(const char *data)
{
	len_ = strlen(data);
	data_ = new char[len_ + 1];
	strcpy(data_, data);
	cout << "Constructor " << data_ << endl;
}

my_string &my_string::operator=(const my_string &s) // copy assignment
{
	delete[] data_;
	len_ = s.len_;
	data_ = new char[len_ + 1];
	strcpy(data_, s.data_);
	std::cout << "Assignment copy" << std::endl;
	return *this;
}

my_string::my_string(const my_string &s)
{
	len_ = s.len_;
	data_ = new char[len_ + 1];
	strcpy(data_, s.data_);
	std::cout << "Copy Constructor" << std::endl;
}

my_string::my_string(my_string &&s)
{
	data_ = s.data_;
	len_ = s.len_;
	s.data_ = nullptr;
	s.len_ = 0;
	std::cout << "Constructor move" << std::endl;
}

my_string &my_string::operator=(my_string &&s)
{
	delete data_;
	data_ = s.data_;
	delete[] s.data_;
	return *this;
	std::cout << "Assignment move" << std::endl;
}

// TODO copy/move constructor/assignment, destructor

int main()
{
	my_string s1("Hello");				   // Constructor Hello
	my_string s2("World");				   // Constructor World
	my_string s3(s1);					   // Copy Constructor Hello
	my_string s4 = s2;					   // Copy Constructor World
	my_string s5("temp");				   // Constructor temp
	s5 = s4;							   // Copy Assignment World
	my_string s6(move(my_string("rval"))); // Constructor rval			Move Constructor rval
	my_string s7 = move(my_string("Hi"));  // Constructor Hi			Move Constructor Hi
	my_string s8("temp");				   // Constructor temp
	s8 = move(my_string("moving"));		   // Constructor moving		Move Assignment moving
}