// MD5:EpVnOEKX/ThpfexIBNBQFg==// Verifikator 5.05// Program:Datoteka// Poèetno vrijeme: 15:56 (internetsko) Završno vrijeme: 17:26 Preostalo: 56 +// Opis zadatka:opis// Autor:Mateo Zoviæ// Poèetno vrijeme:9.3.2022. 15:56:24// Završno vrijeme:9.3.2022. 16:29:53// Identifikatori:main,tslog,mat_br,prez_ime[35],g_upisa,slog,dat,izbor,unos,jos,*,ispis,c// IP:fe80::d5f:8681:47e9:d45%8 ( 1589 )// #:#include <iostream>,#include <fstream>,// Uspješnih/neuspješnih prevoðenja:23/5#include <iostream>
#include <fstream>
using namespace std;

struct tslog{
	int mat_br;
	char prez_ime[35];
	int g_upisa;
}; 
tslog slog;

fstream dat;

void unos(){
	char jos='d';
	dat.open("podaci.dat", ios::out | ios::binary);
	
	while((jos=='d') || (jos=='D')){
		cout<<"Maticni broj: ";
		cin>>slog.mat_br;
		cout<<"Prezime i ime: ";
		cin>>slog.prez_ime;
		cout<<"Godina upisa: ";
		cin>>slog.g_upisa;
		
		dat.write((char *) &slog, sizeof(slog));
		cout<<"Hocete li jos upisivati (d/n)? ";
		cin>>jos;
	};
	dat.close();
	dat.clear();
};

void ispis(){
	dat.open("podaci.dat", ios::in | ios::binary);
	while(1){
		dat.read((char *) &slog, sizeof(slog));
		if(dat.eof()) break;
		
		cout<<"Maticni broj: "<<slog.mat_br<<endl
			<<"Prezime i ime: "<<slog.prez_ime<<endl
			<<"Godina upisa: "<<slog.g_upisa<<endl;
	};
	dat.close();
	dat.clear();
};

int main(){
	
	int izbor;
	
	do{
		cout<<"Izaberite: "<<endl<<endl
			<<"1. Unos podataka u datoteku"<<endl
			<<"2. Ispis podataka iz datoteke"<<endl
			<<"9. Izlaz iz programa"<<endl;
		cin>>izbor;
		
		switch(izbor){
			case 1: unos();
			break;
			case 2: ispis();
			break;
			case 9: break;
			default:
			cout<<"Pogresan unos!"<<endl;
			};
	
	} while(izbor!=9);
	
	cout<<"Kraj programa!"<<endl;
	char c;
	cin>>c;

	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
