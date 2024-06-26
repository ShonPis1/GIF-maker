#include "handleChoices.h"

void handleChoices(int choice, FramesList* list) {
	char path[MAX_STR_LEN];
	unsigned int duration;
	char frameName[MAX_STR_LEN];
	int newPosition;

	switch (choice) {
	case ADD:
		if (!scanFrameDetails(list->head, path, &duration, frameName)) break;
		addFrameToList(list, frameName, duration, path);
		break;

	case REMOVE:
		printf("Enter the name of the frame you wish to erase\n");
		scanf("%s", frameName);
		getchar();

		removeFrame(list, frameName);
		break;

	case CHANGE_INDEX:
		printf("Enter the name of the frame\n");
		scanf("%s", frameName);
		getchar();

		if (!isNameExists(list->head, frameName)) {
			printf("this frame does not exist\n");
			break;
		}

		printf("Enter the new index in the movie you wish to place the frame\n");
		scanf("%d", &newPosition);
		getchar();

		// Validate new position
		while (newPosition < 1 || newPosition > list->size) {
			printf("The movie contains only %d frames!\n", list->size);
			printf("Enter the new index in the movie you wish to place the frame\n");
			scanf("%d", &newPosition);
			getchar();
		}

		moveFrame(list, frameName, newPosition);
		break;
	case CHANGE_DURATION:
		printf("Enter the name of the frame\n");
		scanf("%s", frameName);
		getchar();

		if (!isNameExists(list->head, frameName)) {
			printf("this frame does not exist\n");
			break;
		}
		printf("Enter the new duration in milliseconds\n");
		scanf("%u", &duration);
		getchar();
		changeFrameDuration(list, frameName, duration);

		break;
	case CHANGE_ALL_DURATION:
		printList(list);
		break;
	}
}
