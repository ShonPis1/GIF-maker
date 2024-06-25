#include "handleChoices.h"

void handleChoices(int choice, FramesList* list) {
	char path[MAX_STR_LEN];
	unsigned int duration;
	char frameName[MAX_STR_LEN];

	switch (choice) {
		case ADD:
			if (!getsFrameDetails(list->head, &path, &duration, &frameName))
				break;

			addFrameToList(list, frameName, duration, path);
			break;
		case REMOVE:
			printList(list);
			break;
	}
}