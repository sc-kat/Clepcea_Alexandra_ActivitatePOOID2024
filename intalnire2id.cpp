#include <iostream>
#include <string>
using namespace std;

// github.com/gabivas
// gabriel.vasilescu@csie.ase.ro

class Masina
{

    // struct vs class: structurile sunt entitati cu zona publica
    // incapsulare: setarea atributelor in zona private pentru a fi accesate prin getteri si setteri

private:
    const int id;
    static int nrMasini;
    string marca;
    int nrComponente;
    float *preturi; // float* defineste un vector dinamic

    // transmiterea parametrilor prin valoare, prin referinta sau prin pointer

public:
    Masina() : id(++nrMasini)
    {

        //"this" este pointer la obiectul curent (??? de verif diferenta intre clasa si obiect ???)
        this->marca = "Necunoscuta";
        this->nrComponente = 0;
        this->preturi = nullptr;
    }

    Masina(string marca, int nrComponente, float *preturi) : id(++nrMasini)
    {
        this->marca = marca;
        this->nrComponente = nrComponente;
        // shallow copy
        // this->preturi = preturi

        // deep-copy
        this->preturi = new float[nrComponente];
        for (int i = 0; i < nrComponente; i++)
        {
            this->preturi[i] = preturi[i];
        }

        delete[] preturi; // why delete preturi? de ce nu this.preturi, what is this sorcery?//
    }

    int getNrComponente()
    {
        return this->nrComponente;
    }

    void setNrComponente(int nrComponente)
    {
        if (nrComponente > 0)
        {
            this->nrComponente = nrComponente;
        }
    }

    float *getPreturi()
    {
        // return this->preturi; ---- ASA NU! trebuie facut deep copy, asta e shallow copy

        float *vectorPreturi = new float[this->nrComponente];
        for (int i = 0; i < this->nrComponente; i++)
        {
            vectorPreturi[i] = this->preturi[i];
        }
        return vectorPreturi;
    }

    void setPreturi(float *noulVectorPreturi, int nouaDimensiune)
    {
        setNrComponente(nouaDimensiune);
        if (this->preturi != nullptr)
        {
            delete[] this->preturi;
        }
        this->preturi = new float[nouaDimensiune];
        for (int i = 0; i < nouaDimensiune; i++)
        {
            this->preturi[i] = noulVectorPreturi[i];
        }
        delete[] noulVectorPreturi;
    }

    ~Masina()
    {
        if (this->preturi != nullptr)
            delete[] this->preturi;
    }

    void afiseazaMasina()
    {

        cout << this->id << ". Masina cu marca " << this->marca;
        if (this->nrComponente > 0)
        {
            cout << " are " << this->nrComponente << " componente cu urmatoarele preturi: ";
            if (this->preturi != nullptr)
            {
                for (int i = 0; i < this->nrComponente; i++)
                {
                    cout << " " << this->preturi[i];
                }
            }
            cout << endl;
        }
    }
};

int Masina::nrMasini = 0;

int main()
{
    Masina masina1;
    Masina masina2("Renault", 4, new float[4]{23.5, 50.0, 60.7, 3.5});
    masina1.afiseazaMasina();
    masina1.setNrComponente(1);

    cout << endl
         << "Noua valoare este: " << masina1.getNrComponente() << endl;

    masina2.afiseazaMasina();
    masina2.setPreturi(new float[2]{10.5, 14.7}, 2);

    float *vectorPreturi = masina2.getPreturi();
    for (int i = 0; i < masina2.getNrComponente(); i++)
    {
        cout << " " << vectorPreturi[i];
    }
}
