// MD5:GRzsVX+cRFhrFbTpvXNpkQ==// Verifikator 5.05// Program:Sortiranje// Poèetno vrijeme: 15:44 (internetsko) Završno vrijeme: 17:15 Preostalo: 80 +// Opis zadatka:opis// Autor:Mateo Zoviæ// Poèetno vrijeme:9.3.2022. 15:45:19// Završno vrijeme:9.3.2022. 15:55:15// Identifikatori:main,i,niz[10],bubble_sort,*polje,duljina,tmp,j// IP:fe80::d5f:8681:47e9:d45%8 ( 1589 )// #:#include <iostream>,// Uspješnih/neuspješnih prevoðenja:15/2#include <iostream>
using namespace std;

void bubble_sort(int *polje, int duljina){
	int tmp;
	
	for(int i=duljina-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(polje[j+1] < polje[j]){
		tmp=polje[j];
		polje[j]=polje[j+1];
		polje[j+1]=tmp;	
			}
			
		}
	}
	
}

int main(){

	int i;
	int niz[10]={9,8,7,10,6,4,3,2,5,1};
	
	for(i=0; i<10; i++)
		cout<<niz[i]<<" ";
	
	cout<<"\nSortiram..."<<endl;
	bubble_sort(niz, 10);
	
	for(i=0; i<10; i++)
		cout<<niz[i]<<" ";
		
	cin>>i;

	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}
