#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>
#include <direct.h>
using namespace std;

void savekrediti(string filename,map<string,int> krediti){
    ofstream outfile;
    outfile.open(filename.c_str());
    for(auto it = krediti.begin();it!= krediti.end();it++){
        outfile << it->first << "\n" << it->second << endl;
    }
    outfile.close();
}

void saveblacklist(string filename,map<string,bool>blacklist ){
    ofstream outfile;
    outfile.open(filename.c_str());
    for(auto it = blacklist.begin();it != blacklist.end();it++){
        outfile << it->first << "\n" << it->second << endl;
    }
    outfile.close();
}

map<string,int> readkrediti(string filename,map<string,int> krediti){
    ifstream infile;
    infile.open(filename.c_str());
    if(infile.fail()){
        return krediti;
    }
    string s;
    string key;
    int n;
    while(infile >> s){
        if(n %2 != 0){
            key = s;
        }else{
            krediti[key] = stoi(s);
        }
        n++;
    }
    infile.close();
    return krediti;
}

map<string,bool> readblacklist(string filename,map<string,bool> blacklist){
    ifstream infile;
    infile.open(filename.c_str());
    map<string,bool> v;
    if(infile.fail()){
        return v;
    }
    string s;
    string key;
    int cnt = 1;
    while(infile >> s){
        if(cnt % 2 != 0){
            key = s;
        }else{
            blacklist[key] = stoi(s);
        }
        cnt++;
    }
    infile.close();
    return blacklist;

}
void createtxtfile (string filename){
	ofstream outfile (filename.c_str());
	outfile.close();
}

void createneededfiles(string filename){
    string s = filename;
    mkdir(filename.c_str());
    s = filename +"\\" + "baza.txt" ;
    createtxtfile(s);
    s = filename + "\\" +"krediti.txt";
    createtxtfile(s);
    s = filename + "\\" + "blacklist.txt";
    createtxtfile(s);
    s = filename + "\\" + "uaryofiti.txt";
    createtxtfile(s);
    s = filename + "\\" + "shavisia.txt";
    createtxtfile(s);
    return;
}

void printsspaketi (){
    cout << "1.500sms" << endl;
    cout << "fasi 1.5lari" << endl;
    cout << " vada-7dge" << endl;
    return;
}
void printspaketi(){
    cout << "saertashoriso zarebis aqtivacia" << endl;
    cout << "fasi 1 lari vada 1 tve" << endl;
    return;
}
void printipaketi(){
    cout << "1.2gb + gamis ulimito-7lari" << endl;
    cout << "2.4gb + gamis ulimito-11lari" << endl;
    cout << "3.10gb + gamis ulimito -17" << endl;
    cout << "4.30gb + gamis ulimito-30 lari" << endl;
    cout << "0 ukan dabruneba" << endl;
    cout << "00 mtabar gverdze dabruneba" << endl;
}

class damxmare{
    public:
    damxmare(){
        mb = 0;
        balansi = 0;
        wutebi = 0;
        sms = 0;
        tarifi = "nothing";
    }
    void setbalansi(int amount){
        balansi = amount;
        return;
    }
    void setmb(int n){
        mb = n;
        return;
    }
    void setsms(int n){
        sms = n;
        return;
    }
    void setwutebi(int n){
        wutebi = n;
        return;
    }
    void chbalansi(int amount){
        balansi + amount;
        return;
    }
    void chtarifi(string j){
        tarifi = j;
        return;
    }
    void chsms(int amount){
        sms + amount;
        return;
    }
    void chmb(int amount){
        mb + amount;
        return;
    }
    double balansig(){
        return balansi;
    }
    int mbg(){
        return mb;
    }
    int smsg(){
        return sms;
    }
    string tarifig(){
        return tarifi;
    }
    int wutebig(){
        return wutebi;
    }

    private:
    double balansi;
    int mb;
    int sms;
    int wutebi;
    string tarifi;

};

void savebaza(string filename,map<string,damxmare> baza ){
    ofstream outfile;
    outfile.open(filename.c_str());
    for(map<string,damxmare>::iterator it = baza.begin();it != baza.end();it++){
        outfile << it->first << " " << it->second.balansig() << " " << it->second.mbg() << " " << it->second.smsg() << " "  << it->second.wutebig() << " " << it->second.tarifig() << endl;

    }
    outfile.close();
}
map<string,damxmare> readbaza(string filename,map<string,damxmare> baza){
    ifstream infile;
    infile.open(filename.c_str());
    map<string,damxmare> v;
    if(infile.fail()){
        return v;
    }
    string s;
    string key;
    int i = 0;
    while(infile >> s){
        if(i == 0){
            s == key;
            i++;
            continue;
        }
        if(i == 1){
            int n = stoi(s);
            baza[key].setbalansi(n);
            i++;
            continue;
        }
        if(i == 2){
            int n = stoi(s);
            baza[key].setmb(n);
            i++;
            continue;
        }
        if(i == 3){
            int n = stoi(s);
            baza[key].setsms(n);
            i++;
            continue;
        }
        if(i == 4){
            int n = stoi(s);
            baza[key].setwutebi(n);
            i++;
            continue;
        }
        if(i == 5){
            baza[key].chtarifi(s);
            i = 0;
            continue;
        }
    }
    infile.close();
    return baza;
}

bool checknumber(string number){
    if(number.length() == 9 && number[0] == '5'){
        return true;
    }else{
        return false;
    }
}
 struct print{
     print(){
         cout << "akrifet 1 tu nomris damateba gsurt" << endl;
         cout << "akrifet 2 tu dablokva gsurt nomris" << endl;
         cout << "akrifet 3 tu nomris ganblokva gsurt nomtis" << endl;
         cout << "akrifet 4 tu nomris washla gsurt bazidan" << endl;
         cout << "akrifet 5 tu programis gatishva gsurt" << endl;
     }
 }print;



void print1(){
    cout << "1. specialuri shetavazebebi" << endl;
    cout << "2. chemi monacemebi" << endl;
    cout << "3. tarifi yvelaferi maxsi" << endl;
    cout << "4. internet paketebi" << endl;
    cout << "5. sxva oaketebi" << endl;
    cout << "6. saertashoriso zarebi"<< endl;
    cout << "7. beeline krediti" << endl;
    return;

}

bool checkrnnumber(int n){
    if(n >=0 && n <=10){
        return true;
    }else{
        return false;
    }
}

map<string,int>checkkrediti(map<string,int> krediti,map<string,damxmare> &baza,const auto p1){
    for(auto it = krediti.begin();it != krediti.end();it++){
        if(it->second >= chrono::duration_cast<chrono::hours>( p1.time_since_epoch()).count()){
            baza[it->first].chbalansi(-3);
            krediti.erase(it->first);
            continue;
        }else{
            continue;
        }
    }
    return krediti;
}
map<string,int> ckuaryofiti(const auto p1,map<string,damxmare>baza,map<string,int> &shavisia,map<string,int> uaryofiti){
    for(auto it = uaryofiti.begin();it != uaryofiti.end();it++){
        if(it->second >= chrono::duration_cast<chrono::hours>( p1.time_since_epoch()).count()){
            shavisia[it->first] = chrono::duration_cast<chrono::hours>( p1.time_since_epoch()).count() + 24*30;
            uaryofiti.erase(it->first);
        }else if(baza[it->first].balansig() > 0){
            uaryofiti.erase(it->first);
            shavisia.erase(it->first);
        }else{
            continue;
        }



    }
    return uaryofiti;
}
void checkshavisia(const auto p1,map<string,int>&shavisia){
    for(auto it = shavisia.begin();it!=shavisia.end();it++){
        if(it->second >= chrono::duration_cast<chrono::hours>( p1.time_since_epoch()).count()){
            shavisia.erase(it->first);
        }else{
            continue;
        }

    }
}

int main (){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string filename = "C:\\Users\\user\\Desktop\\project";
    createneededfiles(filename);
    const auto p1 = chrono::system_clock::now();
    map<string,int> uaryofiti;
    map<string,int> shavisia;
    map<string,int> krediti;
    map<string,damxmare> baza;
    baza = readbaza(filename + "\\baza.txt",baza);
    krediti = checkkrediti(krediti,baza,p1);
    map<string,bool> blacklist;
    blacklist = readblacklist(filename + "\\blacklist.txt",blacklist);
    krediti = readkrediti(filename + "\\krediti.txt",krediti);
    uaryofiti = readkrediti(filename + "\\uaryofiti.txt",uaryofiti);
    shavisia = readkrediti(filename + "\\shavisia.txt",shavisia);
    uaryofiti = ckuaryofiti(p1,baza,shavisia,uaryofiti);
    checkshavisia(p1,shavisia);
    string l,fnumber; cin >> l >> fnumber;
    string number;
    if(l == "1"){
        baza [fnumber];

    }
    if(l == "2"){
        blacklist[fnumber] = true;

    }
    if(l == "3"){
        blacklist[fnumber] = false;

    }
    if(l == "4"){
        baza.erase(fnumber);
    }if(l == "5"){
        number = fnumber;

    }
    if(l != "5"){
        cout << "enter your number" << endl;
        cin >> number;
    }
    if(baza.count(number) == 0 || blacklist[number] == true || shavisia.count(number) == 1){
            cout << "number does not exist" << endl;
            cout << " or number is in blacklist" << endl;
            return -1;
        }

    while(true){
        print1();
        string s; cin >> s;
        if(s == "1"){
            while(true){
            cout << "akrifet 1 tu tamshi gsurt" << endl;
            cout << "akrifet 0 tu ar gsurt tamshi" << endl;
            cin >> s;
            if(s == "1"){
                cout << "enter your number beetween 1 and 10" << endl;
                int n; cin >> n;
                if(checkrnnumber(n) == true){
                    if(baza[number].balansig() >= 0.1){
                        baza[number].chbalansi(-0.1);
                        if(((rand() %10)+1) == n){
                            baza[number].chmb(100);
                            cout << "tqven moiget" <<endl;
                            break;
                        }else{
                            cout << "tqven waaget " << endl;
                            break;
                        }
                    }
                    else{
                    cout << "sakmarisi tanxa balansze ar gaqvt" << endl;
                    break;
                    }
                }else{
                cout<< "entered wrong random number" << endl;
                continue;
                }

            }else if(s == "DISMISS" || s == "dissmis"){
                break;
            }
            else{
                continue;
            }

        }

    }
    if(s == "2"){
        cout << baza[number].balansig() << endl;
        cout << baza[number].mbg() << endl;
        cout << baza[number].smsg() << endl;
        cout << baza[number].tarifig() << endl;
        cout << baza[number].wutebig() << endl;
        continue;
    }
    if(s == "3"){
        cin >>s;
        if(s == "1"){
            if(baza[number].balansig() >= 25){
                baza[number].chtarifi("tarifi yvelaferi maqsi");
                baza[number].setmb(2147483646);
                baza[number].setsms(2147483646);
                baza[number].setwutebi(2147483646);
                continue;
            }else{
                cout << "sakmarisi tanxa ar gaqvt angarishze" << endl;
            }
        }else if(s == "DISMISS" || s == "dissmis"){
            break;
        }else{
            continue;
        }
    }
    if(s == "4"){
        printipaketi();
        cin >> s;
        if( s == "1"){
            if(baza[number].balansig() >= 7){
                baza[number].chtarifi("2gb+gamis ulimito");
                baza[number].setmb(200);
                continue;
            }else{
                cout << "ar gaqvt sakmarisi tanxa" << endl;
                break;
            }
        }else if(s == "DISMISS" || s == "dissmis"){
            break;
        }else if( s == "2"){
            if(baza[number].balansig() >=11){
                baza[number].chtarifi("4gb + gamis ulimito");
                baza[number].setmb(4000);
                continue;
            }else{
                cout << "ar gaqvt sakmarisi tanxa" << endl;
                break;
            }
        }else if (s == "3"){
            if(baza[number].balansig() >=17){
                baza[number].chtarifi("10gb + gamis ulimito");
                baza[number].setmb(10000);
                continue;
            }else{
                cout << "ar gaqvt sakmarisi tanxa" << endl;
                break;
            }
        }else if (s == "4"){
            if(baza[number].balansig() >=30){
                baza[number].chtarifi("30gb + gamis ulimito");
                baza[number].setmb(30000);
                continue;
            }else{
                cout << "ar gaqvt sakmarisi tanxa" << endl;
                break;
            }
        }else if (s == "dismiss" || s == "DISMISS"){
            break;
        }else{
            continue;
        }
        }
        if(s == "5"){
        printsspaketi();
        cin >> s;
        if(s == "1"){
            if(baza[number].balansig() >= 1.5){
                baza[number].chtarifi("500 sms paketi");
                baza[number].setsms(500);
                continue;
            }else{
                cout << "ar gaqvt sakmarisi tanxa angarishze" << endl;
                break;
            }
        }else if(s == "DISMISS" || s == "dissmis"){
                break;
            }else{
                continue;
            }
    }
    if(s == "6"){
        printspaketi();
        if(s == "1"){
            if(baza[number].balansig() >=1){
                baza[number].chtarifi("saertashoriso zarebi");
                continue;
            }else{
                cout << "ar gaqvt sakmarisi tanxa" << endl;
            }
        }else if(s == "DISMISS" || s == "dissmis"){
            break;
        }else{
            continue;
        }
    }
    if(s == "7"){
        if(baza[number].balansig() <= 0){
            baza[number].chbalansi(2.6);
            cout << "krediti gaaqtiurda" << endl;
            krediti[number] = chrono::duration_cast<chrono::hours>( p1.time_since_epoch()).count() + 7*24;
            continue;
        }else if(s == "DISMISS" || s == "dissmis"){
            break;
        }else{
            continue;
        }
    }
    if(s == "DISMISS" || s == "dissmis"){
        break;
    }
    }
    savebaza(filename + "\\baza.txt",baza);
    savekrediti(filename + "\\krediti.txt",krediti);
    saveblacklist(filename + "\\blacklist.txt",blacklist);
    savekrediti(filename + "\\uaryofiti.txt",uaryofiti);
    savekrediti(filename + "\\shavisia.txt",shavisia);
    }
