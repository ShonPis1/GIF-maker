#ifndef USER_CHOICES
#define USER_CHOICES
#include "linkedList.h"
#include "utilities.h"
#include "displayMenus.h"
#include "framesList.h" 
#include "view.h"
#include "saveAndLoad.h"

#define EXIT_CODE 0

/*handles the user choices
input: the user choice, the frames list
output: none */
void handleChoices(int choice, FramesList* frames);

#endif // !USER_CHOICES

