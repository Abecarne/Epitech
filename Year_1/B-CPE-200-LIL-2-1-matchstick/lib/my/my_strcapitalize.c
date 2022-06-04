/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_revstr
*/

int  my_putstr(char  const *str);

int est_lettre(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return (1);
    }
    return (0);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    if (str[0] >= 'a' && str[0] <= 'z')  {
        str[0] -= 32;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (est_lettre(str[i - 1]) == 0 && (est_lettre(str[i]))) {
            str[i] -= 32;
        }
    }
    my_putstr(str);
    return (0);
}