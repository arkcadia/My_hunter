/*
** EPITECH PROJECT, 2024
** duck hunter
** File description:
** quack
*/

#include <stdlib.h>
#include "../../include/my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <stdio.h>
#include "../../include/archi.h"

void free_window(archi_t *game)
{
    sfRenderWindow_destroy(game->settings->window);
    sfClock_destroy(game->settings->clock);
    free(game->settings);
}

void free_texture(archi_t *game)
{
    for (int i = 0; i != 7; i++) {
        sfSprite_destroy(game->skin[i].sprite);
        if (i == 5)
            continue;
        sfTexture_destroy(game->skin[i].texture);
    }
}

void free_memory(archi_t *game)
{
    free_window(game);
    free_texture(game);
}
