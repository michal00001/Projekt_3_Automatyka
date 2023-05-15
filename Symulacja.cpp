#include "Symulacja.h"

Symulacja::Symulacja() 
	:czas(0.0),
	pokoj(2,5,8)
{
	;
};
void Symulacja::iteracja(float _deltaT=1.0) 
{
	czas += _deltaT; //deltaT - czas uplywajacy w tym kroku
}; 
void Symulacja::przebieg(int _liczbaIteracji, float _czasProbkowania) 
{
	for (int i = 0; i < _liczbaIteracji; i++)
	{
		iteracja(_czasProbkowania);
		pokoj.aktualizuj(czas);
		std::cout<<"Czas:"<< czas << " Temperatura pomieszczenia " << pokoj.getTemperatura() << std::endl;
		//std::cout << "Cieplo wchodzace " << budynek->getCieploWchodzace() << std::endl;

	}
};
void Symulacja::zapis(char* _nazwaPliku) 
{};