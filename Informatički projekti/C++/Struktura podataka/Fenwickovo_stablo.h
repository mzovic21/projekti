#include<iostream>
#include<conio.h>

using namespace std;

template <typename elem>

class stablo{
	public:

int Suma(int FStablo[], int indeks)
{
	int zbroj=0;

	// indeks u polju krece od 0, u stablu od 1
	indeks=indeks+1;

	// dok postoji roditelj (do korijena stabla)
	while(indeks>0){
		zbroj+=FStablo[indeks];
		
		// postavljanje indeksa na roditelja djeteta
		indeks -= indeks&(-indeks);
	}
	return zbroj;
}

void Azuriraj(int FStablo[], int duljina_polja, int indeks, int promjena)
{
	indeks=indeks+1;

	while(indeks<=duljina_polja){
		FStablo[indeks] += promjena;

		// promjena indeksa na sljedeći element u kojem se javlja
		indeks += indeks&(-indeks);
	}
}

int *Kreiraj_Stablo(int polje[], int duljina_polja)
{
	// kreiranje stabla i postavljanje svih elemenata u stablu na 0
	int *FStablo=new int[duljina_polja+1];
	for(int i=1; i<=duljina_polja; i++) FStablo[i]=0;

	// punjenje stabla
	for(int i=0; i<duljina_polja; i++) Azuriraj(FStablo, duljina_polja, i, polje[i]);

	// ispis stabla
	cout<<"Zapis: ";
	for(int i=1; i<=duljina_polja; i++) cout<<FStablo[i]<< " ";
	cout<<endl;

	return FStablo;
}

};
