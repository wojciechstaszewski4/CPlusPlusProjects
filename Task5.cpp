#include <iostream>
#include <array>

using namespace std;

// Klasa reprezentująca dni tygodnia:

class WeekDays
{
    public:
        // Statyczna metoda zwracająca stałą referencję do tablicy dni tygodnia:

        static const array <string, 7>& GetDays()
        {
            // Statyczna lokalna tablica przechowująca nazwy dni tygodnia:

            static const array <string, 7> days = {"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"};
            return days;
        }
};

// Klasa konwertera dni tygodnia:

class DayConverter
{
    public:
        // Konstruktor, inkrementuje licznik obiektów:

        DayConverter()
        {
            objectCount++;
        }

        // Metoda zwracająca nazwę dnia na podstawie numeru dnia:

        string GetDayName (int dayNumber)
        {
            // Sprawdzenie, czy numer dnia mieści się w zakresie 1-7:

            return (dayNumber >= 1 && dayNumber <= 7) ? WeekDays::GetDays()[dayNumber - 1] : "";
        }

        // Statyczna metoda wyświetlająca liczbę utworzonych obiektów:

        static void DisplayObjectCount()
        {
            cout << "\n Liczba Utworzonych Obiektow: " << objectCount << endl << endl;
        }

        // Destruktor, dekrementuje licznik obiektów:

        ~DayConverter()
        {
            objectCount--;
        }
    private:
        // Statyczna zmienna przechowująca liczbę utworzonych obiektów:

        static int objectCount;
};

// Inicjalizacja statycznej zmiennej objectCount:

int DayConverter::objectCount = 0;

// Funkcja główna programu:

int main (void)
{
    // Utworzenie trzech obiektów klasy DayConverter:

    DayConverter dayConverter1;
    DayConverter dayConverter2;
    DayConverter dayConverter3;

    // Wczytanie numeru dnia od użytkownika:

    int dayNumber;
    cout << "\n Podaj Numer Dnia Tygodnia (1-7): ";
    cin >> dayNumber;

    // Obsługa błędnego formatu danych:

    if (cin.fail())
    {
        cout << " Nieprawidlowy Format Danych! \n" << endl;
        cin.clear();
        cin.ignore (1000, '\n');
        return 1;
    }

    // Pobranie nazwy dnia i wyświetlenie informacji:

    string dayName = dayConverter1.GetDayName (dayNumber);

    if (!dayName.empty())
    {
        cout << " Dzien Tygodnia o Numerze " << dayNumber << " To " << dayName << "." << endl;
    }
    else
    {
        cout << " Numer Dnia Tygodnia Powinien Byc w Zakresie 1-7!" << endl;
    }

    // Wywołanie metody wyświetlającej liczbę utworzonych obiektów:

    DayConverter::DisplayObjectCount();

    return 0;
}