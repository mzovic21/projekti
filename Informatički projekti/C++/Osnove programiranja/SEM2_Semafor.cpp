// MD5:o/5IMNCfk804QDeqD85Odw==
// Verifikator 5.05
// Program:Semafor
// Opis zadatka:Semafor za automobile, pješake, u raznim bojama i drugo...
// Autor:Mateo Zoviæ
// Poèetno vrijeme:16.5.2022. 9:51:10
// Završno vrijeme:16.5.2022. 11:37:22
// Identifikatori:RESET,CRNA,CRVENA,ZELENA,ZUTA,PLAVA,LJUBICASTA,TIRKIZNA,BIJELA,SIVA,CRVENA2,ZELENA2,ZUTA2,PLAVA2,LJUBICASTA2,TIRKIZNA2,BIJELA2,main,x,semafor1,semafor2,objekt,boja,uzorak,broj,i,35,j,objekt2,semafor3,int,boje,y,jos,"<<endl,break,z,break,break,break
// IP:fe80::d5f:8681:47e9:d45%9 ( 1589 )
// #:#include <iostream>,#include <conio.h> //biblioteka za promjenu boja, koristi se samo na poèetku izvoðenja programa,#include <windows.h> //služi za stavljanje programa u stanje 'mirovanja' tj definiranje trajanja stanke,#define RESET "\033[0m" //	potreban za resetirati boju na zadano,#define CRNA "\033[30m",#define CRVENA "\033[31m",#define ZELENA "\033[32m",#define ZUTA "\033[33m",#define PLAVA "\033[34m",#define LJUBICASTA "\033[35m" ,#define TIRKIZNA "\033[36m",#define BIJELA "\033[37m",#define SIVA "\033[1m\033[30m",#define CRVENA2 "\033[1m\033[30m",#define ZELENA2 "\033[1m\033[30m",#define ZUTA2 "\033[1m\033[30m",#define PLAVA2 "\033[1m\033[30m",#define LJUBICASTA2 "\033[1m\033[30m",#define TIRKIZNA2 "\033[1m\033[30m",#define BIJELA2 "\033[1m\033[30m",#include <windows.h> //služi za stavljanje programa u 'stanje mirovanja' tj definiranje trajanja stanke,#define CRVENA2 "\033[1m\033[31m",#define ZELENA2 "\033[1m\033[32m",#define ZUTA2 "\033[1m\033[33m",#define PLAVA2 "\033[1m\033[34m",#define LJUBICASTA2 "\033[1m\033[35m",#define TIRKIZNA2 "\033[1m\033[36m",#define BIJELA2 "\033[1m\033[37m",#include <cstring>,
// Uspješnih/neuspješnih prevoðenja:71/5
// Izradit æe se programsko rješenje zadatka semafor. Ideja je izraditi semafor koji odbrojava
// proteklo vrijeme tj. koji broji koliko do promjene boje svjetla. Postojat æe opcije
// semafora za automobil, za pješake, semafor za trke i opcija za mjenjanje boje i uzoraka 
// semafora. Za sve navedene opcije definirat æe se neki 'objekt' tj. putem petlja æe se ispisivati neki oblik slièan obliku semafora. 
#include <iostream>
#include <conio.h> //biblioteka za promjenu boja, koristi se samo na poèetku izvoðenja programa
#include <windows.h> //služi za stavljanje programa u 'stanje mirovanja' tj definiranje trajanja stanke
#include <cstring>
//ovdje slijedi definiranje svake boje u programu:
#define RESET "\033[0m" //	potreban za resetirati boju na zadano
#define CRNA "\033[30m"
#define CRVENA "\033[31m"
#define ZELENA "\033[32m"
#define ZUTA "\033[33m"
#define PLAVA "\033[34m"
#define LJUBICASTA "\033[35m" 
#define TIRKIZNA "\033[36m"
#define BIJELA "\033[37m"
#define SIVA "\033[1m\033[30m"
#define CRVENA2 "\033[1m\033[31m"
#define ZELENA2 "\033[1m\033[32m"
#define ZUTA2 "\033[1m\033[33m"
#define PLAVA2 "\033[1m\033[34m"
#define LJUBICASTA2 "\033[1m\033[35m"
#define TIRKIZNA2 "\033[1m\033[36m"
#define BIJELA2 "\033[1m\033[37m"
using namespace std;

string boja, uzorak;

//za potrebe rada semafora potrebno je prvo izraditi neki oblik koji æe se prikazivati
void objekt(string boja, string uzorak) //ulazi u objekt (opcija biranja boje i uzorka)
{
	int broj=18, pon=7;
	while(broj<24){ //gornji dio oblika tj rastuæi niz
		for(int i=7; i>0; i--){
			cout<<boja<<"\t\t\t\t   "; //razmak u svakom redu
			for(; pon>=0; pon--) cout<<" "; //svaki red ima drugi broj razmaka
			for(int j=0; j<broj; j++) cout<<uzorak; //svaki red ima razlicit broj znakova u redu
			broj+=2;
			pon+=i;
			cout<<endl;
		}
	}
	
	pon=2, broj=26;
	while(broj>18){ //donji dio oblika tj padajuæi niz
		for(int i=0; i<6; i++){
			pon=i+2;
			cout<<boja<<"\t\t\t\t   "; //razmak na pocetku reda
			for(; pon>=0; pon--) cout<<" "; 
			for(int j=-1; j<=broj; j++) cout<<uzorak;
			
			broj-=2; //pomak je za 2 kako bi se dobio oblik jednakog izgleda s lijeve i desne strane tj svaki sljedeci red je za 2 znaka manji (ili veci) od proslog
			cout<<endl;
		}
	
	}
	cout<<endl<<endl;
}

void objekt2(string boja) //sastoji se od 2 objekta koji se nalaze jedan pored drugog
{
	// jedan dio koda je isti kao i kod objekta
	int broj=18, pon=7, pon2=7, i;
	while(broj<24){ //gornji dio objekta
		for(i=6; i>=0; i--){
			cout<<boja<<"\t\t";
			for(; pon>0; pon--) cout<<" ";
			for(int j=0; j<broj; j++) cout<<"#"; //uzorak
	// drugi objekt koji se nalazi pored prvog
			cout<<boja<<"\t\t";
			for(; pon2>0; pon2--) cout<<" ";
			for(int j=0; j<broj; j++) cout<<"#"; //uzorak
		
			broj+=2;
			pon+=i;
			pon2+=i;
			cout<<endl;
		}
	}
// donji dio objekta
	pon=2, pon2=2; broj=26;
	while(broj>18){
		for(int i=0; i<6; i++){
			pon=i+2;
			cout<<boja<<"\t\t";
			for(; pon>0; pon--) cout<<" ";
			for(int j=-1; j<=broj; j++) cout<<"#";
			
			pon2=i+2;
			cout<<boja<<"\t\t";
			for(; pon2>0; pon2--) cout<<" ";
			for(int j=-1; j<=broj; j++) cout<<"#";
			
			broj-=2;
			cout<<endl;
		}
	}
	cout<<endl<<endl;
}

void boje() // i za kraj dati æe se korisniku na moguænost odabir boje uzorka, kao i znak
// ispune samog objekta
{
// ovo sljedece je puno pisanja i definiranje opcija....
	int y;
	bool jos;
	do{
// odabir boja
		cout<<endl<<RESET<<"   --- PREGLED BOJA ---"<<endl
			<<CRNA<<"\t 1. CRNA"<<BIJELA<<"(1. CRNA)"<<endl //crno na crno neæe biti vidljivo
			<<CRVENA<<"\t 2. CRVENA"<<endl 
			<<ZELENA<<"\t 3. ZELENA"<<endl 
			<<ZUTA<<"\t 4. ZUTA"<<endl 
			<<PLAVA<<"\t 5. PLAVA"<<endl 
			<<LJUBICASTA<<"\t 6. LJUBICASTA"<<endl 
			<<TIRKIZNA<<"\t 7. TIRKIZNA"<<endl 
			<<BIJELA<<"\t 8. BIJELA"<<endl 
			<<SIVA<<"\t 9. SIVA"<<endl
			<<CRVENA2<<"\t10. CRVENA"<<endl 
			<<ZELENA2<<"\t11. ZELENA"<<endl 
			<<ZUTA2<<"\t12. ZUTA"<<endl 
			<<PLAVA2<<"\t13. PLAVA"<<endl 
			<<LJUBICASTA2<<"\t14. LJUBICASTA"<<endl 
			<<TIRKIZNA2<<"\t15. TIRKIZNA"<<endl 
			<<BIJELA2<<"\t16. BIJELA"<<endl<<endl;
			
		cout<<BIJELA<<"Odaberi boju: "; cin>>y;
		switch(y){
			case 1: boja=CRNA; break;
			case 2: boja=CRVENA; break;
			case 3: boja=ZELENA; break;
			case 4: boja=ZUTA; break;
			case 5: boja=PLAVA; break;
			case 6: boja=LJUBICASTA; break;
			case 7: boja=TIRKIZNA; break;
			case 8: boja=BIJELA; break;
			case 9: boja=SIVA; break;
			case 10: boja=CRVENA2; break;
			case 11: boja=ZELENA2; break;
			case 12: boja=ZUTA2; break;
			case 13: boja=PLAVA2; break;
			case 14: boja=LJUBICASTA2; break;
			case 15: boja=TIRKIZNA2; break;
			case 16: boja=BIJELA2; break;
			default: cout<<"Pogresan unos"<<endl;
		} 
// jos je potrebno izraditi odabir uzorka
		int z;
		cout<<boja<<endl<<endl<<"   --- PREGLED UZORAKA ---"<<endl
			<<"\t 1. "<<(char)35<<endl //ascii vrijednosti pojedinog znaka
			<<"\t 2. "<<(char)42<<endl
			<<"\t 3. "<<(char)15<<endl
			<<"\t 4. "<<(char)254<<endl
			<<"\t 5. "<<(char)2<<endl
			<<"\t 6. "<<(char)3<<endl
			<<"\t 7. "<<(char)4<<endl
			<<"\t 8. "<<(char)5<<endl
			<<"\t 9. "<<(char)6<<endl
			<<"\t10. "<<(char)43<<endl
			<<"\t11. "<<(char)64<<endl
			<<"\t12. "<<(char)176<<endl
			<<"\t13. "<<(char)177<<endl
			<<"\t14. "<<(char)178<<endl
			<<"\t15. "<<(char)219<<endl
			<<"\t16. "<<(char)248<<endl;
			
		cout<<"Odaberi uzorak: "; cin>>z;
		switch(z){
			case 1: uzorak=(char)35; break;
			case 2: uzorak=(char)42; break;
			case 3: uzorak=(char)15; break;
			case 4: uzorak=(char)254; break;
			case 5: uzorak=(char)2; break;
			case 6: uzorak=(char)3; break;
			case 7: uzorak=(char)4; break;
			case 8: uzorak=(char)5; break;
			case 9: uzorak=(char)6; break;
			case 10: uzorak=(char)43; break;
			case 11: uzorak=(char)64; break;
			case 12: uzorak=(char)176; break;
			case 13: uzorak=(char)177; break;
			case 14: uzorak=(char)178; break;
			case 15: uzorak=(char)219; break;
			case 16: uzorak=(char)248; break;
			default: cout<<"Pogresan unos"<<endl;
		}
		objekt(boja, uzorak); //ulazi se u funkciju objekt s izabranom bojom i uzorkom
		cout<<BIJELA<<"Zelite li jos? (1/0): "; cin>>jos;
	} while(jos);
}

void semafor1()
{
	cout<<LJUBICASTA<<"Zapocinjem simulaciju semafora";
	Sleep(500); cout<<". "; Sleep(500); cout<<". "; Sleep(500); cout<<". "; Sleep(500); cout<<". "; Sleep(500); //program èeka pola sekunde odnosno 500ms, ova naredba je iz windows.h biblioteke
	cout<<endl<<endl;
//CRVENO SVJETLO	
	boja=CRVENA; //boja znakova
	uzorak=char(35); //uzorak znakova (#) prema ascii vrijednosti
	objekt(boja, uzorak);
	cout<<LJUBICASTA<<"Odbrojavanje: "; //boja teksta se definira prije samog ispisa
	for(int i=7; i>0; i--){
		cout<<i<<", ";
		Sleep(1000); //program svaku sekundu ispisuje broj
	}
	cout<<"0"<<endl<<endl;
//ŽUTO SVJETLO
	boja=ZUTA; //boja znakova
	uzorak=char(35); //uzorak znakova (#) prema ascii vrijednosti
	objekt(boja, uzorak);
	cout<<LJUBICASTA<<"Odbrojavanje: "; //boja teksta se definira prije samog ispisa
	for(int i=3; i>0; i--){
		cout<<i<<", ";
		Sleep(1000); //program svaku sekundu ispisuje broj
	}
	cout<<"0"<<endl<<endl;
//ZELENO SVJETLO
	boja=ZELENA; //boja znakova
	uzorak=char(35); //uzorak znakova (#) prema ascii vrijednosti
	objekt(boja, uzorak);
	cout<<LJUBICASTA<<"Odbrojavanje: "; //boja teksta se definira prije samog ispisa
	for(int i=10; i>0; i--){
		cout<<i<<", ";
		Sleep(1000); //program svaku sekundu ispisuje broj
	}
	cout<<"0"<<endl<<endl;
}

void semafor2() //slièan kao i semafor1 samo bez žutog svjetla
{
	cout<<LJUBICASTA<<"Zapocinjem simulaciju semafora";
	Sleep(500); cout<<". "; Sleep(500); cout<<". "; Sleep(500); cout<<". "; Sleep(500); cout<<". "; Sleep(500); //program èeka pola sekunde odnosno 500ms, ova naredba je iz windows.h biblioteke
	cout<<endl<<endl;
// CRVENO svjetlo	
	boja=CRVENA;
	uzorak=char(35); // znak #
	objekt(boja, uzorak);
	cout<<LJUBICASTA<<"Odbrojavanje: ";
	for(int i=5; i>0; i--){
		cout<<i<<", ";
		Sleep(1000);
	}
	cout<<"0"<<endl<<endl;
	
	boja=ZELENA;
	uzorak=char(35); // znak #
	objekt(boja, uzorak);
	cout<<LJUBICASTA<<"Odbrojavanje: ";
	for(int i=7; i>0; i--){
		cout<<i<<", ";
		Sleep(1000);
	}
	cout<<"0"<<endl<<endl;
}

void semafor3() //sastoji se od objekta i objekta2 
{
// u ovome potprogramu, kao i u ostalim se pozivaju objekt i objekt2 u raznim bojam, te se
// postavlja odreðeno trajanje zastoja programa
	cout<<endl<<endl;
	boja=ZUTA;
	objekt2(boja);
	Sleep(1500);
	cout<<endl<<endl;
	objekt2(boja);
	Sleep(1500);
	for(int i=0; i<3; i++){ //objekt se 3 puta izvodi
		boja=ZUTA2;
		uzorak=char(35);
		objekt(boja, uzorak);
		Sleep(720);
	}
	boja=ZELENA;
	uzorak=char(35);
	objekt(boja, uzorak);
	Sleep(4720);
	boja=CRVENA;
	uzorak=char(35);
	objekt(boja, uzorak);
	Sleep(2720);
}

int main(){
	system("color 03"); //dolazi iz biblioteke conio.h, potrebno navesti na poèetku kako bi se kasnije definirane boje normalno izvodile
	int x;
	do{
		cout<<endl<<TIRKIZNA2<<"---- IZBORNIK -----"<<endl
			<<"0. Odaberi boje i uzorak"<<endl
			<<"1. Semafor za automobile"<<endl
			<<"2. Semafor za pjesake"<<endl
			<<"3. Semafor za trke"<<endl
			<<"9. Izlaz"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
		
		switch(x){
			case 0: boje();
			break;
			case 1: semafor1();
			break;
			case 2: semafor2();
			break;
			case 3: semafor3();
			break;
			case 9: break;
			default: cout<<"Pogresan unos!"<<endl;
		}
	
	}while(x!=9);
	cout<<"Izlaz iz programa"<<endl<<endl;
	
	system("PAUSE");
	return 0;
}
