#include "Symulacja.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include "RegulatorFactory.h"

int main(void) {
	Symulacja pierwsza;
	Regulator* regulator = nullptr;
	/*RegulatorBB bangbang;
	RegulatorPID pidownik;*/
	char nazwa[17];

	int x = 0;
	while (x < 1 || x>2) {
		std::cout << "Wybierz regulator\n" << "1\tRegulator dwupolozeniowy\n" << "2\tRegulator PID\n";
		while (1) {
			std::cin >> x; 
			if (std::cin.fail() == true) { 
				std::cout << "Wykryto blad" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else break;
		}
	}
	if (x == 1)
	{
		regulator = RegulatorFactory::stworzRegulatorBB();
		//pierwsza.setRegulator(&bangbang);
		pierwsza.setRegulator(regulator);
		strcpy_s(nazwa,"_RegulatorBB.csv");
	}
	else
	{
		regulator = RegulatorFactory::stworzRegulatorPID(0.5, 0.2, 0.1);
		//pierwsza.setRegulator(&pidownik);
		pierwsza.setRegulator(regulator);
		strcpy_s(nazwa, "RegulatorPID.csv");
	}
	
	pierwsza.przebieg(250, 1);
	
	pierwsza.zapis(nazwa);
}