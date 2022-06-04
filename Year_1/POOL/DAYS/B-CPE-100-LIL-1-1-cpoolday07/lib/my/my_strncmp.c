/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strncmp
*/

int  my_strncmp(char  const *s1 , char  const *s2 , int n)
{
    if (n > my_strlen(s1) || n < my_strlen(s2)) {
        return (0);
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        
    }
    return (0);
}