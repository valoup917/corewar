/*
** EPITECH PROJECT, 2021
** my_strlen_tests.c
** File description:
** se
*/

#include <criterion/criterion.h>

char *my_strlen(char *str);

Test(my_strlen_fct, simple_test)
{
    char *str = "Dan is big oooser";
    cr_assert_(my_strlen("Dan is big looser\n"));
    cr_assert_(my_strlen(str));
}
