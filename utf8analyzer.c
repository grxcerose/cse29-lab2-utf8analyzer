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




int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
}

    
    
    // implement the UTF-8 analyzer here
}
