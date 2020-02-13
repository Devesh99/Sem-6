#include <bits/stdc++.h> 
using namespace std; 
  
struct MDT{
    int index;
    string defn;
};

struct ALA{
    int ind;
    string args;
};

ALA a[10];
MDT m[10];
int ap=0;
int mp=0;
void pass1(string mn){
    string s,word;
    int index=0;
    int i,flag;
    string arg;
    
    m[mp].index=index;
    m[mp].defn=mn;
    m[mp].defn+=" &arg1";
    mp++;
    index++;

    cin>>arg;
    a[ap].ind=0;
    a[ap++].args=mn;
    cout <<arg;
    
    flag=0;
    string s1,s2,s3;
    cin>>s1;
    cin>>s1;
    cout<<'\n';
    while(s1!="ENDM"){
        cout<<s1<<" ";
        cin>>s1;
        if(s1=="/"){
            m[mp].index=index;
            index++;
            mp++;
            cout<<'\n';
            cin>>s1;
        }
        if(s1==arg){
            m[mp].defn+=" #1";
        }
        else{
            m[mp].defn+=" ";
            m[mp].defn+=s1;
        }
    }
    cout<<s1;
}
void rep(string s2){
    for(int i=0;i<mp;++i){
        cout<<m[i].defn<<'\n';
    }
}

int main() 
{ 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t,i,n,j;
    string s1,s2,mname="";
    cin>>s1;
    cin>>s1;
    while(s1!="end"){
        cout<<s1<<" ";
        s2=s1;
        cin>>s1;
        if(s1=="/"){
            cout<<'\n';
            cin>>s1;
        }
        if(s1=="macro"){
            mname=s2;
            cout<<s1<<" ";
            pass1(s2);
            
            s1=" ";
        }
        if(s1==mname){
            cin>>s2;
            rep(s2);
            s1=" ";
        }

        
    }
    cout<<s1;
    cout<<"\n\nContents of MDT:\nIndex\tMacro Defn\n\n";
    for(i=0;i<=mp;++i){
        cout<<m[i].index<<'\t'<<m[i].defn<<'\n';
    }

    cout<<"\nContents of ALA is:\nIndex\tMacro Name\n";
    for(i=0;i<=ap;++i){
        cout<<a[i].ind<<"\t"<<a[i].args<<'\n';
    }
    return 0; 
} 

/*Input file
/ model small
/ data
/ M1 DB "WELCOME$"
/ M2 DB "TCET$"
/ code 
/ Disp macro XX
/ MOV AH, 09
/ Lea DX, XX
/ INT 21 H
/ ENDM
/ startup
/ Disp M1
/ Disp M2
/ exit
/ end*/
