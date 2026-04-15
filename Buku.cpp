#include <iostream>
#include <string>
using namespace std;

int main() {
//Deklarasi STRUKTUR
struct DATABUKU { 
	string nama;
	string Pengarang;
	string nTahun;
	float Harga; };
//pendefinisiam STRUKTUR
DATABUKU Data_DB;
//pengaksesan anggota struktur
Data_DB.nama 		= "Selamat Tinggal" ;
Data_DB.Pengarang 	= "Tere Liye";
Data_DB.nTahun 		= "2005";
Data_DB.Harga 		= 80000;
cout<<endl;
cout<<endl;
cout<< "Judul Buku 		= " << Data_DB.nama << endl;
cout<< "Nama Pengarang  = " << Data_DB.Pengarang << endl;
cout<< "Tahun Terbit 	= " << Data_DB.nTahun << endl;
cout<< "Harga 			= " << Data_DB.Harga << endl;
cin.get(); }