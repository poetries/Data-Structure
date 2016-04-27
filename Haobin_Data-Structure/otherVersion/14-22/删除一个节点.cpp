r = p->pNext;
p->pNext = p->pNext->pNext;
free(r);