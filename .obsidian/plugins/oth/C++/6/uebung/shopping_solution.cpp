#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <list>

using namespace std;

struct Product
{
    int id;
    std::string name;
    double price;
};

struct ListItem
{
    const Product *product;
    int quantity;
    double sub_total() const
    {
        return product->price * quantity;
    }
};

map<int, Product> read_products(istream &input, ostream &error)
{
    string line;
    map<int, Product> result;
    while (getline(input, line))
    {
        Product p;
        istringstream iss(line);
        if (iss >> p.id >> p.name >> p.price)
        {
            result[p.id] = p;
        }
        else
        {
            error << "Unable to parse line: " << line << endl;
        }
    }
    return result;
}

list<ListItem> read_shopping_list(istream &input, ostream &error, map<int, Product> &products)
{
    string line;
    list<ListItem> result;
    while (getline(input, line))
    {
        ListItem li;
        istringstream iss(line);
        int product_id;
        if (iss >> li.quantity >> product_id)
        {
            li.product = &(products[product_id]);
            result.push_back(li);
        }
        else
        {
            error << "Unable to parse line: " << line << endl;
        }
    }
    return result;
}

void print_shopping_list(ostream &output, const list<ListItem> &list_items)
{
    output << showpoint << setprecision(2) << fixed;
    float total = 0.0;
    for (const ListItem &li : list_items)
    {
        total += li.sub_total();
        output << li.quantity << " " << li.product->name << " kosten insgesamt " << li.sub_total() << endl;
    }
    output << "-------------\nDer Einkauf kostet insgesamt " << total << endl;
    output << setiosflags(ios::showbase);
}

int main(int argc, char **argv)
{
    cout << "Running." << endl;
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    ifstream products_file(argv[1]);
    if (!products_file)
    {
        cerr << "File not found: " << argv[1] << endl;
        return 2;
    }
    map<int, Product> products = read_products(products_file, cerr);
    list<ListItem> list_items = read_shopping_list(cin, cerr, products);
    print_shopping_list(cout, list_items);
    products_file.close();
}