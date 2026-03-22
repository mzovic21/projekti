// MD5:RdPHdRhR9L1XTfxCZtrnkA==// Verifikator 5.05// Program:Vježba1// Poèetno vrijeme: 15:32 (internetsko) Završno vrijeme: 17:03 Preostalo: 16 *// Opis zadatka:opis// Autor:Mateo Zoviæ// Poèetno vrijeme:16.3.2022. 15:33:03// Završno vrijeme:16.3.2022. 16:47:04// Identifikatori:main,x,polje,funkcija,polje[][15],struktura,vrijeme,polje[][12],i,a,b,povrsinatrokuta,rez,ptrokuta,tmjesto,ocjena,sifra,imeprez[30],mjesto1,mjesto2,void,cout,c,s// IP:fe80::d5f:8681:47e9:d45%8 ( 1589 )// #:#include <iostream>,#include<conio.h>,#include <cstring>,#include <conio.h>,#include <cmath>,#include <ctime>[B],#include "biblioteka_vrijeme.cc",#include <iomanip>,// Uspješnih/neuspješnih prevoðenja:34/24#include <iostream>
#include <conio.h>
#include <cstring>
#include <cmath>
#include <iomanip>
#include "biblioteka_vrijeme.cc"
using namespace std;

void polje()
{
	char polje[][12]={"prozor", "svjetiljka", "televizor", "olovka", "monitor"};
	
	cout<<"Sadrzaj polja: ";
	for(int i=0; i<5; i++){
		cout<<polje[i]<<" ";
	}
	
}

double ptrokuta(double a, double b);

void funkcija()
{
	double a,b;
	
	cout<<"Unesi duzinu stranice a: ";
	cin>>a;
	cout<<"Unesi duzinu stranice b: ";
	cin>>b;	
	
	if(ptrokuta(a,b) == -1){
		cout<<"Nije moguce izracunati povrsinu!";
	}
	
	else{
		cout<<"Povrsina iznosi: "<<ptrokuta(a,b);
	}
}

double ptrokuta(double a, double b)
{
	double rez;
	
	if(a<=0 || b<=0){
		return -1;
	}
	
	rez=(a*b)/2;
	return rez;
}

void struktura()
{
	struct tmjesto{
		float ocjena;
		int sifra;
		char imeprez[30];
	};
	tmjesto mjesto1;
	
	mjesto1.ocjena = 4.43;
	mjesto1.sifra = 421;
	strcpy(mjesto1.imeprez,"Matic Melita");
	
	tmjesto mjesto2;
	
	memcpy(&mjesto2,&mjesto1,sizeof(tmjesto));
	
	cout << mjesto2.ocjena << endl
		 << mjesto2.sifra << endl
 		 << mjesto2.imeprez << endl;	
}

void vrijeme()
{
	double a,b,c;
	
	do{
		cout<<"Unesi duzinu stranice a: ";
		cin>>a;
		vrijeme_pocetak();
		cout<<"Unesi duzinu stranice b: ";
		cin>>b;
		cout<<"Unesi duzinu stranice c: ";
		cin>>c;
		vrijeme_kraj();
		cout<<"Vrijeme upisa iznosi: "<<vrijeme_proteklo()/10<<" (stotinka sekunde)"<<endl;
	} while(a+b<c || b+c<a || c+a<b);
	
	double s,rez;
	
	s=(a+b+c)/2;
	rez=sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<"Povrsina trokuta iznosi: "<< fixed << setprecision(1) << rez;
	
}

int main(){
	system("color 03");
	
	int x;
	
	do{
		cout<<endl<<"-------------------"<<endl
			<<"IZBORNIK: "<<endl
			<<"1. Polje"<<endl
			<<"2. Funkcija"<<endl
			<<"3. Struktura"<<endl
			<<"4. Mjerenje vremena"<<endl
			<<"9. Izlaz iz programa"<<endl;
			
		cout<<"Opcija: ";
		cin>>x;
		
		switch(x){
			case 1:	polje();
			break;
			case 2:	funkcija();
			break;
			case 3:	struktura();
			break;
			case 4:	vrijeme();
			break;
			case 9:
			break;	
			
			default:	cout<<"Pogreska unosa!";
		}
	
	} while(x!=9);
	cout<<"Izlaz iz programa";
	
	cout<<endl<<endl;
	system("PAUSE");
}
  
