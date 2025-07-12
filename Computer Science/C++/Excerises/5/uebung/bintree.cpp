#include <iostream>

struct bintree;
bintree &create_tree(std::string value);

struct bintree
{
    bintree *left;
    bintree *right;
    std::string value;
    void print()
    {
        std::cout << "(";
        if (left)
        {
            left->print();
        }
        std::cout << value;
        if (right)
        {
            right->print();
        }
        std::cout << ")";
    }

    void insert(bintree &sub)
    {
        if (sub.value < value)
        {
            if (left)
            {
                left->insert(sub);
            }
            else
            {
                left = &sub;
            }
        }
        else
        {
            if (right)
            {
                right->insert(sub);
            }
            else
            {
                right = &sub;
            }
        }
    }

    void insert(std::string value)
    {
        insert(create_tree(value));
    }

    void remove()
    {
        if (left)
        {
            left->remove();
        }
        if (right)
        {
            right->remove();
        }
        delete this;
    }
};

bintree &create_tree(std::string value)
{
    bintree *res = new bintree{nullptr, nullptr, value};
    return *res;
}

int main()
{
    bintree t1 = {nullptr, nullptr, "abr"};
    bintree t2 = {nullptr, nullptr, "ra"};
    bintree t3 = {nullptr, nullptr, "aca"};
    bintree t4 = {nullptr, nullptr, "dab"};
    t1.insert(t2);
    t1.insert(t3);
    t1.insert(t4);
    t1.print();
    std::cout << std::endl;

    bintree &t5 = create_tree("abr");
    t5.insert("ra");
    t5.insert("aca");
    t5.insert("dab");
    t5.print();
    t5.remove();
    std::cout << std::endl;

    return 0;
}
