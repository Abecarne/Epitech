/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** delete_stack
*/

#include "list.h"
#include "stack.h"

bool stack_pop(stack_t *stack_ptr)
{
    return (list_del_elem_at_front(stack_ptr));
}

void stack_clear(stack_t *stack_ptr)
{
    list_clear(stack_ptr);
}