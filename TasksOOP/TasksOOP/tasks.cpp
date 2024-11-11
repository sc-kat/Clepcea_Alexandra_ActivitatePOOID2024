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

	Pantalon(const Pantalon& p) :marime(p.marime) {
		this->culoare = new char[strlen(p.culoare)+1];
		strcpy_s(this->culoare, strlen(p.culoare) + 1, p.culoare);
		this->material = p.material;
	}

	~Pantalon() {
		if (this->culoare != nullptr) {
			delete[] this->culoare;
		}
	}

	int getMarime() {
		return this->marime;
	}
	char* getCuloare() {
		return this->culoare;
	}

	//void setCuloare()

	static void afiseazaNrPantaloni() {
		cout << "Pana acum ";
		if (nrPantaloni == 1) {
			cout << "s-a croit o pereche de pantaloni." << endl;
		}
		else {
			cout << "s-au croit " << nrPantaloni << " perechi de pantaloni." << endl;
		}
		cout << endl;
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

	Bluza(const Bluza& b) :marime(b.marime) {
		this->culoare = new char[strlen(b.culoare) + 1];
		strcpy_s(this->culoare, strlen(b.culoare) + 1, b.culoare);
		this->tipManeca = b.tipManeca;
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
		cout << endl;
	}

	void afisare() {
		cout << "Marime: " << this->marime << endl;
		cout << "Culoare: " << this->culoare << endl;
		cout << "Material: " << this->tipManeca << endl;
		cout << "Numar bluze: " << nrBluze << endl;
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

	Fusta(const Fusta& f) :marime(f.marime) {
		this->culoare = new char[strlen(f.culoare) + 1];
		strcpy_s(this->culoare, strlen(f.culoare) + 1, f.culoare);
		this->tipLungime = f.tipLungime;
	}

	~Fusta() {
		if (this->culoare != nullptr) {
			delete[]this->culoare;
		}
	}

	static void afiseazaNrFuste() {
		cout << "Pana acum ";
		if (nrFuste == 1) {
			cout << "s-a croit o fusta." << endl;
		}
		else {
			cout << "s-au croit " << nrFuste << " fuste." << endl;
		}
		cout << endl;
	}

	void afisare() {
		cout << "Marime: " << this->marime << endl;
		cout << "Culoare: " << this->culoare << endl;
		cout << "Material: " << this->tipLungime << endl;
		cout << "Numar fuste: " << nrFuste << endl;
		cout << endl;
	}
};
int Fusta::nrFuste = 0;


int main() {
	
	//Pantalon pant1;
	//pant1.afisare();

	//Pantalon pant2(46, (char*)"Negru");
	//pant2.afisare();

	//Pantalon pant3(40, (char*)"Gri", "bumbac");
	//pant3.afisare();

	//Pantalon::afiseazaNrPantaloni();

	/*Bluza bluza1;
	bluza1.afisare();

	Bluza bluza2(36, (char*)"Maro");
	bluza2.afisare();

	Bluza bluza3(38, (char*)"Turcoz", "bufanta");
	bluza3.afisare();

	Bluza::afiseazaNrBluza();

	Fusta fusta1;
	fusta1.afisare();

	Fusta::afiseazaNrFuste();

	Fusta fusta2(44, (char*)"Mov", "Midi");
	fusta2.afisare();

	Fusta::afiseazaNrFuste();

	Fusta fusta3(50, (char*)"Lila", "Lunga");
	fusta3.afisare();

	Fusta::afiseazaNrFuste();*/

	

	return 0;
}
