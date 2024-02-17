#include "sort.h"

/**
 * insertion_sort_list - Sort a list using the Insertion Sort algorithm
 * @list: Double pointer to the head of the list
 * Return: Returns void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node, *temp;

    /** Check for null pointer or a list with fewer than 2 nodes **/
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;
    
    /** Start with the second node in the list **/
    current = (*list)->next;

    while (current != NULL)
    {
        next_node = current->next;

        /** Move current node backwards in the list until it's in the correct position **/
        while (current->prev != NULL && current->n < current->prev->n)
        {
            /** Swap with previous node **/
            temp = current->prev;
            current->prev = temp->prev;
            temp->next = current->next;

            if (current->next != NULL)
                current->next->prev = temp;

            if (temp->prev != NULL)
                temp->prev->next = current;
            /** Update the list head if necessary **/
            else
                *list = current;

            current->next = temp;
            temp->prev = current;

            /** Adjust the pointers after swapping **/
            current = current->prev;
            print_list(*list);
        }

        /** Move to the next node to be sorted **/
        current = next_node;
    }
}
