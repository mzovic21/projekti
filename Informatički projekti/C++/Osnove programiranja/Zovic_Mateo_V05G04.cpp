// MD5:3PjGhMtBKGWLEWmZ08vyew==// Verifikator 5.05// Program:V05G04// Poèetno vrijeme: 13:02 (internetsko) Završno vrijeme: 14:33 Preostalo: 23 *// Opis zadatka:opis// Autor:Mateo Zovic// Poèetno vrijeme:22.4.2022. 13:03:13// Završno vrijeme:22.4.2022. 14:10:09// Identifikatori:dat,prostbr,main,tpredmet,naziv[35],sifra,upisani,godina,brojz,x,sif,kreiraj,unos,brk,broj,prost,i,j,predmet,*,dat.close,rb_zapisa,adresa,predmet2,cout<<"Redni,do,while,1,pretraga,ispis,naden,if,sekunde,<<endl,rb_zapisa2,adresa2// IP:fe80::d5f:8681:47e9:d45%9 ( 1589 )// #:#include <ctime>[B],#include <iostream>[B],#include <conio.h>,#include <fstream>,#include <cmath>,#include "biblioteka_vrijeme.cc",// Uspješnih/neuspješnih prevoðenja:32/4#include <iostream>
#include <conio.h>
#include <fstream>
#include <cmath>
#include "biblioteka_vrijeme.cc"
using namespace std;

fstream dat;
int prostbr;

struct tpredmet{
	char naziv[35];
	int sifra;
	int upisani;
	int godina;
	int brojz;
};

void kreiraj()
{
	int broj;
	bool prost=true;
	
	do{
		do{
			cout<<"Unesi broj: "; cin>>broj;
		} while(broj<10 || broj>100);
		for(int i=2; i<=sqrt(broj); i++){
		if(broj%i==0) prost=false;
		}
	
	} while(prost);
	
	for(int i=--broj; i>1; i--){
		prost=true;
		
		for(int j=2; j<=sqrt(i); j++){
			if(i%j==0){
				prost=false;
				break;
			}
		}
		
		if(prost){
			prostbr=i;
			cout<<"Prvi manji prosti broj: "<<prostbr<<endl;
			break;
		}
	}
	
	tpredmet predmet;
	
	dat.open("Predmet.dat", ios::out | ios::binary);
	
	for(int i=0; i<broj; i++){
		predmet.brojz=i;
		dat.write((char*)&predmet, sizeof(tpredmet));
	}
	
	dat.close();
	dat.clear();
}

void unos()
{
	int rb_zapisa, adresa;
	tpredmet predmet, predmet2;
	cout<<"Sifra: "; cin>>predmet.sifra;
	cout<<"Naziv: "; cin.ignore(); cin.getline(predmet.naziv, 35);
	cout<<"Broj upisanih: "; cin>>predmet.upisani;
	cout<<"Godina: "; cin>>predmet.godina;
	
	rb_zapisa=predmet.sifra%prostbr;
	adresa=rb_zapisa*sizeof(tpredmet);
	cout<<"Redni broj zapisa je "<<rb_zapisa<<endl
		<<"Adresa zapisa je "<<adresa<<endl;
		
		dat.open("Predmet.dat", ios::out | ios::in | ios::binary);
		
		dat.seekg(rb_zapisa*sizeof(tpredmet));
		do{
			dat.read((char*)&predmet2, sizeof(tpredmet));
		} while(predmet2.sifra>0);
		
		int rb_zapisa2, adresa2;
		rb_zapisa2=(dat.tellg() / sizeof(tpredmet))-1;
		adresa2=rb_zapisa2*sizeof(predmet);
		dat.seekp(adresa2);
		
		if(rb_zapisa2!=rb_zapisa){
			cout<<"-- Pronaden duplikat! --"<<endl
				<<"Redni broj zapisa (novi) je "<<rb_zapisa2<<endl
				<<"Adresa zapisa (nova) je "<<adresa2<<endl;
		}
		
		predmet.brojz=predmet2.brojz;
		dat.write((char*)&predmet, sizeof(tpredmet));
		
		dat.close();
		dat.clear();
}

void pretraga(int sif)
{
	int rb_zapisa, adresa;
	tpredmet predmet;
	
	rb_zapisa=sif%prostbr;
	adresa=rb_zapisa*sizeof(tpredmet);
	cout<<"Redni broj zapisa je "<<rb_zapisa<<endl
		<<"Adresa zapisa je "<<adresa<<endl;
		
	bool naden=false;
	
	dat.open("Predmet.dat", ios::in | ios::binary);
	
	dat.seekg(rb_zapisa*sizeof(tpredmet));
	
	do{
		dat.read((char*)&predmet, sizeof(tpredmet));
		if(dat.eof()) break;
		
		if(predmet.sifra == sif){
			cout<<"-- Pronaden duplikat! --"<<endl;
			naden=true;
			cout<<"Broj zapisa: "<<predmet.brojz<<endl
				<<"Sifra: "<<predmet.sifra<<endl
				<<"Naziv: "<<predmet.naziv<<endl
				<<"Broj upisanih: "<<predmet.upisani<<endl
				<<"Godina: "<<predmet.godina<<endl;
				break;
		}
	
	} while(predmet.sifra>0);
	
	dat.close();
	dat.clear();
	
	if(!naden) cout<<"Zapis nije pronaden."<<endl;
}

void ispis()
{
	vrijeme_kraj();
	int sekunde;
	sekunde=vrijeme_proteklo()/1000;
	cout<<"Proteklo vrijeme: "<<sekunde/60<<" minute i "<<sekunde%60<<" sekunde!"<<endl<<endl;
	
	dat.open("Predmet.dat", ios::in | ios::binary);
	
	tpredmet predmet;
	
	while(true){
		dat.read((char*)&predmet, sizeof(tpredmet));
		if(dat.eof()) break;
		
		if(predmet.sifra != 0){
			cout<<"Redni broj u datoteci: "<<predmet.brojz<<endl
				<<"Adresa: "<<predmet.brojz*sizeof(tpredmet)<<endl
				<<"Sifra: "<<predmet.sifra<<endl
				<<"Naziv: "<<predmet.naziv<<endl
				<<"Broj upisanih: "<<predmet.upisani<<endl
				<<"Godina: "<<predmet.godina<<endl<<endl;
		}
	}
	
	dat.close();
	dat.clear();
}

int main(){
	system ("color 03");
	
	vrijeme_pocetak();
	
	int x, sif, brk=0, bru=0, bri=0, brp=0;
	
	do{
		cout<<endl<<"----- IZBORNIK -----"<<endl
			<<"1. Kreiranje datoteke"<<endl
			<<"2. Unos podataka"<<endl
			<<"3. Pretrazivanje datoteke"<<endl
			<<"4. Ispis i statistika"<<endl
			<<"9. Izlaz iz programa"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
		
		switch(x){
			case 1: brk++; kreiraj();
			break;
			case 2: bru++; unos();
			break;
			case 3: brp++; cout<<"Unesi sifru: "; cin>>sif; pretraga(sif);
			break;
			case 4: bri++; ispis();
					cout<<"--- Broj poziva ---"<<endl
						<<"Opcija 1: "<<brk<<endl
						<<"Opcija 2: "<<bru<<endl
						<<"Opcija 3: "<<brp<<endl
						<<"Opcija 4: "<<bri<<endl;
						
			break;
			case 9: break;
			default: cout<<"Pogresan unos!"<<endl;
		}
	
	} while(x!=9);


	system("PAUSE");
}
