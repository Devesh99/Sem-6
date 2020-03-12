#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string a[20][4];
int t=-1;
int t9=0;

int main()
{
    cout<<"Enter a Expression: ";
    string ex,ex1;
    string op1,op2;
    char e;
    int i;
    cin>>ex;
    for(i=2;i<ex.size();++i){
        if((ex[i-1]=='^'||ex[i-1]=='*'||ex[i-1]=='-'||ex[i-1]=='+'||ex[i-1]=='/')&&ex[i]=='-'){
            t++;
            //ex.erase(std::remove(ex.begin(),ex.end(),'-'),ex.end());
            t9++;
            ex1.append("t"+to_string(t9));
            int z=i+1;
            int cc=0;
            op2="";
            while(ex[z]!='^'||ex[z]!='*'||ex[z]!='-'||ex[z]!='+'||ex[z]!='/'){
                cc++;
                z++;
            }
            z=i+1;
            op2.append(ex,i+1,cc);
            
            a[t][0]="uminus"; a[t][1]=op2; a[t][2]=" "; a[t][3]="t"+to_string(t);
            //ex.erase(std::remove(ex.begin(),ex.end(),'-'),ex.end());
            op1="";
        }
    }
        else if(ex[i]=='^'){
            t++;
            t9++;
            ex1.append("t"+to_string(t9));
            ex1+='^';
            t9++;
            ex1.append("t"+to_string(t9));
            
            int z=i+1;
            int cc=0;
            op2="";
            while(ex[z]!='^'||ex[z]!='*'||ex[z]!='-'||ex[z]!='+'||ex[z]!='/'){
                cc++;
                z++;
            }
            z=i+1;
            op2.append(ex,i+1,cc);
            
            a[t][0]+=ex[i]; a[t][1]=op2; a[t][2]=" "; a[t][3]="t"+to_string(t);
            
            
            op1="";
        }
        else{
            op1.push_back(ex[i]);
        }
    }
    return 0;
}
