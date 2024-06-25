#ifndef MENUS
#define MENUS
#include <stdio.h>

#define NEW_LINE_CHAR '\n'

typedef enum {
	CREATE_PROJECT,
	LOAD_PROJECT
}programOptions;

typedef enum {
	EXIT,
	ADD,
	REMOVE,
	CHANGE_INDEX,
	CHANGE_DURATION,
	CHANGE_ALL_DURATION,
	FRAMES_LIST,
	PLAY,
	SAVE
}movieOptions;

/*shows the main menu of the program and gets the choice from the user
input: none
output: the user choice to continue the program */
int programMenu();

/*shows the menu for movie properties control and gets the user choice for the program continue
input: none
output: the user choice */
int movieMenu();

#endif // !MENUS
