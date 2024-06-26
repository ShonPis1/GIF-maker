#ifndef FRAMES
#define FRAMES
#include "linkedList.h"
#include "utilities.h"

// list of all the frames 
typedef struct FramesList {
	FrameNode* head;
	FrameNode* tail;
	int size;
} FramesList;

/**/
FramesList* createList();

/**/
void addFrameToList(FramesList* list, char name[], unsigned int duration, char path[]);

/**/
void removeFrame(FramesList* list, char name[]);

/**/
void moveFrame(FramesList* list, const char* frameName, int newPosition);

/**/
void changeFrameDuration(FramesList* list, char* frameName, unsigned int newDuration);

/**/
void destroyList(FramesList* list);

/**/
void printList(FramesList* list);

#endif // ! FRAMES

