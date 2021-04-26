#include <stdlib.h>
#include <stdio.h>
#include "data_generator.h"
#include "Dynamic_Array.h"


Data_Element* insert_dynamic_array(Data_Element *arr, Data_Element data,
                                    int *num, int *size)
{
    arr[*num] = data;

    *num += 1;
    if (*num == *size) {
        *size *= 2;
        Data_Element* new_arr = malloc(*size * sizeof(Data_Element));
        
        int i;
        for(i=0; i<*num; i++)
        {
            new_arr[i] = arr[i];
        }

        free(arr);
        arr = 0;
        return new_arr;
    }

    return arr; 
}

Data_Element* delete_dynamic_array(Data_Element *arr, Data_Element data,
                                    int *num, int *size)
{
    int i;
    for(i=0; i<*num; i++)
    {
        if (arr[i].key == data.key)
        {
            arr[i] = arr[*num-1];

            *num -= 1;
            if (*num < *size/4)
            {
                *size /= 2;
                Data_Element* new_arr = malloc(*size * sizeof(Data_Element));

                int j;
                for(j=0; j<*num; j++)
                {
                    new_arr[j] = arr[j];
                }

                free(arr);
                arr = 0;
                return new_arr;
            }
        }
    }

    return arr;                     
}

Data_Element search_dynamic_array(Data_Element *arr, int key, int num)
{
    Data_Element ans;
    ans.is_null = 1;

    int i;
    for(i=0; i<num; i++)
    {
        if (arr[i].key == key)
        {
            return arr[i];
        }
    }

    return ans;
}