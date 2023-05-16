#pragma once
#include <iostream>

class Grzejnik
{

public:
	Grzejnik(float _moc,float _poziom);
	void setpoziomMocy(float _poziom);
	float wyemitowaneCieplo(float _czasProbkowania) { return mocNominalna * poziomMocy * _czasProbkowania; }; //[W]

private:
	float mocNominalna; //[W]
	float poziomMocy; //[%] - liczba z zakresu 0 do 1;

};

