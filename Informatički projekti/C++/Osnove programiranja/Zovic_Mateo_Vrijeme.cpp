// MD5:8B4aXABNfR0bAuP+1c2lQg==// Verifikator 5.05// Program:Vrijeme// Poèetno vrijeme: 15:38 (internetsko) Završno vrijeme: 17:00 Preostalo: 76 +// Opis zadatka:opis// Autor:Mateo Zoviæ// Poèetno vrijeme:9.3.2022. 15:38:46// Završno vrijeme:9.3.2022. 15:44:24// Identifikatori:main,br_sec,min,sat,sec// IP:fe80::d5f:8681:47e9:d45%8 ( 1589 )// #:#include <iostream>,// Uspješnih/neuspješnih prevoðenja:7/0#include <iostream>
using namespace std;

int main(){

	int br_sec, min, sat, sec;
	
	cout<<"Unesi broj sekundi: ";
	cin>>br_sec;
	
	sat=br_sec/3600;
	min=br_sec%3600/60;
	sec=br_sec-(sat*3600)-(min*60);
	
	cout<<sat<<"h: "<<min<<"min: "<<sec<<'s'<<endl;
	cin>>sec;
	
	cout<<endl<<endl;
	system("PAUSE");
	
	return 0;
}
