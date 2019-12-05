#ifndef SET_H
#define SET_H

#define TRUE 0
#define FALSE 1
#define MAX_MEMBERS_IN_SET 256
#define MAX_MEMBERS_TO_PRINT 16
#define EXTENSION_OF_SET -1

typedef struct set{
    char members[MAX_MEMBERS_IN_SET];
} set;

/*arrays with all groups and actions names to check commands*/
extern const char *setNames[];
extern const char *actionNames[];

void read_set(set *group, int *list);

void printError(int errorNum);

void print_set(set *group);

void union_set(set *groupA, set *groupB, set *groupC);

void symdiff_set(set *groupA, set *groupB, set *groupC);

void sub_set(set *groupA, set *groupB, set *groupC);

void intersect_set(set *groupA, set *groupB, set *groupC);

void stop();

#endif
