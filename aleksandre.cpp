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

using namespace std;

class damxmare{
    public:
    damxmare(){
        tarifi = "";
        mb = 0;
        balansi = 0;
        wutebi = 0;
        sms = 0;

    }

    void setmb(){
        int n;
        mb = n;
        return;
    }
    void setsms(){
        int sm;
        sms = sm;
        return;
    }
    void setmins(){
        int mins;
        wutebi = mins;
        return;
    }
    void chbalansi(int fasi){
        balansi + fasi;
        return;
    }
    void tar(string s){
        tarifi = s;
        return;
    }

    void mbchck(int fasi){
        mb + fasi;
        return;
    }
    double balansbi(){
        return balansi;
    }
    int mbg(){
        return mb;
    }
    int smsbi(){
        return sms;
    }
    string tarifebi(){
        return tarifi;
    }
    int wutebs(){
        return wutebi;
    }

    private:
    double balansi;
    int mb;
    int sms;
    int wutebi;
    string tarifi;

};


void kreditisshenaxva(string createfile,map<string,int> krediti){
    ofstream outfile;
    outfile.open(createfile.c_str());
    for(auto it = krediti.begin();it!= krediti.end();it++){
        outfile << it->first << "\n" << it->second << endl;
    }
    outfile.close();
}

void blacklistshenxava(string createfile,map<string,bool>blacklist ){
    ofstream outfile;
    outfile.open(createfile.c_str());
    for(auto it = blacklist.begin();it != blacklist.end();it++){
        outfile << it->first << "\n" << it->second << endl;
    }
    outfile.close();
}

map<string,int> readkrediti(string createfile,map<string,int> krediti){
    ifstream infile;
    infile.open(createfile.c_str());
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

map<string,bool> readblacklist(string createfile,map<string,bool> blacklist){
    ifstream infile;
    infile.open(createfile.c_str());
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
void createtxtfile (string createfile){
	ofstream outfile (createfile.c_str());
	outfile.close();
}

void createneededfiles(string createfile){
    string s = createfile;
    mkdir(createfile.c_str());
    s = createfile +"\\" + "baza.txt" ;
    createtxtfile(s);
    s = createfile + "\\" +"krediti.txt";
    createtxtfile(s);
    s = createfile + "\\" + "blacklist.txt";
    createtxtfile(s);
    s = createfile + "\\" + "uaryofiti.txt";
    createtxtfile(s);
    s = createfile + "\\" + "shavisia.txt";
    createtxtfile(s);
    return;
}

void bazasv(string createfile,map<string,damxmare> baza ){
    ofstream outfile;
    outfile.open(createfile.c_str());
    for(map<string,damxmare>::iterator it = baza.begin();it != baza.end();it++){
        outfile << it->first  << it->second.balansbi() << " " << it->second.mbg() << " " << it->second.smsbi() << " "  << it->second.wutebs() << " " << it->second.tarifebi() << endl;

    }
    outfile.close();
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



void sawyisishemoyvana(){
    cout << "1. specialuri shetavazebebi" << endl;
    cout << "2. chemi monacemebi" << endl;
    cout << "3. tarifi yvelaferi maxsi" << endl;
    cout << "4. internet paketebi" << endl;
    cout << "5. sxva oaketebi" << endl;
    cout << "6. saertashoriso zarebi"<< endl;
    cout << "7. beeline krediti" << endl;

}



}

map<string,int> ckuaryofiti(const auto n,map<string,damxmare>baza,map<string,int> &shavisia,map<string,int> uaryofiti){
    for(auto it = uaryofiti.begin();it != uaryofiti.end();it++){
        if(it->second >= chrono::duration_cast<chrono::hours>( n.time_since_epoch()).count()){
            shavisia[it->first] = chrono::duration_cast<chrono::hours>( n.time_since_epoch()).count() + 24*30;
            uaryofiti.erase(it->first);
        }else if(baza[it->first].balansbi() > 0){
            uaryofiti.erase(it->first);
            shavisia.erase(it->first);
        }else{
            continue;
        }



    }
    return uaryofiti;
}
void checkshavisia(const auto n,map<string,int>&shavisia){
    for(auto it = shavisia.begin();it!=shavisia.end();it++){
        if(it->second >= chrono::duration_cast<chrono::hours>( n.time_since_epoch()).count()){
            shavisia.erase(it->first);
        }else{
            continue;
        }

    }
}

void chamatebanomris(){
    string s; cin >> s;
    map<string,int> balansi;
        balansi[s];
}


void amoshlanomris(){
    string s; cin >> s;
    map<string,int> balansi;
    balansi.erase(s);

}

void nomrischck(){
    string number;
    map<string,int> balansi;
    if(balansi.count(number) != 1){
            cout << "nomeri an ar arsebobs an shavsiashia" << endl;
            return false;
        }
}

void cinfirst(){
    string s; cin >> s;
        string number;
        map<string,int> balansi;

            while(true){
            cout << "akrifet 1 tu tamshi gsurt" << endl;
            cout << "akrifet 0 tu ar gsurt tamshi" << endl;
            cin >> s;
            if(s == "1"){
                cout << "enter your number beetween 1 and 10" << endl;
                int n; cin >> n;
                if(n > 1 && n < 10){
                    if(balansi[number].balansbi() >= 0){
                        balansi[number].chbalansi(0);
                        if((rand() % 10) == n + 1){
                            balansi[number].mbchck(100);
                            cout << "gilocavt moiget" <<endl;
                            break;
                        }else{
                            cout << "waaget " << endl;
                            break;
                        }
                    }
                    else{
                    cout << "sakmarisi tanxa balansze ar gaqvt" << endl;
                    break;
                    }
                }else{
                    break;
                }

            }
            else{
                continue;
            }
             }
               }

        void cintwo(){
             string s; cin >> s;
            string number;
            map<string,int> balansi;
             if(s == "2"){
        cout << balansi[number].balansbi() << endl;
        cout << balansi[number].mbg() << endl;
        cout << balansi[number].smsbi() << endl;
        cout << balansi[number].tarifebi() << endl;
        cout << balansi[number].wutebs() << endl;
        continue;
        }
}

    void cinthree(){
        string s; cin >> s;
        string number;
        map<string,int> balansi;
        if(s == "3"){
        cin >>s;
        if(s == "1"){
            if(balansi[number].balansbi() >= 25){
                balansi[number].tar("gaaqtiurda tarafii yvelaferi maxi");
                balansi[number].setmb(99999);
                balansi[number].setsms(99999);
                balansi[number].setmins(99999);
                continue;
            }else{
                cout << "sakmarisi tanxa ar gaqvt angarishze" << endl;
            }
        }else{
            continue;
        }
    }
    }

    void cinfour(){
        string s; cin >> s;
        string number;
        map<string,int> balansi;
         if(s == "4"){
        cout << "1.2gb + gamis ulimito-7lari" << endl;
        cout << "2.4gb + gamis ulimito-11lari" << endl;
        cout << "3.10gb + gamis ulimito -17" << endl;
        cout << "4.30gb + gamis ulimito-30 lari" << endl;
        cout << "0 ukan dabruneba" << endl;
        cout << "00 mtabar gverdze dabruneba" << endl;
        cin >> s;
        if( s == "1"){
            if(balansi[number].balansbi() >= 7){
                balansi[number].tar("2gb+gamis ulimito");
                balansi[number].setmb(200);
                continue;
            }else{
                cout << "balansze ar aris sakmarisi tanxa" << endl;
                break;
            }
        }
        }else if( s == "2"){
            if(balansi[number].balansbi() >=11){
                balansi[number].tar("4gb + gamis ulimito");
                balansi[number].setmb(400);
                continue;
            }else{
                cout << "balansze ar aris sakmarisi tanxa" << endl;
                break;
            }
        }else if (s == "3"){
            if(baza[number].balansbi() >=17){
                baza[number].tar("10gb + gamis ulimito");
                baza[number].setmb(1000);
                continue;
            }else{
                cout << "balansze ar aris sakmarisi tanxa" << endl;
                break;
            }
        }else if (s == "4"){
            if(baza[number].balansbi() >=30){
                baza[number].tar("30gb + gamis ulimito");
                baza[number].setmb(3000);
                continue;
            }else{
                cout << "balansze ar aris sakmarisi tanxa" << endl;
                break;
            }
        }
    }
 }

    void cinfive(){
        string s; cin >> s;
        string number;
        map<string,int> balansi;
        cout << "1. 500 sms" << endl;
        cout << "vada 7 dge" << endl;
        cout << "0. ukan" << endl;

        if(s == "1"){
            if(balansi[number].balansbi() >= 7){
                balansi[number].smsbi(500);
            }else{
                cout << "balansze ar aris sakmarisi tanxa" << endl;
                break;
            }
        }
    }

    void cinsix(){
        string s; cin >> s;
        string number;
        map<string,int> balansi;
        cout << "saertashoriso zarebis aqtivacia amerikashi da canadashi" << endl;
        cout << "girebuleba 1 lari vada 1 tve" << endl;
        cout << "1.activacia" << endl;

        if(s == "1"){
            if(balansi[number].balansbi() >= 1)
                // ver davwere :(
        }
    }

    void saveinfo(){
        createneededfiles(createfile);
    const auto n = chrono::system_clock::now();
    map<string,int> uaryofitibal;
    map<string,int> shavisia;
    map<string,int> krediti;
    map<string,damxmare> balansi;
    krediti = checkkrediti(krediti,balansi,p1);
    map<string,bool> blacklist;
    blacklist = readblacklist(filename + "\\blacklist.txt",blacklist);
    krediti = readkrediti(filename + "\\krediti.txt",krediti);
    uaryofiti = readkrediti(filename + "\\uaryofiti.txt",uaryofitibal);
    shavisia = readkrediti(filename + "\\shavisia.txt",shavisia);
    uaryofiti = ckuaryofiti(p1,balansi,shavisia,uaryofitibal);
    checkshavisia(p1,shavisia);
        bazasv(filename + "\\baza.txt",balansi);
        blacklistshenxava(filename + "\\blacklist.txt",blacklist);
        kreditisshenaxva(filename + "\\shavisia.txt",shavisia);
        kreditisshenaxva(filename + "\\uaryofitibal.txt",uaryofitibal);
        kreditisshenaxva(filename + "\\krediti.txt",krediti);
    }
int main (){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string createfile = "C:\\Users\\user\\Desktop\\project 2";
    saveinfo();
    map<string,bool> blacklist;
    string gl,monacemebi; cin >> gl >> monacemebi;

    if(gl == "1"){
            chamatebanomris();
    }
    if(gl == "2"){
        blacklist[monacemebi] = true;

    }
    if(gl == "3"){
        blacklist[monacemebi] = false;

    }
    if(gl == "4"){
       amoshlanomris();
    }if(gl == "5"){
        number = monacemebi;
    }
    if(gl != "5"){
        cout << "enter your number" << endl;
        cin >> number;
        nomris
    }
    nomrischck();


    while(true){
        sawyisishemoyvana();
        string ch; cin >> ch;
        if(ch == "1"){
        cinfirst();
        }
        if(ch == "2"){
        cintwo();
        }
            if(ch == "3"){
        cinthree();
            }
        if(ch == "4"){
        cinfour();
        }
        if(ch == "5")
        cinfive();
        if(ch == "6")
        cinsix();
        if(s == "dismiss"){
            if(s == "DISMISS"){
            break;
        }
    }

    }
