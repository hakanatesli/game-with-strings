/************************************************************
**                   SAKARYA ÜNÝVERSÝTESÝ
**          BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**              BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                 PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**      ÖDEV NUMARASI....:3
**      ÖÐRENCÝ ADI......:HAKAN ATEÞLÝ
**      ÖÐRENCÝ NUMARASI.:G171210002
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
	for (int i = 0; i < strlen(c); i++)//burada cümledeki boþluklarý bulup dizinin karakter boyutu deðerinden çýkartýp harf sayýsý deðerini bulmak için.
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
	for (int i = 0; i < strlen(c); i++)//buradada boþluklarý bulup bir ekleyip dizinin kelime sayýsýný bulmak için döngü yaptým.
	{
		if (c[i] == ' ')
			donendeger++;
	}
	return donendeger;
}
//-----------------------------------------------------------
void noktalama(char c[100])
{
	for (int i = 0; i < strlen(c); i++)//burada dizinin her bir elemanýn döngüde döndürüp if ile belirlenen noktalama iþaretleriyle karþýlaþtýrýp ekrana bastýrdým.
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
	for (x = 0; x < strlen(c); x++)//burada kullanýcýdan alýnan cümleyi baþka diziye koplayadým ileride karþýlaþtýrýp polindrom olup olmadýðýný bulmak için.
		c1[x] = c[x];
	c1[x] = '\0';
	i = 0;
	j = strlen(c) - 1;
	while (i < j) {//burada diznin ilk deðerini son deger olarak atýyo böyle süre gelen iþlemlerle diziyi ters çevirdim.
		gec = c[i];
		c[i] = c[j];
		c[j] = gec;
		i++;
		j--;
	}
	cout << c << endl;
	if (strcmp(c, c1) == 0)//burada üst tarafta kopyaladýðým dizi ile ters çevrileni karþýlaþtýrýp polindrom mu sorusuna cevap aradým.
		cout << "girilen cumle palindrom";
	else
		cout << "girilen cumle palindrom degil";
	for (x = 0; x < strlen(c1); x++)//cümleyi baþka bir diziye kopyaladým.
		c[x] = c1[x];
	c[x] = '\0';
	for (x = 0; x < strlen(c1); x++)//cümleyi baþka bir diziye kopyaladým.
		c2[x] = c1[x];
	c2[x] = '\0';
}
//-----------------------------------------------------------
void kelimedekiharfsayaci(char c[100])
{
	char * gec;
	char * gec1;
	gec = strtok_s(c, " .,;", &gec1);
	while (gec != NULL)//burada kelimleri ayýrýp ayrý ayrý dizi boyutunu ublup ekrana yazdýrmak için döngü oluþturdum.
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
	while (gec != NULL)//buradada ayýrdýðým kelimelerin içindeki sesli harfleri tekrar içeride for döngüsüne sokarak if ile sesli harfe eþit olanlarý bulmak için oluþturdum.
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
	while (gec1 != NULL)//burada kelimeleri ayýrdým.
	{
		cout << gec1 << " : ";
		for (x = 0; x < strlen(gec1); x++)//burada kelimeyi kopyaladým.
			c1[x] = gec1[x];
		c1[x] = '\0';
		i = 0;
		j = strlen(gec1) - 1;
		while (i < j) {//burada ayýrdýðým kelimeyi ters çevirdim.
			gec = gec1[i];
			gec1[i] = gec1[j];
			gec1[j] = gec;
			i++;
			j--;
		}
		if (strcmp(gec1, c1) == 0)//kopyaladýðýmla ters çevirdiðim ayný mý diye kontrol ettim.
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