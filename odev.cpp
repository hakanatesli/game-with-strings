/************************************************************
**                   SAKARYA �N�VERS�TES�
**          B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**              B�LG�SAYAR M�HEND�SL��� B�L�M�
**                 PROGRAMLAMAYA G�R�� DERS�
**
**      �DEV NUMARASI....:3
**      ��RENC� ADI......:HAKAN ATE�L�
**      ��RENC� NUMARASI.:G171210002
**      DERS GRUBU.......:2/A
************************************************************/
#include <iostream>
#include <string.h>
#include <locale.h>
#include <string>
using namespace std;
int sayac;
//-----------------------------------------------------------
struct metin {
	char cumle[100], cml[100], cml2[15], cml3[100], cml4[100];
};
//-----------------------------------------------------------
struct sayi {
	int harfsayisi;
	int kelimesayisi;
}sonuc;
//-----------------------------------------------------------
int harfsayaci(char c[100])
{
	int nekadar, artan = 0;
	nekadar = strlen(c);
	for (int i = 0; i < strlen(c); i++)//burada c�mledeki bo�luklar� bulup dizinin karakter boyutu de�erinden ��kart�p harf say�s� de�erini bulmak i�in.
	{
		if (c[i] == ' ')
			artan++;
	}
	return nekadar - artan;
}
//-----------------------------------------------------------
int kelimesayaci(char c[100])
{
	int donendeger = 1;
	for (int i = 0; i < strlen(c); i++)//buradada bo�luklar� bulup bir ekleyip dizinin kelime say�s�n� bulmak i�in d�ng� yapt�m.
	{
		if (c[i] == ' ')
			donendeger++;
	}
	return donendeger;
}
//-----------------------------------------------------------
void noktalama(char c[100])
{
	for (int i = 0; i < strlen(c); i++)//burada dizinin her bir eleman�n d�ng�de d�nd�r�p if ile belirlenen noktalama i�aretleriyle kar��la�t�r�p ekrana bast�rd�m.
	{
		if (c[i] == '!' || c[i] == '.' || c[i] == ',' || c[i] == ',' || c[i] == ':' || c[i] == ';' || c[i] == '?' || c[i] == '\'' || c[i] == '/')
		{
			cout << i + 1 << ". sutunda " << c[i] << " noktalama isareti vardir." << endl;
		}
	}
}
//-----------------------------------------------------------
void cumlepalindrom(char c[100], char c1[100], char c2[100])
{
	int i, j, x;
	char gec;
	for (x = 0; x < strlen(c); x++)//burada kullan�c�dan al�nan c�mleyi ba�ka diziye koplayad�m ileride kar��la�t�r�p polindrom olup olmad���n� bulmak i�in.
		c1[x] = c[x];
	c1[x] = '\0';
	i = 0;
	j = strlen(c) - 1;
	while (i < j) {//burada diznin ilk de�erini son deger olarak at�yo b�yle s�re gelen i�lemlerle diziyi ters �evirdim.
		gec = c[i];
		c[i] = c[j];
		c[j] = gec;
		i++;
		j--;
	}
	cout << c << endl;
	if (strcmp(c, c1) == 0)//burada �st tarafta kopyalad���m dizi ile ters �evrileni kar��la�t�r�p polindrom mu sorusuna cevap arad�m.
		cout << "girilen cumle palindrom";
	else
		cout << "girilen cumle palindrom degil";
	for (x = 0; x < strlen(c1); x++)//c�mleyi ba�ka bir diziye kopyalad�m.
		c[x] = c1[x];
	c[x] = '\0';
	for (x = 0; x < strlen(c1); x++)//c�mleyi ba�ka bir diziye kopyalad�m.
		c2[x] = c1[x];
	c2[x] = '\0';
}
//-----------------------------------------------------------
void kelimedekiharfsayaci(char c[100])
{
	char * gec;
	char * gec1;
	gec = strtok_s(c, " .,;", &gec1);
	while (gec != NULL)//burada kelimleri ay�r�p ayr� ayr� dizi boyutunu ublup ekrana yazd�rmak i�in d�ng� olu�turdum.
	{
		cout << gec << " : ";
		cout << " " << strlen(gec) << endl;
		gec = strtok_s(NULL, " .,;", &gec1);
	}
}
//-----------------------------------------------------------
void kelimedekiseslisayaci(char c[100])
{
	char * gec;
	char*gec1;
	gec = strtok_s(c, " .,;", &gec1);
	while (gec != NULL)//buradada ay�rd���m kelimelerin i�indeki sesli harfleri tekrar i�eride for d�ng�s�ne sokarak if ile sesli harfe e�it olanlar� bulmak i�in olu�turdum.
	{
		cout << gec << " : ";
		int i = strlen(gec);
		for (int x = 0; x < i; x++)
		{
			if (gec[x] == 'a' || gec[x] == 'e' || gec[x] == 'i' || gec[x] == 'u' || gec[x] == 'o')
				sayac++;
		}
		cout << sayac << endl;
		gec = strtok_s(NULL, " .,;", &gec1);
		sayac = 0;
	}
}
//-----------------------------------------------------------
void kelimepalindrom(char c[100], char c1[100])
{
	int i, j, x;
	char gec;
	char * gec1;
	char*gec2;
	gec1 = strtok_s(c, " .,;", &gec2);
	while (gec1 != NULL)//burada kelimeleri ay�rd�m.
	{
		cout << gec1 << " : ";
		for (x = 0; x < strlen(gec1); x++)//burada kelimeyi kopyalad�m.
			c1[x] = gec1[x];
		c1[x] = '\0';
		i = 0;
		j = strlen(gec1) - 1;
		while (i < j) {//burada ay�rd���m kelimeyi ters �evirdim.
			gec = gec1[i];
			gec1[i] = gec1[j];
			gec1[j] = gec;
			i++;
			j--;
		}
		if (strcmp(gec1, c1) == 0)//kopyalad���mla ters �evirdi�im ayn� m� diye kontrol ettim.
			cout << "kelime palindrom" << endl;
		else
			cout << "kelime palindrom degil" << endl;
		gec1 = strtok_s(NULL, " .,;", &gec2);
	}
}
//-----------------------------------------------------------
int main() {
	struct metin cumle1;
	cout << "metini giriniz(en fazla 100 karakterli ve turkce karakter icermeyen): ";
	cin.get(cumle1.cumle, 100);
	sonuc.harfsayisi = harfsayaci(cumle1.cumle);
	cout << endl << "harf sayisi: " << sonuc.harfsayisi << endl;
	cout << "----------------------------------------------------" << endl;
	sonuc.kelimesayisi = kelimesayaci(cumle1.cumle);
	cout << "kelime sayisi: " << sonuc.kelimesayisi << endl;
	cout << "----------------------------------------------------" << endl;
	noktalama(cumle1.cumle);
	cout << endl << "----------------------------------------------------" << endl;
	cumlepalindrom(cumle1.cumle, cumle1.cml, cumle1.cml3);
	cout << endl << "----------------------------------------------------" << endl;
	kelimedekiharfsayaci(cumle1.cml);
	cout << endl << "----------------------------------------------------" << endl;
	kelimedekiseslisayaci(cumle1.cumle);
	cout << endl << "----------------------------------------------------" << endl;
	kelimepalindrom(cumle1.cml3, cumle1.cml4);
	cout << endl << "----------------------------------------------------" << endl;
	system("pause");
	return 0;
}