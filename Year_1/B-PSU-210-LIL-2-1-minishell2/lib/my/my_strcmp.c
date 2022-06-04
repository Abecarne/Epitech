/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strcmp
*/

int my_strlen(char  const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int max = (my_strlen(s1) <= my_strlen(s2)) ? my_strlen(s1) : my_strlen(s2);

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    for (int i = 0; i < max; i++)
        if (s1[i] != s2[i])
            return (1);
    return (0);
}