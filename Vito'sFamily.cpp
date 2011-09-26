#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

template <class T>
int vitos (vector <T> & vec){
    sort (vec.begin(),vec.end());
    int size = vec.size();
    int piv = size/2;
    int tmp = 0;
    for (int i = 0; i < size; ++i){
        tmp += abs(vec[i] - vec[piv]);
    }
    return tmp;
}

template <class T>
void printV (vector <T> & vec){
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
}

int main()
{
    vector <int> p;
    int a,b,tmp;
    while (cin>>a){
        for (int k=0;k<a;k++)
        {
            cin>>b;
            for(int y=0;y<b;y++)
            {
                 cin>>tmp;
               p.push_back(tmp);
            }
            cout<<vitos (p) << endl;
            p.clear();
        }

    }
    return 0;
}
