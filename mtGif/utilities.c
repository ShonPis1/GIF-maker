#include "utilities.h"

int isNameExists(FrameNode* head, char name[]) {
	FrameNode* current = head;
	while (current != NULL) {
		if (strcmp(current->frame->name, name) == 0) {
			return TRUE;
		}
		current = current->next;
	}
	return FALSE;
}

int scanFrameDetails(FrameNode* head, char* path, unsigned int* duration, char* frameName) {
	printf("*** Creating new frame ***\n");

	printf("Please insert frame path:\n");
	scanf("%s", path);
	getchar(); // cleaning the buffer 

	printf("Please insevrt frame duration(in miliseconds):\n");
	if (scanf("%u", duration) != 1) {
		printf("invalid duration");
		return FALSE;
	}
	getchar(); // cleaning the buffer

	printf("Please choose a name for that frame:\n");
	scanf("%s", frameName);

	// checking if the name already exists in the list 
	while (isNameExists(head, frameName)) {
		printf("The name is already taken, please enter another name\n");
		scanf("%s", frameName);
	}

	getchar(); // cleaning the buffer 

	return TRUE;
}

int isPathExists(char path[]) {
	FILE* imgFile = fopen(path, "r");
	if (!imgFile) {
		printf("Can't find file! Frame will not be added\n");
		return FALSE;
	}
	fclose(imgFile);
	return TRUE;
}
/*
int scanNewPositionNew(FramesList* list, char frameName[], int* newPosition) {
	printf("Enter the name of the frame\n");
	scanf("%s", frameName);
	getchar();
	if (!isNameExists(list, frameName)) {
		printf("this frame does not exist\n");
		return FALSE;
	}

	printf("Enter the new index in the movie you wish to place the frame\n");
	scanf("%d", newPosition);
	getchar();
	
	// checking validity
	while (*newPosition < 1 || *newPosition > list->size) {
		printf("The movie contains only %d frames!\n", list->size);
		printf("Enter the new index in the movie you wish to place the frame\n");
		scanf("%d", newPosition);
		getchar();
	}
	return TRUE;
}
*/
void getFrameName(char* name) {
	printf("Enter the name of the frame\n");
	scanf("%s", name);
	getchar();
}
