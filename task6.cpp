#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

// Klasa bazowa reprezentująca konwerter:

class Converter
{
    public:
        static int objectCount; // Licznik obiektów.

        Converter()
        {
            objectCount++;
        }

        virtual ~Converter()
        {
            objectCount--;
        }

        virtual void handleConversion() = 0; // Metoda wirtualna do obsługi konwersji.
};

int Converter::objectCount = 0;

// Klasa reprezentująca konwerter temperatur:

class TemperatureConverter : public Converter
{
    public:
        void handleConversion() override;
    private:
        double convertTemperature (double temperature, char conversionType);
        void handleCelsiusToFahrenheit();
        void handleFahrenheitToCelsius();
        void displayTemperatureMenu();
};

// Klasa reprezentująca konwerter dni tygodnia:

class DayOfWeekConverter : public Converter
{
    public:
        void handleConversion() override;
    private:
        string convertDayOfWeek (int dayNumber);
};

// Klasa reprezentująca menedżera przepisów kawowych:

class CoffeeRecipeManager : public Converter
{
    public:
        void handleConversion() override;
        void initializeCoffeeRecipes();
    private:
        map <int, pair <string, string>> coffeeRecipes;
        void addCoffeeRecipe (int recipeNumber, const string &name, const string &description);
        string getCoffeeRecipe (int recipeNumber);
};

// Funkcja wyświetlająca główne menu:

void displayMenu()
{
    cout << "\n Menu:" << endl;
    cout << " 1. Konwerter Temperatur," << endl;
    cout << " 2. Konwerter Dni Tygodnia," << endl;
    cout << " 3. Wybor Przepisow Kawowych," << endl;
    cout << " 0. Wyjscie. \n" << endl;
}

// Metoda wyświetlająca menu dla konwertera temperatur:

void TemperatureConverter::displayTemperatureMenu()
{
    cout << "\n Menu:" << endl;
    cout << " 1. Celsjusz Na Fahrenheit," << endl;
    cout << " 2. Fahrenheit Na Celsjusz. \n" << endl;
}

// Metoda dokonująca konwersji temperatury:

double TemperatureConverter::convertTemperature (double temperature, char conversionType)
{
    if (conversionType == 'C')
    {
        return (temperature * 9 / 5) + 32;
    }
    else if (conversionType == 'F')
    {
        return (temperature - 32) * 5 / 9;
    }
    else
    {
        cout << " Nieprawidlowy Rodzaj Konwersji!" << endl;
        return 0.0;
    }
}

// Metoda obsługująca konwersję z Celsiusa na Fahrenheita:

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

    double result = convertTemperature (value, 'C');
    cout << " Temperatura w Stopniach Fahrenheita: " << fixed << setprecision (2) << result << endl;
}

// Metoda obsługująca konwersję z Fahrenheita na Celsiusa:

void TemperatureConverter::handleFahrenheitToCelsius()
{
    double value;
    cout << "\n Podaj Temperature w Stopniach Fahrenheita: ";
    cin >> value;

    if (cin.fail()) {
        cout << " Nieprawidlowy Format Danych!" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return;
    }

    double result = convertTemperature (value, 'F');
    cout << " Temperatura w Stopniach Celsjusza: " << fixed << setprecision (2) << result << endl;
}

// Metoda obsługująca główną konwersję dla konwertera temperatur:

void TemperatureConverter::handleConversion()
{
    int conversionChoice;

    displayTemperatureMenu();

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

// Metoda konwertująca numer dnia tygodnia na nazwę:

string DayOfWeekConverter::convertDayOfWeek (int dayNumber)
{
    const string days_of_week[7] = {"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"};
    return days_of_week[dayNumber - 1];
}

// Metoda obsługująca konwersję dni tygodnia:

void DayOfWeekConverter::handleConversion()
{
    int dayNumber;
    cout << "\n Podaj Numer Dnia Tygodnia (1-7): ";
    cin >> dayNumber;

    if (cin.fail()) {
        cout << " Nieprawidlowy Format Danych!" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return;
    }

    if (dayNumber >= 1 && dayNumber <= 7)
    {
        string result = convertDayOfWeek (dayNumber);
        cout << " Dzien Tygodnia o Numerze " << dayNumber << " To " << result << "." << endl;
    }
    else
    {
        cout << " Numer Dnia Tygodnia Powinien Byc w Zakresie 1-7!" << endl;
    }
}

// Metoda dodająca przepis na kawę do mapy:

void CoffeeRecipeManager::addCoffeeRecipe (int recipeNumber, const string &name, const string &description)
{
    coffeeRecipes[recipeNumber] = make_pair (name, description);
}

// Metoda pobierająca przepis na kawę z mapy:

string CoffeeRecipeManager::getCoffeeRecipe (int recipeNumber)
{
    if (coffeeRecipes.find (recipeNumber) != coffeeRecipes.end())
    {
        auto recipe = coffeeRecipes[recipeNumber];
        return " Przepis: " + recipe.first + " - " + recipe.second;
    }
    else
    {
        return " Nieznany Przepis!";
    }
}

// Metoda obsługująca konwersję przepisów kawowych:

void CoffeeRecipeManager::handleConversion()
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

// Metoda inicjalizująca przepisy kawowe:

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

// Główna funkcja programu:

int main (void)
{
    TemperatureConverter tempConverter;
    DayOfWeekConverter dayConverter;
    CoffeeRecipeManager coffeeManager;

    coffeeManager.initializeCoffeeRecipes();

    while (true)
    {
        displayMenu();

        int choice;
        cout << " Wybierz Program Do Uruchomienia: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "\n Do Widzenia!" << endl;
            cout << " Liczba Utworzonych Obiektow: " << Converter::objectCount << endl << endl;
            break;
        }

        Converter *selectedConverter = nullptr;

        switch (choice)
        {
            case 1:
                selectedConverter = &tempConverter;
                break;

            case 2:
                selectedConverter = &dayConverter;
                break;

            case 3:
                selectedConverter = &coffeeManager;
                break;

            default:
                cout << " Nieprawidlowy Wybor Programu! Sprobuj Ponownie." << endl;
                break;
        }

        if (selectedConverter != nullptr)
        {
            selectedConverter->handleConversion();
        }
    }

    return 0;
}