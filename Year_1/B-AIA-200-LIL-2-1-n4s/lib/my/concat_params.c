/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday08-simon.auduberteau
** File description:
** concat_params
*/

char *concat_params(int argc, char **argv)
{
    char *concat;
    int size_av = 0;
    int size_max = 0;
    int h = 0;

    for (int i = 0; i != argc; i++)
        size_max += my_strlen(argv[i]);
    concat = malloc(sizeof(char) * size_max + argc);
    for (int j = 0; j != argc; j++) {
        for (int a = 0; argv[j][a] != '\0'; a++) {
            concat[h] = argv[j][a];
            h++;
        }
        concat[h] = ' ';
        h++;
    }
    concat[h - 1] = '\0';
    return (concat);
}