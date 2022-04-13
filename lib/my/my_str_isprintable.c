/*
** EPITECH PROJECT, 2021
** my_str_istrin.c
** File description:
** task
*/

int my_str_isprintable(char const *str)
{
    while (*str != '\0') {
        if ((*str >= '\0' && *str < '!') || (*str == 127))
            *str++;
        else
            return (0);
    }
    return (1);
}