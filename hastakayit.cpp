#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
using namespace std;
struct insan {
	int yas;
	string ad;
	string soyad;
	char id[5];
	string yasadigisehir;
	string sonasitarihi;
	int dozno;
	string asiadi;
	
};
void yenikayit()
{
	
	insan a;
	a.asiadi = "NULL";
	a.dozno = 0;
	a.sonasitarihi = "01.06.2020";

	cout << "Ilk 2 harfi buyuk 4 haneli ID'nizi giriniz(HHRR formatinda olmalidir.): ";
	cin >> a.id;
	if ((a.id[0] >= 'A' && a.id[0] <= 'Z') && (a.id[1] >= 'A' && a.id[1] <= 'Z'))
	{
		if ((a.id[2] >= '0' && a.id[2] <= '9') && (a.id[3] >= '0' && a.id[3] <= '9')&& (a.id[4]=='\0')) {
			cout << "Adinizi giriniz:";
			cin >> a.ad;
			cout << "Soyadinizi giriniz:";
			cin >> a.soyad;
			cout << "Yasinizi giriniz:";
			cin >> a.yas;
			cout << "Yasadiginiz sehri giriniz:";
			cin >> a.yasadigisehir;
			ofstream yazmadosyasi;
			yazmadosyasi.open("database.txt", ios::app);
			yazmadosyasi << a.id << " " << a.ad << " " << a.soyad << " " << a.yas << " " << a.yasadigisehir << " " << a.sonasitarihi << " " << a.dozno << " " << a.asiadi << endl;
			yazmadosyasi.close();
		}
		else
		{
			cout << "Lutfen ID'nizi dogru girdiginizden emin olunuz.";
		}
		
	}
	else {
		cout << "Lutfen ID'nizi dogru girdiginizden emin olunuz.";
	}
	
}
void kayitgoruntuleme()
{
	int i = 1;
	string kelime;
	ifstream okumadosyasi;
	okumadosyasi.open("database.txt");
	while (okumadosyasi >> kelime) {
		if(i%8==1)
		{
			cout <<"ID:"<<kelime << endl;
		}
		if (i % 8 == 2)
		{
			cout << "Ad:" << kelime << endl;
		}
		if (i % 8 == 3)
		{
			cout << "Soyad:" << kelime << endl;
		}
		if (i % 8 == 4)
		{
			cout << "Yas:" << kelime << endl;
		}
		if (i % 8 == 5)
		{
			cout << "Yasadigi sehir:" << kelime << endl;
		}
		if (i % 8 == 6)
		{
			cout << "Son asi tarihi:" << kelime << endl;
		}
		if (i % 8 == 7)
		{
			cout << "Doz no:" << kelime << endl;
		}
		if (i % 8 == 0)
		{
			cout << "Asi adi:" << kelime << endl;
		}
		i++;
	}
	if (i == 1)
	{
		cout << "Kayit bulunmamaktadir." << endl;
	}
	okumadosyasi.close();
}
void kayitguncelleme()
{
	insan a;
	int satirsayisi = 0;
	int x = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	int i = 1;
	string kelime,satir;
	ifstream okumadosyasi;
	okumadosyasi.open("database.txt");
	while (getline(okumadosyasi, satir))
	{
		satirsayisi++;
	}
	string* id = new string[satirsayisi];
	string* ad = new string[satirsayisi];
	string* soyad = new string[satirsayisi];
	string* yas = new string[satirsayisi];
	string* yasadigisehir = new string[satirsayisi];
	string* asidozno = new string[satirsayisi];
	string* asiadi = new string[satirsayisi];
	string* sonasitarihi = new string[satirsayisi];
	okumadosyasi.close();
	okumadosyasi.open("database.txt");
	while (okumadosyasi >> kelime) {
		if (i % 8 == 1)
		{
			id[x] = kelime;
			x++;
		}
		if (i % 8 == 2)
		{
			ad[b] = kelime;
			b++;
		}
		if (i % 8 == 3)
		{
			soyad[c] = kelime;
			c++;
		}
		if (i % 8 == 4)
		{
			yas[d] = kelime;
			d++;
		}
		if (i % 8 == 5)
		{
			yasadigisehir[e] = kelime;
			e++;
		}
		if (i % 8 == 6)
		{
			sonasitarihi[f] = kelime;
			f++;
		}
		if (i % 8 == 7)
		{
			asidozno[g] = kelime;
			g++;
		}
		if (i % 8 == 0)
		{
			asiadi[h] = kelime;
			h++;
		}
		i++;
	}
	int n;
	cout << "Degistirmek istediginiz kisinin ID'sini giriniz(HHRR):";
	cin >> a.id;
	for (int i = 0; i < satirsayisi; i++)
	{
		if (id[i] == a.id)
		{
			cout << "Kullanicinin hangi bilgisini degistirmek istersiniz?" << endl;
			cout << "(1)ID" << endl;
			cout << "(2)AD" << endl;
			cout << "(3)SOYAD" << endl;
			cout << "(4)YAS" << endl;
			cout << "(5)YASADIGI SEHIR" << endl;
			cin >> n;
			if (n == 1)
			{
				cout << "Yeni ID giriniz:";
				cin >> id[i];
			}
			if (n == 2)
			{
				cout << "Yeni ad giriniz:";
				cin >> ad[i];
			}
			if (n == 3)
			{
				cout << "Yeni soyad giriniz:";
				cin >> soyad[i];
			}
			if (n == 4)
			{
				cout << "Yeni yas giriniz:";
				cin >> yas[i];
			}
			if (n == 5)
			{
				cout << "Yeni yasadigi sehir giriniz:";
				cin >> yasadigisehir[i];
			}
		}
		
	}
	
	ofstream yazmadosyasi;
	yazmadosyasi.open("temp.txt");
	for (int i = 0; i < satirsayisi; i++)
	{
	yazmadosyasi << id[i] << " " << ad[i] << " " << soyad[i] << " " << yas[i] << " " << yasadigisehir[i] << " " << sonasitarihi[i] << " " << asidozno[i] << " " << asiadi[i] << endl;
	}
	yazmadosyasi.close();
	okumadosyasi.close();
	remove("database.txt");
	rename("temp.txt", "database.txt");
	delete[] id;
	delete[] ad;
	delete[] soyad;
	delete[] yas;
	delete[] yasadigisehir;
	delete[] asidozno;
	delete[] asiadi;
	delete[] sonasitarihi;
}
void yeniasikaydi()
{
	int counterx = 0, countery = 0;
	insan a;
	int satirsayisi = 0;
	int x = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	int i = 1;
	string kelime, satir;
	ifstream okumadosyasi;
	okumadosyasi.open("database.txt");
	while (getline(okumadosyasi, satir))
	{
		satirsayisi++;
	}
	string* id = new string[satirsayisi];
	string* ad = new string[satirsayisi];
	string* soyad = new string[satirsayisi];
	string* yas = new string[satirsayisi];
	string* yasadigisehir = new string[satirsayisi];
	string* asidozno = new string[satirsayisi];
	string* asiadi = new string[satirsayisi];
	string* sonasitarihi = new string[satirsayisi];
	okumadosyasi.close();
	okumadosyasi.open("database.txt");
	while (okumadosyasi >> kelime) {
		if (i % 8 == 1)
		{
			id[x] = kelime;
			x++;
		}
		if (i % 8 == 2)
		{
			ad[b] = kelime;
			b++;
		}
		if (i % 8 == 3)
		{
			soyad[c] = kelime;
			c++;
		}
		if (i % 8 == 4)
		{
			yas[d] = kelime;
			d++;
		}
		if (i % 8 == 5)
		{
			yasadigisehir[e] = kelime;
			e++;
		}
		if (i % 8 == 6)
		{
			sonasitarihi[f] = kelime;
			f++;
		}
		if (i % 8 == 7)
		{
			asidozno[g] = kelime;
			g++;
		}
		if (i % 8 == 0)
		{
			asiadi[h] = kelime;
			h++;
		}
		i++;
	}
	int flag = 0;
	string randevutarihi;
	int z;
	int gunfarki;
	cout << "Asi kaydi yapmak istediginiz kisinin ID'sini giriniz:";
	cin >> a.id;
	for (int i = 0; i < satirsayisi; i++)
	{
		if (a.id == id[i])
		{
			flag++;
			cout << "Randevu tarihi giriniz(GG.AA.YYYY):";
			cin >> randevutarihi;
			char gun1[3];
			char ay1[3];
			char yil1[5];
			randevutarihi.copy(gun1, 2, 0);
			gun1[2] = '\0';
			randevutarihi.copy(ay1, 2, 3);
			ay1[2] = '\0';
			randevutarihi.copy(yil1, 4, 6);
			yil1[4] = '\0';
			int gecengunsayisi1, gecengunsayisi2;
			gecengunsayisi1 = (stoi(yil1) * 365) + stoi(gun1);
			int aylar[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
			for (int a = 0; a < stoi(ay1) - 1; a++)
			{
				gecengunsayisi1 += aylar[a];
			}
			char gun2[3];
			char ay2[3];
			char yil2[5];
			sonasitarihi[i].copy(gun2, 2, 0);
			gun2[2] = '\0';
			sonasitarihi[i].copy(ay2, 2, 3);
			ay2[2] = '\0';
			sonasitarihi[i].copy(yil2, 4, 6);
			yil2[4] = '\0';
			gecengunsayisi2 = (stoi(yil2) * 365 )+ stoi(gun2);
			for (int a = 0; a < stoi(ay2) - 1;a++)
			{
				gecengunsayisi2 += aylar[a];
			}
			gunfarki = gecengunsayisi1 - gecengunsayisi2;
			if (asidozno[i] == "2" ||stoi(yas[i])<18)
			{
				cout <<"Asi hakkiniz yoktur."<<endl;
			}
			else if (gunfarki < 30)
			{
				cout << "Son asinin ustunden 30 gun gecmelidir.";
			}
			else {
				cout << "Olmak istediginiz asiyi seciniz:" << endl;
				cout << "(1)X" << endl;
				cout << "(2)Y" << endl;
				cin >> z;
				if (z == 1)
				{
					if (asiadi[i] == "X" || asiadi[i] == "NULL") {
						cout << "Asi kaydiniz tamamlandi"<<endl;
						sonasitarihi[i] = randevutarihi;
						asiadi[i] = "X";
						if (asidozno[i] == "0")
						{

							counterx++;
							asidozno[i] = "1";
						}
						else if (asidozno[i] == "1")
						{
							asidozno[i] = "2";
						}
					}
					else {
						cout << "Sadece bir tur asi olabilirsiniz. " << endl;
						
					}
				}
				if (z == 2)
				{
					if (asiadi[i] == "Y" || asiadi[i] == "NULL") {
						cout << "Asi kaydiniz tamamlandi"<<endl;
						sonasitarihi[i] = randevutarihi;
						asiadi[i] = "Y";
						if (asidozno[i] == "0")
						{
							countery++;
							asidozno[i] = "1";
						}
						else if (asidozno[i] == "1")
						{
							asidozno[i] = "2";
						}
					}
					else {
						cout << "Sadece bir tur asi olabilirsiniz." << endl;
					}
				}
			}
		}
		
	}
	 if (flag == 0)
		{
		cout << "ID bulunamadi.";
		}
	ofstream yazmadosyasi;
	yazmadosyasi.open("temp.txt");
	for (int i = 0; i < satirsayisi; i++)
	{
		yazmadosyasi << id[i] << " " << ad[i] << " " << soyad[i] << " " << yas[i] << " " << yasadigisehir[i] << " " << sonasitarihi[i] << " " << asidozno[i] << " " << asiadi[i] << endl;
	}
	yazmadosyasi.close();
	okumadosyasi.close();
	remove("database.txt");
	rename("temp.txt", "database.txt");
	delete[] id;
	delete[] ad;
	delete[] soyad;
	delete[] yas;
	delete[] yasadigisehir;
	delete[] asidozno;
	delete[] asiadi;
	delete[] sonasitarihi;
}
int main()
{
	string x;
	while (1) {
		cout << "Istediginiz islemin rakamini yaziniz" << endl;
		cout << "Lutfen bir islem seciniz." << endl;
		cout << "(1)Sisteme kaydolmak" << endl;
		cout << "(2)Kayit goruntulemek" << endl;
		cout << "(3)Kayit guncellemek" << endl;
		cout << "(4)Yeni asi kaydi" << endl;
		cout << "(5)Cikis yapmak" << endl;
		cin >> x;
		if (x == "1")
		{
			yenikayit();
		}
		if (x == "2")
		{
			kayitgoruntuleme();
		}
		if (x == "3")
		{
			kayitguncelleme();
		}
		if (x == "4")
		{
			yeniasikaydi();
		}
		if (x == "exit" || x == "5")
		{
			break;
		}
	}
}
