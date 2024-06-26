#ifndef UTILITIES_OPERATIONS
#define UTILITIES_OPERATIONS

#include "linkedList.h"
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 256
#define NEWLINE_CHAR "\n"
#define NULL_CHAR '\0'

/**/
int isNameExists(FrameNode* head, char name[]);

/**/
int getsFrameDetails(FrameNode* head, char** path, unsigned int* duration, char** frameName);

/**/
int isPathExists(char path[]);

#endif // !UTILITIES_OPERATIONS

