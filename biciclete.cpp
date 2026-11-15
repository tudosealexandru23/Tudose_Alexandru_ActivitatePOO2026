#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Bicicleta {
private:
    char* marca;
    int viteze;
    float pret;

public:
    Bicicleta() : marca(nullptr), viteze(0), pret(0.0f) {
        marca = new char[12];
        strcpy(marca, "NECUNOSCUTA");
    }

    Bicicleta(const char* marca, int viteze, float pret) : viteze(viteze), pret(pret) {
        if (marca != nullptr && strlen(marca) > 0 && strlen(marca) < 20) {
            this->marca = new char[strlen(marca) + 1];
            strcpy(this->marca, marca);
        }
        else {
            this->marca = nullptr;
        }

        if (this->viteze < 0) {
            this->viteze = 0;
        }

        if (this->pret < 0.0f) {
            this->pret = 0.0f;
        }

        cout << "Constructor cu parametri apelat\n";
    }

    Bicicleta(const Bicicleta& other) {
        if (other.marca != nullptr) {
            marca = new char[strlen(other.marca) + 1];
            strcpy(marca, other.marca);
        }
        else {
            marca = nullptr;
        }

        viteze = other.viteze;
        pret = other.pret;
        cout << "Constructor de copiere apelat\n";
    }

    ~Bicicleta() {
        cout << "Destructor apelat pentru bicicleta "
             << (marca ? marca : "Necunoscuta") << "\n";
        delete[] marca;
        marca = nullptr;
    }

    const char* getMarca() const {
        return marca;
    }

    void setMarca(const char* marca) {
        if (marca != nullptr && strlen(marca) > 0 && strlen(marca) < 20) {
            char* copie = new char[strlen(marca) + 1];
            strcpy(copie, marca);
            delete[] this->marca;
            this->marca = copie;
        }
        else {
            delete[] this->marca;
            this->marca = nullptr;
        }
    }

    int getViteze() const {
        return viteze;
    }

    void setViteze(int viteze) {
        this->viteze = viteze >= 0 ? viteze : 0;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float pret) {
        this->pret = pret >= 0 ? pret : 0.0f;
    }

    Bicicleta& operator=(const Bicicleta& other) {
        if (this != &other) {
            char* copie = nullptr;

            if (other.marca != nullptr) {
                copie = new char[strlen(other.marca) + 1];
                strcpy(copie, other.marca);
            }

            delete[] marca;
            marca = copie;
            viteze = other.viteze;
            pret = other.pret;
        }

        cout << "Operator de atribuire apelat\n";
        return *this;
    }

    void afisare() const {
        cout << "Marca: " << (marca ? marca : "Necunoscuta")
             << ", Numar viteze: " << viteze
             << ", Pret: " << pret << " lei" << endl;
    }
};

int main() {
    Bicicleta bicicleta1("MountainBike", 21, 1850.50f);
    bicicleta1.afisare();

    Bicicleta bicicleta2 = bicicleta1;
    bicicleta2.afisare();

    Bicicleta bicicleta3;
    bicicleta3 = bicicleta1;
    bicicleta3.afisare();

    bicicleta3.setMarca("CityBike");
    bicicleta3.setViteze(7);
    bicicleta3.setPret(1200.99f);

    cout << "Detalii dupa modificare:\n";
    bicicleta3.afisare();

    return 0;
}
