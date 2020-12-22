// 前序遍历：根节点-左子树-右子树
// 中序遍历：左子树-根节点-右子树
// 后序遍历：左子树-右子树-根节点
// 层序遍历：上-下 左-右
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define Error 0

typedef char ElemType;
typedef int Status;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

Status create_tree(BiTree *tree)
{
    ElemType ch;
    scanf("%c", &ch);

    if (ch == ' ') {
        *tree = NULL;
    } else {
        *tree = (BiTNode *)malloc(sizeof(BiTNode));
        (*tree)->data = ch;
        create_tree(&(*tree)->lchild);
        create_tree(&(*tree)->rchild);
    }
    return OK;
}

//前序遍历二叉树
/*若二叉树为空，则空操作；否则
 * （1）访问根节点
 * （2）遍历左子树
 * （3）遍历右子树
 */
void DLR(BiTree tree)
{
    if (tree) {
        printf("%c", tree->data);
        DLR(tree->lchild);
        DLR(tree->rchild);
    }
}

//中序遍历二叉树
/*若二叉树为空，则空操作；否则
 * （1）遍历左子树
 * （2）访问根节点
 * （3）遍历右子树
 */
 void LDR(BiTree tree)
 {
     if (tree) {
         LDR(tree->lchild);
         printf("%c", tree->data);
         LDR(tree->rchild);
     }
 }

 //后序遍历二叉树
 /*若二叉树为空，则空操作；否则
  * （1）遍历左子树
  * （2）遍历右子树
  * （3）访问根节点
  */
 void LRD(BiTree tree) {
     if (tree) {
        LRD(tree->lchild);
        LRD(tree->rchild);
        printf("%c", tree->data);
     }
 }

 void destory_tree(BiTree tree)
 {
     if (tree) {
         destory_tree(tree->lchild);
         destory_tree(tree->rchild);
         free(tree);
         tree = NULL;
     }
 }

int main(int argc, char **argv) {

    BiTree tree = NULL;
    create_tree(&tree);
    printf("\n-----------------------------------------\n");
    DLR(tree);
    printf("\n-----------------------------------------\n");

    printf("\n-----------------------------------------\n");
    LDR(tree);
    printf("\n-----------------------------------------\n");

    printf("\n-----------------------------------------\n");
    LRD(tree);
    printf("\n-----------------------------------------\n");

    destory_tree(tree);
    return 0;
}
