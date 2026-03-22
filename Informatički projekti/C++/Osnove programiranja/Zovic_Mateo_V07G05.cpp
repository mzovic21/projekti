// MD5:Tk8csysJh9X1F1ZMMvioyw==// Verifikator 5.05// Program:V07G05// Poèetno vrijeme: 12:01 (internetsko) Završno vrijeme: 13:32 Preostalo: 26 +// Opis zadatka:opis// Autor:Mateo Zoviæ// Poèetno vrijeme:5.5.2022. 12:01:45// Završno vrijeme:5.5.2022. 13:06:11// Identifikatori:dat,main,x,tprijava,sifra_prijave,sifra_predmeta,mat_broj,datum,tlista,*sljedeci,*glava,kreiraj,unos,brojac,zapis,glava,odabir,jos,prijava,*,dat.close,kopi,ispis,*novi,*zadnji,if,zadnji,*trenutni,indikator// IP:fe80::d5f:8681:47e9:d45%9 ( 1589 )// #:#include <iostream>,#include <conio.h>,#include <fstream>,// Uspješnih/neuspješnih prevoðenja:31/8#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

fstream dat;

struct tprijava{
	int sifra_prijave;
	int sifra_predmeta;
	int mat_broj;
	float datum;
};

struct tlista{
	int sifra_prijave;
	int sifra_predmeta;
	int mat_broj;
	float datum;
	tlista *sljedeci;
};
tlista *glava;

bool indikator=false;
int zapis=0;

void kreiraj()
{
	if(!indikator) cout<<"Datoteka ne postoji"<<endl;
	else cout<<"Datoteka postoji"<<endl;
	
	if(!zapis) cout<<"Datoteka je prazna"<<endl;
	else cout<<"Broj zapisa: "<<zapis<<endl;
	
	if(glava) cout<<"Glava liste postoji"<<endl;
	else cout<<"Ne postoji glava liste"<<endl;
	
	if(glava) cout<<"Vezana lista prazna: NE"<<endl;
	else cout<<"Vezana lista prazna: DA"<<endl;
	
	if(!indikator){
		dat.open("Prijave.dat", ios::out | ios::binary);
		dat.close();
		dat.clear();
		indikator=true;
		
		glava=new tlista;
		glava->sljedeci=NULL;
		return;
	}
	
	else{
		char odabir;
		cout<<"Kreiraj novu datoteku? (d/n): "; cin>>odabir;
		
		if(odabir=='d'){
			dat.open("Prijave.dat", ios::out | ios::binary);
			dat.close();
			dat.clear();
			indikator=true;
		
			glava=new tlista;
			glava->sljedeci=NULL;
		}
	}
}

void unos()
{
	if(!indikator){
		cout<<"Datoteka ne postoji!"<<endl;
		return;
	}
	
	char jos;
	do{
		tprijava prijava;
		dat.open("Prijave.dat", ios::binary | ios::in | ios::out | ios::ate);
		
		cout<<"Sifra prijave: "; cin>>prijava.sifra_prijave;
		cout<<"Sifra predmeta: "; cin>>prijava.sifra_predmeta;
		cout<<"Maticni broj studenta: "; cin>>prijava.mat_broj;
		cout<<"Datum ispita: "; cin>>prijava.datum;
		
		dat.write((char*)&prijava, sizeof(tprijava));
		
		dat.close();
		dat.clear();
		
		zapis++;
		
		cout<<"Zelite li ponoviti upis? (d/n): "; cin>>jos;
		cout<<endl;
	} while(jos=='d');
}

void kopi()
{
	if(!indikator){
		cout<<"Nije moguce kopiranje!"<<endl;
		return;
	}
	
	tprijava prijava;
	tlista *novi, *zadnji=glava;
	dat.open("Prijave.dat", ios::in | ios::binary);
	
	while(true){
		dat.read((char*)&prijava, sizeof(tprijava));
		if(dat.eof()) break;
		
		novi=new tlista;
		zadnji->sljedeci=novi;
		novi->sljedeci=NULL;
		novi->sifra_prijave=prijava.sifra_prijave;
		novi->sifra_predmeta=prijava.sifra_predmeta;
		novi->mat_broj=prijava.mat_broj;
		novi->datum=prijava.datum;
		
		zadnji=novi;
		
		cout<<"Primarni kljuc: "<<novi->sifra_prijave<<endl;
	}
	
	dat.close();
	dat.clear();
}

void ispis()
{
	if(!indikator) cout<<"Glava liste ne postoji!"<<endl;
	if(!zapis) cout<<"Lista je prazna!"<<endl;
	if(!indikator || !zapis) return;
	
	tlista *trenutni=glava->sljedeci;
	
	while(trenutni){
		cout<<"---------------------"<<endl
			<<"Sifra prijave: "<<trenutni->sifra_prijave<<endl
			<<"Sifra predmeta: "<<trenutni->sifra_predmeta<<endl
			<<"Maticni broj studenta: "<<trenutni->mat_broj<<endl
			<<"Datum ispita: "<<trenutni->datum<<endl
			<<"Pokazivac sljedeci: "<<trenutni->sljedeci<<endl;
			
		trenutni=trenutni->sljedeci;
	}
}

int main(){
	system("color 03");
	
	int x;
	
	do{
		cout<<endl<<"----- IZBORNIK ------"<<endl
			<<"1. Kreiraj datoteku i alokacija"<<endl
			<<"2. Rucni unos u datoteku"<<endl
			<<"3. Kopiranje u vezanu listu"<<endl
			<<"4. Ispis vezane liste"<<endl
			<<"9. Izlaz iz programa"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
		
		switch(x){
			case 1: kreiraj();
			break;
			case 2: unos();
			break;
			case 3: kopi();
			break;
			case 4: ispis();
			break;
			case 9: break;
			default: cout<<"Pogresan unos!"<<endl;
		}
	
	} while(x!=9);
	
	cout<<"Izlaz iz programa."<<endl;
	system("PAUSE");
	return 0;
}
