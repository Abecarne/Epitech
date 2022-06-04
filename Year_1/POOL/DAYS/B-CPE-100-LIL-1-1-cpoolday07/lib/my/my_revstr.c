/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_revstr
*/

int  my_putstr(char  const *str)
{
    for (int i = 0; str[i] !='\0'; i++) {
        my_putchar(str[i]);
    }
}

int my_strlen(char  const *str)
{
    int cpt = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        cpt++;
    }
    return (cpt);
}

char my_swap2(char *a, char *b)
{
    char copie = *a;
    *a = *b;
    *b = copie;
}

char *my_revstr(char *str)
{
    int len_mot = my_strlen(str);
    int g_d = 0;
    int d_g = len_mot - 1;

    while (g_d <= d_g) {
        my_swap2(&str[g_d], &str[d_g]);
        g_d++;
        d_g--;
    }
    return (str);
}