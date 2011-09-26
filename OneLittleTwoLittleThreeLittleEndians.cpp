#include <iostream>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

vector<int> cambiaAvector(list<int> a){
	vector<int> rpta;
	list<int> :: iterator ii;
    for(ii=a.begin();ii!=a.end();ii++)
	rpta.push_back(*ii);
	return rpta;
}

list<int> sumar(vector<int> a, vector<int> b){
    list <int> res;
    int conta=0;
    for(int i=a.size(),j=b.size();i>0;i--,j--){
        if(a[i-1]==0 && b[j-1]==0){
            if(conta==0)
                res.push_front(0);
            else{
                res.push_front(1);
                conta=0;
            }
        }
        if( a[i-1]==1 && b[j-1]==1 )
        {
            if(conta==1){
                res.push_front(1);
                conta=1;
            }
            else{
                res.push_front(0);
                conta=1;
            }
        }
        if( (a[i-1]==0 && b[j-1]==1) || (a[i-1]==1 && b[j-1]==0)){
            if(conta==0){
                res.push_front(1);
            }
            else{
                res.push_front(0);
                conta=1;
            }
        }
    }
    if(conta==1)
    res.push_front(1);
    return res;
}

vector <int> cambiarAnegativo(vector<int> &a){
    vector<int> aa;
    vector <int> :: iterator i;
    for(i=a.begin();i<a.end();i++){
        if(*i==0)
        aa.push_back(1);
        else{
            if(*i==1)
                aa.push_back(0);
        }
	}
	vector<int> uno;
	for(int i=0;i<(a.size())-1;i++)
       uno.push_back(0);
    uno.push_back(1);
    list<int> nuevo=sumar(aa,uno);
    vector<int> rpta;
    list<int> :: iterator ii;
    for(ii=nuevo.begin();ii!=nuevo.end();ii++)
		rpta.push_back(*ii);
    return rpta;
}

vector<int> convertirBits(long num){
    vector<int> aux;
    vector<int > aux2;
    int a=32;
    if(num>0){
        while(a>1){
            aux.push_back(num%2);
            num/=2;
            a--;
        }
        aux.push_back(num);
        for(int i=aux.size()-1;i>=0;i--){
            aux2.push_back(aux[i]);
        }
        return aux2;
    }
    else
    {
        num=num-(num+num);
        while(a>1){
            aux.push_back(num%2);
            num/=2;
            a--;
        }
        aux.push_back(num);
        for(int i=aux.size()-1;i>=0;i--)
            aux2.push_back(aux[i]);
        return cambiarAnegativo(aux2);
    }
}

long convertirAnum(vector< vector<int> > a){
    vector<int>aux;
    long num=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<8;j++)
           aux.push_back(a[i][j]);
           
    for(int i=0,j=31;i<32;i++,j--)
        if(aux[i]== 1)
            num=num+pow(2,j);

    return num ;
}

void imprimirVector(vector<int> a){
    for(int i=0;i<a.size();i++)
        if((i+1)%8!=0)
            cout<<a[i]<<" ";
        else
            cout<<a[i]<<"  ";
}

void imprimirVectorDvec(vector< vector<int> >a){
    for(int i=0;i<a.size();i++)
        imprimirVector(a[i]);
}

vector<vector<int> > devolver(vector<int> a){
    vector<int> uno;
    vector<int> dos;
    vector<int> tres;
    vector<int> cuatro;
    vector<vector<int> > rpta;
    for(int j=0;j<8;j++)
        uno.push_back(a[j]);
    for(int j=8;j<16;j++)
        dos.push_back(a[j]);
    for(int j=16;j<24;j++)
        tres.push_back(a[j]);
    for(int j=24;j<32;j++)
        cuatro.push_back(a[j]);
    rpta.push_back(cuatro);
    rpta.push_back(tres);
    rpta.push_back(dos);
    rpta.push_back(uno);
    return rpta;
}

int main()
{
    long numero;
    while (cin >> numero){
		cout << numero << " converts to " << convertirAnum(devolver(convertirBits(numero))) << endl;
	}
    return 0;
}
