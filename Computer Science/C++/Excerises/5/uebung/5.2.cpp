#include <iostream>
#include <string>
#include <vector>

class Ingredient
{
private:
    int amount_;
    std::string unit_;
    std::string name_;

public:
    Ingredient(int amount, std::string unit, std::string name) : amount_(amount), unit_(unit), name_(name) {}
    Ingredient(int amount, std::string name) : amount_(amount), unit_("x"), name_(name) {}
    Ingredient(std::string name) : amount_(1), unit_("x"), name_(name) {}

    void print();
};

void Ingredient::print()
{
    std::cout << amount_ << " " << unit_ << " " << name_ << std::endl;
}

class Recipe
{
private:
    std::string title_;
    std::vector<Ingredient> ingredients_;
    std::vector<std::string> commands_;

public:
    Recipe(std::string title) : title_(title){};

    void add(Ingredient ingredient);
    void add(std::string command);
    void print();
};

void Recipe::add(Ingredient ingredient)
{
    ingredients_.push_back(ingredient);
}
void Recipe::add(std::string command)
{
    commands_.push_back(command);
}
void Recipe::print()
{
    using namespace std;
    cout << " - - - " << title_ << " - - -" << endl;
    cout << "   - - " << "Ingredients" << " - -   " << endl;
    for (Ingredient i : ingredients_)
    {
        i.print();
    }
    cout << "   - - " << "Procedure" << " - -   " << endl;
    for (std::string command : commands_)
    {
        cout << command << endl;
    }
}

int main()
{
    Ingredient flour = Ingredient(200, "g", "flour");
    Ingredient sugar = Ingredient(30, "g", "sugar");
    Ingredient milk = Ingredient(150, "ml", "milk");
    Ingredient egg = Ingredient(2, "eggs");
    Ingredient salt = Ingredient("salt");
    Ingredient bakingPowder = Ingredient("baking powder");
    flour.print(); // 200 g flour
    egg.print();   // 2 x eggs
    salt.print();  // 1 x salt
    std::cout << std::endl;
    Recipe r("Pancakes");
    r.add(flour);
    r.add(sugar);
    r.add(milk);
    r.add(egg);
    r.add(salt);
    r.add(bakingPowder);
    r.add("Sift the dry ingredients together.");
    r.add("Make a well, then add the wet ingredients. Stir to combine.");
    r.add("Scoop the batter onto a hot griddle or pan.");
    r.add("Cook for two to three minutes, then flip.");
    r.add("Continue cooking until brown on both sides.");
    r.print();
}