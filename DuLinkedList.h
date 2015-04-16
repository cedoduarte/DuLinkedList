#ifndef DULISTAENLAZADA_H
#define DULISTAENLAZADA_H

typedef struct DuNode DuNode;
typedef struct DuLinkedList DuLinkedList;

struct DuNode
{
    DuNode *pNext;
    DuNode *pPrev;
    void *ptr;
};

struct DuLinkedList
{
    DuNode *pBegin;
    DuNode *pEnd;
};

#ifdef __cplusplus
extern "C"
{
#endif

DuNode *DuNodeNew(void);

void DuNext(DuNode **n);

void DuAdvance(DuNode *node, int n);

void *DuData(DuNode *n);

DuLinkedList *DuLinkedListNew(void);

void DuLinkedListFree(DuLinkedList *L);

void DuLinkedListClear(DuLinkedList *L);

int DuLinkedListSize(DuLinkedList *L);

void DuLinkedListAppend(DuLinkedList *L, void *ptr);

DuNode *DuBegin(DuLinkedList *L);

DuNode *DuEnd(DuLinkedList *L);

void DuForEach(DuNode *begin,
               DuNode *end,
               void (*callback)(DuNode *, void *),
               void *data);

#ifdef __cplusplus
}
#endif

#endif // DULISTAENLAZADA_H

