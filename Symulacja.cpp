#include "Symulacja.h"

std::ostream& operator<<(std::ostream& out, Dane& dane) {
	out << dane.getCzas()<<";" << dane.getTemperatura() << std::endl;
	return out;
};

Symulacja::Symulacja()
	:czas(0.0),
	pokoj(3.5, 10, 12),
	ogrzewacz(10000, 0),
	regulator(nullptr)
{};

void Symulacja::setRegulator(Regulator* _regulator) {
	regulator = _regulator;
}

void Symulacja::iteracja(float _deltaT=1.0) 
{
	czas += _deltaT; //deltaT - czas uplywajacy w tym kroku
}; 

void Symulacja::przebieg(int _liczbaIteracji, float _czasProbkowania) 
{
	try {
	if (regulator == nullptr) throw "Nie dodano instancji regulatora!";
	}
	catch (const char*) {
		std::cout << "Nie wybrano zadnego regulatora!" << std::endl;
		return;
	}
	regulator->setGrzejnik(&ogrzewacz);

	regulator->setPomieszczenie(&pokoj);

	dane.reserve(_liczbaIteracji);

	for (int i = 0; i < _liczbaIteracji; i++)
	{
		iteracja(_czasProbkowania);

		//ogrzewacz.setpoziomMocy(regulator->steruj(22.0, pokoj.getTemperatura(), _czasProbkowania));

		regulator->steruj(22.0, _czasProbkowania);

		std::cout << "Wartosc nastawy dla grzejnika " << ogrzewacz.getpoziomMocy() << std::endl;
		pokoj.dodajCieplo(ogrzewacz.wyemitowaneCieplo(_czasProbkowania));

		std::cout <<"Czas:" << czas << " Cieplo wchodzace " << pokoj.getCieploWchodzace() << std::endl;
		pokoj.aktualizuj(_czasProbkowania);
		std::cout<<"Temperatura pomieszczenia " << pokoj.getTemperatura() << std::endl << std::endl;
		
		Dane wartosci(czas, pokoj.getTemperatura());
		dane.push_back(wartosci);
	}
};

void Symulacja::zapis(char* _nazwaPliku) 
{
	std::ofstream plik;
	plik.open(_nazwaPliku, std::ofstream::out);
	std::locale pol("pl_PL");
	plik.imbue(pol);
	if(plik.good()){
			plik << "Czas [s];Temperatura [*C]\n";
		for (int i = 0; i < dane.size(); i++)
		{
			plik << dane[i];
		}
		plik.close();
	}
	else {
		std::cout << "Nie otwarto pliku!"<<std::endl;
	}
};