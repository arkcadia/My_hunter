/*
** EPITECH PROJECT, 2024
** duck hunter
** File description:
** quack
*/
#include <unistd.h>
#include "../include/my.h"
#include <time.h>

void readme(void)
{
    write(1, "        Welcome on my game Tyranid_hunter\n\n"
    "        You are a space marine on dudy, your task"
    "is simple, shot those tyranids\n\n"
    "        But how you manage to do that ?, left click to shot on"
    "any tyranid model, to kill them in the name of the emperor\n\n"
    "        Yet brother, beware u only have 3 chance to kill"
    "them otherwise you will die, also beware they become faster\n"
    "                        The emperor protects \n", 409);
}

void click_menu(archi_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->settings->window);

    if (mouse.x >= 833 && mouse.x <= 1004
        && mouse.y >= 301 && mouse.y <= 456) {
        if (game->settings->event.type == sfEvtMouseButtonPressed &&
            game->settings->event.mouseButton.button == sfMouseLeft)
            main_game(game);
    }
    if (mouse.x >= 833 && mouse.x <= 986
        && mouse.y >= 450 && mouse.y <= 605) {
        if (game->settings->event.type == sfEvtMouseButtonPressed &&
            game->settings->event.mouseButton.button == sfMouseLeft)
            sfRenderWindow_close(game->settings->window);
    }
}

void animate_sprite(archi_t *game)
{
    if (clock_timer(game)) {
        if (game->skin[6].hitbox.left >= 295)
            game->skin[6].hitbox.left = 0;
        game->skin[6].hitbox.left += 74;
        sfSprite_setTextureRect(game->skin[6].sprite, game->skin[6].hitbox);
    }
}

static void manage_event(archi_t *game)
{
    while (sfRenderWindow_pollEvent(game->settings->window,
            &(game->settings->event))) {
        if (game->settings->event.type == sfEvtClosed)
            sfRenderWindow_close(game->settings->window);
        }
}

void main_window(archi_t *game)
{
    clock_timer(game);
    while (sfRenderWindow_isOpen(game->settings->window)) {
        manage_event(game);
        sfRenderWindow_drawSprite(game->settings->window,
                            game->skin[0].sprite, NULL);
        sfRenderWindow_drawSprite(game->settings->window,
                            game->skin[6].sprite, NULL);
        sfRenderWindow_drawSprite(game->settings->window,
                            game->skin[2].sprite, NULL);
        sfRenderWindow_drawSprite(game->settings->window,
                            game->skin[1].sprite, NULL);
    animate_sprite(game);
    sfRenderWindow_display(game->settings->window);
    click_menu(game);
    }
    free_memory(game);
}

int main(int nb_arg, __attribute__((unused)) char **argv)
{
    archi_t *game;

    if (nb_arg != 1) {
        readme();
        return 0;
    }
    srand(time(NULL));
    game = malloc(sizeof(archi_t));
    if (game == NULL)
        return ERROR_EXIT;
    redirect(game);
    main_window(game);
    return 0;
}
