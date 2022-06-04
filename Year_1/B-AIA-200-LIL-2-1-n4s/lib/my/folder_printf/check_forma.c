/*
** EPITECH PROJECT, 2020
** B-PSU-100-LIL-1-1-myprintf-simon.auduberteau
** File description:
** check_forma
*/

int check_forma(char forma)
{
    char type_forma[] = "SploXxcsdub#.";

    for (int i = 0; type_forma[i] != '\0'; i++)
        if (forma == type_forma[i])
            return (0);
    return (1);
}