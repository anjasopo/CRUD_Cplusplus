/**********************************
  *        Final Project 		  *
  *			Kelompok 10			  *
  *   Algoritma dan Pemrograman   *
  *           S1IF-01             *
  *            2017               *
  *********************************/

/*
 * file fungsi.h
 * semua perintah didalam menu
 *
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <windows.h>
#include "loading.h"

using namespace std;

void bukadata();
void proses();

int cari(string kode);

struct Barang
{
	std::string merk;
	std::string nama;
	std::string kode;
	std::string harga;
};

vector<Barang> brg;

void input() // Untuk menu input atau memasukan data barang
{
	system ("cls");
	cout << "\n            =====================           \n";
	cout << " -----------| Input Data Barang |-----------\n";
	cout << " |          =====================          |\n";
	cout << " | Read : Kosongkan merk barang jika ingin |\n";
	cout << " |        membatalkan penginputan barang   |\n";
	cout << " -------------------------------------------\n";		
	while(true) // Perulangan untuk input data
	{
		cout << "\n --------------- Data Barang ---------------\n";
		cout << " Merk Barang : ";
		string mb;
		getline(cin, mb);
		if(mb == "")
		break;

		cout << " Nama Barang : ";
		string nb;
		getline(cin, nb);

		cout << " Kode Barang : ";
		string kb;
		getline(cin, kb);

		cout << " Harga Barang: ";
		string hb;
		getline(cin, hb);

		cout << " ---------------------------------";

		string jwb;
		cout << "\n\n Tambahkan barang lagi [Ya/Tidak] ? ";
		getline(cin, jwb);

		Barang data_temp = {mb, nb, kb, hb};
		brg.push_back(data_temp);   	

		if(jwb[0] == 't' || jwb[0] == 'T')
		{
			break;
		}
	}
}

void hasil() // Untuk menu tampilkan semua data barang
{
	bukadata();
	// Menampilkan Data Barang
	system("cls");
	cout << "\n			              ===============\n";
	cout << " -------------------------------------| Data Barang |------------------------------------\n";
	cout << " |			              ===============                                   |\n";
	cout << " |                                                                                      |\n";
	cout << " |--------------------------------------------------------------------------------------|\n";
	cout << " | Kode Barang	|      Merk      |\t\tNama Barang\t\t|     Harga\t|\n";
	cout << " |--------------------------------------------------------------------------------------|\n";
	for(auto m:brg)
	{
		cout << " | " << setw(7) << m.kode << "\t|"
			 << "  " << setw(9) << m.merk << "\t |"
			 << "  " << setw(26) << m.nama << "\t\t|"
			 << "  " << setw(10) << m.harga <<" \t|" << endl;
	}
	cout << " ----------------------------------------------------------------------------------------\n";
	cout << "\n Total semua barang: " << brg.size() << '\n' << '\n';
}

void cari() // Untuk menu cari data barang
{
	cout << "\n\t\t   =============\n"
	" ------------------| Cari Data |-----------------\n"
	" |		   =============	        |\n"
	" |  Read: Masukan kode barang yang akan dicari\t|\n"
	" ------------------------------------------------\n";
	while (true)
		{
			cout << "\n    Masukan Kode Barang: ";
			string c;
			getline(cin, c);
			
			int f = cari(c);
			if(f != brg.size())
				{
					cout << "\n        --------------------\n";
					cout << "        | Barang Ditemukan |\n";
					cout << "        --------------------\n\n";
					cout << "  "; system("pause > nul | echo tekan apa saja untuk menampilkan semua data barang...");
					hasil();	
				}
			else
				{
					cout << "\n   ------------------------------\n";
					cout << "   |   Barang Tidak Ditemukan   |\n";
					cout << "   ------------------------------\n\n";
				}
			cout << " "; system("pause >nul |echo tekan apa saja untuk kembali ke menu. . .");
			break;
		}
}

void edit() // Untuk menu edit data barang
{
	cout << "\n\t\t      =============\n"
	" ---------------------| Edit Data |----------------------\n"
	" |		      =============			|\n"
	" | Read: 1. Masukan kode barang yang akan diedit\t|\n"
	" |\t 2. Jika data ditemukan silahkan isi semua data\t|\n"
	" |\t    barang yang akan diedit\t\t\t|\n"
	" |\t 3. Data Barang [baru] tidak boleh kosong\t|\n"
	" |\t 4. Jika lupa kode barang cek pada menu nomor 5\t|\n"
	" --------------------------------------------------------\n";
	while(true)
		{	
			cout << "\n   Masukan Kode Barang: ";
			string c;
			getline(cin, c);

			// Mencari Data Barang
			int f = cari(c);
			if(f != brg.size())
				{
					cout << "   -------------------------\n";
					cout << "   | Kode Barang Ditemukan |\n";
					cout << "   -------------------------\n";
					cout << "\n   Data Barang [Baru]\n";
					cout << "\tMerk Barang : ";
					string mb;
					getline(cin, mb);
					if(mb != "")
						{
							brg[f].merk = mb;
						}
						
					string nb;
					cout << "\tNama Barang : ";
					getline(cin, nb);
					if(nb != "")
						{
							brg[f].nama = nb;
						}
					
					string kb;
					cout << "\tKode Barang : ";
					getline(cin, kb);
					if(kb != "")
						{
							brg[f].kode = kb;
						}
						
					string hb;						
					cout << "\tHarga Barang: ";
					getline(cin, hb);
					if(hb != "")
						{
						brg[f].harga = hb;
						}
					cout << "\n\n   Menyimpan Data Barang...";
					proses();
					cout << "\n   Data Barang Berhasil diedit";
					cout << "\n\n  "; system("pause > nul | echo tekan apa saja untuk menampilkan semua data barang...");

					hasil();
				}
			else
				{
					cout << " -------------------------------\n";
					cout << " | Kode Barang Tidak Ditemukan |\n";
					cout << " -------------------------------\n\n";
				}
			break;
		}	
	cout << " "; system("pause > nul | echo tekan apa saja untuk kembali ke menu. . .");
}

void hapus() // Untuk menu hapus data barang
{
	cout << "\n\t\t  ==============\n";
	cout << " -----------------| Hapus Data |-----------------\n";
	cout << " |\t\t  ==============\t\t|\n";
	cout << " | Read: Masukan kode barang yang akan dihapus	|\n";
	cout << " ------------------------------------------------\n\n";
	while(true)
		{
			cout << "   Kode Barang: ";
			string c;
			getline(cin, c);
			// Pencarian Data
			int f = cari(c);
			if(f != brg.size())
			{ // Jika kode barang ditemukan
				cout << "   -------------------------\n";
				cout << "   | Kode Barang Ditemukan |\n";
				cout << "   -------------------------\n\n";
				cout << "   Hapus data ini[Ya/Tidak] ? ";
				while(true)
				{ // Jawaban Ya untuk menghapus
					string jwb;
					getline(cin, jwb);
					if(jwb[0] == 'Y' || jwb[0] == 'y')
					{
							auto first = begin(brg) + f;
							brg.erase(first, first + 1);
							cout << "\n\n   Menghapus Data Barang...";
							proses();
							cout << "\n   Data Barang Berhasil dihapus";
							cout << "\n\n   "; system("pause > nul | echo tekan apa saja untuk menampilkan semua data barang...");
							hasil();
					}
					else
					{
							cout << "\n\n   Menghapus Data Barang...";
							proses();
							cout << "\n   Data Barang Gagal dihapus\n\n";
					}
					break;
				}
			}
			else
			{
				cout << "   -------------------------------\n";
				cout << "   | Kode Barang Tidak Ditemukan |\n";
				cout << "   -------------------------------\n\n";
			}
			break;
		}
	cout << "   "; system("pause >nul |echo tekan apa saja untuk kembali ke menu. . .");
}

void info() // Untuk menu info menampilkan info program data barang
{
	system("cls");
	cout << "\n\n\n\t==================================================================\n";
	cout << "\t||\t\t\t   KELOMPOK 10\t\t\t\t||\n";
	cout << "\t==================================================================\n";
	cout << "\t||\t\tProgram Pendataan Barang Sederhana\t\t||\n";
	cout << "\t||\t\t\t Informatika 01 \t\t\t||\n";
	cout << "\t||\t\t\t\t\t\t\t\t||\n";
	cout << "\t||\tAnggota kelompok:\t\t\t\t\t||\n";
	cout << "\t||\t\t- Yohanes Eudes Anjas Susetya	(17.11.0922)\t||\n";
	cout << "\t||\t\t- Gilang Oktavian Aji\t\t(17.11.0964)\t||\n";
	cout << "\t||\t\t- Daniel Kristiawan\t\t(17.11.0980)\t||\n";
	cout << "\t||\t\t- Rizky Amanullah\t\t(17.11.0987)\t||\n";
	cout << "\t||\t\t\t\t\t\t\t\t||\n";
	cout << "\t||\t\t\t\t\t\t\t\t||\n";
	cout << "\t||\t\t\tUNIVERSITAS AMIKOM\t\t\t||\n";
	cout << "\t||\t\t\t    YOGYAKARTA\t\t\t\t||\n";
	cout << "\t||\t\t\t       2017\t\t\t\t||\n";
	cout << "\t==================================================================\n\n\n\n";
	system("pause");
}

void keluar() // Untuk menu keluar
{
	// Loading
	system("cls");
	char a = 177, b = 219;
	cout << "\n\n\n\n\n\n\n\t\t\t\t Menutup Program...";
	cout << "\n\n\n";
	cout << "\t\t\t\t ";
	for (int i = 0; i <= 20; i++)
	cout << a;
	Sleep(50);
	cout << "\r";
	cout << "\t\t\t\t ";
	for (int i = 0; i <= 20; i++)
	{
		cout << b;
		Sleep(100);
	}
	system("cls");
	exit(0);
}

int cari(string kode)
{
	for(int i = 0; i < brg.size(); ++i)
		if(brg[i].kode == kode)
			return i;
	
	return brg.size();
}