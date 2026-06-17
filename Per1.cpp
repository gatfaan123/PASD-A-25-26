#include <iostream>
#include <string>
using namespace std;

int main() {
//Deklarasi STRUKTUR
struct MATAKULIAH { 
	string nama;
	int sks;
	char nHuruf;
	float nAngka; };
//pendefinisiam STRUKTUR
MATAKULIAH Data_MK;
//pengaksesan anggota struktur
Data_MK.nama = "Algoritma dan Pemograman 2" ;
Data_MK.sks = 3;
Data_MK.nHuruf = 'A';
Data_MK.nAngka = 4.00;
cout<<endl;
cout<<endl;
cout<< "Maka Kuliah = " << Data_MK.nama << endl;
cout<< "Jumlah sks  = " << Data_MK.sks << endl;
cout<< "Nilai 		= " << Data_MK.nHuruf << endl;
cout<< "Indeks 		= " << Data_MK.nAngka << endl;
cin.get(); }