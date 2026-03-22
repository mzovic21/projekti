// Ulaz n osoba max 50, njihova šifra, ime i prezime, spol, tezina, visina
// Izlaz odvojiti osobe po spolu i ispisati osobe cija relativna tezina je iznad prosjeka
// Realtivna tezina (omjer tezine i visine)
#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;

int main ()
{
	system("color 03");

	int n;

	do{
		cout<<"Unesi broj osoba: ";
		cin>>n;
	} while(n<1 || n>50);

	struct osobe{
		int sifra;
		char preziime[50];
		char spol;
		float tezina;
		int visina;
		float omjer;
	};
	osobe ljud[50];
	
	for(int i=0; i<n; i++){
		cout<<"Unesi sifru: ";
		cin>>ljud[i].sifra;
		cout<<"Unesi prezime i ime: ";
		cin.ignore();
		cin.getline(ljud[i].preziime, 50);
		cout<<"Unesi spol (M ili Z): ";
		cin>>ljud[i].spol;
		cout<<"Unesi tezinu: ";
		cin>>ljud[i].tezina;
		cout<<"Unesi visinu (u cm): ";
		cin>>ljud[i].visina;
	}
	
	float ukupnoZ=0, ukupnoM=0;
	int brojacZ=0, brojacM=0;
	for(int i=0; i<n; i++){
		if(ljud[i].spol=='M'){
			ljud[i].omjer = ljud[i].tezina / ljud[i].visina;
			ukupnoM+=ljud[i].omjer;
			brojacM++;
		}
		if(ljud[i].spol=='Z'){
			ljud[i].omjer = ljud[i].tezina / ljud[i].visina;
			ukupnoZ+=ljud[i].omjer;
			brojacZ++;
		}
	}

	ukupnoM/=brojacM;
	ukupnoZ/=brojacZ;
	cout<<"Prosjek M: "<<ukupnoM<<endl
		<<"Prosjek Z: "<<ukupnoZ<<endl
		<<"--------------------------";
	
	for(int i=0; i<n; i++){
		if(ljud[i].spol=='M' && ljud[i].omjer > ukupnoM){
			cout<<"M -> "<<ljud[i].preziime<<endl;
		}
		if(ljud[i].spol=='Z' && ljud[i].omjer > ukupnoZ){
			cout<<"Z -> "<<ljud[i].preziime<<endl;
		}
	}

	cout<<endl<<endl;
	system("pause");
	return 0;
}

