/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** window
*/

#include "../includes/my_radar.h"

static void close_window(game_t *game)
{
    sfRenderWindow_close(game->window);
}

static void analyse_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            close_window(game);
        }
        if (game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyEscape) {
            close_window(game);
        }
    }
}

static sfRenderWindow *create_render_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "My Radar", sfResize | sfClose, NULL);
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

int launch_simulation(void)
{
    game_t game;

    game.window = create_render_window();
    if (!game.window)
        return 84;
    while (sfRenderWindow_isOpen(game.window)) {
        analyse_events(&game);
        sfRenderWindow_clear(game.window, sfBlack);
        sfRenderWindow_display(game.window);
    }
    sfRenderWindow_destroy(game.window);
    return 0;
}
