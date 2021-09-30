#include <stdio.h>
#include <unistd.h>
//#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "calcullatriceFonction.h"

int main(int argc, char *argv[]) {

    char *monOperation=NULL;
    monOperation = malloc(sizeof(char));
    int ret;// taille de la chainne
        if (monOperation == NULL)
        {
            exit(0);
        }
        // demande a l'utilisateur de saisire
        write(1, "ecriver votre calcule:\n", 23);
       ret = read(0,monOperation,50);
        char str2[ret];
        strcpy(str2, monOperation);

        //parentheses(monOperation, ret);
       //printf("%s",monOperation);
  //  checkIsAccepted(str2,ret);

    additio(str2,2);
     free(monOperation);

    return 0;
}