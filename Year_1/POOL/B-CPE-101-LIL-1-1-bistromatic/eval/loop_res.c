/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-evalexpr-simon.auduberteau
** File description:
** loop_res
*/

char *result_calc(char *dest);

int final_no_prio(char *dest)
{
    int cmp = 0;
    int i = 0;

    for (; dest[i] != '\0'; i++) {
        if (dest[i] == '+' || dest[i] == '-' || dest[i] == '/' ||
            dest[i] == '*' || dest[i] == '%')
            cmp++;
        if (cmp == 2)
            return (i);
    }
    return (i);
}

int is_sign(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%') {
        return (1);
    }
    return (0);
}

int contain_sign(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_sign(str[i] == 1)) {
            return (1);
        }
    }
    return (0);
}