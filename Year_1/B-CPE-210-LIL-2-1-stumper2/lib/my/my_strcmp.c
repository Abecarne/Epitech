/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Compare 2 strings
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int ret = 1;

    if (my_strlen(s1) != my_strlen(s2))
        ret = 0;
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            ret = 0;
    return (ret);
}