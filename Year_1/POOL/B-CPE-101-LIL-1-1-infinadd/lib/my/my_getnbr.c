/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_getnbr
*/

int my_strlen(char *str);

int final_sign(char const *str, int nb_signes)
{
    int sign = 1;
    for (int i = 0; i < nb_signes; i++) {
        if (str[i] == '-') {
            sign *= -1;
        }
    }
    return (sign);
}

int nb_sign(char const *str)
{
    int nbr_of_sign = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == '-' || str[i] == '+') {
            nbr_of_sign++;
        }
    }
    return (nbr_of_sign);
}

int nb_digit(char const *str)
{
    int nbr_of_digit = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr_of_digit++;
        }
    }
}

int  my_getnbr(char  const *str)
{
    int len = my_strlen(str);
    long cpt_nb_chiffres = 1;
    int nb_signes = nb_sign(str);
    int nb_chiffres = nb_digit(str);
    int signe_final = final_sign(str, nb_signes);
    long nb_final = 0;
    long operation = 0;

    for (int i = 0; i < (len - nb_signes) - 1; i++)
        cpt_nb_chiffres *= 10;
    for (int j = nb_signes; j < len; j++) {
        operation = (str[j] - 48) * cpt_nb_chiffres;
        nb_final += (operation * signe_final);
        cpt_nb_chiffres /= 10;
    }
    if ((nb_final < -2147483648) || (nb_final > +2147483647) || (nb_final == 0))
        nb_final = 0;
    return (nb_final);
}