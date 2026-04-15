#include <iostream>
#include <string>
using namespace std;

typedef int angka;
typedef float pecahan;
typedef char huruf[30];
int main() {
	angka umur;
	pecahan pecah;
	huruf nama;
	huruf karakter;
	cout<<"Masukan Umur Anda: ";cin>>umur;
	cout<<"Umur Anda Andalah"<<umur<<endl;
	cout<<endl;
	cout<<"Masukan Bilang Pecahan: ";cin>>pecah;
	cout<<"Bilangan Pecahan"<<pecah<<endl;
	cout<<endl;
	cout<<"Masukan Nama : ";cin>>nama;
	cout<<"Nama Anda"<<nama<<endl;
	cout<<endl;
	cout <<"Masukan Satu Huruf: ";cin>>karakter;
	cout<<"Huruf Anda"<<karakter<<endl;
cin.get();	}