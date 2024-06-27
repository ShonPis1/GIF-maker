#ifndef FRAMES
#define FRAMES
#include "linkedList.h"

// list of all the frames 
typedef struct FramesList {
	FrameNode* head;
	FrameNode* tail;
	int size;
} FramesList;

/*creates and initializes a FramesList sturcture 
input: none 
output: a pointer to the list or NULL if memory allocation fails*/
FramesList* createList();

/*creates a new frame node and adds it to the frames list 
input: a pointer to the list, the name of the frame, duration, path
output: none */
void addFrameToList(FramesList* list, char name[], unsigned int duration, char path[]);

/*removes a frame node from the frames list and free it
input: a pointer to the list, the name of the frame 
output: none */
void removeFrame(FramesList* list, char name[]);

/*moves a frame node position to a ew position in the frames list 
input: the list, the frame name, the new position */
void moveFrame(FramesList* list, char* frameName, int newPosition);

/*changes the duration of a frame, if frameName is NULL
the new duration will be set in all nodes
input: the list, the frame name(may be NULL), the new duration
output: none */
void changeFrameDuration(FramesList* list, char* frameName, unsigned int newDuration);

/*prints each frame details in the frames list 
input: the list
output: none */
void printList(FramesList* list);

/*frees the list and it's frames it's details
inputL the list
output: none */
void destroyList(FramesList* list);

#endif // ! FRAMES

