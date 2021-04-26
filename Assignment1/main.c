#include "ex.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    const double length_arr[] = {0.1, 0.2, 0.5, 0.8, 1.0};
    const double porbability_arr[] = {0.001, 0.005, 0.01, 0.05, 0.1};
    const int num_sequences = 5;
    const int max_length = 1000000;
    const double mixed_percentage = 0.05;

    // clock_t start, end;

    int i,j,z;

    printf("Start first experiment. Insertion only\n");
    for(j=0; j<num_sequences; j++)
    {
        ex1(length_arr[j]*max_length);
        // int num_trails = length_arr[j]*max_length;

        // // initialize variables for the operation array;
        // int id_next = 1;

        // Operation *operation_arr = 0;
        // operation_arr = (Operation*)malloc((num_trails*2) * sizeof(Operation));

        // printf("=================================\nExp1, #trails is %d: \n", num_trails);
        // for(i=0; i<num_trails; i++)
        // {
        //     operation_arr[i] = gen_insertion(&id_next);
        // }
        // printf(".......finish creating the operation array for insertion\n");

        // // initialize variables for the treap;
        // Treap *treap = 0;

        // start = clock();
        // for(z=0; z<num_trails; z++)
        // {
        //     treap = treap_insert(operation_arr[z].data, treap);
        // }
        // end = clock();
        // free(treap);
        // printf("The running time for the Treap on %d trails is: %f\n", num_trails, (double)(end - start) / (double)(CLOCKS_PER_SEC));

        // // initialize variables for the dynamic array;
        // int num=0, size = 1;
        // Data_Element *dynamic_arr = malloc(sizeof(Operation));

        // start = clock();
        // for(z=0; z<num_trails; z++)
        // {
        //     dynamic_arr = insert_dynamic_array(dynamic_arr, operation_arr[z].data, &num, &size);
        // }
        // end = clock();
        // free(dynamic_arr);
        // printf("The running time for the Dynamic Array on %d trails is: %f\n", num_trails, (double)(end - start) / (double)(CLOCKS_PER_SEC));

        // free(operation_arr);
    }
    printf("End first experiment.\n\n\n");

    printf("Start second experiment.Insertion and Deletion\n");
    for(j=0; j<num_sequences; j++)
    {
        ex2(porbability_arr[j], max_length);
        // // initialize variables for the operation array;
        // int id_next = 1;

        // Operation *operation_arr = 0;
        // operation_arr = (Operation*)malloc((max_length*2) * sizeof(Operation));

        // // always insert first
        // int num_del = 0;
        // operation_arr[0] = gen_insertion(&id_next);

        // for(i=1; i<max_length; i++)
        // {
        //     if ((double)rand()/RAND_MAX < porbability_arr[j])
        //     {
        //         operation_arr[i] = gen_deletion(&id_next, operation_arr, i);
        //         num_del += 1;
        //     } else {
        //         operation_arr[i] = gen_insertion(&id_next);
        //     }
        // }
        // printf(".......finish creating the operation array for deletion and insertion\n");
        // printf("The percentage of deletion is roughly about %f.\n", (double)num_del/max_length);

        // // initialize variables for the treap;
        // Treap *treap = 0;

        // start = clock();
        // for(z=0; z<max_length; z++)
        // {
        //     if (operation_arr[z].type == ADD)
        //     {
        //         treap = treap_insert(operation_arr[z].data, treap);
        //     } 
        //     else if (operation_arr[z].type == DELETE)
        //     {
        //         treap = treap_delet(operation_arr[z].data.key, treap);
        //     } else {}
        // }
        // end = clock();
        // free(treap);
        // printf("The running time for the Treap is: %f\n", (double)(end - start) / (double)(CLOCKS_PER_SEC));

        // // initialize variables for the dynamic array;
        // int num=0, size = 1;
        // Data_Element *dynamic_arr = malloc(size * sizeof(Operation));

        // start = clock();
        // for(z=0; z<max_length; z++)
        // {
        //     if (operation_arr[z].type == ADD)
        //     {
        //         dynamic_arr = insert_dynamic_array(dynamic_arr, operation_arr[z].data, &num, &size);
        //     } 
        //     else if (operation_arr[z].type == DELETE)
        //     {
        //         dynamic_arr = delete_dynamic_array(dynamic_arr, operation_arr[z].data, &num, &size);
        //     } else {}
        // }
        // end = clock();
        // free(dynamic_arr);
        // printf("The running time for the Dynamic Array is: %f\n", (double)(end - start) / (double)(CLOCKS_PER_SEC));

        // free(operation_arr);
    }
    printf("End second experiment.\n\n\n");

    printf("Start third experiment. Insertion and Search\n");
    for(j=0; j<num_sequences; j++)
    {
        ex3(porbability_arr[j], max_length);
        // // initialize variables for the operation array;
        // int id_next = 1;

        // Operation *operation_arr = 0;
        // operation_arr = (Operation*)malloc((max_length*2) * sizeof(Operation));

        // // always insert first
        // int num_search = 0;
        // operation_arr[0] = gen_insertion(&id_next);

        // for(int i=1; i<max_length; i++)
        // {
        //     if ((double)rand()/RAND_MAX < porbability_arr[j])
        //     {
        //         operation_arr[i] = gen_search();
        //         num_search += 1;
        //     } else {
        //         operation_arr[i] = gen_insertion(&id_next);
        //     }
        //     // printf("--> type: %d, id: %d, key: %d\n", operation_arr[i].type, operation_arr[i].data.id, operation_arr[i].data.key);
        // }
        // printf(".......finish creating the operation array for search and insertion\n");
        // printf("The percentage of search is roughly about %f.\n", (double)num_search/max_length);

        // // initialize variables for the treap;
        // Treap *treap = 0;
        // int total_found = 0;

        // start = clock();
        // for(z=0; z<max_length; z++)
        // {
        //     if (operation_arr[z].type == ADD)
        //     {
        //         treap = treap_insert(operation_arr[z].data, treap);
        //     } 
        //     else if (operation_arr[z].type == DELETE)
        //     {
        //         Data_Element ans = treap_search(operation_arr[z].data.key, treap, &total_found);
        //     } else {}
        // }
        // end = clock();
        // free(treap);
        // printf("The running time for the Treap is: %f\n", (double)(end - start) / (double)(CLOCKS_PER_SEC));
        // printf("There are %d elements that are actually in the treap, about %f.\n", total_found, (double)total_found/max_length);

        // // initialize variables for the dynamic array;
        // int num=0, size = 1;
        // total_found = 0;
        // Data_Element *dynamic_arr = malloc(size * sizeof(Operation));

        // start = clock();
        // for(z=0; z<max_length; z++)
        // {
        //     if (operation_arr[z].type == ADD)
        //     {
        //         dynamic_arr = insert_dynamic_array(dynamic_arr, operation_arr[z].data, &num, &size);
        //     } 
        //     else if (operation_arr[z].type == SEARCH)
        //     {
        //         Data_Element ans = search_dynamic_array(dynamic_arr, operation_arr[z].data.key, num);
        //         if (!ans.is_null)
        //             total_found++;
        //     } else {}
        // }
        // end = clock();
        // free(dynamic_arr);
        // printf("The running time for the Dynamic Array is: %f\n", (double)(end - start) / (double)(CLOCKS_PER_SEC));
        // printf("There are %d elements that are actually in the dynamic array, about %f.\n", total_found, (double)total_found/max_length);

        // free(operation_arr);
    }
    printf("End third experiment.\n\n\n");

    printf("Start final experiment. Mixed Operations\n");
    for(j=0; j<num_sequences; j++)
    {
        ex4(length_arr[j]*max_length, mixed_percentage);
        // int num_trails = length_arr[j]*max_length;

        // // initialize variables for the operation array;
        // int id_next = 1;

        // Operation *operation_arr = 0;
        // operation_arr = (Operation*)malloc((num_trails*2) * sizeof(Operation));

        // printf("=================================\n#trails is %d: \n", num_trails);

        // // always insert first
        // int num_search = 0, num_deletion = 0;
        // operation_arr[0] = gen_insertion(&id_next);

        // for(i=1; i<num_trails; i++)
        // {
        //     if ((double)rand()/RAND_MAX < mixed_percentage*2)
        //     {
        //         if ((double)rand()/RAND_MAX < 0.5)
        //         {
        //             operation_arr[i] = gen_search();
        //             num_search += 1;
        //         } else {
        //             operation_arr[i] = gen_deletion(&id_next, operation_arr, i);
        //             num_deletion += 1;
        //         }
        //     } else {
        //         operation_arr[i] = gen_insertion(&id_next);
        //     }
        //     //printf("--> type: %d, id: %d, key: %d\n", operation_arr[i].type, operation_arr[i].data.id, operation_arr[i].data.key);
        // }
        // printf(".......finish creating the operation array for mixed operations\n");
        // printf("The percentage of search is roughly about %f.\n", (double)num_search/num_trails);
        // printf("The percentage of deletion is roughly about %f.\n", (double)num_deletion/num_trails);

        // // initialize variables for the treap;
        // Treap *treap = 0;
        // int total_found = 0;

        // start = clock();
        // for(z=0; z<num_trails; z++)
        // {
        //     if (operation_arr[z].type == ADD)
        //     {
        //         treap = treap_insert(operation_arr[z].data, treap);
        //     } 
        //     else if (operation_arr[z].type == DELETE)
        //     {
        //         treap = treap_delet(operation_arr[z].data.key, treap);
        //     } 
        //     else if  (operation_arr[z].type == SEARCH)
        //     {
        //         Data_Element ans = treap_search(operation_arr[z].data.key, treap, &total_found);
        //     } else {}
        // }
        // end = clock();
        // free(treap);
        // printf("The running time for the Treap on %d trails is: %f\n", num_trails, (double)(end - start) / (double)(CLOCKS_PER_SEC));
        // printf("There are %d elements that are actually in the treap, about %f.\n", total_found, (double)total_found/num_trails);

        // // initialize variables for the dynamic array;
        // int num=0, size = 1;
        // total_found = 0;
        // Data_Element *dynamic_arr = malloc(sizeof(Operation));

        // start = clock();
        // for(z=0; z<num_trails; z++)
        // {
        //     if (operation_arr[z].type == ADD)
        //     {
        //         dynamic_arr = insert_dynamic_array(dynamic_arr, operation_arr[z].data, &num, &size);
        //     } 
        //     else if (operation_arr[z].type == DELETE)
        //     {
        //         dynamic_arr = delete_dynamic_array(dynamic_arr, operation_arr[z].data, &num, &size);
        //     } 
        //     else if  (operation_arr[z].type == SEARCH)
        //     {
        //         Data_Element ans = search_dynamic_array(dynamic_arr, operation_arr[z].data.key, num);
        //         if (!ans.is_null)
        //             total_found++;
        //     } else {}
        // }
        // end = clock();
        // free(dynamic_arr);
        // printf("The running time for the Dynamic Array on %d trails is: %f\n", num_trails, (double)(end - start) / (double)(CLOCKS_PER_SEC));
        // printf("There are %d elements that are actually in the dynamic array, about %f.\n", total_found, (double)total_found/num_trails);

        // free(operation_arr);
    }
    printf("End final experiment.\n\n\n");

    return 0;
}