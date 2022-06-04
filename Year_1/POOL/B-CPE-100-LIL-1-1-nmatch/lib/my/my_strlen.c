/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_swap
*/

int my_strlen(char  const *str)
{
    int cpt = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        cpt++;
    }
    return (cpt);
}