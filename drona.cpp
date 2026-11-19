#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Drona {
private:
    char* model;
    int autonomie;
    float pret;

public:
    Drona() {
        model = new char[strlen("Model necunoscut") + 1];
        strcpy(model, "Model necunoscut");
        autonomie = 0;
        pret = 0;
    }

    Drona(const char* model, int autonomie, float pret) {
        if (model != nullptr && strlen(model) > 0) {
            this->model = new char[strlen(model) + 1];
            strcpy(this->model, model);
        }
        else {
            this->model = nullptr;
        }

        this->autonomie = autonomie >= 0 ? autonomie : 0;
        this->pret = pret >= 0 ? pret : 0;
    }

    Drona(const Drona& alta) {
        if (alta.model != nullptr) {
            model = new char[strlen(alta.model) + 1];
            strcpy(model, alta.model);
        }
        else {
            model = nullptr;
        }

        autonomie = alta.autonomie;
        pret = alta.pret;
    }

    ~Drona() {
        delete[] model;
    }

    const char* getModel() const {
        return model;
    }

    void setModel(const char* model) {
        char* copie = nullptr;

        if (model != nullptr && strlen(model) > 0) {
            copie = new char[strlen(model) + 1];
            strcpy(copie, model);
        }

        delete[] this->model;
        this->model = copie;
    }

    int getAutonomie() const {
        return autonomie;
    }

    void setAutonomie(int autonomie) {
        this->autonomie = autonomie >= 0 ? autonomie : 0;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float pret) {
        this->pret = pret >= 0 ? pret : 0;
    }

    Drona& operator=(const Drona& alta) {
        if (this != &alta) {
            char* copie = nullptr;

            if (alta.model != nullptr) {
                copie = new char[strlen(alta.model) + 1];
                strcpy(copie, alta.model);
            }

            delete[] model;
            model = copie;
            autonomie = alta.autonomie;
            pret = alta.pret;
        }

        return *this;
    }

    void afisare() const {
        cout << "Model: " << (model != nullptr ? model : "Necunoscut")
             << ", Autonomie: " << autonomie << " minute"
             << ", Pret: " << pret << " lei" << endl;
    }
};

int main() {
    Drona drona1("DJI Mini 4 Pro", 34, 4200);
    drona1.afisare();

    Drona drona2 = drona1;
    drona2.afisare();

    Drona drona3;
    drona3 = drona1;
    drona3.afisare();

    drona3.setModel("DJI Air 3");
    drona3.setAutonomie(46);
    drona3.setPret(6500);

    cout << "Dupa modificare:" << endl;
    drona3.afisare();

    return 0;
}
