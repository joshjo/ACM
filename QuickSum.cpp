#include <iostream>
#include <stdlib.h>
#define SIZE 256

using namespace std;

bool notValid(char ch){
    if (ch == ' ' || ch == '\n') return true;
    return false;
}

int quickSum(char * str){
    int sum = 0;
    int i = 0;
    if (*str == '#') exit(1);
    while (str[i] != 0){
        if (!notValid(str[i])){
            sum += (str[i] - 'A' + 1)*(i+1);
        }
        i++;
    }
    return sum;
}

int main()
{
    char str [SIZE];
    while (str[0] != '#'){
        cin.getline(str,SIZE);
        cout << quickSum(str) << endl;
    }
    return 0;
}
