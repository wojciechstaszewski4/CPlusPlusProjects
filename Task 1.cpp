#include <iostream>
#include <map> // Do wyboru przepisów.

using namespace std;

map <int, string> coffeeRecipes; // Użyłem mapy do przechowywania przepisów na kawę. 

// Definicje funkcji do wyboru przepisów na kawę:

void AddCoffeeRecipe (int recipeNumber, const string &recipe)
{
    coffeeRecipes[recipeNumber] = recipe;
}

string GetCoffeeRecipe (int recipeNumber)
{
    if (coffeeRecipes.find (recipeNumber) != coffeeRecipes.end()) // Wyszukiwanie zadeklarowanych przepisów.
    {
        return " Przepis: " + coffeeRecipes[recipeNumber] + "\n";
    }
    else
    {
        return " Nieznany Przepis! \n";
    }
}

int main (void)
{
    // Miejsce dodawania przepisów na kawę za pomocą mapy:

    AddCoffeeRecipe (1, "Kawa Czarna - 100% Kawy.");
    AddCoffeeRecipe (2, "Kawa Biala - 50% Kawy i 50% Mleka.");
    AddCoffeeRecipe (3, "Espresso - 100% Kawy.");
    AddCoffeeRecipe (4, "Latte - 30% Kawy, 70% Mleka, Pianka Mleczna Na Wierzchu.");
    AddCoffeeRecipe (5, "Cappuccino - 80% Kawy, 20% Mleka, Pianka Mleczna Na Wierzchu.");
    AddCoffeeRecipe (6, "Mochaccino - 50% Kawy, 25% Gorzkiej Czekolady, 25% Mleka, Bita Smietana Na Wierzchu.");
    AddCoffeeRecipe (7, "Americano - 70% Kawy i 30% Wody.");
    AddCoffeeRecipe (8, "Cafe Frappe - 70% Kawy, 20% Mleka, 10% Lodu.");
    AddCoffeeRecipe (9, "Flat White - 90% Kawy, 10% Mleka, Mikrospienione Mleko.");

    int recipeNumber;
    cout << "\n Podaj Numer Przepisu Na Kawe: ";
    cin >> recipeNumber;

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych! \n" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return 1;
    }

    string recipe = GetCoffeeRecipe (recipeNumber); // Wywołanie funkcji do wyboru przepisów na kawę:
    cout << recipe << endl;

    return 0;
}