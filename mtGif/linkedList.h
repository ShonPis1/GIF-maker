#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FAILURE_CODE 1
#define FALSE 0
#define TRUE !FALSE

#define MAX_STR_LEN 256

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

/*creates and sets a frame structure 
input: the frame name, the duration, the path
output: the new seted frame structure*/
Frame* createFrame(char name[], unsigned int duration, char path[]);

/*frees the seted frame structure
input: the frame 
output: none */
void destroyFrame(Frame* frame);

/*creates a frame node structure
input: a seted frame structure
output: a new frame node	*/
FrameNode* createFrameNode(Frame* frame);

/*frees the seted frame node structure
input: the frame node
output: none*/
void destroyFrameNode(FrameNode* node);

#endif // !LINKEDLIST


