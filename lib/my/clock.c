/*
** EPITECH PROJECT, 2024
** duck hunter
** File description:
** quack
*/

#include "../../include/my.h"
#include <time.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <stdio.h>
#include "../../include/archi.h"

int clock_timer(archi_t *game)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(game->settings->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        sfClock_restart(game->settings->clock);
        return 1;
    }
    return 0;
}
