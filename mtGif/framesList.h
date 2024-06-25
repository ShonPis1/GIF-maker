#ifndef FRAMES_LIST
#define FRAMES_LIST
#include "linkedList.h"

// list of all the frames 
typedef struct FramesList {
	FrameNode* head;
	FrameNode* tail;
	int size;
} FramesList;

/**/
FramesList* createList();

void addFrameToList(FramesList* list, char name[], unsigned int duration, char path[]);

/**/
void destroyList(FramesList* list);

void printList(FramesList* list);

#endif // ! FRAMES_LIST

