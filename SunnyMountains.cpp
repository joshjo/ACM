#include <iostream>
#include <math.h>
#include <vector>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

vector < pair < int , int > > puntosDpicos;

float distanciaEuclidiana(int x1, int y1, int x2, int y2)
{
    return pow((pow( x2-x1 ,2) + pow( y2-y1 ,2)),0.5);
}

void llenar(int x, int y){
    pair<int,int> prueba;
    prueba.first=x;
    prueba.second=y;
    puntosDpicos.push_back(prueba);
}

void llenarVector(int tam){
    int x,y;

    for(int i=0;i<tam;i++){
        cin>>x>>y;
        llenar(x,y);
    }
}

void imprimirVector(){
    for(int i=0;i<puntosDpicos.size();i++){
        cout<<"<"<<puntosDpicos[i].first<<","<<puntosDpicos[i].second<<">"<<endl;
    }
}

void ordenarPuntos(vector< pair<int,int> >){
    pair<int,int> aux;
    for(int j=0; j<puntosDpicos.size();j++){
        for(int i=0;i<puntosDpicos.size()-j;i++){
            if(puntosDpicos[i].first > puntosDpicos[i+1].first){
                aux=puntosDpicos[i];
                puntosDpicos[i]=puntosDpicos[i+1];
                puntosDpicos[i+1]=aux;
            }
        }
    }
}

float sumarPuntos(){
    int xRefe;
    int yRefe;
    float distanRefe;
    float suma=0;
    float pedazoAsumar;
    float disPunApun;
    float disPedaRefe;
    int j=1,i=0;
	while(j<=puntosDpicos.size()-1){
		j++;
		j=i+j;
		if(puntosDpicos[(puntosDpicos.size()-1)-i].second < puntosDpicos[(puntosDpicos.size()-1)-(j)].second){
			if(i==0){
				suma=distanciaEuclidiana(puntosDpicos[(puntosDpicos.size()-1)-i].first,
										 puntosDpicos[(puntosDpicos.size()-1)-i].second,
										 puntosDpicos[(puntosDpicos.size()-1)-(j)].first,
										 puntosDpicos[(puntosDpicos.size()-1)-(j)].second);
			}
			else
			{
				xRefe=puntosDpicos[(puntosDpicos.size()-1)-(i+j)].first ;
				yRefe=puntosDpicos[(puntosDpicos.size()-1)-((i+j)-1)].second;
				distanRefe=puntosDpicos[(puntosDpicos.size()-1)-(i+j)].second - yRefe;
				disPunApun=distanciaEuclidiana(puntosDpicos[(puntosDpicos.size()-1)-((j)-1)].first,
											   puntosDpicos[(puntosDpicos.size()-1)-((j)-1)].second,
											   puntosDpicos[(puntosDpicos.size()-1)-(j)].first,
											   puntosDpicos[(puntosDpicos.size()-1)-(j)].second
											   );
				disPedaRefe=puntosDpicos[(puntosDpicos.size()-1)-(i+j)].second - puntosDpicos[(puntosDpicos.size()-1)-i].second;
				pedazoAsumar=(disPedaRefe*disPunApun)/distanRefe;
				suma=suma+pedazoAsumar;
			}
			i = j;
			j = i+1;
		}
    }
    return suma;
}

int main(){
    llenarVector(2);
    imprimirVector();
    cout<<endl;
    ordenarPuntos(puntosDpicos);
    imprimirVector();
    cout<<sumarPuntos();
    return 0;
}
