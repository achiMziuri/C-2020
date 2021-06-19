//მას ბოდიშით ძაან დამაგვიანდა ;-;
#include <bits/stdc++.h>
#define ll long long int
#define add push_back
using namespace std;

string database = "database.txt";
string filename = "database.txt";
string blocked_filename = "!database.txt";
int gel=0,sms=0,mb=0;
double fifteen = 0.15;
//////////////////////////////
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
// bool is_digit(const char value) {
//     return isdigit(value); 
// }
// bool is_numeric(const string& value) {
//     return all_of(value.begin(), value.end(), is_digit); 
// }
// void is_numeric(const vector<string> value) {
//     return all_of(value.begin(), value.end(), is_digit); 
// }
void printVector(vector <int> ar , int num){//Prints Vector
    for(int i = 0; i < num; i++){////////() "array name","array size"
        cout << ar[i] << " ";
    }
    cout << endl;
}
void readFileWord(string txt){
    ifstream file(txt);
    string word;
    if(file.is_open()==false){
        cout << "NOT OPENED " << endl;
    }else{
        while(file >> word){
            cout << word << endl;
        }
    }
    file.close();
}
vector<string> readFile(string fileName){
    ifstream infile;
    infile.open(fileName);
    vector<string> v;
    if(infile.fail()){
        cout << "Can not find the file" << endl;
        return v;
    }
    string s;
    while(infile >> s){
        v.add(s);
    }
    infile.close();
    return v;
}
vector<string> readFile(vector<string> VecfileName){
    string fileName = accumulate(VecfileName.begin(), VecfileName.end(), std::string{});
    ifstream infile;
    infile.open(fileName);
    vector<string> v;
    if(infile.fail()){
        cout << "Can not find the file" << endl;
        return v;
    }
    string s;
    while(infile >> s){
        v.add(s);
    }
    infile.close();
    return v;
}
vector<string> readFileWordSave(string txt){
    ifstream file(txt);
    string word;
    vector <string> vec;
    if(file.is_open()==false){
        cout << "NOT OPENED " << endl;
    }else{
        while(file >> word){
            vec.push_back(word);
        }
    }
    file.close();
    return vec;
}
void addPhoneNumberToDatabase(string num){
    ofstream outfile("database.txt");
    vector<string> vec = readFileWordSave("database.txt");
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    vec.push_back(num);
    for(int i = 0; i < vec.size();i++){
        outfile << vec[i] << endl;
    }
    outfile.close();
}
class phone{
    private:
        string phoneNumber;
    public:
        phone(){
            this->phoneNumber = "";
        }
        ~phone(){

        }
        add(string num){
            // addPhoneNumberToDatabase(num);
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            v.push_back(num);
            ofstream outfile("database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile << gel << endl;
            outfile << sms << endl;
            outfile << mb << endl;
            outfile.close();
        }
        block(string num){
            string blocked_filename = "!database.txt";
            vector <string> v = readFile(blocked_filename);
            v.push_back(num);
            ofstream outfile("!database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        unblock(string num){
            string blocked_filename = "!database.txt";
            vector <string> v = readFile(blocked_filename);
            for(int i = 0; i < v.size(); i++){
                if(v[i]==num){
                    v.erase(v.begin()+i);
                }
            }
            ofstream outfile("!database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        remove(string num){
            string filename = "database.txt";
            vector <string> v = readFile(filename); 
            for(int i = 0; i < v.size(); i++){
                if(v[i]==num){
                    v.erase(v.begin()+i,v.begin()+i+4);
                }
            }
            ofstream outfile("database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        // add_gel(string num, int amount){
        //     string filename = "database.txt";
        //     vector <string> v = readFile(filename);
        //     int indx;
        //     int old;
        //     for(int i = 0; i < v.size(); i++){
        //         if(v[i]==num){
        //             indx = i + 1;
        //             cout << v[i] << endl;
        //         }
        //     }
        // }
        add_gel(string num, double amount){//gel sms mb
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            int hlp;
            string slp;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    double mun = stoi(v[i+1]);
                    mun = mun + amount;
                    string slp;
                    slp = to_string(mun);
                    v[i+1] = slp;
                    break;
                    // cout << "vot" << mun << endl;
                    // cout << v[i+1] << endl;
                }
            }
            ofstream outfile("database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        add_sms(string num, double amount){//gel sms mb
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            int hlp;
            string slp;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    double mun = stoi(v[i+2]);
                    mun = mun + amount;
                    string slp;
                    slp = to_string(mun);
                    v[i+2] = slp;
                    break;
                    // cout << "vot" << mun << endl;
                    // cout << v[i+1] << endl;
                }
            }
            ofstream outfile("database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        add_mb(string num, double amount){//gel sms mb
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            int hlp;
            string slp;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    double mun = stoi(v[i+3]);
                    mun = mun + amount;
                    string slp;
                    slp = to_string(mun);
                    v[i+3] = slp;
                    break;
                    // cout << "vot" << mun << endl;
                    // cout << v[i+1] << endl;
                }
            }
            ofstream outfile("database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        ////
        remove_gel(string num, double amount){//gel sms mb
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            int hlp;
            string slp;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    double mun = stoi(v[i+1]);
                    mun = mun - amount;
                    string slp;
                    slp = to_string(mun);
                    v[i+1] = slp;
                    break;
                    // cout << "vot" << mun << endl;
                    // cout << v[i+1] << endl;
                }
            }
            ofstream outfile("database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        remove_sms(string num, double amount){//gel sms mb
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            int hlp;
            string slp;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    double mun = stoi(v[i+2]);
                    mun = mun - amount;
                    string slp;
                    slp = to_string(mun);
                    v[i+2] = slp;
                    break;
                    // cout << "vot" << mun << endl;
                    // cout << v[i+1] << endl;
                }
            }
            ofstream outfile("database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        remove_mb(string num, double amount){//gel sms mb
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            int hlp;
            string slp;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    double mun = stoi(v[i+3]);
                    mun = mun - amount;
                    string slp;
                    slp = to_string(mun);
                    v[i+3] = slp;
                    break;
                    // cout << "vot" << mun << endl;
                    // cout << v[i+1] << endl;
                }
            }
            ofstream outfile("database.txt");
            for(int i = 0; i < v.size(); i++){
                outfile << v[i] << endl;
            }
            outfile.close();
        }
        coutGel(string num){
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            string answ;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    answ = v[i+1];
                }
            }
            cout << answ << endl;
        }
        coutSms(string num){
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            string answ;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    answ = v[i+2];
                }
            }
            cout << answ << endl;
        }
        coutMb(string num){
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            string answ;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    answ = v[i+3];
                }
            }
            cout << answ << endl;
        }
        ///
        int Gel(string num){
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            string answ;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    answ = v[i+1];
                }
            }
            int ans = stoi(answ);
            return ans;
        }
        int Sms(string num){
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            string answ;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    answ = v[i+2];
                }
            }
            int ans = stoi(answ);
            return ans;
        }
        int Mb(string num){
            string filename = "database.txt";
            vector <string> v = readFile(filename);
            string answ;
            for(int i = 0; i < v.size(); i=i+4){
                if(v[i]==num){
                    answ = v[i+3];
                }
            }
            int ans = stoi(answ);
            return ans;
        }
};
bool hasFifteenCent(string nu){
    phone myphon1;
    double gl;
    gl = myphon1.Gel(nu);
    if(gl>=fifteen){
        return true;
    }else return false;
}
bool checkExit(string str){
    if(str=="EXIT"||str=="exit"||str=="DISMISS"||str=="dismiss") return true;
    else return false;
}

void checkInput(string userInput){
    // if(userInput=="1") {
    phone myphone;
    myphone.add("555373709");
    // }
    // else continue;adding
}
bool checkExistenceInDatabase(string nu){
    vector <string> vec = readFile(filename);
    for(int i = 0; i < vec.size(); i=i+4){
        if(vec[i]==nu){
            return true;
        }
    }
    return false;
}
bool checkExistenceInDatabaseBlock(string nu){
    vector <string> vec = readFile(blocked_filename);
    for(int i = 0; i < vec.size(); i++){
        if(vec[i]==nu){
            return true;
        }
    }
    return false;
}
bool alreadyBlocked(string nu){
    vector <string> v = readFile(blocked_filename);
    for(int i = 0; i < v.size(); i++){
        if(nu==v[i]){
            return true;
        }
    }
    return false;
}
int randomNumGenerator(){
    int answ;
    answ = (rand()%10)+1;
    return answ;
}
bool continueConf(string str){
    if(str=="CONTINUE"){
        return true;
    }else return false;
}
bool has_gel(string nu, double amount){
    phone myphon2;
    double som = myphon2.Gel(nu);
    if(som>=amount){
        return true;
    }else return false;
}
bool has_sms(string nu, double amount){
    phone myphon2;
    double som = myphon2.Sms(nu);
    if(som>=amount){
        return true;
    }else return false;
}
bool has_mb(string nu, double amount){
    phone myphon2;
    double som = myphon2.Mb(nu);
    if(som>=amount){
        return true;
    }else return false;
}
void SpecialOfferHard(string nu){
    cout << "Selected Hard mode" << endl;
    cout << "Random number is generated..." << endl;
    int randomNum = randomNumGenerator();
    bool win = false;
    int tm = 1;
    while(true){
        if(tm!=0){
            cout << "You have " << tm << " tries!" << endl;
            cout << "Input your guess" << endl;
        }
        if(tm == 0){
            break;
        }
        cout << "CHEAT: " << randomNum << endl;
        int nad; cin >> nad;
        if(nad==randomNum){
            win = true;
            break;
        }
        tm--;
    }
    if(win==true){
        cout << "CONGRATS" << endl;
        cout << "You won 3 GEL!" << endl;
        phone myphone8;
        double lari = 1;
        myphone8.add_gel(nu,lari);
    }else if(win==false){
        cout << "Unfortunately You lost :(" << endl;
        phone myphone9;
        myphone9.remove_gel(nu,fifteen);
        cout << "You just lost 0.15 :(" << endl;
    }
    while(true){
        cout << "If you wish to play again type YES if not NO" << endl;
        string nihao; cin >> nihao;
        if(nihao=="YES"){
            cout << "Selected YES" << endl;
            SpecialOfferHard(nu);
        }else if(nihao=="NO"){
            cout << "Selected NO" << endl;
            return;
        }else cout << "Error, input again!" << endl;
    }
}
void SpecialOfferNormal(string nu){
    cout << "Selected Normal mode" << endl;
    cout << "Random number is generated..." << endl;
    int randomNum = randomNumGenerator();
    bool win = false;
    int tm = 3;
    while(true){
        if(tm!=0){
            cout << "You have " << tm << " tries!" << endl;
            cout << "Input your guess" << endl;
        }
        if(tm == 0){
            break;
        }
        cout << "CHEAT: " << randomNum << endl;
        int nad; cin >> nad;
        if(nad==randomNum){
            win = true;
            break;
        }
        tm--;
    }
    if(win==true){
        cout << "CONGRATS" << endl;
        cout << "You won 1 GEL!" << endl;
        phone myphone8;
        double lari = 1;
        myphone8.add_gel(nu,lari);
    }else if(win==false){
        cout << "Unfortunately You lost :(" << endl;
        phone myphone9;
        myphone9.remove_gel(nu,fifteen);
        cout << "You just lost 0.15 :(" << endl;
    }
    while(true){
        cout << "If you wish to play again type YES if not NO" << endl;
        string nihao; cin >> nihao;
        if(nihao=="YES"){
            cout << "Selected YES" << endl;
            SpecialOfferNormal(nu);
        }else if(nihao=="NO"){
            cout << "Selected NO" << endl;
            return;
        }else cout << "Error, input again!" << endl;
    }
}
void SpecialOffer(string nu){
    string numbr = nu;
    cout << "Game Rules:" << endl;
    cout << "This machine will generate a single number " << endl;
    cout << "from 1 to 10. You have 3 tries to guess that" << endl;
    cout << "number and if you will guess you'll get" << endl;
    cout << "a Prize. There is also harder mode:" << endl;
    cout << "Instead of 3 tries u get 1 and the prize" << endl;
    cout << "is 3 times better! Every game costs 15 cents (0.15)" << endl;
    while(true){
        cout << "If you wish to continue type: 'CONTINUE'" << endl;
        cout << "If you wish to exit type 'DISMISS'" << endl;
        string s; cin >> s;
        if(checkExit(s)){
            return;
        }
        if(continueConf(s)){
            break;
        }
    }
    while(true){
        cout << "Type 'NORMAL' to play normal mode." << endl;
        cout << "Type 'HARD' to play hard mode." << endl;
        cout << "If you wish to exit type 'DISMISS'" << endl;
        string s; cin >> s;
        if(checkExit(s)){
            return;
        }
        if(s=="NORMAL"){
            if(hasFifteenCent(nu)==false){
                cout << "You don't have enough money :(" << endl;
                return;
            }
            SpecialOfferNormal(nu);
            break;
        }else if(s=="HARD"){
            if(hasFifteenCent(nu)==false){
                cout << "You don't have enough money :(" << endl;
                return;
            }
            SpecialOfferHard(nu);
            break;
        }
    }
}
void MyBalance(string nu){
    cout << "/////////////" << endl;
    cout << "Selected My Balance" << endl;
    cout << "Number: " << nu << endl;
    phone myphone7;
    cout << "GEL: ";
    myphone7.coutGel(nu);
    cout << endl;
    cout << "SMS: ";
    myphone7.coutSms(nu);
    cout << endl;
    cout << "MB: ";
    myphone7.coutMb(nu);
    cout << "/////////////" << endl;
}
void EverythingMAX(string nu){
    cout << "/////////////" << endl;
    cout << "Selected Everything MAX" << endl;
    cout << "If you will buy this package" << endl;
    cout << "You will get 20 GEL, 5000 SMS and 15000 MB" << endl;
    cout << "Price: 25 GEL" << endl;
    while(true){
        cout << "If you wish to buy this package type YES" << endl;
        cout << "If not Type NO" << endl;
        string cons; cin >> cons;
        if(cons=="YES"){
            break;
        }else if(cons=="NO"){
            return;
        }
    }
    double twentyFive = 25;
    if(has_gel(nu,twentyFive)==false){
        cout << "You don't have enough money to buy this package." << endl;
        return;
    }
    phone myphon3;
    double fivek = 5000;
    double fifteenk = 15000;
    myphon3.remove_gel(nu,twentyFive-5);
    myphon3.add_sms(nu,fivek);
    myphon3.add_mb(nu,fifteenk);
    cout << "Operation succesful" << endl;
}
void InternetPackages(string nu){
    cout << "/////////////" << endl;
    phone mypho;
    cout << "Selected Internet Packages" << endl;
    while(true){
        cout << "0. Return" << endl;
        cout << "1. 2GB - 2GEL" << endl;
        cout << "2. 5GB - 4GEL" << endl;
        cout << "3. 10GB - 7GEL" << endl;
        cout << "4. 30GB - 18GEL" << endl;
        cout << "5. Unlimited - 179GEL" << endl;
        string str; cin >> str;
        if(checkExit(str)||str=="0"){
            return;
        }
        if(str=="1"){
            cout << "Selected 2GB 2GEL" << endl;
            mypho.add_mb(nu,2);
            cout << "Done" << endl;
            return;
        }else if(str=="2"){
            cout << "Selected 5GB 4GEL" << endl;
            mypho.add_mb(nu,5);
            cout << "Done" << endl;
            return;
        }else if(str=="3"){
            cout << "Selected 10GB 7GEL" << endl;
            mypho.add_mb(nu,10);
            cout << "Done" << endl;
            return;
        }else if(str=="4"){
            cout << "Selected 30GB 18GEL" << endl;
            mypho.add_mb(nu,30);
            cout << "Done" << endl;
            return;
        }else if(str=="5"){
            cout << "Selected Unlimited 179GEL" << endl;
            mypho.add_mb(nu,9999);
            cout << "Done" << endl;
        }
        else cout << "Please use number 0 - 5" << endl;
    }
}
void OtherPackages(string nu){
    cout << "Selected other Packages" << endl;
    cout << "1. 500sms 1.5" << endl;
    while(true){
        string str; cin >> str;
        if(checkExit(str)||str=="0"){
            return;
        }else if(str=="1"){
            phone nihh;
            nihh.add_mb(nu,500);
            cout << "Done" << endl;
            return;
        }else cout << "Please use number 0 - 1" << endl;
    }
}
void MoneyTransferOne(string nu, string sec){
    phone a;
    double d;
    while(true){
        cout << "Input amount to send" << endl;
        cin >> d;
        if(has_gel(nu,d)){
            break;
        }else cout << "You don't have enough money to send" << endl;
    }
    a.remove_gel(nu,d);
    a.add_gel(sec,d);
    cout << "Done" << endl;
}
void MoneyTransferTwo(string nu, string sec){
    phone a;
    double d;
    while(true){
        cout << "Input amount to send" << endl;
        cin >> d;
        if(has_sms(nu,d)){
            break;
        }else cout << "You don't have enough money to send" << endl;
    }
    a.remove_sms(nu,d);
    a.add_sms(sec,d);
    cout << "Done" << endl;
}
void MoneyTransferOThree(string nu, string sec){
    phone a;
    double d;
    while(true){
        cout << "Input amount to send" << endl;
        cin >> d;
        if(has_mb(nu,d)){
            break;
        }else cout << "You don't have enough money to send" << endl;
    }
    a.remove_mb(nu,d);
    a.add_mb(sec,d);
    cout << "Done" << endl;
}
void MoneyTransfer(string nu){
    cout << "Selected Money transfer" << endl;
    string sec;
    while(true){
        cout << "Input number to send GEL,SMS or MB" << endl;
        cin >> sec;
        if(checkExit(sec)){
            return;
        }
        if(isNumber(sec)==false){
            cout << "Please type only digits" << endl;
        }
        else if(checkExistenceInDatabase(nu)==true){
            cout << "Number found" << endl;
            break;
        }else cout << "Number not Found" << endl;
    }
    while(true){
        cout << "0. Return" << endl;
        cout << "1. Send GEL" << endl;
        cout << "2. Send SMS" << endl;
        cout << "3. Send MB" << endl;
        string c; cin >> c;
        if(checkExit(c)||c=="0"){
            return;
        }else if(c=="1"){
            cout << "Selected 1" << endl;
            MoneyTransferOne(nu,sec);
            return;
        }else if(c=="2"){
            cout << "Selected 2" << endl;
            MoneyTransferTwo(nu,sec);
            return;
        }else if(c=="3"){
            cout << "Selected 3" << endl;
            MoneyTransferOThree(nu,sec);
            return;
        }
        else cout << "Please use number 0 - 3" << endl;
    }
}
void a1(){
    cout << "Selceted 1 - add phone number to database" << endl;
    string phoneNum;
    while(true){
        cout << "Input number: ";
        string nu; cin >> nu;
        if(checkExit(nu)==true){
            return;
        }
        if(isNumber(nu)==false){
            cout << "Please type only digits" << endl;
        }
        else if(checkExistenceInDatabase(nu)==true){
            cout << "Number Already exists in database" << endl;
        }
        else if(checkExistenceInDatabase(nu)==false){
            cout << "Adding Number to database..." << endl;
            phoneNum = nu;
            break;
        }
    }
    phone myphone;
    myphone.add(phoneNum);
    cout << "Adding phone number to database ends successfully" << endl;
    return;
}
void a2(){
    cout << "Selected 2 - discussing possible possibilites" << endl;
    string numm;
    while(true){
        cout << "Input number: ";
        string nu; cin >> nu;
        if(checkExit(nu)==true){
            return;
        }
        else if(checkExistenceInDatabase(nu)==false){
            cout << "Number doesn't exist in database." << endl;
        }
        else if(checkExistenceInDatabaseBlock(nu)==true){
            cout << "Number is blocked!" << endl;
        }
        else{
            cout << "Redirecting..." << endl;
            numm = nu;
            break;
        }
    }
    cout << "////////////////////////////////"<< endl;
    cout << "            BEELINE"<< endl;
    cout << "////////////////////////////////"<< endl;
    cout << "/// Press 0 to return" << endl;
    cout << "/// Press 1 to redirect to 'Special Offer'"<< endl;
    cout << "/// Press 2 to redirect to 'My Balance'" << endl;
    cout << "/// Press 3 to redirect to package 'Everything MAX'" << endl;
    cout << "/// Press 4 to redirect to 'Internet Packages'" << endl;
    cout << "/// Press 5 to redirect to 'Other Packages'" << endl;
    cout << "/// Press 6 to redirect to 'Money transfer'" << endl;
    while(true){
        cout << "Type Dismiss to exit" << endl;
        string dg; cin >> dg;
        if(checkExit(dg)==true){
            return;
        }
        else if(dg=="0"){
            return;
        }else if(dg=="1"){
            cout << "Redirecting to 'Special Offer'..." << endl;
            SpecialOffer(numm);
        }else if(dg=="2"){
            cout << "Redirecting to 'My Balance'..." << endl;
            MyBalance(numm);
        }else if(dg=="3"){
            cout << "Redirecting to 'Everything MAX'..." << endl;
            EverythingMAX(numm);
        }else if(dg=="4"){
            cout << "Redirecting to 'Internet Packages'..." << endl;
            InternetPackages(numm);
        }else if(dg=="5"){
            cout << "Redirecting to 'Other Packages'..." << endl;
            OtherPackages(numm);
        }else if(dg=="6"){
            cout << "Redirecting to 'Money Transfer'..." << endl;
            MoneyTransfer(numm);
        }
        else cout << "Please use digit from 0 to 6" << endl;//Input number
    }

}
void a3(){//already blocked, not blocked, not in database
    cout << "Selected 3 - block phone number" << endl;
    while(true){
        cout << "Input number: ";
        string nu; cin >> nu;
        if(checkExit(nu)==true){
            return;
        }
        else if(checkExistenceInDatabase(nu)==false){
            cout << "Number doesn't exist in database." << endl;
        }
        else if(alreadyBlocked(nu)==true){
            cout << "Number is already blocked" << endl;
            cout << "If you wish to Unblock this number please type" << endl;
            cout << "'YES'" << endl;
            string conf; cin >> conf;
            if (conf == "YES"){
                phone myphone2;
                myphone2.unblock(nu);
                cout << "Number is succesfully unblocked." << endl;
                break;
            }else cout << "Unblocking Terminated!" << endl;
        }
        else if (alreadyBlocked(nu)==false){
            cout << "If you wish to Block this number please type" << endl;
            cout << "'YES'" << endl;
            string conf; cin >> conf;
            if(conf=="YES"){
                phone myphone1;
                myphone1.block(nu);
                cout << "Number is succesfully blocked." << endl;
                break;
            }else cout << "Blocking process Terminated!" << endl;
        }
    }
}
void a4(){
    cout << "Selected 4 - unblock phone number" << endl;
    while(true) {
        cout << "Input phone number: ";
        string nu; cin >> nu;
        if(checkExit(nu)==true){
            return;
        }
        else if(checkExistenceInDatabase(nu)==false){
            cout << "Number doesn't exist in database." << endl;
        }
        else if(alreadyBlocked(nu)==false){
            cout << "Number is already unblocked" << endl;
            cout << "If you wish to block this number please type" << endl;
            cout << "'YES'" << endl;
            string conf; cin >> conf;
            if (conf == "YES"){
                phone myphone4;
                myphone4.block(nu);
                cout << "Number is succesfully blocked." << endl;
                break;
            }else cout << "Unblocking Terminated!" << endl;
        }
        else if (alreadyBlocked(nu)==true){
            cout << "If you wish to Unblock this number please type" << endl;
            cout << "'YES'" << endl;
            string conf; cin >> conf;
            if(conf=="YES"){
                phone myphone1;
                myphone1.unblock(nu);
                cout << "Number is succesfully Unblocked." << endl;
                break;
            }else cout << "Unblocking process Terminated!" << endl;
        }
    }
}
void a5(){
    cout << "Selected 5 - remove phone number from database" << endl;
    while(true){
        cout << "Input phone number: ";
        string nu; cin >> nu;
        if(checkExit(nu)==true){
            return;
        }
        else if(checkExistenceInDatabase(nu)==true){
            cout << "If you wish to delete number from database please type" << endl;
            cout << "'YES'" << endl;
            string conf; cin >> conf;
            if(conf=="YES"){
                phone myphone5;
                myphone5.remove(nu);
                break;
            }

        }
        else if(checkExistenceInDatabase(nu)==false){
            cout << "Number doesn't exist in database" << endl;
        }
    }
    cout << "Number is succesfully removed from database :(" << endl;
}
int main (){
    string userInput;
    while(true){
        cout << "////////////////////////////////"<< endl;
        cout << "            BEELINE"<< endl;
        cout << "////////////////////////////////"<< endl;
        cout << "/// Press 1 to add phone number to database"<< endl;
        cout << "/// Press 2 to enter phone number and discuss possible features\n";
        cout << "/// Press 3 to block phone number" << endl;
        cout << "/// Press 4 to unblock phone number" << endl;
        cout << "/// Press 5 to remove phone number database" << endl;
        cout << "/// Type EXIT or DISMISS to exit code" << endl;
        cin >> userInput;
        if(checkExit(userInput)==true){
            break;
        }
        else if(userInput=="1"){
            a1();
        }
        else if(userInput=="2"){
            a2();
        }
        else if(userInput=="3"){
            a3();
        }
        else if(userInput=="4"){
            a4();
        }
        else if(userInput=="5"){
            a5();
        }
        // checkInput(userInput);
    }
}