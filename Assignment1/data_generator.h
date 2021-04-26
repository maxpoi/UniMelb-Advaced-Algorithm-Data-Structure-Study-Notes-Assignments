#define ADD 1
#define DELETE -1
#define SEARCH 0

typedef struct Data_Element Data_Element;
struct Data_Element {
    int id;
    int key;
    int is_null;
};

typedef struct Operation Operation;
struct Operation {
    int type;
    Data_Element data;
};

Data_Element gen_element();
Operation gen_insertion(int *id);
Operation gen_deletion(int *id, Operation *arr, int num);
Operation gen_search();