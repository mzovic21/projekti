// MD5:/zzHASWuoqFqjXQs8ex7Dg==
// Verifikator 5.05
// Program:Vezanalista
// Opis zadatka:opis
// Autor:M Z
// Poèetno vrijeme:19.3.2022. 22:51:46
// Završno vrijeme:20.3.2022. 0:27:54
// Identifikatori:main,x,unos,ispis,pretraga,brisanje,tstudent,mbroj,god,imeprez[40],*sljedeci,*glava,*novi,*zadnji,glava,zadnji,*tekuci,br,*brisi,*prethodni,imeprez
// IP:fe80::f936:49ec:7c2c:5719%19 ( 1589 )
// #:#include <iostream>,#include <conio.h>,#include <cstring>,
// Uspješnih/neuspješnih prevoðenja:24/1
#include <iostream>
#include <conio.h>
//#include <cstring>
using namespace std;

struct tstudent{
	int mbroj;
	int god;
	char imeprez[40];
	tstudent *sljedeci;
};

void unos(tstudent *glava)
{
	tstudent *novi, *zadnji;
	zadnji=glava;
	
	while(zadnji->sljedeci){
		zadnji=zadnji->sljedeci;
	}
	
	novi=new tstudent;
	zadnji->sljedeci=novi;
	novi->sljedeci=NULL;
	cout<<"Unos MB: ";
	cin>>novi->mbroj;
	cout<<"Ime i prez: ";
	cin.ignore();
	cin.getline(novi->imeprez, 40);
	cout<<"Godina: ";
   	cin>>novi->god;
}

void ispis(tstudent *glava)
{
	tstudent *tekuci=glava->sljedeci;
	while(tekuci){
		cout<<"MB: "<<tekuci->mbroj<<endl
			<<"Ime: "<<tekuci->imeprez<<endl
			<<"God: "<<tekuci->god<<endl;
		tekuci=tekuci->sljedeci;
	}
}

void pretraga(tstudent *glava, int br)
{
	tstudent *tekuci=glava->sljedeci;
	while(tekuci){
		if(tekuci->mbroj == br){
			cout<<"MB: "<<tekuci->mbroj<<endl
			<<"Ime: "<<tekuci->imeprez<<endl
			<<"God: "<<tekuci->god<<endl;
		tekuci=tekuci->sljedeci;
		}
		tekuci=tekuci->sljedeci;
	}
}

void brisanje(tstudent *glava, int br)
{
	tstudent *brisi=glava->sljedeci;
	tstudent *prethodni=glava;
	while(brisi){
		if(brisi->mbroj == br){
			prethodni->sljedeci=brisi->sljedeci;
			delete brisi;
		}
		prethodni=brisi;
		brisi=brisi->sljedeci;
	}
}


int main(){

	system("color 03");

	tstudent *glava=new tstudent;
	glava->sljedeci=NULL;

	int x, br;

	do{
		cout<<endl<<"----IZBORNIK----"<<endl
			 <<"1. Unos novog elementa"<<endl
 			 <<"2. Ispis sadrzaja +zbroj PK"<<endl
 			 <<"3. Pretrazivanje"<<endl
 			 <<"4. Brisanje"<<endl
 			 <<"9. Izlaz"<<endl
 			 <<"Opcija: ";
 		cin>>x;
		 
 		switch(x){
		 	case 1: unos(glava);
	 		break;
		 	case 2: ispis(glava);
	 		break;
		 	case 3: { cout<<"Pretraga: ";
	 				 cin>>br;
	 				 pretraga(glava, br);}
	 		break;
		 	case 4: { cout<<"Brisi: ";
	 				 cin>>br;
	 				 brisanje(glava, br);}
	 		break;
		 	case 9: break;
		 
 			default: cout<<"Krivo uneseni broj!";
 		}
	
	} while(x!=9);
	
	cout<<endl<<"Izlaz iz programa";

	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
  
  
