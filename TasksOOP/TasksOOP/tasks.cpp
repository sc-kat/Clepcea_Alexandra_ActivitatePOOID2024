#include <iostream>
#include <cstring>

using namespace std;

//Industrie: Croitorie

class Pantalon {
public:
	const int marime;
	char* culoare;
	string material;
	static int nrPantaloni;

	Pantalon() :marime(32) {
		this -> culoare = new char[strlen("Alb") + 1];
		strcpy_s(this->culoare, strlen("Alb") + 1, "Alb");
		this -> material = "In";
		nrPantaloni++;
	}

	Pantalon(int marime, char* culoare,string material) :marime(marime) {
		this -> culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		this -> material = material;
		nrPantaloni++;
	}

	Pantalon(int marime, char* culoare) :marime(marime) {
		this -> culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		this->material = "Bumbac";
		nrPantaloni++;
	}

};
int Pantalon::nrPantaloni = 0;

class Bluza {
public:
	const int marime;
	char* culoare;
	string tipManeca;
	static int nrBluze;

	Bluza() :marime(40) {
		this->culoare = new char[strlen("Alb") + 1];
		strcpy_s(this->culoare, strlen("Alb") + 1, "Alb");
		this->tipManeca = "Lunga";
		nrBluze++;
	}

	Bluza(int marime, char* culoare, string tipManeca) :marime(marime) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		this->tipManeca = tipManeca;
		nrBluze++;
	}

	Bluza(int marime, char* culoare) :marime(marime) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		this->tipManeca = "Scurta";
		nrBluze++;
	}

};
int Bluza::nrBluze = 0;

class Fusta {
public:
	const int marime;
	char* culoare;
	string tipLungime;
	static int nrFuste;

	Fusta() :marime(42) {
		this->culoare = new char[strlen("Roz")+1];
		strcpy_s(this->culoare, strlen("Roz") + 1, "Roz");
		this->tipLungime = "Midi";
		nrFuste++;
	}

	Fusta(int marime, char* culoare, string tipLungime) :marime(marime) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		this->tipLungime = tipLungime;
		nrFuste++;
	}

	Fusta(int marime, char* culoare) :marime(marime) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		this->tipLungime = "Mini";
		nrFuste++;
	}
};
int Fusta::nrFuste = 0;

int main() {

}
