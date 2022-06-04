/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

/* Affichage */
void my_putchar(char c);
void my_put_octal(int nb);
void my_put_maj_s(char *str);
void my_printf(char *str, ...);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_put_unbr(unsigned nb);
int my_put_binary(int nb);
int my_put_majhexa(int nb);
int my_put__majhexa(int nb);
int my_put__hexa(int nb);
int my_putstrmaj(char const *str);
int my_put_hexa(int nb);
int my_put_maj_hexa(int nb);
unsigned my_put_dec_unsigned(unsigned nb);
unsigned long long my_put_adress(unsigned long long nb);
unsigned long long my_put_hexa_pointer(unsigned long long int nb);

/* Conversions */
int my_getnbr(char const *str);
char *int_to_char(int nb);
char *my_revstr(char *str);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char **str_to_array(char *str);

/* Comparaisons / Comptages*/
void my_swap(int *a, int *b);
int my_isneg(int nb);
int est_lettre(char c);
int my_strlen(char const *str);
int my_strlen_strstr(char  const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
unsigned long long my_nb_len(unsigned long long nb);

/* Copies / Concaténations */
char *my_strdup(char  const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
char *my_strncpy(char *dest, char const *src, int n);

/* Calculs */
int my_is_prime(int nb);
int my_change_base(int nb, int base);
int my_find_prime_sup(int nb);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);

#endif /* MY_H_ */