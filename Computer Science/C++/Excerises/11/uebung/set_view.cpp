#include <set>
#include <string>
#include <functional>
#include <cassert>

template <class T>
class set_view
{
private:
    std::set<T> set_;
    std::function<bool(T)> filter_;

public:
    set_view(std::set<T> set, std::function<bool(T)> filter) : set_(set), filter_(filter){};
    void filter(std::function<bool(T)> filter)
    {
        filter_ = filter;
    }

    bool contains(T input)
    {
        for (const auto &s : set_)
        {
            if (filter_(input))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    std::set<std::string> names = {"Anne", "John", "Cindy", "Adam"};
    set_view<std::string> nv(names, [](std::string s)
                             { return true; });
    assert(nv.contains("Cindy"));
    assert(nv.contains("John"));
    nv.filter([](std::string s)
              { return s.size() == 4; });
    assert(!nv.contains("Cindy"));
    assert(nv.contains("John"));
    nv.filter([](std::string s)
              { return s.find("y") != std::string::npos; });
    assert(nv.contains("Cindy"));
    assert(!nv.contains("John"));
}