#include <stdio.h>
#include "boolean.h"
#include "queue.h"

#define MAX_N 100

int distance[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];
int N;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

boolean isValid(int row, int col) {
    return (row >= 0 && row < N && col >= 0 && col < N && grid[row][col] != '#');
}

void findStart(int *startRow, int *startCol) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'A') {
                *startRow = i;
                *startCol = j;
                return;
            }
        }
    }
}

int bfs(int startRow, int startCol) {
    Queue q;
    CreateQueue(&q);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distance[i][j] = -1;
        }
    }
    
    ElType start = {startRow, startCol};
    enqueue(&q, start);
    distance[startRow][startCol] = 0;
    
    while (!isEmpty(q)) {
        ElType current;
        dequeue(&q, &current);
        
        if (grid[current.row][current.col] == 'B') {
            return distance[current.row][current.col];
        }
        
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];
            
            if (isValid(newRow, newCol) && distance[newRow][newCol] == -1) {
                distance[newRow][newCol] = distance[current.row][current.col] + 1;
                ElType next = {newRow, newCol};
                enqueue(&q, next);
            }
        }
    }
    
    return -1;
}

int main() {
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }
    
    int startRow, startCol;
    findStart(&startRow, &startCol);
    
    int result = bfs(startRow, startCol);
    
    if (result == -1) {
        printf("Tidak\n");
    } else {
        printf("Ya\n%d\n", result);
    }
    
    return 0;
}