/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** task
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i]; i++) {
        if (s2[i + 1] == '\0' || s1[i + 1] == '\0') {
            return 0;
        }
    }
    return (s1[i] - s2[i]);
}