#include "Treap.h"
#include "random_number_generator.h"
#include "math.h"
#include "assert.h"
#include <stdlib.h>
#include <stdio.h>


Treap* rotate_left(Treap *treap) 
{
    Treap *right = treap->right;
    Treap *right_left = right->left;

    right->left = treap;
    treap->right = right_left;

    return right;
}

Treap* rotate_right(Treap *treap)
{
    Treap *left = treap->left;
    Treap *left_right = left->right;

    left->right = treap;
    treap->left = left_right;

    return left;
}

Treap* treap_insert(Data_Element data, Treap *treap)
{
    if (treap == 0)
    {
        return gen_treap(data);
    }

    if ((data.key > treap->data.key) ||
        (data.key == treap->data.key && data.id > treap->data.id))
    {
        if (treap->right == 0)
        {
            treap->right = gen_treap(data);
        } else {
            treap->right = treap_insert(data, treap->right);
        }

        if (treap->right->priority < treap->priority)
        {
            treap = rotate_left(treap);
        }
    } 
    else if (data.key < treap->data.key ||
            (data.key == treap->data.key && data.id < treap->data.id))
    {
        if (treap->left == 0)
        {
            treap->left = gen_treap(data);
        } else {
            treap->left = treap_insert(data, treap->left);
        }

        if (treap->left->priority < treap->priority)
        {
            treap = rotate_right(treap);
        }
    }

    return treap;
}

Treap* treap_delet(int key, Treap *treap)
{
    // safe guard
    if (treap == 0)
    {
        return treap;
    }

    // find the node first
    if (key > treap->data.key)
    {
        treap->right = treap_delet(key, treap->right);
    }
    else if (key < treap->data.key)
    {
        treap->left = treap_delet(key, treap->left);
    } else {
        // now it is found, move it to the leaf
        //treap.priority = RAND_MAX+1;

        // need safety guard to prevent accessing priority of a 0 pointer.
        if (treap->left != 0 && treap->right != 0)
        {
            // if left < right, then left need to be the new root. And vice versa.
            if (treap->left->priority < treap->right->priority)
            {
                treap = rotate_right(treap);
                treap->right = treap_delet(key, treap->right);
            } else {
                treap = rotate_left(treap);
                treap->left = treap_delet(key, treap->left);
            }
        }
        else if (treap->left == 0 && treap->right != 0)
        {
            treap = rotate_left(treap);
            treap->left = treap_delet(key, treap->left);
        }
        else if (treap->left != 0 && treap->right == 0)
        {
            treap = rotate_right(treap);
            treap->right = treap_delet(key, treap->right);
        } else {
            free(treap);
            treap = 0;
        }
    }

    return treap;
}

Data_Element treap_search(int key, Treap *treap, int *total_found)
{
    Data_Element ans;
    ans.is_null = 1;

    // should never happen
    if (treap == 0)
    {
        return ans;
    }

    if (key > treap->data.key)
    {
        ans = treap_search(key, treap->right, total_found);
    } 
    else if (key < treap->data.key)
    {
        ans = treap_search(key, treap->left, total_found);
    }
    else {
        *total_found += 1;
        return treap->data;
    }

    return ans;
}

Treap* gen_treap(Data_Element data)
{
    // srand(time(0));
    Treap *node;
    node = malloc(sizeof(Treap));
    node->data = data;
    node->priority = generate_random_number(RANDOM_MAX);
    node->left = 0;
    node->right = 0;

    return node;
}

void print_treap(Treap *treap)
{
    if (treap != 0) 
    {
        print_treap(treap->left);
        printf(" --> id: %d, key: %d, p: %d; <-- \n", treap->data.id, treap->data.key, treap->priority);
        print_treap(treap->right);
    }
}

int treap_size(Treap* treap, int size)
{
    if (treap!=0)
    {
        size += treap_size(treap->left, 0);
        size += 1;
        size += treap_size(treap->right, 0);

        return size;
    }

    return 0;
}