//
//  main.c
//  2020_12_30_01
//
//  Created by dulei on 2020/12/30.
//

#include <stdio.h>

#define GRAPH_SIZE 5

typedef char VertexType;
typedef int EdgeType;

struct _M_Graph {
    VertexType vertex[GRAPH_SIZE];
    EdgeType arcs[GRAPH_SIZE][GRAPH_SIZE];
};

static int visited[GRAPH_SIZE];

void create_graph(struct _M_Graph *graph)
{
    graph->vertex[0] = 'A';
    graph->vertex[1] = 'B';
    graph->vertex[2] = 'C';
    graph->vertex[3] = 'D';
    graph->vertex[4] = 'E';

    graph->arcs[0][0] = 0;
    graph->arcs[0][1] = 1;
    graph->arcs[0][2] = 1;
    graph->arcs[0][3] = 1;
    graph->arcs[0][4] = 1;

    graph->arcs[1][0] = 1;
    graph->arcs[1][1] = 0;
    graph->arcs[1][2] = 1;
    graph->arcs[1][3] = 1;
    graph->arcs[1][4] = 1;

    graph->arcs[2][0] = 1;
    graph->arcs[2][1] = 1;
    graph->arcs[2][2] = 0;
    graph->arcs[2][3] = 1;
    graph->arcs[2][4] = 1;

    graph->arcs[3][0] = 1;
    graph->arcs[3][1] = 1;
    graph->arcs[3][2] = 1;
    graph->arcs[3][3] = 0;
    graph->arcs[3][4] = 1;

    graph->arcs[4][0] = 1;
    graph->arcs[4][1] = 1;
    graph->arcs[4][2] = 1;
    graph->arcs[4][3] = 1;
    graph->arcs[4][4] = 0;

    int i;
    for (i = 0; i < GRAPH_SIZE; i++) {
        visited[i] = 0;
    }
}

void display_data(EdgeType (*et)[GRAPH_SIZE], int n)
{
    int i;
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < GRAPH_SIZE; j++) {
            printf("%d ", et[i][j]);
        }
        printf("\n");
    }
}

void DFS(struct _M_Graph *graph, int index)
{
    visited[index] = 1;
    printf("%c\n", graph->vertex[index]);

    int i;
    for (i = 0; i < GRAPH_SIZE; i++) {
        if (graph->arcs[index][i] == 1 && visited[i] == 0) {
            DFS(graph, i);
        }
    }
}

void DFS_traverse(struct _M_Graph *graph)
{
    int row;
    for (row = 0; row < GRAPH_SIZE; row++) {
        if (visited[row] == 0) {
            DFS(graph, 0);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct _M_Graph graph;
    create_graph(&graph);
    display_data(graph.arcs, GRAPH_SIZE);
    DFS_traverse(&graph);
    return 0;
}
