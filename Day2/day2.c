#include <stdio.h>

int checkLine(char* line) {
    int number;
    while (fscanf(line, "%d", number) == 1) {
        printf("%d ", number);
    }
    
   
}

int main(int argc, char** argv) {
    if (argc != 2) {
        return 1;
    }
    FILE* f = fopen(argv[1], "r");
    if (f == NULL) {
        return 1;
    }
    int count;
    char line[100];
    while (fgets(line, 100, f) != NULL) {
        checkLine(line);
    }
}
