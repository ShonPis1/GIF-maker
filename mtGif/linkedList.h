#ifndef LINKEDLIST
#define LINKEDLIST

#define FAILURE_CODE 1
#define FALSE 0
#define TRUE !FALSE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Frame struct
typedef struct Frame
{
	char* name;
	unsigned int duration;
	char* path;
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;

/**/
Frame* createFrame(char name[], unsigned int duration, char path[]);
void destroyFrame(Frame* frame);

/**/
FrameNode* createFrameNode(Frame* frame);
void destroyFrameNode(FrameNode* node);

#endif // !LINKEDLIST


