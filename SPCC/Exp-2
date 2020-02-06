#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define deb(x) cout << #x << " " << x << endl;

#define For(i,n) for(int i=0;i<n;i++)

int lc=0;
struct MOT{
    string mop;
    int bop;
    string ilen;
    string iformat;
};

struct Symbol{
    string val;
    int slen;
    char ra;
};

struct Literal{
    string val;
    int llen;
    char ra;
};

struct Base{
    char avail;
    string content;
};


struct objcode{
    int ra;
    string pass1;
    string pass2;
}obj[20];
int pp=-1;


map<string, MOT> mot;
map<string, string> pot;
map<string, Symbol> sym;
map<string, Literal> lit;
map<int, Base> basetab;

void createMOT(){
    MOT m1={"A",0x5A,"10","001"};
    MOT m2={"AH",0x4A,"10","001"};
    MOT m3={"L",0x5F,"10","001"};
    
    mot.insert({"A",m1});
    mot.insert({"AH",m2});
    mot.insert({"L",m3});
}
void createPOT(){
   pot.insert({"START","P1START"});
   pot.insert({"DROP","P1DROP"});
   pot.insert({"EQU","P1EQU"});
   pot.insert({"END","P1END"});
   pot.insert({"USING","P1USING"});
   pot.insert({"DC","P1DC"});
}
void createBaseTab(){
    Base b1={'N',"-"}; Base b2={'N',"-"}; Base b3={'N',"-"}; Base b4={'N',"-"};
    Base b5={'N',"-"}; Base b6={'N',"-"}; Base b7={'N',"-"}; Base b8={'N',"-"};
    Base b9={'N',"-"}; Base b10={'N',"-"}; Base b11={'N',"-"}; Base b12={'N',"-"};
    Base b13={'N',"-"}; Base b14={'N',"-"}; Base b15={'N',"-"};
    basetab.insert({1,b1}); basetab.insert({2,b2}); basetab.insert({3,b3});
    basetab.insert({4,b4}); basetab.insert({5,b5}); basetab.insert({6,b6});
    basetab.insert({7,b7}); basetab.insert({8,b8}); basetab.insert({9,b9});
    basetab.insert({10,b10}); basetab.insert({11,b11}); basetab.insert({12,b12});
    basetab.insert({13,b13}); basetab.insert({14,b14}); basetab.insert({15,b15});
}

string s1,s2,s3;
void getnew(){
    cin>>s1>>s2>>s3;
}

int main() {
    int i,num,len,basen;
    string buff,temp,sz;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    createMOT();
    createPOT();
    createBaseTab();
    //category c1={0,"LOL"};
    //categories.insert( {"Pit", c1});
    //categories[2] = {2, "Second category"};
    //cout<<categories["Pit"].name;
    
    
    //First Line
    getline(cin,s1);
    getnew();
    Symbol s={"0",1,'R'};
    sym.insert({s1,s});
    if(s3=="-")
        lc=0;
    else
        lc=stoi(s3);
        
    obj[++pp].ra=lc;
    obj[pp].pass1="__";
    obj[pp].pass2="__";

    //Second Line
    getnew();  
    i=0;
    while(s3[i]!=',')
        buff.push_back(s3[i++]);
    i++;
    while(s3[i]!='\0')
        temp.push_back(s3[i++]);
    num=stoi(temp);
    basen=num;
    basetab[num].avail='Y';
    basetab[num].content=buff;
    obj[++pp].ra=lc;
    obj[pp].pass1="__";
    obj[pp].pass2="__";
    
    //Third Line to End
    obj[++pp].ra=lc;
    while(1){
        getnew();
        if(s2=="END"){
            obj[pp].pass1="-";
            break;
        }
        if(mot.find({s2}) != mot.end()){
            if(mot[s2].ilen=="01"){
                lc+=2;
            }else if(mot[s2].ilen=="10"){
                lc+=4;
            }else{
                lc+=6;
            }
            obj[pp].pass1=s2+" _,_";
        }
        else if(pot.find({s2})!=pot.end()){
            if(s3[0]=='F'){
                lc+=4;
                len=4;
            }
            else if(s3[0]=='H'){
                lc+=2;
                len=2;
            }
            num=s3[2]-'0';
            s={to_string(lc),len,'R'};
            sym.insert({s1,s});
            obj[pp].pass1=to_string(num);
            Literal l={to_string(lc),len,'R'};
            lit.insert({s3,l});
        }
        obj[++pp].ra=lc;
    }
    
    //PASS2
    pp=2;
    getnew();getnew();
    while(1){
        getnew();
        if(s2=="END"){
            obj[pp].pass2="-";
            break;
        }
        if(mot.find({s2}) != mot.end()){
            sz=s3.substr(2);
            obj[pp].pass2=s2+" ";
            obj[pp].pass2+=s3[0];
            obj[pp].pass2+=", ";
            obj[pp].pass2+=sym[sz].val;
            obj[pp].pass2+="(0, ";
            obj[pp].pass2+=to_string(basen);
            obj[pp].pass2+=")";
        }
        else if(pot.find({s2})!=pot.end()){
            int x=s3[2]-'0';
            if(x==5)
                obj[pp].pass2="0101";
            if(x==4)
                obj[pp].pass2="0100";
        }
        pp++;
    }
    cout<<"RA(LC)\t\tPass 1\t\tPass 2\n";
    for(i=0;i<=pp;++i){
        cout<<obj[i].ra<<"\t\t"<<obj[i].pass1<<"         "<<obj[i].pass2<<endl;
    }

    cout<<"Mnemonic Opcode Table is:\nM opcode\tb opcode\ti len\tinstr format\n";
    for(auto i:mot){
        cout<<i.second.mop<<"\t\t\t"<<i.second.bop<<"\t\t\t"<<i.second.ilen<<"\t\t\t"<<i.second.iformat<<endl;
    }
    cout<<"\nPseudo Opcode Table is:\n\npseudo opcode\tRoutine Address\n";
    for(auto i:pot){
        cout<<i.first<<"              "<<i.second<<endl;
    }

    cout<<"\nSymbol Table is:\nSymbol\tValue\t Lenght\t R/A\n";
    for(auto i:sym){
        cout<<setw(1)<<i.first<<"    "<<i.second.val<<"       "<<i.second.slen<<"        "<<i.second.ra<<endl;
    }

    cout<<"\nLiteral Table is:\nLiteral \tValue\t Lenght\t R/A\n";
    for(auto i:lit){
        cout<<setw(1)<<i.first<<"      "<<i.second.val<<"       "<<i.second.llen<<"        "<<i.second.ra<<endl;
    }
    cout<<"\nBase Table is:\nReg Avail \tContent of Base Reg\n";
    for(auto i:basetab){
        cout<<i.first<<"     "<<i.second.avail<<"       "<<i.second.content<<"        "<<endl;
    }
    return 0;
}

/*Input.txt
Label    Mnemonic       Operand
PG1         START       -
-           USING       *,15
-           L           1,FIVE
-           A           1,FOUR
FIVE        DC          F'5'
FOUR        DC          F'4'
-           END         -

PG1         START       -
-           USING       *,15
-           L           1,FIVE
-           A           1,FOUR
FIVE        DC          F'5'
FOUR        DC          F'4'
-           END         -
*/
