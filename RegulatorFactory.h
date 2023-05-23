#pragma once
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
class RegulatorFactory
{
public:
	static Regulator* stworzRegulatorPID(float kp, float ki, float kd);
	static Regulator* stworzRegulatorBB();
};

