/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** window management
*/

#include "../includes/my_radar.h"

static void poll_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(game->window);
        }
    }
}

static void plane_mouvement(game_t *game)
{
    sfVector2f pos;
    sfTime time_elapsed = sfClock_getElapsedTime(game->clock);
    float seconds = sfTime_asSeconds(time_elapsed);

    if (seconds > 0.01) {
        pos = sfSprite_getPosition(game->plane_sprite);
        pos.x += 100.0 * seconds;
        sfSprite_setPosition(game->plane_sprite, pos);
        sfClock_restart(game->clock);
    }
}

static void load_resources(game_t *game)
{
    game->background_texture =
        sfTexture_createFromFile("assets/background.png", NULL);
    game->background_sprite = sfSprite_create();
    game->plane_texture = sfTexture_createFromFile("assets/plane.png", NULL);
    game->plane_sprite = sfSprite_create();
    game->clock = sfClock_create();
    sfSprite_setTexture(game->background_sprite,
        game->background_texture, sfTrue);
    sfSprite_setPosition(game->background_sprite, (sfVector2f){0.0, 0.0});
    sfSprite_setTexture(game->plane_sprite, game->plane_texture, sfTrue);
    sfSprite_setPosition(game->plane_sprite, (sfVector2f){500, 500});
    sfSprite_setScale(game->plane_sprite, (sfVector2f){0.1, 0.1});
}

static void destroy_resources(game_t *game)
{
    sfSprite_destroy(game->plane_sprite);
    sfTexture_destroy(game->plane_texture);
    sfRenderWindow_destroy(game->window);
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        poll_events(game);
        plane_mouvement(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->background_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, game->plane_sprite, NULL);
        sfRenderWindow_display(game->window);
    }
}

int open_window(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};

    game->window = sfRenderWindow_create(mode, "My Radar",
        sfResize | sfClose, NULL);
    if (!game->window)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    load_resources(game);
    game_loop(game);
    destroy_resources(game);
    return 0;
}
