#include "Symulacja.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"

int main(void) {
	Symulacja pierwsza;
	RegulatorBB bangbang;
	RegulatorPID pidownik;
	pierwsza.setRegulator(&pidownik);
	pierwsza.przebieg(250,1);
	char nazwa[] = "Pliczek.csv";
	pierwsza.zapis(nazwa);
}