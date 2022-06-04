/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strcmp
*/

int my_strlen(char  const *str);

int  my_strcmp(char  const *s1 , char  const *s2)
{
    for (int i = 0; i < my_strlen(s1); i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}