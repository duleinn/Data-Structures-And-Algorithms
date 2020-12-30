//
//  main.c
//  2020_12_30_01
//
//  Created by dulei on 2020/12/30.
//

#include <stdio.h>

typedef struct ArcNode {
    int vexIndex;
    int *info;
    struct ArcNode *next;
} ArcNode;

typedef struct VertexNode {
    int data;
    ArcNode *firstArc;
} VertexNode;

typedef struct {
    VertexNode vertex[20];
} ALGraph;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
