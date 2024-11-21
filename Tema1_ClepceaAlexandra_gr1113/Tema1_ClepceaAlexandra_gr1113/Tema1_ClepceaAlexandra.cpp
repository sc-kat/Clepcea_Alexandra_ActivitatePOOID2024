#include <iostream>
#include <string>
using namespace std;

class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	Autobuz() :idAutobuz(++nrAutobuze) {
		this->capacitate = 30;
		this->nrPersoaneImbarcate = 15;
		this->producator = new char[strlen("WV") + 1];
		strcpy_s(this->producator, strlen("WV") + 1, "WV");
	}

	Autobuz(int capac, int nrPersoaneImbarcate, char* producator) :idAutobuz(++nrAutobuze) {
		this->capacitate = capac;
		if (nrPersoaneImbarcate <= this->capacitate) {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		else {
			this->nrPersoaneImbarcate = 0;
		}
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}


	Autobuz(const Autobuz& autobuz) :idAutobuz(++nrAutobuze) {
		this->capacitate = autobuz.capacitate;
		this->nrPersoaneImbarcate = autobuz.nrPersoaneImbarcate;
		this->producator = new char[strlen(autobuz.producator) + 1];
		strcpy_s(this->producator, strlen(autobuz.producator) + 1, autobuz.producator);

	}

	const Autobuz& operator=(const Autobuz& a) {
		if (this == &a) {
			return *this;
		}
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
		this->producator = new char[strlen(a.producator) + 1];
		strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);

		return *this;
	}

	friend ostream& operator<<(ostream& oStream, const Autobuz& autobuz);

	operator int() const {
		return this->nrPersoaneImbarcate;
	}

	bool operator>(const Autobuz& a) const {
		return this->capacitate > a.capacitate;
	}

	int getCapacitate() {
		return this->capacitate;
	}

	void setCapacitate(int capacitate) {
		this->capacitate = capacitate;
	}

	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	void setNrPersoaneImbarcate(int nrPersImb) {
		this->nrPersoaneImbarcate = nrPersImb;
	}

	void afisare() {   //metoda extra pentru a ma verifica, creata inainte de a supraincarca operatorul <<;
		cout << "Id autobuz: " << this->idAutobuz << endl;
		cout << "Capacitate: " << this->capacitate << endl;
		cout << "Nr persoane imbarcate: " << this->nrPersoaneImbarcate << endl;
		cout << "Producator: " << this->producator << endl;
		cout << endl;
	}

	int getNumarLocuriLibere() {
		return this->capacitate - this->nrPersoaneImbarcate;
	}

	~Autobuz() {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
	}

};

int Autobuz::nrAutobuze = 0;

ostream& operator<<(ostream& oStream, const Autobuz& autobuz) {
	oStream << "Id autobuz: " << autobuz.idAutobuz << "; "
		<< "Capacitate: " << autobuz.capacitate << "; "
		<< "Nr. persoane imbarcate: " << autobuz.nrPersoaneImbarcate << "; "
		<< "Producator: " << autobuz.producator;
	return oStream;
}

int main() {

	char producator[] = "Mercedes-Benz";
	Autobuz autobuz1(106, 30, producator);
	
	cout << "Capacitate initiala autobuz 1: " << autobuz1.getCapacitate() << endl;
	autobuz1.setCapacitate(100);
	cout << "Capacitate noua autobuz 1: " << autobuz1.getCapacitate() << endl;
	cout << endl;

	Autobuz autobuz2;
	//autobuz2.afisare();
	cout << "Numar initial de persoane imbarcate in autobuz 2: " << autobuz2.getNrPersoaneImbarcate() << endl;
	autobuz2.setNrPersoaneImbarcate(3);
	cout << "Numar nou de persoane imbarcate in autobuz 2: " << autobuz2.getNrPersoaneImbarcate() << endl;

	Autobuz autobuz3;
	autobuz3 = autobuz1;
	//autobuz1.afisare();
	//autobuz2.afisare();
	//autobuz3.afisare();

	cout << autobuz1 << endl;
	cout << autobuz2 << endl;
	cout << autobuz3 << endl;
	
	cout << "Locuri libere in autobuz: " << autobuz1.getNumarLocuriLibere() << endl;

	int nrPersAutobuz1 = autobuz1;

	cout << "Numar persoane autobuz 1: " << nrPersAutobuz1 << endl;

	cout << "Dintre autobuzele 1 si 2, care are capacitatea mai mare?" << endl;
	
	if (autobuz1 > autobuz2) {
		cout << "Capacitatea autobuzului 1 este mai mare." << endl;
	}
	else {
		cout << "Capacitatea autobuzului 2 este mai mare sau egala." << endl;
	}
}