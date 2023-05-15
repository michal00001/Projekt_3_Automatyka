#include "Grzejnik.h"

Grzejnik::Grzejnik(float _moc, float _poziom) 
{
	if (_moc < 0.0) mocNominalna = -_moc;
	else mocNominalna = _moc;

	if (_poziom > 1.0) {
		std::cout << "Podano nieprawidlowy (za duzy) poziom mocy\n";
			poziomMocy = 1.0;
	}
	else if (_poziom < 0.0) {
		std::cout << "Podano nieprawidlowy (za maly) poziom mocy\n";
		poziomMocy = 0.0;
	}
	else poziomMocy = _poziom;
};