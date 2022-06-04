/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_evil_str
*/
int my_putstr(char  const *str);
int my_swap(int *a, int *b);
int my_strlen(char  const *str);

char my_swap2(char *a, char *b)
{
    char copie = *a;
    *a = *b;
    *b = copie;
}

char *my_evil_str(char *str)
{
    int len_mot = my_strlen(str);
    int g_d = 0;
    int d_g = len_mot - 1;

    while (g_d <= d_g) {
        my_swap2(&str[g_d], &str[d_g]);
        g_d++;
        d_g--;
    }
    my_putstr(str);
    return (0);
}