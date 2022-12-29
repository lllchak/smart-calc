#include "sutils.h"

void print_stack(stack* stk) {
    /*
    Description:
        Prints out stack values

    Args:
        (stack_t*) stk : Pointer to stack_t object to print out

    Returns:
        None (only prints stack values)
    */
    
    node* curr = stk->head;
    node* next = NULL;

    while (curr) {
        if (curr->data->is_num) printf("'%f'", curr->data->num_var);
        else printf("'%c' ", curr->data->operator);
        next = curr->next;
        curr = next;
    }
}
