/*************************************************************************
	> File Name: binary_tree.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年10月23日 星期二 19时17分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int data;
    struct
}




void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

Node *build() {
    Node *root == init(1);
    root->lchild = init(2);
    root->rchild = init(3);
    root->lchild->lchild = init(6);
    root->lchild->rchild = init(7);
    root->lchild->lchild->rchild = init(12);
    root->rchild->lchild = init(5);
    root->rchild->rchild = init(9);
    root->rchild->lchild->lchild = init(10);
    root->rchild->lchild->rchild = init(11);
    return root;
}

int height_tree(Node *root) {
    if (root == NULL) return 0;
    int lh = height_tree(root->lchild), rh = height_tree(root->rchild);
    return (lh > rh ? lh : rh) + 1;
}

void preorder(Node *root) {
    return ;
}

void postorder(Node *root) {
    return ;
}

voi 
int main() {
    Node *root = build();


    return 0;
}
