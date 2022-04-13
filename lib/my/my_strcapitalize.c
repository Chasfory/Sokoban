/*
** EPITECH PROJECT, 2021
** my_strcapitalize.c
** File description:
** task
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    for (int i = 1; str[i] != '\0'; i++)
        if ((str[i - 1] == ' ') && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] = str[i] - 32;
    return (str);
}