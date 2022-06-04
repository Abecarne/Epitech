/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** final_calcul
*/

int final(char *dest, int k, char *ind_prio, int j);

int beginning(char *dest, int i, char *ind_prio, int j);

int operators(int a, int c, char b);

int my_spe_getnbr_end(char *str, int begin, int end);

int my_spe_getnbr(char *str, int begin);

char *replace_dest_by_res(char *dest, char *calc, int res);

char *calc_to_char(int beg, int end, char *dest);

char *factor(char *str);

char *sum(char *str);

char *multiplicater(char *dest, char *ind_prio)
{
    int i = 0;
    int k = 0;
    int res = 0;

    for (int j = 0; ind_prio[j] != '\0';) {
        i = beginning(dest, i, ind_prio, j);
        k = final(dest, k, ind_prio, j);
        res = operators(my_spe_getnbr(dest, i),
        my_spe_getnbr_end(dest, (ind_prio[j] - 48) + 1, k),
        dest[ind_prio[j] - 48]);
        dest = replace_dest_by_res(dest, calc_to_char(i, k, dest), res);
        ind_prio = factor(dest);
    }
    return (dest);
}

char *summer(char *dest, char *ind_sum)
{
    int i = 0;
    int k = 0;
    int res = 0;

    for (int j = 0; ind_sum[j] != '\0';) {
        i = beginning(dest, i, ind_sum, j);
        k = final(dest, k, ind_sum, j);
        res = operators(my_spe_getnbr(dest, i),
        my_spe_getnbr_end(dest, (ind_sum[j] - 48) + 1, k),
        dest[ind_sum[j] - 48]);
        dest = replace_dest_by_res(dest, calc_to_char(i, k, dest), res);
        ind_sum = sum(dest);
    }
    return (dest);
}