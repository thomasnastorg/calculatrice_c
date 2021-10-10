//
// Created by thomas on 25/09/2021.
//

#include "myFunction.h"
#include <iostream>
#include <unistd.h>
#include <sys/fcntl.h>
void myPutnbr(int nb);
char* mySrcpy(char *dest,const char str);
char myStrncpy(char* dest,const char* str , int nb);
int myStrcmp(const char *S1,const char S2);

void myputchar(char c){
    write(1,&c,1);
}

void myPutnbr(int nb){
    int b = 0;
    if(nb<0){
        myputchar('_');
        nb= nb;
    }
    if(nb<10){
        myputchar(nb + '0');
    }else if (nb > 9){
        myPutnbr(nb/10);
        b=nb%10;
        myputchar(b+'0');
    }

}

char mySrcpy(char* dest,const char* str){
    int i = 0;

    while (str[i] != '\0'){
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;

}
char* myStrncpy(char* dest,const char* str , int nb){
    int i = 0;

    while (i != nb){
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;

}
int myStrcmp(const char *S1,const char S2){

    while (S1 && *S1 == S2){
        ++S1;
        ++S2;
    }
    (int)(unsigned char)(S1) - (int)(unsigned char)(S2);
    if (((int)(unsigned char)(S1) - (int)(unsigned char)(*S2)) == 0){
        return 0;
    } else{
        return 1;
    }
}


void my_reverse(char str[], int len)
{
    int start, end;
    char temp;
    for(start=0, end=len-1; start < end; start++, end--) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
    }
}

char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;


    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }


    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
        num = num/base;
    }


    if (isNegative){
        str[i++] = '-';
    }

    str[i] = '\0';

    my_reverse(str, i);

    return str;
}