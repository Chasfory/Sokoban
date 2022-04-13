/*
** EPITECH PROJECT, 2021
** strncmp
** File description:
** string compute
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i < n)
        i++;
    return (s1[i] - s2[i]);
}