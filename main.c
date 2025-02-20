#include <stdio.h>
#include <string.h>
#include "headers/compression.h"

void print_usage() {
    printf("Usage:\n");
    printf("  encode <input_filename>\n");
    printf("  decode <input_filename> <output_extension>\n");
}

int main() {
    char command[10];
    char input_filename[256];
    char output_extension[10];

    scanf("%9s", command);

    if (strcmp(command, "encode") == 0) {
        scanf("%255s", input_filename);

        char output_filename[256];
        strcpy(output_filename, input_filename);
        char *dot = strrchr(output_filename, '.');
        if (dot) {
            strcpy(dot, ".huff");
        } else {
            strcat(output_filename, ".huff");
        }

        if (encode(input_filename) != 0) {
            printf("Error: failed to compress the file.\n");
            return -1;
        }
        printf("File successfully compressed to %s\n", output_filename);

    } else if (strcmp(command, "decode") == 0) {
        scanf("%255s", input_filename);
        scanf("%9s", output_extension);

        if (decode(input_filename, output_extension) != 0) {
            printf("Error: failed to decompress the file.\n");
            return -1;
        }
        printf("File successfully decompressed.\n");

    } else {
        print_usage();
        return -1;
    }


    return 0;
}
