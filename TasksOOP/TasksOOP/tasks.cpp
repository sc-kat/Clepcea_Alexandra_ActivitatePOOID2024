#include <iostream>
#include <cstring>

using namespace std;

//Industrie: Croitorie

class Pantalon {
private:
	const int marime;
	char* culoare;
	string material;
	static int nrPantaloni;

	//tentative TODO adaugare atribut cu nrVerificari, string* Verificator(?)

public:
	
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

	~Pantalon() {
		if (this->culoare != nullptr) {
			delete[] this->culoare;
		}
	}

	static void afiseazaNrPantaloni() {
		cout << "Pana acum ";
		if (nrPantaloni == 1) {
			cout << "s-a croit o pereche de pantaloni." << endl;
		}
		else {
			cout << "s-au croit " << nrPantaloni << " perechi de pantaloni." << endl;
		}
	}

	void afisare() {
		cout << "Marime: " << this->marime << endl;
		cout << "Culoare: " << this->culoare << endl;
		cout << "Material: " << this->material << endl;
		cout << "Numar pantaloni: " << nrPantaloni << endl;
		cout << endl;
	}
};
int Pantalon::nrPantaloni = 0;

class Bluza {
private:
	const int marime;
	char* culoare;
	string tipManeca;
	static int nrBluze;

public:

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

	~Bluza() {
		if (this->culoare != nullptr) {
			delete[]this->culoare;
		}
	}

	static void afiseazaNrBluza() {
		cout << "Pana acum ";
		if (nrBluze == 1) {
			cout << "s-a croit o bluza." << endl;
		}
		else {
			cout << "s-au croit " << nrBluze << " bluze." << endl;
		}
	}

	void afisare() {
		cout << "Marime: " << this->marime << endl;
		cout << "Culoare: " << this->culoare << endl;
		cout << "Material: " << this->tipManeca << endl;
		cout << "Numar pantaloni: " << nrBluze << endl;
		cout << endl;
	}

};
int Bluza::nrBluze = 0;

class Fusta {
private:
	const int marime;
	char* culoare;
	string tipLungime;
	static int nrFuste;

public:

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

	~Fusta() {
		if (this->culoare != nullptr) {
			delete[]this->culoare;
		}
	}

	static void afiseazaNrFuste() {
		cout << "Pana acum ";
		if (nrFuste == 1) {
			cout << "s-a croit o fuste." << endl;
		}
		else {
			cout << "s-au croit " << nrFuste << " fuste." << endl;
		}
	}

	void afisare() {
		cout << "Marime: " << this->marime << endl;
		cout << "Culoare: " << this->culoare << endl;
		cout << "Material: " << this->tipLungime << endl;
		cout << "Numar pantaloni: " << nrFuste << endl;
		cout << endl;
	}
};
int Fusta::nrFuste = 0;

int main() {
	
	Pantalon pant1;
	pant1.afisare();

	Pantalon pant2(46, (char*)"Negru");
	pant2.afisare();

	Pantalon pant3(40, (char*)"Gri", "bumbac");
	pant3.afisare();

	Pantalon::afiseazaNrPantaloni();


	return 0;
}
