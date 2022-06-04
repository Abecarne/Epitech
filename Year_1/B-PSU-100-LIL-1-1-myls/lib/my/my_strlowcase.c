/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strlowcase
*/

int  my_putstr(char  const *str);

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    my_putstr(str);
}