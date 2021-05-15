#include "../kernel.h"
#include "../libc/atclib.h"

//Catch @Whelk@ Game
//I know this is all trash, but just...
void game(){
	char aa;
	while(1){
		aa = get_input_keycode();
		if(aa==KEY_J){
			printf("One @ caught");
			break;
		}else if(aa==KEY_U){
			printf("One @ caught");
			break;
		}else if(aa==KEY_H){
			printf("One @ caught");
			break;
		}else if(aa==KEY_F){
			printf("One @ caught");
			break;
		}else if(aa==KEY_D){
			printf("One @ caught");
			break;
		}else if(aa==KEY_W){
			printf("One @ caught");
			break;
		}else if(aa==KEY_Z){
			printf("One @ caught");
			break;
		}else{
			printf("KILLED ALL");
			break;
		}
	}
}