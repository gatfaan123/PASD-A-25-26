//Quick Sort
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

// Fungsi Quick Sort
void Q_Sort(int[], int, int);

int main()
{
    int NumList[9] = {65,2,44,26,19,22,5,3,12};
    cout << "Data SEBELUM diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int d = 0; d < 9; d++)
    {
        cout << setw(3) << NumList[d];
    }
    cout << endl << endl;

    Q_Sort(NumList, 0, 8);

    cout << "Data SETELAH diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int iii = 0; iii < 9; iii++)
    {
        cout << setw(3) << NumList[iii];
    }
    cin.get();
    return 0;
}

void Q_Sort(int Angka[], int Kiri, int Kanan) {
    int pivot, KiriHold, KananHold;
    KiriHold = Kiri;
    KananHold = Kanan;
    pivot = Angka[Kiri];

    while (Kiri < Kanan)
    {
        while ((Angka[Kanan] >= pivot) && (Kiri < Kanan))
            Kanan--;
        if (Kiri != Kanan)
        {
            Angka[Kiri] = Angka[Kanan];
            Kiri++;
        }
        while ((Angka[Kiri] <= pivot) && (Kiri < Kanan))
            Kiri++;
        if (Kiri != Kanan)
        {
            Angka[Kanan] = Angka[Kiri];
            Kanan--;
        }
    }
    Angka[Kiri] = pivot;
    pivot = Kiri;
    Kiri = KiriHold;
    Kanan = KananHold;

    if (Kiri < pivot)
        Q_Sort(Angka, Kiri, pivot - 1);
    if (Kanan > pivot)
        Q_Sort(Angka, pivot + 1, Kanan);
}