/*
** EPITECH PROJECT, 2021
** my_str_isalpha.c
** File description:
** task
*/

int my_str_isalpha(char const *str)
{
    while (*str != '\0') {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
            *str++;
        else
            return (0);
    }
    return (1);
}
