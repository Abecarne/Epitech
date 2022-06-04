/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** Fir tree
*/

void my_putchar(char c);

void print_sapin(int size)
{   
    int reduceline = 5;
    int reduceamt = 4;
    int star = 1;
    int reduce = 1;
    
    for (int i = 1; i <= calcul_etage(size); i++, star += 2) {
        if (i == reduceline) {
            star -= reduceamt;
            reduce ++;
            reduceline = calcul_etage(reduce) + 1;
        if (reduce % 2 != 0)
            reduceamt += 2;
        }
        for (int e = 0; e < ((colonnes(size) - 2) / 2) - (star / 2) + 1; e++) {
            my_putchar(' ');
        }
         for (int s = 1; s <= star; s++) {
            my_putchar('*');
        }
        my_putchar('\n');
    }
}

int print_wood(int size)
{
    int width = 1;

    for (int i = 1; i <= size; i++) {
        if (i % 2 == 0) {
            width += 2;
        }
    }
    for (int l = 1; l <= size; l++) {
        for (int s = 0; s < (colonnes(size) / 2) - (width / 2); s++) {
            my_putchar(' ');
        }
        for (int e = 0; e < width; e++) {
            my_putchar('|');
        }
        my_putchar('\n');
    }
}

int calcul_etage(int size)
{
    int res = 0;

    for (int i = 0; i < size; i++) {
        res += i + 4;
    }
    return (res);
}

int colonnes(int size)
{
    int res = 1;
    int ligne = 4;
    int sep = 1;

    for (int i = 0; i < size; i++, ligne++) {
        res  = res + (2 * (ligne - sep));
        if (i % 2 == 0)
            sep++;
    }
    return (res);
}

void  tree(int size)
{
    if (size <= 0)
        return (0);
    print_sapin(size);
    print_wood(size);
}