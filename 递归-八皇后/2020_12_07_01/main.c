//
//  main.c
//  2020_12_07_01
//
//  Created by dulei on 2020/12/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_not_danger(int row, int col, int (*chess)[8]);
void eight_queen(int row, int col, int (*chess)[8]);

int is_not_danger(int row, int col, int (*chess)[8])
{
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
    
    for (int i = 0; i < 8; i++) {
        if (*(*(chess+i)+col) != 0) {
            flag1 = 1;
            break;
        }
    }
    
    for (int i = row, k = col; i >= 0 && k >=0; i--, k--) {
        if (*(*(chess+i)+k) != 0) {
            flag2 = 1;
            break;
        }
    }
    
    for (int i = row, k = col; i < 8 && k >= 0; i++, k--) {
        if (*(*(chess+i)+k) != 0) {
            flag3 = 1;
            break;
        }
    }
    
    for (int i = row, k = col; i >= 0 && k < 8; i--, k++) {
        if (*(*(chess+i)+k) != 0) {
            flag4 = 1;
            break;
        }
    }
    
    for (int i = row, k = col; i < 8 && k < 8; i++, k++) {
        if (*(*(chess+i)+k) != 0) {
            flag5 = 1;
            break;
        }
    }
    
    if (flag1 == 1 || flag2 == 1 || flag3 == 1 || flag4 == 1 || flag5 == 1) {
        return 0;
    } else {
        return 1;
    }
}

void eight_queen(int row, int col, int (*chess)[8])
{
    int chess2[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess2[i][j] = *(*(chess+i)+j);
        }
    }
    
    if (row == 8) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%d ", chess2[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    } else {
        for (int j = 0; j < col; j++) {
            if (is_not_danger(row, j, chess2)) {
                for (int i = 0; i < 8; i++) {
                    chess2[row][i] = 0;
                }
                chess2[row][j] = 1;
                
                eight_queen(row+1, col, chess2);
            }
        }
    }
}

void eight_test(int row, int col, int **chess)
{
    int chess2[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess2[i][j] = chess[i][j];
        }
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", chess2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int chess[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chess[i][j] = 0;
        }
    }
    
    
    int **p_array = (int**)malloc(8*sizeof(int*));
    for (int i = 0; i < 8; i++) {
        p_array[i] = (int *)malloc(8*sizeof(int));
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            p_array[i][j] = 1;
        }
    }

    eight_test(0, 8, p_array);
    return 0;
}

