/*******************************************************************************************
**
**                                   SAKARYA �N�VERS�TES�
**                           B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                              B�LG�SAYAR M�HEND�SL��� B�L�M�
**                                PROGRAMLAMAYA G�R�ޞ DERS�
**
**
**                           �DEV NUMARASI: 1
**                           ��RENC� ADI: MUSTAFA ENES G�NERUZ
**                           ��RENC� NUMARASI: S191210943
**
********************************************************************************************/

#include <iostream>
#include <fstream>
#include  <string.h>
using namespace std;

// Toplam tutar de�i�keninin t�m bloklarda g�r�nmesi i�in blok d���na yaz�lmal�.
float toplam_tutar = 0.0;
float adet_fiyati = 0.0;

void delete_urun()
{

    fstream urunDosyasi;
    fstream geciciDosya;

    urunDosyasi.open("UrunDosyasi.txt", ios::in);
    geciciDosya.open("GeciciDosya.txt", ios::out);
    char urun_no[25];
    char urun_adi[25];
    char birim[25];
    char birim_fiyati[25];
    char marka[25];
    char no_kontrol[25];
    cin.ignore();
    cout << " \n\t Silmek istedi�iniz �r�n�n numaras�n� giriniz : ";
    cin.getline(no_kontrol, 25);
    //�r�n dosyas�n�n sonuna gelmedi�i s�rece i�lemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        //strcmp string.h k�t�phanesi i�inde bulunan bir fonksiyondur. �ki stringi kar��la�t�r�p ayn� olup olmad�klar�n� kontrol eder. 
        if (strcmp(urun_no, no_kontrol) == 0)
        {
            continue;
        }
        else //�r�n bilgilerini ge�ici dosyaya aktar.
        {
            geciciDosya << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
        }

    }
    geciciDosya.close();
    urunDosyasi.close();

    urunDosyasi.open("UrunDosyasi.txt", ios::out);
    geciciDosya.open("GeciciDosya.txt", ios::in);
    //Ge�ici dosyan�n sonuna gelmedi�i s�rece i�lemi devam ettir.
    while (!geciciDosya.eof())
    {
        geciciDosya.getline(urun_no, 25, '|');
        geciciDosya.getline(urun_adi, 25, '|');
        geciciDosya.getline(birim, 25, '|');
        geciciDosya.getline(birim_fiyati, 25, '|');
        geciciDosya.getline(marka, 25);
        urunDosyasi << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
    }
    geciciDosya.close();
    urunDosyasi.close();
    //Ge�ici dosyadaki bilgileri sil.
    remove("GeciciDosya.txt");
    cout << "\n ��lem tamamland�! \n";
}

void urun_degistir()
{
    fstream urunDosyasi;
    fstream geciciDosya;

    urunDosyasi.open("UrunDosyasi.txt", ios::in);
    geciciDosya.open("GeciciDosya.txt", ios::out);
    char urun_no[25];
    char urun_adi[25];
    char birim[25];
    char birim_fiyati[25];
    char marka[25];
    char no_kontrol[25];
    cin.ignore();
    cout << " \n\t De�i�tirmek istedi�iniz �r�n�n numaras�n� giriniz : ";
    cin.getline(no_kontrol, 25);
    //�r�n dosyas�n�n sonuna gelmedi�i s�rece i�lemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        //strcmp string.h k�t�phanesi i�inde bulunan bir fonksiyondur. �ki stringi kar��la�t�r�p ayn� olup olmad�klar�n� kontrol eder. 
        if (strcmp(urun_no, no_kontrol) == 0)
        {
            cout << " \n\t�r�n�n yeni bilgilerini giriniz:  \n ";
            cout << " \n �r�n no : ";
            cin.getline(urun_no, 25);
            cout << " \n �r�n ad� : ";
            cin.getline(urun_adi, 25);
            cout << " \n Birim : ";
            cin.getline(birim, 25);
            cout << " \n Birim fiyat� : ";
            cin.getline(birim_fiyati, 25);
            cout << " \n Marka : ";
            cin.getline(marka, 25);
            geciciDosya << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
        }
        else
        {
            geciciDosya << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
        }


    }
    geciciDosya.close();
    urunDosyasi.close();

    urunDosyasi.open("UrunDosyasi.txt", ios::out);
    geciciDosya.open("GeciciDosya.txt", ios::in);
    //Ge�ici dosyan�n sonuna gelmedi�i s�rece i�lemi devam ettir.
    while (!geciciDosya.eof())
    {
        geciciDosya.getline(urun_no, 25, '|');
        geciciDosya.getline(urun_adi, 25, '|');
        geciciDosya.getline(birim, 25, '|');
        geciciDosya.getline(birim_fiyati, 25, '|');
        geciciDosya.getline(birim, 25);
        urunDosyasi << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
    }
    geciciDosya.close();
    urunDosyasi.close();
    remove("geciciDosya.txt");
    cout << "\n ��lem tamamland�! \n";
}

void urun_dosyasi_goruntule()
{
    char urun_no[25];
    char urun_adi[25];
    char birim[25];
    char birim_fiyati[25];
    char marka[25];

    fstream urunDosyasi;
    urunDosyasi.open("UrunDosyasi.txt", ios::in);

    cout << " \n\t �r�n no \t �r�n ad� \t Birim \t Birim fiyat� \t Marka \n";
    //�r�n dosyas�n�n sonuna gelmedi�i s�rece i�lemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        cout << "\n   \t " << urun_no << "\t" << "\t" << urun_adi << "\t" << "\t" << birim << "\t" << birim_fiyati << "\t" << "\t" << marka << endl;
    }
}

void urun_ara()
{

    fstream urunDosyasi;
    urunDosyasi.open("UrunDosyasi.txt", ios::in);
    char urun_no[25];
    char urun_adi[25];
    char birim[25];
    char birim_fiyati[25];
    char marka[25];
    char no_kontrol[25];
    cout << " \n Arad���n�z �r�n�n numaras�n� giriniz : ";
    cin.ignore();
    cin.getline(no_kontrol, 25);
    int aranan_urun_mu = 0; // Aranan �r�n�n bulunup bulunmad���, tan�mlanan aranan_urun_mu integer de�i�keni �zerinden kontrol edildi.
    cout << " \n\t �r�n no \t �r�n ad� \t Birim \t\t Birim fiyat� \t Marka\n";
    //�r�n dosyas�n�n sonuna gelmedi�i s�rece i�lemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        // Kullan�c�n�n girdi�i say� ile �r�n numaras� uyu�uyorsa aranan �r�n�n bilgilerini ekrana yazd�r.
        if (strcmp(urun_no, no_kontrol) == 0)
        {
            cout << "\n   \t " << urun_no << "\t" << "\t" << urun_adi << "\t" << "\t" << birim << "\t" << "\t" << birim_fiyati << "\t" << "\t" << marka << endl;
            aranan_urun_mu = 1;
            break;
        }

    }
    // Aranan �r�n mevcut de�ilse ekrana '�r�n bulunamad�' yazd�r.
    if (aranan_urun_mu == 0)
    {
        cout << " \n �r�n bulunamad�!\n";
    }
    urunDosyasi.close();
}

void  urun_ekle()
{
    char urun_no[25];
    char urun_adi[25];
    char birim[25];
    char birim_fiyati[25];
    char marka[25];

    fstream urunDosyasi;
    urunDosyasi.open("UrunDosyasi.txt", ios::app);
    cin.ignore();
    cout << " \n �r�n no : ";
    cin.getline(urun_no, 25);
    cout << " \n �r�n ad� : ";
    cin.getline(urun_adi, 25);
    cout << " \n Birim : ";
    cin.getline(birim, 25);
    cout << " \n Birim fiyat� : ";
    cin.getline(birim_fiyati, 25);
    cout << " \n Marka : ";
    cin.getline(marka, 25);
    urunDosyasi << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
    cout << "��lem tamamland� !";
    urunDosyasi.close();
}

void hakedis_ekle(); // C++ dili kodu yukar�dan a�a�� do�ru okudu�u i�in, a�a��da b�yle bir fonksiyonun oldu�u belirtildi.

void proje_ekle() {

    char proje_no[25];
    char proje_adi[25];
    char firma[25];
    char proje_sorumlusu[25];
    char proje_kontroloru[25];
    char hakedis_girilsin_mi;

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::app);
    cin.ignore();
    cout << " \n Proje no : ";
    cin.getline(proje_no, 25);
    cout << " \n Proje ad� : ";
    cin.getline(proje_adi, 25);
    cout << " \n Proje y�r�t�c� firma : ";
    cin.getline(firma, 25);
    cout << " \n Proje sorumlusu : ";
    cin.getline(proje_sorumlusu, 25);
    cout << " \n Proje kontrol�r� : ";
    cin.getline(proje_kontroloru, 25);
    projeDosyasi << "P. no:" << proje_no << '|' << "P. ad�:" << proje_adi << '|' << "P. y�r�t�c� firma:" << firma << '|' << "P. sorumlusu:" << proje_sorumlusu << '|' << "P. kontrol�r�:" << proje_kontroloru << '\n';

    cout << "Projeye ayl�k hakedi� eklemek istiyor musunuz?(E/e)(H/h): ";
    cin >> hakedis_girilsin_mi;

    if (hakedis_girilsin_mi == 'E' || hakedis_girilsin_mi == 'e') {
        hakedis_ekle();
    }
    else if (hakedis_girilsin_mi == 'H' || hakedis_girilsin_mi == 'h') {
        cout << "\nHakedi� eklenmedi.\n";
    }
    else {
        cout << "��lem tamamland�!\n";
        projeDosyasi.close();
    }
}


void hakedis_ara() {

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::in);
    char hakedis_donemi[25];
    char hakedis_donem_kontrol[25];
    char urun_adi[25];{}

    cout << " \n Arad���n�z hakedi� d�nemini giriniz : ";
    cin.ignore();
    cin.getline(hakedis_donem_kontrol, 25);
    int aranan_hakedis_mi = 0;// Aranan hakedi� d�neminin bulunup bulunmad���, tan�mlanan aranan_hakedis_mi integer de�i�keni �zerinden kontrol edildi.
    cout << " \n\t Hakedi� d�nemi \t Kullan�lan �r�nler \t Adet fiyatlar�(TL) \t Toplam tutar(TL)";
    //Proje dosyas�n�n sonuna gelmedi�i s�rece i�lemi devam ettir.
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(hakedis_donemi, 25, '|');
        
        // Kullan�c�n�n girdi�i de�er ile hakedi� d�nemi de�eri uyu�uyorsa aranan hakedi� d�nemi bilgilerini ekrana yazd�r.
        if (strcmp(hakedis_donemi, hakedis_donem_kontrol) == 0)
        {
            cout << "\n   \t " << hakedis_donemi << "\t" << "\t" << urun_adi << "\t" << "\t" << adet_fiyati << "\t" << "\t" << toplam_tutar << endl;
            aranan_hakedis_mi = 1;
            break;
        }

    }
    if (aranan_hakedis_mi == 0) // Aranan �r�n mevcut de�ilse ekrana 'Aranan hakedi� d�nemi bulunamad�' yazd�r.
    {
        cout << " \n Aranan hakedi� d�nemi bulunamad�!\n";
    }
    projeDosyasi.close();
}

void proje_dosyasi_goruntule() {
    char proje_no[25];
    char proje_adi[25];
    char firma[25];
    char proje_sorumlusu[25];
    char proje_kontroloru[25];

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::in);

    cout << " \n\t Proje no \t Proje ad� \t Firma \t Proje sorumlusu \t P. kontrol�r� \n";
    //Proje dosyas�n�n sonuna gelinmedi�i s�rece i�lemi devam ettir.
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(proje_no, 25, '|');
        projeDosyasi.getline(proje_adi, 25, '|');
        projeDosyasi.getline(firma, 25, '|');
        projeDosyasi.getline(proje_sorumlusu, 25, '|');
        projeDosyasi.getline(proje_kontroloru, 25);
        cout << "\n   \t " << proje_no << "\t" << proje_adi << "\t" << "\t" << firma << "\t" << proje_sorumlusu << "\t" << proje_kontroloru << endl;
    }
}

void delete_proje() {

    fstream projeDosyasi;
    fstream geciciDosya2;

    projeDosyasi.open("ProjeDosyasi.txt", ios::in);
    geciciDosya2.open("GeciciDosya2.txt", ios::out);
    char proje_no[25];
    char proje_adi[25];
    char firma[25];
    char proje_sorumlusu[25];
    char proje_kontroloru[25];
    char proje_no_kontrol[25];
    cin.ignore();
    cout << " \n\t Silmek istedi�iniz projenin numaras�n� giriniz : ";
    cin.getline(proje_no_kontrol, 25);
    //Proje dosyas�n�n sonuna gelinmedi�i s�rece i�lemi devam ettir.
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(proje_no, 25, '|');
        projeDosyasi.getline(proje_adi, 25, '|');
        projeDosyasi.getline(firma, 25, '|');
        projeDosyasi.getline(proje_sorumlusu, 25, '|');
        projeDosyasi.getline(proje_kontroloru, 25);
        // Kullan�c�n�n girdi�i say� ile proje numaras� uyu�uyorsa proje bilgilerini ge�ici dosyaya yaz.
        if (strcmp(proje_no, proje_no_kontrol) == 0)
        {
            geciciDosya2 << proje_no << '|' << proje_adi << '|' << firma << '|' << proje_sorumlusu << '|' << proje_kontroloru << '\n';
        }
        else // Di�er durumlarda d�ng�n�n ba��na d�n.
        {
            continue;
        }
    }
    geciciDosya2.close();
    projeDosyasi.close();

    projeDosyasi.open("ProjeDosyasi.txt", ios::out);
    geciciDosya2.open("GeciciDosya2.txt", ios::in);
    //Ge�ici dosyan�n sonuna gelinmedi�i s�rece i�leme devam et.
    while (!geciciDosya2.eof())
    {
        geciciDosya2.getline(proje_no, 25, '|');
        geciciDosya2.getline(proje_adi, 25, '|');
        geciciDosya2.getline(firma, 25, '|');
        geciciDosya2.getline(proje_sorumlusu, 25, '|');
        geciciDosya2.getline(proje_kontroloru, 25);
        projeDosyasi << proje_no << '|' << proje_adi << '|' << firma << '|' << proje_sorumlusu << '|' << proje_kontroloru << '\n';
    }
    geciciDosya2.close();
    projeDosyasi.close();
    remove("GeciciDosya2.txt");
    cout << "\n ��lem tamamland�! \n";
}

void hakedis_urun_ekle();

char hakedis_donemi[25];

void hakedis_ekle() {
    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::app);
    cin.ignore();
    cout << " \n Hakedi� d�nemi (De�eri girdikten sonra 2 kere Enter'a bas�n�z) : ";
    cin.getline(hakedis_donemi, 25);
    projeDosyasi << "Hakedi� d�nemi:" << hakedis_donemi << " ";

    hakedis_urun_ekle();
}

void proje_ara() {

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::in);
    char proje_no[25];
    char proje_adi[25];
    char firma[25];
    char proje_sorumlusu[25];
    char proje_kontroloru[25];
    char proje_no_kontrol[25];
    cout << " \n Arad���n�z projenin numaras�n� giriniz : ";
    cin.ignore();
    cin.getline(proje_no_kontrol, 25);
    int aranan_proje_mi = 0; // Aranan projenin bulunup bulunmad���, tan�mlanan aranan_proje_mi integer de�i�keni �zerinden kontrol edildi.
    cout << " \n\t Proje no \t Proje ad� \t Firma \t\t Proje sorumlusu \t Proje kontrol�r�\n";
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(proje_no, 25, '|');
        projeDosyasi.getline(proje_adi, 25, '|');
        projeDosyasi.getline(firma, 25, '|');
        projeDosyasi.getline(proje_sorumlusu, 25, '|');
        projeDosyasi.getline(proje_kontroloru, 25);
        // Kullan�c�n�n girdi�i de�er ile proje numaras� uyu�uyorsa aranan proje bilgilerini ekrana yazd�r.
        if (strcmp(proje_no, proje_no_kontrol) == 0)
        {
            cout << "\n   \t " << proje_no << "\t" << "\t" << proje_adi << "\t" << "\t" << firma << "\t" << "\t" << proje_sorumlusu << "\t" << "\t" << proje_kontroloru << endl;
            aranan_proje_mi = 1;
            break;
        }
    }
    if (aranan_proje_mi == 0) // Aranan �r�n mevcut de�ilse ekrana 'Proje bulunamad�' yazd�r.
    {
        cout << " \n Proje bulunamad�!\n";
    }
    projeDosyasi.close();
}

void hakedis_urun_ekle() {

    char urun_adi[25];

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::app);
    cin.ignore();
    cout << " \n �r�n ad�: ";
    cin.getline(urun_adi, 25);
    cout << " \n �r�n�n adet fiyat�(Say� giriniz.): ";
    cin >> adet_fiyati;
    toplam_tutar += adet_fiyati;

    projeDosyasi << "�r�n ad�:" << urun_adi << '|' << "Adet fiyat�:" << adet_fiyati << '\n';
    cout << "�r�n eklendi. Ba�ka bir �r�n eklemek istiyorsan�z ana men�den 10. se�ene�e gidiniz.";
    projeDosyasi.close();
}

int main()
{
    setlocale(LC_ALL, "turkish"); //T�rk�e karakter eklemek i�in.

    int cevap;

    bool ekran = true; // Konsol ekran�n� a��k tutma veya kapatma i�lemi i�in 'ekran' boolean de�i�keni tan�mland�.
    while (ekran)
    {
        cout << " �r�n ekle : 1 \n �r�n ara : 2 \n �r�n dosyas�n� g�r�nt�le : 3 \n �r�n bilgileri de�i�tir : 4 \n �r�n sil :  5 \n Proje ekle : 6 \n ";
        cout << "Proje ara: 7  \n Proje dosyas�n� g�r�nt�le : 8 \n Proje sil : 9 \n Hakedi� d�nemi ara : 10 \n Hakedi� d�nemine �r�n ekle : 11 \n Yapmak istedi�iniz i�lem numaras�n� yaz�n�z : ";

        cin >> cevap;
        //Kullan�c� taraf�ndan girilen de�erlere g�re, i�lemi ilgili fonksiyonlara y�nlendir.
        switch (cevap)
        {
        case 1:
            urun_ekle();
            break;
        case 2:
            urun_ara();
            break;
        case 3:
            urun_dosyasi_goruntule();
            break;
        case 4:
            urun_degistir();
            break;
        case 5:
            delete_urun();
            break;
        case 6:
            proje_ekle();
            break;
        case 7:
            proje_ara();
            break;
        case 8:
            proje_dosyasi_goruntule();
            break;
        case 9:
            delete_proje();
            break;
        case 10:
            hakedis_ara();
            break;
        case 11:
            hakedis_urun_ekle();
            break;
        default:
            cout << " \n Yanl�� numara girdiniz. \n";
        }
        cout << " Devam etmek i�in 'e' tu�una, ��kmak i�in ba�ka bir tu�a bas�n�z. \n ";
        char secim;
        cin >> secim;
        //Devam etmek isterse ana men�y� tekrar g�ster, istemezse konsol ekran�n kapat. 
        if (secim != 'e')
        {
            ekran = false;
        }
    }
    return 0;
}
