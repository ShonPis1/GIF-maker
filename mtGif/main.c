#include "displayMenus.h"
#include "linkedList.h"
#include "framesList.h"
#include "handleChoices.h"

int main(void) {
	FramesList* frames = createList();
	int program_choice = programMenu();
	int act_choice;
	char savedPath[MAX_STR_LEN];
	FILE* savedProject; 
	char line[MAX_STR_LEN];

	if (program_choice == CREATE_PROJECT) {
		printf("Working on a new project.\n");
	}
	else {
		printf("Enter the path of the project (including project name):\n");
		scanf("%s", savedPath);
		getchar();

		loadProject(frames, savedPath);
	}

	do {
		act_choice = movieMenu();
		handleChoices(act_choice, frames);
	} while (act_choice != EXIT);

	printf("Bye Bye ;)");
	destroyList(frames);

	return 0;
}