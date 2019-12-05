#include "set.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

void symdiff_set(set *groupA, set *groupB, set *groupC)
{

}


void sub_set(set *groupA, set *groupB, set *groupC)
{
    int i = 0;
    int j = 0;
    int list[MAX_MEMBERS_IN_SET] = {EOF};

    /*set the 3'rd set to empty group*/
    resetSet (groupC);

    /*add all members from the first set to dest set*/
    while (groupA->members[i] != EXTENSION_OF_SET)
    {
        if (isExist (groupB,groupA->members[i]) == FALSE){
            list[j++] = groupA->members[i];
        }
        i++;
    }

    list[j] = EXTENSION_OF_SET;

    read_set (groupC, (int *) list);

}


void intersect_set(set *groupA, set *groupB, set *groupC)
{
    int i = 0;
    int j = 0;
    int list[MAX_MEMBERS_IN_SET] = {EOF};

    /*set the 3'rd set to empty group*/
    resetSet (groupC);

    /*add all members from the first set to dest set*/
    while (groupA->members[i] != EXTENSION_OF_SET)
    {
        if (isExist (groupB,groupA->members[i]) == TRUE){
            list[j++] = groupA->members[i];
        }
        i++;
    }

    i = 0;
    /*add all members from the second set to dest set*/
    while (groupB->members[i] != EXTENSION_OF_SET)
    {
        if (isExist (groupA,groupB->members[i]) == TRUE){
            list[j++] = groupB->members[i];
        }
        i++;
    }
    list[j] = EXTENSION_OF_SET;

    read_set (groupC, (int *) list);

}

void union_set(set *groupA, set *groupB, set *groupC)
{
    int i = 0;
    int j = 0;
    int list[MAX_MEMBERS_IN_SET] = {EOF};
    /*set the 3'rd set to empty group*/
    resetSet (groupC);

    /*add all members from the first set to dest set*/
    while (groupA->members[i] != EXTENSION_OF_SET)
    {
        list[j++] = groupA->members[i++];
    }

    i = 0;
    /*add all members from the second set to dest set*/
    while (groupB->members[i] != EXTENSION_OF_SET)
    {
        list[j++] = groupB->members[i++];
    }
    list[j] = EXTENSION_OF_SET;

    read_set (groupC, (int *) list);
}

void read_set(set *group, int *list)
{
    int i;
    int j;
    sortToMax (list);

    /*set the group to empty group*/
    resetSet (group);

    i = 0;
    j = 0;
    while ((list[i] != EXTENSION_OF_SET))
    {
        if (isExist (group, list[i]) == FALSE)
        {
            group->members[j] = list[i];
            i++;
            j++;
        }
        else
        {
            i++;
        }
        if (i == MAX_MEMBERS_IN_SET - 1)
        {
            break;
        }
    }
    group->members[i] = EXTENSION_OF_SET;

}

/* This function get an error id and print the error message to the console*/
void printError(int errId)
{
    switch (errId)
    {
        /*labels errors*/
        case 1:
            printf ("Undefined set name\n");
            break;
        case 2:
            printf ("Invalid set member – value out of range\n");
            break;
        case 3:
            printf ("List of set members is not terminated correctly\n");
            break;
        case 4:
            printf ("Invalid set member – not an integer\n");
            break;
        case 5:
            printf ("Extraneous text after end of command\n");
            break;
        case 6:
            printf ("Missing parameter\n");
            break;
        case 7:
            printf ("Multiple consecutive commas\n");
            break;
        case 8:
            printf ("Missing comma\n");
            break;
        case 9:
            printf ("Illegal comma\n");
            break;
        case 10:
            printf ("Undefined command name\n");
            break;
        default:
            printf ("Undefined Error ID\n");/*failure*/
    }
}


void print_set(set *group)
{
    int i = 0;
    if (group->members[0] == EXTENSION_OF_SET)
    {
        printf ("The set is empty");
        return;
    }

    while (group->members[i] != EXTENSION_OF_SET)
    {
        printf ("%3u ", (unsigned char) group->members[i]);
        i++;
        if (i % MAX_MEMBERS_TO_PRINT == 0)
        {
            printf ("\n");
        }
    }
    printf ("\n");
}

void stop()
{
    printf("Exiting the program...");
    exit(0);
}