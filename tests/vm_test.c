/*
** EPITECH PROJECT, 2021
** vm test
** File description:
** .
*/

#include <criterion/criterion.h>
#include "corewar.h"

Test(my_check_dump_string_fct, simple_test)
{
    cr_assert_eq(check_dump_string("6546"), 0);
    cr_assert_eq(check_dump_string("aezr5454az"), 1);
    cr_assert_eq(check_dump_string("6878797987987978"), 1);
    cr_assert_eq(check_dump_string("687879zefzef7987987978"), 1);
    cr_assert_eq(check_dump_string("-1"), 1);
    cr_assert_eq(check_dump_string("0"), 1);
    cr_assert_eq(check_dump_string("565****1"), 1);
    cr_assert_eq(check_dump_string("\n64556456\t"), 1);
}

Test(my_check_int_fct, simple_test)
{
    cr_assert_eq(check_int("6546"), 0);
    cr_assert_eq(check_int("54"), 0);
    cr_assert_eq(check_int("6546544"), 0);
    cr_assert_eq(check_int("54***65455898"), 1);
    cr_assert_eq(check_int("6878797987987978"), 1);
    cr_assert_eq(check_int("687879zefzef7987987978"), 1);
    cr_assert_eq(check_int("217483647"), 0);
    cr_assert_eq(check_int("555"), 0);
    cr_assert_eq(check_int("\t5465\n"), 0);
}

Test(my_check_extension_fct, simple_test)
{
    cr_assert_eq(check_extension("chammpio.cor"), 0);
    cr_assert_eq(check_extension("chammpio.co"), 0);
    cr_assert_eq(check_extension("chammpiocor"), 0);
    cr_assert_eq(check_extension("chammpio.s"), 0);
    cr_assert_eq(check_extension("c.cor"), 0);
    cr_assert_eq(check_extension("chazezz.s"), 0);
    cr_assert_eq(check_extension("cham54r"), 0);
    cr_assert_eq(check_extension("chammpi6454646o.s"), 0);
    cr_assert_eq(check_extension("c.czezezor"), 0);
}