/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** get_nodes_stack
*/

#include "list.h"
#include "stack.h"

void *stack_top(stack_t stack)
{
    return (list_get_elem_at_front(stack));
}
