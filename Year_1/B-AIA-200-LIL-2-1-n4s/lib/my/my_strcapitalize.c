/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday06-simon.auduberteau
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && (str[i] >= 'a' && str[i] <= 'z') || str[i - 1] == ' ' &&
            (str[i] >= 'a' && str[i] <= 'z') || str[i - 1] == '-' &&
            (str[i] >= 'a' && str[i] <= 'z') || str[i - 1] == '+' &&
            (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 'a' - 'A';
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }
    return (str);
}