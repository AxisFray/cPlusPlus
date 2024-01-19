#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;
void Dodaj(), Usun(), Losuj(), Wpisz(), menu(),Pokaz(),Zapisz(),Wczytaj();
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
	cout << "[6]  Zapisz do pliku" << endl;
	cout << "[7]  Wczytaj z pliku" << endl;
	cout << "[8]  wyjscie" << endl;
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
		Zapisz();
		break;
	case 7:
		Wczytaj();
		break;
	case 8:
		
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
void Wczytaj()
{
	if (tablica1 == false)
	{
		cout << "najpierw dodaj tablice" << endl;
		menu();
	}
	int i;
	char znak;
	fstream plik;

	string nazwa,plikk;
	
	plik.open("plik.txt", ios::out);
	if (!plik.good()) { Wczytaj(); }
	plik >> plikk;
	for (i = 0; i < rozmiar; i++)
	{
		if(plikk[i]!=' ')
		{
			if(plikk[i]=='1' or plikk[i]=='0' or plikk[i]=='2' or plikk[i]=='3' or plikk[i]=='4' or plikk[i]=='5' or plikk[i]=='6' or plikk[i]=='7' or plikk[i]=='8' or plikk[i]=='9')
				{
				tablica[i]=plikk[i];
			}
			else{cout<< "zle dane" << endl;
			     menu();
			     
		}
		
	}
}
