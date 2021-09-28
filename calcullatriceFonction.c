//
// Created by Thomas on 23/09/2021.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
    for (i = 0; i != nbrchar; i++){
        if(operation[i] == 40){
            printf("il y a une parentehe");
        }
    }
}

void additio(char *operation){

    // tester si nb

}

void checkIsAccepted(char*  operation, int nbrchar){
    //
    int i = 0, j = 0;
    int nbrDec[10] = {40,41,48,49,50,51,52,53,56,57};
    for (i = 0; i < nbrchar; ++i)
    {
        for (j = 0; j <=9 ; ++j)
        {
            if(operation[i] == nbrDec[j])
            {
                i++;
                j=0;
            }
            else if (operation[i] == 10)
            {
                
            }else if (j == 9){
                write(2, "errore\n", 7);
                exit(0);
            }
        }
    }
}
