/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** infinite addition
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *greater(char *a, char *b)
{
    int len1 = my_strlen(a);
    int len2 = my_strlen(b);

    if (len1 <= len2) {
        return (b);
    } else {
        return (a);
    }
}

char *remove_zero(char *str)
{
    int count = 0;
    int i = 0;

    while(str[i] == '0') {
        count++;
        i++;
    }
    
    for (int j = count; str[j] != '\0'; j++) {
        my_putchar(str[j]);
    }
}

char *final_string(int ac, char **av)
{
    char *s1 = av[1];
    char *s2 = av[2];
    char *final = malloc(sizeof(char) * (my_strlen(greater(s1, s2)) + 2));
    int index_s1 = my_strlen(s1) - 1;
    int index_s2 = my_strlen(s2) - 1;
    int index_fin;
    int tmp = 0;
    int tmp_of_tmp = 0;

    for (int i = 0; i <= (my_strlen(greater(s1, s2)) + 1); i++)
        final[i] = '0';
    final[my_strlen(greater(s1, s2)) + 1] = '\0';
    for (index_fin = my_strlen(final) - 1; index_fin >= 1
         && index_s1 >= 0 && index_s2 >= 0; index_fin--) {
        tmp = ((s1[index_s1] - '0') + (s2[index_s2] - '0') + (final[index_fin] - '0'));
        if (tmp >= 10) {
            tmp_of_tmp = tmp;
            final[index_fin] = ((tmp_of_tmp % 10) + '0');
            final[index_fin - 1] = '1';
        } else {
            final[index_fin] = (tmp + '0');
        }
        index_s1--;
        index_s2--;
        if (index_s1 < 0) {
            for (index_s2; index_s2 >= 0; index_s2--) {
                index_fin--;
                tmp = ((s2[index_s2] - '0') + (final[index_fin] - '0'));
                if (tmp >= 10) {
                    tmp_of_tmp = tmp;
                    final[index_fin] = ((tmp_of_tmp % 10) + '0');
                    final[index_fin - 1] = '1';
                } else {
                    final[index_fin] = (tmp + '0');
                }
            }
        }
        if (index_s2 < 0) {
            for (index_s1; index_s1 >= 0; index_s1--) {
                index_fin--; 
                tmp = ((s1[index_s1] - '0') + (final[index_fin] - '0'));
                if (tmp >= 10) {
                    tmp_of_tmp = tmp;
                    final[index_fin] = ((tmp_of_tmp % 10) + '0');
                    final[index_fin - 1] = '1';
                } else {
                    final[index_fin] = (tmp + '0');
                }
            }
        }
    }
    remove_zero(final);
}
