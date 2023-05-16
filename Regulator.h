#pragma once
class Regulator
{
	virtual float steruj(float _temp, float _wartoscZmierzona, float _dt);
};

