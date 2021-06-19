#include <bits/stdc++.h>
#include <time.h>
#include <fstream>
#define ll long long
#define pb push_back
using namespace std;
void nomrebisBaza(vector <string> &v){
    cout << "Nomrebis Bazis Gasakontroleblad Gaqvt Otxi Funqcia 1) Nomris Damateba   2) Nomris Dablokva  3) Ganblokva  4) Washla-  -- --  Tu Gsurt Nomrebis Bazidan Gasvla Daweret (EXIT)" << endl;
    cout << "Shemoiyvanet Sasurveli Funqciis Nomeri: ";string a;cin >> a;cout << endl;bool sworinom = false;
    if(a == "1"){
        string s;
        cout << "Shemoiyvanet Nomeri: ";cin >> s;cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                cout << "Msgavsi Nomeri Ukve Arsebobs" << endl;
                nomrebisBaza(v);
                return;
            }
        }
        v.pb(s);v.pb("0");v.pb("0");v.pb("0");v.pb("utarifo");v.pb("araris");v.pb("ganblokili");
        cout << "Nomeri Damatebulia" << endl;
        nomrebisBaza(v);
        return;
    }if(a == "2"){
        string s;
        cout << "Shemoiyvanet Nomeri: ";cin >> s;cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                v[i+6] = "dablokili";
                sworinom = true;break;
            }
        }if(sworinom == false)cout << "Nomeri Arasworia"<< endl;
        nomrebisBaza(v);
        return;
    }if(a == "3"){
        string s;
        cout << "Shemoiyvanet Nomeri: ";cin >> s;cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                v[i+6] = "ganblokili";
                sworinom = true;break;
            }//stoi
        }if(sworinom == false)cout << "Nomeri Arasworia"<< endl;
        nomrebisBaza(v);
        return;
    }if(a == "4"){
        string s;
        cout << "Shemoiyvanet Nomeri: ";cin >> s;cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                v.erase(v.begin()+i,v.begin()+i+7);
                sworinom = true;break;
            }
        }if(sworinom == false)cout << "Nomeri Arasworia" << endl;
        nomrebisBaza(v);
        return;
    }if(a == "EXIT")return;
}
void nomrisFunqciebi(vector<string> &v){
    cout << "Gaqvt Shidi Funqcia 1)Tamashi Wesebs Gaecnobit Archevis Shemtxvevashi 2) Balansis Naxva 3) Paketi YvelaferiMaqsi Yvelaferi Ulimito(sms,mgb,dro) Fasi 25Lari" << endl << "4) Internet Paketebi 5) 500SMS Fasi 1.5Lari Vada 7 Dge  6) Saertashoriso Paketi   Airchiet Sasurveli Nomeri, Akrifet [DISMISS] Rata Gamortot Programa" << endl;
    string a;cin >> a;
    if(a == "1"){
        cout << "Shoemoiyvanet Nomeri: ";string s;cin >> s;cout << endl;bool sworinom = false;int c;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                sworinom = true;
                if(v[i+6] == "dablokili"){
                    cout << "Nomeri Dablokilia" << endl;
                    nomrisFunqciebi(v);
                    return;
                }
                c = i+3;
                if(stod(v[i+1]) < 0.1){
                    cout << "Sakmarisi Tanxa Argaqvt" << endl;
                    nomrisFunqciebi(v);
                    return;
                }
            }
        }if(sworinom == false){
            cout << "Nomeri Arasworia" << endl;
            nomrisFunqciebi(v);
            return;
        }
        cout << "Chven Virchevt 0 Dan 10 Mde Ricxvs. Tuki Gamoicnobt Chven Archeul Ricxvs Dagericxebat 100Megabaiti Tamashis Dawyebis Safasuri 0.1 Lari" << endl;
        cout << "Tu Gsurt Tamashis Dawyeba Shemoiyvanet (1)" << endl;int f;cin >> f;
        if(f != 1){
            nomrisFunqciebi(v);
            return;
        }else{
            v[c-2] = to_string(stod(v[c-2]) - 0.1);
        }
        int a = rand() % 10;int b;
        cout << "Shemoiyvanet Ricxvi: ";cin >> b;cout << endl;
        if(a == b){
            cout << "Gilocavt Tqven Gamoicanit Ricxvi" << endl;
            v[c] = to_string(stod(v[c])+100);
            nomrisFunqciebi(v);
            return;
        }else{
            cout << "Tqven Vergamoicanit Ricxvi )" << endl;nomrisFunqciebi(v);return;
        }
    }if(a == "2"){
        cout << "Shemoiyvanet Nomeri: "; string s; cin >> s; cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                if(v[i+6] == "dablokili"){
                    cout << "Nomeri Dablokilia" << endl;
                    nomrisFunqciebi(v);
                    return;
                }
                cout << "Tanxa: " << v[i+1] << " Lari" << endl << "SMS: " << v[i+2] << endl << "MegaByte: " << v[i+3] << endl;
                nomrisFunqciebi(v);
                return;
            }
        }cout << "Nomeri Arasworia" << endl;nomrisFunqciebi(v);return;
    }if(a == "3"){
        cout << "Shemoiyvanet Nomeri: "; string s; cin >> s; cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                if(v[i+6] == "dablokili"){
                    cout << "Nomeri Dablokilia" << endl;
                    nomrisFunqciebi(v);
                    return;
                }
                if(stoi(v[i+1]) < 25){
                    cout << "Sakmarisi Tanxa Argaqvt" << endl;
                    nomrisFunqciebi(v);return;
                }else v[i+1] = to_string(stod(v[i+1])-25);
                v[i+2] = "ulimito";v[i+3] = "ulimito";v[i+4] = "ulimito";nomrisFunqciebi(v);return;
            }
        }cout << "Nomeri Arasworia" << endl;nomrisFunqciebi(v);return;
    }if(a == "4"){
        cout << "Shemoiyvanet Nomeri: ";string s; cin >> s; cout << endl;
        cout << "0) Ukan Dabruneba" << endl;
        cout << "1) 2GB Interneti + Gamis Ulimito Interneti 7Lari" << endl;
        cout << "2) 4GB Interneti + Gamis Ulimito Interneti 11Lari" << endl;
        cout << "3) 10GB Interneti + Gamis Ulimito Interneti 17Lari" << endl;
        cout << "4) 30GB Interneti + Gamis Ulimito Interneti 30Lari" << endl;
        cout << "Shemoiyvanet Sasurveli Nomeri: ";int k;cin >> k;cout << endl;
        int o,o1;bool sworinom = false;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                if(v[i+6] == "dablokili"){
                    cout << "Nomeri Dablokilia" << endl;
                    nomrisFunqciebi(v);
                    return;
                }
                o = i+3;o1 = i+4;sworinom = true;break;
            }
        }if(sworinom == false){
            cout << "Nomeri Arasworia" << endl;nomrisFunqciebi(v);return;
        }
        if(k == 0){
            nomrisFunqciebi(v);return;
        }if(k == 1){
            v[o] = stoi(v[o]) + 2048;
            v[o1] += "+GamisUlimitoInterneti";
            cout << "Paketi Gaaqtiurda" << endl;
        }if(k == 2){
            v[o] = stoi(v[o]) + 4096;
            v[o1] += "+GamisUlimitoInterneti";
            cout << "Paketi Gaaqtiurda" << endl;
        }if(k == 3){
            v[o] = stoi(v[o]) + 10240;
            v[o1] += "+GamisUlimitoInterneti";
            cout << "Paketi Gaaqtiurda" << endl;
        }if(k == 4){
            v[o] = stoi(v[o]) + 30720;
            v[o1] += "+GamisUlimitoInterneti";
            cout << "Paketi Gaaqtiurda" << endl;
        }nomrisFunqciebi(v);return;
    }if(a == "5"){
        cout << "Shemoiyvanet Nomeri: " << endl;string s;cin >> s;cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s && stod(v[i+1]) >= 1.5){
                v[i+2]+=stoi(v[i+2])+500;
                v[i+4]+="+500 SMS 7 Dge";
                time_t now = time(0);
                string dt = ctime(&now);string s100 = dt;v[i+4]+="."+s100;
                nomrisFunqciebi(v);return;
            }
        }cout << "Nomeri Arasworia An Sakmarisi Tanxa Argaqvt Nomerze" << endl;nomrisFunqciebi(v);return;
    }if(a == "6"){
        cout << "Shemoiyvanet Nomeri: " << endl;string s;cin >> s;cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s && stoi(v[i+1]) >= 1){
                v[i+1]= to_string(stod(v[i+1]) - 1);
                v[i+4]+="+SaertashorisoZarebi";
                time_t now = time(0);
                string dt = ctime(&now);string s101 = dt;v[i+4]+="."+s101;
                nomrisFunqciebi(v);return;
            }
        }cout << "Nomeri Arasworia An Sakmarisi Tanxa Argaqvt" << endl;nomrisFunqciebi(v);return;
    }if(a == "7"){
        cout << "Shemoiyvanet Nomeri: ";string s;cin>>s;cout << endl;
        for(int i = 0; i < v.size(); i+=7){
            if(v[i] == s){
                if(stod(v[i+1]) < 0){
                    cout << "Kredits Vergaaqtiureb Uaryofiti Balansit )" << endl;
                    nomrisFunqciebi(v);
                    return;
                }else{
                    v[i+1] = to_string(stod(v[i+1]) + 2.6);
                    v[i+4] += "+Krediti";
                    time_t now = time(0);
                    string dt = ctime(&now);string s102 = dt;v[i+4]+="."+s102;
                    nomrisFunqciebi(v);
                    return;
                }
            }
        }cout << "Nomeri Arasworia" << endl;nomrisFunqciebi(v);return;
    }if(a == "DISMISS")return;nomrisFunqciebi(v);return;
}
int main(){
    vector <string> v;ifstream infile;
    infile.open("NomrebisBaza.txt");
    while(infile.good()){//monacemebis amogeba
        string s;
        infile >> s;
        if(s != "")v.pb(s);
    }
    //es for programis chartvis mere amowmebs ra paketebs gauvida vad ada sheasbamis moqmedebas aketebs
    for(int i = 4; i < v.size(); i+=7){
        string s = v[i],s1,s2,s3;
        string s7 = v[i+1];
        time_t now = time(0);
        string dt = ctime(&now);
        string s8;s8+=dt;
        if(s8[4] + s8[5] + s8[6] != s7[4] + s7[5] + s7[6]){
           string s9,s10;
           s9 = s8[8]+s8[9];s10 = s7[8] + s7[9];
           if(stoi(s8) - stoi(s7) > 0){
               if(stoi(v[i-3]) < 0)v[i+2] = "dablokili";
               else v[i+1] = "";
           }
        }
        for(int j = 0; j < s.length(); j++){
            if((int)s[j] == '+')s1 = "";
            else if((int)s[j] == '.'){
                s2+=s[j+4]+s[j+5]+s[j+6];s3+=s[j+8];if((int)s[j+9] != ' ')s3+=s[j+9];
                int a = stoi(s3);
                time_t now = time(0);
                string dt = ctime(&now);
                string s5;s5+=dt;bool kvira = false,tve = false;
                if(s1 == "Krediti"||s1 == "500 SMS 7 Dge")kvira = true;
                else tve = true;
                string s6;s6+=s5[8];if(s5[9] != ' ')s6+=s5[9];
                if(tve){
                    string s11;s11+=s5[4];s11+=s5[5];s11+=s5[6];
                    if(s11 != s2){
                        int b = stoi(s6);
                        if(a > b){
                            v[i].erase(s1.begin()+j-20, s1.begin()+j+23);
                        }
                    }
                }else if(kvira){
                    string s11;s11+=s5[4];s11+=s5[5];s11+=s5[6];
                    if(s11 != s2){
                        if(31-stoi(s6) > 7){
                            if(s1 == "Krediti"){
                                v[i].erase(s1.begin()+j-8,s1.begin()+j+23);
                                v[i-3] = to_string(stoi(v[i-3])-3);
                                if(stoi(v[i-3]) < 0)v[i+1] = s5;
                            }
                            else if(s1 == "500 SMS 7 Dge"){
                                v[i].erase(s1.begin()+j-14,s1.begin()+j+23);
                                v[i-2] = to_string(stoi(v[i-2]) - 500);
                            }
                        }
                    }else{
                        if(stoi(s6)-stoi(s3) > 7){
                            if(s1 == "Krediti"){
                                v[i].erase(s1.begin()+j-8,s1.begin()+j+23);
                                v[i-3] = to_string(stoi(v[i-3])-3);
                                if(stoi(v[i-3]) < 0)v[i+1] = s5;
                            }
                            else if(s1 == "500 SMS 7 Dge"){
                                v[i].erase(s1.begin()+j-14,s1.begin()+j+23);
                                v[i-2] = to_string(stoi(v[i-2]) - 500);
                            }
                        }
                    }
                }
            }else s1+=s[j];
        }s1 = "";
    }
    cout << "Ori Archevanigaqvt 1-Nomrebis Bazis Kontroli || 2-Nomris Funqciebi  Miutitet Sasurveli Nomeri" << endl;
    int arch;cin >> arch;
    if(arch == 1)nomrebisBaza(v);
    else if(arch == 2)nomrisFunqciebi(v);
    ofstream outfile;//monacemebis shenaxva
    outfile.open("NomrebisBaza.txt");
    for(int i = 0; i < v.size(); i++)outfile << v[i] << " ";
}