#include "bintree.h"

#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree) {
    BinTree p = newTreeNode(root);
    if (p != NULL) {
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }

    return p;
}

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree,
                BinTree* p) {
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val) {
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }

    return p;
}

void deallocTreeNode(Address p) { free(p); }

boolean isTreeEmpty(BinTree p) { return p == NULL; }

boolean isOneElmt(BinTree p) {
    return p != NULL && LEFT(p) == NULL && RIGHT(p) == NULL;
}

boolean isUnerLeft(BinTree p) {
    return p != NULL && LEFT(p) != NULL && RIGHT(p) == NULL;
}

boolean isUnerRight(BinTree p) {
    return p != NULL && LEFT(p) == NULL && RIGHT(p) != NULL;
}

boolean isBinary(BinTree p) {
    return p != NULL && LEFT(p) != NULL && RIGHT(p) != NULL;
}

void printPreorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
        return;
    }

    printf("(");
    printf("%d", ROOT(p));
    printPreorder(LEFT(p));
    printPreorder(RIGHT(p));
    printf(")");
}

void printInorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
        return;
    }

    printf("(");
    printInorder(LEFT(p));
    printf("%d", ROOT(p));
    printInorder(RIGHT(p));
    printf(")");
}

void printPostorder(BinTree p) {
    if (isTreeEmpty(p)) {
        printf("()");
        return;
    }

    printf("(");
    printPostorder(LEFT(p));
    printPostorder(RIGHT(p));
    printf("%d", ROOT(p));
    printf(")");
}

void printTreeV2(BinTree p, int h, int indent) {
    if (isTreeEmpty(p)) {
        return;
    }

    printf("%*s", indent, "");
    printf("%d\n", ROOT(p));
    printTreeV2(LEFT(p), h, indent + h);
    printTreeV2(RIGHT(p), h, indent + h);
}

void printTree(BinTree p, int h) { printTreeV2(p, h, 0); }