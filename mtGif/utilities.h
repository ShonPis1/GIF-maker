#ifndef UTILITIES_OPERATIONS
#define UTILITIES_OPERATIONS

#include "linkedList.h"
#include <stdio.h>
#include <string.h>
#include "framesList.h"

#define NEWLINE_CHAR '\n'
#define NULL_CHAR '\0'

/*checks if the name is exists in the frames list
input: the list, the name 
output: if exists or not */
int isNameExists(FrameNode* head, char name[]);

/*scans all the frame's details and checks it's validity
input: the head of the nodes, the path, pointer to the duration, the name 
output: if all the details are valid */
int scanFrameDetails(FrameNode* head, char* path, unsigned int* duration, char* frameName);

/*checks if the path is valid and exists 
input: the path
output: if exists or not*/
int isPathExists(char path[]);

/*scans the frame name and checks it's validity 
input: the list, the frame name
output: if the name is scanned and is valid*/
int getFrameName(FramesList* list, char* name);

/*scans the needed details for a new position of a frame node
input; the list, the frame name, a pointer to the new position 
output: if the details are all valid */
int scanNewPosition(FramesList* list, char frameName[], int* newPosition);

#endif // !UTILITIES_OPERATIONS

