#ifndef UTILITIES_H
#define UTILITIES_H

#include "set.h"

int readLine(char s[], unsigned int len);

/*check if number exist on set group
 * return 0 if the num not exist and 1 if exist  */
int isExist(set *group, int num);

/*get command of the the string.
 * return the command index on command array.
 * if the command is not exist or with upper case:
 * the function return -1 and print error 10*/
int getCommand(char *line);

/*this function received list with -1 in the last cell and return the list sort from lower value to highest.
 * if length of list lower then 2 return false*/
void sortToMax(int *list);

/*set the set to empty set. first cell on array contain -1 and all other "\0"*/
void resetSet(set *group);

#endif

