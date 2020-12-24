//
//  main.c
//  2020_12_23_01
//
//  Created by dulei on 2020/12/23.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define Error 0

typedef char ElemType;
typedef int status;
typedef enum {link, thread} PointerTag;

struct BiThrNode {
    ElemType data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag ltag;
    PointerTag rtag;
};

typedef struct BiThrNode *BiThrTree;

static BiThrTree pre_tree = NULL;

status create_tree(BiThrTree *tree)
{
    ElemType ch;
    scanf("%c", &ch);
    
    if (ch == ' ') {
        *tree = NULL;
    } else {
        *tree = (struct BiThrNode *)malloc(sizeof(struct BiThrNode));
        if ((*tree) == NULL) {
            exit(EXIT_FAILURE);
        }
        
        (*tree)->data = ch;
        (*tree)->ltag = link;
        (*tree)->rtag = link;
        create_tree(&(*tree)->lchild);
        create_tree(&(*tree)->rchild);
    }
    
    return OK;
}

void tree_LDR(BiThrTree tree)
{
    if (tree) {
        tree_LDR(tree->lchild);
        if (tree->lchild == NULL) {
            tree->ltag = thread;
            tree->lchild = pre_tree;
        }
        
        if (pre_tree->rchild == NULL) {
            pre_tree->rtag = thread;
            pre_tree->rchild = tree;
        }
        
        pre_tree = tree;
        tree_LDR(tree->rchild);
    }
}

void tree_head(BiThrTree *p, BiThrTree tree)
{
    *p = (struct BiThrNode *)malloc(sizeof(struct BiThrNode));
    if ((*p) == NULL) {
        exit(EXIT_FAILURE);
    }
    (*p)->ltag = link;
    (*p)->rtag = thread;
    (*p)->lchild = *p;
    (*p)->rchild = *p;
    
    if (tree == NULL) {
        (*p)->lchild = *p;
    } else {
        (*p)->lchild = tree;
        (*p)->ltag = link;
        pre_tree = *p;
        
        tree_LDR(tree);
        
        pre_tree->rchild = *p;
        pre_tree->rtag = thread;
        
        (*p)->rtag = thread;
        (*p)->rchild = pre_tree;
    }
}

int main(int argc, const char * argv[]) {
    
    BiThrTree tree = NULL;
    BiThrTree head = NULL;

    create_tree(&tree);
    tree_head(&head, tree);
    
    printf("\n");
    return 0;
}
