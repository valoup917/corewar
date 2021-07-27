/*
** EPITECH PROJECT, 2021
** my_printf_tests.c
** File description:
** my_printf_tests.c
*/

#include <criterion/criterion.h>

void my_putstr(char const *str);

Test(my_printf, exists)
{
    my_putstr("Hello, world!");
}
