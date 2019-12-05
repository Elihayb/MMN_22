#include "utilities.h"
#include "set.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
   Read a line from stdin into string s[] passed as parameter.
   In stdin, a line is terminated by a newline (\n) character,
   or when EOF (end of file) is reached.
   The terminating \n is not included in the string.
   len specifies the maximum number of chars to read from stdin.
   s[] is assumed to have space for len chars + terminating \0.
   The line in stdin is truncated if it exceeds len chars.
   Returns the actual length of the string s[].
*/
int readLine(char s[], unsigned int len)
{
    int c, i = 0;
    while ((len-- > 0) && ((c = getchar ()) != EOF) && (c != '\n'))
    {
        s[i++] = c;
    }
    s[i] = '\0'; /* terminate the string */
    return i;
}

int check_line(char s[])
{
    int *list;
    if (getCommand ((char *) s) == -1)
    {
        printError (10);
    }


}

/*check if number exist on set group
 * return 0 if the num not exist and 1 if exist  */
int isExist(set *group, int num)
{
    int i;
    for (i = 0 ; i < MAX_MEMBERS_IN_SET ; i++)
    {
        if (group->members[i] == num)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/*get command of the the string.
 * return the command index on command array.
 * if the command is not exist or with upper case:
 * the function return -1 and print error 10*/
int getCommand(char *str)
{
    int i;
    int cmdNum = -1;/*save the command number*/
    const char s[2] = " ";
    char *token;
    char *tempstr = calloc (strlen (str) + 1, sizeof (char));

    /*save copy of string to prevent corrupted it*/
    strcpy (tempstr, str);

    /*split teh string with delimiter " " */
    token = strtok (tempstr, s);

    /*scan the first token and check it*/
    while (token != NULL)
    {
        if (isspace (token[0]))
        {
            continue;
        }
        for (i = 0 ; i < 7 ; i++)
        {
            if (strcmp (actionNames[i], token) == TRUE)
            {
                cmdNum = i;
                strcpy (tempstr, token);
                break;
            }

        }
        /*TODO: remove comments */
        //if(cmdNum != -1){
        break;
        //}
        //token = strtok (NULL, s);
    }
    /*check if command with lower case only*/
    if (cmdNum != -1)
    {
        i = 0;
        while (tempstr[i] != '\0')
        {

            if ((isalpha (tempstr[i])) && (!islower (tempstr[i])) )
            {
                printError (10);
                return -1;
            }
            i++;
        }
        free (tempstr);

        return cmdNum;
    }
    printError (10);
    return -1;
}

/*the function received string and argument type and return array with arguments
 * arguments flag can received the following data:
 * 1 - get groups on command
 * 2 - get numbers and return it as array*/
char *TrimString(char *str, int argumentType)
{
    int cmdNum;
    char *strTmp = calloc (strlen (str) + 1, sizeof (char));
    char *retStr = calloc (strlen (str) + 1, sizeof (char));
    int i = 0;

    /*save copy of string*/
    strcpy (strTmp, str);

    /*get the command to cut the string after command name*/
    cmdNum = getCommand (str);

    strTmp = strstr (strTmp, actionNames[cmdNum]);

    while (strTmp[i] != EOF)
    {
        if (isspace (strTmp[i]))
        {
            continue;
        }

        retStr[i] = strTmp[i];
    }
    retStr[i++] = '\0';

    return retStr;

}

/*this function received list and length and return the list sort from lower value to highest.
 * if length of list lower then 2 return false*/
void sortToMax(int *list)
{
    int i, j, tmp;
    int length = 0;

    while (list[length] != EXTENSION_OF_SET){
        length++;
    }

    if (length < 2)
    {
        return;
    }
    for (i = 0 ; i < length-1 ; i++)
    {
        for (j = 0 ; j < length-1 ; j++)
        {
            if (list[j] > list[i])
            {
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}

/*set the set to empty set. first cell on array contain -1 and all other "\0"*/
void resetSet(set *group)
{
    int i;
    group->members[0] = -1;

    for (i = 1;i<MAX_MEMBERS_IN_SET;i++){
        group->members[i] = EOF;
    }
}
