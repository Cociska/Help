/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** my_radar
*/


#ifndef MY_RADAR_MY_RADAR_H
    #define MY_RADAR_MY_RADAR_H

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/Sound.h>
    #include <unistd.h>
    #include <stdlib.h>

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
} game_t;

int my_strlen(const char *s);
int my_strcmp(char const *s1, char const *s2);

void help(void);

int launch_simulation(void);

#endif //MY_RADAR_MY_RADAR_H
