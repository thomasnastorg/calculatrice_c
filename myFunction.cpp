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