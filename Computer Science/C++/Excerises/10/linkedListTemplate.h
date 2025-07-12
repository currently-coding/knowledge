#include <memory>
#include <string>
#include <iostream>

template <class T>
class linked_list
{
private:
    T value_;
    std::shared_ptr<linked_list<T>> next_;

public:
    linked_list<T>(const T &value) : value_(value), next_(nullptr) {}
    const T &value()
    {
        return value_;
    }
    void insert(const T &v)
    {
        if (next_)
            next_->insert(v);
        else
            next_ = std::make_shared<linked_list<T>>(linked_list<T>(v));
    }
    void print(std::ostream &os)
    {
        os << value_;
        if (next_)
        {
            os << ", ";
            next_->print(os);
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
