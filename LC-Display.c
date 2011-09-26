#include <stdio.h>
#include <stdlib.h>

char B = '|';
char G = '-';
char S = ' ';
char L = '\n';

void initNum(char ** string, int size){
    int i, pos = 0;
    int sizeH = size + 3;
    int sizeV = (size * 2)+3;
    size_t tam = sizeH*sizeV + 1;
    (*string) = (char*)malloc(tam*sizeof(char));
    for (i = 0; i < tam-1; ++i)
       (*string)[i] = '#';
    (*string)[tam-1] = '\0';
}

void spaceHorizontal (char ** string, int * pos, int size){
    int i;
    int k = (*pos);
    int tam = size + 2;
    for (i = 0; i < tam; ++i)
        (*string)[k++] = S;
    (*string)[k++] = L;
    *pos = k;
}

int drawHorizontal (char ** string, int * pos, int size){
    int i;
    int k = *pos;
    (*string)[k++] = S;
    for (i = 1; i < size + 1; ++i)
        (*string)[k++] = G;
    (*string)[k++] = S;
    (*string)[k++] = L;
    *pos = k;
}

void drawVertical (char ** string, int * pos, int size){
    int i, j, k;
    k = *pos;
    int tam = size + 1;
    for (j = 0; j < size; ++j){
        (*string)[k++] = B;
        for (i = 1; i < tam; ++i)
            (*string)[k++] = S;
        (*string)[k++] = B;
        (*string)[k++] = L;
    }
    *pos = k;
}


void drawVerticalRight (char ** string, int * pos, int size){
    int i, j, k;
    k = *pos;
    int tam = size + 1;
    for (j = 0; j < size; ++j){
        for (i = 0; i < tam; ++i)
            (*string)[k++] = S;
        (*string)[k++] = B;
        (*string)[k++] = L;
    }
    *pos = k;
}

void drawVerticalLeft (char ** string, int * pos, int size){
    int i, j, k;
    k = *pos;
    int tam = size + 1;
    for (j = 0; j < size; ++j){
        (*string)[k++] = B;
        for (i = 0; i < tam; ++i)
            (*string)[k++] = S;
        (*string)[k++] = L;
    }
    *pos = k;
}

void draw0 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    drawHorizontal(string,&pos,size);
    drawVertical(string,&pos,size);
    spaceHorizontal(string,&pos,size);
    drawVertical(string,&pos,size);
    drawHorizontal(string,&pos,size);
}

void draw1 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    spaceHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    spaceHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    spaceHorizontal(string,&pos,size);
}

void draw2 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    drawHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    drawHorizontal(string,&pos,size);
    drawVerticalLeft(string,&pos,size);
    drawHorizontal(string,&pos,size);
}

void draw3 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    drawHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    drawHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    drawHorizontal(string,&pos,size);
}

void draw4 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    spaceHorizontal(string,&pos,size);
    drawVertical(string,&pos,size);
    drawHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    spaceHorizontal(string,&pos,size);
}

void draw5 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    drawHorizontal(string,&pos,size);
    drawVerticalLeft(string,&pos,size);
    drawHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    drawHorizontal(string,&pos,size);
}

void draw6 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    drawHorizontal(string,&pos,size);
    drawVerticalLeft(string,&pos,size);
    drawHorizontal(string,&pos,size);
    drawVertical(string,&pos,size);
    drawHorizontal(string,&pos,size);
}

void draw7 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    drawHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    spaceHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    spaceHorizontal(string,&pos,size);
}

void draw8 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    drawHorizontal(string,&pos,size);
    drawVertical(string,&pos,size);
    drawHorizontal(string,&pos,size);
    drawVertical(string,&pos,size);
    drawHorizontal(string,&pos,size);
}

void draw9 (char ** string, int size){
    int pos = 0;
    initNum(string,size);
    drawHorizontal(string,&pos,size);
    drawVertical(string,&pos,size);
    drawHorizontal(string,&pos,size);
    drawVerticalRight(string,&pos,size);
    drawHorizontal(string,&pos,size);
}

int strLength (char * str){
    int i = 0;
    while (str[i++] != '\0');
    return i--;
}

int findSalto (char ** string){
    int pos = 0;
    while ((*string)[pos++] != L);
    return --pos;
//    printf ("%3i", pos);
}

int calcTam (char ** string1, char ** string2,int size){
    int size1 = strLength(*string1);
    int size2 = strLength(*string2);
    int alto = size*2 + 3;
    int linea = findSalto(string1);
    int nuevoTam = size2 + size1 + 1;
    return nuevoTam;
}

void drawNumber (int num, char ** str, int size){
    if (num < 10){
        if (num == 0) draw0(str,size);
        if (num == 1) draw1(str,size);
        if (num == 2) draw2(str,size);
        if (num == 3) draw3(str,size);
        if (num == 4) draw4(str,size);
        if (num == 5) draw5(str,size);
        if (num == 6) draw6(str,size);
        if (num == 7) draw7(str,size);
        if (num == 8) draw8(str,size);
        if (num == 9) draw9(str,size);
    }
}

void concatString (char ** string1, char ** string2, char nuevo [], int size){
    int alto = size*2 + 3;
    int nuevoTam = calcTam(string1,string2,size);
    int i = 0;
    int j = 0;
    int count = 0;
    while (count < alto){
        while ((*string1)[i] != L){
            nuevo[i+j] = (*string1)[i];
            i++;
        }
        nuevo[i+j] = S;
        i++;
        while ((*string2)[j] != L){
            nuevo[i+j] = (*string2)[j];
            j++;
        }
        nuevo[i+j] = L;
        j++;
        count++;
    }
    nuevo[i+j] = '\0';
}

int calcTam2 (int size, int numeros){
    int alto = size*2 + 3;
    int ancho = size + 3;
    int total = alto*ancho*numeros;
    return total;
}

int digits (int num){
    int count = 0;
    while (num >= 10){
        num = num/10;
        count++;
    }
    return ++count;
}

void printNum (int num,int size){
    int res = 0;
    char numero [calcTam2(size,digits(num))];
    char * str;
    char * str2;
    char * str3;
    res = num % 10;
    num = num / 10;
    drawNumber(res,&str,size);
    res = num % 10;
    num = num / 10;
    drawNumber(res,&str2,size);
    concatString(&str,&str2,numero,size);
    drawNumber(num,&str3,size);
    concatString(&numero,&str3,numero,size);
    printf (numero);
}

int main()
{
    int size = 2;
    int i;
    char * string1;
    char * string2;
    char string3 [66];

//    draw0(&string1,size);
//    draw3(&string2,size);
//    printf("%3i",digits(100));
    printNum(123,2);
//    concatString(&string1,&string2,string3,size);
//    printf(string3);

//    strLength(string);

//    size_t tam = 10;

//    string = (char*)malloc(tam*sizeof(char));
//
//    size_t nuevoTam = 100;
//    realloc (string,nuevoTam*sizeof(char));

//    for (i = 0; i < nuevoTam-1; ++i){
//       string[i] = '0';
//    }
//    string[tam-1] = '\0';
//    string[10] = 'a';
//    printf(string);
//    draw0(&string,size);
//    printf(string);
//    draw1(&string,size);
//    printf(string);
//    draw2(&string,size);
//    printf(string);
//    draw3(&string,size);
//    printf(string);
//    draw4(&string,size);
//    printf(string);
//    draw5(&string,size);
//    printf(string);
//    draw6(&string,size);
//    printf(string);
//    draw7(&string,size);
//    printf(string);
//    draw8(&string,size);
//    printf(string);
//    draw9(&string,size);
//    printf(string);
//    size_t tam = (size*2) + 1;
//    string = (char*)malloc(tam*sizeof(char));
//    for (i = 0; i < tam-1; ++i){
//       string[i] = '0';
//    }
//    int ini = 5;
//    drawVerticalLeft(&string,&ini,2);
//    string[tam-1] = '\0';
//    draw1(&string, 2);
//    spaceHorizontal(&string,0,2);

    return 0;
}
