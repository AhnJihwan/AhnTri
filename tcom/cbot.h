void antroid_hmenu(){
	os_print_string("\nArtificial Intellegence by AhnTri: Type [6390] for help. Do not input nothing, or it would crash.");
}

void ahntroid(){
	char * input;
	antroid_hmenu();
	os_print_string("\n\nUser_Master| ");
	input = read_char();
	if(strcmp(input, "hello")==0 || strcmp(input, "hola")==0 || strcmp(input, "hi")==0 || strcmp(input, "hi man")==0 || strcmp(input, "dude")==0){
		os_print_string("Hello, User Master. This AI is well-trained by arrays of words or numbers");
		os_print_string("\nbut have only one output. Whatever, good day!");
		ahntroid();
	}else if(strcmp(input, "bye")==0 || strcmp(input, "good bye")==0 || strcmp(input, "bye")==0){
		os_print_string("Bye-Bye, Good-Bye!!");
		kernmain();
	}else if(strcmp(input, "help")==0){
		os_print_string("Help: exit() to exit");
		ahntroid();
	}else if(strcmp(input, "wow")==0 || strcmp(input, "whow")==0 || strcmp(input, "omg")==0 || strcmp(input, "lol")==0){
		os_print_string("Why, is AhnTriOS too good? If is, give a *heart in Github!");
		ahntroid();
	}else if(strcmp(input, "happi")==0 || strcmp(input, "happy")==0 || strcmp(input, "good")==0 || strcmp(input, "great")==0 || strcmp(input, "thanks")==0){
		os_print_string("I am happy to hear that you are happy!");
		ahntroid();
	}else if(strcmp(input, "fu")==0 || strcmp(input, "fuck")==0 || strcmp(input, "fuck u")==0 || strcmp(input, "fuck you")==0 || strcmp(input, "crap")==0 || strcmp(input, "shit")==0 || strcmp(input, "jesus")==0){
		os_print_string("Don't say those words. If you do, fuck you :(");
		ahntroid();
	}else{
		os_print_string("Word not trained or not exist in code.");
		
	}
}

