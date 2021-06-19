#include<bits/stdc++.h>
#include<fstream>
#include<ctime>
using namespace std;

class monacemebi{
	public:
		double balansi;
		int sms;
		int mb;
	};
// global infomation
monacemebi info; 
int number; 

void damateba(){
	info.balansi = 0;
	info.sms = 0;
	info.mb = 0;
}

void dablokva(){
	info.balansi = 0;
	info.sms = 0;
	info.mb = 0;
	ofstream outfile;
	outfile.open("blocklist.txt");
	outfile << number;
	outfile.close();
}

void ganblokva(){
	ofstream outfile;
	outfile.open("blocklist.txt", std::ofstream::out | std::ofstream::trunc); // es movidzie infos shlis;
	outfile.close();
	info.balansi = 0;
	info.mb = 0;
	info.sms = 0;
}

void washla(){
	ofstream outfile;
	outfile.open("NomrisBaza" ,std::ofstream::out | std::ofstream::trunc);
	outfile.close();
}

void dasruleba(){
	exit;
}

void PirveliNawili(){

    ofstream outfile;
    outfile.open("NomrisBaza");
    outfile << number;
    outfile.close();
    
	printf("1.damateba \n");
	printf("2.dablokva \n");
	printf("3.ganblokva \n");
	printf("4.washla \n");
	printf("5.EXIT \n");
	
	
	int choice;cin >> choice;
	if(choice == 1){
		damateba();
	}else if(choice == 2){
		dablokva();
	}else if(choice == 3){
		ganblokva();
	}else if(choice == 4){
		washla();
	}else if(choice == 5){
		dasruleba();
	}
}

void Specialuri(){
	int choice;cin >> choice;
	if(choice == 0){
		exit;
	}else if(choice == 1 && info.balansi >= 0.1){
		int ChemiCifri;cin >> ChemiCifri;
		int random; cin >> random;
		if(random == ChemiCifri){
			info.mb = 100;
		}
	}
}

void ChemiMonacemebi(){
	cout << info.balansi << endl;
	cout << info.mb << endl;
	cout << info.sms << endl;
}

void YvelaferiMaxi(){
	int girebuleba = 25;
	int choice; cin >> choice;
	if (choice == 1 && info.balansi >= girebuleba){
		info.balansi = info.balansi - girebuleba;
		info.mb = 999;
		info.sms = 999; // usasruloba vigulisxme 
	}else{
		printf("ar gaqvt balansze sakmarisi tanza \n");
	}
}

void InternetPaketebi(){
	printf("1.2GB+gamis ulimito interneti - 7lari \n");
	printf("2.4GB + gamis ulimito interneti - 11lari \n");
	printf("3.10GB + gamis ulimito interneti - 17lari \n");
	printf("4.30GB + gamis ulimito interneti - 30lari \n");
	printf("0.ukan");
	int choice;cin >> choice;
	if(choice == 1 && info.balansi >= 7){
		info.balansi = info.balansi - 7;
		info.mb = 2000;
	}else if(choice == 2 && info.balansi >= 11){
		info.balansi = info.balansi - 11;
		info.mb = 4000;
	}else if(choice == 3 && info.balansi >= 17){
		info.balansi = info.balansi - 17;
		info.mb = 10000;
	}else if(choice == 4 && info.balansi >= 30){
		info.balansi = info.balansi - 30;
		info.mb = 30000;
	}else{
		exit;
	}
}

void SxvaPaketebi(){
	printf("1.500 sms \n");
	printf("Fasi 1.5 Lari \n");
	printf("Vada - 7 dge");
	printf("0.ukan \n");
	printf("0.0 Mtavari menu \n");
	int choice;cin >> choice;
	if(choice == 1 && info.balansi >= 1.5){
		info.balansi = info.balansi - 1.5;
		info.sms = 500;
		time_t now = time(0);
        string dt = ctime(&now);// au aq ver mivxvdi rogor xdeba da ubralod gadmovakopire tqveni kodi
        cout << dt << endl;
	}else{
		exit;
	}
}

void Saertashoriso(){
	printf("America da Canada 5 Tetri \n");
	printf("Evropa,Azia,DST da centr,aziis rigi qveknebi 38 tetri \n");
	printf("Zaris camockeba 10 tetri \n");
	printf("Fasi 1 lari, Vada 1 tve \n");
	printf("1.aqtivacia \n");
	printf("0.ukan \n");
	
	int choice;cin >> choice;
	if(choice == 1 && info.balansi >= 1){
		info.balansi = info.balansi - 1;
		printf("service activated \n");
	}else{
		exit;
	}
}

void BeelineCredit(){
	if(info.balansi <= 0){
		info.balansi += 2.6;
	}
	time_t now = time(0);
    string dt = ctime(&now);
    cout << dt << endl;
    info.balansi -= 3;
}

void MeoreNawili(){
	printf("1.specialuri shetavazebebi \n");
	printf("2.chemi monacemebi \n");
	printf("3.tarifi yvelaferi maxi \n");
	printf("4.internet paketebi \n");
	printf("5.Sxva paketebi \n");
	printf("6.Saertashoriso zarebi \n");
	printf("7.Beeline krediti \n");
	
	int choice;cin >> choice;
	if(choice == 1){
		Specialuri();
	}else if(choice == 2){
		ChemiMonacemebi();
	}else if(choice == 3){
		YvelaferiMaxi();
	}else if(choice == 4){
		InternetPaketebi();
	}else if(choice == 5){
		SxvaPaketebi();
	}else if(choice == 6){
		Saertashoriso();
	}else if(choice == 7){
		BeelineCredit();
	}
	
	if(info.balansi < 0){
     time_t now = time(0);
     string dt = ctime(&now);
     cout << dt << endl;
     
     ofstream outfile;
     outfile.open("blocklist");
     outfile << number;
     outfile.close();
     info.balansi = 0;
     info.mb = 0;
     info.sms = 0;
	}
}

void solution(){
	PirveliNawili();
	MeoreNawili();
}

int main(int number){
	solution();
}
