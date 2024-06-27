#include "saveAndLoad.h"

void saveProject(FramesList* list, char* pathToSave) {
	FILE* fileToSave = fopen(pathToSave, "w");
	if (!fileToSave) {
		printf("failed to create the file... \n");
		return;
	}
	if (!list->head) {
		fclose(fileToSave);
		return;
	}

	FrameNode* tmp = list->head;
	while (tmp) {
		fprintf(fileToSave, "%s,%d,%s\n",
			tmp->frame->path, tmp->frame->duration, tmp->frame->name);
		tmp = tmp->next;
	}
	fclose(fileToSave);
}

void loadProject(FramesList* list, char* path) {
	char line[MAX_STR_LEN];
	char framePath[MAX_STR_LEN];
	unsigned int duration;
	char name[MAX_STR_LEN];

	FILE* savedProject = fopen(path, "r");
	if (!savedProject) {
		printf("Error!- cant open file, creating a new project\n");
		fclose(savedProject);
		return;
	}
	else {
		// reading each line 
		while (fgets(line, MAX_STR_LEN, savedProject)) {
		    // sscanf for reading and interpreting the data from each line by a fromat 
			// the format: %[^,],%u,%s.
			// %[^,] is for getting all the chars until a ',' is occurred(the path's string)
			sscanf(line, "%[^,],%u,%s", framePath, &duration, name);
			addFrameToList(list, name, duration, framePath);
		}
		fclose(savedProject);
	}
}

