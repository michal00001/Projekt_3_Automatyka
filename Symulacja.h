#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include <iostream>
#include <vector>

class Dane
{
private:
	float czas;
	float temperatura;
public:
	Dane(float _czas, float _temp)
		:czas(_czas),
		temperatura(_temp) {};
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

	void iteracja(float _deltaT); //deltaT - czas uplywajacy w tym kroku


};

