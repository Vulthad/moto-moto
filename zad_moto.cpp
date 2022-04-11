//program optymalizacyjny wyznaczający największe pole na podstawie podanego obwodu prostokata

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool czy_int(string dana)									//funkcja weryfikująca, czy wprowadzona liczba jest całkowita i ogólną poprawność; sprawdzanie po kolei wprowadzonych znaków
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

void algorytm(int dlugosc, int *a, int *b, int *pole)	//funkcja obliczająca wymiary obszaru
{
	*a= dlugosc / 4;									//wynik porównania pochodnej z a(dlugosc-2*a) do zera
	*b= dlugosc - 2 * *a;								//dlugosc drugiego boku wynika z obwodu prostokąta
	*pole = *a * *b;									//wzór na pole obszaru prostokąta, może też być uzyskany analitycznie - (dlugosc * *a)-(2 * pow(*a, 2))
}

bool menu()												//true na wyjscie z petli, false na zostanie											
{
	string wejscie;
	int max_dlugosc, max_pole;
	int a, b;
	
	cout<<"Program do obliczania wymiarow dzialki - wpisz \"RUN\" by uruchomić algorytm; \"STOP\" by wylaczyc program"": "<<endl;
	cin>>wejscie;
	
	transform(wejscie.begin(), wejscie.end(), wejscie.begin(), ::toupper); 	//zamiana na duże litery wpisanego tekstu by wpisanie np. "run" też uruchomiło algorytm; pętla for i toupper na kazdy znak daje to samo
	
	
	if(wejscie.compare("RUN")==0)
	{
		
		cout<<"Podaj maksymalna dlugosc ogrodzenia: "<<endl;
		cin>>wejscie;
		
		
		max_dlugosc=atoi(wejscie.c_str());									//normalnie przez stoi() ale uparcie wychodził błąd, że "stoi not included in this scope", prawdopodobnie coś z kompilatorem(?)
		
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
	
	system("pause");
	return 0;
	
}





