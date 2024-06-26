#ifndef UTILITIES_OPERATIONS
#define UTILITIES_OPERATIONS

#include "linkedList.h"
#include <stdio.h>
#include <string.h>
#include "framesList.h"

#define MAX_STR_LEN 256
#define NEWLINE_CHAR '\n'
#define NULL_CHAR '\0'

/**/
int isNameExists(FrameNode* head, char name[]);

/**/
int scanFrameDetails(FrameNode* head, char* path, unsigned int* duration, char* frameName);

/**/
int isPathExists(char path[]);

/**/
void getFrameName(char* name);

/*
int scanNewPositionNew(FramesList* list, char frameName[], int* newPosition);
*/
#endif // !UTILITIES_OPERATIONS

