#pragma once
#include "Pomieszczenie.h"

class Symulacja
{
	float czas;
	Pomieszczenie* budynek;

public:
	Symulacja();
	void iteracja(float _deltaT); //deltaT - czas uplywajacy w tym kroku
	void przebieg(int _liczbaIteracji, float _czasProbkowania);
	void zapis(char* _nazwaPliku);
};

