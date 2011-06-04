#include "hash.h"

int main() {
	Hash htable;
	Avl key;

	assert(mkhash(&htable, 5) == 0);

	inserthash(&htable, &key);

	Avl *a = lookuphash(&htable, &key);

	printf("%p\n", a);
}
