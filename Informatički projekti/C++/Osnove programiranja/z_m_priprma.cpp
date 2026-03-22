// MD5:1nRqY5NH1nlI2LndiT49Vw==
// Verifikator 5.05
// Program:priprma
// Opis zadatka:opis
// Autor:m z
// Poèetno vrijeme:28.4.2022. 13:10:56
// Završno vrijeme:29.4.2022. 0:58:10
// Identifikatori:main,x,tinventar,naziv[35],sifra,vrijednost,godina,kreiraj,dat,ind,tindeks,adresa,odabir,unos,inventar,indeks,*,dat.close,indeks.sifra,jos,jos[3],da[3],jos[2],pretraga,ispis,br,naden,void,if,cout<<"Adresa,while,brojac,ind.write,cout,cout<<"Sifra,dat.seekg
// IP:fe80::f936:49ec:7c2c:5719%20 ( 1589 )
// #:#include <iostream>,#include <conio.h>,#include <fstream>,#include <cstring>,
// Uspješnih/neuspješnih prevoðenja:99/21
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstring>
using namespace std;

fstream dat, ind;

struct tinventar{
	char naziv[35];
	int sifra;
	int godina;
	float vrijednost;
};

struct tindeks{
	int sifra;
	int adresa;
};

void kreiraj()
{
	bool odabir;
	if(dat && ind){
		cout<<"Zelite li obrisati datoteke? (1/0): ";
		cin>>odabir;
	}
		
	if(!odabir) return;
		
	dat.open("inventar.dat", ios::out);
	dat.close(); 
	dat.clear();
		
	ind.open("indeks.ind", ios::out);
	ind.close();
	ind.clear();
}

void unos()
{
	string jos;
	do{
	tinventar inventar;
	tindeks indeks;
	int brojac;
	
	dat.open("inventar.dat", ios::binary | ios::in | ios::out | ios::ate);
	ind.open("indeks.ind", ios::binary | ios::in | ios::out | ios::ate);
	
	cout<<"Sifra: "; cin>>inventar.sifra;
	cout<<"Naziv: "; cin.ignore(); cin.getline(inventar.naziv, 35);
	cout<<"Vrijednost: "; cin>>inventar.vrijednost;
	cout<<"Godina: "; cin>>inventar.godina;
	
	indeks.sifra=inventar.sifra;
	indeks.adresa=(int)dat.tellp();
	
	dat.write((char*)&inventar, sizeof(tinventar));
	ind.write((char*)&indeks, sizeof(tindeks));
	
	dat.close();
	dat.clear();
	ind.close();
	ind.clear();
	
	
	cout<<"Zelite li ponoviti upis? (da/ne): "; cin>>jos;
	cout<<endl;
	
	} while(jos=="da" || jos=="DA");
}

void pretraga(int br)
{
	tinventar inventar;
	tindeks indeks;
	bool naden=false;
	
	dat.open("inventar.dat", ios::in | ios::binary);
	ind.open("indeks.ind", ios::in | ios::binary);
	
	while(true){
		ind.read((char*)&indeks, sizeof(tindeks));
		
		if(ind.eof()) break;
		if(indeks.sifra==br){
			naden=true;
			dat.seekg(indeks.adresa);
			dat.read((char*)&inventar, sizeof(tinventar));
			cout<<"Adresa zapisa: "<<indeks.adresa<<endl
				<<"Sifra: "<<inventar.sifra<<endl
				<<"Naziv: "<<inventar.naziv<<endl
				<<"Vrijednost: "<<inventar.vrijednost<<endl
				<<"Godina: "<<inventar.godina<<endl;
			break;
		}
	}
	
	if(!naden) cout<<"Zapis nije pronaden!"<<endl;
	
	dat.close();
	dat.clear();
	ind.close();
	ind.clear();
}

void ispis()
{
	tinventar inventar;
	tindeks indeks;
	int brojac;
	
	dat.open("inventar.dat", ios::in | ios::binary);
	ind.open("indeks.ind", ios::in | ios::binary);
	
	while(true){
		ind.read((char*)&indeks, sizeof(tindeks));
		if(ind.eof()) break;
		dat.seekg(indeks.adresa);
		dat.read((char*)&inventar, sizeof(tinventar));
		
		brojac=dat.tellg()/sizeof(tinventar);
		
		cout<<"Sifra zapisa: "<<indeks.sifra<<endl
			<<"Adresa zapisa: "<<indeks.adresa<<endl
				<<"Sifra: "<<inventar.sifra<<endl
				<<"Naziv: "<<inventar.naziv<<endl
				<<"Vrijednost: "<<inventar.vrijednost<<endl
				<<"Godina: "<<inventar.godina<<endl<<endl;
	}
	cout<<"Ukupan broj zapisa: "<<brojac<<endl;
	
	dat.close();
	dat.clear();
	ind.close();
	ind.clear();
}

int main(){
	system("color 03");
	
	int x, br;
	
	do{
		cout<<endl<<"---- -- IZBORNIK -- -----"<<endl
			<<"1. Kreiraj maticnu i indeksnu datoteku"<<endl
			<<"2. Rucni unos podataka"<<endl
			<<"3. Pretrazivanje prema primarnom kljucu"<<endl
			<<"4. Ispis sadrzaja maticne datoteke prema redoslijedu primarnog kljuca"<<endl
			<<"9. Izlaz iz programa"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
		
		switch(x){
			case 1: kreiraj();
			break;
			case 2: unos();
			break;
			case 3: cout<<"Unesi sifru: "; cin>>br; pretraga(br);
			break;
			case 4: ispis();
			break;
			case 9: break;
			default: cout<<"Pogresan unos!"<<endl;
		}
		
	} while(x!=9);
	
	cout<<"Izlaz iz programa"<<endl;
	
	system("PAUSE");
	return 0;
}
