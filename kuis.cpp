#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

const int HASHSIZE = 100; // Contoh batas slot memori
struct HashData {
    char kode[50];
    char nama[100];
};
HashData* hashTable[HASHSIZE]; 
// ------------------------------------------------------------------------

// FUNGSI PENDUKUNG (Menghitung jumlah huruf)
int characterAmount(char array[]){
    int jumlah=0;
    for(int i=0; array[i]!='\0'; i++)
        jumlah++;
    return jumlah;
}

// FUNGSI PENDUKUNG (Mengecek apakah loker kosong)
bool isIndexEmpty(int rec){
    if(hashTable[rec] == NULL)
        return true;
    else
        return false;
}

// =========================================================================
// 1. INTI RUMUS HASHING-NYA! (FUNGSI HASH)
// =========================================================================
int hashFunction(HashData *array){
    int value = 0, rec, n;
    
    n = characterAmount(array->kode); 
    
    // TAHAP 1: Menjumlahkan kode ASCII dari setiap huruf Kode MK
    for(int i=0; i<n; i++)
        value += array->kode[i];
        
    // TAHAP 2: Di-Modulo (sisa bagi) dengan total loker (HASHSIZE)
    rec = value % HASHSIZE; 
    
    return rec; // Nilai 'rec' inilah nomor alamat lokernya!
}


// =========================================================================
// 2. IMPLEMENTASI HASHING SAAT MENYIMPAN DATA (INSERT)
// =========================================================================
void insert(HashData *array){
    int rec;
    
    // Program memanggil rumus Hashing untuk minta nomor loker
    rec = hashFunction(array); 
    
    // PENERAPAN UTAMA: Data langsung dimasukkan ke loker nomor 'rec'
    // TANPA TABRAKAN HANDLING (Langsung tiban kalau ada isi sebelumnya)
    hashTable[rec] = array; 
    
    cout << "Input successfully!" << endl;
    cout << "Data disimpan pada record indeks " << rec << endl;
}


// Fungsi tambahan untuk mencocokkan huruf saat mencari
int searchingProcess(HashData *cari, int rec){
    int m, n, j = 0;
    bool equal = true;
    if(isIndexEmpty(rec) == false){
        n = characterAmount(cari->kode);
        m = characterAmount(hashTable[rec]->kode);
        if(n == m){
            while((equal == true) && (cari->kode[j] != '\0')){
                if(tolower(cari->kode[j]) != tolower(hashTable[rec]->kode[j]))
                    equal = false;
                j++;
            }
            if(equal == true)
                return rec;
            else
                return -1;
        }
        else
            return -1;
    }
    else {
        return -1;
    }
}


// =========================================================================
// 3. IMPLEMENTASI HASHING SAAT MENCARI DATA (SEARCHING)
// =========================================================================
void searching(HashData *cari){
    int rec;
    
    // PENERAPAN: Hitung ulang Kode MK untuk tahu lokernya
    rec = hashFunction(cari); 
    
    rec = searchingProcess(cari, rec);
    if(rec >= 0){
        cout << "Data ditemukan pada record indeks " << rec << endl;
        cout << "Isi data : " << endl;
        cout << "=> KodeMK      : " << hashTable[rec]->kode << endl;
        cout << "=> Matakuliah  : " << hashTable[rec]->nama << endl;
    }
    else {
        cout << "Maaf! Data tidak ditemukan." << endl;
    }
}


// =========================================================================
// 4. IMPLEMENTASI HASHING SAAT MENGHAPUS DATA (DELETING)
// =========================================================================
void deleting(HashData *hapus){
    int rec;
    
    // PENERAPAN: Hitung loker target
    rec = hashFunction(hapus); 
    
    rec = searchingProcess(hapus, rec);
    if(rec >= 0){
        cout << "Data :" << endl;
        cout << "  => KodeMK      : " << hashTable[rec]->kode << endl;
        cout << "  => MataKuliah  : " << hashTable[rec]->nama << endl;
        cout << "terhapus!" << endl;
        
        // Hapus alokasi memori objek lawas agar tidak memory leak
        delete hashTable[rec];
        // Langsung buang isi lokernya menjadi KOSONG (NULL)
        hashTable[rec] = NULL; 
    }
    else {
        cout << "Maaf! Data tidak ditemukan!" << endl;
    }
}


// Menampilkan seluruh isi tabel/loker yang tidak kosong
void DisplayTable(){
    cout << "\n";
    cout << "|===================================================|" << endl;
    cout << "| Indeks |    KODEMK    |        Nama Mata Kuliah    |" << endl;
    cout << "|===================================================|" << endl;
    for(int i = 0; i < HASHSIZE; i++)
    {
        if(isIndexEmpty(i) == false)
            cout << setw(6) << i << "      " << hashTable[i]->kode << "\t     " << hashTable[i]->nama << endl;
    }
}

// Mengosongkan seluruh memori
void Clear(){
    for(int i = 0; i < HASHSIZE; i++){
        if (hashTable[i] != NULL){
            delete hashTable[i];
            hashTable[i] = NULL;
        }
    }
}


// PROGRAM UTAMA / MENU
int main(){
    char ulang = 'Y', menu;
    do{
        system("cls"); // Pakai "clear" jika di Linux/Mac
        
        puts("        PROSES HASH TABLE        ");
        puts("");
        puts("1. Input");
        puts("2. Delete");
        puts("3. Find");
        puts("4. Display");
        puts("5. Clear");
        puts("x. Keluar");
        puts("");
        cout << "Menu pilihan Anda : "; cin >> menu;
        cin.ignore(); // Membersihkan buffer setelah input menu
        
        switch(menu){
            case '1' : {
                HashData *array = new HashData;
                puts("");
                cout << "KodeMK        : "; cin >> array->kode;
                cin.ignore(); // Bersihkan sisa newline agar getline tidak terlewati
                cout << "Matakuliah    : "; cin.getline(array->nama, 100);
                cout << endl;
                insert(array); 
                cout << endl;
                system("pause");
                break;
            }
            case '2' : {
                HashData hapus;
                cout << "Hapus Matakuliah(KodeMK) : "; cin >> hapus.kode;
                deleting(&hapus); 
                cout << endl;
                system("pause"); 
                break;
            }
            case '3' : {
                HashData cari;
                cout << "Cari MataKuliah (KodeMK) : "; cin >> cari.kode;
                searching(&cari); 
                cout << endl;
                system("pause"); 
                break;
            }
            case '4' :
                DisplayTable(); 
                cout << endl;
                system("pause");
                break;
            case '5' :
                Clear();
                puts("Tabel hash telah dikosongkan."); 
                cout << endl;
                system("pause"); 
                break;
            case 'x' :
            case 'X' :
                ulang = 'T'; break;
            default :
                puts("Pilihan diluar Menu yang tersedia!"); 
                cout << endl;
                system("pause");
                break;
        }
    }
    while(toupper(ulang) == 'Y');
    
    // Bersihkan memori sebelum program benar-benar ditutup
    Clear();
    return 0;
}