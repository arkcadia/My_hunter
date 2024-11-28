/*
** EPITECH PROJECT, 2024
** duck hunter
** File description:
** quack
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <stdio.h>
#include "../../include/archi.h"

static void set_position(archi_t *game, int sprite)
{
    game->skin[4].pos.y = rand() % 900;
    sfSprite_setPosition(game->skin[sprite].sprite, game->skin[4].pos);
}

static void event(archi_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->settings->window);
    sfFloatRect coord_rect_1 = sfSprite_getGlobalBounds(game->skin[4].sprite);
    sfFloatRect coord_rect_2 = sfSprite_getGlobalBounds(game->skin[5].sprite);

    while (sfRenderWindow_pollEvent(game->settings->window,
        &(game->settings->event))) {
        if (game->settings->window == sfEvtClosed)
            sfRenderWindow_close(game->settings->window);
        if (sfFloatRect_contains(&coord_rect_1, mouse.x, mouse.y) &&
            game->settings->event.type == sfEvtMouseButtonPressed &&
            game->settings->event.mouseButton.button == sfMouseLeft)
            set_position(game, 4);
        if (sfFloatRect_contains(&coord_rect_2, mouse.x, mouse.y) &&
            game->settings->event.type == sfEvtMouseButtonPressed &&
            game->settings->event.mouseButton.button == sfMouseLeft)
            set_position(game, 5);
    }
}

void generate_random(archi_t *game, int timer, int speed)
{
    game->skin[4].move.x = (rand() % 13 - 13) / 10 - speed;
    game->skin[4].move.y = 0;
    if (timer == 99)
        game->skin[4].move.y = rand() % 40 - 20;
}

void reset_pos(archi_t *game)
{
    if (sfSprite_getPosition(game->skin[4].sprite).x == 20) {
        set_position(game, 4);
        game->skin[4].life += -1;
    }
    if (sfSprite_getPosition(game->skin[5].sprite).x == 20) {
        set_position(game, 5);
        game->skin[4].life += -1;
    }
    if (game->skin[4].life == 0)
        sfRenderWindow_close(game->settings->window);
}

void move_sprite(archi_t *game, int timer, int speed)
{
    generate_random(game, timer, speed);
    sfSprite_move(game->skin[4].sprite, game->skin[4].move);
    if (sfSprite_getPosition(game->skin[4].sprite).y <= 20) {
        game->skin[4].move.y = 20;
        sfSprite_move(game->skin[4].sprite, game->skin[4].move);
    }
    if (sfSprite_getPosition(game->skin[4].sprite).y >= 1050) {
        game->skin[4].move.y = -20;
        sfSprite_move(game->skin[4].sprite, game->skin[4].move);
    }
    generate_random(game, timer, speed);
    sfSprite_move(game->skin[5].sprite, game->skin[4].move);
    if (sfSprite_getPosition(game->skin[5].sprite).y <= 20) {
        game->skin[4].move.y = 20;
        sfSprite_move(game->skin[5].sprite, game->skin[4].move);
    }
    if (sfSprite_getPosition(game->skin[5].sprite).y >= 1050) {
        game->skin[4].move.y = -20;
        sfSprite_move(game->skin[5].sprite, game->skin[4].move);
    }
}

void draw_da_sprite(archi_t *game, int timer, int speed)
{
        sfRenderWindow_clear(game->settings->window, sfWhite);
        sfRenderWindow_drawSprite(game->settings->window,
                                game->skin[3].sprite, NULL);
        sfRenderWindow_drawSprite(game->settings->window,
                                game->skin[4].sprite, NULL);
        sfRenderWindow_drawSprite(game->settings->window,
                                game->skin[5].sprite, NULL);
        move_sprite(game, timer, speed);
        reset_pos(game);
        sfRenderWindow_display(game->settings->window);
}

void main_game(archi_t *game)
{
    int timer = 0;
    int speed = 0;

    game->skin[4].life = 3;
    set_position(game, 4);
    set_position(game, 5);
    while (sfRenderWindow_isOpen(game->settings->window)) {
        event(game);
        timer += 1;
        if (timer == 100) {
            speed += 0.1;
            timer = 0;
        }
    draw_da_sprite(game, timer, speed);
    }
}
