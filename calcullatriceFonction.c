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

//check up de parentethe
void parentheses(char *operation, int nbrchar){
    int i;
    for (i = 0; i != nbrchar; i++)
    {
        if(operation[i] == 40) {
            typeOperation(operation,i,1);
            }
        }
}

void typeOperation(char* operation, int positionDeDebut,int binaire){
    positionDeDebut = positionDeDebut +1;
    if(binaire==1){
        while (operation[positionDeDebut]!= 41)
        {
            if (operation[positionDeDebut] == 43)//reperageg d'un addistion
            {
                additio(operation,positionDeDebut);
                //tu vas fair un addition
            }
            positionDeDebut++;
        }
    }

}

int additio(char *operation,int position) {
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0;
    //int nb[10] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
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
    resulta = nbA + nbB;
    return resulta;
    //decalage();
        //ratation nb


}
void moveAndWrit(char* decalageDeString,int positionA,int positionB, int nb){



}
void move(char* decalageDeString,int positionA,int positionB, int nb){

}

void checkIsAccepted(char *operation, int nbrchar){
    //
    int i = 0, j = 0;
    int nbrDec[14] = {40,41,42,43,45,47,48,49,50,51,52,53,56,57};
    for (i = 0; i < nbrchar; ++i)
    {
        for (j = 0; j <=14 ; ++j)
        {
            if(operation[i] == nbrDec[j])
            {
                i++;
                j=0;
            }
            else if (operation[i] == 10)
            {

            }else if (j == 14){
                write(2, "errore\n", 7);
                exit(0);
            }
        }
    }
}
