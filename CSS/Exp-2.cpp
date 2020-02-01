#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define For(i,n) for(int i=0;i<n;i++)

int main()
{
    string key,pt,ct;
    int t,i,j,k,lenk,lenm,row;

    cout<<"Enter a key: ";
    cin>>key;
    lenk=key.length();
    int keyarr[lenk];
    For(i,lenk){
        keyarr[i]=key[i]-97;
    }
    cout<<"Enter Message to be encrypted: ";
    getline(cin,pt);
    getline(cin,pt);
    lenm=pt.length();
    k=0;
    For(i,lenm){
        if(pt[i]==' '){
            ct.push_back(95);
        }else{
            ct.push_back((pt[i]-97+keyarr[k%lenk])%26+97);
            k++;
        }
    }
    cout<<"The message after Substitution Cipher is: "<< ct<<endl;
    
    row=(lenm+4)/5;
    int tr[row][5];
    k=0;
    For(i,row){
        For(j,5){
            if(ct[k]=='\0')
                tr[i][j]='_';
            else
                tr[i][j]=ct[k++];
        }
    }
    cout<<"Transpose Matrix:\n";
    For(i,row){
        For(j,5){
            printf("%c ",tr[i][j]);
        }
        cout<<'\n';
    }
    
    cout<<"Message after Transposition Cipher is: ";
    For(i,5){
        For(j,row){
            printf("%c",tr[j][i]);
        }
    }
    cout<<"\nDecrypted Message is: ";
    k=0;
    t=0;
    For(i,row){
        For(j,5){
            if(tr[i][j]=='_'){
                pt[k++]=' ';
            }
            else{
                pt[k++]=(tr[i][j]-97-keyarr[t%lenk]+26)%26+97;
                t++;
            }
        }
    }
    cout<<pt;
    
    return 0;
}
