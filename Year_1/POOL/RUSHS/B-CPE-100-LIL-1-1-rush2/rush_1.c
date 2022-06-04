/*
** EPITECH PROJECT, 2020
** Anthony Becarne & Noa Chambrin
** File description:
** rush_1
*/

#include <stdlib.h>

int my_strlen(char  const *str);

void my_putchar(char c);

int  my_put_nbr(int nb);

void display1(char c, int nb)
{
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(nb);
    my_putchar('\n');
}

int cpt_letters1(char *str, char a)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == a) || (str[i] == a - 32) || (str[i] == a + 32)) {
            cpt++;
        }
    }
    return (cpt);
}

void nb_letters1(int argc, char **argv)
{
    char *str = argv[1];
    char letter = argv[2][0];
    int nb_letter;

    nb_letter = cpt_letters1(str, letter);
    if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
        display1(letter, nb_letter);
    } else {
        write(2, "Invalid char\n", 13);
    }
}