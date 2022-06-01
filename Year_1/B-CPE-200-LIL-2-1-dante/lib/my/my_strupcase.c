/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strupcase
*/

int  my_putstr(char  const *str);

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
    my_putstr(str);
    return (0);
}