// MD5:44xSe/YZi1yB4TggFB2Bqg==
// Verifikator 5.05
// Program:proba datoteka
// Opis zadatka:opis
// Autor:m z
// Poèetno vrijeme:14.4.2022. 11:48:41
// Završno vrijeme:15.4.2022. 1:39:06
// Identifikatori:main,x,upis,upis2,dat,tpredmet,sifra,godina,prijava,vrijeme,naziv[35],predmet,jos,*,naziv[20],i,ar,&i,&ar,br,&zadnji,ispis,pretraga,zapis
// IP:fe80::d5f:8681:47e9:d45%9 ( 1589 )
// #:#include <iostream>,#include <conio.h>,#include <fstream>,#include <ctime>[B],#include "biblioteka_vrijeme.cc",#include <cstring>,
// Uspješnih/neuspješnih prevoðenja:45/15
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstring>
//#include "biblioteka_vrijeme.cc"
using namespace std;

struct tpredmet{
	char naziv[35];
	int sifra;
	int godina;
	int prijava;
	long vrijeme;
};
tpredmet predmet;
fstream dat;
char naziv[20];

void upis(int &i, int &ar, int &zadnji)
{
	dat.open(naziv, ios::binary | ios::out | ios::in);
	bool jos;
	
	do{
		i++; 
		cout<<"Sifra: "; cin>>predmet.sifra;
		//vrijeme_pocetak();
		cout<<"Naziv: "; cin.ignore(); cin.getline(predmet.naziv, 35);
		cout<<"Godina: "; cin>>predmet.godina;
		cout<<"Broj prijava: "; cin>>predmet.prijava;
		//vrijeme_kraj();
		ar+=predmet.prijava;
		//predmet.vrijeme=vrijeme_proteklo()/1000;
		dat.write((char*)&predmet, sizeof(predmet));
		zadnji=predmet.sifra;
		
		cout<<"Ukupan broj zapisa u datoteci iznosi: "<<i<<endl
			<<"Aritmeticka sredina broja prijava iznosi: "<<ar/i<<endl;
		cout<<"Dalje (1/0): "; cin>>jos;
		cout<<endl;
	} while(jos);
	dat.close();
	dat.clear();
}

void upis2(int br, int &zadnji, int &i, int &ar)
{
	dat.open(naziv, ios::out | ios::in | ios::binary);
	while(true){
		dat.read((char*)&predmet, sizeof(predmet));
		if(dat.eof()) break;
		if(predmet.sifra==br){
			i++;
			cout<<"Ta sifra postoji!"<<endl;
			predmet.sifra=++zadnji;
			cout<<"Nova vrijednost sifre: "<<predmet.sifra<<endl;
			cout<<"Naziv: "; cin.ignore(); cin.getline(predmet.naziv, 35);
			//vrijeme_pocetak();
			cout<<"Godina: "; cin>>predmet.godina;
			cout<<"Broj prijava: "; cin>>predmet.prijava;
			//vrijeme_kraj();
			ar+=predmet.prijava;
			//predmet.vrijeme=vrijeme_proteklo()/1000;
			dat.write((char*)&predmet, sizeof(predmet));
			cout<<endl<<"Ukupan broj zapisa u datoteci iznosi: "<<i<<endl
				<<"Aritmeticka sredina broja prijava iznosi: "<<(float)ar/i<<endl;
		}
	}
	dat.close();
	dat.clear();
}

void ispis()
{
	dat.open(naziv, ios::in | ios::binary);
	
	while(true){
		dat.read((char*)&predmet, sizeof(predmet));
		if(dat.eof()) break;
		cout<<"Sifra: "<<predmet.sifra<<endl
			<<"Naziv: "<<predmet.naziv<<endl
			<<"Godina: "<<predmet.godina<<endl
			<<"Broj prijava: "<<predmet.prijava<<endl<<endl;
	}
	dat.close();
	dat.clear();
}

void pretraga(int br)
{
	int zapis=0, j=0;
	dat.open(naziv, ios::in | ios::binary);
	while(true){
		dat.read((char*)&predmet, sizeof(predmet));
		if(dat.eof()) break;
		if(predmet.sifra==br){
			zapis++;
			cout<<"Sifra: "<<predmet.sifra<<endl
				<<"Naziv: "<<predmet.naziv<<endl
				<<"Godina: "<<predmet.godina<<endl
				<<"Broj prijava: "<<predmet.prijava<<endl<<endl
				<<"Redni broj zapisa: "<<j<<endl;
		}
		j++;
	}
	
	if(!zapis) cout<<"Sifra nije pronadena!"<<endl;
	dat.close();
	dat.clear();
}

int main(){
	system("color 03");
	
	strcpy(naziv, "Predmeti.dat");
	dat.open(naziv, ios::out | ios::binary);
	dat.close();
	dat.clear();
	
	int x, i=0, ar=0, br, zadnji;
	
	do{
		cout<<endl<<"----- IZBORNIK -----"<<endl
			<<"1. Upis"<<endl
			<<"2. Upis 2"<<endl
			<<"3. Ispis"<<endl
			<<"4. Pretraga"<<endl
			<<"9. Izlaz"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
		
		switch(x){
			case 1: upis(i, ar, zadnji);
			break;
			case 2: cout<<"Unesi sifru: "; cin>>br; upis2(br, zadnji, i, ar);
			break;
			case 3: cout<<"Aritmeticka sredina broja prijava: "<<ar/i<<endl; ispis();
			break;
			case 4: cout<<"Ukupan broj zapisa u datoteci: "<<i<<endl; 
					cout<<"Unesi sifru: "; cin>>br;
					pretraga(br);
			break;
			case 9: break;
			default: cout<<"Pogresna opcija!"<<endl;
		}
		
	} while(x!=9);
	cout<<"Izlaz iz programa"<<endl;
	
	system("PAUSE");
	return 0;
}
