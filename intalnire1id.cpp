#include <iostream>
#include <cstring>

using namespace std;

class Robot {
public:
	string nume;
	int versiuneSoft;
	float memorie;
	bool esteBiped;
	char* culoare;

	//destructor
	~Robot() {    
		if (this->culoare != NULL) {
			delete[]this->culoare;
		}
	}

	Robot() {
		this->nume = "Tesla";
		this->memorie = 78.9;
		this->versiuneSoft = 2;
		this->esteBiped = true;
		//robot1.culoare = (char*)malloc(strlen("Alb")+1);
		this->culoare = new char[strlen("Alb") + 1];
		strcpy(this->culoare, "Alb");
	}

	Robot(string nume) {
		this->nume = nume;
		this->memorie = 78.9;
		this->versiuneSoft = 2;
		this->esteBiped = true;
		//robot1.culoare = (char*)malloc(strlen("Alb")+1);
		this->culoare = new char[strlen("Alb") + 1];
		strcpy(this->culoare, "Alb");
	}

	Robot(int versiuneSoft) {
		this->nume = "Tesla";
		this->memorie = 78.9;
		this->versiuneSoft = versiuneSoft;
		this->esteBiped = true;
		//robot1.culoare = (char*)malloc(strlen("Alb")+1);
		this->culoare = new char[strlen("Alb") + 1];
		strcpy(this->culoare, "Alb");
	}

	Robot(string nume, int versiuneSoft, float memorie, bool esteBiped,const char* culoare) {
		this->nume = nume;
		this->memorie = memorie;
		this->versiuneSoft = versiuneSoft;
		this->esteBiped = esteBiped;
		//robot1.culoare = (char*)malloc(strlen("Alb")+1);
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);

	}

	void afisare() {
		cout << "Nume:" << this->nume << endl; // -> este echivalent cu deferentiere plus accesare
		cout << "Soft:" << this->versiuneSoft << endl; 
		cout << "Memorie: " << this->memorie << endl; 
		cout << "Culoare: " << this->culoare << endl; 
		cout << "Este biped: " << (this->esteBiped? "DA":"NU") << endl;
	}
};

void main(){
	Robot robot1;
	robot1.afisare();

	Robot robot2("Marcel");
	robot2.afisare();

	Robot robot3(10);
	robot3.afisare();

	Robot robot4("Gigel", 200, 56.7, 0, "Rosu");
	robot4.afisare();

	Robot* pointer;
	pointer = new Robot("Cornel");
	delete pointer;
}