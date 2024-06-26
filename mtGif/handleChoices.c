#include "handleChoices.h"

void handleChoices(int choice, FramesList* list) {
	char path[MAX_STR_LEN];
	unsigned int duration;
	char frameName[MAX_STR_LEN];
	char nameToRemove[MAX_STR_LEN];

	switch (choice) {
		case ADD:
			if (!getsFrameDetails(list->head, &path, &duration, &frameName))
				break;
			addFrameToList(list, frameName, duration, path);
			break;
		case REMOVE:
			printf("Enter the name of the frame you wish to erase\n");
			scanf("%s", nameToRemove);
			getchar();
			removeFrame(list, nameToRemove);
			break;

		case CHANGE_INDEX:
			printList(list);
			break;
	}
}