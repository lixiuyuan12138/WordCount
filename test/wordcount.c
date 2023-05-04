#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main(int argc, char *argv[]) {
    char *filename; 
    char *parameter;
    char line[MAX_LEN]; 
    int count = 0;
    int is_word = 0;

    
    if (argc == 3) {
        parameter = argv[1];
        filename = argv[2];
    } else if (argc == 2) {
        parameter = argv[1];
        filename = "input.txt"; 
    } else {
        printf("Usage: %s -c/-w [filename]\n", argv[0]);
        return 1;
    }

    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LEN, fp) != NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (parameter[1] == 'c') {
                count++;
            } else if (parameter[1] == 'w') {
                if (line[i] == ' ' || line[i] == ',' || line[i] == '\t' || line[i] == '\n') {
                    is_word = 0;
                } else if (is_word == 0) {
                    is_word = 1;
                    count++; 
                }
            }
        }
    }
    fclose(fp);

    if (parameter[1] == 'c') {
        printf("×Ö·ûÊý£º%d\n", count);
    } else if (parameter[1] == 'w') {
        printf("µ¥´ÊÊý£º%d\n", count);
    }

    return 0;
}
