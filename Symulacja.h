#pragma once
#include "Pomieszczenie.h"
#include <iostream>

class Symulacja
{
public:
	Symulacja();
	void przebieg(int _liczbaIteracji, float _czasProbkowania);
	void zapis(char* _nazwaPliku);

private:
	float czas;
	Pomieszczenie pokoj;

	void iteracja(float _deltaT); //deltaT - czas uplywajacy w tym kroku


};

