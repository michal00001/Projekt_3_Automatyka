#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "Regulator.h"


class Dane
{

private:
	float czas;
	float temperatura;
public:
	Dane(float _czas, float _temp)
		:czas(_czas),
		temperatura(_temp) {};
	float getCzas() { return czas; };
	float getTemperatura() { return temperatura; };
};



class Symulacja
{
public:
	Symulacja();
	void przebieg(int _liczbaIteracji, float _czasProbkowania);
	void zapis(char* _nazwaPliku);

private:
	float czas;
	Pomieszczenie pokoj;
	Grzejnik ogrzewacz;
	std::vector<Dane> dane;
	Regulator* regulator;

	void iteracja(float _deltaT); //deltaT - czas uplywajacy w tym kroku
	
};

