//
// Created by Thomas on 23/09/2021.
//

#ifndef CALCULATRICE_C_CALCULLATRICEFONCTION_H
#define CALCULATRICE_C_CALCULLATRICEFONCTION_H


int contsize(char *string);
void parentheses(char *operationn, int nbrchar);
void checkIsAccepted(char* operation, int nbrchar);
void typeOperation(char* operation, int positionDeDebut,int binaire);
void additio(char *operation,int position);
void move(char* decalageDeString,int positionA,int positionB, int nb);
void moveAndWrit(char* decalageDeString,int positionA,int positionB, int nb);
#endif //CALCULATRICE_C_CALCULLATRICEFONCTION_H


