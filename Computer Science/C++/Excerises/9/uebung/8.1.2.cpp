#include <iostream> // input output
#include <string>   //
#include <set>
#include <sstream>

class stringset
{
private:
    std::set<std::string> set;

public:
    stringset() = default;
    stringset(const std::string &value);
    stringset(const char *other);
    stringset(const stringset &other);

    stringset operator+(const stringset &other);
    stringset operator%(const stringset &other);
    stringset operator-(const stringset &other);
    bool operator[](const std::string &value) const;
    operator size_t();

    friend std::ostream &operator<<(std::ostream &os, const stringset &s);
    friend std::istream &operator>>(std::istream &is, stringset &s);
};

stringset::stringset(const std::string &value)
{
    set.insert(value);
}

stringset::stringset(const char *other) // copy constructor
{
    std::string value(other);
    this->set.insert(value);
}

stringset::stringset(const stringset &other)
{
    this->set = other.set;
}

stringset stringset::operator+(const stringset &other)
{
    for (const std::string &s : other.set)
    {
        set.insert(s);
    }
    return *this;
}

stringset stringset::operator%(const stringset &other)
{
    stringset result;
    for (const std::string &s : this->set)
    {
        if (other.set.find(s) != other.set.end())
        {
            result.set.insert(s);
        }
    }
    return result;
}

stringset stringset::operator-(const stringset &other)
{
    stringset result(*this);
    for (const std::string &s : other.set)
    {
        result.set.erase(s);
    }
    return result;
}

bool stringset::operator[](const std::string &value) const
{
    return set.find(value) != set.end();
}

stringset::operator size_t()
{
    return set.size();
}

std::ostream &operator<<(std::ostream &os, const stringset &s)
{
    os << "{";
    for (const std::string &l : s.set)
    {
        os << l << ", ";
    }
    os << "}" << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, stringset &s)
{
    std::string element;
    while (is >> element && element != "}")
    {
        s.set.insert(element);
    }
    return is;
}

int main()
{
    stringset fruit = stringset("apple") + stringset("pear") + stringset("orange");
    stringset colors = stringset("blue") + stringset("orange") + stringset("purple");
    stringset brands;
    std::istringstream("{compaq,blue,apple}") >> brands;
    std::cout << brands << std::endl; // {compaq,blue,apple}
    stringset colors_or_brands = colors + brands;
    std::cout << (size_t)colors_or_brands << std::endl; // 5
    std::cout << fruit - brands << std::endl;           // {pear,orange}
}