//
// Created by Thomas on 23/09/2021.
//

#ifndef CALCULATRICE_C_CALCULLATRICEFONCTION_H
#define CALCULATRICE_C_CALCULLATRICEFONCTION_H


int contsize(char *string);
void parentheses(char *operationn, int nbrchar);
void checkIsAccepted(char*  operation, int nbrchar);
void typeOperation(char* operation, int positionDeDébut, bool parentheses);
void additio(char *operation,int position);
#endif //CALCULATRICE_C_CALCULLATRICEFONCTION_H


