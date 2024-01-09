#include<iostream>
#include<fstream>
using namespace std;
//domeniul ales este MeDicina
class Cladire {
private:
	string numeStradaCladire;
	int suprafata;
public:
	virtual int nrPacientiSiDoctori() = 0;
	Cladire() {
		numeStradaCladire = "Stejarului";
		suprafata = 500;
	}
	virtual ~Cladire() {

	}

};
class Spital: public Cladire {
private:
	string nume;
	const int anInfiintare;
	int nrPaturi;
protected:
	int nrPacienti;
private:
	static int nrSectiiATI;
	char* localitate;
public:
	//presupunem ca la fiecare 5 pacienti exista un doctor
	virtual int nrPacientiSiDoctori() {
		return nrPacienti + int(nrPacienti/5);
	}
	//getteri:
	string getNume() {
		return this->nume;
	}
	const int getAnInfiintare() {
		return this->anInfiintare;
	}
	int getNrPaturi() {
		return this->nrPaturi;
	}
	int getNrPacienti() {
		return this->nrPacienti;
	}
	char* getLocalitate() {
		return this->localitate;
	}
	//setteri
	void setNume(string nume) {
		if (nume.length() > 3) {             //validam input-ul
			this->nume = nume;
		}
	}
	void setNrPaturi(int nrPaturi) {
		if (nrPaturi > 0) {
			this->nrPaturi = nrPaturi;
		}
	}
	void setNrPacienti(int nrPacienti) {
		if (nrPacienti > 0) {
			this->nrPacienti = nrPacienti;
		}
	}
	void setLocalitate(const char* localitate) {
		if (this->localitate != NULL)
		{
			delete[]this->localitate;
		}
		this->localitate = new char[strlen(localitate) + 1];
		strcpy_s(this->localitate, strlen(localitate) + 1, localitate);
	}
	Spital() :anInfiintare(1988) {                  //Lista de initializare
		this->nume = "Elias";
		this->nrPaturi = 15;
		this->nrPacienti = 8;
		this->localitate = new char[strlen("Bucuresti") + 1];
		strcpy_s(this->localitate, strlen("Bucuresti") + 1, "Bucuresti");
	}
	void afisare() {
		cout << "nume:" << this->nume;
		cout << "\nan infiintare:" << this->anInfiintare;
		cout << "\nnrPacieti:" << this->nrPacienti;
		cout << "\nnrPaturi:" << this->nrPaturi;
		cout << "\nnr sectii ATI:" << this->nrSectiiATI;
		cout << "\nlocalitate:" << this->localitate;
		cout << endl;
	}
	Spital(string nume, const int an, int nrPaturi, int nrPacienti, const char* localitate) : anInfiintare(an) {
		this->nume = nume;
		this->nrPaturi = nrPaturi;
		this->nrPacienti = nrPacienti;
		this->localitate = new char[strlen(localitate) + 1];
		strcpy_s(this->localitate, strlen(localitate) + 1, localitate);
	}
	Spital(const int an, int nrPaturi, int nrPacienti) :anInfiintare(an) {
		this->nume = "Regina Maria";
		this->nrPaturi = nrPaturi;
		this->nrPacienti = nrPacienti;
		this->localitate = new char[strlen("Bucuresti") + 1];
		strcpy_s(this->localitate, strlen("Bucuresti") + 1, "Bucuresti");

	}
	//constructor de copiere
	Spital(const Spital& spital) : anInfiintare(spital.anInfiintare) {
		this->nume = spital.nume;
		this->nrPaturi = spital.nrPaturi;
		this->nrPacienti = spital.nrPacienti;

		this->localitate = new char[strlen(spital.localitate) + 1];
		strcpy_s(this->localitate, strlen(spital.localitate) + 1, spital.localitate);

	}
	//operatori
	Spital& operator=(const Spital& spital) {      //1.1
		if (this != &spital) {
			this->nume = spital.nume;
			this->nrPaturi = spital.nrPaturi;
			this->nrPacienti = spital.nrPacienti;

			if (this->localitate != NULL) {
				delete[]this->localitate;
			}

			this->localitate = new char[strlen(spital.localitate) + 1];
			strcpy_s(this->localitate, strlen(spital.localitate) + 1, spital.localitate);

			return *this;
		}
	}
	friend ostream& operator<<(ostream& scrie, const Spital& s) {  //1.2
		scrie << "Nume:" << s.nume << endl;
		scrie << "An infiintare:" << s.anInfiintare << endl;
		scrie << "Numar paturi:" << s.nrPaturi << endl;
		scrie << "Numar pacienti:" << s.nrPacienti << endl;
		scrie << "Numar sectii ATI:" << s.nrSectiiATI << endl;
		cout << "Localitate: " << s.localitate << endl;
		cout << endl;
		return scrie;
	}
	Spital operator++() {    //preincrementare   //1.3
		this->nrPaturi += 7;
		return *this;
	}
	Spital operator--() {      //1.4    
		this->nrPacienti -= 5;
		return *this;
	}
	friend istream& operator>>(istream& citeste, Spital& s) {
		cout << "Nume:"; citeste >> s.nume;
		cout << "Numar paturi:"; citeste >> s.nrPaturi;
		cout << "Numar pacienti:"; citeste >> s.nrPacienti;
		cout << "Localitate:";
		if (s.localitate != NULL) {
			delete[]s.localitate;
		}
		s.localitate = new char[strlen(s.localitate) + 1];
		citeste >> s.localitate;
		return citeste;
	}
	//destructor
	~Spital() {
		if (this->localitate != NULL)
		{
			delete[]this->localitate;
			this->localitate = NULL;
		}
	}
	//scriere in fisier
	friend ofstream& operator<<(ofstream& scrie, const Spital& s) {
		scrie << s.nume << endl;
		scrie << s.anInfiintare << endl;
		scrie << s.nrPaturi << endl;
		scrie << s.nrPacienti << endl;
		scrie << s.nrSectiiATI << endl;
		scrie << s.localitate << endl;
		scrie << endl;
		return scrie;

	}
	friend ifstream& operator>>(ifstream& citeste, Spital& s) {
		citeste >> s.nume;
		float val = 0;
		citeste >> val; //pt an infiintare care e tip de const int
		citeste >> s.nrPaturi;
		citeste >> s.nrPacienti;
		citeste >> val; //pt nrSectiiATI care e de tip static
		citeste >> s.localitate;
		return citeste;


	}
	static int getSectiiATI() {
		return nrSectiiATI;
	}
	//functie friend
	friend void paturiNecesare(Spital y);

};
void paturiNecesare(Spital y) {
	if (y.nrPacienti > y.nrPaturi)
		cout << "este necesara suplimentarea cu " << y.nrPacienti - y.nrPaturi << " paturi\n";
	else {
		cout << "sunt suficiente paturi pentru toti pacientii\n";
	}
}
int Spital::nrSectiiATI = 1;
class SpitalPsihiatrie : public Spital {
private:
	char* numeDirector;
	int nrPsihiatrii;
	int nrTerapii;
public:
	int nrPacientiSiDoctori() {
		return this->nrPacienti + nrPsihiatrii;
	}
	char* getNumeDirector() {
		return this->numeDirector;
	}
	int getNrPsihiatrii() {
		return this->nrPsihiatrii;
	}
	int getNrTerapii() {
		return this->nrTerapii;
	}
	void setNumeDirector(const char* numeDirector) {
		if (this->numeDirector != NULL)
		{
			delete[]this->numeDirector;
		}
		this->numeDirector = new char[strlen(numeDirector) + 1];
		strcpy_s(this->numeDirector, strlen(numeDirector) + 1, numeDirector);
	}
	void setNrPsihiatrii(int nrPsihiatrii) {
		if (nrPsihiatrii > 0)
			this->nrPsihiatrii = nrPsihiatrii;
	}
	void setNrTerapii(int nrTerapii) {
		if (nrTerapii > 0)
			this->nrTerapii = nrTerapii;
	}

	SpitalPsihiatrie() :Spital("Obregia", 1960, 60, 34, "Bucuresti") {
		this->numeDirector = new char[strlen("Popescu") + 1];
		strcpy_s(this->numeDirector, strlen("Popescu") + 1, "Popescu");
		this->nrPsihiatrii = 12;
		this->nrTerapii = 3;
	}
	SpitalPsihiatrie(int nrPsihiatrii, int nrTerapii, const char* numeDirector) :Spital() {
		this->numeDirector = new char[strlen(numeDirector) + 1];
		strcpy_s(this->numeDirector, strlen(numeDirector) + 1, numeDirector);
		this->nrPsihiatrii = nrPsihiatrii;
		this->nrTerapii = nrTerapii;
	}
	SpitalPsihiatrie(string nume, const int an, int nrPaturi, int nrPacienti, const char* localitate, const char* numeDirector,
		int nrPsihiatrii, int nrTerapii) :Spital(nume, an, nrPaturi, nrPacienti, localitate) {
		this->numeDirector = new char[strlen(numeDirector) + 1];
		strcpy_s(this->numeDirector, strlen(numeDirector) + 1, numeDirector);
		this->nrPsihiatrii = nrPsihiatrii;
		this->nrTerapii = nrTerapii;
	}
	SpitalPsihiatrie(const SpitalPsihiatrie& sp) :Spital(sp) {
		this->numeDirector = new char[strlen(sp.numeDirector) + 1];
		strcpy_s(this->numeDirector, strlen(sp.numeDirector) + 1, sp.numeDirector);
		this->nrPsihiatrii = sp.nrPsihiatrii;
		this->nrTerapii = sp.nrTerapii;
	}
	SpitalPsihiatrie& operator=(const SpitalPsihiatrie& sp) {

		if (this != &sp) {
			Spital::operator=(sp);
			if (this->numeDirector != NULL) {
				delete[]this->numeDirector;
			}
			this->numeDirector = new char[strlen(sp.numeDirector) + 1];
			strcpy_s(this->numeDirector, strlen(sp.numeDirector) + 1, sp.numeDirector);
			this->nrPsihiatrii = sp.nrPsihiatrii;
			this->nrTerapii = sp.nrTerapii;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& scrie, const SpitalPsihiatrie& sp) {
		scrie << (Spital)sp;
		scrie << "Nume director spital: " << sp.numeDirector << endl;
		scrie << "Numar psihiatrii: " << sp.nrPsihiatrii << endl;
		scrie << "Numar terapii utilizate:" << sp.nrTerapii << endl;
		scrie << endl;

		return scrie;
	}
	~SpitalPsihiatrie() {
		if (numeDirector != NULL) {
			delete[]this->numeDirector;
		}

	}



};
class echipamentMedical {
private:
	string nume;
	char* specializare;
	float pret;
	int aniUtilizare;
	static int perioadaGarantie;
	const int nrOperatori; //necesar de personal pentru ca aparatul sa fie pus in functiune
	bool estePornit;
	int nrDefectiuni;

public:
	//getteri:
	string getNume() {
		return this->nume;
	}
	char* getSpecializare() {
		return this->specializare;
	}
	float getPret() {
		return this->pret;
	}
	int getAniUtilizare() {
		return this->aniUtilizare;
	}
	const int getNrOperatori() {
		return this->nrOperatori;
	}
	bool getEstePornit() {
		return this->estePornit;
	}
	int getNrDefectiuni() {
		return this->nrDefectiuni;
	}
	//setteri
	void setNume(string nume) {
		if (nume.length() > 3) {
			this->nume = nume;
		}
	}
	void setSpecializare(const char* specializare) {
		if (this->specializare != NULL) {
			delete[]this->specializare;

		}
		this->specializare = new char[strlen(specializare) + 1];
		strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	void setAniUtilizare(int aniUtilizare)
	{
		if (aniUtilizare > -1) {
			this->aniUtilizare = aniUtilizare;
		}
	}
	void setEstePornit(bool estePornit) {
		if ((estePornit == 1) || (estePornit == 0))
			this->estePornit = estePornit;
	}
	void setNrDefectiuni(int nrDefectiuni) {
		if (nrDefectiuni > -1) {
			this->nrDefectiuni = nrDefectiuni;
		}
	}
	void afisare() {
		cout << "\nNume echipament:" << this->nume;
		cout << "\nSpecializare:" << this->specializare;
		cout << "\nPret:" << this->pret;
		cout << "\nAni utilizare:" << this->aniUtilizare;
		cout << "\nPerioada garantie:" << this->perioadaGarantie;
		cout << "\nNumar operatori:" << this->nrOperatori;
		cout << "\nEste pornit:" << this->estePornit;
		cout << "\nNumar defectiuni:" << this->nrDefectiuni;
		cout << endl;
		cout << endl;
	}
	echipamentMedical() :nrOperatori(2) {
		this->nume = "Aparat de ventilatie";
		this->specializare = new char[strlen("Urgente") + 1];
		strcpy_s(this->specializare, strlen("Urgente") + 1, "Urgente");
		this->pret = 30000;
		this->aniUtilizare = 2;
		this->estePornit = 0;
		this->nrDefectiuni = 0;

	}
	echipamentMedical(string nume, const char* specializare, int aniUtilizare, const int nrOp) :nrOperatori(nrOp) {
		this->nume = nume;
		this->specializare = new char[strlen(specializare) + 1];
		strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
		this->pret = 7000;
		this->aniUtilizare = aniUtilizare;
		this->estePornit = 0;
		if (this->aniUtilizare <= 2)
			this->nrDefectiuni = 0;
		else
		{
			this->nrDefectiuni = this->aniUtilizare - 1;
		}

	}
	echipamentMedical(bool estePornit) :nrOperatori(2) {
		this->nume = "Aparat resuscitere";
		this->specializare = new char[strlen("Reanimare") + 1];
		strcpy_s(this->specializare, strlen("Reanimare") + 1, "Reanimare");
		this->pret = 4000;
		this->aniUtilizare = 4;
		this->estePornit = estePornit;
		if (this->aniUtilizare <= 3)
			this->nrDefectiuni = 0;
		else
		{
			this->nrDefectiuni = this->aniUtilizare - 1;
		}

	}
	echipamentMedical(const char* nume, float pret) :nrOperatori(1) {
		float x;
		this->nume = nume;
		this->pret = pret;
		x = this->pret;
		if (x < 2000) {
			this->specializare = new char[strlen("Pneumologie") + 1];
			strcpy_s(this->specializare, strlen("Pneumologie") + 1, "Pneumologie");

		}
		else
		{
			this->specializare = new char[strlen("Chirurgie") + 1];
			strcpy_s(this->specializare, strlen("Chirurgie") + 1, "Chirurgie");
		}
		this->aniUtilizare = 8;
		this->estePornit = 0;
		this->nrDefectiuni = 2;


	}
	//constructor de copiere
	echipamentMedical(const echipamentMedical& EchipamentMedical) : nrOperatori(EchipamentMedical.nrOperatori) {
		this->nume = EchipamentMedical.nume;
		this->specializare = new char[strlen(EchipamentMedical.specializare) + 1];
		strcpy_s(this->specializare, strlen(EchipamentMedical.specializare) + 1, EchipamentMedical.specializare);
		this->pret = EchipamentMedical.pret;
		this->aniUtilizare = EchipamentMedical.aniUtilizare;
		this->estePornit = EchipamentMedical.estePornit;
		this->nrDefectiuni = EchipamentMedical.nrDefectiuni;
	}
	//operatori
	echipamentMedical& operator=(const echipamentMedical& EchipamentMedical) {  //2.1
		if (this != &EchipamentMedical) {
			this->nume = EchipamentMedical.nume;
			this->specializare = new char[strlen(EchipamentMedical.specializare) + 1];
			strcpy_s(this->specializare, strlen(EchipamentMedical.specializare) + 1, EchipamentMedical.specializare);
			this->pret = EchipamentMedical.pret;
			this->aniUtilizare = EchipamentMedical.aniUtilizare;
			this->estePornit = EchipamentMedical.estePornit;
			this->nrDefectiuni = EchipamentMedical.nrDefectiuni;
			return *this;
		}
	}
	friend istream& operator>>(istream& citeste, echipamentMedical& e) {   //2.2
		cout << "Nume:"; citeste >> e.nume;
		cout << "Specializare:";
		if (e.specializare != NULL) {
			delete[]e.specializare;
		}
		e.specializare = new char[strlen(e.specializare) + 1];
		citeste >> e.specializare;
		cout << "Pret:"; citeste >> e.pret;
		cout << "Ani de utilizare:"; citeste >> e.aniUtilizare;
		cout << "Este pornit:"; citeste >> e.estePornit;
		cout << "Numar defectiuni:"; citeste >> e.nrDefectiuni;
		return citeste;
	}
	friend ostream& operator<<(ostream& scrie, echipamentMedical& e) {
		scrie << "Nume:" << e.nume << endl;
		scrie << "Specializare:" << e.specializare << endl;
		scrie << "Pret:" << e.pret << endl;
		scrie << "Ani de utilizare:" << e.aniUtilizare << endl;
		scrie << "Perioada de garantie:" << e.perioadaGarantie << " ani" << endl;
		scrie << "Numar operatori:" << e.nrOperatori << endl;
		scrie << "Este pornit:" << e.estePornit << endl;
		scrie << "Numar defectiuni:" << e.nrDefectiuni << endl;
		return scrie;
	}
	echipamentMedical operator++(int) {  //2.3
		echipamentMedical temporar = *this;
		this->aniUtilizare += 3;
		return temporar;
	}
	bool operator>(echipamentMedical e) {  //2.4
		return this->pret > e.pret;
	}
	//metoda pentru a citi intr un fisier binar
	void citesteInFisBinar(fstream& f) {
		int sizeOfNume = this->nume.length();
		f.write((char*)&sizeOfNume, sizeof(int));
		for (int i = 0; i < sizeOfNume; i++) {
			f.write((char*)&this->nume[i], sizeof(char));
		}
		int sizeOfSpecializare = strlen(this->specializare);
		f.write((char*)&sizeOfSpecializare, sizeof(int));
		for (int i = 0; i < sizeOfSpecializare; i++) {
			f.write((char*)&this->specializare[i], sizeof(char));
		}
		f.write((char*)&pret, sizeof(float));
		f.write((char*)&aniUtilizare, sizeof(int));
		f.write((char*)&perioadaGarantie, sizeof(int));
		f.write((char*)&nrOperatori, sizeof(int));
		f.write((char*)&estePornit, sizeof(bool));
		f.write((char*)&nrDefectiuni, sizeof(int));

	}
	//metoda pentru a citi dintr un fisier binar
	void citesteDinFisBinar(fstream& f) {
		int sizeOfNume;
		f.read((char*)&sizeOfNume, sizeof(int));
		for (int i = 0; i < sizeOfNume; i++) {
			f.read((char*)&this->nume[i], sizeof(char));
		}
		this->nume[sizeOfNume] = '\0';
		int sizeOfSpecializare;
		f.read((char*)&sizeOfSpecializare, sizeof(int));
		for (int i = 0; i < sizeOfSpecializare; i++) {
			f.read((char*)&this->specializare[i], sizeof(char));
		}
		this->specializare[sizeOfSpecializare] = '\0';
		int val = 0;
		f.read((char*)&pret, sizeof(float));
		f.read((char*)&aniUtilizare, sizeof(int));
		f.read((char*)&val, sizeof(int));
		f.read((char*)&val, sizeof(int));
		f.read((char*)&estePornit, sizeof(bool));
		f.read((char*)&nrDefectiuni, sizeof(int));

	}


	~echipamentMedical() {
		if (this->specializare != NULL)
		{
			delete[]this->specializare;
		}
	}

	//fct de return var statica
	static int getPerioadaGarantie() {
		return perioadaGarantie;
	}

};
int echipamentMedical::perioadaGarantie = 2;
class ProdusFarmaceutic {
private:
	string producator;
	int unitatiPerLot;
public:
	virtual float sumaIncasata() = 0;
	ProdusFarmaceutic() {
		producator = "SunWave Pharma";
		unitatiPerLot = 50;
	}
	~ProdusFarmaceutic() {
	};

};
class Medicament:public ProdusFarmaceutic {
private:
	char* denumire;
	string modDeAdministrare;
protected:
	float pretIntreg;
	float reducere; //medicamente compensate
	static float TVA;
private:
	bool prescriptieMedicala;
	int nrFarmaciiPartenere;
	const int termenValabilitate; //masurat in luni
public:
	virtual float sumaIncasata()  {
		return pretIntreg+pretIntreg*TVA-pretIntreg*reducere;
	}

	char* getDenumire() {
		return this->denumire;

	}
	string getModDeAdministrare() {
		return this->modDeAdministrare;
	}
	float getPretIntreg() {
		return this->pretIntreg;
	}
	float getReducere() {
		return this->reducere;
	}
	bool getPrescriptieMedicala() {
		return this->prescriptieMedicala;
	}
	int getNrFarmaciiPartenere() {
		return this->nrFarmaciiPartenere;
	}
	const int getTermenValabilitate() {
		return this->termenValabilitate;
	}
	//setteri
	void setDenumire(const char* denumire) {
		if (this->denumire != NULL)
		{
			delete[]this->denumire;
		}
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	void setModDeAdministrare(string modDeAdministrare) {
		if (modDeAdministrare.length() > 3)
			this->modDeAdministrare = modDeAdministrare;

	}
	void setPretIntreg(float pretIntreg) {
		if (pretIntreg > 0) {
			this->pretIntreg = pretIntreg;
		}
	}
	void setReducere(float reducere) {
		if (reducere >= 0 && reducere <=1) {
			this->reducere = reducere;
		}
	}
	void setPrescriptieMedicala(bool prescriptieMedicala) {
		if (prescriptieMedicala == 1 || prescriptieMedicala == 0)
			this->prescriptieMedicala = prescriptieMedicala;
	}
	void setNrFarmaciiPartenere(int nrFarmaciiPartenere) {
		if (nrFarmaciiPartenere > 0) {
			this->nrFarmaciiPartenere = nrFarmaciiPartenere;
		}
	}
	void afisare() {
		cout << "\nDenumire medicament:" << this->denumire;
		cout << "\nMod de Administrare:" << this->modDeAdministrare;
		cout << "\nPret intreg:" << this->pretIntreg;
		cout << "\nReducere:" << this->reducere;
		cout << "\nTVA:" << this->TVA;
		cout << "\nPrescriptie medicala:" << this->prescriptieMedicala;
		cout << "\nNumar farmacii partenere:" << this->nrFarmaciiPartenere;
		cout << "\nTermen de valabilitate:" << this->termenValabilitate << " " << "luni";
		cout << endl;
		cout << endl;
	}
	Medicament() :termenValabilitate(6) {
		this->denumire = new char[strlen("Aerius") + 1];
		strcpy_s(this->denumire, strlen("Aerius") + 1, "Aerius");
		this->modDeAdministrare = "oral";
		this->pretIntreg = 34;
		this->reducere = 0.3;
		this->prescriptieMedicala = 0;
		this->nrFarmaciiPartenere = 12;
	}
	Medicament(const char* denumire, float pretIntreg, bool prescriptieMedicala, int nrFarmaciiPartenere) :termenValabilitate(6) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->modDeAdministrare = "oral";
		this->pretIntreg = pretIntreg;
		this->reducere = 0.5;
		this->prescriptieMedicala = prescriptieMedicala;
		this->nrFarmaciiPartenere = nrFarmaciiPartenere;

	}
	Medicament(const char* denumire, string modDeAdministrare, float pretIntreg, float reducere, const int termenV) :termenValabilitate(termenV) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->modDeAdministrare = modDeAdministrare;
		this->pretIntreg = pretIntreg;
		this->reducere = reducere;
		this->prescriptieMedicala = 1;
		this->nrFarmaciiPartenere = 5;


	}
	Medicament(string modDeAdministrare, float pretIntreg, float reducere, bool prescriptieMedicala, int nrFarmaciiPartenere, const int termenV) :termenValabilitate(termenV) {
		this->denumire = new char[strlen("MollekinImuno") + 1];
		strcpy_s(this->denumire, strlen("MollekinImuno") + 1, "MollekinImuno");
		this->modDeAdministrare = modDeAdministrare;
		this->pretIntreg = pretIntreg;
		this->reducere = reducere;
		this->prescriptieMedicala = prescriptieMedicala;
		this->nrFarmaciiPartenere = nrFarmaciiPartenere;
	}
	//constructor de copiere
	Medicament(const Medicament& medicament) :termenValabilitate(medicament.termenValabilitate) {
		this->denumire = new char[strlen(medicament.denumire) + 1];
		strcpy_s(this->denumire, strlen(medicament.denumire) + 1, medicament.denumire);
		this->modDeAdministrare = medicament.modDeAdministrare;
		this->pretIntreg = medicament.pretIntreg;
		this->reducere = medicament.reducere;
		this->prescriptieMedicala = medicament.prescriptieMedicala;
		this->nrFarmaciiPartenere = medicament.nrFarmaciiPartenere;
	}
	//operatori
	Medicament& operator=(const Medicament& medicament) {        //3.1
		if (this != &medicament) {
			this->denumire = new char[strlen(medicament.denumire) + 1];
			strcpy_s(this->denumire, strlen(medicament.denumire) + 1, medicament.denumire);
			this->modDeAdministrare = medicament.modDeAdministrare;
			this->pretIntreg = medicament.pretIntreg;
			this->reducere = medicament.reducere;
			this->prescriptieMedicala = medicament.prescriptieMedicala;
			this->nrFarmaciiPartenere = medicament.nrFarmaciiPartenere;
			return *this;
		}

	}
	bool operator<(Medicament m) {      //3.2
		return this->pretIntreg < m.pretIntreg;
	}
	Medicament operator++(int) {       //3.3
		Medicament temporar = *this;
		this->reducere += 0.05;
		return temporar;

	}

	bool operator!=(Medicament m) {    //3.4
		return this->nrFarmaciiPartenere != m.nrFarmaciiPartenere;
	}
	//operator citire de la tastatura
	friend istream& operator>>(istream& citire, Medicament& m) {
		cout << "Denumire:";
		if (m.denumire != NULL) {
			delete[]m.denumire;

		}
		m.denumire = new char[strlen(m.denumire) + 1];
		citire >> m.denumire;
		cout << "Mod de administrare:"; citire >> m.modDeAdministrare;
		cout << "Pret intreg:"; citire >> m.pretIntreg;
		cout << "Reducere:"; citire >> m.reducere;
		cout << "Prescriptie medicala:"; citire >> m.prescriptieMedicala;
		cout << "Numar farmacii partenere:"; citire >> m.nrFarmaciiPartenere;
		return citire;
	}
	friend ostream& operator<<(ostream& scrie, const Medicament& m) {
		scrie << "Denumire:" << m.denumire << endl;
		scrie << "Mod de administrare:" << m.modDeAdministrare << endl;
		scrie << "Pret intreg:" << m.reducere << endl;
		scrie << "Reducere:" << m.reducere << endl;
		scrie << "TVA:" << m.TVA << endl;
		scrie << "Prescriptie medicala:" << m.prescriptieMedicala << endl;
		scrie << "Numar farmacii partenere:" << m.nrFarmaciiPartenere << endl;
		scrie << "Termen de valabiliate:" << m.termenValabilitate << " luni" << endl;
		return scrie;


	}

	~Medicament() {
		if (this->denumire != NULL)
		{
			delete[]this->denumire;

		}
	}
	//operator scriere in fisier ofstream
	friend ofstream& operator<<(ofstream& scrie, const Medicament& m) {
		scrie << m.denumire << endl;
		scrie << m.modDeAdministrare << endl;
		scrie << m.pretIntreg << endl;
		scrie << m.reducere;
		scrie << m.TVA << endl;
		scrie << m.prescriptieMedicala << endl;
		scrie << m.nrFarmaciiPartenere << endl;
		scrie << m.termenValabilitate << endl;
		return scrie;
	}
	//operator citire din fisier
	friend ifstream& operator>>(ifstream& citeste, Medicament& m) {
		if (m.denumire != NULL) {
			delete[]m.denumire;

		}
		m.denumire = new char[strlen(m.denumire) + 1];
		citeste >> m.denumire;
		citeste >> m.modDeAdministrare;
		citeste >> m.pretIntreg;
		citeste >> m.reducere;
		float val = 0;
		citeste >> val;//pentru tva care e de tip static
		citeste >> m.prescriptieMedicala;
		citeste >> m.nrFarmaciiPartenere;
		citeste >> val; //pentru termenValabilitate care e de tip const int
		return citeste;
	}
	//funct de acc var static
	static float getTVA() {
		return TVA;
	}
	friend void pretRedus(Medicament x);
};
float Medicament::TVA = 0.09;
class Pastila :public Medicament {
private:
	string substantaActiva;
	int nrComprimateZi;
	char* scop;
public:
	float sumaIncasata() {
		return (this->pretIntreg + this->pretIntreg* Medicament::TVA - this->pretIntreg * this->reducere)/this->nrComprimateZi;
	}
	string getSubstantaActiva() {
		return this->substantaActiva;
	}
	int getNrComprimateZi() {
		return this->nrComprimateZi;
	}
	char* getScop() {
		return this->scop;
	}
	void setSubstantaActiva(string substantaActiva) {
		if (substantaActiva.length() > 3) {
			this->substantaActiva = substantaActiva;
		}
	}
	void setNrComprimateZi(int nrComprimateZi) {
		if (nrComprimateZi > 0 && nrComprimateZi < 7) {
			this->nrComprimateZi = nrComprimateZi;
		}
	}
	void setScop(const char* scop) {
		if (this->scop != NULL) {
			delete[]this->scop;
		}
		this->scop = new char[strlen(scop) + 1];
		strcpy_s(this->scop, strlen(scop) + 1, scop);
	}
	Pastila() :Medicament("Parasinus", 23, 0, 50) {
		this->substantaActiva = "Paracetamol";
		this->nrComprimateZi = 3;
		this->scop = new char[strlen("raceala") + 1];
		strcpy_s(this->scop, strlen("raceala") + 1, "raceala");
	}
	Pastila(string substantaActiva, int nrComprimateZi, const char* scop) :Medicament() {
		this->substantaActiva = substantaActiva;
		this->nrComprimateZi = nrComprimateZi;
		this->scop = new char[strlen(scop) + 1];
		strcpy_s(this->scop, strlen(scop) + 1, scop);

	}
	Pastila(string modDeAdministrare, float pretIntreg, float reducere, bool prescriptieMedicala,
		int nrFarmaciiPartenere, const int termenV, string substantaActiva,
		int nrComprimateZi, const char* scop) :Medicament(modDeAdministrare, pretIntreg, reducere,
			prescriptieMedicala, nrFarmaciiPartenere, termenV) {
		this->substantaActiva = substantaActiva;
		this->nrComprimateZi = nrComprimateZi;
		this->scop = new char[strlen(scop) + 1];
		strcpy_s(this->scop, strlen(scop) + 1, scop);

	}
	Pastila(const Pastila& p) :Medicament(p) {
		this->substantaActiva = p.substantaActiva;
		this->nrComprimateZi = p.nrComprimateZi;
		this->scop = new char[strlen(p.scop) + 1];
		strcpy_s(this->scop, strlen(p.scop) + 1, p.scop);
	}
	Pastila operator=(const Pastila& p) {
		if (this != &p) {
			Medicament::operator=(p);
			this->substantaActiva = p.substantaActiva;
			this->nrComprimateZi = p.nrComprimateZi;
			if (this->scop != NULL) {
				delete[]this->scop;
			}
			this->scop = new char[strlen(p.scop) + 1];
			strcpy_s(this->scop, strlen(p.scop) + 1, p.scop);
		}
		return *this;
	}
	friend ostream& operator <<(ostream& scrie, const Pastila& p) {
		scrie << (Medicament)p;
		scrie << "Substanta activa:" << p.substantaActiva << endl;
		scrie << "Numar comprimate pe zi:" << p.nrComprimateZi << endl;
		scrie << "Folosita pentru tratare:" << p.scop << endl;
		return scrie;
	}
	~Pastila() {
		if (scop != NULL) {
			delete[]this->scop;
		}
	}
};
//noua clasa
class Doctor {
private:
	string nume;
	Spital spital;
	const int anNastere;
	float salariu;
	char* specializare;
	int aniVechime;
public:
	string getNume() {

		return this->nume;
	}
	Spital getSpital() {
		return this->spital;
	}
	const int getAnNastere() {

		return this->anNastere;
	}
	float getSalariu() {
		return this->salariu;
	}
	char* getSpecializare() {
		return this->specializare;
	}
	int getAniVechime() {
		return this->aniVechime;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setSpecializare(const char* specializare) {
		if (this->specializare != NULL)
		{
			delete[]this->specializare;
		}
		this->specializare = new char[strlen(specializare) + 1];
		strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
	}
	void setSpital(Spital s) {
		this->spital = s;
	}
	void setSalariu(float s) {
		this->salariu = s;
	}
	void setAniVechime(int a) {
		this->aniVechime = a;
	}
	Doctor() :anNastere(1978) {
		this->nume = "Popescu";
		this->spital = spital;
		this->salariu = 12000;
		this->specializare = new char[strlen("Cardiologie") + 1];
		strcpy_s(this->specializare, strlen("Cardiologie") + 1, "Cardiologie");
		this->aniVechime = 15;
	}
	Doctor(string nume, const char* specializare, const int an) :anNastere(an) {
		this->nume = nume;
		this->spital = spital;
		this->salariu = 10000;
		this->specializare = new char[strlen(specializare) + 1];
		strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
		this->aniVechime = 7;
	}
	Doctor(const Doctor& d) :anNastere(d.anNastere) {
		this->nume = d.nume;
		this->spital = d.spital;
		this->salariu = d.salariu;
		this->specializare = new char[strlen(d.specializare) + 1];
		strcpy_s(this->specializare, strlen(d.specializare) + 1, d.specializare);
		this->aniVechime = d.aniVechime;

	}
	//operatori
	friend istream& operator>>(istream& citire, Doctor& d) {
		cout << "Nume:"; citire >> d.nume;
		cout << "Spitalul la care lucreaza:"; citire >> d.spital;
		cout << "Salariul:"; citire >> d.salariu;
		cout << "Specializare:";
		if (d.specializare != NULL) {
			delete[]d.specializare;
		}
		d.specializare = new char[strlen(d.specializare) + 1];
		cin >> d.specializare;
		cout << "Ani vechime:"; citire >> d.aniVechime;
		return citire;
	}
	friend ostream& operator<<(ostream& scrie, const Doctor& d) {
		scrie << "Nume:" << d.nume << endl;
		scrie << "Spital:" << d.spital << endl;
		scrie << "Anul nasterii:" << d.anNastere << endl;
		scrie << "Salariul:" << d.salariu << endl;
		scrie << "Specializare:" << d.specializare << endl;
		scrie << "Ani vechime:" << d.aniVechime << endl;
		return scrie;
	}
	Doctor& operator=(const Doctor& doctor) {
		if (this != &doctor) {
			this->nume = doctor.nume;
			this->spital = doctor.spital;
			this->salariu = doctor.salariu;
			this->specializare = new char[strlen(doctor.specializare) + 1];
			strcpy_s(this->specializare, strlen(doctor.specializare) + 1, doctor.specializare);
			this->aniVechime = doctor.aniVechime;
			return *this;
		}

	}
	//metoda pentru a citi din fisier binar
	void citesteInFisBinar(fstream& f) {
		int sizeOfNume = this->nume.length();
		f.write((char*)&sizeOfNume, sizeof(int));
		for (int i = 0; i < sizeOfNume; i++) {
			f.write((char*)&this->nume[i], sizeof(char));
		}

		f.write((char*)&spital, sizeof(Spital));
		f.write((char*)&anNastere, sizeof(int));
		f.write((char*)&salariu, sizeof(float));
		int sizeOfSpecializare = strlen(this->specializare);
		f.write((char*)&sizeOfSpecializare, sizeof(int));
		for (int i = 0; i < sizeOfSpecializare; i++) {
			f.write((char*)&this->specializare[i], sizeof(char));
		}
		f.write((char*)&aniVechime, sizeof(int));


	}
	void citesteDinFisBinar(fstream& f) {
		int sizeOfNume;
		f.read((char*)&sizeOfNume, sizeof(int));
		for (int i = 0; i < sizeOfNume; i++) {
			f.read((char*)&this->nume[i], sizeof(char));
		}
		this->nume[sizeOfNume] = '\0';
		int val = 0;
		f.read((char*)&spital, sizeof(Spital));
		f.read((char*)&val, sizeof(int));
		f.read((char*)&salariu, sizeof(float));
		int sizeOfSpecializare;
		f.read((char*)&sizeOfSpecializare, sizeof(int));
		for (int i = 0; i < sizeOfSpecializare; i++) {
			f.read((char*)&this->specializare[i], sizeof(char));
		}
		this->specializare[sizeOfSpecializare] = '\0';
		f.read((char*)&aniVechime, sizeof(int));


	}

	~Doctor() {
		if (specializare != NULL) {
			delete[]this->specializare;
		}
	}
};

void pretRedus(Medicament x) {
	float y;
	y = x.pretIntreg - x.pretIntreg * x.reducere;
	cout << "Dupa aplicarea reducerii medicamentul " << x.denumire << " costa " << y << " lei";
}
void main() {
	Spital s1;
	cout << "Obiectul s1:" << endl;
	s1.afisare();
	paturiNecesare(s1);
	Spital s2("Ioan Lascar", 2009, 12, 34, "Comanesti");
	Spital s3(1990, 12, 88);
	cout << "Obiectul s2:" << endl;
	s2.afisare();
	cout << "Obiectul s3:" << endl;
	s3.afisare();
	cout << "******************************************************";
	echipamentMedical e1("EKG", "cardiologie", 5, 1);
	cout << "\nObiectul e1:";
	e1.afisare();
	echipamentMedical e2(1);
	cout << "Obiectul e2:";
	e2.afisare();
	echipamentMedical e3("Tensiometru", 4000);
	cout << "Obiectul e3:";
	e3.afisare();
	cout << "******************************************************";
	Medicament m1("Erdomed", 40, 1, 6);
	cout << "\nObiectul m1:";
	m1.afisare();
	Medicament m2("HCC", "Intravenos", 50, 0.3, 3);
	cout << "Obiectul m2:";
	m2.afisare();
	pretRedus(m2);
	Medicament m3("Oral", 76, 0.7, 0, 3, 12);
	cout << "\nObiectul m3:";
	m3.afisare();
	cout << "#########################################################";
	cout << "\nVERIFICARE GETTERI SI SETTERI:";
	cout << "\nPentru clasa Spital:" << endl;
	cout << "GETTERI:" << endl;
	cout << s1.getNume() << " |" << s1.getAnInfiintare() << " |" << s1.getNrPaturi() << " paturi | ";
	cout << s1.getNrPacienti() << " pacienti | " << s1.getSectiiATI() << " sectii ATI | " << s1.getLocalitate() << endl;
	cout << "SETTERI:" << endl;
	s1.setNume("Spitalul Militar");
	s1.setNrPaturi(20);
	s1.setNrPacienti(12);
	s1.setLocalitate("Sibiu");
	cout << s1.getNume() << " |" << s1.getAnInfiintare() << " |" << s1.getNrPaturi() << " paturi |";
	cout << s1.getNrPacienti() << " pacienti | " << s1.getSectiiATI() << " sectii ATI | " << s1.getLocalitate();
	cout << "\nPentru clasa echipamentMedical:" << endl;
	cout << "GETTERI:" << endl;
	cout << e1.getNume() << " |" << e1.getSpecializare() << " |" << e1.getPret() << " lei | ";
	cout << e1.getAniUtilizare() << " ani | " << e1.getPerioadaGarantie() << " ani garantie | ";
	cout << e1.getNrOperatori() << " operatori| ";
	cout << e1.getEstePornit() << " | " << e1.getNrDefectiuni() << " defectiuni" << endl;
	cout << "SETTERI:" << endl;
	e1.setNume("Spirometru");
	e1.setSpecializare("Pneumologie");
	e1.setPret(1500);
	e1.setAniUtilizare(8);
	e1.setEstePornit(1);
	e1.setNrDefectiuni(3);
	cout << e1.getNume() << " |" << e1.getSpecializare() << " |" << e1.getPret() << " lei | ";
	cout << e1.getAniUtilizare() << " ani | " << e1.getPerioadaGarantie() << " ani garantie | ";
	cout << e1.getNrOperatori() << " operatori| ";
	cout << e1.getEstePornit() << " | " << e1.getNrDefectiuni() << " defectiuni" << endl;
	cout << "Pentru clasa Medicament:\n";
	cout << "GETTERI:" << endl;
	cout << m1.getDenumire() << " |" << m1.getModDeAdministrare() << " |" << m1.getPretIntreg() << " lei | " << m1.getReducere() << " | ";
	cout << m1.getTVA() << " | " << m1.getPrescriptieMedicala() << " | " << m1.getNrFarmaciiPartenere() << " farmacii |";
	cout << m1.getTermenValabilitate() << " ani\n";
	cout << "SETTERI:" << endl;
	m1.setDenumire("Quixx");
	m1.setModDeAdministrare("Nazal");
	m1.setPretIntreg(21.50);
	m1.setReducere(0);
	m1.setPrescriptieMedicala(0);
	m1.setNrFarmaciiPartenere(30);
	cout << m1.getDenumire() << " |" << m1.getModDeAdministrare() << " |" << m1.getPretIntreg() << " lei | " << m1.getReducere() << " | ";
	cout << m1.getTVA() << " | " << m1.getPrescriptieMedicala() << " | " << m1.getNrFarmaciiPartenere() << " farmacii |";
	cout << m1.getTermenValabilitate() << " ani\n";
	cout << "#########################################################";
	Spital s4 = s2;
	cout << "\nObiectul s4 creat pe baza constructorului de copiere:" << endl;
	s4.afisare();
	cout << endl;
	Spital s5;
	cout << "\nObiectul s5:" << endl;
	s5.afisare();
	cout << "Dupa utilizrea operatorului = noul s5 va fi:" << endl;
	s5 = s3;
	s5.afisare();
	echipamentMedical e4 = e1;
	cout << "\nObiectul e4 realizat pe baza constructorului de copiere:" << endl;
	e4.afisare();
	echipamentMedical e5("Glucometru", "Diabetologie", 6, 2);
	cout << "\nObiectul e5:" << endl;
	e5.afisare();
	e5 = e2;
	cout << "Dupa utilizarea operatorului = obiectul e5 este:" << endl;
	e5.afisare();
	cout << endl;
	Medicament m4 = m3;
	cout << "obiectul m4 realizat pe baza constructorului de copiere este:";
	m4.afisare();
	Medicament m5("Sinupret", 64, 0, 7);
	cout << "\nObiectul m5 este:";
	m5.afisare();
	m5 = m1;
	cout << "\nDupa utilizarea operatorului = obiectul m5 este:" << endl;
	m5.afisare();
	cout << "Verificare operatori,exceptand cei de atribuire:" << endl;
	cout << "Operatorului <<:" << endl;
	cout << s1;
	Spital s6;
	cout << "Obiectul s6:" << endl;
	s6.afisare();
	Spital s7;
	s7.afisare();
	cout << "Obiectul s7:" << endl;
	s7 = ++s6;
	s7 = --s6;
	cout << "Dupa aplicarea operatorilor obiectul s7 este:" << endl;
	s7.afisare();
	echipamentMedical e6(1);
	cout << "Citire echipament medical" << endl;
	cin >> e6;
	e6.afisare();
	if (e1 > e2) {
		cout << "Echipamentul medical " << e1.getNume() << " este mai scump decat" << e2.getNume() << endl;
	}
	else
	{
		cout << "Echipamentul medical " << e1.getNume() << " este mai ieftin sau la fel de scump ca " << e2.getNume() << endl;
	}
	if (m2 < m4) {
		cout << "Medicamentul " << m2.getDenumire() << " este mai ieftin decat " << m4.getDenumire() << endl;
	}
	else
	{
		cout << "Medicamentul " << m2.getDenumire() << " este mai scump sau la fel de scump ca " << m4.getDenumire() << endl;
	}

	echipamentMedical e7(0);
	cout << "Obiectul e7:";
	e7.afisare();
	cout << "Obiectul e2:";
	e2.afisare();
	e2 = e7++;
	cout << "Obiectul e7:";
	e7.afisare();
	Medicament m6("Tranchisept", 23, 0, 12);
	Medicament m7("Aspenter", 15, 0, 39);
	m6.afisare();
	cout << "Obiectul m7:" << endl;
	m7.afisare();
	m6 = m7++;
	m6.afisare();
	cout << "Obiectul m7:" << endl;
	m7.afisare();
	if (m3 != m2) {
		cout << "Medicamentul " << m3.getDenumire() << " nu este la acelasi numar de farmacii precum medicamentul " << m2.getDenumire();
	}
	else
	{
		cout << "Medicamentul " << m3.getDenumire() << " este la acelasi numar de farmacii precum medicamentul " << m2.getDenumire();
	}
	Spital s[5];
	int i;
	cout << "Citire spitale:" << endl;
	for (i = 0; i < 2; i++) {
		cin >> s[i];
	}
	cout << "Afisare spitale:" << endl;
	for (i = 0; i < 2; i++) {
		cout << s[i];
		cout << "**********************************************************" << endl;
	}
	cout << "\nCitire echipament medical:" << endl;
	echipamentMedical e[5];
	for (i = 0; i < 2; i++) {
		cin >> e[i];

	}
	cout << "\nAfisare echipament medical:" << endl;
	for (i = 0; i < 2; i++) {
		cout << e[i];
		cout << "**************************************************************" << endl;


	}
	cout << "Citire medicamente:" << endl;
	Medicament m[5];
	for (i = 0; i < 2; i++) {
		cin >> m[i];
	}
	cout << "\nAfisare medicamente:" << endl;
	for (i = 0; i < 2; i++) {
		cout << m[i];
		cout << "*********************************************************************" << endl;
	}
	cout << "Citire matrice cu medicamente:" << endl;
	Medicament md[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cin >> md[i][j];
	}
	cout << "Afisare matrice cu medicamente:" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
		{
			cout << md[i][j];
			cout << "************************************************************************" << endl;
		}
	}
	Doctor d1;
	cout << "obiectul d1:" << d1 << endl;
	Doctor d2;
	cin >> d2;
	cout << "obiectul d2:" << d2 << endl;
	Doctor d3("Vasilescu", "Pneumologie", 1980);
	cout << "obiectul d3:" << endl << d3 << endl;
	Doctor d4;
	cout << "obiectul d4:" << endl << d4 << endl;
	d4 = d3;
	cout << "obiectul d4 dupa utilizarea operatorului =:" << endl << d4 << endl;
	Doctor d5 = d3;
	cout << "obiectul d5 dupa construirea cu ajutorului constructorului de copiere:" << endl << d5 << endl;
	cout << endl << "VERIFICARE GETTERI:" << endl;
	cout << d1.getNume() << "|" << d1.getSpital() << "|" << d1.getAnNastere() << "|" << d1.getSalariu() << "|";
	cout << d1.getAniVechime() << "|" << d1.getSpecializare() << endl;
	cout << "VERIFICARE SETTERI:" << endl;
	d4.setNume("Opincariu");
	d4.setAniVechime(8);
	d4.setSpecializare("Oncologie");
	d4.setSalariu(12330);
	Spital s10(2000, 12, 9); //anul infintarii este de tip const ceea ce inseamna ca valoarea primului parametru va fi inutila pt setter
	d4.setSpital(s10);
	cout << "d4 dupa setteri:" << endl << d4;
	//scriere in fisier text pentru clasa medicament
	Medicament m10;
	//cin >> m10;
	ofstream file("fisierM.txt", ios::out);
	file << m10;
	//scriere in fisier text pentru clasa spital
	Spital s11;
	//cin >> s11;
	ofstream f("fisierS.txt", ios::out);
	f << s11;
	//citire din fisierul text pentru clasa spital
	ifstream citeste("fisierS.txt", ios::in);
	Spital s12;
	citeste >> s12;
	cout << s12;
	//citire din fisierul text pentru clasa medicament
	ifstream citire("fisierM.txt", ios::in);
	Medicament m11;
	citire >> m11;
	cout << m11;
	//scriere in fisier binar pentru clasa echipamentMedical
	fstream fis("FisierBinar.echMed", ios::binary | ios::out);
	echipamentMedical e10;
	e10.citesteInFisBinar(fis);
	fis.close();
	cout << endl;
	//citire din fisier binar pentru clasa echipamentMedical
	fstream fi("FisierBinar.echMed", ios::binary | ios::in);
	echipamentMedical e11;
	e11.citesteDinFisBinar(fi);
	cout << e11;
	fi.close();
	//scriere in fisier binar pentru clasa Doctor
	fstream fisier("FisierBinar.doctor", ios::binary | ios::out);
	Doctor d10;
	d10.citesteInFisBinar(fisier);
	fisier.close();
	cout << endl;
	/*citire din fisier binar pentru clasa Doctor
	fstream fisie("FisierBinar.doctor", ios::binary | ios::in);
	Doctor d11;
	d11.citesteDinFisBinar(fisie);
	cout << d11;
	fisie.close();*/
	cout << "Verificare clasa SpitalPsihiatrie:" << endl;
	SpitalPsihiatrie sp1;
	cout << "Obiectul sp1:" << endl << sp1 << endl;
	SpitalPsihiatrie sp2("Socola", 1950, 80, 40, "Iasi", "Chiriac", 34, 5);
	cout << "Obiectul sp2:" << endl << sp2 << endl;
	SpitalPsihiatrie sp3(19, 3, "Pavel");
	cout << "Obiectul sp3:" << endl << sp3 << endl;
	SpitalPsihiatrie sp4 = sp3;
	cout << "Obiectul sp4:" << endl << sp4 << endl;
	sp3 = sp2;
	cout << "Obiectul sp3 dupa aplicarea operatorului = :" << endl << sp3 << endl;
	cout << endl << "VERIFICARE GETTERI SI SETTERI(se face doar pentru atributele proprii):" << endl;
	cout << "getteri:" << endl;
	cout << sp1.getNumeDirector() << "|" << sp1.getNrPsihiatrii() << " psihiatrii |" << sp1.getNrTerapii() << " terapii" << endl;
	cout << "setteri:" << endl;
	sp1.setNumeDirector("Ionescu");
	sp1.setNrPsihiatrii(15);
	sp1.setNrTerapii(2);
	cout << sp1.getNumeDirector() << "|" << sp1.getNrPsihiatrii() << " psihiatrii |" << sp1.getNrTerapii() << " terapii" << endl;
	cout << endl << "Verificare clasa Pastila:" << endl;
	Pastila p1;
	cout << "Obiectul p1:" << endl << p1 << endl;
	Pastila p2("Oral", 40, 0.2, 0, 39, 7, "Vitamina C", 2, "Imunitate");
	cout << "Obiectul p2:" << endl << p2 << endl;
	Pastila p3("Ibuprofen", 3, "Dureri");
	cout << "Obiectul p3:" << endl << p3 << endl;
	Pastila p4 = p2;
	cout << "Obiectul p4 care a fost creat cu ajutorul constructorului de copiere:" << endl << p4 << endl;
	p2 = p1;
	cout << "Obiectul p2 dupa utilizarea operatorului =:" << endl << p2 << endl;
	cout << endl << "VERIFICARE GETTERI SI SETTERI(se face doar pentru atributele proprii):" << endl;
	cout << p1.getSubstantaActiva() << "|" << p1.getNrComprimateZi() << " pastile|" << p1.getScop() << endl;
	p2.setSubstantaActiva("Desloratadina");
	p2.setNrComprimateZi(5);
	p2.setScop("Alergie");
	cout << p2.getSubstantaActiva() << "|" << p2.getNrComprimateZi() << " pastile|" << p2.getScop() << endl;
	//upcasting
	Medicament* m15;
	m15 = &p2;
	cout << endl << *m15;
Cladire** pointerC;
pointerC = new Cladire * [10];
pointerC[0] = new Spital();
pointerC[1] = new Spital(1930,34,89);
pointerC[2] = new SpitalPsihiatrie(8,2,"Vasilescu");
pointerC[3] = new SpitalPsihiatrie("Pantelimon",1980,87,67,"Bucuresti","Tudor",12,4);
pointerC[4] = new Spital("Spitalul Militar",1920,109,80,"Craiova");
pointerC[5] = new Spital(2004,200,125);
pointerC[6] = new SpitalPsihiatrie(12,1,"Petrescu");
pointerC[7] = new SpitalPsihiatrie();
pointerC[8] = new Spital(1999,198,33);
pointerC[9] = new SpitalPsihiatrie(12,3,"Pogor");
cout << "Numar de pacienti si doctori:" << endl;
for (int i = 0; i < 10; i++)
	cout << pointerC[i]->nrPacientiSiDoctori() << " persoane" << endl;
ProdusFarmaceutic** pointerPF;
pointerPF = new ProdusFarmaceutic * [10];
pointerPF[0] = new Medicament();
pointerPF[1] = new Medicament("Oral",45,0,12);
pointerPF[2] = new Pastila();
pointerPF[3] = new Pastila("Aciclofenac",2,"Dureri musculare");
pointerPF[4] = new Medicament("Amoxacilina","Oral",13,0,4);
pointerPF[5] = new Medicament("Cetirizina",68,0,4);
pointerPF[6] = new Pastila("Oral",98,0.2,1,76,9, "Vitamina C",4,"Imunitate");
pointerPF[7] = new Pastila("Ciclopirox",3,"Fungi");
pointerPF[8] = new Medicament("Dexametazona",34.5,1,88);
pointerPF[9] = new Pastila("Hidrocortizon",1,"Antialergen");
cout << "Sume incasate:" << endl;
for (int i = 0; i < 10; i++)
	cout << pointerPF[i]->sumaIncasata() <<" lei" << endl;
}
