/*
** EPITECH PROJECT, 2020
** my
** File description:
** Task 02
*/

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
char *my_strcpy(char const *src);
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
char *my_strcat(char *str1, char *str2);
char *my_strncat(char *dest, char const *src, int nb);

int my_printf(const char *format, ...);
int my_print_str(int i, const char *s, char *content);
int my_print_int(int i, const char *s, int content, int x);
int my_print_int2(int i, const char *s, int content, int x);
int my_print_mod(int i, const char *s);
int my_print_space(int i, const char *s);
void my_print_binary(int nb);
int my_put_mod(int i);
int my_print_char(int i, const char *format);
void my_print_nonascii(const char *s);
void my_print_oct(int nb);
void my_print_oct2(int nb);
int check_positive(int nb);
void my_print_hex(int nb);
void my_print_positive(int nb);
char *fill_str(int b, char a);
int check_mod(int i, const char *format);
int my_print_other(int i, const char *s, int content, int x);
void my_print_zero(int i, const char *s, int content, int x);
void my_print_hash(int i, const char *s, int content, int x);
void my_print_empty(int i, const char *s, int content, int x);
int skip_space(int i, const char *s);
char *my_int_to_str(int nb);
int my_tablen(char **tab);
void my_put_tab(char **tab);
char **my_tabcpy(char **tab);
int my_putchar_error(char c);
int my_putstr_error(char const *str);
