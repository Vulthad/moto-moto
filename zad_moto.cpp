//program optymalizacyjny wyznaczaj�cy najwi�ksze pole na podstawie podanego obwodu prostokata

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool czy_int(string dana)									//funkcja weryfikuj�ca, czy wprowadzona liczba jest ca�kowita i og�ln� poprawno��; sprawdzanie po kolei wprowadzonych znak�w
{
	for(int i=0; i<dana.length();i++)
	{
		if(isdigit(dana[i])==false)
		{
			return false;	
		}
	}
	
	return true;
}

void algorytm(int dlugosc, int *a, int *b, int *pole)	//funkcja obliczaj�ca wymiary obszaru
{
	*a= dlugosc / 4;									//wynik por�wnania pochodnej z a(dlugosc-2*a) do zera
	*b= dlugosc - 2 * *a;								//dlugosc drugiego boku wynika z obwodu prostok�ta
	*pole = *a * *b;									//wz�r na pole obszaru prostok�ta, mo�e te� by� uzyskany analitycznie - (dlugosc * *a)-(2 * pow(*a, 2))
}

bool menu()												//true na wyjscie z petli, false na zostanie											
{
	string wejscie;
	int max_dlugosc, max_pole;
	int a, b;
	
	cout<<"Program do obliczania wymiarow dzialki - wpisz \"RUN\" by uruchomi� algorytm; \"STOP\" by wylaczyc program"": "<<endl;
	cin>>wejscie;
	
	transform(wejscie.begin(), wejscie.end(), wejscie.begin(), ::toupper); 	//zamiana na du�e litery wpisanego tekstu by wpisanie np. "run" te� uruchomi�o algorytm; p�tla for i toupper na kazdy znak daje to samo
	
	
	if(wejscie.compare("RUN")==0)
	{
		
		cout<<"Podaj maksymalna dlugosc ogrodzenia: "<<endl;
		cin>>wejscie;
		
		
		max_dlugosc=atoi(wejscie.c_str());									//normalnie przez stoi() ale uparcie wychodzi� b��d, �e "stoi not included in this scope", prawdopodobnie co� z kompilatorem(?)
		
		if(czy_int(wejscie)==true && max_dlugosc>0)							
		{
			algorytm(max_dlugosc, &a, &b, &max_pole);
			system("cls");
			cout<<"Dla podanej dlugosci ogrodzenia rownej "<<max_dlugosc<<" najlepszym rozwiazaniem bedzie wytyczenie obszaru o bokach a= "<<a<<" i b= "<<b<<", pole tego obszaru bedzie wynosic "<<max_pole<<endl;
			return true;	
		}
		else
		{
			system("cls");
			cout<<"Nieprawidlowe dane"<<endl;
			return false;
		}
	}
	
	else if(wejscie.compare("STOP")==0)
	{
		system("cls");
		return true;
	}	
	
	else
	{
		system("cls");
		cout<<"Nieprawidlowy napis, sprobuj jeszcze raz"<<endl;
		return false;
	}
		
}

int main()
{
	
	while(menu()!=true){}
	return 0;
	
}





