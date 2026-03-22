// MD5:LvlIhZiJ5iHhGJmF6jMxmw==// Verifikator 5.05// Program:V10G04// Poèetno vrijeme: 11:01 (internetsko) Završno vrijeme: 12:32 Preostalo: 15 +// Opis zadatka:opis// Autor:Mateo Zoviæ// Poèetno vrijeme:3.6.2022. 11:02:05// Završno vrijeme:3.6.2022. 12:17:22// Identifikatori:main,x,cvrste2,sifra,naziv[30],cijena,unos,cvrste1,*sljedeci,vrste2,*novi,*zadnji,zadnji,*vrste1,do,sljedeci,ispis,*trenutni,crobe2,sifraR,sifraV,kom,crobe1,*robe2,robe2,int,*robe1,jos,robe1,broj,kljuc,pretraga,postoji,cout<<"Alociram,cout<<"Alociram// IP:fe80::f936:49ec:7c2c:5719%20 ( 1589 )// #:#include <iostream>,#include <conio.h>,// Uspješnih/neuspješnih prevoðenja:38/12#include <iostream>
#include <conio.h>
using namespace std;

class cvrste2{
	public:
	int sifra;
	char naziv[30];
	float cijena;
	
	void unos(){
		cout<<"Unesi sifru vrste: "; cin>>sifra;
		cout<<"Naziv vrste robe: "; cin.ignore(); cin.getline(naziv, 30);
		cout<<"Cijena komada: "; cin>>cijena;
	}
	
	void ispis(){
		cout<<"Sifra vrste: "<<sifra<<endl
			<<"Naziv vrste robe: "<<naziv<<endl
			<<"Cijena komada: "<<cijena<<endl;
	}
	
	cvrste2(){
		cout<<"Alociram cvrste2"<<endl;
	}
	
	int kljuc(){
		return sifra;
	}
};

class cvrste1{
	public:
	cvrste1 *sljedeci;
	cvrste2 vrste2;
	
	cvrste1(){
		sljedeci=NULL;
		cout<<"Alociram cvrste1"<<endl;
	}
	
	void unos(){
		cvrste1 *novi, *zadnji;
		zadnji=this;
		while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
		novi=new cvrste1;
		zadnji->sljedeci=novi;
		novi->vrste2.unos();
		novi->vrste2.kljuc();

	}
	
	void ispis(){
		cvrste1 *trenutni=this->sljedeci;
		while(trenutni){
			trenutni->vrste2.ispis();
			cout<<"Pokazivac sljedeci: "<<trenutni->sljedeci;
			trenutni=trenutni->sljedeci;
			cout<<endl<<endl;
		}
	}
	
};
cvrste1 *vrste1;

class crobe2{
	public:
	int sifraR;
	int sifraV;
	int kom;
	
	void unos(){
		cout<<"Unesi sifru robe: "; cin>>sifraR;
		cout<<"Unesi sifru vrste: "; cin>>sifraV;
		cout<<"Broj komada: "; cin>>kom;
	}
	
	void ispis(){
		cout<<"Sifra robe: "<<sifraR<<endl
			<<"Sifra vrste: "<<sifraV<<endl
			<<"Broj komada: "<<kom<<endl;
	}
	
	crobe2(){
		cout<<"Alociram crobe2"<<endl;
	}
	
	int kljuc(){
		return sifraV;
	}
	
};

class crobe1{
	public:
	crobe1 *sljedeci;
	crobe2 *robe2;
	
	crobe1(){
		robe2=new crobe2;
		sljedeci=NULL;
		cout<<"Alociram crobe1"<<endl;
	}
	
	void unos(){
		crobe1 *novi, *zadnji;
		zadnji=this;
		while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
		novi=new crobe1;
		zadnji->sljedeci=novi;
		novi->robe2->unos();
		novi->robe2->kljuc();
	}
	
	void ispis(){
		crobe1 *trenutni=this->sljedeci;
		while(trenutni){
			trenutni->robe2->ispis();
			cout<<"Pokazivac sljedeci: "<<trenutni->sljedeci;
			trenutni=trenutni->sljedeci;
			cout<<endl<<endl;
		}
	}
	
	void pretraga(int broj){
		bool postoji=false;
		crobe1 *trenutni=this->sljedeci;
		while(trenutni){
			if(broj==trenutni->robe2->sifraV){
				trenutni->robe2->ispis();
				cout<<trenutni->sljedeci<<endl;
				postoji=true;
			}
			trenutni=trenutni->sljedeci;
		}
		if(!postoji) cout<<"Pod sifrom "<<broj<<" nije upisana ni jedan roba!"<<endl;
	}
};
crobe1 *robe1;

int main(){
	system("color 03");
	
	int x, broj;
	bool jos;
	vrste1=new cvrste1;
	robe1=new crobe1;
	
	do{
		cout<<endl<<"--- IZBORNIK ---"<<endl
			<<"1. Unos vrsta robe na kraj liste"<<endl
			<<"2. Unos roba na kraj liste"<<endl
			<<"3. Ispis liste vrsta robe i liste robe"<<endl
			<<"4. Popis roba zadane vrste"<<endl
			<<"9. Izlaz"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
		
		switch(x){
			case 1: vrste1->unos();
			break;
			case 2: do{
						robe1->unos(); 
						cout<<"Jos? (1/0): "; cin>>jos;
					}while(jos);
			break;
			case 3: vrste1->ispis(); cout<<"--------"<<endl; robe1->ispis();
			break;
			case 4: cout<<"Unesi sifru vrste robe: "; cin>>broj; cout<<endl; robe1->pretraga(broj);
			case 9: break;
			default: cout<<"Pogresna opcija!"<<endl;
		};
	
	}while(x!=9);
	
	system("PAUSE");
	return 0;
}
