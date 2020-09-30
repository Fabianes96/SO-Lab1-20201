#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wgrepFunction(char termino[], char *fileName);
int wgrepByInput(char termino[], _IO_FILE* io);

int main(int argc, char *argv[]) {
    if(argc == 1 ){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }    
    // if(argc ==2){
    //    if (wgrepByInput(argv[1], stdin) == 1) {
    //             return 1;
    //     } 
    // }
    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            if (wgrepFunction(argv[1], argv[i]) == 1) {
                return 1;
            }
        }
    }
    return 0;
}
// int wgrepByInput (char termino[], _IO_FILE* io){
    
//     char* str = NULL;
//     char c;
//     while (c!= EOF) {
//         c = fgets(str, io);
//         printf("%c", c);
//     }
//        fclose(io);

//     return 0;
// }

int wgrepFunction(char termino[], char *fileName) {
    FILE *fp = fopen(fileName, "r");
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    if (fp == NULL) {
        printf("wgrep: cannot open file\n");
        return 1;
    }    

    line_size = getline(&line_buf, &line_buf_size, fp);
    /* Loop through until we are done with the file. */
    while (line_size >= 0)
    {
        /* Increment our line count */
        line_count++;
        if(strstr(line_buf, termino) != NULL){
            printf("%s", line_buf);
        }
        /* Get the next line */
        line_size = getline(&line_buf, &line_buf_size, fp);
    }
    /* Free the allocated line buffer */
    free(line_buf);
    line_buf = NULL;    

    /* Close the file now that we are done with it */
    fclose(fp);    

    return 0;
}   