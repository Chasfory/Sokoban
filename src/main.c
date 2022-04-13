/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

static char const *USAGE = "USAGE\n\t./my_sokoban map\nDESCRIPTION"
    "\n\tmap file representing the warehouse map, containing '#' for walls,\n"
    "\t\t'P' for the player, 'X' for boxes and 'O' for storage locations.\n";

int main(int ac, char **av)
{
    int result = 0;

    if (ac != 2) {
        return 84;
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr(USAGE);
        return 0;
    }
    else if (error_map(av[1]) == -1) {
        return 84;
    }
    result = start_game(av[1]);
    if (result == 1) {
        return 1;
    } else if (result == -1) {
        return 84;
    }
    return 0;
}