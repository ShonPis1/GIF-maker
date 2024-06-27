#include "handleChoices.h"

void handleChoices(int choice, FramesList* list) {
	char path[MAX_STR_LEN];
	unsigned int duration;
	char frameName[MAX_STR_LEN];
	int newPosition;
	char pathToSave[MAX_STR_LEN];
	FILE* fileToSave;

	switch (choice) {
	case ADD:
		if (!scanFrameDetails(list->head, path, &duration, frameName)) break;
		if (!isPathExists(path)) break;
		addFrameToList(list, frameName, duration, path);
		break;

	case REMOVE:
		printf("Enter the name of the frame you wish to erase\n");
		scanf("%s", frameName);
		getchar();
		removeFrame(list, frameName);
		break;

	case CHANGE_INDEX:
		if (scanNewPosition(list, frameName, &newPosition))
			moveFrame(list, frameName, newPosition);
		break;

	case CHANGE_DURATION:
		if (!getFrameName(list->head, frameName)) break;
		printf("Enter the new duration in milliseconds\n");
		if (scanf("%u", &duration) != 1) {
			printf("invalid duration\n");
			break;
		}
		getchar();
		changeFrameDuration(list, frameName, duration);
		break;

	case CHANGE_ALL_DURATION:
		printf("Enter the new duration in milliseconds\n");
		if (scanf("%u", &duration) != 1) {
			printf("invalid duration\n");
			break;
		}
		getchar();
		changeFrameDuration(list, NULL, duration);
		break;

	case FRAMES_LIST:
		printList(list);
		break;

	case PLAY:
		play(list->head); 
		break;

	case SAVE:
		printf("Enter the path of the project (including project name):\n");
		scanf("%s", pathToSave);
		getchar();
		
		saveProject(list, pathToSave);
		break;
	}
}
