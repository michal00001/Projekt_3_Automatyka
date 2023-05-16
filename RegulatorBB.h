#pragma once
#include "Regulator.h"
class RegulatorBB :public Regulator
{
public:
	//float steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt);
	void steruj(float _zadanaTemp, float _dt);
private:

};

