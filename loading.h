/**********************************
  *        Final Project 		  *
  *			Kelompok 10			  *
  *   Algoritma dan Pemrograman   *
  *           S1IF-01             *
  *            2017               *
  *********************************/

/*
 * file loading.h
 * untuk tampilan loading
 * pada program
 *
*/

#include <iostream>
#include <windows.h>

using namespace std;

void bukadata()
{
	system("cls");
	char a = 177, b = 219;
	cout << "\n\n\n\n\n\t\t Membuka Data Barang...";
	cout << "\n\n\n";
	cout << "\t\t ";
	for (int i = 0; i <= 35; i++)
			cout << a;
			Sleep(10);
			cout << "\r";
			cout << "\t\t ";
	for (int i = 0; i <= 35; i++)
			{
			cout << b;
			Sleep(28);
			}
}

void proses()
{
	char a = 177, b = 219;
	cout << "\n   ";
	for (int i = 0; i <= 28; i++)
	cout << a;
	Sleep(10);
	cout << "\r";
	cout << "   ";
	for (int i = 0; i <= 28; i++)
		{
			cout << b;
			Sleep(28);
		}
}