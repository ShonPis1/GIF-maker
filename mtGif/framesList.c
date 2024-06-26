#include "framesList.h"

#define MAX_NAME_LEN 256

FramesList* createList() {
	FramesList* list = (FramesList*)malloc(sizeof(FramesList));
	if (!list) {
		printf("Memory allocation failed\n");
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	
	return list;
}

void addFrameToList(FramesList* list, char name[], unsigned int duration, char path[]) {
	if (!isPathExists(path)) return;

	Frame* frame = createFrame(name, duration, path);
	if (!frame) return;

	FrameNode* node = createFrameNode(frame);
	if (!node) return;

	if (!list->head) {
		list->head = node;
		list->tail = list->head;
	}
	else {
		list->tail->next = node;
		list->tail = list->tail->next;
	}

	list->size++;
}

void destroyList(FramesList* list) {
	FrameNode* tmp = list->head;

	// no need to free the tail seperately

	while (list->head != NULL) {
		tmp = list->head;
		list->head = list->head->next;
		destroyFrameNode(tmp);
	}

	free(list);
}

void printList(FramesList* list) {
	if (!list) return;
	printf("------FRAMES LIST (size=%d)------\n", list->size);
	FrameNode* tmp = list->head;

	while (tmp != NULL) {
		printf("%s -> ", tmp->frame->name);
		tmp = tmp->next;
	}

	printf("NULL\n");
}

void removeFrame(FramesList* list, char name[]) {
	FrameNode* currF = list->head;
	FrameNode* prevF = NULL;

	while (currF) {
		if (strcmp(currF->frame->name, name) == 0) { // searching for the node
			if (!prevF) {
				// no previous node so removing the head
				list->head = currF->next;
				// if there is only head in the list 
				if (currF == list->tail) list->tail = NULL;
				destroyFrameNode(currF);
			}
			else {
				prevF->next = currF->next;
				if (currF == list->tail) {
					list->tail = prevF;
				}
				destroyFrameNode(currF);
			}
			list->size--;
			return;
		}
		prevF = currF;
		currF = currF->next;
	}
	printf("The frame was not found\n");
}

