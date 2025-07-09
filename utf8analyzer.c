#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

//task 1
void isValidASCII(char argv[]){
	int lenthInput = strlen(argv);
	int notValid = 0; 
	for(int i = 0; i<strlen(argv); i++){
		if((argv[i]&0b11000000)==0b10000000){
			notValid = 1;
		}
	}
	if(notValid == 1){
		printf("Valid ASCII: false\n");
	}
	else{
		printf("Valid ASCII: ture\n");
	}
}

//task 2
void makeUppercase(char argv[]){
	char output[100] = "";
	char temp = '';
	for(int i = 0; i<strlen(argv); i++){
		temp = 'a';
		if((argv[i]<=122)&&(argv[i]>=97)){
			temp = (argv[i] - 32);	
		}
		else{
			temp = argv[i];
		}
		output[i] = temp; 
	}
	printf("u")
}

int main(int argc, char *argv[]) {
	isValidASCII("abcde");
	isValidASCII("abcde🐿️");

    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
}
