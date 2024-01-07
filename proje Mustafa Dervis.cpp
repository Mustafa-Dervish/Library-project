/****************************************************************************
**					           SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				          BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				            PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI………………: Proje
**				ÖĞRENCİ ADI……………………: MUSTAFA DERVİŞ
**				ÖĞRENCİ NUMARASI………: 
**				DERS GRUBU………………………: B
****************************************************************************/

#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>


using namespace std;

int main(int argc, char* argv[])
{
	// Birkaç değışken tanımladım
	int secim, i = 1;
	string Tc;
	string ADI;
	string SOYADI;
	int No;
	string TELEFON;
	string TARIH;
	string Gor;
	string say;
	string ISBN;
	string Kitap;
	string Yazar_adi;
	string Yazar_soyad;
	string Konu;
	string Tur;
	string Sayfasay;
	string TCNO;
	string Odunc_tarih;
	string Donus_tarih;
	string n, pass;

	//cevap adlı bir char tanımladım
	char cevap = 'e';
	do
	{

		cout << "   Kullanici adi.........: ";
		cin >> n;
		cout << "   Kullanici sifre.......: ";
		cin >> pass;
		// tarih değışken tanımladım
		time_t now = time(0);
		char* dt = ctime(&now);
		cout << "   Programing Baslama saati: " << dt << endl;


		// ekrana yazdırmak için bir loop tanımladım
	} while (n != "deneme" || pass != "0000");
	do
	{
		cout << "   Ne yapmak istiyorsunuz ?\n " << endl;
		cout << "   1) Okuyucu kaydi " << endl;
		cout << "   2) Okuyucu kaydi guncelleme  " << endl;
		cout << "   3) Okuyucu silme( Okuyucu silindiginde okuyucunun oduncleri geri donmelidir.) " << endl;
		cout << "   4) Okuyucu uzerindeki kitaplar listesi  " << endl;
		cout << "   5) Okuyucu kitap odunc alma  " << endl;
		cout << "   6) Okuyucu kitap geri dondurme  " << endl;
		cout << "   7) Kitap ekleme  " << endl;
		cout << "   8) Kitap silme  " << endl;
		cout << "   9) Kitap duzeltme  " << endl;
		cout << "   10) cikis " << endl;
		cin >> secim;
		// 10 seçersak programdan cıkılacak
		if (secim == 10)
			exit(1);
	} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);
	ofstream file;
	file.open("Odunc.txt");
	ofstream file1;
	file1.open("okuyucu.txt");
	ofstream file2;
	file2.open("Kitaplar.txt");
	if (secim == 1)
	{
		do
		{
			cout << "\n TC NO      :"; cin >> Tc;
			cout << "\n ADI      :"; cin >> ADI;
			cout << "\n SOYADI   :"; cin >> SOYADI;
			cout << "\n uye No     :"; cin >> No;
			cout << "\n TELEFON       :"; cin >> TELEFON;
			cout << "\n DOGUM TARIHI       :"; cin >> TARIH;
			cout << "\n Gorevi     :"; cin >> Gor;
			cout << "\n Alabilecegi kitap sayisi       :"; cin >> say;
			file1 << Tc << " " << ADI << ' ' << SOYADI << ' '
				<< No << ' ' << TELEFON << ' '
				<< TARIH << " " << Gor << " " << say << "\n";
			cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
		} while (!(cevap == 'h'));
		file1.close();
		cout << "dosyaya yazim tamamlandi. ";
	}
	if (secim == 2)
	{
		string TC;
		cout << "TC :"; cin >> TC;
		ifstream file1("okuyucu.txt");
		while (!file1.eof())
		{
			file1 >> Tc >> ADI >> SOYADI >> No >> TELEFON >> TARIH >> Gor >> say;
			if (TC == Tc)
			{
				cout << "\n 2-	Okuyucu kaydi guncelleme      :";
				cout << "\n ADI      :"; cin >> ADI;
				cout << "\n SOYADI   :"; cin >> SOYADI;
				cout << "\n uye No     :"; cin >> No;
				cout << "\n TELEFON       :"; cin >> TELEFON;
				cout << "\n DOĞUM TARİHİ       :"; cin >> TARIH;
				cout << "\n Gorevi     :"; cin >> Gor;
				cout << "\n Alabilecegi kitap sayisi       :"; cin >> say;
				cin >> cevap;
			}
		}
	}
	if (secim == 3)
	{
		string TC;
		cout << "TC :"; cin >> TC;
		ifstream file1;
		file1.open("okuyucu.txt");

		while (!file1.eof())
		{
			file1 >> Tc >> ADI >> SOYADI
				>> No >> TELEFON >> TARIH >> Gor >> say;

			if (TC == Tc)
			{
				ofstream file1;
				file1.open("okuyucu.txt");
				file1 << "" << "" << "" << "" << "" << ""
					<< "" << "" << "" << ""
					<< "" << "" << "" << "" << "" << "\n";
				ifstream file;
				file.open("Odunc.txt");
				while (!file.eof())
				{
					file >> ISBN >> TCNO >> Odunc_tarih >> Donus_tarih;
					if (TC == TCNO)
					{
						ofstream file;
						file.open("Odunc.txt");
						file << "" << "" << "" << "" << "" << ""
							<< "" << "" << "" << ""
							<< "" << "" << "" << "" << "" << "\n";
					}
				}
			}
		}
	}
	if (secim == 4)
	{
		string TC;
		string Isbn;
		cout << "TC :"; cin >> TC;
		ifstream file;
		file.open("Odunc.txt");
		ifstream file2;
		file2.open("Kitaplar.txt");
		while (!file.eof())
		{
			file >> Isbn >> TCNO >> Odunc_tarih
				>> Donus_tarih;
			if (TC == TCNO)
			{
				while (!file2.eof())
				{
					file2 >> ISBN >> Kitap >> Yazar_adi >> Yazar_soyad
						>> Konu >> Tur >> Sayfasay;
					if (ISBN == Isbn)
					{
						cout << "\n Kitap İsmi     :" << Kitap;
						cout << "\n Yazar adi  :" << Yazar_adi;
						cout << "\n Yazar soyadi    :" << Yazar_soyad;
						cout << "\n Konu   :" << Konu;
						cout << "\n Tur      :" << Tur;
						cout << "\n Sayfasayisi    :" << Sayfasay;
					}
				}
			}
			file2.close();
			file.close();
		}
	}
	if (secim == 5)
	{
		ofstream file;
		file.open("Odunc.txt");
		do
		{
			cout << "\n ISBN     :"; cin >> ISBN;
			cout << "\n TCNO     :"; cin >> TCNO;
			cout << "\n Odunc tarihi  :"; cin >> Odunc_tarih;
			cout << "\n Donus tarihi   :"; cin >> Donus_tarih;

			file << ISBN << " " << TCNO << ' ' << Odunc_tarih << ' '
				<< Donus_tarih << "\n";
			cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
		} while (!(cevap == 'h'));
		file.close();
		cout << "dosyaya yazim tamamlandi. ";
	}
	if (secim == 6)
	{
		string Isbn;
		cout << "ISBN :"; cin >> Isbn;
		ifstream file;
		file.open("Odunc.txt");
		while (!file.eof())
		{
			file >> ISBN >> TCNO >> Odunc_tarih >> Donus_tarih;
			if (Isbn == ISBN)
			{
				ofstream file;
				file.open("Odunc.txt");
				file << "" << "" << "" << "" << "" << ""
					<< "" << "" << "" << ""
					<< "" << "" << "" << "" << "" << "\n";
			}
		}
	}
	if (secim == 7)
	{
		ofstream file2;
		file2.open("Kitaplar.txt");
		do
		{
			cout << "\n ISBN     :"; cin >> ISBN;
			cout << "\n Kitap Ismi     :"; cin >> Kitap;
			cout << "\n Yazar adi  :"; cin >> Yazar_adi;
			cout << "\n Yazar soyadi    :"; cin >> Yazar_soyad;
			cout << "\n Konu   :"; cin >> Konu;
			cout << "\n Tur      :"; cin >> Tur;
			cout << "\n Sayfasayisi    :"; cin >> Sayfasay;

			file2 << ISBN << " " << Kitap << ' ' << Yazar_adi << ' '
				<< Yazar_soyad << ' ' << Konu << ' '
				<< Tur << " " << Sayfasay << "\n";
			cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
		} while (!(cevap == 'h'));
		file2.close();
		cout << "dosyaya yazim tamamlandi. ";
	}
	if (secim == 8)
	{
		string Isbn;
		cout << "ISBN :"; cin >> Isbn;
		ifstream file2;
		file2.open("okuyucu.txt");
		while (!file2.eof())
		{
			file2 >> ISBN >> Kitap >> Yazar_adi
				>> Yazar_soyad >> Konu >> Tur >> Sayfasay;
			if (Isbn == ISBN)
			{
				ofstream file2;
				file2.open("okuyucu.txt");
				file2 << "" << "" << "" << "" << "" << ""
					<< "" << "" << "" << ""
					<< "" << "" << "" << "" << "" << "\n";
			}
		}
	}
	if (secim == 9)
	{
		string Isbn;
		cout << "ISBN :"; cin >> Isbn;
		ifstream file2;
		file2.open("Kitaplar.txt");
		while (!file2.eof())
		{
			file2 >> ISBN >> Kitap >> Yazar_adi >> Yazar_soyad
				>> Konu >> Tur >> Sayfasay;
			if (ISBN == Isbn)
			{
				cout << "\n Kitap İsmi     :" << Kitap;
				cout << "\n Yazar adi  :" << Yazar_adi;
				cout << "\n Yazar soyadi    :" << Yazar_soyad;
				cout << "\n Konu   :" << Konu;
				cout << "\n Tur      :" << Tur;
				cout << "\n Sayfasayisi    :" << Sayfasay;
			}
		}
		file2.close();
	}

	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "   Programing Baslama saati: " << dt << endl;;

	system("PAUSE");
	return EXIT_SUCCESS;
}


