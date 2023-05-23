#pragma once
#include <iostream>
#include "Pomieszczenie.h"
#include "Grzejnik.h"

class Regulator
{
public:
	Regulator() :grzejnik(nullptr), pomieszczenie(nullptr) {};
	//_zadanaTemp - wartosc zadana temperatury, 
	//_zmierzonaTemp - wartoœæ zmierzonej w tej chwili temperatury, 
	//_dt - czas miêdzy pomiarami, "krok pomiarowy"
//	virtual float steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt) = 0;	
	virtual void steruj(float _zadanaTemp, float _dt) = 0;

	void setGrzejnik(Grzejnik* _grzejnik) { grzejnik = _grzejnik; };
	void setPomieszczenie(Pomieszczenie* _pomieszczenie) { pomieszczenie = _pomieszczenie; };

protected:
	Grzejnik* grzejnik;
	Pomieszczenie* pomieszczenie;
private:
	Regulator(const Regulator& _obiekt);
	Regulator& operator=(const Regulator& _obiekt);
};

