/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
char *my_strdup(char  const *src);
char *concat_params(int argc , char **argv);
int est_lettre(char c);
int my_strlen_strstr(char  const *str);
void my_printf(char *str, ...);
int my_change_base(int nb, int base);
int my_put_unbr(unsigned nb);
int my_put_hexa(int nb);
int my_put_maj_hexa(int nb);
unsigned long long my_put_hexa_pointer(unsigned long long int nb);
void my_put_maj_s(char *str);

#endif /* MY_H_ */