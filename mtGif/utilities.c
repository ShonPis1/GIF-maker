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

int getsFrameDetails(FrameNode* head, char** path, unsigned int* duration, char** frameName) {
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