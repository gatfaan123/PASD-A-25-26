#include <iostream>
using namespace std;

class Mahasiswa{
		public:
		char NPM[9];
		char nama[30];
		float ipk;
		};
int main() {
		Mahasiswa mhs; 
		cout << "Nomor pokok Mahasiswa = "; cin>> mhs.NPM;
		cout << "Nama Mahasiswa = "; cin>> mhs.nama;
		cout << "Indeks Prestasi Komulatif = "; cin>> mhs.ipk;
		cout << endl;
		cout << " Data Anda " << endl;
		cout << "Nomor Pokok Mahasiswa = " << mhs.NPM << endl;
		cout << "Nama Mahasiswa = " << mhs.nama << endl;
		cout << "Indeks Prestasi Komulatif = " << mhs.ipk <<endl;
		cin.get(); }