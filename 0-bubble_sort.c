#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers
 * @array: an array of integers
 * @size: size of the array
 * Return: returns void
*/
void bubble_sort(int *array, size_t size)
{
    /** Checking for null pointer or size < 2 **/
    if (array == NULL || size < 2)
        return;

    size_t i, j;
    int temp, flag;

    /** This's the outer loop: each pass through the array **/
    for (i = 0; i < size - 1; i++)
    {
        /** Reset flag at the start of each pass **/
        flag = 0;
        /** This's the inner loop: compares adjacent elements **/
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j + 1] < array[j])
            {
                /** Perform the swap **/
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                /** Indicates that a swap occur **/
                flag = 1;
                print_array(array, size);
            }
        }
        /** If no swaps occurred, the array is sorted **/
        if (flag == 0)
            break;
    }
}
