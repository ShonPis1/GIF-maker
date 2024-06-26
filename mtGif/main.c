#include "displayMenus.h"
#include "linkedList.h"
#include "framesList.h"
#include "handleChoices.h"

int main(void) {
	int program_choice = programMenu();
	int act_choice;

	if (program_choice == CREATE_PROJECT) {
		printf("Working on a new project.\n");
		FramesList* frames = createList();

		do {
			act_choice = movieMenu();
			handleChoices(act_choice, frames);
		} while (act_choice != EXIT);

		printf("Bye Bye ;)");
		//TODO: destroy list
		return 0;
			
	}
	else {
		printf("Z");
	}
	
	

	return 0;
}