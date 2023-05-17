#include "Symulacja.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"

int main(void) {
	Symulacja pierwsza;
	RegulatorBB bangbang;
	RegulatorPID pidownik;
	char nazwa[17];

	int x = 0;
	while (x < 1 || x>2) {
		std::cout << "Wybierz regulator\n" << "1\tRegulator dwupolozeniowy\n" << "2\tRegulator PID\n";
		while (1) { //niesko�czona p�tla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b��du
				std::cout << "Wykryto blad" << std::endl; //komunikat o b��dzie
				std::cin.clear(); //resetowanie flag b��du
				std::cin.ignore(256, '\n'); //czyszczenie 256 znak�w bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
	}
	//if (x ==1)
	//{
	//	pierwsza.setRegulator(&bangbang);
	//	strcpy_s(nazwa,"_RegulatorBB.csv");
	//}
	//else
	//{
	//	pierwsza.setRegulator(&pidownik);
	//	strcpy_s(nazwa, "RegulatorPID.csv");
	//}
	try{
		pierwsza.przebieg(250, 1);
	}
	catch (const char*) {
		std::cout << "Nie wybrano zadnego regulatora!" << std::endl;
	}
	pierwsza.zapis(nazwa);
}