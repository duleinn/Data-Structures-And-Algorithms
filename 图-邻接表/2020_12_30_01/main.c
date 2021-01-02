//
//  main.c
//  2020_12_30_01
//
//  Created by dulei on 2020/12/30.
//

#include <stdio.h>
#include <stdlib.h>

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
    VertexNode vertex[8];
} ALGraph;

static int visited[8];
void DFS(ALGraph *graph, int i)
{
    visited[i] = 1;
    printf("%d ", graph->vertex[i].data);

    ArcNode *p_node = graph->vertex[i].firstArc;
    while (p_node != NULL) {
        if (visited[p_node->vexIndex] == 0) {
            DFS(graph, p_node->vexIndex);
        }
        p_node = p_node->next;
    }
}

void DFS_traverse(ALGraph *graph)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (visited[i] == 0) {
            DFS(graph, i);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
