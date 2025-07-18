#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
//helper method

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
        char temp;
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
        printf("Uppercased ASCII: %s\n",output);
}

//task 3 (may have some problem)
void LengthOfstring(char argv[]){
        uint32_t output = strlen(argv);
        printf("Length in bytes: %d\n",output);
}


int count_codepoints(const char *input, int *cps, int *byte_lengths) {
    int i = 0;
    int count = 0;
    while (input[i]) {
        int bytes;
        int cp = decode_utf8(&input[i], &bytes);
        if (cp == -1) return -1;  // invalid UTF-8
        cps[count] = cp;
        byte_lengths[count] = bytes;
        count++;
        i += bytes;
    }
    return count;
}


void print_codepoints(int *cps, int count) {
    printf("Decimal representations of each codepoint: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", cps[i]);
    }
    printf("\n");
}  

void print_byte_lengths(int *byte_lengths, int count) {
    printf("Bytes used to represent each codepoint: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", byte_lengths[i]);
    }
    printf("\n");
}



void substr6(const char str[]) {
    int index = 0;
    int count = 0;
    int start = 0;
    int end = 6;
    while(str[index] != 0){
        if(count == start){
                break;
        }
        if((str[index] & 0b10000000) == 0){
                index += 1;
        }
        else if((str[index] & 0b11100000) == 0b11000000){
                index += 2;
        }
        else if((str[index] & 0b11110000) == 0b11100000){
                index += 3;
        }
        else if((str[index] & 0b11111000) == 0b11110000){
                index += 4;
        }
        else{
                index += 1;
        }
        count += 1;
    }
    while(str[index] != 0){
            if(count == end){
                    break;
            }
            if((str[index] & 0b10000000) == 0){
                printf("%c", str[index]);
                index += 1;
            }
            else if((str[index] & 0b11100000) == 0b11000000){
                printf("%c%c", str[index], str[index+1]);
                index += 2;
            }
            else if((str[index] & 0b11110000) == 0b11100000){
                printf("%c%c%c", str[index], str[index+1], str[index+2]);
                index += 3;
            }
            else if((str[index] & 0b11111000) == 0b11110000){
                printf("%c%c%c%c", str[index], str[index+1], str[index+2], str[index+3]);
                index += 4;
            }
            else{ index += 1;
            }
            count += 1;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
        isValidASCII("abcde");
        isValidASCII("abcde🐿️ ");

    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
}


