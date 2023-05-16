#include "RegulatorPID.h"

float RegulatorPID::steruj(float _zadanaTemp, float _zmierzonaTemp, float _dt) {
	float moc=0.0;
	/*obliczanie uchybu - e*/
	/**/
	float e = _zadanaTemp - _zmierzonaTemp;

	/*obliczanie wartosci czesci proporcjonalnej*/
	/**/
	float Up = Kp * e;

	/*obliczanie wartosci czesci calkujacej*/
	/*która sumuje (ca³kuje) uchyb w czasie i steruje proporcjonalnie do tej ca³ki:
	e_calka =e_calka + e (uchyb)* deltaT 
	ui = Ki * e_calka*/
	eCalka+= e * _dt;
	float Ui = Ki * eCalka;

	/*obliczanie wartosci czesci rozniczkujacej*/
	/**/
	float de = 0;
	de = (e - ePoprzednie) / _dt;//dlaczego ePoprzednie jest niezdefiniowany
	float Ud = Kd * de;

	/*przypisanie wartosci uchybu jako poprzedni uchyb do dalszych obliczen regulatora*/
	ePoprzednie = e;

	/*wartosc mocy = suma z poszczegolnych czlonow regulatora*/
	return Up+Ui+Ud;
};

