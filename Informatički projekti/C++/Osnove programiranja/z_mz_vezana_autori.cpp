// MD5:pZMe0e5afPkPc0gsb6WkqA==
// Verifikator 5.05
// Program:vezana autori
// Opis zadatka:opis
// 
// Autor:mz z
// Poèetno vrijeme:22.3.2022. 21:19:53
// Završno vrijeme:22.3.2022. 22:50:51
// Identifikatori:main,x,unos,ispis,pretraga,brisanje,tautor,sifra,imeprez[40],naslov[50],*sljedeci,*glava,*novi,*zadnji,glava,zadnji,*tekuci,zbroj,br,*prethodni,*brisi
// IP:fe80::f936:49ec:7c2c:5719%19 ( 1589 )
// #:#include <iostream>,#include <conio.h>,
// Uspješnih/neuspješnih prevoðenja:24/3
#include <iostream>
#include <conio.h>
using namespace std;

struct tautor {
	int sifra;
	char imeprez[40];
	char naslov[50];
	tautor *sljedeci;
};

void unos(tautor *glava)
{
	tautor *novi, *zadnji;
	zadnji=glava;
	
	while(zadnji->sljedeci){
		zadnji=zadnji->sljedeci;
	}
	
	novi=new tautor;
	zadnji->sljedeci=novi;
	novi->sljedeci=NULL;
	
	cout<<"Sifra: "; cin>>novi->sifra;
	cout<<"Ime i prezime: "; cin.ignore(); cin.getline(novi->imeprez, 40);
	cout<<"Naslov: "; cin.getline(novi->naslov, 50);
}

void ispis(tautor *glava)
{
	tautor *tekuci=glava->sljedeci;
	int zbroj=0;
	
	while(tekuci){
		cout<<"Sifra: "<<tekuci->sifra<<endl
			<<"Ime i prezime: "<<tekuci->imeprez<<endl
			<<"Naslov: "<<tekuci->naslov<<endl
			<<"Vrijednost pokazivaca: "<<tekuci->sljedeci<<endl<<endl;
			
		zbroj+=tekuci->sifra;
		tekuci=tekuci->sljedeci;
	}
	cout<<"Zbroj sifra: "<<zbroj<<endl;
}

void pretraga(tautor *glava, int br)
{
	tautor *tekuci=glava->sljedeci;
	
	while(tekuci){
		if(tekuci->sifra == br){
			cout<<"Sifra: "<<tekuci->sifra<<endl
				<<"Ime i prezime: "<<tekuci->imeprez<<endl
				<<"Naslov: "<<tekuci->naslov<<endl;
				return;
		}
		tekuci=tekuci->sljedeci;
	}
	cout<<"Element nije pronaden!"<<endl;
}

void brisanje(tautor *glava, int br)
{
	tautor *brisi=glava->sljedeci;
	tautor *prethodni=glava;
	
	while(brisi){
		if(brisi->sifra == br){
			prethodni->sljedeci=brisi->sljedeci;
			delete brisi;
			cout<<"Element je uspjesno obrisan"<<endl;
			return;
		}
		prethodni=brisi;
		brisi=brisi->sljedeci;
	}
	cout<<"Element nije pronaden!"<<endl;
}

int main(){
	system("color 03");
	
	tautor *glava=new tautor;
	glava->sljedeci=NULL;
	
	int x, br;
	
	do{
		cout<<endl<<"-----------IZBORNIK-----------"<<endl
			<<"1. Unos novog elementa vezane liste"<<endl
			<<"2. Ispis sadrzaja vezane liste zajedno sa zbrojem primarnih kljuceva"<<endl
			<<"3. Pretrazivanje vezane liste"<<endl
			<<"4. Brisanje elementa liste"<<endl
			<<"9. Izlaz iz programa"<<endl
			<<"Opcija: "; cin>>x;
		cout<<"----------------------"<<endl;
		
		switch(x){
			case 1: unos(glava);
			break;
			case 2: ispis(glava);
			break;
			case 3: { cout<<"Pretrazi: "; cin>>br; 
					 pretraga(glava, br);}
			break;
			case 4: { cout<<"Obrisi: "; cin>>br; 
					 brisanje(glava, br);}
			break;
			case 9: break;
			
			default: cout<<"Pogresna opcija!"<<endl;
		}
	
	} while(x!=9);
	
	cout<<"Izlaz iz programa";

	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
