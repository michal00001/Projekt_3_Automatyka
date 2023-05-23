#pragma once
#include "Regulator.h"
class RegulatorPID :public Regulator
{
public:
	RegulatorPID() :Kp((float)4.0), Ki((float)0.02), Kd((float)1.0),eCalka((float)0.0),ePoprzednie((float)0.0) {};
	//float steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt);
	void steruj(float _zadanaTemp, float _dt=1.0);
	float getKp() { return Kp; };
	float getKi() { return Ki; };
	float getKd() { return Kd; };

	void setKp(float _Kd) {};
	void setKi(float _Ki) {};
	void setKd(float _Kd) {};

private:
	float Kp;
	float Ki;
	float Kd;
	float eCalka;
	float ePoprzednie;
};

