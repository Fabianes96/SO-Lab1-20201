#include <stdio.h>
#include <stdlib.h>


int showFile(char *fileName);


int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (showFile(argv[i]) == 1) {
                return 1;
            }
        }
    }

    return 0;
}

int showFile(char *fileName) {
    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("wcat: cannot open file\n\n");
        return 1;
    }
    char c;

    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
    printf("\n");

    return 0;
}