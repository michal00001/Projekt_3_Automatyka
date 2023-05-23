#include "RegulatorFactory.h"

Regulator* RegulatorFactory::stworzRegulatorPID(float kp, float ki, float kd) {
	RegulatorPID* regulatorPID = new RegulatorPID();

	return regulatorPID;
};

Regulator* RegulatorFactory::stworzRegulatorBB() {
	RegulatorBB* regulatorBB = new RegulatorBB();

	return regulatorBB;
}