#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

const int TEMPERATURE_CONVERSION_OPTION = 1;
const int DAY_OF_WEEK_CONVERSION_OPTION = 2;
const int COFFEE_RECIPES_OPTION = 3;
const int EXIT_OPTION = 0;

// Enumeracja dla dni tygodnia:

enum DaysOfWeek
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

// Struktura do konwersji temperatur:

struct TemperatureConversion
{
    double celsius;
    double fahrenheit;
};

// Struktura dla funkcji konwersji temperatur:

struct TemperatureConverter
{
    static TemperatureConversion convertTemperature (double temperature);
    static void handleCelsiusToFahrenheit();
    static void handleFahrenheitToCelsius();
    static void handleTemperatureConversion();
    static void displayTemperatureConversionMenu();
};

// Struktura do konwersji dni tygodnia:

struct DayOfWeekConversion
{
    int dayNumber;
    string dayName;
};

// Struktura dla funkcji konwersji dni tygodnia:

struct DayOfWeekConverter
{
    static DayOfWeekConversion convertDayOfWeek (int dayNumber);
    static void handleDayOfWeekConversion();
};

// Struktura dla przepisów na kawę:

struct CoffeeRecipe
{
    string name;
    string description;
};

// Struktura dla zarządzania przepisami na kawę:

struct CoffeeRecipeManager
{
    static void addCoffeeRecipe (int recipeNumber, const string &name, const string &description);
    static string getCoffeeRecipe (int recipeNumber);
    static void handleCoffeeRecipes();
    static void initializeCoffeeRecipes();
};

// Funkcja do wyświetlania głównego menu:

void displayMenu()
{
    cout << "\n Menu:" << endl;
    cout << " " << TEMPERATURE_CONVERSION_OPTION << ". Konwerter Temperatur," << endl;
    cout << " " << DAY_OF_WEEK_CONVERSION_OPTION << ". Konwerter Dni Tygodnia," << endl;
    cout << " " << COFFEE_RECIPES_OPTION << ". Wybor Przepisow Kawowych," << endl;
    cout << " " << EXIT_OPTION << ". Wyjscie. \n" << endl;
}

// Funkcja do wyświetlania menu konwersji temperatur:

void TemperatureConverter::displayTemperatureConversionMenu()
{
    cout << "\n Menu:" << endl;
    cout << " 1. Celsjusz Na Fahrenheit," << endl;
    cout << " 2. Fahrenheit Na Celsjusz. \n" << endl;
}

// Funkcja do przeprowadzania konwersji temperatur:

TemperatureConversion TemperatureConverter::convertTemperature (double temperature)
{
    TemperatureConversion result;
    result.celsius = (temperature - 32) * 5 / 9;
    result.fahrenheit = (temperature * 9 / 5) + 32;
    return result;
}

// Funkcja do obsługi konwersji z Celsjusza na Fahrenheita:

void TemperatureConverter::handleCelsiusToFahrenheit()
{
    double value;
    cout << "\n Podaj Temperature w Stopniach Celsjusza: ";
    cin >> value;

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych!" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return;
    }

    TemperatureConversion result = convertTemperature (value);
    cout << " Temperatura w Stopniach Fahrenheita: " << fixed << setprecision (2) << result.fahrenheit << endl;
}

// Funkcja do obsługi konwersji z Fahrenheita na Celsjusza:

void TemperatureConverter::handleFahrenheitToCelsius()
{
    double value;
    cout << "\n Podaj Temperature w Stopniach Fahrenheita: ";
    cin >> value;

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych!" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return;
    }

    TemperatureConversion result = convertTemperature (value);
    cout << " Temperatura w Stopniach Celsjusza: " << fixed << setprecision (2) << result.celsius << endl;
}

// Funkcja do obsługi wyboru konwersji temperatur:

void TemperatureConverter::handleTemperatureConversion()
{
    int conversionChoice;
    displayTemperatureConversionMenu();
    cout << " Wybierz Opcje Konwersji: ";
    cin >> conversionChoice;

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych!" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return;
    }

    switch (conversionChoice)
    {
    case 1:
        handleCelsiusToFahrenheit();
        break;
    case 2:
        handleFahrenheitToCelsius();
        break;
    default:
        cout << " Nieprawidlowy Wybor Konwersji!" << endl;
        break;
    }
}

// Funkcja do obsługi konwersji dni tygodnia:

DayOfWeekConversion DayOfWeekConverter::convertDayOfWeek (int dayNumber)
{
    DayOfWeekConversion result;
    string days_of_week[7] = {"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"};

    result.dayNumber = dayNumber;
    result.dayName = days_of_week[dayNumber - 1];
    return result;
}

// Funkcja do obsługi wprowadzania przez użytkownika numerów dni tygodnia:

void DayOfWeekConverter::handleDayOfWeekConversion()
{
    int dayNumber;
    cout << "\n Podaj Numer Dnia Tygodnia (1-7): ";
    cin >> dayNumber;

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych!" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return;
    }

    if (dayNumber >= 1 && dayNumber <= 7)
    {
        DayOfWeekConversion result = convertDayOfWeek (dayNumber);
        cout << " Dzien Tygodnia o Numerze " << result.dayNumber << " To " << result.dayName << "." << endl;
    }
    else
    {
        cout << " Numer Dnia Tygodnia Powinien Byc w Zakresie 1-7!" << endl;
    }
}

// Mapa do przechowywania przepisów na kawę:

map <int, CoffeeRecipe> coffeeRecipes;

// Funkcja do dodawania przepisów na kawę do mapy:

void CoffeeRecipeManager::addCoffeeRecipe (int recipeNumber, const string &name, const string &description)
{
    CoffeeRecipe recipe;
    recipe.name = name;
    recipe.description = description;
    coffeeRecipes[recipeNumber] = recipe;
}

// Funkcja do pobierania przepisów na kawę na podstawie numeru przepisu:

string CoffeeRecipeManager::getCoffeeRecipe (int recipeNumber)
{
    if (coffeeRecipes.find (recipeNumber) != coffeeRecipes.end())
    {
        CoffeeRecipe recipe = coffeeRecipes[recipeNumber];
        return " Przepis: " + recipe.name + " - " + recipe.description;
    }
    else
    {
        return " Nieznany Przepis!";
    }
}

// Funkcja do obsługi wyboru przepisów na kawę przez użytkownika:

void CoffeeRecipeManager::handleCoffeeRecipes()
{
    int recipeNumber;
    cout << "\n Podaj Numer Przepisu Na Kawe: ";
    cin >> recipeNumber;

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych!" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return;
    }

    string recipe = getCoffeeRecipe (recipeNumber);
    cout << recipe << endl;
}

// Funkcja do inicjalizacji przepisów na kawę w mapie:

void CoffeeRecipeManager::initializeCoffeeRecipes()
{
    addCoffeeRecipe (1, "Kawa Czarna", "100% Kawy.");
    addCoffeeRecipe (2, "Kawa Biala", "50% Kawy i 50% Mleka.");
    addCoffeeRecipe (3, "Espresso", "100% Kawy.");
    addCoffeeRecipe (4, "Latte", "30% Kawy, 70% Mleka, Pianka Mleczna Na Wierzchu.");
    addCoffeeRecipe (5, "Cappuccino", "80% Kawy, 20% Mleka, Pianka Mleczna Na Wierzchu.");
    addCoffeeRecipe (6, "Mochaccino", "50% Kawy, 25% Gorzkiej Czekolady, 25% Mleka, Bita Smietana Na Wierzchu.");
    addCoffeeRecipe (7, "Americano", "70% Kawy i 30% Wody.");
    addCoffeeRecipe (8, "Cafe Frappe", "70% Kawy, 20% Mleka, 10% Lodu.");
    addCoffeeRecipe (9, "Flat White", "90% Kawy, 10% Mleka, Mikrospienione Mleko.");
}

// Funkcja główna programu:

int main (void)
{
    CoffeeRecipeManager::initializeCoffeeRecipes();

    while (true)
    {
        displayMenu();

        int choice;
        cout << " Wybierz Program Do Uruchomienia: ";
        cin >> choice;

        if (choice == EXIT_OPTION)
        {
            cout << " Do Widzenia! \n" << endl;
            break;
        }

        switch (choice)
        {
        case TEMPERATURE_CONVERSION_OPTION:
            TemperatureConverter::handleTemperatureConversion();
            break;

        case DAY_OF_WEEK_CONVERSION_OPTION:
            DayOfWeekConverter::handleDayOfWeekConversion();
            break;

        case COFFEE_RECIPES_OPTION:
            CoffeeRecipeManager::handleCoffeeRecipes();
            break;

        default:
            cout << " Nieprawidlowy Wybor Programu! Sprobuj Ponownie." << endl;
            break;
        }
    }

    return 0;
}