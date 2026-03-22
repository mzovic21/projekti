// MD5:fa4/oxb8mJZRwWTXw5uR7w==// Verifikator 5.05// Program:Vježba3// Poèetno vrijeme: 12:01 (internetsko) Završno vrijeme: 13:32 Preostalo: 3 +// Opis zadatka:opis// Autor:Mateo Zoviæ// Poèetno vrijeme:31.3.2022. 12:01:35// Završno vrijeme:31.3.2022. 13:29:31// Identifikatori:main,x,troba,sifra,cijena,godina,naziv[35],unos_ispis,ispis_unos,vrijeme,*sljedeci,*prethodni,*glava,glava,*zadnji,*novi,novi,dodaj_kraj,ispis_pocetak,*trenutni,ispis_kraj,dodaj_pocetak,int,brisanje,br,*brisi,y,tstablo,*lijevo,*desno,stablo,*vrh,memcpy// IP:fe80::d5f:8681:47e9:d45%8 ( 1589 )// #:#include <iostream>,#include <conio.h>,#include <ctime>[B],#include "biblioteka_vrijeme.cc",#include <iomanip>,// Uspješnih/neuspješnih prevoðenja:36/8#include <iostream>
#include <conio.h>
#include "biblioteka_vrijeme.cc"
using namespace std;

struct troba{
	double vrijeme;
	float cijena;
	int sifra;
	int godina;
	char naziv[35];
	troba *sljedeci;
	troba *prethodni;
};

struct tstablo{
	double vrijeme;
	float cijena;
	int sifra;
	int godina;
	char naziv[35];
	troba *lijevo;
	troba *desno;
};

void dodaj_kraj(troba *glava)
{
	troba *zadnji;
	zadnji=glava;
	
	while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
	troba *novi=new troba;
	novi->sljedeci=NULL;
	novi->prethodni=zadnji;
	zadnji->sljedeci=novi;
	
	cout<<"Unesi sifru: "; cin>>novi->sifra;
	vrijeme_pocetak();
	cout<<"Unesi naziv robe: "; cin.ignore(); cin.getline(novi->naziv, 35);
	cout<<"Unesi cijenu komada: "; cin>>novi->cijena;
	cout<<"Unesi godinu proizvodnje: "; cin>>novi->godina;
	vrijeme_kraj();
	novi->vrijeme=vrijeme_proteklo()/1000;
	cout<<endl<<"Vrijeme upisa iznosi "<<novi->vrijeme<<" sekundi!"<<endl<<endl;
}
void ispis_pocetak(troba *glava)
{
	troba *trenutni=glava->sljedeci;
	
	while(trenutni){
		cout<<"-------------------"<<endl
			<<"Sifra: "<<trenutni->sifra<<endl
			<<"Naziv robe: "<<trenutni->naziv<<endl
			<<"Cijena komada: "<<trenutni->cijena<<endl
			<<"Godina proizvodnje: "<<trenutni->godina<<endl
			<<"Vrijeme unosa: "<<trenutni->vrijeme<<endl
			<<"Pokazivac sljedeci: "<<trenutni->sljedeci<<endl
			<<"Pokazivac prethodni: "<<trenutni->prethodni<<endl;
			
		trenutni=trenutni->sljedeci;
	}
}

void ispis_kraj(troba *glava)
{
	if(glava->sljedeci==NULL){
		ispis_pocetak(glava); 
		return;
	}
	
	troba *trenutni=glava->sljedeci;
	while(trenutni->sljedeci) trenutni=trenutni->sljedeci;
	while(trenutni!=glava){
		cout<<"-------------------"<<endl
			<<"Sifra: "<<trenutni->sifra<<endl
			<<"Naziv robe: "<<trenutni->naziv<<endl
			<<"Cijena komada: "<<trenutni->cijena<<endl
			<<"Godina proizvodnje: "<<trenutni->godina<<endl
			<<"Vrijeme unosa: "<<trenutni->vrijeme<<endl
			<<"Pokazivac sljedeci: "<<trenutni->sljedeci<<endl
			<<"Pokazivac prethodni: "<<trenutni->prethodni<<endl;
			
		trenutni=trenutni->prethodni;
	}
	
}
void dodaj_pocetak(troba *glava)
{
	if(glava->sljedeci==NULL){
		dodaj_kraj(glava);
		return;
	}
	
	troba *sljedeci;
	sljedeci=glava->sljedeci;
	troba *novi=new troba;
	novi->sljedeci=sljedeci;
	novi->prethodni=glava;
	sljedeci->prethodni=novi;
	glava->sljedeci=novi;
	
	cout<<"Unesi sifru: "; cin>>novi->sifra;
	vrijeme_pocetak();
	cout<<"Unesi naziv robe: "; cin.ignore(); cin.getline(novi->naziv, 35);
	cout<<"Unesi cijenu komada: "; cin>>novi->cijena;
	cout<<"Unesi godinu proizvodnje: "; cin>>novi->godina;
	vrijeme_kraj();
	novi->vrijeme=vrijeme_proteklo()/1000;
	cout<<endl<<"Vrijeme upisa iznosi "<<novi->vrijeme<<" sekundi!"<<endl<<endl;
}

void brisanje(troba *glava, int br)
{
	troba *prethodni, *brisi, *sljedeci;
	prethodni=glava;
	brisi=glava->sljedeci;
	
	while(brisi){
		if(brisi->sifra == br){
		int y;
		cout<<"-------------------"<<endl
			<<"Sifra: "<<brisi->sifra<<endl
			<<"Naziv robe: "<<brisi->naziv<<endl
			<<"Cijena komada: "<<brisi->cijena<<endl
			<<"Godina proizvodnje: "<<brisi->godina<<endl
			<<"Vrijeme unosa: "<<brisi->vrijeme<<endl
			<<"Pokazivac sljedeci: "<<brisi->sljedeci<<endl
			<<"Pokazivac prethodni: "<<brisi->prethodni<<endl<<endl
			<<"Zelite li obrisati element? (1/0) "; cin>>y;
			
			if(y){
				prethodni->sljedeci=brisi->sljedeci;
				sljedeci=brisi->sljedeci;
				if(sljedeci) sljedeci->prethodni=brisi->prethodni;
				delete brisi;
				cout<<"Element liste uspjesno obrisan!"<<endl;
			}
			return;
		}
		prethodni=brisi;
		brisi=brisi->sljedeci;
	}
	cout<<"Element liste ne postoji!"<<endl;
}

void stablo(troba *glava)
{
	while(glava->sljedeci != NULL){
		tstablo *vrh=new tstablo;
		memcpy(&vrh, &glava, sizeof(troba));
	}
	
}

int main(){
	system("color 03");
	
	troba *glava=new troba;
	glava->sljedeci=NULL;
	glava->prethodni=NULL;
	
	
	
	int x, br;
	
	do{
		cout<<endl<<"------ IZBORNIK ------"<<endl
			<<"1. Dodavanje elementa na kraj dvostruko vezane liste"<<endl
			<<"2. Dodavanje elementa na pocetak dvostruko vezane liste"<<endl
			<<"3. Brisanje elemenata iz dvostruko vezane liste"<<endl
			<<"4. Binarno stablo"<<endl
			<<"9. Izlaz iz programa"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
		
		switch(x){
			case 1: dodaj_kraj(glava); ispis_pocetak(glava);
			break;
			case 2: ispis_kraj(glava); dodaj_pocetak(glava);
			break;
			case 3: cout<<"Unesi sifru: "; cin>>br; brisanje(glava, br);
			break;
			case 4: cout<<"Nije rijeseno!"<<endl; //stablo(glava);
			break;
			case 9: break;
			
			default: cout<<"Pogresna opcija!"<<endl;
		}
	
	} while(x!=9);
	cout<<"Izlaz iz programa";
	
	cout<<endl;
	system("PAUSE");
	return 0;
} 
