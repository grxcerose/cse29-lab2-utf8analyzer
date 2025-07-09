#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
//helper method
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
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
