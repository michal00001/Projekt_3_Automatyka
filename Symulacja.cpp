#include "Symulacja.h"

Symulacja::Symulacja() 
	:czas(0.0)
{
	Pomieszczenie pokoj(3.5,15,10.35);
	budynek = &pokoj;
};
void Symulacja::iteracja(float _deltaT) 
{
	czas += _deltaT; //deltaT - czas uplywajacy w tym kroku
}; 
void Symulacja::przebieg(int _liczbaIteracji, float _czasProbkowania) 
{
	for (int i = 0; i < _liczbaIteracji; i++)
	{
		iteracja(0.05);
		budynek->aktualizuj();
		

	}
};
void Symulacja::zapis(char* _nazwaPliku) 
{};