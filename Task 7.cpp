#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <limits>

using namespace std;

// Ten program to symulator prostego automatu do kawy, który umożliwia użytkownikowi wybór różnych napojów oraz wykonuje odpowiednie operacje związane z przygotowywaniem napojów, dodawaniem środków finansowych,
// kontrolą poziomu wody, czyszczeniem automatu i śledzeniem statystyk. W głównej pętli programu użytkownik może wybierać między różnymi opcjami, takimi jak zrobienie napoju, dodanie środków,
// sprawdzenie dostępnych środków, wypłata reszty, sprawdzenie poziomu wody, sprawdzenie, czy automat jest wyczyszczony, dolewanie wody, czy czyszczenie automatu. Opcje te są obsługiwane przez odpowiednie funkcje,
// a także wykorzystują różne klasy, takie jak Drink, Coffee, Espresso, itp. Wybierając opcję przygotowania napoju, użytkownik wybiera konkretny napój z menu, określając również rozmiar i poziom cukru.
// Program sprawdza dostępność składników, takich jak woda, środki finansowe i stan czystości automatu, a następnie przygotowuje wybrany napój. Automat śledzi liczbę zrobionych napojów,
// dochód oraz ewentualne limity dla poszczególnych napojów. Co 20 napojów automat wymaga czyszczenia. Dodatkowo, użytkownik może kontrolować poziom wody, dolewać ją do automatu oraz sprawdzać statystyki,
// takie jak liczba zrobionych napojów i całkowity dochód automatu. Program umożliwia również dodawanie środków finansowych oraz wypłatę reszty. Dodatkowo, wprowadzono zabezpieczenie,
// które ogranicza ilość wyrobionych napojów danego rodzaju do 50. Po przekroczeniu tego limitu dla konkretnego napoju, automat informuje użytkownika,
// że osiągnięto limit dla danego napoju i nie ma możliwości przygotowania kolejnych. Wprowadzone zabezpieczenie zapewnia bardziej realistyczną symulację,
// gdzie skończenie się składników (Kawy lub herbaty) po pewnej liczbie napojów staje się wyzwaniem. W ten sposób, program symuluje interakcję z prostym automatem do kawy,
// zapewniając użytkownikowi możliwość korzystania z różnych funkcji, śledzenia stanu automatu i uwzględniając ograniczenia związane z dostępnością składników.

class Drink
{
    public:
        virtual void prepare() const = 0;
        virtual ~Drink() = default;
        virtual int getPrice() const = 0;
        virtual string getName() const = 0;
        virtual bool isLarge() const = 0;
        virtual int getSugarLevel() const = 0;
};

class Coffee : public Drink
{
    protected:
        bool large;
        int sugarLevel;

    public:
        Coffee (bool isLarge, int sugarLevel) : large (isLarge), sugarLevel (sugarLevel) {}

        bool isLarge() const override
        {
            return large;
        }

        int getSugarLevel() const override
        {
            return sugarLevel;
        }
};

class Espresso : public Coffee
{
    public:
        Espresso (bool isLarge, int sugarLevel) : Coffee (isLarge, sugarLevel) {}

        void prepare() const override
        {
            cout << "\n Przygotowuje Kawe Espresso..." << endl;
        }

        int getPrice() const override
        {
            return isLarge() ? 5 : 4;
        }

        string getName() const override
        {
            return "Espresso";
        }
};

class Latte : public Coffee
{
    public:
        Latte (bool isLarge, int sugarLevel) : Coffee (isLarge, sugarLevel) {}

        void prepare() const override
        {
            cout << "\n Przygotowuje Kawe Latte..." << endl;
        }

        int getPrice() const override
        {
            return isLarge() ? 6 : 5;
        }

        string getName() const override
        {
            return "Latte";
        }
};

class Cappuccino : public Coffee
{
    public:
        Cappuccino (bool isLarge, int sugarLevel) : Coffee (isLarge, sugarLevel) {}

        void prepare() const override
        {
            cout << "\n Przygotowuje Kawe Cappuccino..." << endl;
        }

        int getPrice() const override
        {
            return isLarge() ? 6 : 5;
        }

        string getName() const override
        {
            return "Cappuccino";
        }
};

class Americano : public Coffee
{
    public:
        Americano (bool isLarge, int sugarLevel) : Coffee (isLarge, sugarLevel) {}

        void prepare() const override
        {
            cout << "\n Przygotowuje Kawe Americano..." << endl;
        }

        int getPrice() const override
        {
            return isLarge() ? 4 : 3;
        }

        string getName() const override
        {
            return "Americano";
        }
};

class Mocha : public Coffee
{
    public:
        Mocha (bool isLarge, int sugarLevel) : Coffee (isLarge, sugarLevel) {}

        void prepare() const override
        {
            cout << "\n Przygotowuje Kawe Moche..." << endl;
        }

        int getPrice() const override
        {
            return isLarge() ? 7 : 6;
        }

        string getName() const override
        {
            return "Mocha";
        }
};

class BlackTea : public Coffee
{
    public:
        BlackTea (bool isLarge, int sugarLevel) : Coffee (isLarge, sugarLevel) {}

        void prepare() const override
        {
            cout << "\n Przygotowuje Herbate Czarna..." << endl;
        }

        int getPrice() const override
        {
            return isLarge() ? 4 : 3;
        }

        string getName() const override
        {
            return "Herbata Czarna";
        }
};

class GreenTea : public Coffee
{
    public:
        GreenTea (bool isLarge, int sugarLevel) : Coffee (isLarge, sugarLevel) {}

        void prepare() const override
        {
            cout << "\n Przygotowuje Herbate Zielona..." << endl;
        }

        int getPrice() const override
        {
            return isLarge() ? 5 : 4;
        }

        string getName() const override
        {
            return "Herbata Zielona";
        }
};

class Water : public Coffee
{
    public:
        Water (bool isLarge, int sugarLevel) : Coffee (isLarge, sugarLevel) {}

        void prepare() const override
        {
            cout << "\n Przygotowuje Wode..." << endl;
        }

        int getPrice() const override
        {
            return large ? 2 : 1;
        }

        string getName() const override
        {
            return "Woda";
        }
};

class Selector
{
    public:
        static bool chooseSize (const string &prompt)
        {
            cout << prompt << endl;
            cout << " 1. Maly," << endl;
            cout << " 2. Duzy. \n" << endl;

            int sizeChoice;

            while (true)
            {
                cout << " Wybierz Rozmiar: ";
                if (cin >> sizeChoice && (sizeChoice == 1 || sizeChoice == 2))
                {
                    return sizeChoice == 2;
                }
                else
                {
                    cout << " Wprowadz Poprawny Rozmiar Napoju (1-2)! Sprobuj Ponownie. \n" << endl;
                    cin.clear();
                    cin.ignore (numeric_limits<streamsize>::max(), '\n');
                }
            }
        }

        static int chooseSugarLevel (int minLevel, int maxLevel)
        {
            int sugarLevel;

            while (true)
            {
                cout << " Wybierz Poziom Cukru (" << minLevel << "-" << maxLevel << "): ";

                if (cin >> sugarLevel && sugarLevel >= minLevel && sugarLevel <= maxLevel)
                {
                    return sugarLevel;
                }
                else
                {
                    cout << " Wprowadz Poprawny Poziom Cukru (0-5)! Sprobuj Ponownie. \n" << endl;
                    cin.clear();
                    cin.ignore (numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
};

class CoffeeMachine
{
    private:
        int waterLevel;
        int coffeeCount;
        int revenue;
        bool machineCleaned;
        int moneyInserted;
        unordered_map<string, int> drinkUses;
        unordered_map<string, int> drinkLimits;

    public:
        CoffeeMachine() : waterLevel(500), coffeeCount(0), machineCleaned(true), revenue(0), moneyInserted(0)
        {
            drinkUses["Espresso"] = -1;
            drinkLimits["Espresso"] = 50;

            drinkUses["Latte"] = -1;
            drinkLimits["Latte"] = 50;

            drinkUses["Cappuccino"] = -1;
            drinkLimits["Cappuccino"] = 50;

            drinkUses["Americano"] = -1;
            drinkLimits["Americano"] = 50;

            drinkUses["Mocha"] = -1;
            drinkLimits["Mocha"] = 50;

            drinkUses["BlackTea"] = -1;
            drinkLimits["BlackTea"] = 50;

            drinkUses["GreenTea"] = -1;
            drinkLimits["GreenTea"] = 50;
        }
        
        void addMoney (int amount)
        {
            moneyInserted += amount;
            cout << " Dodano " << amount << "zl." << endl;
            cout << " Dostepne Srodki: " << moneyInserted << "zl" << endl;
        }

        int getMoneyInserted() const
        {
            return moneyInserted;
        }

        void dispenseChange (int change)
        {
            if (moneyInserted > 0)
            {
                cout << " Wyplacone Srodki: " << change << "zl" << endl;
                moneyInserted = 0;
            }
            else
            {
                cout << " Brak Srodkow Do Wyplaty!" << endl;
            }
        }

        int getWaterLevel() const
        {
            return waterLevel;
        }

        bool isMachineCleaned() const
        {
            return machineCleaned;
        }

        void addWater (int amount)
        {
            waterLevel += amount;
            cout << " Dodano " << amount << "ml Wody." << endl;
            cout << " Aktualny Poziom Wody: " << waterLevel << "ml" << endl;
        }

        void cleanMachine()
        {
            cout << "\n Czyszcze Automat..." << endl;
            machineCleaned = true;
        }

        int getCoffeeCount() const
        {
            return coffeeCount;
        }

        int getRevenue() const
        {
            return revenue;
        }

        void makeDrink (unique_ptr<Drink> drink)
        {
            if (waterLevel < (drink->isLarge() ? 100 : 50))
            {
                cout << "\n Brak Wody! Dolej Wode Przed Przygotowaniem Kolejnego Napoju." << endl;
                return;
            }

            if (!machineCleaned)
            {
                cout << "\n Automat Wymaga Czyszczenia! Wyczysc Automat Przed Przygotowaniem Kolejnego Napoju." << endl;
                return;
            }

            int price = drink->getPrice();

            if (moneyInserted < price)
            {
                cout << "\n Niewystarczajace Srodki! Dodaj Wiecej Pieniedzy." << endl;
                return;
            }

            int change = moneyInserted - price;
            moneyInserted -= price;

            drinkUses[drink->getName()]++;
            
            if (drinkUses[drink->getName()] >= drinkLimits[drink->getName()])
            {
                cout << "\n Osiagnieto Limit Dla " << drink->getName() << ". Nie Mozna Go Juz Przygotowac!" << endl;
                return;
            }
            
            drink->prepare();
            waterLevel -= (drink->isLarge() ? 100 : 50);
            coffeeCount++;
            revenue += price;

            cout << " " << drink->getName() << " Zostala Zrobiona. Aktualny Poziom Wody: " << waterLevel << "ml" << endl;

            if (coffeeCount % 20 == 0)
            {
                machineCleaned = false;
            }
        }
};

int main (void)
{
    CoffeeMachine coffeeMachine;

    while (true)
    {
        cout << "\n Automat Do Kawy:" << endl;
        cout << " 1. Zrob Kawe Lub Herbate," << endl;
        cout << " 2. Dodaj Srodki," << endl;
        cout << " 3. Sprawdz Dostepne Srodki," << endl;
        cout << " 4. Wyplac Srodki," << endl;
        cout << " 5. Sprawdz Ilosc Wody," << endl;
        cout << " 6. Sprawdz, Czy Automat Jest Wyczyszczony," << endl;
        cout << " 7. Dolej Wody," << endl;
        cout << " 8. Wyczysc Automat," << endl;
        cout << " 9. Zobacz Licznik Napojow," << endl;
        cout << " 10. Sprawdz Dochod Automatu," << endl;
        cout << " 0. Wylacz. \n" << endl;

        int choice;
        while (true)
        {
            cout << " Wybierz Opcje: ";
            if (cin >> choice)
            {
                break;
            }
            else
            {
                cout << " Wprowadz Liczbe Calkowita! Sprobuj Ponownie. \n" << endl;
                cin.clear();
                cin.ignore (numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (choice)
        {
            case 1:
            {
                cout << "\n Dostepne Napoje:" << endl;
                cout << " 1. Espresso - Cena: 4zl (Male) / 5zl (Duze)," << endl;
                cout << " 2. Latte - Cena: 5zl (Male) / 6zl (Duze)," << endl;
                cout << " 3. Cappuccino - Cena: 5zl (Male) / 6zl (Duze)," << endl;
                cout << " 4. Americano - Cena: 3zl (Male) / 4zl (Duze)," << endl;
                cout << " 5. Mocha - Cena: 6zl (Mala) / 7zl (Duza)," << endl;
                cout << " 6. Herbata Czarna - Cena: 3zl (Mala) / 4zl (Duza)," << endl;
                cout << " 7. Herbata Zielona - Cena: 4zl (Mala) / 5zl (Duza)," << endl;
                cout << " 8. Woda - Cena: 1zl (Mala) / 2zl (Duza). \n" << endl;

                int drinkChoice;
                while (true)
                {
                    cout << " Wybierz Numer Napoju: ";
                    if (cin >> drinkChoice)
                    {
                        break;
                    }
                    else
                    {
                        cout << " Wprowadz Liczbe Calkowita! Sprobuj Ponownie. \n" << endl;
                        cin.clear();
                        cin.ignore (numeric_limits<streamsize>::max(), '\n');
                    }
                }

                unique_ptr<Drink> selectedDrink;

                switch (drinkChoice)
                {
                    case 1:
                    {
                        bool isLarge = Selector::chooseSize ("\n Rozmiary:");
                        int sugarLevel = Selector::chooseSugarLevel (0, 5);
                        selectedDrink = make_unique<Espresso>(isLarge, sugarLevel);
                        break;
                    }
                    case 2:
                    {
                        bool isLarge = Selector::chooseSize ("\n Rozmiary:");
                        int sugarLevel = Selector::chooseSugarLevel (0, 5);
                        selectedDrink = make_unique<Latte>(isLarge, sugarLevel);
                        break;
                    }
                    case 3:
                    {
                        bool isLarge = Selector::chooseSize ("\n Rozmiary:");
                        int sugarLevel = Selector::chooseSugarLevel (0, 5);
                        selectedDrink = make_unique<Cappuccino>(isLarge, sugarLevel);
                        break;
                    }
                    case 4:
                    {
                        bool isLarge = Selector::chooseSize ("\n Rozmiary:");
                        int sugarLevel = Selector::chooseSugarLevel (0, 5);
                        selectedDrink = make_unique<Americano>(isLarge, sugarLevel);
                        break;
                    }
                    case 5:
                    {
                        bool isLarge = Selector::chooseSize ("\n Rozmiary:");
                        int sugarLevel = Selector::chooseSugarLevel (0, 5);
                        selectedDrink = make_unique<Mocha>(isLarge, sugarLevel);
                        break;
                    }
                    case 6:
                    {
                        bool isLarge = Selector::chooseSize ("\n Rozmiary:");
                        int sugarLevel = Selector::chooseSugarLevel (0, 5);
                        selectedDrink = make_unique<BlackTea>(isLarge, sugarLevel);
                        break;
                    }
                    case 7:
                    {
                        bool isLarge = Selector::chooseSize ("\n Rozmiary:");
                        int sugarLevel = Selector::chooseSugarLevel (0, 5);
                        selectedDrink = make_unique<GreenTea>(isLarge, sugarLevel);
                        break;
                    }
                    case 8:
                    {
                        bool isLarge = Selector::chooseSize ("\n Rozmiary:");
                        int sugarLevel = Selector::chooseSugarLevel (0, 5);
                        selectedDrink = make_unique<Water>(isLarge, sugarLevel);
                        break;
                    }
                    default:
                        cout << " Nieprawidlowy Wybor Napoju!" << endl;
                        continue;
                }

                coffeeMachine.makeDrink (move (selectedDrink));
                break;
            }
            case 2:
            {
                int moneyToAdd;
                while (true)
                {
                    cout << "\n Podaj Kwote (zl): ";
                    if (cin >> moneyToAdd)
                    {
                        break;
                    }
                    else
                    {
                        cout << " Wprowadz Liczbe Calkowita! Sprobuj Ponownie." << endl;
                        cin.clear();
                        cin.ignore (numeric_limits<streamsize>::max(), '\n');
                    }
                }

                coffeeMachine.addMoney (moneyToAdd);
                break;
            }
            case 3:
            {
                cout << " Dostepne Srodki: " << coffeeMachine.getMoneyInserted() << "zl" << endl;
                break;
            }
            case 4:
            {
                coffeeMachine.dispenseChange (coffeeMachine.getMoneyInserted());
                break;
            }
            case 5:
                cout << " Aktualny Poziom Wody: " << coffeeMachine.getWaterLevel() << "ml" << endl;
                break;
            case 6:
                cout << " Automat Jest " << (coffeeMachine.isMachineCleaned() ? "Wyczyszczony!" : "Niewyczyszczony!") << endl;
                break;
            case 7:
            {
                int waterAmount;
                while (true)
                {
                    cout << "\n Podaj Ilosc Wody Do Dolania (ml): ";
                    if (cin >> waterAmount)
                    {
                        break;
                    }
                    else
                    {
                        cout << " Wprowadz Liczbe Calkowita! Sprobuj Ponownie." << endl;
                        cin.clear();
                        cin.ignore (numeric_limits<streamsize>::max(), '\n');
                    }
                }

                coffeeMachine.addWater (waterAmount);
                break;
            }
            case 8:
                coffeeMachine.cleanMachine();
                cout << " Automat Zostal Wyczyszczony!" << endl;
                break;
            case 9:
                cout << " Liczba Zrobionych Napojow: " << coffeeMachine.getCoffeeCount() << endl;
                break;
            case 10:
                cout << " Dochod Automatu: " << coffeeMachine.getRevenue() << "zl" << endl;
                break;
            case 0:
                cout << " Automat Zostal Wylaczony! \n" << endl;
                return 0;
            default:
                cout << " Nieprawidlowy Wybor! Sprobuj Ponownie." << endl;
        }
    }

    return 0;
}