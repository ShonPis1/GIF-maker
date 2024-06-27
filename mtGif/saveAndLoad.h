#ifndef  SAVE_AND_LOAD_PROJECT
#define SAVE_AND_LOAD_PROJECT

#include "framesList.h"

/*saved the project proccess with all it's frames
inpit: the list, the file where the proccess will be saved
output: none */
void saveProject(FramesList* list, char* pathToSave);

/*loads a previous project proccess 
input: the list, the path of the saved project
output: none */
void loadProject(FramesList* list, char* path);

#endif // ! SAVE_AND_LOAD_PROJECT
