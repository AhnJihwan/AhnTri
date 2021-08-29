#include "../kernel.h"
#include "../libc/atclib.h"
//Next version of Fish Dictionary
//Fish Dictionary ++
//Word 1-6 are original, line 7~ are new words(FishDic++).
void fdic(){
	framebuffer_clscr(0x013571);
	char * input;
	while(1){
		framebuffer_putstr("\n\n><(((@)> ", 0xc3a984);
		input = read_char();
		if(strcmp(input, "abandon")==0 || strcmp(input, "desert")==0){
			framebuffer_putstr("verb-cease to support or look after (someone)", 0xc3a984);
			free(input);
		}else if(strcmp(input, "abashed")==0 || strcmp(input, "embarrassed")==0){
			framebuffer_putstr("embarrassed, disconcerted, or ashamed.", 0xc3a984);
			kernmain();
		}else if(strcmp(input, "abbreviation")==0){
			framebuffer_putstr("a shortened form of a word or phrase.", 0xc3a984);
			free(input);
		}else if(strcmp(input, "abhorrent")==0 || strcmp(input, "detestable")==0 || strcmp(input, "hateful")==0){
			framebuffer_putstr("inspiring disgust and loathing; repugnant.", 0xc3a984);
			free(input);
		}else if(strcmp(input, "ability")==0 || strcmp(input, "talent")==0 || strcmp(input, "skill")==0){
			framebuffer_putstr("possession of the means or skill to do something.", 0xc3a984);
			free(input);
		}else if(strcmp(input, "ablaze")==0 || strcmp(input, "alight")==0 || strcmp(input, "aflame")==0 || strcmp(input, "on fire")==0){
			framebuffer_putstr("burning fiercely.", 0xc3a984);
			free(input);
		}else if(strcmp(input, "accelerate")==0 || strcmp(input, "hurry up")==0 || strcmp(input, "speed up")==0 || strcmp(input, "hurry")==0){
			framebuffer_putstr("To make faster; to hurry up", 0xc3a984);
			free(input);
		}else if(strcmp(input, "in terms of")==0 || strcmp(input, "in light of")==0 || strcmp(input, "in regard to")==0){
			framebuffer_putstr("in relation to something; from the side", 0xc3a984);
			free(input);
		}else if(strcmp(input, "act as")==0 || strcmp(input, "serve as")==0 || strcmp(input, "function as")==0){
			framebuffer_putstr("To play the role of", 0xc3a984);
			free(input);
		}else if(strcmp(input, "prove to")==0 || strcmp(input, "turn out to")==0){
			framebuffer_putstr("be discovered to be", 0xc3a984);
			free(input);
		}else if(strcmp(input, "exit")==0 || strcmp(input, "out")==0){
			kernmain();
		}else{
			framebuffer_putstr("Word does not exist. Please contribute if you know that word.", 0xc3a984);
			
		}
	}
}
