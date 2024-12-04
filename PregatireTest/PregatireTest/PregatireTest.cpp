#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Farmacie {

private:
	static int contorCID;
	const int codUnic;
	string adresa;
	int nrMedicamente;
	float* preturi;

public:
	Farmacie() :codUnic(++contorCID) {
		this->adresa = "Depozit Central";
		this->nrMedicamente = 0;
		this->preturi = nullptr;
	}

	Farmacie(string adresa, int nrMedicamente, float* preturi) :codUnic(++contorCID) {
		this->adresa = adresa;
		if (nrMedicamente >= 0) {
			this->nrMedicamente = nrMedicamente;
		}
		this->preturi = new float[nrMedicamente];
		for (int i = 0; i < nrMedicamente; i++) {
			if (preturi[i] >= 0) {
				this->preturi[i] = preturi[i];
			}
		}
	}

	Farmacie(const Farmacie& f) :codUnic(++contorCID) {
		this->adresa = f.adresa;
		this->nrMedicamente = f.nrMedicamente;
		this->preturi = new float[f.nrMedicamente];
		for (int i = 0; i < f.nrMedicamente; i++) {
			this->preturi[i] = f.preturi[i];
		}
	}

	~Farmacie() {
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}
	}

	void setAdresa(string adresa) {
		this->adresa = adresa;
	}

	string getAdresa() {
		return this->adresa;
	}

	int getNrMedicamente() {
		return this->nrMedicamente;
	}

	int getCodUnic() const {
		return this->codUnic;
	}

	Farmacie operator=(const Farmacie& farma) {
		if (&farma != this) {
			this->adresa = farma.adresa;
			this->nrMedicamente = farma.nrMedicamente;
			if (this->preturi != nullptr) {
				delete[] preturi;
			}
			this->preturi = new float[this->nrMedicamente];
			for (int i = 0; i < this->nrMedicamente; i++) {
				this->preturi[i] = farma.preturi[i];
			}
		}

		return *this;
	}

	friend ostream& operator<<(ostream& oStream, const Farmacie& f);
	friend istream& operator>>(istream& in, Farmacie& f);

	int getNrMedicamenteIeftine(float valoare) {
		int counter = 0;

		for (int i = 0; i < this->nrMedicamente; i++) {
			if (this->preturi[i] < valoare) {
				counter++;
			}
		}

		return counter;
	}

	bool operator>(const Farmacie& f) {
		return this->nrMedicamente > f.nrMedicamente;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrMedicamente) {
			return this->preturi[index];
		}
		else {
			throw "Index out of bounds";
		}
	}


};

int Farmacie::contorCID = 0;

ostream& operator<<(ostream& oStream, const Farmacie& f) {
	oStream << "Cod Unic: " << f.codUnic << "; "
		<< "Adresa: " << f.adresa << "; "
		<< "Nr. Medicamente: " << f.nrMedicamente << "; ";
		if (f.nrMedicamente > 0) {
			oStream << "Preturi medicamente: ";
			for (int i = 0; i < f.nrMedicamente; i++) {
				oStream << f.preturi[i];
				if (i < f.nrMedicamente - 1) {
					oStream << ", ";
				}
			}
			oStream << ".";
		}
	oStream << endl;
	return oStream;

};

istream& operator>>(istream& in, Farmacie& f) {
	cout << "Adresa: ";
	in >> f.adresa;
	cout << "Nr Medicamente: ";
	in >> f.nrMedicamente;
	if (f.preturi != NULL) {
		delete[] f.preturi;
	}
	if (f.nrMedicamente > 0) {
		f.preturi = new float[f.nrMedicamente];
		for (int i = 0; i < f.nrMedicamente; i++) {
			cout << "Pretul " << i+1 << ": ";
			in >> f.preturi[i];
		}
	}
	else {
		f.preturi = NULL;
	}
	
	return in;
}


int main(){
	Farmacie farmacie;
	cout << farmacie;

	float preturi[] = {3.55, 2.00, 1.00, 6.99};
	Farmacie farmacie2("Bucuresti", 4, preturi);
	cout << farmacie2;
	
	cout << farmacie.getAdresa() << endl;
	farmacie.setAdresa("Braila");
	cout << farmacie;
	cout << farmacie2.getNrMedicamenteIeftine(5) << endl;

	cout << endl;

	if (farmacie > farmacie2) {
		cout << "Are mai multe medicamente farm 1" << endl;
	}
	else {
		cout << "Are un numar egal sau mai mic de medicamente farm 1 fata de farm 2" << endl;
	}

	cout << endl;

	cin >> farmacie;
	cout << farmacie;
}


