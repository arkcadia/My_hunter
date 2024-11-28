/*
** EPITECH PROJECT, 2024
** .h file for duck hunter
** File description:
** .h
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <stdio.h>
    #include "archi.h"
    #define ERROR_EXIT 84
void free_memory(archi_t *game);
void main_game(archi_t *game);
void redirect(archi_t *game);
int clock_timer(archi_t *game);
#endif /*MY_H_*/
