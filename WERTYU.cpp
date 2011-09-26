#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#define SIZE 26

using namespace std;

typedef map <char,char> Map;

string alpha = "*QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

bool notValid(char c){
    if (c == ' ' || c == 'Q' || c == 'A' || c == 'Z') return true;
    return false;
}

void fillMap (Map & M){
    int size = alpha.size();
    for (int i = 1; i < size; ++i)
        M[alpha[i]] = alpha[i-1];
}

int charsize (char * str){
    int size = 0;
    while (str[size++] != 0);
    return --size;
}

char * questWord (char * str, Map & M){
    int size = charsize(str);
    char * res = new char [size + 1];
    for (int i = 0; str[i] != 0; ++i){
        if (notValid(str[i]));
        else
            res[i] = M[str[i]];
    }
    res[size] = 0;
    return res;
}

int main()
{
    Map M;
    fillMap (M);
    char cad [1000];
    while (getline(cad)){
//        cout << charsize(cad) << endl;
//        printf ("%s5\n",cad);
        char * str2 = questWord(cad,M);
        cout << str2 << endl;
    }
    return 0;
}
