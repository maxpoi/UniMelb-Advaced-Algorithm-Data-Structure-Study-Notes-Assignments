#include "data_generator.h"

typedef struct Treap Treap;
struct Treap
{
    Data_Element data;
    int priority;
    Treap *left, *right;
};

Treap* rotate_left(Treap *treap);
Treap* rotate_right(Treap *treap);
Treap* treap_insert(Data_Element data, Treap *treap);
Treap* treap_delet(int key, Treap *treap);
Data_Element treap_search(int key, Treap *treap, int *total_found);
Treap* gen_treap(Data_Element data);
void print_treap(Treap *treap);
int treap_size(Treap* treap, int size);
