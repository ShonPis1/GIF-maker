#include "linkedList.h"

Frame* createFrame(char name[], unsigned int duration, char path[]) {
	Frame* newFrame = (Frame*)malloc(sizeof(Frame));
	if (!newFrame){
		printf("Memory allocation failed\n");
        return NULL;
	}

    // allocate memory for the name and path strings to copy the input strings
    newFrame->name = (char*)malloc(strlen(name) + 1);
    if (!newFrame->name) {
        printf("Memory allocation failed for name\n");
        destroyFrame(newFrame);
        return NULL;
    }
    strcpy(newFrame->name, name);

    newFrame->path = (char*)malloc(strlen(path) + 1);
    if (!newFrame->path) {
        printf("Memory allocation failed for path\n");
        destroyFrame(newFrame);
        return NULL;
    }
    strcpy(newFrame->path, path);

    newFrame->duration = duration;

    return newFrame;
}

void destroyFrame(Frame* frame) {
    if (frame == NULL) return;

    if (frame->path != NULL) free(frame->path);
    if (frame->name != NULL) free(frame->name);
    free(frame);
}

FrameNode* createFrameNode(Frame* frame) {
    FrameNode* newNode = (FrameNode*)malloc(sizeof(FrameNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->frame = frame;
    newNode->next = NULL;
    return newNode;
}

void destroyFrameNode(FrameNode* node) {
    if (node == NULL) return;

    destroyFrame(node->frame);
    free(node);
}
