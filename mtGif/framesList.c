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

void moveFrame(FramesList* list, char* frameName, int newPosition) {
	FrameNode* current = list->head;
	FrameNode* previous = NULL;
	FrameNode* nodeToMove = NULL;
	FrameNode* prevNodeToMove = NULL;
	int currentIndex;

	// find the node to move
	while (current) {
		if (strcmp(current->frame->name, frameName) == 0) {
			nodeToMove = current;
			prevNodeToMove = previous;
			break;
		}
		previous = current;
		current = current->next;
	}

	// remove the node from the current position
	if (prevNodeToMove) {
		prevNodeToMove->next = nodeToMove->next;
	}
	else {
		list->head = nodeToMove->next;
	}

	if (nodeToMove == list->tail) {
		list->tail = prevNodeToMove;
	}

	// insert the node at the new position
	current = list->head; //the node at the new position 
	previous = NULL; // the node before the current 
	currentIndex = 1; 

	while (current && currentIndex < newPosition) {
		previous = current;
		current = current->next;
		currentIndex++;
	}

	if (previous) {
		previous->next = nodeToMove;
	}
	else {
		list->head = nodeToMove; 
	}

	nodeToMove->next = current;

	if (newPosition == list->size) {
		list->tail = nodeToMove;
	}
}

void changeFrameDuration(FramesList* list, char* frameName, unsigned int newDuration) {
	FrameNode* temp = list->head;
	while (temp) {
		if (frameName == NULL || strcmp(temp->frame->name, frameName) == 0) {
			temp->frame->duration = newDuration;
			if (frameName) break;
		}

		temp = temp->next;
	}
}

void printList(FramesList* list) {
	printf("                Name            Duration        Path\n");
	if (!list->head) return;

	FrameNode* tmp = list->head;
	while (tmp != NULL) {
		printf("                %s              %u ms         %s\n", 
			tmp->frame->name, tmp->frame->duration, tmp->frame->path);

		tmp = tmp->next;
	}
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
