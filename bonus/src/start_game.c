/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"

static void display_map(game_t *game, int mode_game)
{
    int longest_line = recup_longest_line(game);

    clear();
    if (mode_game == 2) {
        mvprintw(1, 1, "nbr mov= %d", game->compt_mov);
    }
    for (int tmp = 0; game->new_maps[tmp]; tmp++) {
        mvprintw((LINES / 2) - ((longest_line / 2) - tmp),
        (COLS / 2) - (longest_line / 2), game->new_maps[tmp]);
    }
    refresh();
}

int display_win(game_t *game)
{
    int choose = 0;

    clear();
    while (1) {
        mvprintw(LINES / 2 - 1, COLS / 2 - 5, "You win !\n");
        mvprintw(LINES / 2, COLS / 2 - 5, "Restart ? Y/n\n");
        choose = getch();
        if (choose == 'n') {
            endwin();
            sfMusic_destroy(game->son);
            return 1;
        } else if (choose == 'y') {
            reset_game(game);
            return 0;
        }
    }
}

int display_loose(game_t *game)
{
    int choose = 0;

    clear();
    while (1) {
        mvprintw(LINES / 2 - 1, COLS / 2 - 5, "You loose !\n");
        mvprintw(LINES / 2, COLS / 2 - 5, "Restart ? Y/n\n");
        choose = getch();
        if (choose == 'n') {
            endwin();
            sfMusic_destroy(game->son);
            return 1;
        } else if (choose == 'y') {
            reset_game(game);
            return 0;
        }
    }
}
static int check_mouv_player(game_t *game, int action, int mode_game)
{
    (action == KEY_DOWN) ? mouv_down(game) : 0;
    (action == KEY_UP) ? mouv_up(game) : 0;
    (action == KEY_LEFT) ? mouv_left(game) : 0;
    (action == KEY_RIGHT) ? mouv_right(game) : 0;
    if (check_win(game) == 1) {
        if (display_win(game) == 0) {
            return 0;
        }
        return 1;
    }
    if (check_lose(game) == 2) {
        if (display_loose(game) == 0) {
            return 0;
        }
        return 2;
    }
    return 0;
}

static int check_mouv_player_multi(game_t *game, int action)
{
    (action == KEY_DOWN) ? mouv_down(game) : 0;
    (action == KEY_UP) ? mouv_up(game) : 0;
    (action == KEY_LEFT) ? mouv_left(game) : 0;
    (action == KEY_RIGHT) ? mouv_right(game) : 0;
    (action == 's') ? mouv_down_b(game) : 0;
    (action == 'z') ? mouv_up_b(game) : 0;
    (action == 'q') ? mouv_left_b(game) : 0;
    (action == 'd') ? mouv_right_b(game) : 0;
    if (check_win(game) == 1) {
        if (display_win(game) == 0) {
            return 0;
        }
        return 1;
    }
    if (check_lose(game) == 2) {
        if (display_loose(game) == 0) {
            return 0;
        }
        return 2;
    }
    return 0;
}

static int game_action(game_t *game, int mode_game)
{
    int action = 0;
    int result = 0;

    display_map(game, mode_game);
    action = getch();
    if (action == ' ') {
        reset_game(game);
        return 0;
    }
    switch (mode_game)
    {
        case (0):
            result = check_mouv_player_multi(game, action);
            break;
        case (1):
            result = check_mouv_player_inverted(game, action, mode_game);
            break;
        case (2):
            result = check_mouv_player(game, action, mode_game);
            break;
        case (3):
            result = check_mouv_player(game, action, mode_game);
            break;
        case (4):
            result = check_mouv_player(game, action, mode_game);
            break;
    }
    return result;
}

static int game_loop(game_t *game, int mode_game)
{
    int result = 0;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    while(1) {
        result = game_action(game, mode_game);
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

int start_game(mode_game_t *opt_mode)
{
    game_t game = init_struct();

    if (game_initialization(&game, opt_mode) == -1) {
        return -1;
    }
    if (game_loop(&game, opt_mode->mode_game) == 1) {
        free_game(game);
        return 1;
    }
    return 0;
}