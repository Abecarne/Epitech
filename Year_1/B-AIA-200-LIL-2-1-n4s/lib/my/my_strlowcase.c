/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday06-simon.auduberteau
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }
    return (str);
}