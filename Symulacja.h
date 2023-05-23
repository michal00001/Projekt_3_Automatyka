#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include <iostream>
#include <vector>
#include <fstream>



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
	void setRegulator(Regulator* _regulator);

private:
	float czas;
	Pomieszczenie pokoj;
	Grzejnik ogrzewacz;
	std::vector<Dane> dane;
	Regulator* regulator;

	void iteracja(float _deltaT); //deltaT - czas uplywajacy w tym kroku
	Symulacja(const Symulacja& obiekt);
	Symulacja& operator=(const Symulacja& _obiekt);
};

