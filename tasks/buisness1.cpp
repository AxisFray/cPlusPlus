#include <iostream>;
#include <cstdio>;
#include <conio.h>;
#include <windows.h>;
#include <time.h>;
#include <cstdlib>
#include <ctime>
#include <math.h>;

int x;
float money = 300.0;
float increasebuy = 1, increasesell = 1;
float bankacc = 0.0;
int choice;
int number1, number2;
using namespace std;
float properties[6];// 1pen 2usb  3hardrive 4keyboard 5computer 6cars
float pricessell[6];
float pricesbuy[6];
string text[9];
string names[6];
void Play(), Keyy(), Bank(), Owned(), Equipment(), settings();


int main()
{
    settings();
    Play();


}
int random(int a, int b)
{
    srand(time(NULL));
    int random = a + rand() % b;
    return random;

}
void Event()
{
    int charge;
    float zakr1 = money * 0.1 / 1;
    float zakr2 = money * 0.9 / 1;
    charge = random(zakr1, zakr2);
    text[0] = "za nocleg w hotelu placisz " + charge;
    text[1] = "placisz mandat wynoszacy :" + charge;
    text[2] = "zrobiles wspaniale zakupy,placisz " + charge;
    text[3] = "za przejazd placisz " + charge;
    text[4] = "kupiles po drodze pamiatki, placisz " + charge;
    text[5] = "odwiedziles okoliczne atrakcje turystyczne,\n placisz " + charge;
    text[6] = "kolega oferuje ci darmowy przejazd samolotem w zamian \n w zamian za pomoc dawno temu \n nic nie tracisz";
    text[7] = "dostales spadek od babci,\n otrzymujesz " + charge;
    text[8] = "nocowales u rodziny, zaoszczedziles pieniadze,\n otrzymujesz " + charge;

}
void settings()
{
    pricesbuy[0] = 2;
    pricesbuy[1] = 5;
    pricesbuy[2] = 70;
    pricesbuy[3] = 130;
    pricesbuy[4] = 250;
    pricesbuy[5] = 500;

    pricessell[0] = 2;
    pricessell[1] = 5;
    pricessell[2] = 70;
    pricessell[3] = 130;
    pricessell[4] = 250;
    pricessell[5] = 500;
    names[0] = "pen";
    names[1] = "usb";
    names[2] = "harddrive";
    names[3] = "keyboard";
    names[4] = "computer";
    names[5] = "car";
}


float Round0(float liczba)
{
    float wynik = liczba * 100;
    int a = (int)wynik;
    wynik = (float)a / 100;
    return wynik;
}

void Play()
{
    system("cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=BUSINESS-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");


    cout << "    money    -- " << Round0(money) << endl;
    cout << "    bank account -- " << Round0(bankacc) << endl;
    printf("                  [1] - INFO               \n");
    printf("                  [2] - BANK               \n");
    printf("                  [3] - KUP                \n");
    printf("                  [4] - SPRZEDAJ           \n");
    printf("                  [5] - WYJDZ              \n");
    printf("                  [6] - EKWIPUNEK          \n");
    printf("                  [7] - WYLOT              \n");
    printf("                                                                                      \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    Keyy();
}

void Info()
{
    system("cls");
    int infochoice;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=INFO-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("                                                                                     \n");
    printf("    wpisz liczby w nawiasach kwadratowych aby dostac sie do okreslonych miejsc       \n");
    printf("                       kupuj i sprzedawaj produkty aby sie wzbogacic                 \n");
    printf("               wplacaj pieniadze do banku aby nie straci ich w czasie gry            \n");
    printf("                                                                                     \n");
    printf("                            [1] - POWROT DO MENU GLOWNEGO                            \n");
    printf("                                                                                     \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    cin >> infochoice;
    if (infochoice == 1) { Play(); }
    else { Info(); }
}
void Bank()
{
    int bankchoice;
    float value;
    value = 0;
    system("cls");
    
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=BANK=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("                                                                                     \n");
    cout << "    money    -- " << Round0(money) << endl;
    cout << "    bank account -- " << Round0(bankacc) << endl;
    printf("       [1]   WPLAC   \n");
    printf("       [2]   WYPLAC  \n");
    printf("       [3]   POWROT DO MENU GLOWNEGO\n");
    printf("                                                                                     \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    cout << "Wybierz numer 1 - 3\n";
    cin >> bankchoice;
    if (bankchoice == 3) //menu
    {
        Play();
    }
    cout << "Ile pieniedzy chcesz wplacic / wyplacic \n";
    cin >> value;
    if(bankchoice==1) //wplac do banku
    {
        if (money < value)
        {
            system("cls");
            cout << "Zbyt malo pieniedzy aby wplacic\n";
            Sleep(1500);
            system("cls");
            Play();
        }
        bankacc += value;
        money -= value;
        Play();
        }
    
    if (bankchoice == 2)  //wyplac z banku
    {
        if (bankacc < value)
        {
            system("cls");
            cout << "Zbyt malo pieniedzy aby wyplacic\n";
            Sleep(150);
            system("cls");
            Bank();
        }
        else
        {
            bankacc -= value;
            money += value;
            Play();
        }
    }
    
}
void Buy()
{   
    
    system("cls");
    int buychoice, buynumber;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=KUP-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    cout << "                      WYBOR                 CENA KUPNA" << endl;
    cout << "                    [1] - pen         " << Round0(pricesbuy[0]) << endl;
    cout << "                    [2] - usb         " << Round0(pricesbuy[1]) << endl;
    cout << "                    [3] - harddrive   " << Round0(pricesbuy[2]) << endl;
    cout << "                    [4] - keyboard    " << Round0(pricesbuy[3]) << endl;
    cout << "                    [5] - computer    " << Round0(pricesbuy[4]) << endl;
    cout << "                    [6] - car         " << Round0(pricesbuy[5]) << endl;
    cout << "                    [7] - Powrot do menu" << endl;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    Owned();
    printf("Wybierz numer 1 - 7 \n");
    cin >> buychoice;
    if (buychoice <= 0 or buychoice >= 8)
    {
        system("cls");
        printf("          WPISZ LICZBE 1 - 7          ");
        Sleep(1800);
        system("cls");
        Buy();
    }
    if (buychoice == 7) { Play(); }
    cout << "Ile chcesz kupic " << names[buychoice - 1] << endl;
    cin >> buynumber;
    buychoice -= 1;
    if (money >= pricesbuy[buychoice] * buynumber)
    {
        properties[buychoice] += buynumber;
        money -= pricesbuy[buychoice] * buynumber;
        Play();
    }
    if (money < pricesbuy[buychoice] * buynumber)
    {
        system("cls");
        printf("              NIE MASZ WYSTARCZAJACO PIENIEDZY         ");
        Sleep(1800);
        system("cls");
        Buy();
    }
    
}
void Sell()
{
    system("cls");
    int sellchoice, sellnumber;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=SPRZEDAJ-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    cout << "                      WYBOR                 CENA SPRZEDAZY " << endl;
    cout << "                    [1] - pen         " << Round0(pricessell[0]) << endl;
    cout << "                    [2] - usb         " << Round0(pricessell[1]) << endl;
    cout << "                    [3] - harddrive   " << Round0(pricessell[2]) << endl;
    cout << "                    [4] - keyboard    " << Round0(pricessell[3]) << endl;
    cout << "                    [5] - computer    " << Round0(pricessell[4]) << endl;
    cout << "                    [6] - car         " << Round0(pricessell[5]) << endl;
    cout << "                    [7] - Powrot do menu" << endl;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    Owned();
    printf("Wybierz numer 1 - 7\n");
    cin >> sellchoice;
    if (sellchoice == 7) { Play(); }
    cout << "Ile chcesz sprzedac  :" << names[sellchoice - 1] << endl;
    cin >> sellnumber;
    
    if(sellchoice <= 0 || sellchoice >=8)
    {
        system("cls");
        printf("               WPISZ LICZBE 1 - 7                 ");
        Sleep(1800);
        system("cls");
        Buy();
    }
    sellchoice -= 1;
    if (properties[sellchoice] >=  sellnumber)
    {
        properties[sellchoice] -= sellnumber;
        money += pricessell[sellchoice] * sellnumber;
        
    }
    Play();
}
void Equipment()
{
    system("cls");
    int equichoice;
    cout << "          POSIADANE           " << endl;
    int w;
    for (w = 0; w <= 5; w++)
    {
        cout << "posiadasz :" << properties[w] << "    " << names[w] << endl;
    }
    printf("    [1] - Przejdz do menu");
    cin >> equichoice;
    if (equichoice == 1)
    {
        Play();
    }
    else
    {
        Equipment();
    }
        
}

void CheckNum()
{
    if (number1 == 1)
    {
        increasesell = 1.25;
    }
    if (number1 == 2)
    {
        increasesell = 0.8;
    }
    if (number1 == 3)
    {
        increasesell = 1.3;
    }
    if (number1 == 4)
    {
        increasesell = 1.2;
    }
    if (number1 == 5)
    {
        increasesell = 1.5;
    }
    if (number1 == 6)
    {
        increasesell = 1.7;
    }
    if (number1 == 7)
    {
        increasesell = 1.9;
    }
    if (number1 == 8)
    {
        increasesell = 1.3;
    }
    if (number1 == 9)
    {
        increasesell = 0.6;
    }
    if (number1 == 10)
    {
        increasesell = 0.75;
    }
    if (number2 == 1)
    {
        increasebuy = 1.25;
    }
    if (number2 == 2)
    {
        increasebuy = 0.8;
    }
    if (number2 == 3)
    {
        increasebuy = 1.3;
    }
    if (number2 == 4)
    {
        increasebuy = 1.2;
    }
    if (number2 == 5)
    {
        increasebuy = 1.5;
    }
    if (number2 == 6)
    {
        increasebuy = 1.7;
    }
    if (number2 == 7)
    {
        increasebuy = 1.9;
    }
    if (number2 == 8)
    {
        increasebuy = 1.3;
    }
    if (number2 == 9)
    {
        increasebuy = 0.6;
    }
    if (number2 == 10)
    {
        increasebuy = 0.75;
    }
}
void IncPrice()
{
    
    number1 = random(1, 10);
    number2 = random(1, 10);
    CheckNum();


    for(x = 0; x <= 5; x++)
    {
        pricesbuy[x] *= increasebuy;
        pricessell[x] *= increasesell;
        Round0(pricesbuy[x]);
        Round0(pricessell[x]);
    }
}


//1pen 2usb  3hardrive 4keyboard 5computer 6cars



void Keyy()
{
    cout << "Wpisz wartosc 1 - 7\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        Info();
        break;
    case 2:
        Bank();
        break;
    case 3:
        Buy();
        break;
    case 4:
        Sell();
        break;
    case 5:
        exit(0);
        break;
    case 6:
        Equipment();
        break;
    case 7:
        IncPrice();
        Event();
        Play();
        break;
    default:
        Play();
        break;
    }

}



void Owned()
{
    cout << "          POSIADANE           " << endl;
    int w;
    for (w = 0; w <= 5; w++)
    {
        cout << "posiadasz :" << properties[w] << "    " << names[w] << endl;
    }

}
