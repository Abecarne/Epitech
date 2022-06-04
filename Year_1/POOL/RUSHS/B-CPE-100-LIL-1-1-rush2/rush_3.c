/*
** EPITECH PROJECT, 2020
** Anthony Becarne & Noa Chambrin
** File description:
** rush_1
*/
#include <stddef.h>
#include <stdlib.h>

int my_strlen(char  const *str);

void my_putchar(char c);

int  my_put_nbr(int nb);

void display_nb3(char c, int nb)
{
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(nb);
}

void display_proba3(int ent, int flo)
{
    my_putchar('(');
    my_put_nbr(ent);
    my_putchar('.');
    my_put_nbr(flo);
    my_putchar('%');
    my_putchar(')');
}

int cpt_letters3(char *str, char a)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == a) || (str[i] == a - 32) || (str[i] == a + 32)) {
            cpt++;
        }
    }
    return (cpt);
}

void proba3(char *str, char a)
{
    int nb_alpha = 0;
    float proba = 0;
    int nb_letter = cpt_letters3(str, a);
    int part_ent = 0;
    int part_dec = 0;
    int mul = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z')) {
            nb_alpha++;
        }
    }
    proba = (float)nb_letter / (float)nb_alpha * 100;
    mul = proba * 100;
    part_ent = proba;
    part_dec = mul % 100;
    display_proba3(part_ent, part_dec);
}

void nb_letters3(int argc, char **argv)
{
    char *str = argv[1];
    int nb_let = 0;
    char letter;

    for (int i = 2; i < argc; i++) {
        letter = argv[i][0];
        if ((letter >= 'a' && letter <= 'z')
        || (letter >= 'A' && letter <= 'Z')) {
            nb_let = cpt_letters3(str, letter);
        display_nb3(letter, nb_let);
        my_putchar(' ');
        proba3(str, argv[i][0]);
        my_putchar('\n');
        } else {
            write(2, "Invalid char\n", 13);
        }
    }
}

