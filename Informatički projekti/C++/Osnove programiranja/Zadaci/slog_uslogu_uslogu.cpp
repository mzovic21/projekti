// Unos ime i prezime, a zatim je li osoba nastavnik ili student, kod nastavnika ide unos
// titule i godine staza, a kod studenta prosjek i ects bodovi, izlaz ispis po statusu
#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");
	
	struct slog_student{
		float prosjek;
		short ects;
	};
	
	struct slog_nastavnik{
		char titula[20];
		short godine;
	};
	
	union slog_izbor{
		slog_student student;
		slog_nastavnik nastavnik;
	};
	
	struct slog_osoba{
		char imeprez[40];
		slog_izbor izbor;
		bool tko;
	};
	slog_osoba osoba[50];
	
	int n;

	do{
		cout<<"Unesi broj osoba: ";
		cin>>n;
	} while(n<1 && n!=0 && n>50);

	for(int i=0; i<n; i++){
		cout<<"Unesi ime i prezime osobe: ";
		cin.ignore();
		cin.getline(osoba[i].imeprez, 40);
		cout<<"Ako je osoba student upisi 1, ako je nastavnik upisi 0: ";
		cin>>osoba[i].tko;
		
		if(osoba[i].tko){
			cout<<"Unesi prosjek: ";
			cin>>osoba[i].izbor.student.prosjek;
			cout<<"Unesi ECTS bodove: ";
			cin>>osoba[i].izbor.student.ects;
		}
		if(!osoba[i].tko){
			cout<<"Unesi titulu: ";
			cin.ignore();
			cin.getline(osoba[i].izbor.nastavnik.titula, 20);
			cout<<"Unesi godine staza: ";
			cin>>osoba[i].izbor.nastavnik.godine;
		}
	}
	
	cout<<endl<<"-------------STUDENTI----------------"<<endl;
	for(int i=0; i<n; i++){
		if(osoba[i].tko){
			cout<<osoba[i].imeprez<<" --> PROSJEK: "<<osoba[i].izbor.student.prosjek
				<<" --> ECTS: "<<osoba[i].izbor.student.ects<<endl;
		}
	}
	
	cout<<endl<<"-------------NASTAVNICI----------------"<<endl;
	for(int i=0; i<n; i++){
		if(!osoba[i].tko){
			cout<<osoba[i].imeprez<<" --> TITULA: "<<osoba[i].izbor.nastavnik.titula
				<<" --> GODINE STAZA: "<<osoba[i].izbor.nastavnik.godine<<endl;
		}
	}
	

	cout<<endl<<endl;
	system("pause");
	return 0;
}

