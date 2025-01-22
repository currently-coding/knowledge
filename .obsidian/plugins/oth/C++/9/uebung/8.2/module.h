#include <string>
#include <iostream>

namespace Module
{
    class Module
    {
    private:
        std::string name_;
        int ects_;

    public:
        Module(std::string, int);
        ~Module();
        const std::string &name() const;
        int ects() const;
    };

    std::ostream &operator<<(std::ostream &, const Module &);
} // namespace Module
