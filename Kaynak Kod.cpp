/*******************************************************************************************
**
**                                   SAKARYA ÜNÝVERSÝTESÝ
**                           BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                              BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                                PROGRAMLAMAYA GÝRÝÞž DERSÝ
**
**
**                           ÖDEV NUMARASI: 1
**                           ÖÐRENCÝ ADI: MUSTAFA ENES GÜNERUZ
**                           ÖÐRENCÝ NUMARASI: S191210943
**
********************************************************************************************/

#include <iostream>
#include <fstream>
#include  <string.h>
using namespace std;

// Toplam tutar deðiþkeninin tüm bloklarda görünmesi için blok dýþýna yazýlmalý.
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
    cout << " \n\t Silmek istediðiniz ürünün numarasýný giriniz : ";
    cin.getline(no_kontrol, 25);
    //Ürün dosyasýnýn sonuna gelmediði sürece iþlemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        //strcmp string.h kütüphanesi içinde bulunan bir fonksiyondur. Ýki stringi karþýlaþtýrýp ayný olup olmadýklarýný kontrol eder. 
        if (strcmp(urun_no, no_kontrol) == 0)
        {
            continue;
        }
        else //Ürün bilgilerini geçici dosyaya aktar.
        {
            geciciDosya << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
        }

    }
    geciciDosya.close();
    urunDosyasi.close();

    urunDosyasi.open("UrunDosyasi.txt", ios::out);
    geciciDosya.open("GeciciDosya.txt", ios::in);
    //Geçici dosyanýn sonuna gelmediði sürece iþlemi devam ettir.
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
    //Geçici dosyadaki bilgileri sil.
    remove("GeciciDosya.txt");
    cout << "\n Ýþlem tamamlandý! \n";
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
    cout << " \n\t Deðiþtirmek istediðiniz ürünün numarasýný giriniz : ";
    cin.getline(no_kontrol, 25);
    //Ürün dosyasýnýn sonuna gelmediði sürece iþlemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        //strcmp string.h kütüphanesi içinde bulunan bir fonksiyondur. Ýki stringi karþýlaþtýrýp ayný olup olmadýklarýný kontrol eder. 
        if (strcmp(urun_no, no_kontrol) == 0)
        {
            cout << " \n\tÜrünün yeni bilgilerini giriniz:  \n ";
            cout << " \n Ürün no : ";
            cin.getline(urun_no, 25);
            cout << " \n Ürün adý : ";
            cin.getline(urun_adi, 25);
            cout << " \n Birim : ";
            cin.getline(birim, 25);
            cout << " \n Birim fiyatý : ";
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
    //Geçici dosyanýn sonuna gelmediði sürece iþlemi devam ettir.
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
    cout << "\n Ýþlem tamamlandý! \n";
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

    cout << " \n\t Ürün no \t Ürün adý \t Birim \t Birim fiyatý \t Marka \n";
    //Ürün dosyasýnýn sonuna gelmediði sürece iþlemi devam ettir.
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
    cout << " \n Aradýðýnýz ürünün numarasýný giriniz : ";
    cin.ignore();
    cin.getline(no_kontrol, 25);
    int aranan_urun_mu = 0; // Aranan ürünün bulunup bulunmadýðý, tanýmlanan aranan_urun_mu integer deðiþkeni üzerinden kontrol edildi.
    cout << " \n\t Ürün no \t Ürün adý \t Birim \t\t Birim fiyatý \t Marka\n";
    //Ürün dosyasýnýn sonuna gelmediði sürece iþlemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        // Kullanýcýnýn girdiði sayý ile ürün numarasý uyuþuyorsa aranan ürünün bilgilerini ekrana yazdýr.
        if (strcmp(urun_no, no_kontrol) == 0)
        {
            cout << "\n   \t " << urun_no << "\t" << "\t" << urun_adi << "\t" << "\t" << birim << "\t" << "\t" << birim_fiyati << "\t" << "\t" << marka << endl;
            aranan_urun_mu = 1;
            break;
        }

    }
    // Aranan ürün mevcut deðilse ekrana 'Ürün bulunamadý' yazdýr.
    if (aranan_urun_mu == 0)
    {
        cout << " \n Ürün bulunamadý!\n";
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
    cout << " \n Ürün no : ";
    cin.getline(urun_no, 25);
    cout << " \n Ürün adý : ";
    cin.getline(urun_adi, 25);
    cout << " \n Birim : ";
    cin.getline(birim, 25);
    cout << " \n Birim fiyatý : ";
    cin.getline(birim_fiyati, 25);
    cout << " \n Marka : ";
    cin.getline(marka, 25);
    urunDosyasi << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
    cout << "Ýþlem tamamlandý !";
    urunDosyasi.close();
}

void hakedis_ekle(); // C++ dili kodu yukarýdan aþaðý doðru okuduðu için, aþaðýda böyle bir fonksiyonun olduðu belirtildi.

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
    cout << " \n Proje adý : ";
    cin.getline(proje_adi, 25);
    cout << " \n Proje yürütücü firma : ";
    cin.getline(firma, 25);
    cout << " \n Proje sorumlusu : ";
    cin.getline(proje_sorumlusu, 25);
    cout << " \n Proje kontrolörü : ";
    cin.getline(proje_kontroloru, 25);
    projeDosyasi << "P. no:" << proje_no << '|' << "P. adý:" << proje_adi << '|' << "P. yürütücü firma:" << firma << '|' << "P. sorumlusu:" << proje_sorumlusu << '|' << "P. kontrolörü:" << proje_kontroloru << '\n';

    cout << "Projeye aylýk hakediþ eklemek istiyor musunuz?(E/e)(H/h): ";
    cin >> hakedis_girilsin_mi;

    if (hakedis_girilsin_mi == 'E' || hakedis_girilsin_mi == 'e') {
        hakedis_ekle();
    }
    else if (hakedis_girilsin_mi == 'H' || hakedis_girilsin_mi == 'h') {
        cout << "\nHakediþ eklenmedi.\n";
    }
    else {
        cout << "Ýþlem tamamlandý!\n";
        projeDosyasi.close();
    }
}


void hakedis_ara() {

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::in);
    char hakedis_donemi[25];
    char hakedis_donem_kontrol[25];
    char urun_adi[25];{}

    cout << " \n Aradýðýnýz hakediþ dönemini giriniz : ";
    cin.ignore();
    cin.getline(hakedis_donem_kontrol, 25);
    int aranan_hakedis_mi = 0;// Aranan hakediþ döneminin bulunup bulunmadýðý, tanýmlanan aranan_hakedis_mi integer deðiþkeni üzerinden kontrol edildi.
    cout << " \n\t Hakediþ dönemi \t Kullanýlan ürünler \t Adet fiyatlarý(TL) \t Toplam tutar(TL)";
    //Proje dosyasýnýn sonuna gelmediði sürece iþlemi devam ettir.
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(hakedis_donemi, 25, '|');
        
        // Kullanýcýnýn girdiði deðer ile hakediþ dönemi deðeri uyuþuyorsa aranan hakediþ dönemi bilgilerini ekrana yazdýr.
        if (strcmp(hakedis_donemi, hakedis_donem_kontrol) == 0)
        {
            cout << "\n   \t " << hakedis_donemi << "\t" << "\t" << urun_adi << "\t" << "\t" << adet_fiyati << "\t" << "\t" << toplam_tutar << endl;
            aranan_hakedis_mi = 1;
            break;
        }

    }
    if (aranan_hakedis_mi == 0) // Aranan ürün mevcut deðilse ekrana 'Aranan hakediþ dönemi bulunamadý' yazdýr.
    {
        cout << " \n Aranan hakediþ dönemi bulunamadý!\n";
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

    cout << " \n\t Proje no \t Proje adý \t Firma \t Proje sorumlusu \t P. kontrolörü \n";
    //Proje dosyasýnýn sonuna gelinmediði sürece iþlemi devam ettir.
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
    cout << " \n\t Silmek istediðiniz projenin numarasýný giriniz : ";
    cin.getline(proje_no_kontrol, 25);
    //Proje dosyasýnýn sonuna gelinmediði sürece iþlemi devam ettir.
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(proje_no, 25, '|');
        projeDosyasi.getline(proje_adi, 25, '|');
        projeDosyasi.getline(firma, 25, '|');
        projeDosyasi.getline(proje_sorumlusu, 25, '|');
        projeDosyasi.getline(proje_kontroloru, 25);
        // Kullanýcýnýn girdiði sayý ile proje numarasý uyuþuyorsa proje bilgilerini geçici dosyaya yaz.
        if (strcmp(proje_no, proje_no_kontrol) == 0)
        {
            geciciDosya2 << proje_no << '|' << proje_adi << '|' << firma << '|' << proje_sorumlusu << '|' << proje_kontroloru << '\n';
        }
        else // Diðer durumlarda döngünün baþýna dön.
        {
            continue;
        }
    }
    geciciDosya2.close();
    projeDosyasi.close();

    projeDosyasi.open("ProjeDosyasi.txt", ios::out);
    geciciDosya2.open("GeciciDosya2.txt", ios::in);
    //Geçici dosyanýn sonuna gelinmediði sürece iþleme devam et.
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
    cout << "\n Ýþlem tamamlandý! \n";
}

void hakedis_urun_ekle();

char hakedis_donemi[25];

void hakedis_ekle() {
    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::app);
    cin.ignore();
    cout << " \n Hakediþ dönemi (Deðeri girdikten sonra 2 kere Enter'a basýnýz) : ";
    cin.getline(hakedis_donemi, 25);
    projeDosyasi << "Hakediþ dönemi:" << hakedis_donemi << " ";

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
    cout << " \n Aradýðýnýz projenin numarasýný giriniz : ";
    cin.ignore();
    cin.getline(proje_no_kontrol, 25);
    int aranan_proje_mi = 0; // Aranan projenin bulunup bulunmadýðý, tanýmlanan aranan_proje_mi integer deðiþkeni üzerinden kontrol edildi.
    cout << " \n\t Proje no \t Proje adý \t Firma \t\t Proje sorumlusu \t Proje kontrolörü\n";
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(proje_no, 25, '|');
        projeDosyasi.getline(proje_adi, 25, '|');
        projeDosyasi.getline(firma, 25, '|');
        projeDosyasi.getline(proje_sorumlusu, 25, '|');
        projeDosyasi.getline(proje_kontroloru, 25);
        // Kullanýcýnýn girdiði deðer ile proje numarasý uyuþuyorsa aranan proje bilgilerini ekrana yazdýr.
        if (strcmp(proje_no, proje_no_kontrol) == 0)
        {
            cout << "\n   \t " << proje_no << "\t" << "\t" << proje_adi << "\t" << "\t" << firma << "\t" << "\t" << proje_sorumlusu << "\t" << "\t" << proje_kontroloru << endl;
            aranan_proje_mi = 1;
            break;
        }
    }
    if (aranan_proje_mi == 0) // Aranan ürün mevcut deðilse ekrana 'Proje bulunamadý' yazdýr.
    {
        cout << " \n Proje bulunamadý!\n";
    }
    projeDosyasi.close();
}

void hakedis_urun_ekle() {

    char urun_adi[25];

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::app);
    cin.ignore();
    cout << " \n Ürün adý: ";
    cin.getline(urun_adi, 25);
    cout << " \n Ürünün adet fiyatý(Sayý giriniz.): ";
    cin >> adet_fiyati;
    toplam_tutar += adet_fiyati;

    projeDosyasi << "Ürün adý:" << urun_adi << '|' << "Adet fiyatý:" << adet_fiyati << '\n';
    cout << "Ürün eklendi. Baþka bir ürün eklemek istiyorsanýz ana menüden 10. seçeneðe gidiniz.";
    projeDosyasi.close();
}

int main()
{
    setlocale(LC_ALL, "turkish"); //Türkçe karakter eklemek için.

    int cevap;

    bool ekran = true; // Konsol ekranýný açýk tutma veya kapatma iþlemi için 'ekran' boolean deðiþkeni tanýmlandý.
    while (ekran)
    {
        cout << " Ürün ekle : 1 \n Ürün ara : 2 \n Ürün dosyasýný görüntüle : 3 \n Ürün bilgileri deðiþtir : 4 \n Ürün sil :  5 \n Proje ekle : 6 \n ";
        cout << "Proje ara: 7  \n Proje dosyasýný görüntüle : 8 \n Proje sil : 9 \n Hakediþ dönemi ara : 10 \n Hakediþ dönemine ürün ekle : 11 \n Yapmak istediðiniz iþlem numarasýný yazýnýz : ";

        cin >> cevap;
        //Kullanýcý tarafýndan girilen deðerlere göre, iþlemi ilgili fonksiyonlara yönlendir.
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
            cout << " \n Yanlýþ numara girdiniz. \n";
        }
        cout << " Devam etmek için 'e' tuþuna, çýkmak için baþka bir tuþa basýnýz. \n ";
        char secim;
        cin >> secim;
        //Devam etmek isterse ana menüyü tekrar göster, istemezse konsol ekranýn kapat. 
        if (secim != 'e')
        {
            ekran = false;
        }
    }
    return 0;
}
