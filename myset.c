#include <stdio.h>
#include "set.h"
#include "utilities.h"

const char *actionNames[] = {"read_set", "print_set", "union_set", "symdiff_set", "sub_set", "intersect_set", "stop"};
const char *setNames[] = {"SETA", "SETB", "SETC", "SETD", "SETE", "SETF"};


int main()
{
    int i = 0;
    set SETA = {EXTENSION_OF_SET};
    set SETB = {EXTENSION_OF_SET};
    set SETC = {EXTENSION_OF_SET};
    set SETD = {EXTENSION_OF_SET};
    set SETE = {EXTENSION_OF_SET};
    set SETF = {EXTENSION_OF_SET};


    /*====================================================================================*/
    /*get command check*/
    printf ("\n=============== get command ================\n");
    char *str = "  symdiff_set  1268 intersect_set";
    char *str1 = "  0522symdiff_set  1268 intersect_set";
    char *str2 = "  SYMdiff_set  1268 intersect_set";
    char *str3 = "  ";
    printf ("get command (3) : %d\n", getCommand (str));
    printf ("get command (-1) : %d\n", getCommand (str1));
    printf ("get command (-1) : %d\n", getCommand (str2));
    printf ("get command (-1) : %d\n", getCommand (str3));

    /*is exist check*/
    printf ("\n============== is exist =================\n");
    SETA.members[0] = 20;

    printf ("is exist (1 - FALSE): %d\n", isExist (&SETA, 3));
    printf ("is exist (0 - TRUE): %d\n", isExist (&SETA, 20));

    /*check print set*/
    printf ("\n============== print set =================\n");
    SETB.members[0] = 1;
    SETB.members[1] = 3;
    SETB.members[2] = 53;
    SETB.members[3] = 177;
    SETB.members[4] = EXTENSION_OF_SET;
    printf ("print set:\n");
    print_set (&SETB);

    /*check read set, print set and sort to max*/
    printf ("\n=============== read set, print set and sort to max ================\n");
    int list1[11] = {5, 8, 7, 3, 6, 9, 1, 4, 7, 88, -1};
    printf ("read set:\n");
     printf("expected:\n  1   3   4   5   6   7   8   9  88\nactual:\n");
    read_set (&SETC, (int *) list1);
    print_set (&SETC);


    /*check union_set*/
    printf ("\n================ union_set ===============\n");
    printf ("union_set:\n");
    union_set (&SETC,&SETB,&SETA);
    printf ("set b:\n");
    print_set (&SETB);
    printf ("set c:\n");
    print_set (&SETC);
    printf ("set a:\n");
    print_set (&SETA);

    printf ("\n================ intersect_set ===============\n");
    printf ("intersect_set:\n");
    intersect_set (&SETC,&SETB,&SETA);
    printf ("set b:\n");
    print_set (&SETB);
    printf ("set c:\n");
    print_set (&SETC);
    printf ("set a:\n");
    print_set (&SETA);

    printf ("\n================ sub_set ===============\n");
    printf ("sub_set:\n");
    sub_set (&SETB,&SETC,&SETA);
    printf ("set b:\n");
    print_set (&SETB);
    printf ("set c:\n");
    print_set (&SETC);
    printf ("set a:\n");
    print_set (&SETA);


    stop ();
    /*====================================================================================*/

    return 0;
}
