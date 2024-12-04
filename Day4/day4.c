#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    char* words;
} Puzzle;

void resize(Puzzle* grid, int rows, int cols) {
    grid->words = realloc(grid->words, sizeof(char)*rows*cols);
}


int index(Puzzle* grid, int r, int c) {
    return r * grid->col + c; 
}

void append(Puzzle* grid, char c) {
    grid->words[grid->col*grid->row - 1] = c;
}

void freeGrid(Puzzle* grid) {
    free(grid->words);
    grid->row = 0;
    grid->col = 0;
}

void printGrid(Puzzle* grid) {
    for (int r = 0; r < grid->row; r++) {
        for (int c = 0; c < grid->col; c++) {
            printf("%c ", grid->words[index(grid,r,c)]);
        }
        printf("\n");
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

    Puzzle grid;
    grid.words = NULL;
    
    char c;
    int n_of_rows = 0;
    int n_of_cols = 0;
    

    while ((c = fgetc(f)) != EOF) {
        n_of_rows++;
        if (c == '\n') {
            n_of_cols++;
            n_of_rows = 0;
            grid.col = n_of_cols;
        }
        grid.row = n_of_rows;
        resize(&grid, n_of_rows, n_of_cols);
        append(&grid, c);
    }
    grid.row = n_of_rows;
    grid.col = n_of_cols + 1;
    printGrid(&grid);

    printf("%d, %d\n", grid.row, grid.col);

    fclose(f);
    freeGrid(&grid);
    return 0;
}