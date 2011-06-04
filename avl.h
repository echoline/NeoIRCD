#ifndef __AVL_H
#define __AVL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Avl	Avl;
typedef struct Avltree	Avltree;
typedef struct Avlwalk	Avlwalk;

struct Avl {
	Avl *p;
	Avl *n[2];
	int bal;
};

Avl *avlnext(Avlwalk *walk);
Avl *avlprev(Avlwalk *walk);
Avlwalk *avlwalk(Avltree *tree);
void deleteavl(Avltree *tree, Avl *key, Avl **oldp);
void endwalk(Avlwalk *walk);
void insertavl(Avltree *tree, Avl *key, Avl **oldp);
Avl *lookupavl(Avltree *tree, Avl *key);
Avltree *mkavltree(int(*cmp)(Avl*, Avl*));
Avl *searchavl(Avltree *tree, Avl *key, int neighbor);

#ifdef __cplusplus
}
#endif

#endif
