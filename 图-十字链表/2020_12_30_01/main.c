//
//  main.c
//  2020_12_30_01
//
//  Created by dulei on 2020/12/30.
//

#include <stdio.h>

typedef int InfoType;
typedef int VertexType;

typedef struct ArcNode {
    int tailVex;
    int headVex;
    struct ArcNode *tailLink;
    struct ArcNode *headLink;
    InfoType *info;
} ArcNode;

typedef struct VerNode {
    VertexType data;
    ArcNode *firstIn;
    ArcNode *firstOut;
} VerNode;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
