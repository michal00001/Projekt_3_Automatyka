#include "Symulacja.h"

int main(void) {
	Symulacja pierwsza;
	pierwsza.przebieg(25,1);
	char nazwa[] = "Pliczek.csv";
	pierwsza.zapis(nazwa);
}