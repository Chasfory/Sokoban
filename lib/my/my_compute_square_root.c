/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** task05
*/

#include <unistd.h>

int my_compute_square_root(int nb)
{
    int a = 0;

    if (nb == 2 || nb <= 0) {
        return (0);
    }
    while (a * a < nb) {
        a++;
    }
    if (a * a != nb) {
        return (0);
    }
    else {
        return (a);
    }
}