#pragma once
class Regulator
{
public:
	virtual float steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt);	//_zadanaTemp - wartosc zadana temperatury,
																				//_zmierzonaTemp - wartoœæ zmierzonej w tej chwili temperatury,
																				//_dt - czas miêdzy pomiarami, "krok pomiarowy"
};

