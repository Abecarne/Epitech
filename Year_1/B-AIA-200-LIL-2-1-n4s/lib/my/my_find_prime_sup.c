/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday05-simon.auduberteau
** File description:
** my_find_prime_sup
*/
int  my_is_prime(int nb);

int  my_find_prime_sup(int nb)
{
    int i = nb;
    int prime = 1;

    for (; my_is_prime(nb) != 1; nb++);
    return (nb);
}