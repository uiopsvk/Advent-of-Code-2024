#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int* array, int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i+1; j < len; j++) {
            if (array[min] > array[j]) {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}



int main(int argc, char** argv) {
    if (argc != 2) {
        return 1;
    }
    
    char* source = argv[1];
    FILE* f = fopen(source, "r");
    if (f == NULL) {
        return 1;
    }
    
    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));
    int num1, num2, sum;
    int n_of_lines = 0;
    while (fscanf(f, "%d %d", &num1, &num2) == 2) {
        n_of_lines++;
        x = realloc(x, n_of_lines * sizeof(int));
        y = realloc(y, n_of_lines * sizeof(int));

        if (x == NULL || y == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(x);
            free(y);
            fclose(f);
            return 1;
        }
        x[n_of_lines-1] = num1;
        y[n_of_lines-1] = num2;
    }
    
    sort(x, n_of_lines);
    sort(y, n_of_lines);
    for (int i = 0; i < n_of_lines; i++) {
        sum += abs(x[i]-y[i]);
    }
    printf("%d\n", sum);
    
    free(x);
    free(y);
    fclose(f);
    return 0;
}