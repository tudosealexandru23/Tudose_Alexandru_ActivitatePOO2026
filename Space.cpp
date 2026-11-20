#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MisiuneSpatiala
{
private:
	static int agentieSpatiala;
	int codMisiune;
	char* numeNava;
	int durataZile;
	double* distanteOrbitale;
	int numarEtape;

public:
	MisiuneSpatiala(const char* numeNava, int durataZile)
	{
		this->codMisiune = 0;
		this->distanteOrbitale = nullptr;
		this->numarEtape = 0;
		if (numeNava != nullptr)
		{
			this->numeNava = new char[strlen(numeNava) + 1];
			strcpy(this->numeNava, numeNava);
		}
		else
		{
			this->numeNava = nullptr;
		}

		if (durataZile > 0)
		{
			this->durataZile = durataZile;
		}
		else
		{
			this->durataZile = 0;
		}
	}

	~MisiuneSpatiala()
	{
		delete[] this->numeNava;
		delete[] this->distanteOrbitale;
	}

	MisiuneSpatiala(const MisiuneSpatiala& m)
	{
		this->codMisiune = m.codMisiune;
		this->durataZile = m.durataZile;
		this->numarEtape = m.numarEtape;

		if (m.distanteOrbitale != nullptr)
		{
			this->distanteOrbitale = new double[m.numarEtape];
			for (int i = 0; i < m.numarEtape; i++)
			{
				this->distanteOrbitale[i] = m.distanteOrbitale[i];
			}
		}
		else
		{
			this->distanteOrbitale = nullptr;
		}

		if (m.numeNava != nullptr)
		{
			this->numeNava = new char[strlen(m.numeNava) + 1];
			strcpy(this->numeNava, m.numeNava);
		}
		else
		{
			this->numeNava = nullptr;
		}
	}

	MisiuneSpatiala& operator=(const MisiuneSpatiala& m)
	{
		if (this != &m)
		{
			delete[] this->numeNava;
			delete[] this->distanteOrbitale;

			this->codMisiune = m.codMisiune;
			this->durataZile = m.durataZile;
			this->numarEtape = m.numarEtape;

			if (m.distanteOrbitale != nullptr)
			{
				this->distanteOrbitale = new double[m.numarEtape];
				for (int i = 0; i < m.numarEtape; i++)
				{
					this->distanteOrbitale[i] = m.distanteOrbitale[i];
				}
			}
			else
			{
				this->distanteOrbitale = nullptr;
			}

			if (m.numeNava != nullptr)
			{
				this->numeNava = new char[strlen(m.numeNava) + 1];
				strcpy(this->numeNava, m.numeNava);
			}
			else
			{
				this->numeNava = nullptr;
			}
		}
		return *this;
	}

	MisiuneSpatiala& operator+=(double distanta)
	{
		if (distanta > 0)
		{
			double* temp = new double[this->numarEtape + 1];
			for (int i = 0; i < this->numarEtape; i++)
			{
				temp[i] = this->distanteOrbitale[i];
			}
			temp[this->numarEtape] = distanta;
			delete[] this->distanteOrbitale;
			this->distanteOrbitale = temp;
			this->numarEtape++;
		}
		return *this;
	}

	void setDistanteOrbitale(double* distanteOrbitale, int numarEtape)
	{
		if (distanteOrbitale != nullptr && numarEtape > 0)
		{
			delete[] this->distanteOrbitale;
			this->numarEtape = numarEtape;
			this->distanteOrbitale = new double[numarEtape];
			for (int i = 0; i < numarEtape; i++)
			{
				this->distanteOrbitale[i] = distanteOrbitale[i];
			}
		}
	}

	void setDurataZile(int durataZile)
	{
		if (durataZile > 0)
		{
			this->durataZile = durataZile;
		}
	}

	friend ostream& operator<<(ostream& out, const MisiuneSpatiala& m)
	{
		out << "Nava: " << (m.numeNava ? m.numeNava : "necunoscuta") << endl;
		out << "Durata: " << m.durataZile << " zile" << endl;
		out << "Etape: " << m.numarEtape << endl;
		for (int i = 0; i < m.numarEtape; i++)
		{
			out << "  Distanta " << i + 1 << ": " << m.distanteOrbitale[i] << " km" << endl;
		}
		return out;
	}
};

int MisiuneSpatiala::agentieSpatiala = 0;

int main()
{
	MisiuneSpatiala a("Ares-Marte", 210);

	MisiuneSpatiala b(a);

	MisiuneSpatiala c("Europa-Jupiter", 540);

	b = c;

	double traiectorie[] = { 384400, 54600000, 225000000 };

	a.setDurataZile(230);
	b.setDistanteOrbitale(traiectorie, 3);

	a += 1500000;
	a += 78000000;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	cin.get();
	return 0;
}