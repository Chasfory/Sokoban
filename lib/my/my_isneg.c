/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** Task
*/

#include <unistd.h>

int my_putchar(char c);

int my_isneg(int n)
{
    if (n<0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}