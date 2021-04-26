#include "assert.h"
#include "math.h"
#include "data_generator.h"
#include "random_number_generator.h"
#include "stdio.h"


Data_Element gen_element(int *id_next) {
    Data_Element new;

    new.id = *id_next;
    new.key = generate_random_number(RANDOM_MAX);
    new.is_null = 0;

    *id_next += 1;

    return new;
}

Operation gen_insertion(int *id_next)
{
    Operation insertion;
    insertion.type = ADD;
    insertion.data = gen_element(id_next);

    return insertion;
}

Operation gen_deletion(int *id_next, Operation *arr, int num) {
    int id = generate_random_number(*id_next);
    if (id == *id_next)
    {
        id--;
    }

    Operation deletion;
    deletion.type = DELETE;

    int i;
    Data_Element temp == 0;
    for(i=0; i<num; i++) 
    {
        if (arr[i].type == DELETE && arr[i].data.id == id)
        {
            temp.is_null = 0;
            temp.key = generate_random_number(RANDOM_MAX);

            deletion.data = temp;
            return deletion;
        } else {
            if (arr[i].type == ADD && arr[i].data.id == id && !temp)
            {
                temp = arr[i].data;
            }
        }
    }
    
    deletion.data = temp;
    return deletion;
}

Operation gen_search()
{
    Data_Element temp;
    temp.key = generate_random_number(RANDOM_MAX);
    temp.is_null = 0;

    Operation search;
    search.type = SEARCH;
    search.data = temp;

    return search;
}