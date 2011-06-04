#ifndef __HASH_H
#define __HASH_H

#include "avl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Hash	Hash;

struct Hash {
	unsigned int order;
	int (*cmp)(Avl *l, Avl *r);
	void (*rm)(void *param, void *data);
	Avltree **map;
};

unsigned long hashf(Avl *k, unsigned int order);
int mkhash(Hash *hash, unsigned int order);
Avl *lookuphash(Hash *hash, Avl *data);
void inserthash(Hash *hash, Avl *data);

#ifdef __cplusplus
}
#endif

#endif
