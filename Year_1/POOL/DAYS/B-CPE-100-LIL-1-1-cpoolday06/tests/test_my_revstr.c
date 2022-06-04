#include  <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_strncpy , copy_string_in_empty_array)
{
    char  my_dest [6] = {0};
    char  dest [6] = {0};
    my_strncpy(my_dest , "Hello", 6);
    strncpy(dest , "Hello", 6);
    cr_assert_str_eq(my_dest , dest);
}