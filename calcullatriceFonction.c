//
// Created by Thomas on 23/09/2021.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calcullatriceFonction.h"


// fonction pour determiner la longeur de caracter
int contsize(char *string)
{
    int i;
    for ( i=0; string[i] != 0; i++)
    {

    }
    return i;
}


//checkup de parentethe
void parentheses(char *operation, int *nbrchar)
{
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

void typeOperation(char* operation, int position,int parentheses /* si vrai =1 faux =0*/,int taillTotalle )
{

    int positionBis = position + 1;
    //---------avec parentheses ---------
    if (parentheses == 1)
    {

        while (operation[positionBis] != 41)
        {

            positionBis = position;
            while (operation[positionBis] != 41)
            {

                if(operation[positionBis] == 94)
                {
                    puissance(operation,positionBis);
                    positionBis = position;
                }
                positionBis++;
            }
            positionBis = position;
            while (operation[positionBis] != 10) {
                if (operation[position + 1] == 45 && positionBis == position + 1 && operation[positionBis] == 45 )
                { // Cas où le nombre à gauche est négatif, càd il y a un '-' en début de chaine
                } else {
                    if (operation[positionBis] == 42) { // Enfin : check si on va multiplier ou diviser
                        multiplication(operation, positionBis);
                        positionBis = position; // Je mets -1 pour qu'en sortant du if, positionBis le mette à 0 pour recommencer un nouveau check de la chaine

                    } else if (operation[positionBis] == 47)
                    {
                        division(operation, positionBis);
                        positionBis = position;
                    }
                }

                positionBis++;
            }
            // ICI ICI
            positionBis = position;
            while (operation[positionBis] != 41)
            {
                if (operation[position + 1] == 45 && positionBis == position + 1 && operation[positionBis] == 45 )
                { // Cas où le nombre à gauche est négatif, càd il y a un '-' en début de chaine
                }
                else
                {
                    if (operation[positionBis] == 43) { // Enfin : check si on va additionner ou soustraire
                        if (operation[positionBis + 1] == 45)
                        {
                            move(operation, positionBis, taillTotalle);
                            positionBis = position;
                        }
                        else
                        {
                            additio(operation, positionBis);
                            positionBis = position; // Je mets -1 pour qu'en sortant du if, positionBis le mette à 0 pour recommencer un nouveau check de la chaine
                        }
                    }
                    else if (operation[positionBis] == 45)
                    {
                        if (operation[positionBis + 1] == 45)
                        {
                            operation[positionBis + 1] = 43;
                            move(operation, positionBis, taillTotalle);
                            positionBis = position;
                        } else
                        {
                            soutraction(operation, positionBis);
                            positionBis = position; // Je mets -1 pour qu'en sortant du if, positionBis le mette à 0 pour recommencer un nouveau check de la chaine
                        }
                    }

                }
                positionBis++;
            }
        }
        delParentheses(operation, position, positionBis, taillTotalle);
    }
    //---------sans parentheses ---------
    else if (parentheses == 0)
    {
        positionBis = 0;
        while (operation[positionBis] != 10)
        {

            if(operation[positionBis] == 94)
            {
                puissance(operation,positionBis);
                positionBis = -1;
            }
            positionBis++;
        }
        positionBis = 1;
        while (operation[positionBis] != 10) {
            if (operation[0] == 45 &&positionBis == 0)
            { // Cas où le nombre à gauche est négatif, càd il y a un '-' en début de chaine
            } else {
                if (operation[positionBis] == 42) { // Enfin : check si on va multiplier ou diviser
                    multiplication(operation, positionBis);
                    positionBis = 0; // Je mets -1 pour qu'en sortant du if, positionBis le mette à 0 pour recommencer un nouveau check de la chaine
                } else if (operation[positionBis] == 47)
                {
                    division(operation, positionBis);
                    positionBis = 0;
                }
            }

            positionBis++;
        }
        // ICI ICI
        positionBis = 1;
        while (operation[positionBis] != 10)
        {
            if (operation[0] == 45 &&
                positionBis == 0) { // Cas où le nombre à gauche est négatif, càd il y a un '-' en début de chaine
            }
            else
            {
                if (operation[positionBis] == 43) { // Enfin : check si on va additionner ou soustraire
                    if (operation[positionBis + 1] == 45)
                    {
                        move(operation, positionBis, taillTotalle);
                        positionBis = 0;
                    }
                    else
                    {
                        additio(operation, positionBis);
                        positionBis = -1; // Je mets -1 pour qu'en sortant du if, positionBis le mette à 0 pour recommencer un nouveau check de la chaine
                    }
                }
                else if (operation[positionBis] == 45)
                {
                    if (operation[positionBis + 1] == 45)
                    {
                        operation[positionBis + 1] = 43;
                        move(operation, positionBis, taillTotalle);
                        positionBis = 0;
                    } else
                    {
                        soutraction(operation, positionBis);
                        positionBis = -1; // Je mets -1 pour qu'en sortant du if, positionBis le mette à 0 pour recommencer un nouveau check de la chaine
                    }
                }

            }
            positionBis++;
        }
    }
}

    void soutraction(char *operation, int position)
    {
        int PremierPositionD = 0, secondPositionD = 0, PremierPositionA = 0, secondPositionA = 0, nbA = 0, nbB = 0, nbAdd = 0, resulta = 0, negative = 0;
        char nb[10] = {"0123456789"};
        PremierPositionD = position - 1;
        if(operation[position +1] == 45)
        {
            PremierPositionA = position + 2;
            negative=1;
        } else
        {
            PremierPositionA = position + 1;
        }
        int i = position - 1;

        // Determination des borne de nbA et nbB
        int decalageJ = 0;
        for (int j = 0; j < 10; ++j)
        {
            if (decalageJ == 1) {
                j = 0;
                decalageJ = 0;
            }
            if (operation[i] == nb[j])
            {
                secondPositionD = i;
                if (i != 0) {
                    i--;
                    decalageJ = 1;
                    j = 0;
                }
            } else if (j == 10)
            {

            }
        }
        i = position + 1;
        if(negative == 1 ){
            i++;
        }
        decalageJ = 0;
        for (int j = 0; j < 10; ++j)
        {
            if (decalageJ == 1)
            {
                j = 0;
                decalageJ = 0;
            }
            if (operation[i] == nb[j])
            {
                secondPositionA = i;
                i++;
                decalageJ = 1;
                j = 0;// Cas spécial où j=9, on veut continuer le test pour la position suivante, donc on remet j=0 pour continuer le for
            }
            else if (j == 10 || operation[i])
            { ;//corriger car je ne rentre pas dans la condition
            }
        }
        //composition de a et b
        for (int j = secondPositionD; j <= PremierPositionD; ++j)
        {

            nbAdd = operation[j] - 48;
            nbA = nbA + nbAdd;
            if (j < PremierPositionD)
            {
                nbA = nbA * 10;
            }
            nbAdd = 0;
        }
        for (int j = PremierPositionA; j <= secondPositionA; ++j)
        {

            nbAdd = operation[j] - 48;
            nbB = nbB + nbAdd;
            if (j < secondPositionA)
            {
                nbB = nbB * 10;
            }
            if(negative == 1)
            {
                nbB = -nbB;
            }
            nbAdd = 0;
        }
        resulta = nbA - nbB;
        moveAndWrit(operation, secondPositionD, secondPositionA, resulta);
    }
    void additio(char *operation, int position)
    {
        int PremierPositionD = 0, secondPositionD = 0, PremierPositionA = 0, secondPositionA = 0, nbA = 0, nbB = 0, nbAdd = 0, resulta = 0;
        char nb[10] = {"0123456789"};
        PremierPositionD = position - 1;
        PremierPositionA = position + 1;
        int i = position - 1;

        // Determination des borne de nbA et nbB
        int decalageJ = 0;
        for (int j = 0; j < 10; ++j)
        {
            if (decalageJ == 1)
            {
                j = 0;
                decalageJ = 0;
            }
            if (operation[i] == nb[j])
            {
                secondPositionD = i;
                if (i != 0)
                {
                    decalageJ = 1;
                    i--;
                    j = 0;
                }
            }
            else if (j == 10)
            {

            }
        }
        i = position + 1;
        decalageJ = 0;
        for (int j = 0; j < 10; j++)
        {
            if (decalageJ == 1)
            {
                j = 0;
                decalageJ = 0;
            }
            if (operation[i] == nb[j])
            {
                secondPositionA = i;
                i++;
                decalageJ = 1;
                j = 0;// Cas spécial où j=9, on veut continuer le test pour la position suivante, donc on remet j=0 pour continuer le for
            } else if (j == 10 || operation[i])
            { ;//corriger car je ne rentre pas dans la condition
            }
        }
        //composition de a et b
        for (int j = secondPositionD; j <= PremierPositionD; ++j)
        {

            nbAdd = operation[j] - 48;
            nbA = nbA + nbAdd;
            if (j < PremierPositionD)
            {
                nbA = nbA * 10;
            }
            nbAdd = 0;
        }
        if ((secondPositionD > 0 || operation[secondPositionD - 1] == "-" ) && operation[secondPositionD - 1] != 40 )
        {
            nbA = -nbA;
            secondPositionD = secondPositionD - 1;
        }
        for (int j = PremierPositionA; j <= secondPositionA; ++j)
        {

            nbAdd = operation[j] - 48;
            nbB = nbB + nbAdd;
            if (j < secondPositionA)
            {
                nbB = nbB * 10;
            }
            nbAdd = 0;
        }
        resulta = nbA + nbB;
        moveAndWrit(operation, secondPositionD, secondPositionA, resulta);
    }


void multiplication(char *operation,int position)
{
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0,negative=0;
    char nb[10]= {"0123456789"};
    PremierPositionD = position - 1;
    if(operation[position +1] == 45)
    {
        PremierPositionA = position + 2;
        negative=1;
    } else
    {
    PremierPositionA = position + 1;
    }
    int i = position -1;

    // Determination des borne de nbA et nbB
    int decalageJ = 0;
    for (int j = 0; j < 10; ++j)
    {
        if (decalageJ == 1)
        {
            j = 0;
            decalageJ = 0;
        }
        if (operation[i] == nb[j])
        {
            secondPositionD = i;
            if (i != 0){
                i--;
                decalageJ = 1;
                j = 0;
            }
        } else if( j == 10)
        {

        }
    }

    i = position +1;
    if(negative == 1 ){
        i++;
    }
    decalageJ = 0;

    for (int j = 0; j < 10; ++j)
    {
        if (decalageJ == 1) {
            j = 0;
            decalageJ = 0;
        }
        if (operation[i] == nb[j])
        {
            secondPositionA = i;
            if (i != 0){
                i++;
                decalageJ = 1;
                j = 0;
            }
        } else if( j == 10 || operation[i])
        {
            ;//corriger car je ne rentre pas dans la condition
        }
    }
    //composition de a et b
    for (int j = secondPositionD; j <= PremierPositionD ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbA = nbA+nbAdd;
        if(j <PremierPositionD)
        {
            nbA=   nbA * 10;
        }
        nbAdd =0;
    }
    for (int j = PremierPositionA; j <= secondPositionA ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbB = nbB+nbAdd;
        if(j <secondPositionA)
        {
            nbB=   nbB * 10;
        }
        if(negative == 1)
        {
            nbB = -nbB;
        }
        nbAdd =0;
    }
    resulta = nbA * nbB;
    moveAndWrit(operation,secondPositionD,secondPositionA,resulta);
}


void division(char *operation,int position)
{
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0, negative =0;
    char nb[10]= {"0123456789"};
    PremierPositionD = position - 1;

    if(operation[position +1] == 45)
    {
        PremierPositionA = position + 2;
        negative=1;
    } else
    {
        PremierPositionA = position + 1;
    }
    int i = position -1;

    // Determination des borne de nbA et nbB
    int decalageJ = 0;
    for (int j = 0; j < 10; ++j)
    {
        if (decalageJ == 1) {
            j = 0;
            decalageJ = 0;
        }
        if (operation[i] == nb[j])
        {
            secondPositionD = i;
            if (i != 0){
                i--;
                decalageJ=1;
                j = 0;
            }
        } else if( j == 10){

        }
    }

    i = position +1;
    if(negative == 1 ){
        i++;
    }
    decalageJ=0;

    for (int j = 0; j < 10; ++j)
    {
        if (decalageJ == 1) {
            j = 0;
            decalageJ = 0;
        }
        if (operation[i] == nb[j])
        {
            secondPositionA = i;
            if (i != 0){
                i++;
                decalageJ=1;
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
        if(j <PremierPositionD)
        {
            nbA=   nbA * 10;
        }
        nbAdd =0;
    }
    for (int j = PremierPositionA; j <= secondPositionA ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbB = nbB+nbAdd;
        if(j <secondPositionA)
        {
            nbB=   nbB * 10;
        }
        if(negative == 1)
        {
            nbB = -nbB;
        }
        nbAdd =0;
    }

    resulta = nbA / nbB;
    moveAndWrit(operation,secondPositionD,secondPositionA,resulta);
}

void puissance(char *operation,int position)
{
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0;
    char nb[10]= {"0123456789"};
    PremierPositionD = position - 1;
    PremierPositionA = position + 1;
    int i = position -1;

    // Determination des borne de nbA et nbB
    int decalageJ = 0;
    for (int j = 0; j < 10; ++j)
    {
        if (decalageJ == 1)
        {
            j = 0;
            decalageJ = 0;
        }
        if (operation[i] == nb[j])
        {
            secondPositionD = i;
            if (i != 0){
                i--;
                decalageJ=1;
                j = 0;
            }
        } else if( j == 10)
        {

        }
    }
    decalageJ=0;
    i = position +1;
    for (int j = 0; j < 10; ++j)
    {
        if (decalageJ == 1)
        {
            j = 0;
            decalageJ = 0;
        }
        if (operation[i] == nb[j])
        {
            secondPositionA = i;
            if (i != 0){
                i++;
                decalageJ=1;
                j = 0;
            }


        } else if( j == 10 || operation[i])
        {
            ;//corriger car je ne rentre pas dans la condition
        }
    }
    //composition de a et b
    for (int j = secondPositionD; j <= PremierPositionD ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbA = nbA+nbAdd;
        if(j <PremierPositionD)
        {
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
    resulta = nbA;
    for (int j = 0; j < nbB-1; ++j)
    {
        resulta = resulta * nbA;
    }

    moveAndWrit(operation,secondPositionD,secondPositionA,resulta);
}
void moveAndWrit(char* decalageDeString,int positionA,int positionB, int nb){
    char *transForme;
    char buffer[20];
    int taille, position = positionA, tailleChar, decalageDeFin,tailleOperation,fin;

    transForme = itoa(nb, buffer, 10) ;
    taille = contsize(transForme);
    tailleChar = contsize(decalageDeString) ;
    decalageDeFin =positionB +1;
    for (int i = 0; i < taille; ++i)
    {
        decalageDeString[position] = transForme[i];
        position++;
        fin = i;
    }
    for (int i = positionA + taille; i <=tailleChar ; ++i)
    {
        decalageDeString[i] =  decalageDeString[decalageDeFin];
        decalageDeFin++;
        if (fin < i){
        fin = i ;
        }
    }
    if(decalageDeString[fin +1 ] != 10)
    {
        decalageDeString[fin +1 ] = 10;
        fin =fin +1;
    }

}
void move(char* operatio,int positionA, int nb)
{
   int positionbis = positionA,fin;
    for (int i = 0; i <= nb-positionA ; ++i)
    {
        operatio[positionbis]= operatio[positionbis+1];
        positionbis++;
        fin = i ;
    }
    operatio[fin +1 ] =  NULL;
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


int checkIsAccepted(char *operation, int nbrchar){
    //
    int i = 0, j = 0;
    int ok = 0, error =0;
    int nbrDec[18] = {32,40,41,42,43,45,47,48,49,50,51,52,53,54,55,56,57,94};

    if (operation[0] == 10 || operation[0] == 32){
        error = 1;
        ok = 1;
    } else if(operation[0] == 112 && operation[1] == 103 && operation[2] == 99 && operation[3] == 100){
        for (int k = 0; k < nbrchar; ++k) {
                if( operation[k] == 44){
                    printf("%d\n",deconpositionPgcd(operation,k));
                    ok = 1;
                }

        }
    } else
    {
    for (i = 0; i < nbrchar; ++i)
    {
        for (j = 0; j <=18 ; ++j)
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
            else if (j == 18 || (operation[i] == 40 && operation[i+1] ==41)){
               error = 1;
                ok = 1;
            }
            }
        }
    }
    if(error== 1){
        write(2, "errore\n", 7);
    }
    return ok;
}

int deconpositionPgcd(char *operation, int position){
    int PremierPositionD =0 , secondPositionD =0 , PremierPositionA =0, secondPositionA=0,nbA=0,nbB=0,nbAdd=0, resulta = 0;
    char nb[10]= {"0123456789"};
    PremierPositionD = position - 1;
    PremierPositionA = position + 1;
    int i = position -1;

    // Determination des borne de nbA et nbB
    int decalageJ = 0;
    for (int j = 0; j < 10; ++j)
    {
        if (decalageJ == 1)
        {
            j = 0;
            decalageJ = 0;
        }
        if (operation[i] == nb[j])
        {
            secondPositionD = i;
            if (i != 0){
                i--;
                decalageJ=1;
                j = 0;
            }
        } else if( j == 10)
        {

        }
    }
    decalageJ=0;
    i = position +1;
    for (int j = 0; j < 10; ++j)
    {
        if (decalageJ == 1)
        {
            j = 0;
            decalageJ = 0;
        }
        if (operation[i] == nb[j])
        {
            secondPositionA = i;
            if (i != 0){
                i++;
                decalageJ=1;
                j = 0;
            }


        } else if( j == 10 || operation[i])
        {
            ;//corriger car je ne rentre pas dans la condition
        }
    }
    //composition de a et b
    for (int j = secondPositionD; j <= PremierPositionD ; ++j)
    {

        nbAdd = operation[j] - 48;
        nbA = nbA+nbAdd;
        if(j <PremierPositionD)
        {
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
    return pgcd(nbA,nbB);
}
int pgcd(int nbr1, int nbr2)
{
    if (nbr2 != 0)
        return pgcd(nbr2, nbr1%nbr2);
    else
        return nbr1;
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
