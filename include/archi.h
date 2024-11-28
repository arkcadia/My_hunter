/*
** EPITECH PROJECT, 2024
** .h file for duck hunter
** File description:
** .h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct setting_t {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
} setting_t;
typedef struct texture_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f size;
    sfVector2f move;
    sfIntRect hitbox;
    int life;
} texture_t;
typedef struct archi_t {
    setting_t *settings;
    texture_t *skin;
} archi_t;
#endif
