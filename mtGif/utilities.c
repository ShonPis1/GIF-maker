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
	if (!fgets(path, MAX_STR_LEN, stdin)) { // checking if fgets successfully read the string
		printf("failed to scan the path successfully");
		return FALSE;
	}
	path[strcspn(path, NEWLINE_CHAR)] = NULL_CHAR; // removing the new lines char in the end of the string
	
	printf("Please insert frame duration(in miliseconds):\n");
	if (scanf("%u", duration) != 1) {
		printf("invalid duration");
		return FALSE;
	}
	getchar(); // cleaning the buffer

	printf("Please choose a name for that frame:\n");
	if (!fgets(frameName, MAX_STR_LEN, stdin)) { // checking if fgets successfully read the string
		printf("failed to scan the frame name successfully");
		return FALSE;
	}
	// checking if the name alreadt exists in the list 
	while (isNameExists(head, frameName)) {
		printf("The name is already taken, please enter another name\n");
		if (!fgets(frameName, MAX_STR_LEN, stdin)) { // checking if fgets successfully read the string
			printf("failed to scan the frame name successfully");
			return FALSE;
		}
	}
	
	frameName[strcspn(frameName, NEWLINE_CHAR)] = NULL_CHAR; // removing the new lines char in the end of the string 

	return TRUE;
}