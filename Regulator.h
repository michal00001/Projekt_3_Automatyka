#pragma once
class Regulator
{
public:
	virtual float steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt);	//_zadanaTemp - wartosc zadana temperatury,
																				//_zmierzonaTemp - warto�� zmierzonej w tej chwili temperatury,
																				//_dt - czas mi�dzy pomiarami, "krok pomiarowy"
};

