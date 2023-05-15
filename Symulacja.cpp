#include "Symulacja.h"

Symulacja::Symulacja() 
	:czas(0.0),
	pokoj(2,5,8),
	ogrzewacz(3500,1000)
{};

void Symulacja::iteracja(float _deltaT=1.0) 
{
	czas += _deltaT; //deltaT - czas uplywajacy w tym kroku
}; 

void Symulacja::przebieg(int _liczbaIteracji, float _czasProbkowania) 
{
	dane.reserve(_liczbaIteracji);
	for (int i = 0; i < _liczbaIteracji; i++)
	{
		iteracja(_czasProbkowania);
		pokoj.dodajCieplo(ogrzewacz.wyemitowaneCieplo(_czasProbkowania));
		std::cout <<"Czas:" << czas << " Cieplo wchodzace " << pokoj.getCieploWchodzace() << std::endl;
		pokoj.aktualizuj(czas);
		std::cout<<"Temperatura pomieszczenia " << pokoj.getTemperatura() << std::endl;
		
		Dane wartosci(czas, pokoj.getTemperatura());
		dane.push_back(wartosci);
	}
};
void Symulacja::zapis(char* _nazwaPliku) 
{
	};