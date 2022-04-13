/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban.c
*/

#include "sokoban.h"
#include "struct_choose_mode.h"
#include "struct_play.h"
#include "struct_help.h"

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

int display_title(void)
{
    attron(COLOR_PAIR(2));
    mvprintw((LINES / 2) - 8, (COLS / 2) - 15, "__  __       __  __  __         ");
    attron(COLOR_PAIR(3));
    mvprintw((LINES / 2) - 7, (COLS / 2) - 15, "  | | | | /  | | | | | | |\\   |");
    attron(COLOR_PAIR(2));
    mvprintw((LINES / 2) - 6, (COLS / 2) - 15, "--  | | |/   | | --- --- | \\  |");
    attron(COLOR_PAIR(3));
    mvprintw((LINES / 2) - 5, (COLS / 2) - 15, "|   | | |\\  | | | | | | |  \\ |");
    attron(COLOR_PAIR(3));
    mvprintw((LINES / 2) - 4, (COLS / 2) - 15, " -- --- | \\ --- --- | | |   \\|");
    return 0;
}

int display_help_game(char const **display)
{
    int choose = 0;

    clear();
    while (1) {
        mvprintw(LINES / 2 - 2,
	       COLS / 2 - 17, display[0]);
        mvprintw(LINES / 2 - 1,
	       COLS / 2 - 17, display[1]);
        mvprintw(LINES / 2 + 0,
	       COLS / 2 - 17, display[2]);
        mvprintw(LINES / 2 + 1,
	       COLS / 2 - 17, display[3]);
        mvprintw(LINES / 2 + 2,
	       COLS / 2 - 17, display[4]);
        refresh();
        choose = getch();
        if (choose == 'T' || choose == 't') {
            clear();
            refresh();
            return 0;
        }
    }
}

void display_bis(int opt_mode)
{
    switch (opt_mode)
    {
        case (0):
            display_help_game(display_help_multi);
            break;
        case (1):
            display_help_game(display_help_inverted);
            break;
        case (2):
            display_help_game(display_help_least_move);
            break;
        case (3):
            display_help_game(display_help_tetris);
            break;
        case (4):
            display_help_game(display_help_futur);
            break;
    }
}

int display_help_mode(char const **display)
{
    int choose = 0;

    clear();
    while (1) {
        attron(COLOR_PAIR(6));
        mvprintw(LINES / 2 - 2,
	       COLS / 2 - 17, display[0]);
        mvprintw(LINES / 2 - 1,
	       COLS / 2 - 17, display[1]);
        mvprintw(LINES / 2 + 0,
	       COLS / 2 - 17, display[2]);
        mvprintw(LINES / 2 + 1,
	       COLS / 2 - 17, display[3]);
        mvprintw(LINES / 2 + 2,
	       COLS / 2 - 17, display[4]);
        refresh();
        choose = getch();
        if (choose == 'x' || choose == 'X') {
            clear();
            refresh();
            return 0;
        }
    }
}

int display_choose_map(int post_select, mode_game_t *opt_game, char const **map)
{
    char *def_map = NULL;

    switch (post_select)
    {
        case (0):
            def_map = my_strcat("maps/", map[post_select]);
            opt_game->maps_mode = malloc(sizeof(char) * my_strlen(def_map) + 1);
            opt_game->maps_mode = my_strcpy(opt_game->maps_mode, def_map);
            return 1;
        case (1):
            def_map = my_strcat("maps/", map[post_select]);
            opt_game->maps_mode = malloc(sizeof(char) * my_strlen(def_map) + 1);
            opt_game->maps_mode = my_strcpy(opt_game->maps_mode, def_map);
            return 1;
        case (2):
            break;
    }
    return 0;
}

int display_mode(char const **map, mode_game_t *opt_game)
{
    WINDOW *window;
    int post_select = 0;
    int choose = 0;

    clear();
    window = newwin(30, 30, 20, 80);
    keypad(window, TRUE);
    box(window, 0, 0);
    while (1)
    {
        for (int i = 0; i < 3; i++) {
            if (i == post_select)
                wattron(window, A_REVERSE);
            mvwprintw(window, i + 1, 1, map[i]);
            wattroff(window, A_REVERSE);
        }
        choose = wgetch(window);
        switch(choose)
        {
            case KEY_DOWN:
                post_select++;
                if (post_select == 3) {
                    post_select = 0;
                }
                break;
            case KEY_UP:
                post_select--;
                if(post_select == -1) {
                    post_select = 2;
                }
                break;
            case 'x':
                endwin();
                return 1;
            case 'X':
                endwin();
                return 1;
            case 't':
                if (display_choose_map(post_select, opt_game, map) == 1) {
                    display_bis(opt_game->mode_game);
                    endwin();
                    return 1;
                }
                endwin();
                return 0;
        }
    }
    refresh();
    wrefresh(window);
    return 0;
}

int display_mode_map(mode_game_t *opt_game)
{
    int exit_game = 0;

    switch(opt_game->mode_game)
    {
        case (0):
            exit_game = display_mode(map_multiplayer, opt_game);
            break;
        case (1):
            exit_game = display_mode(map_inverted, opt_game);
            break;
        case (2):
            exit_game = display_mode(map_least_mov, opt_game);
            break;
        case (3):
            exit_game = display_mode(map_tetris, opt_game);
            break;
        case (4):
            exit_game = display_mode(map_futur, opt_game);
            break;
    }
    return exit_game;
}

int choose_game(mode_game_t *opt_game)
{
    WINDOW *window;
    int choose = 0;
    int exit_game = 0;

    initscr();
    noecho();
    window = newwin(30, 30, 20, 80);
    keypad(window, TRUE);
    box(window, 0, 0);
    curs_set(0);
    while (1) {
        display_title();
        for (int i = 0; i < 5; i++) {
            if (i == opt_game->mode_game)
                wattron(window, A_REVERSE);
            mvwprintw(window, i + 1, 1, choose_mode[i]);
            wattroff(window, A_REVERSE);
        }
        choose = wgetch(window);
        switch(choose)
        {
            case KEY_DOWN:
                opt_game->mode_game += 1;
                if (opt_game->mode_game == 5) {
                    opt_game->mode_game = 0;
                }
                break;
            case KEY_UP:
                opt_game->mode_game -= 1;
                if(opt_game->mode_game == -1) {
                    opt_game->mode_game = 4;
                }
                break;
            case 'x':
                endwin();
                return 10;
            case 'X':
                endwin();
                return 10;
            case 'h':
                display_help_mode(display_help_the_game);
                window = newwin(30, 30, 20, 80);
                keypad(window, TRUE);
                box(window, 0, 0);
                break;
            case 'H':
                display_help_mode(display_help_the_game);
                window = newwin(30, 30, 20, 80);
                keypad(window, TRUE);
                box(window, 0, 0);
                break;
            case 't':
                exit_game = display_mode_map(opt_game);
                window = newwin(30, 30, 20, 80);
                keypad(window, TRUE);
                box(window, 0, 0);
                break;
        }
        if (exit_game == 1) {
            endwin();
            return 0;
        }
    }
    refresh();
    wrefresh(window);
}