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
	int getNrPacienti(){
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
		if(this->localitate!=NULL)
		{
			delete[]this->localitate;
		}
		this->localitate = new char[strlen(localitate) + 1];
		strcpy_s(this->localitate,strlen(localitate)+1, localitate);
	}
	Spital() :anInfiintare(1988) {                  //Lista de initializare
		this->nume = "Elias";
		this->nrPaturi = 15;
		this->nrPacienti = 3;
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

		this->localitate = new char[strlen(spital.localitate)+1];
		strcpy_s(this->localitate, strlen(spital.localitate) + 1, spital.localitate);
		
	}
	//destructor
	~Spital() {
		if (this->localitate != NULL)
		{
			delete[]this->localitate;
		}
	}
	static void nrNouSecATI()
	{
		nrSectiiATI = nrSectiiATI * 2;
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
	void setSpecializare( const char* specializare) {
		if (this->specializare!=NULL) {
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
	} }
	void setEstePornit(bool estePornit) {
		if ((estePornit == 1) || (estePornit == 0))
			this->estePornit = estePornit;
	}
	void setNrDefectiuni(int nrDefectiuni) {
		if (nrDefectiuni > -1) {
			this -> nrDefectiuni = nrDefectiuni;
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
		this->specializare = new char[strlen(EchipamentMedical.specializare)+1];
		strcpy_s(this->specializare, strlen(EchipamentMedical.specializare) + 1, EchipamentMedical.specializare);
		this->pret = EchipamentMedical.pret;
		this->aniUtilizare = EchipamentMedical.aniUtilizare;
		this->estePornit = EchipamentMedical.estePornit;
		this->nrDefectiuni = EchipamentMedical.nrDefectiuni;
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
	string getModDeAdministrare(){
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
		if(this->denumire!=NULL)
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
		this->denumire = new char[strlen(medicament.denumire)+1];
		strcpy_s(this->denumire, strlen(medicament.denumire) + 1, medicament.denumire);
		this->modDeAdministrare = medicament.modDeAdministrare;
		this->pretIntreg = medicament.pretIntreg;
		this->reducere = medicament.reducere;
		this->prescriptieMedicala = medicament.prescriptieMedicala;
		this->nrFarmaciiPartenere = medicament.nrFarmaciiPartenere;
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

void pretRedus(Medicament x) {
	float y;
	y = x.pretIntreg - x.pretIntreg * x.reducere;
	cout << "Dupa aplicarea reducerii medicamentul " << x.denumire << " costa " << y << " lei";
}
void main() {
	Spital s1;
	s1.afisare();
	paturiNecesare(s1);
	Spital s2("Ioan Lascar", 2009, 12, 34, "Comanesti");
	Spital s3(1990, 12, 88);
	s2.afisare();
	s3.afisare();
	cout << "******************************************************";
	echipamentMedical e1("EKG", "cardiologie", 5, 1);
	e1.afisare();
	echipamentMedical e2(1);
	e2.afisare();
	echipamentMedical e3("Tensiometru", 4000);
	e3.afisare();
	cout << "******************************************************";
	Medicament m1("Erdomed", 40, 1, 6);
	m1.afisare();
	Medicament m2("HCC", "Intravenos", 50, 0.3, 3);
	m2.afisare();
	pretRedus(m2);
	Medicament m3("Oral", 76, 0.7, 0, 3, 12);
	m3.afisare();

	cout << "\nverificare getteri si setteri:";
	cout << "\nPentru clasa Spital:" << endl;
	cout << s1.getNume() << " |" << s1.getAnInfiintare() << " |" << s1.getNrPaturi() << " paturi | ";
	cout << s1.getNrPacienti() << " pacienti | " << s1.getSectiiATI() << " sectii ATI | " << s1.getLocalitate()<<endl;
	s1.setNume("Spitalul Militar");
	s1.setNrPaturi(20);
	s1.setNrPacienti(12);
	s1.setLocalitate("Sibiu");
	cout << s1.getNume() << " |" << s1.getAnInfiintare() << " |" << s1.getNrPaturi() << " paturi |";
	cout << s1.getNrPacienti() << " pacienti | " << s1.getSectiiATI() << " sectii ATI | " << s1.getLocalitate();
	cout << "\nPentru clasa echipamentMedical:" << endl;
	cout << e1.getNume() << " |" << e1.getSpecializare() << " |" << e1.getPret() << " lei | ";
	cout << e1.getAniUtilizare() << " ani | " << e1.getPerioadaGarantie() << " ani garantie | " ;
	cout << e1.getNrOperatori() << " operatori| ";
	cout  << e1.getEstePornit() <<" | "<< e1.getNrDefectiuni() << " defectiuni" << endl;
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
	cout << "\nPentru clasa Medicament:\n";
	cout << m1.getDenumire() << " |" << m1.getModDeAdministrare() << " |" << m1.getPretIntreg() << " lei | " << m1.getReducere()<<" | ";
	cout << m1.getTVA() << " | " << m1.getPrescriptieMedicala() << " | " << m1.getNrFarmaciiPartenere() << " farmacii |";
	cout << m1.getTermenValabilitate() << " ani\n";
	m1.setDenumire("Quixx");
	m1.setModDeAdministrare("Nazal");
	m1.setPretIntreg(21.50);
	m1.setReducere(0);
	m1.setPrescriptieMedicala(0);
	m1.setNrFarmaciiPartenere(30);
	cout << m1.getDenumire() << " |" << m1.getModDeAdministrare() << " |" << m1.getPretIntreg() << " lei | " << m1.getReducere() << " | ";
	cout << m1.getTVA() << " | " << m1.getPrescriptieMedicala() << " | " << m1.getNrFarmaciiPartenere() << " farmacii |";
	cout << m1.getTermenValabilitate() << " ani\n";
	Spital s4 = s2;
	s4.afisare();
	cout << endl;
	echipamentMedical e4 = e1;
	e1.afisare();
	cout << endl;
	Medicament m4 = m3;
	m4.afisare();

}