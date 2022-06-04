/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Fonction vide
*/

int my_getnbr(char const *str)
{
    int	i = 0;
    int	j = 0;
    int k = 0;

    while (str[i] == '-')
    {
        ++i;
        k = i;
    }

    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
            j *= 10;
            j += str[i] - 48;
            ++i;
    }
    if (k % 2 == 1) {
        return (-j);
    } else {
        return (j);
    }
}