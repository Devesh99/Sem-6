#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define deb(x) cout << #x << " " << x << endl;

typedef long long ll;
const ll mod = 1000000007;

#define For(i,n) for(int i=0;i<n;i++)
int gcd(int a,int b){
    if(!b)
        return a;
    return gcd(b,a%b);
}

int modInverse(int a, int m) 
{ 
    a = a%m; 
    for (int x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
} 
int poww(int a,int b,int n){
	int res=1;
	while(b){
		res=(res*a)%n;
		b--;
	}
	return res;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,i,n,phi,j,e,d;
    int p,q;
    cout<<"Enter P and Q: ";
    cin>>p>>q;
    n=p*q;
    deb(n);
    phi=(p-1)*(q-1);
    deb(phi);
    for(i=2;i*i<phi;++i){
        j=gcd(i,phi);
        if(j==1){
            e=i;
            break;
        }
    }deb(e);
    d=modInverse(e,phi);
    deb(d);
    string m;
    cout<<"Enter message string: ";
    cin>>m;
    
    string c;
	string z;
	int xy;
	cout<<"Encrypted Message is: ";
    for(i=0;i<m.length();++i){
        xy=poww(m[i]-96,e,n);

        c+=xy;
	cout<<xy<<' ';
    }
	cout<<"\nDecrypted Message is: ";
	for(i=0;i<c.length();++i){
		xy=poww(c[i],d,n);
		z+=(xy+96);
	}
	cout<<z<<endl;
    
    return 0;
}
