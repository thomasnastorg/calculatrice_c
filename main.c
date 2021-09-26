#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include "calcullatriceFonction.h"

int main(int argc, char *argv[]) {

    char *monOperation=NULL;
    monOperation = malloc(sizeof(char));

        if (monOperation == NULL)
        {
            exit(0);
        }
        // demande a l'utilisateur de saisire
        write(1, "ecriver votre calcule:\n", 23);
        scanf("%s", monOperation);



        free(monOperation);

    return 0;
}