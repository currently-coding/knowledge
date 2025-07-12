#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <string>
#include <cassert>
#define ERROR std::cerr

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

map<int, Product> read_products(istream &in, ostream &error)
{
	string line;
	map<int, Product> result;

	while (std::getline(in, line))
	{
		Product product;
		istringstream iss(line);
		if (!(iss >> product.id >> product.name >> product.price))
		{
			error << "Unable to parse lines. read_products()" << std::endl;
		}
		result[product.id] = product;
	}
	return result;
}

std::list<ListItem> calculate_shopping(std::map<int, Product> products, std::istream &in, std::ostream &error)
{
	std::list<ListItem> result;
	std::string line;
	while (std::getline(in, line))
	{
		ListItem item;
		int product_id;
		istringstream iss(line);
		if (!(iss >> item.quantity >> product_id))
		{
			error << "Unable to parse line. calculate_shopping()" << std::endl;
			continue;
		}
		auto product = products.find(product_id);
		if (product != products.end())
		{
			item.product = &(product->second);
		}
		else
		{
			error << "Product not found. ID: " << product_id << std::endl;
		}

		result.push_back(item);
	}
	return result;
}

void print(std::list<ListItem> shopping_list)
{
	using namespace std;
	cout << "Shopping List:" << std::endl;
	for (auto const &it : shopping_list)
	{
		cout << it.quantity << "x " << it.product->name << std::fixed << std::setprecision(2) << "(id:" << it.product->id << ", price:" << it.product->price << ") kosten " << it.sub_total() << "€" << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage Error: ./" << argv[0] << " <products.txt> < <shopping_list.txt>" << std::endl;
		return 1;
	}

	std::string products_path = argv[1];
	std::ifstream products_file(products_path);
	if (!products_file)
	{
		std::cerr << "Failed to open products file: " << products_path << std::endl;
		return 1;
	}

	map<int, Product> products = read_products(products_file, cerr);

	list<ListItem> shopping_items = calculate_shopping(products, std::cin, cerr);

	// output
	print(shopping_items);
	return 0;
}

// usage: ./shopping2 products.txt < shopping2.txt