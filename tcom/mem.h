char args[];
	
void memanset(){
	char *inpLoc = args[0];
	char *inpDat = args[1];
	char *value = ((char*)stoi(inpLoc));
	inpDat = read_char();
	memcpy(value, inpDat, sizeof(char));
	printf("OK!");
}

void memprintf(){
	char *inpLoc = args[0];
	char *value = ((char*)stoi(inpLoc));
	printf(value);
}
