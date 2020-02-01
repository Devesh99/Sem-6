#include <iostream>
#include <cmath>
using namespace std;


float dist(float x,float y,float x1,float y1){
    float mx=(x-x1)*(x-x1);
    float my=(y-y1)*(y-y1);
    return (sqrt(mx+my));
}

int main()
{
    int k=2,i,j,x;
    float dist1,dist2;
    cout<<"Enter Number of data points ";
    cin>>x;
    float a[x][2];
    float p1[x][2];
    float p2[x][2];
    //{{1.0,1.0},{1.5,2.0},{3.0,4.0},{5.0,7.0},{3.5,5.0},{4.5,5.0},{3.5,4.5}};
    cout<<"\nEnter X and Y vlaue of each data point:\n ";
    for(i=0;i<x;++i){
        cin>>a[i][0]>>a[i][1];
    }
    
    
    int pp1=-1;
    int pp2=-1;

    float m1x=a[0][0];
    float m1y=a[0][1];
    float m2x=a[x-1][0];
    float m2y=a[x-1][1];

    float n1x=0.0;
    float n1y=0.0;
    float n2x=0.0;
    float n2y=0.0;
    //while((m1x-n1x)<=0.01&&(m1y-n1y)<=0.01&&(m2x-n2x)<=0.01&&(m2y-n2y)<=0.01){
    int n=20;
       while(n>=0){
        pp1=-1;
        pp2=-1;
        for(i=0;i<x;++i){
            dist1=dist(m1x,m1y,a[i][0],a[i][1]);
            dist2=dist(m2x,m2y,a[i][0],a[i][1]);
            if(dist1-dist2<=0){
                pp1++;
                p1[pp1][0]=a[i][0];
                p1[pp1][1]=a[i][1];
            }
            else{
                pp2++;
                p2[pp2][0]=a[i][0];
                p2[pp2][1]=a[i][1];
            }
        }
        dist1=0.0;
        dist2=0.0;
        for(i=0;i<=pp1;++i){
            dist1+=p1[i][0];
            dist2+=p1[i][1];
        }
        n1x=dist1/(pp1+1);
        n1y=dist2/(pp1+1);
 
        dist1=0.0;
        dist2=0.0;
        for(i=0;i<=pp2;++i){
            dist1+=p2[i][0];
            dist2+=p2[i][1];
        }
        cout<<"it->"<<21-n<<endl;
        n2x=dist1/(pp2+1);
        n2y=dist2/(pp2+1);
        cout<<m1x<<" "<<m1y<<endl;
        cout<<m2x<<" "<<m2y<<endl;
        cout<<endl;
        cout<<n1x<<" "<<n1y<<endl;
        cout<<n2x<<" "<<n2y<<endl;
       n--;
        cout<<endl;
        cout<<"m"<<m1x<<" "<<m1y<<" "<<m2x<<" "<<m2y<<endl;
        cout<<"n"<<n1x<<" "<<n1y<<" "<<n2x<<" "<<n2y<<endl;
    }
    cout<<"Cluster 1 contains: \n";
    for(i=0;i<=pp1;++i){
        cout<<p1[i][0]<<" "<<p1[i][1]<<endl;
    }
    cout<<"Mean  of First cluster "<<"x: "<<n1x<<" y: "<<n1y;
    cout<<"\nCluster 2 contains: \n";
    for(i=0;i<=pp2;++i){
        cout<<p2[i][0]<<" "<<p2[i][1]<<endl;
    }
    cout<<"Mean  of First cluster "<<"x: "<<n2x<<" y: "<<n2y;
    return 0;
}
