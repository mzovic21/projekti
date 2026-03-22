// Korisnik unosi recenicu, izlaz broj svakog samoglasnika u recenici
#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;

int main ()
{
	system("color 03");

	char recenica[101];

	cout<<"Unesi recenicu: "<<endl;
	cin.getline(recenica, 101);

	int duljina=strlen(recenica);
	int brojacA=0, brojacE=0, brojacI=0, brojacO=0, brojacU=0, ukupno=0;
	
	for(int i=0; i<duljina; i++){
		if(recenica[i]>='A' && recenica[i]<='Z'){
			recenica[i]+=32;
		}
	}
	
	for(int i=0; i<duljina; i++){
		switch(recenica[i]){
			case 'a':
				brojacA++;
				break;
			case 'e':
				brojacE++;
				break;
			case 'i':
				brojacI++;
				break;
			case 'o':
				brojacO++;
				break;
			case 'u':
				brojacU++;
				break;
		}
	}
	
	ukupno=brojacA+brojacE+brojacI+brojacO+brojacU;
	
	cout<<"Ukupno je "<<ukupno<<" samoglasnika u recenici!"<<endl
		<<"slova a ima: "<<brojacA<<endl
		<<"slova e ima: "<<brojacE<<endl
		<<"slova i ima: "<<brojacI<<endl
		<<"slova o ima: "<<brojacO<<endl
		<<"slova u ima: "<<brojacU;

	cout<<endl<<endl;
	system("pause");
	return 0;
}

