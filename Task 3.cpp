#include <iostream>
#include <iomanip> // Biblioteka dla setprecision.

using namespace std;

// Definicje funkcji do konwersji temperatur:

double CelsiusToFahrenheit (double celsius)
{
    return (celsius * 9/5) + 32;
}

double FahrenheitToCelsius (double fahrenheit)
{
    return (fahrenheit - 32) * 5/9;
}

int main (void)
{
    int conversionChoice;
    double value;

    cout << "\n Menu:" << endl;
    cout << " 1. Celsjusz Na Fahrenheit," << endl;
    cout << " 2. Fahrenheit Na Celsjusz. \n" << endl;

    cout << " Wybierz Opcje Konwersji: ";
    cin >> conversionChoice;

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych! \n" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return 1;
    }

    if (conversionChoice == 1)
    {
        cout << "\n Podaj Temperature w Stopniach Celsjusza: ";
        cin >> value;

        if (cin.fail())
        {
            cout << " Nieprawidlowy Format Danych! \n" << endl;
            cin.clear();
            cin.ignore (1000, '\n');
            return 1;
        }

        double result = CelsiusToFahrenheit (value); // Wywołanie funkcji do konwersji C do F.
        cout << " Temperatura w Stopniach Fahrenheita: " << fixed << setprecision (2) << result << "\n" << endl; // Zaokrąglenie do 2 miejsc po przecinku.
    }
    else if (conversionChoice == 2)
    {
        cout << "\n Podaj Temperature w Stopniach Fahrenheita: ";
        cin >> value;

        if (cin.fail())
        {
            cout << " Nieprawidlowy Format Danych! \n" << endl;
            cin.clear();
            cin.ignore (1000, '\n');
            return 1;
        }

        double result = FahrenheitToCelsius (value); // Wywołanie funkcji do konwersji F do C.
        cout << " Temperatura w Stopniach Celsjusza: " << fixed << setprecision (2) << result << "\n" << endl; // Zaokrąglenie do 2 miejsc po przecinku.
    }
    else
    {
        cout << " Nieprawidlowy Wybor Konwersji! \n" << endl;
    }

    return 0;
}