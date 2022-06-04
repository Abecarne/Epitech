/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** Task 05
*/

int my_compute_square_root(int nb)
{
    int i = nb;
    int result = 0;

    if (nb <= 0) {
        return (0);
    } else {
        do {
            i--;
            result = nb / i;
            if (result == i) {
                if (nb % result == 0) {
                    return (result);
                } else {
                    return (0);
                }
                return (result);
            }
        }
        while (result != i);
    }
}
