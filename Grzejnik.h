#pragma once
#include <iostream>

class Grzejnik
{

public:
	Grzejnik(float _moc,float _poziom);
	void setmocNominalna(float _moc);
	void setpoziomMocy(float _poziom);
	float wyemitowaneCieplo(float _czasProbkowania) { return mocNominalna * poziomMocy * _czasProbkowania; }; //[W]
	float getmocNominalna() { return mocNominalna; };
	float getpoziomMocy() { return poziomMocy; };
private:
	float mocNominalna; //[W]
	float poziomMocy; //[%] - liczba z zakresu 0 do 1;
};

