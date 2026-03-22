#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	system("color 03");

	float x,y;
	char znak;

	start:cout<<"-------------------------"<<endl;
	cin>>x>>znak>>y;
	
	switch(znak){
		case '+':
			cout<<x+y;
			break;
		case '-':
			cout<<x-y;
			break;
		case '*':
			cout<<x*y;
			break;
		case '/':
			cout<<x/y;
			break;
		default:
			cout<<"Kriva operacija!";
	}

	cout<<endl<<"-------------------------";
	cout<<endl<<endl;
	system("pause");
	goto start;
	return 0;
}

