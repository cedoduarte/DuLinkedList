#include "DuLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

DuNode *DuNodeNew(void)
{
    DuNode *n = (DuNode *) malloc(sizeof(DuNode));
    n->pPrev = NULL;
    n->pNext = NULL;
    n->ptr = NULL;
    return n;
}

DuLinkedList *DuLinkedListNew(void)
{
    DuLinkedList *L = (DuLinkedList *) malloc(sizeof(DuLinkedList));
    L->pBegin = NULL;
    L->pEnd = NULL;
    return L;
}

void DuLinkedListClear(DuLinkedList *L)
{
    DuNode *n = L->pBegin, *m;
    while (n != NULL) {
        m = n->pNext;
        free(n);
        n = m;
    }
    L->pBegin = NULL;
    L->pEnd = NULL;
}

void DuLinkedListAppend(DuLinkedList *L, void *ptr)
{
    if (L->pBegin == NULL) {
        L->pBegin = DuNodeNew();
        L->pEnd = L->pBegin;
        L->pBegin->ptr = ptr;
        return;
    }
    DuNode *n = L->pBegin;
    if (L->pBegin != L->pEnd) {
        while (n != L->pEnd) {
            n = n->pNext;
        }
    }
    n->pNext = DuNodeNew();
    n->pNext->pPrev = n;
    n->pNext->ptr = ptr;
    L->pEnd = n->pNext;
}

DuNode *DuBegin(DuLinkedList *L)
{
    return L->pBegin;
}

void DuNext(DuNode **n)
{
    if (*n == NULL) {
        return;
    }
    *n = (**n).pNext;
}

int DuLinkedListSize(DuLinkedList *L)
{
    int contador = 0;
    for (DuNode *n = DuBegin(L); n != NULL; DuNext(&n)) {
        ++contador;
    }
    return contador;
}

void DuForEach(DuNode *begin,
               DuNode *end,
               void (*callback)(DuNode *, void *),
               void *data)
{
    for (DuNode *n = begin; n != end; DuNext(&n)) {
        callback(n, data);
    }
}

void *DuData(DuNode *n)
{
    return n->ptr;
}

void DuLinkedListFree(DuLinkedList *L)
{
    DuLinkedListClear(L);
    free(L);
}

void DuAdvance(DuNode *node, int n)
{
    (void) node;
    (void) n;
    // TODO: ...
}
