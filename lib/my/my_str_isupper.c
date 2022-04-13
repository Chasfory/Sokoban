/*
** EPITECH PROJECT, 2021
** my_str_isupper.c
** File description:
** task
*/

int my_str_isupper(char const *str)
{
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z')
            *str++;
        else
            return (0);
    }
    return (1);
}