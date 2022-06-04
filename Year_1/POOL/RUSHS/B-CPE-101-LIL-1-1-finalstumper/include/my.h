/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

void my_putchar(char);
char my_getnbr(char const *str);
char my_getsigne(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char **my_str_to_word_array(char  const *str);
char *infin_add_less(char *av1, char *av2, char **av);
char *infin_add(char *av1, char *av2, char **av);
char *infin_add_m_l(char *av1, char *av2, char **av, int signe);
char *my_revstr(char *str);
int my_strlen(char const *str);
int cti (char c);
void infin_direction(char *av1, char *av2, char **av);
int find_signe(char *av);
char *str_symbole(char *av);
int  eval_expr(char  const *str);
int size1(char *buff, int i, int j);
int size2(char *buff, int i, int j);
void print(int k, int i, int j);
int  my_strcmp(char  const *s1 , char  const *s2);