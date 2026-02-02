/*
** EPITECH PROJECT, 2025
** my_sudo_80
** File description:
** parsing
*/

#include "../include/my_sudo.h"

static int take_value(char **dst, int argc, char **argv, int *i)
{
    if (*i + 1 >= argc)
        return 84;
    *i += 1;
    *dst = argv[*i];
    return 0;
}

static int parse_option(parsed_t *p, int argc, char **argv, int *i)
{
    char *arg = argv[*i];

    if (!strcmp(arg, "-h")) {
        p->options.h_flag = 1;
        return 1;
    }
    if (!strcmp(arg, "-u"))
        return (take_value(&p->options.user, argc, argv, i) == 0) ? 1 : -1;
    if (!strcmp(arg, "-g"))
        return (take_value(&p->options.group, argc, argv, i) == 0) ? 1 : -1;
    if (arg[0] == '-')
        return -1;
    return 0;
}

parsed_t parsing(int argc, char **argv)
{
    options_t o = {0, 0, NULL, NULL};
    parsed_t p = {o, NULL};
    int state = 0;

    for (int i = 1; i < argc; i++) {
        state = parse_option(&p, argc, argv, &i);
        if (state < 0) {
            p.options.invalid = 1;
            break;
        }
        if (state > 0)
            continue;
        p.command = &argv[i];
        break;
    }
    return p;
}
