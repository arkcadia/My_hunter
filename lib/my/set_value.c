/*
** EPITECH PROJECT, 2024
** duck hunter
** File description:
** quack
*/


#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include "../../include/my.h"
#include "../../include/archi.h"

int create_window_menu(archi_t *game)
{
    game->settings = malloc(sizeof(setting_t));
    if (!game->settings)
        return ERROR_EXIT;
    game->settings->mode.bitsPerPixel = 32;
    game->settings->mode.height = 1080;
    game->settings->mode.width = 1920;
    game->settings->window = sfRenderWindow_create(game->settings->mode
        , "My hunter", sfResize | sfFullscreen | sfClose, NULL);
    game->settings->clock = sfClock_create();
    return 0;
}

void set_sprite_menu(archi_t *game)
{
    game->skin[2].pos.y = 500;
    sfSprite_setTexture(game->skin[2].sprite,
                        game->skin[2].texture, sfTrue);
    sfSprite_setPosition(game->skin[2].sprite,
                        game->skin[2].pos);
    sfSprite_setScale(game->skin[2].sprite,
                        game->skin[1].scale);
}

int create_sprite_menu(archi_t *game)
{
    game->skin = malloc(sizeof(texture_t) * 7);
    if (!game->skin)
        return ERROR_EXIT;
    game->skin[0].texture = sfTexture_createFromFile("cont/menu.jpg", NULL);
    game->skin[0].sprite = sfSprite_create();
    sfSprite_setTexture(game->skin[0].sprite, game->skin[0].texture, sfTrue);
    game->skin[1].texture = sfTexture_createFromFile("cont/play.png", NULL);
    game->skin[1].sprite = sfSprite_create();
    game->skin[1].scale.x = 0.3;
    game->skin[1].scale.y = 0.3;
    game->skin[1].pos.x = 830;
    game->skin[1].pos.y = 300;
    sfSprite_setTexture(game->skin[1].sprite, game->skin[1].texture, sfTrue);
    sfSprite_setPosition(game->skin[1].sprite, game->skin[1].pos);
    sfSprite_setScale(game->skin[1].sprite, game->skin[1].scale);
    game->skin[2].texture =
        sfTexture_createFromFile("cont/exit.png", NULL);
    game->skin[2].sprite = sfSprite_create();
    game->skin[2].pos.x = 830;
    set_sprite_menu(game);
}

void create_sprite_game(archi_t *game)
{
    game->skin[3].texture = sfTexture_createFromFile("cont/tyra2.jpg", NULL);
    game->skin[3].sprite = sfSprite_create();
    game->skin[3].scale.x = 1;
    game->skin[3].scale.y = 2;
    sfSprite_setTexture(game->skin[3].sprite, game->skin[3].texture, sfTrue);
    sfSprite_setScale(game->skin[3].sprite, game->skin[3].scale);
    game->skin[4].texture = sfTexture_createFromFile("cont/tyra.png", NULL);
    game->skin[4].sprite = sfSprite_create();
    game->skin[4].scale.x = 0.35;
    game->skin[4].scale.y = 0.35;
    game->skin[4].pos.x = 1600;
    game->skin[4].pos.y = 500;
    game->skin[4].move.x = 0;
    game->skin[4].move.y = 0;
    sfSprite_setTexture(game->skin[4].sprite, game->skin[4].texture, sfTrue);
    sfSprite_setPosition(game->skin[4].sprite, game->skin[4].pos);
    sfSprite_setScale(game->skin[4].sprite, game->skin[4].scale);
    game->skin[5].sprite = sfSprite_create();
    sfSprite_setTexture(game->skin[5].sprite, game->skin[4].texture, sfTrue);
    sfSprite_setScale(game->skin[5].sprite, game->skin[4].scale);
}

static void create_animation(archi_t *game)
{
    game->skin[6].texture =
        sfTexture_createFromFile("cont/animation/fire2.png", NULL);
    game->skin[6].sprite = sfSprite_create();
    game->skin[6].pos.x = 840;
    game->skin[6].pos.y = -200;
    game->skin[6].scale.x = 2;
    game->skin[6].scale.y = 2;
    game->skin[6].hitbox = (sfIntRect){0, 0, 74, 372};
    sfSprite_setTexture(game->skin[6].sprite, game->skin[6].texture, sfTrue);
    sfSprite_setScale(game->skin[6].sprite, game->skin[6].scale);
    sfSprite_setPosition(game->skin[6].sprite, game->skin[6].pos);
    sfSprite_setTextureRect(game->skin[6].sprite, game->skin[6].hitbox);
}

void redirect(archi_t *game)
{
    create_window_menu(game);
    create_sprite_menu(game);
    create_animation(game);
    create_sprite_game(game);
}
