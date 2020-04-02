#include <iostream>
#include <string>

using namespace std;

#define deb(x) cout << #x << " " << x << endl;

string a[20][4];
int t=-1;



int main()
{
    cout<<"Enter a Expression: ";
    char prev;
    string lhs="";
    string op1,op2,temp;
    string ex1,ex;
    getline(cin, ex1);
    for(char c:ex1){
        if(c==' '||c=='\t'||c=='\n')
            continue;
        ex.push_back(c);
    }
    char e;
    int z,cc,j,i=0;
    while(ex[i++]!='=');
    lhs=ex.substr(0,i-1);
    ex1="";
    for(;i<ex.size();++i){
        if((ex[i]=='-')&&(ex[i-1]=='^'||ex[i-1]=='*'||ex[i-1]=='-'||ex[i-1]=='+'||ex[i-1]=='/'||ex[i-1]=='=')){
            t++;
            temp="t"+to_string(t);
            ex1.append(temp);
            z=i+1;
            cc=0;
            op2="";
            while(ex[z]!='^'&&ex[z]!='*'&&ex[z]!='-'&&ex[z]!='+'&&ex[z]!='/'){
                cc++;
                z++;
            }
            op2.append(ex,i+1,cc);
            a[t][0]="uminus"; a[t][1]=op2; a[t][2]="-"; a[t][3]=temp;
            op1="";
            i=z-1;
            if(i==ex.size()-1){
                op1="";
                break;
                
            }
        }
        else if(ex[i]=='^'||ex[i]=='*'||ex[i]=='/'||ex[i]=='+'||ex[i]=='-'){
            ex1.append(op1);
            ex1.push_back(ex[i]);
            op1="";
        }
        else{
            op1.push_back(ex[i]);
        }
    }
    ex1.append(op1);
    ex=ex1;
    ex1="";
    op1="";
    prev=' ';
    for(i=0;i<ex.size();++i){
        if(ex[i]=='^'){
            t++;
            temp="t"+to_string(t);
            if(prev=='^'){
                int len=op1.size();
                while(len--){
                    ex1.pop_back();
                }
            }
            ex1.append(temp);
            z=i+1;
            cc=0;
            op2="";
            while((z!=ex.size())&&(ex[z]!='^')&&(ex[z]!='*')&&(ex[z]!='-')&&(ex[z]!='+')&&(ex[z]!='/')){
                cc++;
                z++;
            }
            op2.append(ex,i+1,cc);
            a[t][0]=ex[i]; a[t][1]=op1; a[t][2]=op2; a[t][3]="t"+to_string(t);
            op1=temp;
            i=z-1;
            prev='^';
            if(i==ex.size()-1){
                op1="";
                break;
            }
        }
        else if(ex[i]=='*'||ex[i]=='/'||ex[i]=='+'||ex[i]=='-'){
            if(prev=='^')
                op1="";
            ex1.append(op1);
            ex1.push_back(ex[i]);
            op1="";
            prev='$';
        }
        else{
            op1.push_back(ex[i]);
        }
     }
    ex1.append(op1);
    ex=ex1;
    ex1="";
    op1="";
    
    prev=' ';
     for(i=0;i<ex.size();++i){
        if(ex[i]=='*'||ex[i]=='/'){
            t++;
            temp="t"+to_string(t);
            if(prev=='*'||prev=='/'){
                int len=op1.size();
                while(len--){
                    ex1.pop_back();
                }
            }
            ex1.append(temp);
            z=i+1;
            cc=0;
            op2="";
            while((z!=ex.size())&&(ex[z]!='^')&&(ex[z]!='*')&&(ex[z]!='-')&&(ex[z]!='+')&&(ex[z]!='/')){
                cc++;
                z++;
            }
            op2.append(ex,i+1,cc);
            a[t][0]=ex[i]; a[t][1]=op1; a[t][2]=op2; a[t][3]="t"+to_string(t);
            op1=temp;
            prev=ex[i];
            i=z-1;

            if(i==ex.size()-1){
                op1="";
                break;
                
            }
        }
        else if(ex[i]=='+'||ex[i]=='-'){
            if(prev=='*'||prev=='/')
                op1="";
            ex1.append(op1);
            ex1.push_back(ex[i]);
            op1="";
            prev='$';
        }
        else{
            if(ex[i]=='^'){
                op1="";
            }else{
                op1.push_back(ex[i]);
            }
        }
     }
    ex1.append(op1);
    ex=ex1;
    ex1="";
    op1="";
    prev=' ';
    for(i=0;i<ex.size();++i){
        if(ex[i]=='+'||ex[i]=='-'){
            t++;
            temp="t"+to_string(t);
            if(prev=='+'||prev=='-'){
                int len=op1.size();
                while(len--){
                    ex1.pop_back();
                }
            }
            ex1.append(temp);
            z=i+1;
            cc=0;
            op2="";
            while((z!=ex.size())&&(ex[z]!='^')&&(ex[z]!='*')&&(ex[z]!='-')&&(ex[z]!='+')&&(ex[z]!='/')){
                cc++;
                z++;
            }
            op2.append(ex,i+1,cc);
            a[t][0]=ex[i]; a[t][1]=op1; a[t][2]=op2; a[t][3]="t"+to_string(t);
            op1=temp;
            prev=ex[i];
            i=z-1;
            if(i==ex.size()-1){
                op1="";
                break;
                
            }
            
        }
        else{
           if(ex[i]=='^'||ex[i]=='*'||ex[i]=='/'){
                op1="";
            }else{
                op1.push_back(ex[i]);
            }
        }
    }
    t++;
    a[t][0]="=";
    a[t][1]=a[t-1][3];
    a[t][2]="-";
    a[t][3]=lhs;
    cout<<"\nThe 3 address code is:\n\n";
    cout<<"operator\toperand1\toperand2\tresult\n";
    for(i=0;i<=t;++i){
        for(j=0;j<4;++j){
            cout<<a[i][j]<<"\t\t";
        }
        printf("\n");
    }
    return 0;
}


/*OUTPUT

Enter a Expression:  x= y^h^g*l+y-i/p

The 3 address code is:

operator        operand1        operand2        result
^               y               h               t0
^               t0              g               t1
*               t1              l               t2
/               i               p               t3
+               t2              y               t4
-               t4              t3              t5
=               t5              -               x
*/
