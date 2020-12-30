//
//  main.c
//  2020_12_30_01
//
//  Created by dulei on 2020/12/30.
//

#include <stdio.h>

#define GRAPH_SIZE 20

typedef int VertexType;
typedef int EdgeType;

struct _M_Graph {
    VertexType vertex[GRAPH_SIZE];
    EdgeType arcs[GRAPH_SIZE][GRAPH_SIZE];
};

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
