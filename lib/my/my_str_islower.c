/*
** EPITECH PROJECT, 2021
** my_str_is_lower.c
** File description:
** task
*/

int my_str_islower(char const *str)
{
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z')
            *str++;
        else
            return (0);
    }
    return (1);
}