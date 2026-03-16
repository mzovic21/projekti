#include "Fenwickovo_stablo.h"

// using namespace std;
/*
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
}*/

int main(){
	system("color 03");
	
	stablo<int> F;
	
	int polje[]={12, 15, 23, 35, 54, 10, 6, 20, 38, 1, 9};
	// integer zauzima 4 bita, pa je sizeof 44, zato se mora dijeliti sa 4 
	int duljina_polja=sizeof(polje)/sizeof(polje[0]);
	
	// kreiranje stabla
	int *FStablo=F.Kreiraj_Stablo(polje, duljina_polja);
	int interval;
	
	do{
		cout<<"Unesi interval 0-"; cin>>interval;
		cout<<"Suma iznosi "<<F.Suma(FStablo, interval)<<endl;
	} while(interval>=0);
	
	int indeks, broj;
	cout<<"Unesi indeks elementa: "; cin>>indeks;
	cout<<"Unesi novu vrijednost elementa: "; cin>>broj;
	
	// racun koliko iznosi promjena te upis novog broja u polje
	int promjena=broj-polje[indeks];
	polje[indeks]=broj;
	
	F.Azuriraj(FStablo, duljina_polja, indeks, promjena);
	
	cout<<endl<<"Polje: ";
	for(int i=0; i<duljina_polja; i++) cout<<polje[i]<<" ";
	cout<<endl;

	do{
		cout<<"Unesi interval 0-"; cin>>interval;
		cout<<"Suma iznosi "<<F.Suma(FStablo, interval)<<endl;
	} while(interval>=0);
	
	cout<<endl<<endl;
	return 0;
}
