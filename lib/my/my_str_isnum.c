/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** task
*/

int my_str_isnum(char const *str)
{
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9')
            *str++;
        else
            return (0);
    }
    return (1);
}