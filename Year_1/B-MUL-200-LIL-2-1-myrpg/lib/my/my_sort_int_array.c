/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** sort int array
*/

int *update(int *array, int destination, int max, int size)
{
    int save_pos = 0;

    for (int i = size - 1; i >= destination; i--) {
        if (array[i] <= max) {
            max = array[i];
            save_pos = i;
        }
    }
    array[save_pos] = array[destination];
    array[destination] = max;
    return (array);
}

void my_sort_int_array(int *array, int size)
{
    int max = 2147483647;

    for (int destination = 0; destination < size; destination++)
        array = update(array, destination, max, size);
}
