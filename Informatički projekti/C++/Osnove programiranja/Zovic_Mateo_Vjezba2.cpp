// MD5:H05ydd0rzF0itdKf2vG6Lw==// Verifikator 5.05// Program:Vježba2// Poèetno vrijeme: 15:58 (internetsko) Završno vrijeme: 17:29 Preostalo: 37 +// Opis zadatka:opis
// // Autor:Mateo Zoviæ// Poèetno vrijeme:25.3.2022. 15:58:37// Završno vrijeme:25.3.2022. 16:52:00// Identifikatori:main,x,unos,ispis,pretraga,brisanje,tautor,sifra,imeprez[40],naslov[50],*sljedeci,*glava,glava,*novi,*zadnji,zadnji,zbroj,*tekuci,br,*prethodni// IP:fe80::d5f:8681:47e9:d45%8 ( 1589 )// #:#include <iostream>,#include <conio.h>,// Uspješnih/neuspješnih prevoðenja:28/4#include <iostream>
#include <conio.h>
using namespace std;

struct tautor{
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
	
	cout<<"Unesi sifru: "; cin>>novi->sifra;
	cout<<"Unesi prezime i ime: "; cin.ignore(); cin.getline(novi->imeprez, 40);
	cout<<"Unesi naslov rada: "; cin.getline(novi->naslov, 50);
}

void ispis(tautor *glava)
{
	int zbroj=0;
	tautor *tekuci;
	tekuci=glava->sljedeci;
	
	while(tekuci){
		cout<<"------------------"<<endl
			<<"Sifra: "<<tekuci->sifra<<endl
			<<"Prezime i ime: "<<tekuci->imeprez<<endl
			<<"Naslov rada: "<<tekuci->naslov<<endl
			<<"Vrijednost pokazivaca: "<<tekuci->sljedeci<<endl;
			
		zbroj+=tekuci->sifra;
		tekuci=tekuci->sljedeci;
	}
	cout<<endl<<"Zbroj svih primarnih kljuceva: "<<zbroj<<endl;
}

void pretraga(tautor *glava, int br)
{
	tautor *tekuci;
	tekuci=glava->sljedeci;
	
	while(tekuci){
		if(tekuci->sifra == br){
			cout<<"Sifra: "<<tekuci->sifra<<endl
				<<"Prezime i ime: "<<tekuci->imeprez<<endl
				<<"Naslov rada: "<<tekuci->naslov<<endl;
				return;
		}
		tekuci=tekuci->sljedeci;
	}
	cout<<"Element liste nije pronaden"<<endl;
}

void brisanje(tautor *glava, int br)
{
	tautor *prethodni, *zadnji;
	prethodni=glava;
	zadnji=glava->sljedeci;
	
	while(zadnji){
		if(zadnji->sifra == br){
			prethodni->sljedeci = zadnji->sljedeci;
			delete zadnji;
			cout<<"Element uspjesno izbrisan!"<<endl;
			return;
		}
		prethodni=zadnji;
		zadnji=zadnji->sljedeci;	
	}
	cout<<"Element nije pronaden!"<<endl;
}

int main(){
	system("color 03");
	
	int br;
	tautor *glava=new tautor;
	glava->sljedeci=NULL;
	
	int x;
	
	do{
		cout<<endl<<"-------IZBORNIK-------"<<endl
			<<"1. Unos novog elementa vezane liste"<<endl
			<<"2. Ispis sadrzaja vezane liste zajedno sa zbrojem primarnih kljuceva"<<endl
			<<"3. Pretrazivanje vezane liste"<<endl
			<<"4. Brisanje elementa liste"<<endl
			<<"9. Izlaz iz programa"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
			
		switch(x){
			case 1: unos(glava);
			break;
			case 2: ispis(glava);
			break;
			case 3: cout<<"Unesi sifru: "; cin>>br;
					pretraga(glava, br);
			break;
			case 4: cout<<"Unesi sifru: "; cin>>br;
					brisanje(glava, br);
			break;
			case 9: break;
			
			default: cout<<"Pogresna opcija!"<<endl;
		}
	
	} while(x!=9);
	
	
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
  
  
  
