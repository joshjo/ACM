#include<iostream>
#include<cmath>
#include<stdlib.h>
#define M 65001

using namespace std;

bool prime[M];
int genprime();
bool fermat(long int);

int primog(){
    unsigned long i,j,s=sqrt(M);
    for(i=2;i<M;i++)
        prime[i]=true;
    for(i=2;i<s;){
        if(prime[i])
            for(j=i+i;j<M;j+=i)
                prime[j]=false;
        for(i++;!prime[i];i++);
    }
    return 0;
}
bool fermat(long int n)
{
    long int a,m,z,y;
    for(a=2;a<n;a++){
        m=n;
        y=1;
        z=a;
        while(m>0){
            while(m%2==0){
                z=(z*z)%n;
                m>>=1;
            }
            m--;
            y=(y*z)%n;
        }
        if(y!=a)return false;
    }
    return true;
}

int main(){
    long int n;
    primog();
    while(cin>>n&&n){
        if(prime[n])
            cout<<n<<" is normal.\n";
        else if(fermat(n))
            cout<<"The number "<<n<<" is a Carmichael number.\n";
        else
            cout<<n<<" is normal.\n";
    }
    exit(0);
}
