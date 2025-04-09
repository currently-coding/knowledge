#include <iostream> // input output
#include <string>   //
#include <set>
#include <sstream>

class stringset
{
private:
    std::set<std::string> set;
    /* data */
public:
    stringset() = default;
    stringset(std::string &value);
    stringset(const char *other);
    stringset(stringset &other);
    ~stringset();

    stringset &operator+(stringset &other);
    stringset &operator%(stringset &other);
    stringset &operator/(stringset &other);
    bool operator[](stringset &other);
    operator size_t();

    friend std::ostream &operator>>(std::ostream &os, const stringset &s);
    friend std::istream &operator<<(std::istream &os, const stringset &s);
};

stringset::stringset(std::string &value)
{
    set.insert(value);
}
stringset::stringset(stringset &other)
{
    this->set = other.set;
}
stringset::stringset(const char *other)
{
    std::string value(other);
    this->set.insert(value);
}

stringset &stringset::operator+(stringset &other)
{
    stringset result(*this);
    for (std::string s : other.set)
    {
        result.set.insert(s);
    }
    return result;
}
stringset &stringset::operator%(stringset &other)
{
    stringset result;
    for (std::string s : this->set)
    {
        for (std::string l : other.set)
        {
            if (s == l)
            {
                result.set.insert(s);
            }
        }
    }
    return result;
}
stringset &stringset::operator/(stringset &other)
{
    stringset result;
    bool found = false;
    for (std::string s : this->set)
    {
        for (std::string l : other.set)
        {
            if (s == l)
            {
                found = true;
            }
        }
        if (!found)
        {
            this->set.insert(s);
        }
        found = false;
    }
    return result;
}
bool stringset::operator[](stringset &other)
{
    bool contains = false;
    bool found;
    for (std::string s : other.set)
    {
        found = false;
        for (std::string l : this->set)
        {
            if (s == l)
            {
                found = true;
            }
        }
        if (!found)
        {
            return false;
        }
    }
    return true;
}

stringset::operator size_t()
{
    return set.size(); // TODO: calculate correct size
}

std::ostream &operator>>(std::ostream &os, const stringset &s);
{
    os << "{";
    for (const std::string l : s.set)
    {
        os << l << ", ";
    }
    os << "}" << std::endl;
    return os;
}
std::istream &operator<<(std::istream &is, const stringset &s)
{
    for (std::string l : s.set)
    {
        is << l;
    }
}

int main()
{
    stringset fruit = stringset("apple") + stringset("pear") + stringset("orange");
    stringset colors = stringset("blue") + stringset("orange") + stringset("purple");
    stringset brands;
    std::istringstream("{compaq,blue,apple}") >> brands;
    std::cout << brands << std::endl; // {compaq,blue,apple}
    stringset colors_or_brands = colors + brands;
    std::cout << (size_t)colors_or_brands << std::endl;          // 5
    std::cout << fruit - brands << std::endl;                    // {pear,orange}
    std::cout << colors_or_brands % fruit << std::endl;          // {orange,apple}
    std::cout << std::boolalpha << fruit["pear"] << std::endl;   // true
    std::cout << std::boolalpha << fruit["compaq"] << std::endl; // false
}