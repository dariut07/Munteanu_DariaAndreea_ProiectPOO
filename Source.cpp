#include<iostream>
using namespace std;
//domeniul ales este MeDicina
class Spital {
private:
	string nume;
	const int anInfiintare;
	int nrPaturi;
	int nrPacienti;
	static int nrSectiiATI;
	char* localitate;
public:
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
		cout << endl ;
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
	//functie de accesare var statica
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
		scrie << "Perioada de garantie" << e.perioadaGarantie << " ani" << endl;
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
class Medicament {
private:
	char* denumire;
	string modDeAdministrare;
	float pretIntreg;
	float reducere; //medicamente compensate
	static float TVA;
	bool prescriptieMedicala;
	int nrFarmaciiPartenere;
	const int termenValabilitate; //masurat in luni
public:
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
		if (reducere > -1) {
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
	//funct de acc var static
	static float getTVA() {
		return TVA;
	}
	friend void pretRedus(Medicament x);
};
float Medicament::TVA = 0.09;
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
	 char* getSpecializare(){
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
		this->spital =spital;
		this->salariu = 12000;
		this->specializare = new char[strlen("Cardiologie") + 1];
		strcpy_s(this->specializare, strlen("Cardiologie") + 1, "Cardiologie");
		this->aniVechime = 15;
	}
	Doctor(string nume,const char* specializare,const int an) :anNastere(an) {
		this->nume = nume;
		this->spital = spital;
		this->salariu = 10000;
		this->specializare = new char[strlen(specializare) + 1];
		strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
		this->aniVechime = 7;
	}
	Doctor(const Doctor& d):anNastere(d.anNastere) {
		this->nume = d.nume;
		this->spital = d.spital;
		this->salariu = d.salariu;
		this->specializare = new char[strlen(d.specializare) + 1];
		strcpy_s(this->specializare, strlen(d.specializare) + 1, d.specializare);
		this->aniVechime = d.aniVechime;
		
	}
	//operatori
	friend istream& operator>>(istream& citire, Doctor& d) {
		cout << "Nume:";citire >> d.nume;
		cout << "Spitalul la care lucreaza:"; citire >> d.spital;
		cout << "Salariul:"; citire >> d.salariu;
		cout << "Specializare:"; 
		if(d.specializare!=NULL){
		delete[]d.specializare;
		}
		d.specializare = new char[strlen(d.specializare) + 1];
		cin>>d.specializare;
		cout << "Ani vechime:"; citire >> d.aniVechime;
		return citire;
	}
	friend ostream& operator<<(ostream& scrie, const Doctor& d) {
		scrie << "Nume:" << d.nume << endl;
		scrie << "Spitalul la care lucreaza:\n" << d.spital << endl;
		scrie << "Anul nasterii:" << d.anNastere << endl;
		scrie << "Salariul:" << d.salariu<< endl;
		scrie << "Specializare:" << d.specializare << endl;
		scrie << "Anii vechime:" << d.aniVechime << " ani" << endl;
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
cout <<"obiectul d1:"<< d1 << endl;
Doctor d2;
cin >> d2;
cout <<"obiectul d2:"<< d2 << endl;
Doctor d3("Vasilescu", "Pneumologie", 1980);
cout << "obiectul d3:"<<endl << d3 << endl;
Doctor d4;
cout << "obiectul d4:" << endl<<d4<< endl;
d4 = d3;
cout << "obiectul d4 dupa utilizarea operatorului =:"<<endl << d4 << endl;
Doctor d5=d3;
cout << "obiectul d5 dupa construirea cu ajutorului constructorului de copiere:"<<endl << d5 << endl;
cout << endl << "VERIFICARE GETTERI:" << endl;
cout << d1.getNume() << "|" << d1.getSpital() << "|" << d1.getAnNastere() << "|" << d1.getSalariu() << "|";
cout<< d1.getAniVechime() << "|"<<d1.getSpecializare()<<endl;
cout << "VERIFICARE SETTERI:" << endl;
d4.setNume("Opincariu");
d4.setAniVechime(8);
d4.setSpecializare("Oncologie");
d4.setSalariu(12330);
Spital s10(2000,12,9); //anul infintarii este de tip const ceea ce inseamna ca valoarea primului parametru va fi inutila pt setter
d4.setSpital(s10);
cout << "d4 dupa setteri:" << endl << d4;
}
