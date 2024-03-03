#include <iostream>

using namespace std;

// Definicja funkcji do konwersji numeru na nazwę dnia tygodnia:

string GetDayName (int dayNumber)
{
    string days_of_week[7] = {"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"};
    return days_of_week[dayNumber - 1];
}

int main (void)
{
    int dayNumber;
    cout << "\n Podaj Numer Dnia Tygodnia (1-7): ";
    cin >> dayNumber;

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych! \n" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return 1;
    }

    if (dayNumber >= 1 && dayNumber <= 7)
    {
        string day_name = GetDayName (dayNumber); // Wywołanie funkcji do konwersji numeru na nazwę dnia tygodnia.
        cout << " Dzien Tygodnia o Numerze " << dayNumber << " To " << day_name << ". \n" << endl;
    } 
    else
    {
        cout << " Numer Dnia Tygodnia Powinien Byc w Zakresie 1-7! \n" << endl;
    }

    return 0;
}