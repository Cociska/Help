/*
** EPITECH PROJECT, 2025
** my_sudo_80
** File description:
** my_sudo
*/

#ifndef MY_SUDO_H
    #define MY_SUDO_H

    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>

typedef struct {
    int h_flag;
    int invalid;
    char *user;
    char *group;
} options_t;

typedef struct {
    options_t options;
    char **command;
} parsed_t;

void print_help(int fd);
parsed_t parsing(int argc, char **argv);
int auth_user(const char *username);
int read_hash(const char *username, char *out, size_t size);
int find_user_by_name(const char *name, uid_t *uid, gid_t *gid);
int find_user_by_uid(uid_t uid, char *name, size_t name_size);
int find_group_by_name(const char *name, gid_t *gid);
int is_user_in_group_name(const char *user, const char *group_name);
int is_user_in_group_gid(const char *user, gid_t group_gid);
int is_user_allowed(const char *user, uid_t uid, gid_t gid);

#endif
