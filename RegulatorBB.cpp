#include "RegulatorBB.h"

float RegulatorBB::steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt) {
	if (_zmierzonaTemp >= _zadanaTemp) return 0.0;
	else return 1.0;
};