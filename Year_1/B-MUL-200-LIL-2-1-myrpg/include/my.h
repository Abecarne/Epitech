/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY
#define MY
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>

#define OCTALE  "01234567"
#define BIN     "01"
#define HEXA    "0123456789ABCDEF"
#define HEXA_2  "0123456789abcdef"
#define DECIMAL "0123456789"

//my_printf

//fork_engine
char *add_main(char *str1, char *str2);
char *sub_main(char *str1, char *str2);
char *div_main(char *str1, char *str2);
char *mod_main(char *str1, char *str2);
char *mul_main(char *str1, char *str2);

//infin_add
char *infin_add(char *str1, char *str2);

//infin_div
char *last_part_div(char *mul_nbr, char *remainder, char *str1, char *str2);
char *first_div_part(char *str1, char *str2, char *remainder, char *mul_nbr);
char *infin_div(char *str1, char *str2);

//infin_mod
char *last_mod_div(char *remainder, char *str1,  char *str2);
char *first_mod_part(char *str1, char *str2, char *remainder);
char *infin_mod(char *str1, char *str2);

//infin_mul
char *get_first_nb(char *nb1, char const *nb2, char *str_nb1);
char *get_final_nb(char *nb1, char const *nb2, char *str_nb, char *str_result);
char *infin_mul(char *nb1, char *nb2);

//infin_sub
char *infin_sub_negative(char *negatif, char *positif);
char *infin_sub_positive(char *positif, char *negatif);

//mul_addition
char *mul_addition(char *str1, char *str2);
char *clean(char *str);

//quotient_handle
char *init_first(char *remainder, char *str1, int nb_len, int *i);
int is_quotient(char *nbr, char *str1, char *str2, int nb2_len);
char get_quotient(char *str1, char *str2, int nb2_len);

//clean_syntax
char *remove_useless_zero(char *str);
char *add_minus(char *str);
char *egalize(char *str1, int len);
char *prepare_nbr(char *str1, char *str2);
char *add_zero(char *str);

//clean_syntax2
char *remove_minus(char *str);

//my_str_to_base
int get_arr_size(char *base, char *number);
char digit_to_base(char *base, int nbr, int *converter);
char *base_transform(char *base, int *final_nbr_arr, int *converter, int size);
char *my_str_to_base(char *base, char *number);

//calc_realloc
char *calc_realloc(char *str, char c);

//printf_error
int is_long_flag(char *str, int i);
int is_flag(char c);
int is_float(char *str, int i);
int printf_error(char *str);

//float_function
int find_precision(char *str, int i);
int float_function(char *str, int i, va_list func);

//error_engine_long_flag
int check_base(char *flag);
int check_sign(char *flag);
int check_long(char *flag);
int check_zero(char *flag);
int is_long_flag(char *str, int i);

//my_put_base
int print_base_special(char *flag, va_list func);
int put_base_before(char *str, char c, int *before);
int put_base_before_zero(int present, int len, int *before);
int my_put_base(char *base, char *nbr, char c, int *before);

//print_sign
int get_long(char *flag);
int print_before_sign(char *str, char *flag, int i, char sign);
int sign_convert_base(char *str, char flag);
int print_after_sign(char *str, char *flag, int i, char sign);
int print_sign(char *flag, va_list func, char sign);

//print_zero
int put_nbr_zero(va_list func, int *before, char  flag);
int put_nbr_zero_long(va_list func, int *before, char flag);
int put_nbr_zero_long_long(va_list func, int *before, char flag);
int print_zero(char *flag, va_list func, int i);

//print_long
int my_put_long_long(long long nbr, int *before);
int choose_long(char c, va_list func, int *before, int long_value);
int print_long(char *flag, va_list func);

//easy_flag
int end_flag(char c);
int end_flag_base(char c);
int end_flag_sign(char c);

//my_itoa_long_long
int find_nbr_len_long_long(long long nbr);
char *my_itoa_long_long(long long nbr);

//make_flag
char *make_flag(char *str, int i);

//my_atoi_long_long
long long int my_atoi_long_long(char *nbr);

//my_put_ptr
int my_put_ptr(long long int nbr);

//lib
int my_put_error(char const *str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
int my_putchar(char c);
int my_putstr(char const * str);
char *my_revstr(char *str);
int my_show_word_array(char * const *tab);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char **my_str_to_word_array(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
int my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_printf(char *str, ...);
int my_putstr_special(char *str);
char *my_itoa(int nbr);
char *my_long_itoa(long nbr);
int my_put_long(long nbr, int *before);
char *my_ftoa(double nbr, int precision);
int my_put_float(double nbr, int precision, int before);
char *my_utoa(unsigned int nbr);
int my_put_unsigned(unsigned int nbr);
char *my_long_utoa(unsigned long nbr);
char *my_long_long_utoa(unsigned long long nbr);
float my_char_to_float(char *str);

//sous lib
int count_minus(char const *str);
int is_num(char c);
int check_max_verif(char const *str, int min);
int check_max(char const *str, int minus);
int *update(int *array, int destination, int max, int size);
int find_len(char *str, int save);
char *my_clean_str(char const *str);
int is_alpha_num(char c);
char **empty(void);
int search(char *str, char const *to_find, int i);
int is_flag(char c);
int printf_error(char *str);
int choose_function(char c, va_list func);
int make_special_char(int c);
int find_nbr_len(int nbr);
int find_nbr_len_long(long nbr);
int choose_base(char c, va_list func, int opt, int *before);
int shoose_function(char c, va_list func);
int long_function(char *str, int i, va_list func);
int find_nbr_len_float(double nbr);
char *build_float(double nbr, char *result, int precision, int len);
int find_nbr_len_unsigned(unsigned int nbr);
int find_nbr_len_unsigned_long(unsigned long nbr);
int find_nbr_len_unsigned_long_long(unsigned long long nbr);

#endif /* MY */
