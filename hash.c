#include "hash.h"

unsigned long hashf(Avl *k, unsigned int order) {
	return ((unsigned long int)k & ((1 << order) - 1));
}

int mkhash(Hash *hash, unsigned int order) {
	if (order > sizeof(long) * 4)
		return -1;

	hash->order = order;
	hash->map = calloc((unsigned int) (1 << order), sizeof(Avltree*));

	return 0;
}

Avl *lookuphash(Hash *hash, Avl *data) {
	unsigned long cur = hashf(data, hash->order);
	return (lookupavl(hash->map[cur], data));
}

int avlcmp(Avl *l, Avl *r) {
	return 0;
}

void inserthash(Hash *hash, Avl *data) {
	unsigned long cur = hashf(data, hash->order);
	Avl *oldp;
	if (hash->map[cur] == NULL)
		hash->map[cur] = mkavltree(&avlcmp);
	insertavl(hash->map[cur], data, &oldp);
}
