/*
** EPITECH PROJECT, 2021
** my_strdup_tests.c
** File description:
** se
*/

#include <criterion/criterion.h>

char *my_strdup(char const *src);

Test(my_strdup_fct, simple_test)
{
    char *str = "Dan is big looser";
    cr_assert_str_eq(my_strdup("hello world\n"), "hello world\n");
    cr_assert_str_eq(my_strdup(str), str);
}