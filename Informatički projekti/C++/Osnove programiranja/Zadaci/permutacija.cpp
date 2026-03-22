#include <iostream>
#include<cstring>
using namespace std;

void zamjena (char *x, char *y){
	if(x!=y){
	char t;
	t=*x;
	*x=*y;
	*y=t;
}	
}

void permutacija (char *a, int l, int r){ //l=poèetak stringa, r=kraj stringa (dužina stringa-1)
	int i;
	if(l==r) cout<<a<<endl;
	
	else{
		for(i=l; i<=r; i++){
			zamjena((a+l),(a+i));
			permutacija(a,l+1,r);
			zamjena((a+l),(a+i)); 
		}
	}	
}

int main(){
	
	char rijec[10];
	cout<<"Unesi rijec: ";
	cin>>rijec;
	
	int duljina=strlen(rijec);
	
	char niz[duljina];
	strcpy(niz, rijec);
	int n=strlen(niz);
	
	permutacija(niz,0,n-1);
	
	return 0;
} 
