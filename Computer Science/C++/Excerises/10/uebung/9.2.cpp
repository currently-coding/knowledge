#include <iostream>
#include <memory>

class box
{
private:
    std::string content_;

public:
    box(const std::string &content) : content_(content) {}
    void print_content() const
    {
        std::cout << content_ << std::endl;
    }
};

std::shared_ptr<box> make_box()
{
    return std::make_shared<box>("summer");
}

void use_box(std::shared_ptr<box> b)
{
    std::shared_ptr<box> b1 = b;
    std::shared_ptr<box> b2 = b;
    std::shared_ptr<box> b3 = b;
    b1->print_content();
    b2->print_content();
    b3->print_content();
}

int main()
{
    std::shared_ptr<box> b1 = std::make_shared<box>("beach");
    b1->print_content();
    std::cout << b1.use_count();
    std::shared_ptr<box> b2 = std::make_shared<box>("barbecue");
    use_box(b2);
    std::cout << b2.use_count();
    std::shared_ptr<box> b3 = make_box();
    b3->print_content();
}