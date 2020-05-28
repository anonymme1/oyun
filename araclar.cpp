#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include <ctime>
#include <clocale>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


void Otobus() {
	string otobus[30];
	while(1) {
		int secim;
		cout<<"Hosgeldiniz."<<endl;
		cout<<"Bilet almak >> 1\nBilet iptali >> 2\nDolu koltuklari gosterme >> 3\nCikis >> 4"<<endl;
		cout<<"Secimini yap: ";
		cin>>secim;
		if(secim==1) {
			string isim;
			int koltukNo;
			cout<<"\nİsminizi girin: ";
			cin>>isim;
			cout<<"\nSececeginiz koltuk nosu: ";
			cin>>koltukNo;
			if(otobus[koltukNo]=="\0") {
				otobus[koltukNo] = isim;
				cout<<"\nKaydiniz yapildi."<<endl;
				cout<<otobus[koltukNo]<<endl;
			}
			else {
				cout<<"\nKoltuk dolu."<<endl;
				cout<<"\nKoltuk sahibi >> "<<otobus[koltukNo]<<endl;
			}
		}
		else if(secim==2) {
			cout<<"bekle";
			string isim2;
			cout<<"\nismini gir: ";
			cin>>isim2;
			for(int i=0;i<30;i++) {
				if(otobus[i]==isim2) {
					otobus[i]="\0";
				}
			}
			cout<<"\nBiletiniz iptal edilmistir."<<endl;
		}
		else if(secim==3) {
			for(int i=0;i<30;i++) {
				if(otobus[i]!="\0") {
					cout<<i<<". nolu koltuk dolu."<<endl;
				}
			}
		}
		else if(secim==4) {
			break;
		}
	}
}

class Kelime {
        public:
                string kelime,kelime2;

                void kontrol() {
                        int j=0;
                        int sayac=0;
                        int len = kelime.size();
                        for(int i=len-1;i>=0;i--,j++) {
                                kelime2[j] = kelime[i];
                        }

                        for(int i=0;i<len;i++) {
                                if(kelime2[i] == kelime[i]) {
                                        sayac++;
                                }
                        }

                        if(sayac==len) {
                                cout<<"\nPalondrim.\n";
                        }
                        else {
                                cout<<"\nPalondrim degil.\n";
                        }
                }

                void input() {
                        cout<<"\nKelime gir: ";
                        cin>>kelime;
                        kontrol();
                }

};

void Palondrik() {
	Kelime k;
	while(1) {
		k.input();
	}
}
string tersYap(string a) {
	int i=a.size()-1;
	int basla,bitir=i+1;
	string cumle2="";
	while(i>=0) {
		if(a[i]==' ') {
			basla=i+1;
			while(basla!=bitir) {
				cumle2 += a[basla++];
			}
			cumle2 += ' ';
			bitir=i;
		}
		i--;
	}
	basla=0;
	while(basla!=bitir) {
		cumle2 += a[basla++];
	}
	return cumle2;
}
void TersCevir() {
	string cumle;
	cin.ignore();
	cout<<"\nCumle gir: ";
	getline(cin, cumle);
	cout<<endl<<tersYap(cumle)<<endl;
}
void Mayin_Tarlasi() {
	cout<<"\nBu oyunda rasgele karelere yerlestirilmis mayinlar vardir.\nMayinlara basmadan en sona kadar gelirseniz oyunu kazanirsiniz.\nOyunda ilerlemek icin 1 ile 5 arasinda sayilara tiklayin bu sizin yol haritanizdir."<<endl;
	srand(time(NULL));
        int dizi[6][5]={0};
        for(int i=0;i<6;i++) {
                dizi[i][i]=0;
                dizi[i][rand()%4+0]=1;
        }
        int sayi=0;
        while(sayi<5){
                int gir;
                cout<<"\n1 ile 5 arasinda sayi girin: ";
                cin>>gir;
                if(dizi[sayi][gir]==1) {
                        cout<<"\nMayina denk geldin ve kaybettin."<<endl;
                        break;
                }
                else {
                        dizi[sayi][gir]=5;
                        sayi++;
                }
        }
        for(int i=0;i<6;i++) {
                for(int j=0;j<5;j++) {
                        cout<<dizi[i][j]<<" ";
                }
                cout<<endl;
        }
        cout<<endl;
}

void Karspektif() {
	string sayi;
        cout << "\nSayi gir: ";
        cin >> sayi;
        string bastan = "bb", sondan = "aa";
        int sayi1 = stoi(sayi);
        int karesi = sayi1 * sayi1;
        string karesi2 = to_string(karesi);
        if (karesi2.size() == 4)
        {
                bastan[0] = karesi2[0];
                bastan[1] = karesi2[1];
                sondan[0] = karesi2[2];
                sondan[1] = karesi2[3];
                int bastan1 = stoi(bastan);
                int sondan1 = stoi(sondan);
                int sonuc = bastan1 + sondan1;
                if (sonuc == sayi1)
                {
                        cout << "Karspektif." << sonuc << endl;
                }
                else
                {
                        cout << "Karspektif degil." << sonuc << endl;
                }
        }
        else if (karesi2.size() == 5)
        {
                bastan[0] = karesi2[0];
                bastan[1] = karesi2[1];
                sondan[0] = karesi2[3];
                sondan[0] = karesi2[4];
                int bastan1 = stoi(bastan);
                int sondan1 = stoi(sondan);
                int sonuc = bastan1 + sondan1;
                if (sonuc == sayi1)
                {
                        cout << "Karspektif." << sonuc << endl;
                }
                else
                {
                        cout << "Karspektif degil." << sonuc << endl;
                }
        }
        else
        {
                cout <<
                        "\nSayinin karesinin basamak sayisi 4 ten kucuk veya 5 ten buyuk oldugu icin kontrol edilemiyor."
                        << endl;
        }
}
void Secim() {
	cout<<"<<<HOSGELDİM>>>"<<endl;
	cout<<"\n1.Ascii tablosu \n2.Rar sifre kirma \n3.Zip okuma \n4.Vector ile personel \n5.Dosya okuma(satir) \n6.Dosya ile personel \n7.Cumle icinde harf bulma \n8.Cumle icinde kelime bulma \n9.Wifi sifre bulma \n10.Pacman oyunu \n11.Craps oyunu \n12.Sayi tahmin oyunu \n13.Karspektif sayi bulma\n14.Mayin tarlasi oyunu\n15.Cumleyi tersten yazma\n16.Palondrik kelime bulma\n17. 8 vezir Problemi\n\n18.Otobus bileti simulasyonu\n19.EXİT"<<endl;
}
/*
void Pacman() {
	struct Pacman {
	        string renk=sari;
        	int puan=0;
        	int can=2;
	}p;

	struct Yem {
       		 int yemPuan[10]={0};
        	// 10 tane yem icinde 2 tane can alici sayi var o sayi 5 olacak
	}y;

	void yemler() {
       		 srand(time(NULL));
        	 y.yemPuan[0]=rand()%10+20;
       		 y.yemPuan[1]=rand()%10+20;
       		 y.yemPuan[2]=2;
        	 y.yemPuan[3]=3;
        	 for(int i=4;i<10;i++) {
              		  y.yemPuan[i]=rand()%10+20;
      		  }
	}

	void oyun() {
        	for(int i=0;i<10;i++) {
               		 if(y.yemPuan[i]==3||y.yemPuan[i]==2) {
                        	p.can--;
                	}
                	else {
                        	p.puan += y.yemPuan[i];
                	}
        	}
        	if(p.can==0) {
                	cout<<"\nCaniniz kalmadi."<<endl;
                	cout<<"\nPuan >> "<<p.puan<<endl;
                	exit(1);
        	}
        	else {
                	cout<<"\nPuaniniz >> "<<p.puan<<endl;
        	}
	}


        while(1) {
                yemler();
                oyun();
                if(p.can==0) {
                        break;
                }
        }
}
*/
void Sayitahmin() {
	int hak=0;
	string gizliSayi;
	cout<<"\nGizli sayiyi gir: ";
	cin>>gizliSayi;
	while(1) {
		hak++;
		if(hak==4){
			cout<<"\nTahmin hakkin bitti.Kaybettin."<<endl;
			break;
		}
		else {
			string sayiTahmin;
			cout<<"\nTahminini gir: ";
			cin>>sayiTahmin;
			if(sayiTahmin==gizliSayi) {
				cout<<"\nTebrikler gizli sayiyi buldun."<<endl;
				break;
			}
			else {
				cout<<"\nTahminin yanlis."<<endl;
			}
		}
	}
}

void Craps() {
	unsigned int hak=0;
        int toplam=0;
        string zar;
        double skorum=0;
        while(hak<10) {
                hak++;
                cout<<"\nZar at >> "<<endl;
                cin>>zar;
                if(zar=="e") {
                        int zar1=0;
                        int zar2=0;
                        zar1 += rand()%6+1;
                        zar2 += rand()%6+1;
                        cout<<zar1<<" "<<zar2<<endl;
                        toplam = zar1+zar2;
                        if(toplam==7||toplam==11) {
                                cout<<"\n\e[32mTebrikler kazandin."<<endl;
                                skorum++;
                        }
                        if(toplam==12||toplam==2||toplam==3) {
                                cout<<"\n\e[91mKaybettin."<<endl;
                        }
                        else {
                                cout<<"\n\e[33mZari tekrar at."<<endl;
                                continue;
                        }
                }
                else {
                        cout<<"\n\e[31mOyundan cikildi."<<endl;
                        break;
                }
        }
        cout<<"\n\e[97mKazanma olasiligin >> "<<skorum/10<<endl;
}

void Wifi() {
	cout<<"\nWindows icin >> 1"<<endl;
        cout<<"\nLinux   icin >> 2"<<endl;
        string secim;
        cout<<"\nSecmek istedigin platform?: ";
        cin>>secim;
        if(secim=="1") {
                cout<<"\n\tCihazda kayitli wifi aglari : "<<endl;
                system("netsh wlan show profiles");
                string kayit;
                cout<<"\n\tSifresini gormek istedigin agin adini yaz: ";
                cin>>kayit;
                char komut[100];
                int ek;
                ek = sprintf(komut,"netsh wlan show profiles %s keyclear",kayit.c_str());
                system(komut);
        }
        else {
                cout<<"\nLinux icin olani yapim asamasinda"<<endl;
        }
}


void Harf() {
	string cumle;
	fflush(stdin);
	cout<<"\nCumle yaz: ";
	cin.ignore();
	getline(cin, cumle);
	char harf;
	cout<<"\nArayacagin harfi gir: ";
	cin>>harf;
	int sayac=0;
	for(int i=0;i<cumle.size();i++) {
		if(cumle[i]==harf) {
			sayac++;
		}
	}
	cout<<"\nAradigin harf cumle icinde "<<sayac<<" tanedir."<<endl;
}

void Kelime() {
	string cumle;
	cin.ignore();
	cout<<"\nCumle yaz: ";
	getline(cin,cumle);
	int sayac=0;
	for(int i=0;i<cumle.size();i++) {
		if(cumle[i]==' ') {
			sayac++;
		}
	}
	cout<<"\nCumle icinde "<<sayac<<" tane kelime vardir."<<endl;
}




void Personeld() {
	struct Personel {
      	        string ad,soyad;
    	        int gider;
   	        int id;
    	        string strid;
        	string strgider;
	};
	/*
        time_t zaman;
        time(&zaman);
        cout<<"\n\t<<HOŞGELDİNİZ>>\n"<<endl;
        cout<<"\n\tTarih: "<<asctime(localtime(&zaman))<<endl;
        cout<<"\n\tPersonel Ekleme    >> 1"<<endl;
        cout<<"\n\tPersonel Çikarma   >> 2"<<endl;
        cout<<"\n\tPersonel Düzenleme >> 3"<<endl;
        cout<<"\n\tToplam Personel S. >> 4"<<endl;
        cout<<"\n\tToplam Aylik Gider >> 5"<<endl;
        cout<<"\n\tPersonel bilgisi:  >> 6"<<endl;
        cout<<"\n\tProgramdan cikmak icin 7 e basin,"<<endl; */
        Personel p;
        setlocale(LC_ALL,"turkish");
        ofstream person;
        person.open("personel.txt");
        int sayac=0;
        while(1) {
                time_t zaman;
                time(&zaman);
                cout<<"\n\t<<HOŞGELDİNİZ>>\n"<<endl;
                cout<<"\n\tTarih: "<<asctime(localtime(&zaman))<<endl;            
		cout<<"\n\tPersonel Ekleme    >> 1"<<endl;
       	        cout<<"\n\tPersonel Çikarma   >> 2"<<endl;                        cout<<"\n\tPersonel Düzenleme >> 3"<<endl;                        cout<<"\n\tToplam Personel S. >> 4"<<endl;                        cout<<"\n\tToplam Aylik Gider >> 5"<<endl;                        cout<<"\n\tPersonel bilgisi:  >> 6"<<endl;                        cout<<"\n\tProgramdan cikmak icin 7 e basin,"<<endl;
                string islem;
                cout<<"\n\n\tYapacağınız işlemi seçin: ";
                cin>>islem;
                if(islem=="1"){ // personel ekleme
                        sayac++;
                        //ofstream person;
                        //person.open("personel.txt");
                        person<<sayac<<". Personel : "<<endl;
                        cout<<"\n\tİsim gir: ";
                        cin>>p.ad;
                        person<<"\tİsim = "<<p.ad<<endl;
                        cout<<"\n\tSoyisim gir: ";
                        cin>>p.soyad;
                        person<<"\tSoyisim = "<<p.soyad<<endl;
                        cout<<"\n\tAylik gider gir: ";
                        cin>>p.strgider;
                        p.gider = stoi(p.strgider);
                        person<<"\tGider = "<<p.gider<<endl;
                        cout<<"\n\tİd gir: ";
                        cin>>p.strid;
                        p.id = stoi(p.strid);
                        person<<"\tİd = "<<p.id<<endl;
                        cout<<"\n\tKayit tamamlandi."<<endl;
                        cout<<"\n\tBilgiler 'personel.txt' dosyasina kaydedildi."<<endl;
                        //person.close();
                }
                else if(islem=="2"){ // personel cikarma
                        cout<<"bekle"<<endl;
                        cout<<"\n\tAnamenuye dönülüyo Lütfen bekleyin..."<<endl;
                        sleep(3);
                }
                else if(islem=="3"){ // personel duzenleme
                        cout<<"\n\tYapim asamasinda."<<endl;
                        cout<<"\n\tAnamenuye yonlendiriliyo..."<<endl;
                        cout<<"\n\tLütfen 3 sn. bekleyin..."<<endl;
                        sleep(3);
                        continue;
                }
                else if(islem=="4"){ // toplam personel sayisi
                        ifstream personoku("personel.txt");
                        string satir;
                        int sayi=0;
                        while(!personoku.eof()&&!personoku.fail()){ // dosya okuma
                                getline(personoku,satir);
                                sayi++;
                        }
                        int sonuc;
                        sonuc = sayi / 5;
                        cout<<"\n\tToplam personel sayisi: "<<sonuc<<endl;
                        cout<<"\n\tAnamenuye dönülüyo Lütfen bekleyin..."<<endl;
                        sleep(3);
                }
                else if(islem=="5"){ // toplam aylik gider
                        char komut[100];
                        int ek;
                        ek = sprintf(komut,"grep Gider personel.txt");
                        system(komut);
                        cout<<"\n\tAnamenuye dönülüyor Lütfen bekleyin..."<<endl;
                        sleep(3);
                }
                else if(islem=="6"){ // personel gosterme
                        ifstream personoku("personel.txt");
                        string satir;
                        while(getline(personoku,satir)){ // dosya okuma
                                cout<<satir<<endl;
                        }
                        cout<<"\n\tAnamenuye dönülüyor Lütfen bekleyin..."<<endl;
                        sleep(3);
                }
                else if(islem=="7"){ // cikis
                        person.close();
                        cout<<"\n\tProgramdan cikiliyor..."<<endl;
                        break;
                }
                else { // yanlis girilen
                        cout<<"\n\tYanlış seçim.Lütfen tekrar deneyin..."<<endl;
                        sleep(2);
                }
        }
        person.close();
}

void Dosyas() {
	cin.ignore();
	string dosyaAdi;
	cout<<"\nOkuyacagin dosyanin adini gir: ";
	cin>>dosyaAdi;
	ifstream dosyaoku(dosyaAdi);
	string satir="";
	if(dosyaoku.is_open()) {
		int sayac=0;
		while(getline(dosyaoku,satir)) {
			sayac++;
			cout<<sayac<<". satir >> "<<satir<<endl;
		}
	}
	dosyaoku.close();
}

void Ascii() {
	char karakter;
        cout<<"\nKarakter gir(yalnizca tek karakter girin): ";
        cin>>karakter;
        if(karakter=='a') {
                cout<<"\nDecimal  >> 97 "<<endl;
                cout<<"Hexdecimal >> 0x61 "<<endl;
                cout<<"Octav      >> 0142 "<<endl;
        }
        else if(karakter=='b') {
                cout<<"\nDecimal  >> 98 "<<endl;
                cout<<"Hexdecimal >> 0x62 "<<endl;
                cout<<"Octav      >> 0142 "<<endl;
        }
        else if(karakter=='c') {
                cout<<"\nDecimal  >> 99 "<<endl;
                cout<<"Hexdecimal >> 0x63 "<<endl;
                cout<<"Octav      >> 0143 "<<endl;
        }
        else if(karakter=='d') {
                cout<<"\nDecimal  >> 100 "<<endl;
                cout<<"Hexdecimal >> 0x64 "<<endl;
                cout<<"Octav      >> 0144 "<<endl;
        }
        else if(karakter=='e') {
                cout<<"\nDecimal  >> 101 "<<endl;
                cout<<"Hexdecimal >> 0x65 "<<endl;
                cout<<"Octav      >> 0145 "<<endl;
        }
        else if(karakter=='f') {
                cout<<"\nDecimal  >> 102 "<<endl;
                cout<<"Hexdecimal >> 0x66 "<<endl;
                cout<<"Octav      >> 0146 "<<endl;
        }
        else if(karakter=='g') {
                cout<<"\nDecimal  >> 103 "<<endl;
                cout<<"Hexdecimal >> 0x67 "<<endl;
                cout<<"Octav      >> 0147 "<<endl;
        }
        else if(karakter=='h') {
                cout<<"\nDecimal  >> 104 "<<endl;
                cout<<"Hexdecimal >> 0x68 "<<endl;
                cout<<"Octav      >> 0150 "<<endl;
        }
        else if(karakter=='i') {
                cout<<"\nDecimal  >> 105 "<<endl;
                cout<<"Hexdecimal >> 0x69 "<<endl;
                cout<<"Octav      >> 0151 "<<endl;
        }
        else if(karakter=='j') {
                cout<<"\nDecimal  >> 106 "<<endl;
                cout<<"Hexdecimal >> 0x6a "<<endl;
                cout<<"Octav      >> 0152 "<<endl;
        }
        else if(karakter=='k') {
                cout<<"\nDecimal  >> 107 "<<endl;
                cout<<"Hexdecimal >> 0x6b "<<endl;
                cout<<"Octav      >> 0153 "<<endl;
        }
        else if(karakter=='l') {
                cout<<"\nDecimal  >> 108 "<<endl;
                cout<<"Hexdecimal >> 0x6c "<<endl;
                cout<<"Octav      >> 0154 "<<endl;
        }
        else if(karakter=='m') {
                cout<<"\nDecimal  >> 109 "<<endl;
                cout<<"Hexdecimal >> 0x6d "<<endl;
                cout<<"Octav      >> 0155 "<<endl;
        }
        else if(karakter=='n') {
                cout<<"\nDecimal  >> 110 "<<endl;
                cout<<"Hexdecimal >> 0x6e "<<endl;
                cout<<"Octav      >> 0156 "<<endl;
        }
        else if(karakter=='o') {
                cout<<"\nDecimal  >> 111 "<<endl;
                cout<<"Hexdecimal >> 0x6f "<<endl;
                cout<<"Octav      >> 0157 "<<endl;
        }
        else if(karakter=='p') {
                cout<<"\nDecimal  >> 112 "<<endl;
                cout<<"Hexdecimal >> 0x70 "<<endl;
                cout<<"Octav      >> 0160 "<<endl;
        }
        else if(karakter=='q') {
                cout<<"\nDecimal  >> 113 "<<endl;
                cout<<"Hexdecimal >> 0x71 "<<endl;
                cout<<"Octav      >> 0161 "<<endl;
        }
        else if(karakter=='r') {
                cout<<"\nDecimal  >> 114 "<<endl;
                cout<<"Hexdecimal >> 0x72 "<<endl;
                cout<<"Octav      >> 0162 "<<endl;
        }
        else if(karakter=='s') {
                cout<<"\nDecimal  >> 115 "<<endl;
                cout<<"Hexdecimal >> 0x73 "<<endl;
                cout<<"Octav      >> 0163 "<<endl;
        }
        else if(karakter=='t') {
                cout<<"\nDecimal  >> 116 "<<endl;
                cout<<"Hexdecimal >> 0x74 "<<endl;
                cout<<"Octav      >> 0164 "<<endl;
        }
        else if(karakter=='u') {
                cout<<"\nDecimal  >> 117 "<<endl;
                cout<<"Hexdecimal >> 0x75 "<<endl;
                cout<<"Octav      >> 0165 "<<endl;
        }
        else if(karakter=='v') {
                cout<<"\nDecimal  >> 118 "<<endl;
                cout<<"Hexdecimal >> 0x76 "<<endl;
                cout<<"Octav      >> 0166 "<<endl;
        }
        else if(karakter=='w') {
                cout<<"\nDecimal  >> 119 "<<endl;
                cout<<"Hexdecimal >> 0x77 "<<endl;
                cout<<"Octav      >> 0167 "<<endl;
        }
        else if(karakter=='x') {
                cout<<"\nDecimal  >> 120 "<<endl;
                cout<<"Hexdecimal >> 0x78 "<<endl;
                cout<<"Octav      >> 0170 "<<endl;
        }
        else if(karakter=='y') {
                cout<<"\nDecimal  >> 121 "<<endl;
                cout<<"Hexdecimal >> 0x79 "<<endl;
                cout<<"Octav      >> 0171 "<<endl;
        }
        else if(karakter=='z') {
                cout<<"\nDecimal  >> 122 "<<endl;
                cout<<"Hexdecimal >> 0x7a "<<endl;
                cout<<"Octav      >> 0172 "<<endl;
        }
        else if(karakter=='0') {
                cout<<"\nDecimal  >> 48 "<<endl;
                cout<<"Hexdecimal >> 0x30 "<<endl;
                cout<<"Octav      >> 0060 "<<endl;
        }
        else if(karakter=='1') {
                cout<<"\nDecimal  >> 49 "<<endl;
                cout<<"Hexdecimal >> 0x31 "<<endl;
                cout<<"Octav      >> 0061 "<<endl;
        }
        else if(karakter=='2') {
                cout<<"\nDecimal    >> 50 "<<endl;
                cout<<"Hexdecimal >> 0x32 "<<endl;
                cout<<"Octav      >> 0062 "<<endl;
        }
        else if(karakter=='3') {
                cout<<"\nDecimal    >> 51 "<<endl;
                cout<<"Hexdecimal >> 0x33 "<<endl;
                cout<<"Octav      >> 0063 "<<endl;
        }
        else if(karakter=='4') {
                cout<<"\nDecimal    >> 52 "<<endl;
                cout<<"Hexdecimal >> 0x34 "<<endl;
                cout<<"Octav      >> 0064 "<<endl;
        }
        else if(karakter=='5') {
                cout<<"\nDecimal    >> 53 "<<endl;
                cout<<"Hexdecimal >> 0x35 "<<endl;
                cout<<"Octav      >> 0065 "<<endl;
        }
        else if(karakter=='6') {
                cout<<"\nDecimal    >> 54 "<<endl;
                cout<<"Hexdecimal >> 0x36 "<<endl;
                cout<<"Octav      >> 0066 "<<endl;
        }
        else if(karakter=='7') {
                cout<<"\nDecimal    >> 55 "<<endl;
                cout<<"Hexdecimal >> 0x37 "<<endl;
                cout<<"Octav      >> 0067 "<<endl;
        }
        else if(karakter=='8') {
                cout<<"\nDecimal    >> 56 "<<endl;
                cout<<"Hexdecimal >> 0x38 "<<endl;
                cout<<"Octav      >> 0070 "<<endl;
        }
        else if(karakter=='9') {
                cout<<"\nDecimal    >> 57 "<<endl;
                cout<<"Hexdecimal >> 0x39 "<<endl;
                cout<<"Octav      >> 0071 "<<endl;
        }
        else if(karakter=='.') {
                cout<<"\nDecimal    >> 46 "<<endl;
                cout<<"Hexdecimal >> 0x2e "<<endl;
                cout<<"Octav      >> 0056 "<<endl;
        }
        else if(karakter==' ') {
                cout<<"\nDecimal    >> 32 "<<endl;
                cout<<"Hexdecimal >> 0x20 "<<endl;
                cout<<"Octav      >> 0040 "<<endl;
        }
        else {
                cout<<"\nKarakterin bilgisayardaki dili bulunamadi."<<endl;
        }
}

void Rar() {
	string dosyaAdi;
	cin.ignore();
	cout<<"\nKiracagin dosyanin adini gir: ";
	cin>>dosyaAdi;
	string dizi="1234567890poiuytreasdfghjklmnbvcxzqw";
	int denemeSayisi,kacKarakter;
	cout<<"\nKac kez denensin: ";
	cin>>denemeSayisi;
	cout<<"\nKac karakterli sifre olsun: ";
	cin>>kacKarakter;
	char komut[100];
	int ek;
	for(int i=0;i<denemeSayisi;i++) {
		string sifre;
		for(int j=0;j<kacKarakter;j++) {
			sifre += dizi[rand()%dizi.size()];
		}
		ek = sprintf(komut,"unrar e -p%s %s",sifre.c_str(),dosyaAdi.c_str());
		int a = system(komut);
		if(a==EXIT_SUCCESS) {
			cout<<"\nDogru sifre >> "<<sifre<<endl;
			break;
		}
		else {
			cout<<"\nSifre yanlis >> "<<sifre<<endl;
		}
	}
}

int Zip() {
	string dosyaAdi;
	cin.ignore();
	cout<<"\nOkuyacagin dosyanin adini yaz : ";
	cin>>dosyaAdi;
	ifstream dosyaoku(dosyaAdi,ios::binary);
	do{
                char veri[5]={0};
                unsigned int dosyaboyut=0;
                unsigned short len=0, extlen=0;
                dosyaoku.read(veri,4);
                if(dosyaoku.fail()||dosyaoku.eof())
                        break;
                if((veri[0]!='P')||(veri[1]!='K')||(veri[2]!=3)||(veri[3]!=4))
                        break;
                dosyaoku.seekg(14,std::ios::cur);
                dosyaoku.read((char *)&dosyaboyut,4);
                cout<<"Sıkışmış dosya boyutu = "<<dosyaboyut<<endl;
                dosyaoku.seekg(4,std::ios::cur);
                dosyaoku.read((char *)&len,2);
               /* cout<<"Dosya ismi uzunluğu = "<<len<<endl;*/
                dosyaoku.read((char *)&extlen,2);
               /* cout<<"Extra bilgi uzunluğu = "<<extlen<<endl;*/
                char * filename=new char[len+1];
                dosyaoku.read(filename,len);
                filename[len]=0;
                cout<<"Dosya ismi = "<<filename<<endl;
                delete[] filename;
                dosyaoku.seekg(extlen+dosyaboyut,std::ios::cur);
        }while(1);
        return EXIT_SUCCESS;
}

void Personelv() {
	struct Personel {
        	string ad;
       	 	string soyad;
        	int id;
        	double gider;
	};
/*void anamenu() {                                                          time_t zaman;
        time(&zaman);
        cout<<"\n\t<<HOŞGELDİNİZ>>\n"<<endl;
        cout<<"\n\tTarih: "<<asctime(localtime(&zaman))<<endl;
        cout<<"\n\tPersonel Ekleme    >> 1"<<endl;
        cout<<"\n\tPersonel Çikarma   >> 2"<<endl;
        cout<<"\n\tPersonel Düzenleme >> 3"<<endl;
        cout<<"\n\tToplam Personel S. >> 4"<<endl;
        cout<<"\n\tToplam Aylik Gider >> 5"<<endl;
        cout<<"\n\tPersonel bilgisi:  >> 6"<<endl;
}*/
	vector<Personel>personeller;
	Personel p;
        setlocale(LC_ALL,"turkish");
        while(1) {
   		//time(&zaman);                                                     cout<<"\n\t<<HOŞGELDİNİZ>>\n"<<endl;
        	//cout<<"\n\tTarih: "<<asctime(localtime(&zaman))<<endl;
	        cout<<"\n\tPersonel Ekleme    >> 1"<<endl;
		cout<<"\n\tPersonel Çikarma   >> 2"<<endl;
        	cout<<"\n\tPersonel Düzenleme >> 3"<<endl;
		cout<<"\n\tToplam Personel S. >> 4"<<endl;
       	 	cout<<"\n\tToplam Aylik Gider >> 5"<<endl;
		cout<<"\n\tPersonel bilgisi:  >> 6"<<endl;
		cout<<"\n\tCikis              >> 7"<<endl;
                int islem;
                cout<<"\n\tYapicaginiz islemi secin: ";
                cin>>islem;
                if(islem==1){ // personel ekleme
                        cout<<"\n\tİsim gir: ";
                        cin>>p.ad;
                        cout<<"\n\tSoyisim gir: ";
                        cin>>p.soyad;
                        try {
                                cout<<"\n\tAylik gider gir: ";
                                cin>>p.gider;
                                cout<<"\n\tİd gir: ";
                                cin>>p.id;
                        }
                        catch(...) {
                                cout<<"\n\tLütfen sadece rakam girin."<<endl;
                        }
                        personeller.push_back(p);
                        cout<<"\n\tKayit Eklendi."<<endl;
                }
                else if(islem==2){ // personel cikarma
                        int id;
                        for(int i=0;i<personeller.size();i++){
                                cout<<i+1<<". Personel: "<<personeller[i].id<<endl;
                        }
                        try {
                                cout<<"\n\tCikarmak istediginiz personelin id sini girin: ";
                                cin>>id;
                        }
                        catch(...) {
                                cout<<"\n\tLütfen sadece rakam girin."<<endl;
                        }
                        for(int i=0;i<personeller.size();i++){
                                if(personeller[i].id==id){
                                        personeller.erase(personeller.begin()+i);
                                        cout<<id<<" nolu Personel cikarildi."<<endl;
                                        break;
                                }
                        }
                }
                else if(islem==3){ // personel duzenleme
                        cout<<"\n\tYapim asamasinda."<<endl;
                        cout<<"\n\tAnamenuye donuluyor..."<<endl;
                        cout<<"\n\tLütfen 3 sn. bekleyin..."<<endl;
                        sleep(3);
                        continue;
                }
                else if(islem==4){ // toplam personel
                        cout<<"\n\tToplam personel sayisi: "<<personeller.size()<<endl;
                }
                else if(islem==5){ // toplam aylik gider
                        int toplam;
                        for(int i=0;i<personeller.size();i++){
                                toplam += personeller[i].gider;
                        }
                        cout<<"\n\tToplam aylik gider: "<<toplam<<endl;
                }
                else if(islem==6){ // personel bilgisi gosterme
                        for(int i=0;i<personeller.size();i++){
                                cout<<i+1<<". Personel: "<<endl;
                                cout<<"\tİsim: "<<personeller[i].ad<<endl;
                                cout<<"\tSoyisim: "<<personeller[i].soyad<<endl;
                                cout<<"\tAylik gider: "<<personeller[i].gider<<endl;
                                cout<<"\tİd: "<<personeller[i].id<<endl;
                        }
                }
		else {
			break;
		}
        }
}
int main() {
	setlocale(LC_ALL,"turkish");
	srand(time(NULL));
	int secim;
	while(1) {
		Secim();
		cout<<"\nSecimini yaz : ";
		cin>>secim;
		switch(secim) {
			case 1:
				system("clear");
				Ascii();
				break;
			case 2:
				system("clear");
				Rar();
				break;
			case 3:
				system("clear");
				Zip();
				break;
			case 4:
				system("clear");
				Personelv();
				break;
			case 5:
				system("clear");
				Dosyas();
				break;
			case 6:
				system("clear");
				Personeld();
				break;
			case 7:
				system("clear");
				Harf();
				break;
			case 8:
				system("clear");
				Kelime();
				break;
			case 9:
				system("clear");
				Wifi();
				break;
			case 10:
				system("clear");
				//Pacman();
				cout<<"\nYapim asamasinda :) "<<endl;
				break;
			case 11:
				system("clear");
				Craps();
				break;
			case 12:
				system("clear");
				Sayitahmin();
				break;
			case 13:
				system("clear");
				Karspektif();
				break;
			case 14:
				system("clear");
				Mayin_Tarlasi();
				break;
			case 15:
				system("clear");
				TersCevir();
				break;
			case 16:
				system("clear");
				Palondrik();
				break;
			case 17:
				system("clear");
				//Vezirler();
				cout<<"\nYapim asamasinda."<<endl;
				break;
			case 18:
				system("clear");
				Otobus();
				break;
			case 19:
				exit(1);
				break;
			default:
				cout<<"\nAradigin islem bulunamadi."<<endl;
				continue;
		}
	}
}
