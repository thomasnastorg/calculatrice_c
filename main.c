#include <stdio.h>
#include <unistd.h>
//#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "calcullatriceFonction.h"



int main() {
    char monOperation[100];
    do{

    //monOperation = malloc(sizeof(char));
    int *ret;// taille de la chainne
        if (monOperation == NULL)
        {
            exit(0);
        }
        // demande a l'utilisateur de saisire
        write(1, "ecriver votre calcule:\n", 23);
       ret = read(0,monOperation,50);
        //char str2[ret];
        //strcpy(str2, monOperation);

        //parentheses(monOperation, ret);
      //  printf("%s\n",monOperation);
    checkIsAccepted(monOperation,ret);

    parentheses(monOperation,ret);
    typeOperation(monOperation,0,0,ret);
    printf("%s",monOperation);
    } while (monOperation[0] != 101 && monOperation[1] != 120 && monOperation[2] != 105 && monOperation[3] != 116);
    return 0;
}


