/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday06-simon.auduberteau
** File description:
** my_revstr
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char tmp[len];
    int a = 0;

    for (int i = len - 1 ; i >= 0; i--) {
        tmp[a] = str[i];
        a++;
    }
    tmp[a] = '\0';
    for (int i = 0; tmp[i] != '\0'; i++)
        str[i] = tmp[i];
    return (str);
}