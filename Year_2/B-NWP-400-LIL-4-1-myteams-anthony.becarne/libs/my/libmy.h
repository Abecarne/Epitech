/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** libmy
*/

#ifndef LIBMY_H_
    #define LIBMY_H_

char *remove_last_char(char *str);
char **get_files_dir(char *path);
char **str_tokenise(char *str);
int count_args_in_tab(char **tokens);

/**
** @brief Get a tab with a string parsed with double-quote
**
** @param str The string to tokenise
** @return [char**] The tab of strings
**/
char **str_tokenise_quoted(char *str);

char **str_tokenise_special(char *str);

char **fill_with_quoted(char **tokens);

/**
** @brief Matches **str** with **regex** until **n** characters
**
** @param str The string to compare
** @param regex The regex to match
** @param n The number of character to compare
**
** @return [int]
** @retval !0 If the regex matches
** @retval 84 If the regex is invalid
**/
int regex_match(char *str, char *regex, int n);

#endif /* !LIBMY_H_ */
