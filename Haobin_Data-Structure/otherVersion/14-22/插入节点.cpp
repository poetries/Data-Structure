r = p->pNext; p->pNext = q;  q->pNext = r;
q->pNext = p->pNext;  p->pNext = q;
