#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }

    
    int codepoint_count = 0;
...
while (input[i]) {
    int bytes;
    int cp = decode_utf8(&input[i], &bytes);
    ...
    codepoint_count++;
    i += bytes;
} // meets requirement 4 
// printf("Number of UTF-8 codepoints: %d\n", codepoint_count);
    printf("Codepoints (decimal): ");
    cps[codepoint_count] = cp;
    for (int j = 0; j < codepoint_count; j++) {
    printf("%d ", cps[j]);
}
printf("\n"); // meets requirement 5 


byte_lengths[codepoint_count] = bytes;
    printf("Codepoint byte lengths: ");
for (int j = 0; j < codepoint_count; j++) {
    printf("%d ", byte_lengths[j]);
}
printf("\n"); // meets requiremnet 6 
    



}

    
    
    // implement the UTF-8 analyzer here
}
