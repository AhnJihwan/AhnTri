#include "../kernel.h"
#include "../libc/atclib.h"

void antroid_hmenu(){
	framebuffer_putstr("\nArtificial Intellegence by AhnTri: Type [6390] for help. Do not input nothing, or it would crash. There might be some bugs in it - well - idk...", 0x65abe7);
}

void ahntroid(){
	framebuffer_clscr(0x741b47);
	char * input;
	antroid_hmenu();
	while(1){
		framebuffer_putstr("\n\nUser_Master| ", 0x7fa49d);
		input = read_char();
		if(strcmp(input, "hello")==0 || strcmp(input, "hola")==0 || strcmp(input, "hi")==0 || strcmp(input, "hi man")==0 || strcmp(input, "dude")==0 || strcmp(input, "hey")==0){
			framebuffer_putstr("Hello, User Master. This AI is well-trained by arrays of words or numbers", 0x65abe7);
			framebuffer_putstr("\nbut have only one output. Whatever, have a good day!", 0x65abe7);
			free(input);
		}else if(strcmp(input, "bye")==0 || strcmp(input, "good bye")==0 || strcmp(input, "bye")==0){
			int i;
			i = (int)xor32_2times() % 2;
			if(i == 0){
				framebuffer_putstr("Bye-Bye, Good-Bye!!", 0x65abe7);
			} else if(i == 1){
				framebuffer_putstr("Bye! Hope to see you again soon!", 0x65abe7);
			}
			kernmain();
		}else if(strcmp(input, "help")==0){
			framebuffer_putstr("Help: exit() to exit", 0x65abe7);
			free(input);
		}else if(strcmp(input, "wow")==0 || strcmp(input, "whow")==0 || strcmp(input, "omg")==0 || strcmp(input, "lol")==0){
			framebuffer_putstr("Why, is AhnTriOS too good? If is, give a *heart in Github!", 0x65abe7);
			free(input);
		}else if(strcmp(input, "happi")==0 || strcmp(input, "happy")==0 || strcmp(input, "good")==0 || strcmp(input, "great")==0 || strcmp(input, "thanks")==0){
			framebuffer_putstr("I am happy to hear that you are happy!", 0x65abe7);
			free(input);
		}else if(strcmp(input, "fu")==0 || strcmp(input, "fuck")==0 || strcmp(input, "fuck u")==0 || strcmp(input, "fuck you")==0 || strcmp(input, "crap")==0 || strcmp(input, "shit")==0 || strcmp(input, "jesus")==0){
			framebuffer_putstr("Don't say those words. If you do, fuck you :(", 0x65abe7);
			free(input);
		}else if(strcmp(input, "who are u")==0 || strcmp(input, "what is your gender")==0 || strcmp(input, "whoareu")==0 || strcmp(input, "uname")==0){
			framebuffer_putstr("I am AhnTroid. I am an man bot. I am Artificial Intellegence.", 0x65abe7);
			free(input);
		}else if(strcmp(input, "open ccalc")==0 || strcmp(input, "plz ccalc")==0){
			ccalc();
			free(input);
		}else if(strcmp(input, "where are u")==0){
			printf("I am here. Just here. Right here. Yes in front of you. Here.");
			free(input);
		}else if(strcmp(input, "whats ur age")==0){
			printf("My age is 0 years old, and gonna be 1 in 12/22/2021. That's my brithday :)\n");
			free(input);
		}else if(strcmp(input, "bruh")==0){
			printf("Wassup man\n");
			free(input);
		}else{
			framebuffer_putstr("wth u talking about", 0x65abe7);
			
		}
	}
}
