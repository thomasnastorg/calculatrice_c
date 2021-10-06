//
// Created by Thomas on 23/09/2021.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calcullatriceFonction.h"





// fonction pour determinet la longeur de caracter
int contsize(char *string){
    int i;
    for ( i=0; string[i] != 0; i++)
    {

    }
    return i;
}
void prioriter (){

}

//checkup de parentethe
void parentheses(char *operation, int *nbrchar){
    int nePasDepasser = nbrchar;
    int i;
    for (i = 0; i != nePasDepasser; i++)
    {
        if(operation[i] == 40)
        {
            typeOperation(operation,i,1,nePasDepasser); //EX (125)
            i=0;
        }
    }
    nbrchar = contsize(&nbrchar);
}

void typeOperation(char* operation, int position,int parentheses /* si vrai =1 faux =0*/,int taillTotalle ){

    int positionBis = position +1;

    if(parentheses==1){

        while (operation[positionBis]!= 41)
        {

            if (operation[positionBis] == 43)//reperageg d'un addistion
            {
                additio(operation,positionBis);
                positionBis =position +1;
                //tu vas fair un addition
            } else if(operation[positionBis] == 10 ){
                positionBis =position;
            }
            positionBis++;
        }
        delParentheses(operation,position,positionBis,taillTotalle);
    } else if(parentheses == 0){
        positionBis = 0;
        while (operation[positionBis] != 10){
            if(operation[positionBis] == 42){
                multiplication(operation,positionBis);
                positionBis = position+1;
            } else if(operation[positionBis] == 47){
                division(operation,positionBis);
                positionBis = position+1;
            }
            positionBis++;
        }
        positionBis = 0;
        while (operation[positionBis] != 10){
            if(operation[positionBis] == 43){
                additio(operation,positionBis);
                positionBis = 0;
            } else if(operation[positionBis] == 45){
                soutraction(operation,positionBis);
                positionBis = 0;
            }
            positionBis++;
        }
    }

}
void soutraction(char *operation,int position) {
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0;
    char nb[10]= {"0123456789"};
    PremierPositionD = position - 1;
    PremierPositionA = position + 1;
    int i = position -1;

    // Determination des borne de nbA et nbB
    for (int j = 0; j < 10; ++j) {

        if (operation[i] == nb[j]) {
            secondPositionD = i;
            if (i != 0){
                i--;
                j = 0;
            }
        } else if( j == 10){

        }
    }
    i = position +1;
    int decalageJ = 0;
    for (int j = 0; j < 10; ++j) {
        if(decalageJ == 1){
            j=0;
            decalageJ=0;
        }
        if (operation[i] == nb[j]) {
            secondPositionA = i;
            i++;
            decalageJ=1;
            if(j==9){ // Cas spécial où j=9, on veut continuer le test pour la position suivante, donc on remet j=0 pour continuer le for
                j=0;
            }
        } else if( j == 10 || operation[i]){
            ;//corriger car je ne rentre pas dans la condition
        }
    }
    //composition de a et b
    for (int j = secondPositionD; j <= PremierPositionD ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbA = nbA+nbAdd;
        if(j <PremierPositionD){
            nbA=   nbA * 10;
        }
        nbAdd =0;
    }
    for (int j = PremierPositionA; j <= secondPositionA ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbB = nbB+nbAdd;
        if(j <secondPositionA){
            nbB=   nbB * 10;
        }
        nbAdd =0;
    }
    resulta = nbA - nbB;
    moveAndWrit(operation,secondPositionD,secondPositionA,resulta);
}
void additio(char *operation,int position) {
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0;
    char nb[10]= {"0123456789"};
    PremierPositionD = position - 1;
    PremierPositionA = position + 1;
    int i = position -1;

    // Determination des borne de nbA et nbB
    for (int j = 0; j < 10; ++j) {

        if (operation[i] == nb[j]) {
            secondPositionD = i;
            if (i != 0){
                i--;
                j = 0;
            }
        } else if( j == 10){

        }
    }
    i = position +1;
    int decalageJ = 0;
    for (int j = 0; j < 10; j++) {
        if(decalageJ == 1){
            j=0;
            decalageJ=0;
        }
        if (operation[i] == nb[j]) {
            secondPositionA = i;
            i++;
            decalageJ=1;
            if(j==9){ // Cas spécial où j=9, on veut continuer le test pour la position suivante, donc on remet j=0 pour continuer le for
                j=0;
            }
        } else if( j == 10 || operation[i]){
           ;//corriger car je ne rentre pas dans la condition
        }
}
    //composition de a et b
    for (int j = secondPositionD; j <= PremierPositionD ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbA = nbA+nbAdd;
        if(j <PremierPositionD){
            nbA=   nbA * 10;
        }
        nbAdd =0;
    }
    for (int j = PremierPositionA; j <= secondPositionA ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbB = nbB+nbAdd;
        if(j <secondPositionA){
            nbB=   nbB * 10;
        }
        nbAdd =0;
    }
    resulta = nbA + nbB;
    moveAndWrit(operation,secondPositionD,secondPositionA,resulta);
}

void multiplication(char *operation,int position) {
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0;
    char nb[10]= {"0123456789"};
    PremierPositionD = position - 1;
    PremierPositionA = position + 1;
    int i = position -1;

    // Determination des borne de nbA et nbB
    for (int j = 0; j < 10; ++j) {

        if (operation[i] == nb[j]) {
            secondPositionD = i;
            if (i != 0){
                i--;
                j = 0;
            }
        } else if( j == 10){

        }
    }
    i = position +1;
    for (int j = 0; j < 10; ++j) {

        if (operation[i] == nb[j]) {
            secondPositionA = i;
            if (i != 0){
                i++;
                j = 0;
            }


        } else if( j == 10 || operation[i]){
            ;//corriger car je ne rentre pas dans la condition
        }
    }
    //composition de a et b
    for (int j = secondPositionD; j <= PremierPositionD ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbA = nbA+nbAdd;
        if(j <PremierPositionD){
            nbA=   nbA * 10;
        }
        nbAdd =0;
    }
    for (int j = PremierPositionA; j <= secondPositionA ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbB = nbB+nbAdd;
        if(j <secondPositionA){
            nbB=   nbB * 10;
        }
        nbAdd =0;
    }
    resulta = nbA * nbB;
    moveAndWrit(operation,secondPositionD,secondPositionA,resulta);
}

void division(char *operation,int position) {
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0;
    char nb[10]= {"0123456789"};
    PremierPositionD = position - 1;
    PremierPositionA = position + 1;
    int i = position -1;

    // Determination des borne de nbA et nbB
    for (int j = 0; j < 10; ++j) {

        if (operation[i] == nb[j]) {
            secondPositionD = i;
            if (i != 0){
                i--;
                j = 0;
            }
        } else if( j == 10){

        }
    }
    i = position +1;
    for (int j = 0; j < 10; ++j) {

        if (operation[i] == nb[j]) {
            secondPositionA = i;
            if (i != 0){
                i++;
                j = 0;
            }


        } else if( j == 10 || operation[i]){
            ;//corriger car je ne rentre pas dans la condition
        }
    }
    //composition de a et b
    for (int j = secondPositionD; j <= PremierPositionD ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbA = nbA+nbAdd;
        if(j <PremierPositionD){
            nbA=   nbA * 10;
        }
        nbAdd =0;
    }
    for (int j = PremierPositionA; j <= secondPositionA ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbB = nbB+nbAdd;
        if(j <secondPositionA){
            nbB=   nbB * 10;
        }
        nbAdd =0;
    }
    resulta = nbA / nbB;
    moveAndWrit(operation,secondPositionD,secondPositionA,resulta);
}

void moveAndWrit(char* decalageDeString,int positionA,int positionB, int nb){
    char *transForme;
    char buffer[20];
    int taille, position = positionA, tailleChar, decalageDeFin,fin;

    transForme = itoa(nb, buffer, 10) ;
    taille = contsize(transForme);
    tailleChar = contsize(decalageDeString) ;
    decalageDeFin =positionB +1;
    for (int i = 0; i < taille; ++i) {
        decalageDeString[position] = transForme[i];
        position++;
    }
    for (int i = positionA + taille; i <=tailleChar - positionB+2 ; ++i) {
        decalageDeString[i] =  decalageDeString[decalageDeFin];
        decalageDeFin++;
        fin = i ;
    }

        decalageDeString[fin +1 ] =  NULL;


}
void delParentheses(char *operatio, int positionParenthesesA, int positionParenthesesB,int tailleTotale){
    int incrmentationA = positionParenthesesA,incrmentationB =positionParenthesesA+1;
    for (int i = 0; i < tailleTotale-positionParenthesesA ; ++i)
    {
        operatio[incrmentationA]=operatio[incrmentationB];
        incrmentationA++;
        incrmentationB++;
    }
     incrmentationA = positionParenthesesB-1, incrmentationB =positionParenthesesB;
    for (int i = 0; i < tailleTotale-positionParenthesesB ; ++i)
    {
        operatio[incrmentationA]=operatio[incrmentationB];
        incrmentationA++;
        incrmentationB++;
    }
    operatio[incrmentationB]= NULL;
}
void move(char* decalageDeString,int positionA,int positionB, int nb){

}

void checkIsAccepted(char *operation, int nbrchar){
    //
    int i = 0, j = 0;
    int nbrDec[17] = {32,40,41,42,43,45,47,48,49,50,51,52,53,54,55,56,57};
    for (i = 0; i < nbrchar; ++i)
    {
        for (j = 0; j <=17 ; ++j)
        {
            if(operation[i] == nbrDec[j])
            {
                i++;
                j= -1;
            }
            else if (operation[i] == 10)
            {

            }
            else if(operation[0] == 101 && operation[1] == 120 && operation[2] == 105 && operation[3] == 116){
                exit(0);
            }
            else if (j == 17){
                write(2, "errore\n", 7);
                exit(0);
            }
        }
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