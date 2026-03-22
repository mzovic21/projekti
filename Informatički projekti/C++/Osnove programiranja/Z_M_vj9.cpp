#include <iostream>
#include <conio.h>
using namespace std;

class cstavka{
	public:
		int sifra;
		char naziv[30];
		int cijena;
		char proizvodac[50];
	private:
		cstavka *pokazivac;
	public:
		void unos(){
			cstavka *novi, *zadnji;
			zadnji=this;
			while(zadnji->pokazivac) zadnji=zadnji->pokazivac;
			novi=new cstavka;
			zadnji->pokazivac=novi;
			cout<<"Sifra: "; cin>>novi->sifra;
			cout<<"Naziv: "; cin.ignore(); cin.getline(novi->naziv,30);
			cout<<"Cijena: "; cin>>novi->cijena;
			cout<<"Proizvodac: "; cin.ignore(); cin.getline(novi->proizvodac,50);
		}
		
		void ispis(){
			cstavka *trenutni=this->pokazivac;
			while(trenutni){
				cout<<"Sifra: "<<trenutni->sifra<<endl
					<<"Naziv: "<<trenutni->naziv<<endl
					<<"Cijena: "<<trenutni->cijena<<endl
					<<"Proizvodac: "<<trenutni->proizvodac<<endl
					<<"Pokazivac: "<<trenutni->pokazivac<<endl;
				trenutni=trenutni->pokazivac;
			}
		}
		
		void dealokacija(){
			cstavka *prethodni, *trenutni;
			prethodni=this;
			trenutni=this->pokazivac;
			while(trenutni){
				if(prethodni!=this) delete prethodni;
				prethodni=trenutni;
				trenutni=trenutni->pokazivac;
			}
			delete prethodni;
			this->pokazivac=NULL;
		}
		
		cstavka(){
			pokazivac=NULL;
			cout<<"Alociram element liste: "<<endl;
		}
		~cstavka(){
			cout<<"Dealociram: "<<sifra<<endl;
		}
};

int main(){
	system("color 03");
	
	int x, broj;
	bool jos=true;
	cstavka *lista, *polje=NULL;
	lista=new cstavka;
	
	do{
		cout<<endl<<"--------¡¡¡¡---------"<<endl
			<<"1. Alokacija glave, unos elementa"<<endl
			<<"2. Ispis elemenata, dealokacija"<<endl
			<<"3. Alokacija polja / unos podataka"<<endl
			<<"4. Ispis liste"<<endl
			<<"9. Izlaz"<<endl
			<<"Opcija: "; cin>>x;
		cout<<endl;
		
		switch(x){
			case 1: do{
					if(!lista) lista=new cstavka;  
					lista->unos();
					cout<<"Jos? (1/0)"; cin>>jos;
					} while(jos);
			break;
			case 2: lista->ispis();
					cout<<"Dealokacija? (1/0) "; cin>>jos;
					if(jos) lista->dealokacija();
			break;
			case 3: if(!polje) {
						polje=new cstavka[10];
						cout<<"Alociram..."<<endl;
					}
					do{
					cout<<"Unesi broj (0-9): "; cin>>broj;
					if(broj<0 || broj>9) cout<<"Ta lista ne postoji!"<<endl;
					}while(broj<0 || broj>9);
					polje[broj].unos();

			break;
			case 4: 
					do{
					cout<<"Unesi broj (0-9): "; cin>>broj;
					if(broj<0 || broj>9) cout<<"Ta lista ne postoji!"<<endl;
					}while(broj<0 || broj>9);
					polje[broj].ispis();
					
					cout<<"Dealokacija? (1/0) "; cin>>jos;
					if(jos) polje[broj].dealokacija();
			break;
			case 9: break;
			default: cout<<"Pogresan unos!"<<endl;
		}
	
	} while(x!=9);
	
	delete lista;
	lista=NULL;
	delete[] polje;
	polje=NULL;
	
	system("PAUSE");
	return 0;
}
