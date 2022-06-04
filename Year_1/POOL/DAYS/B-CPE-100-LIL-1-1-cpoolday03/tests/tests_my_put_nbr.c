/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** tests my_put_nbr
*/

int my_put_nbr(int nb);

int main(void)
{
    my_put_nbr(0);
    my_put_nbr(42);
    my_put_nbr(-42);
    my_put_nbr(-2147483648);
    my_put_nbr(2147483647);
}
