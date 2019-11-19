/**********************************
  *        Final Project 		  *
  *			Kelompok 10			  *
  *   Algoritma dan Pemrograman   *
  *           S1IF-01             *
  *            2017               *
  *********************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "fungsi.h"
#include "panggil.h"

using namespace std;

int main()
{
	string menu_caption[] = {
		"Input Data Barang", "Cari  Data Barang", "Edit  Data Barang", "Hapus Data Barang", "Tampilkan Data", "Info Program", "Keluar"
	};
	while(true)
	{
		system("cls");
		cout << "\n ------ M E N U ------\n\n";
		int i = 1;
		for(auto m:menu_caption)
		{
			cout << " [" << i << "] " << m << "\n";
			++i;
		}

		cout << "\n    Pilih: ";
		string pilih;
		getline(cin, pilih);

		system("cls");

		switch(pilih[0])
		{
			case '1': // Untuk memasukan data barang
			{
				input();
				break;
			}
			case '2': // Untuk mencari data barang
			{
				cari();
				break;
			}
			case '3': // untuk edit data barang
			{
				edit();
				break;
			}
			case '4': // untuk hapus data barang
			{
				hapus();
				break;
			}
			case '5': // Untuk Menampilkan Seluruh Data
			{
				system("cls");
				hasil();
				cout << " "; system("pause");
				break;
			}
			case '6': // Menampilkan info program
			{
				info();
				break;
			}
			case '7': // Perintah untuk keluar dari program
			{
				keluar();
				break;
			}

			default: // Jika yang dimasukan selain yang ada di menu
			cout << "\n Silahkan pilih menu dengan benar\n\n ";
			system("pause");
		}
	}
	
	return 0;
}