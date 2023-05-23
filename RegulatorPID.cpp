#include "RegulatorPID.h"

//float RegulatorPID::steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt) {
//	float moc=0.0;
//	/*obliczanie uchybu - e*/
//	/**/
//	float e = _zadanaTemp - _zmierzonaTemp;
//
//	/*obliczanie wartosci czesci proporcjonalnej*/
//	/**/
//	float Up = Kp * e;
//
//	/*obliczanie wartosci czesci calkujacej*/
//	/*która sumuje (ca³kuje) uchyb w czasie i steruje proporcjonalnie do tej ca³ki:
//	e_calka =e_calka + e (uchyb)* deltaT 
//	ui = Ki * e_calka*/
//	eCalka+= e * _dt;
//	float Ui = Ki * eCalka;
//
//	/*obliczanie wartosci czesci rozniczkujacej*/
//	/**/
//	float de = 0;
//	de = (e - ePoprzednie) / _dt;//dlaczego ePoprzednie jest niezdefiniowany
//	float Ud = Kd * de;
//
//	/*przypisanie wartosci uchybu jako poprzedni uchyb do dalszych obliczen regulatora*/
//	ePoprzednie = e;
//
//	/*wartosc mocy = suma z poszczegolnych czlonow regulatora*/
//	/*ograniczona dla wartosci 0.0-1.0*/
//	float suma = Up + Ui + Ud;
//	std::cout << "Wartosc nastawy dla grzejnika przed korekta wartosci " << suma << std::endl;
//
//	if (suma >= 1.0)	return 1.0;
//	else if (suma <= 0.0)	return 0.0;
//	else return suma;
//	
//};

void RegulatorPID::steruj(float _zadanaTemp,float _dt) {
	float moc = 0.0;
	/*obliczanie uchybu - e*/
	/**/
	float e = _zadanaTemp - pomieszczenie->getTemperatura();
	//std::cout << "Wartosc uchybu " << e << std::endl;
	
	/*obliczanie wartosci czesci proporcjonalnej*/
	/**/
	float Up = Kp * e;

	/*obliczanie wartosci czesci calkujacej*/
	/*która sumuje (ca³kuje) uchyb w czasie i steruje proporcjonalnie do tej ca³ki:
	e_calka =e_calka + e (uchyb)* deltaT
	ui = Ki * e_calka*/
	eCalka += e * _dt;
	//std::cout << "Wartosc calki " << eCalka << std::endl;

	float Ui = Ki * eCalka;

	/*obliczanie wartosci czesci rozniczkujacej*/
	/**/
	float de = 0;
	de = (e - ePoprzednie) / _dt;
	//std::cout << "Wartosc rozniczki " << de << std::endl;

	float Ud = Kd * de;

	/*przypisanie wartosci uchybu jako poprzedni uchyb do dalszych obliczen regulatora*/
	ePoprzednie = e;

	/*wartosc mocy = suma z poszczegolnych czlonow regulatora*/
	/*ograniczona dla wartosci 0.0-1.0*/
	float suma = Up + Ui + Ud;
	std::cout << "Wartosc nastawy dla grzejnika przed korekta wartosci " << suma << std::endl;

	if (suma >= 1.0)	grzejnik->setpoziomMocy(1.0);
	else if (suma <= 0.0)	grzejnik->setpoziomMocy(0.0);
	else grzejnik->setpoziomMocy(suma);

};