#include <iostream>
using namespace std;

struct Node {
			int NilaiUTS;
			int NilaiUAS;
			int N1, N2; };
Node *P;

int main() {
	P = new Node;
	P -> N1 = 50;

cout<<endl;
cout<<"Isi Variabel P = "<< P -> N1 << endl;
cout<<endl;	
cin.get();}