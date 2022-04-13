/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

static void display_map(game_t *game)
{
    int longest_line = recup_longest_line(game);

    clear();
    for (int tmp = 0; game->new_maps[tmp]; tmp++) {
        mvprintw((LINES / 2) - ((longest_line / 2) - tmp),
        (COLS / 2) - (longest_line / 2), game->new_maps[tmp]);
    }
    refresh();
}

static int check_mouv_player(game_t *game, int action)
{
    (action == KEY_DOWN) ? mouv_down(game) : 0;
    (action == KEY_UP) ? mouv_up(game) : 0;
    (action == KEY_LEFT) ? mouv_left(game) : 0;
    (action == KEY_RIGHT) ? mouv_right(game) : 0;
    if (check_win(game) == 1) {
        display_map(game);
        return 1;
    }
    if (check_lose(game) == 2) {
        display_map(game);
        return 2;
    }
    return 0;
}

static int game_action(game_t *game)
{
    int action = 0;
    int result = 0;

    display_map(game);
    action = getch();
    if (action == ' ') {
        reset_game(game);
        return 0;
    }
    result = check_mouv_player(game, action);
    return result;
}

static int game_loop(game_t *game)
{
    int result = 0;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    while (1) {
        result = game_action(game);
        if (result == 1) {
            endwin();
            return 0;
        }
        if (result == 2) {
            endwin();
            return 1;
        }
    }
    return 0;
}

int start_game(char *av)
{
    game_t game = init_struct();

    if (game_initialization(&game, av) == -1) {
        return -1;
    }
    if (game_loop(&game) == 1) {
        free_game(game);
        return 1;
    }
    return 0;
}