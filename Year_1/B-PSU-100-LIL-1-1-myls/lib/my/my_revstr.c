/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_revstr
*/

char my_swap2(char *a, char *b);

int  my_putstr(char  const *str);

int my_strlen(char  const *str);

char *my_revstr(char *str)
{
    int len_mot = my_strlen(str);
    int g_d = 0;
    int d_g = len_mot - 1;
    char copie;

    while (g_d <= d_g) {
        copie = str[g_d];
        str[g_d] = str[d_g];
        str[d_g] = copie;
        g_d++;
        d_g--;
    }
    return (str);
}