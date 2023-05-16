#include "RegulatorBB.h"

//float RegulatorBB::steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt) {
//	if (_zmierzonaTemp >= _zadanaTemp) {
//		std::cout << "Wylaczono grzanie\n";
//		return 0.0;
//	}
//	else {
//		std::cout << "Wlaczono grzanie\n";
//		return 1.0;
//	}
//};

void RegulatorBB::steruj(float _zadanaTemp, float _dt) {
	if (pomieszczenie->getTemperatura() >= _zadanaTemp) {
		std::cout << "Wylaczono grzanie\n";
		grzejnik->setpoziomMocy(0.0);
	}
	else {
		std::cout << "Wlaczono grzanie\n";
		grzejnik->setpoziomMocy(1.0);
	}
};