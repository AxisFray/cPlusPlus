#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;
void Dodaj(), Usun(), Losuj(), Wpisz(), menu(),Pokaz();
bool tablica1 = false;
int* tablica;
int rozmiar;
int main()
{
	menu();



}
void menu()
{
	cout << "[1]  Dodaj tablice" << endl;
	cout << "[2]  Usun tablice" << endl;
	cout << "[3]  Losuj zawartosc tablicy" << endl;
	cout << "[4]  Wpisz zawartosc tablicy" << endl;
	cout << "[5]  Pokaz tablice" << endl;
	cout << "[6]  wyjscie" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		Dodaj();
		break;
	case 2:
		Usun();
		break;
	case 3:
		Losuj();
		break;
	case 4:
		Wpisz();
		break;
	case 5:
		Pokaz();
	case 6:
		system("exit");
		break;
	default:
		cout << "Zly numer" << endl;
		menu();
	}


}
void Dodaj()
{
	
	cout << "Wpisz wielkosc tablicy" << endl;
	cin >>  rozmiar;
	tablica = new int[rozmiar];
	tablica1 = true;
	menu();

}
void Usun()
{
	if (tablica1 == false)
	{
		cout << "najpierw dodaj tablice" << endl;
		menu();
	}
	int w;
	cout << "Wpisz 1 jesli chcesz usunac tablice" << endl;
	cin >> w;
	if (w == 1)
	{
		delete[] tablica;
		menu();
	}
	else { menu(); }
	tablica1 = false;
}
void Wpisz()
{
	if (tablica1 == false)
	{
		cout << "najpierw dodaj tablice" << endl;
		menu();
	}
	
	int wwl;
	cout << "[1] Wpisuj wszystkie po kolei" << endl;
	cout << "[2] Wpisz konkretny element" << endl;
	cin >> wwl;
	if (wwl == 1)
	{
		int i, el;
		for (i = 0; i < rozmiar; i++)
		{
			cout << "Wpisz " << i << " element tablicy" << endl;
			cin >> el;
			tablica[i] = el;
		}
		menu();
	}
	else {
		if (wwl == 2)
		{
			int ell,ell1;
			cout << "Ktory element chcesz podac ?" << endl;
			cin >> ell;
			cout << "Jaki element chcesz dodac?" << endl;
			cin >> ell1;
			if (ell > rozmiar or ell < 0) { menu(); }
			else {
				tablica[ell] = ell1;
				Dodaj();
			}
		}
	}
}
void Losuj()
{
	if (tablica1 == false)
	{
		cout << "najpierw dodaj tablice" << endl;
		menu();
	}
	int j,p,pp;
	cout << "Podaj przedzial liczb od..." << endl;
	cin >> pp;
	cout << "Podaj przedzial od  "<< pp<<"  do ..." << endl;
	cin >> p;
	for (j = 0; j < rozmiar; j++)
	{
		tablica[j] = (rand() % p)+pp;
	}
	menu();
}
void Pokaz()
{
	int i,ii;
	for (i = 0; i < rozmiar; i++)
	{
		cout <<i+1<<". " << tablica[i] << endl;
	}
	cout << "[1]  Wpisz aby przejsc do menu" << endl;
	while (true)
	{
		cin >> ii;
		if (ii == 1)
		{
			menu();
		}
	}
	

}
