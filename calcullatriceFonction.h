//
// Created by Thomas on 23/09/2021.
//

#ifndef CALCULATRICE_C_CALCULLATRICEFONCTION_H
#define CALCULATRICE_C_CALCULLATRICEFONCTION_H


int contsize(char *string);
void parentheses(char *operationn, int *nbrchar);
void checkIsAccepted(char* operation, int nbrchar);
void typeOperation(char* operation, int positionDeDebut,int binaire ,int taillTotalle);
void additio(char *operation,int position);
void soutraction(char *operation,int position);
void move(char* decalageDeString,int positionA,int positionB, int nb);
void moveAndWrit(char* decalageDeString,int positionA,int positionB, int nb);
void delParentheses(char *operatio, int positionParenthesesA, int positionParenthesesB,int tailleTotale);
void my_reverse(char str[], int len);
char* itoa(int num, char* str, int base);
#endif //CALCULATRICE_C_CALCULLATRICEFONCTION_H


