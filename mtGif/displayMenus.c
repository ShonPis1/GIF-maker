#include "displayMenus.h"

int programMenu() {
	int choice = -1, scanRValue = 0;
	do{
		printf("Welcome to Magshimim Movie Maker! what would you like to do?\n");
		printf(" [%d] Create a new project\n", CREATE_PROJECT);
		printf(" [%d] Load existing project\n", LOAD_PROJECT);
		scanRValue = scanf_s("%d", &choice);
		while (getchar() != NEW_LINE_CHAR); // clear the buffer because the scanf 

	} while ((choice != CREATE_PROJECT && choice != LOAD_PROJECT) || scanRValue != 1);
	
	return choice;
}

int movieMenu() {
	int choice = -1, scanRValue = 0;
	do {
		printf("\n");
		printf("What would you like to do?\n");
		printf(" [%d] Exit\n", EXIT);
		printf(" [%d] Add new Frame\n", ADD);
		printf(" [%d] Remove a Frame\n", REMOVE);
		printf(" [%d] Change frame index\n", CHANGE_INDEX);
		printf(" [%d] Change frame duration\n", CHANGE_DURATION);
		printf(" [%d] Change duration of all frames\n", CHANGE_ALL_DURATION);
		printf(" [%d] List frames\n", FRAMES_LIST);
		printf(" [%d] Play movie!\n", PLAY);
		printf(" [%d] Save project\n", SAVE);
		scanRValue = scanf_s("%d", &choice);
		while (getchar() != NEW_LINE_CHAR); // clear the buffer because the scanf 

	} while (!(choice >= EXIT && choice <= SAVE) || scanRValue != 1);
	
	return choice;
}