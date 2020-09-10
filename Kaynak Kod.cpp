#include <iostream>
#include <fstream>
#include  <string.h>
using namespace std;

// Toplam tutar değişkeninin tüm bloklarda görünmesi için blok dışına yazılmalı.
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
    cout << " \n\t Silmek istediğiniz ürünün numarasını giriniz : ";
    cin.getline(no_kontrol, 25);
    //Ürün dosyasının sonuna gelmediği sürece işlemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        //strcmp string.h kütüphanesi içinde bulunan bir fonksiyondur. İki stringi karşılaştırıp aynı olup olmadıklarını kontrol eder. 
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
    //Geçici dosyanın sonuna gelmediği sürece işlemi devam ettir.
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
    cout << "\n İşlem tamamlandı! \n";
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
    cout << " \n\t Değiştirmek istediğiniz ürünün numarasını giriniz : ";
    cin.getline(no_kontrol, 25);
    //Ürün dosyasının sonuna gelmediği sürece işlemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        //strcmp string.h kütüphanesi içinde bulunan bir fonksiyondur. İki stringi karşılaştırıp aynı olup olmadıklarını kontrol eder. 
        if (strcmp(urun_no, no_kontrol) == 0)
        {
            cout << " \n\tÜrünün yeni bilgilerini giriniz:  \n ";
            cout << " \n Ürün no : ";
            cin.getline(urun_no, 25);
            cout << " \n Ürün adı : ";
            cin.getline(urun_adi, 25);
            cout << " \n Birim : ";
            cin.getline(birim, 25);
            cout << " \n Birim fiyatı : ";
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
    //Geçici dosyanın sonuna gelmediği sürece işlemi devam ettir.
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
    cout << "\n İşlem tamamlandı! \n";
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

    cout << " \n\t Ürün no \t Ürün adı \t Birim \t Birim fiyatı \t Marka \n";
    //Ürün dosyasının sonuna gelmediği sürece işlemi devam ettir.
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
    cout << " \n Aradığınız ürünün numarasını giriniz : ";
    cin.ignore();
    cin.getline(no_kontrol, 25);
    int aranan_urun_mu = 0; // Aranan ürünün bulunup bulunmadığı, tanımlanan aranan_urun_mu integer değişkeni üzerinden kontrol edildi.
    cout << " \n\t Ürün no \t Ürün adı \t Birim \t\t Birim fiyatı \t Marka\n";
    //Ürün dosyasının sonuna gelmediği sürece işlemi devam ettir.
    while (!urunDosyasi.eof())
    {
        urunDosyasi.getline(urun_no, 25, '|');
        urunDosyasi.getline(urun_adi, 25, '|');
        urunDosyasi.getline(birim, 25, '|');
        urunDosyasi.getline(birim_fiyati, 25, '|');
        urunDosyasi.getline(marka, 25);
        // Kullanıcının girdiği sayı ile ürün numarası uyuşuyorsa aranan ürünün bilgilerini ekrana yazdır.
        if (strcmp(urun_no, no_kontrol) == 0)
        {
            cout << "\n   \t " << urun_no << "\t" << "\t" << urun_adi << "\t" << "\t" << birim << "\t" << "\t" << birim_fiyati << "\t" << "\t" << marka << endl;
            aranan_urun_mu = 1;
            break;
        }

    }
    // Aranan ürün mevcut değilse ekrana 'Ürün bulunamadı' yazdır.
    if (aranan_urun_mu == 0)
    {
        cout << " \n Ürün bulunamadı!\n";
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
    cout << " \n Ürün adı : ";
    cin.getline(urun_adi, 25);
    cout << " \n Birim : ";
    cin.getline(birim, 25);
    cout << " \n Birim fiyatı : ";
    cin.getline(birim_fiyati, 25);
    cout << " \n Marka : ";
    cin.getline(marka, 25);
    urunDosyasi << urun_no << '|' << urun_adi << '|' << birim << '|' << birim_fiyati << '|' << marka << '\n';
    cout << "İşlem tamamlandı !";
    urunDosyasi.close();
}

void hakedis_ekle(); // C++ dili kodu yukarıdan aşağı doğru okuduğu için, aşağıda böyle bir fonksiyonun olduğu belirtildi.

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
    cout << " \n Proje adı : ";
    cin.getline(proje_adi, 25);
    cout << " \n Proje yürütücü firma : ";
    cin.getline(firma, 25);
    cout << " \n Proje sorumlusu : ";
    cin.getline(proje_sorumlusu, 25);
    cout << " \n Proje kontrolörü : ";
    cin.getline(proje_kontroloru, 25);
    projeDosyasi << "P. no:" << proje_no << '|' << "P. adı:" << proje_adi << '|' << "P. yürütücü firma:" << firma << '|' << "P. sorumlusu:" << proje_sorumlusu << '|' << "P. kontrolörü:" << proje_kontroloru << '\n';

    cout << "Projeye aylık hakediş eklemek istiyor musunuz?(E/e)(H/h): ";
    cin >> hakedis_girilsin_mi;

    if (hakedis_girilsin_mi == 'E' || hakedis_girilsin_mi == 'e') {
        hakedis_ekle();
    }
    else if (hakedis_girilsin_mi == 'H' || hakedis_girilsin_mi == 'h') {
        cout << "\nHakediş eklenmedi.\n";
    }
    else {
        cout << "İşlem tamamlandı!\n";
        projeDosyasi.close();
    }
}


void hakedis_ara() {

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::in);
    char hakedis_donemi[25];
    char hakedis_donem_kontrol[25];
    char urun_adi[25];{}

    cout << " \n Aradığınız hakediş dönemini giriniz : ";
    cin.ignore();
    cin.getline(hakedis_donem_kontrol, 25);
    int aranan_hakedis_mi = 0;// Aranan hakediş döneminin bulunup bulunmadığı, tanımlanan aranan_hakedis_mi integer değişkeni üzerinden kontrol edildi.
    cout << " \n\t Hakediş dönemi \t Kullanılan ürünler \t Adet fiyatları(TL) \t Toplam tutar(TL)";
    //Proje dosyasının sonuna gelmediği sürece işlemi devam ettir.
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(hakedis_donemi, 25, '|');
        
        // Kullanıcının girdiği değer ile hakediş dönemi değeri uyuşuyorsa aranan hakediş dönemi bilgilerini ekrana yazdır.
        if (strcmp(hakedis_donemi, hakedis_donem_kontrol) == 0)
        {
            cout << "\n   \t " << hakedis_donemi << "\t" << "\t" << urun_adi << "\t" << "\t" << adet_fiyati << "\t" << "\t" << toplam_tutar << endl;
            aranan_hakedis_mi = 1;
            break;
        }

    }
    if (aranan_hakedis_mi == 0) // Aranan ürün mevcut değilse ekrana 'Aranan hakediş dönemi bulunamadı' yazdır.
    {
        cout << " \n Aranan hakediş dönemi bulunamadı!\n";
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

    cout << " \n\t Proje no \t Proje adı \t Firma \t Proje sorumlusu \t P. kontrolörü \n";
    //Proje dosyasının sonuna gelinmediği sürece işlemi devam ettir.
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
    cout << " \n\t Silmek istediğiniz projenin numarasını giriniz : ";
    cin.getline(proje_no_kontrol, 25);
    //Proje dosyasının sonuna gelinmediği sürece işlemi devam ettir.
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(proje_no, 25, '|');
        projeDosyasi.getline(proje_adi, 25, '|');
        projeDosyasi.getline(firma, 25, '|');
        projeDosyasi.getline(proje_sorumlusu, 25, '|');
        projeDosyasi.getline(proje_kontroloru, 25);
        // Kullanıcının girdiği sayı ile proje numarası uyuşuyorsa proje bilgilerini geçici dosyaya yaz.
        if (strcmp(proje_no, proje_no_kontrol) == 0)
        {
            geciciDosya2 << proje_no << '|' << proje_adi << '|' << firma << '|' << proje_sorumlusu << '|' << proje_kontroloru << '\n';
        }
        else // Diğer durumlarda döngünün başına dön.
        {
            continue;
        }
    }
    geciciDosya2.close();
    projeDosyasi.close();

    projeDosyasi.open("ProjeDosyasi.txt", ios::out);
    geciciDosya2.open("GeciciDosya2.txt", ios::in);
    //Geçici dosyanın sonuna gelinmediği sürece işleme devam et.
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
    cout << "\n İşlem tamamlandı! \n";
}

void hakedis_urun_ekle();

char hakedis_donemi[25];

void hakedis_ekle() {
    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::app);
    cin.ignore();
    cout << " \n Hakediş dönemi (Değeri girdikten sonra 2 kere Enter'a basınız) : ";
    cin.getline(hakedis_donemi, 25);
    projeDosyasi << "Hakediş dönemi:" << hakedis_donemi << " ";

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
    cout << " \n Aradığınız projenin numarasını giriniz : ";
    cin.ignore();
    cin.getline(proje_no_kontrol, 25);
    int aranan_proje_mi = 0; // Aranan projenin bulunup bulunmadığı, tanımlanan aranan_proje_mi integer değişkeni üzerinden kontrol edildi.
    cout << " \n\t Proje no \t Proje adı \t Firma \t\t Proje sorumlusu \t Proje kontrolörü\n";
    while (!projeDosyasi.eof())
    {
        projeDosyasi.getline(proje_no, 25, '|');
        projeDosyasi.getline(proje_adi, 25, '|');
        projeDosyasi.getline(firma, 25, '|');
        projeDosyasi.getline(proje_sorumlusu, 25, '|');
        projeDosyasi.getline(proje_kontroloru, 25);
        // Kullanıcının girdiği değer ile proje numarası uyuşuyorsa aranan proje bilgilerini ekrana yazdır.
        if (strcmp(proje_no, proje_no_kontrol) == 0)
        {
            cout << "\n   \t " << proje_no << "\t" << "\t" << proje_adi << "\t" << "\t" << firma << "\t" << "\t" << proje_sorumlusu << "\t" << "\t" << proje_kontroloru << endl;
            aranan_proje_mi = 1;
            break;
        }
    }
    if (aranan_proje_mi == 0) // Aranan ürün mevcut değilse ekrana 'Proje bulunamadı' yazdır.
    {
        cout << " \n Proje bulunamadı!\n";
    }
    projeDosyasi.close();
}

void hakedis_urun_ekle() {

    char urun_adi[25];

    fstream projeDosyasi;
    projeDosyasi.open("ProjeDosyasi.txt", ios::app);
    cin.ignore();
    cout << " \n Ürün adı: ";
    cin.getline(urun_adi, 25);
    cout << " \n Ürünün adet fiyatı(Sayı giriniz.): ";
    cin >> adet_fiyati;
    toplam_tutar += adet_fiyati;

    projeDosyasi << "Ürün adı:" << urun_adi << '|' << "Adet fiyatı:" << adet_fiyati << '\n';
    cout << "Ürün eklendi. Başka bir ürün eklemek istiyorsanız ana menüden 10. seçeneğe gidiniz.";
    projeDosyasi.close();
}

int main()
{
    setlocale(LC_ALL, "turkish"); //Türkçe karakter eklemek için.

    int cevap;

    bool ekran = true; // Konsol ekranını açık tutma veya kapatma işlemi için 'ekran' boolean değişkeni tanımlandı.
    while (ekran)
    {
        cout << " Ürün ekle : 1 \n Ürün ara : 2 \n Ürün dosyasını görüntüle : 3 \n Ürün bilgileri değiştir : 4 \n Ürün sil :  5 \n Proje ekle : 6 \n ";
        cout << "Proje ara: 7  \n Proje dosyasını görüntüle : 8 \n Proje sil : 9 \n Hakediş dönemi ara : 10 \n Hakediş dönemine ürün ekle : 11 \n Yapmak istediğiniz işlem numarasını yazınız : ";

        cin >> cevap;
        //Kullanıcı tarafından girilen değerlere göre, işlemi ilgili fonksiyonlara yönlendir.
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
            cout << " \n Yanlış numara girdiniz. \n";
        }
        cout << " Devam etmek için 'e' tuşuna, çıkmak için başka bir tuşa basınız. \n ";
        char secim;
        cin >> secim;
        //Devam etmek isterse ana menüyü tekrar göster, istemezse konsol ekranın kapat. 
        if (secim != 'e')
        {
            ekran = false;
        }
    }
    return 0;
}
