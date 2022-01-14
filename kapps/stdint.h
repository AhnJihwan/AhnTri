int strcmp(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

int strncmp(char *s1, char *s2, uint8_t n){
    while(n && *s1 && (*s1 == *s2)){
        s1++;
        s2++;
        n--;
    }
    if(n==0){
        return 0;
    }else{
        return 1;
    }
}
