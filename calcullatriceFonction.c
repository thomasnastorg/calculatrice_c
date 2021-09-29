//
// Created by Thomas on 23/09/2021.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calcullatriceFonction.h"


void typeOperation(char *operation, int i, bool b);

// fonction pour determinet la longeur de caracter
int contsize(char *string){
    int i;
    for ( i=0; string[i] != 0; i++)
    {

    }
    return i;
}

//check up de parentethe
void parentheses(char *operation, int nbrchar){
    int i;
    for (i = 0; i != nbrchar; i++)
    {
        if(operation[i] == 40) {
            typeOperation(operation,i,true);
            }
        }
}

void typeOperation(char* operation, int positionDeDébut, bool parentheses){
    positionDeDébut = positionDeDébut +1;
    if(parentheses=true){
        while (operation[positionDeDébut]!= 41)
        {
            if (operation[positionDeDébut] == 43)//reperageg d'un addistion
            {
                additio(operation,positionDeDébut);
                //tu vas fair un addition
            }
            positionDeDébut++;
        }
    }

}

void additio(char *operation,int position) {
    int PremierPositionD, secondPositionD, PremierPositionA, secondPositionA,nbA=0,nbB=0,nbAdd=0, resulta = 0;
    int nb[9] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    PremierPositionD = position - 1;
    PremierPositionA = position + 1;
    int i = position -1;
    for (int j = 0; j < 9; ++j) {
        if (operation[i] == nb[j]) {
            i--;
        } else if (j == 9) {
            secondPositionD = i + 1;
        }
    }
    i = position +1;
    for (int j = 0; j < 9; ++j) {
        if (operation[i] == nb[j]){
        i++;
    } else if(j == 9 )
    {
            secondPositionA = i -1;
    }
}
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
    //decalage();
        //ratation nb


}
void moveAndWrit(char* decalageDeString,int positionA, positionB,nb){



}
void checkIsAccepted(char*  operation, int nbrchar){
    //
    int i = 0, j = 0;
    int nbrDec[13] = {40,41,42,43,45,47,48,49,50,51,52,53,56,57};
    for (i = 0; i < nbrchar; ++i)
    {
        for (j = 0; j <=13 ; ++j)
        {
            if(operation[i] == nbrDec[j])
            {
                i++;
                j=0;
            }
            else if (operation[i] == 10)
            {

            }else if (j == 13){
                write(2, "errore\n", 7);
                exit(0);
            }
        }
    }
}
