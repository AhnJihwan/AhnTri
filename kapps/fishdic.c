#include "../kernel.h"
#include "../libc/atclib.h"
//Next version of Fish Dictionary
//Fish Dictionary ++
//Word 1-6 are original, line 7~ are new words(FishDic++).
void fdic(){
	char * input;
	while(1){
		printf("\n\nFDic{ ");
		input = read_char();
		if(strcmp(input, "abandon")==0 || strcmp(input, "desert")==0){
			printf("verb-cease to support or look after (someone)");
			free(input);
		}else if(strcmp(input, "abashed")==0 || strcmp(input, "embarrassed")==0){
			printf("embarrassed, disconcerted, or ashamed.");
			kernmain();
		}else if(strcmp(input, "abbreviation")==0){
			printf("a shortened form of a word or phrase.");
			free(input);
		}else if(strcmp(input, "abhorrent")==0 || strcmp(input, "detestable")==0 || strcmp(input, "hateful")==0){
			printf("inspiring disgust and loathing; repugnant.");
			free(input);
		}else if(strcmp(input, "ability")==0 || strcmp(input, "talent")==0 || strcmp(input, "skill")==0){
			printf("possession of the means or skill to do something.");
			free(input);
		}else if(strcmp(input, "ablaze")==0 || strcmp(input, "alight")==0 || strcmp(input, "aflame")==0 || strcmp(input, "on fire")==0){
			printf("burning fiercely.");
			free(input);
		}else if(strcmp(input, "accelerate")==0 || strcmp(input, "hurry up")==0 || strcmp(input, "speed up")==0 || strcmp(input, "hurry")==0){
			printf("To make faster; to hurry up");
			free(input);
		}else if(strcmp(input, "in terms of")==0 || strcmp(input, "in light of")==0 || strcmp(input, "in regard to")==0){
			printf("in relation to something; from the side");
			free(input);
		}else{
			printf("Word does not exist. Please contribute if you know that word.");
			
		}
	}
}
