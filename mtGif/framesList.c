#include "framesList.h"

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