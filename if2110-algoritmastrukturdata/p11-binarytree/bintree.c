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

boolean isEqual(BinTree p1, BinTree p2) {
    if (p1 == NULL && p2 == NULL) {
        return true;
    } else if (p1 != NULL && p2 != NULL) {
        return (ROOT(p1) == ROOT(p2)) && isEqual(LEFT(p1), LEFT(p2)) &&
               isEqual(RIGHT(p1), RIGHT(p2));
    } else {
        return false;
    }
}

int getMaximumDepth(BinTree p) {
    if (p == NULL) {
        return 0;
    } else {
        int leftDepth = getMaximumDepth(LEFT(p));
        int rightDepth = getMaximumDepth(RIGHT(p));
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
}

BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start,
                                           ElType end) {
    if (start > end) {
        return NULL;
    } else {
        int mid = (start + end) / 2;
        Address root = newTreeNode(arr[mid]);
        if (root != NULL) {
            LEFT(root) =
                createBinSearchTreeFromSortedArray(arr, start, mid - 1);
            RIGHT(root) = createBinSearchTreeFromSortedArray(arr, mid + 1, end);
        }
        return root;
    }
}

int countNodes(BinTree p) {
    if (p == NULL) {
        return 0;
    } else {
        return 1 + countNodes(LEFT(p)) + countNodes(RIGHT(p));
    }
}

boolean findPath(BinTree p, ElType target, ElType path[], int* pathLen) {
    if (p == NULL) {
        return false;
    }
    path[*pathLen] = ROOT(p);
    (*pathLen)++;
    if (ROOT(p) == target) {
        return true;
    }
    if (findPath(LEFT(p), target, path, pathLen) ||
        findPath(RIGHT(p), target, path, pathLen)) {
        return true;
    }
    (*pathLen)--;
    return false;
}

void printPathToElement(BinTree p, ElType target) {
    ElType path[100];
    int pathLen = 0;
    boolean found = findPath(p, target, path, &pathLen);
    if (found) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d", path[i]);
            if (i != pathLen - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}
