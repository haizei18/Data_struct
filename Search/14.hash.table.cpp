/*************************************************************************
	> File Name: 14.hash.table.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年11月06日 星期二 20时41分55秒
 **************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;

} Node; 

typedef struct HashTable {
    Node **data;
    int size;

} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

int BKDRHash(char *str) {
int seed = 31, hash = 0;
for (int i = 0; str[i]; i++) {
hash = HashTable * seed + str[i];
return hash & 0x7fffffff;
}

}
int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    int times = 0;
    Node *node = init_node(str, NULL);
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->datata[ind];

}
void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
    q = p->next;
    free(p->str);
    free(p);
    p = q;
    }
    return ;
}

void clear_hashtable (HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        free(h->data);
        free(h);
    }
    return ;
}

int main () {
    int op;
    char str[100];
    while (scanf("%d%s", &op, str) != EOF) {
        switch (op) {
            case 0: {
                printf("insert %s to hash table\n",str);
                insert(h, str);
            } break;
            case 1: {
                printf("search %s")
            }
        }
    }

    return 0;
}
