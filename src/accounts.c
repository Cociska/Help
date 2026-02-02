/*
** EPITECH PROJECT, 2025
** my_sudo_80
** File description:
** accounts
*/

#include "../include/my_sudo.h"
#include <stdlib.h>

static int user_uid_gid_match(
    char *line, const char *name, uid_t *uid, gid_t *gid)
{
    char *save = NULL;
    char *login = strtok_r(line, ":", &save);
    char *x = strtok_r(NULL, ":", &save);
    char *uid_s = strtok_r(NULL, ":", &save);
    char *gid_s = strtok_r(NULL, ":", &save);

    (void)x;
    if (!login || !uid_s || !gid_s || strcmp(login, name) != 0)
        return 0;
    *uid = (uid_t)strtoul(uid_s, NULL, 10);
    *gid = (gid_t)strtoul(gid_s, NULL, 10);
    return 1;
}

int find_user_by_name(const char *name, uid_t *uid, gid_t *gid)
{
    FILE *f = fopen("/etc/passwd", "r");
    char line[4096];

    if (!f)
        return 84;
    while (fgets(line, sizeof(line), f))
        if (user_uid_gid_match(line, name, uid, gid)) {
            fclose(f);
            return 0;
        }
    fclose(f);
    return 84;
}

static int user_uid_match(char *line, uid_t uid, char *name, size_t name_size)
{
    char *save = NULL;
    char *login = strtok_r(line, ":", &save);
    char *x = strtok_r(NULL, ":", &save);
    char *uid_s = strtok_r(NULL, ":", &save);

    (void)x;
    if (!login || !uid_s || (uid_t)strtoul(uid_s, NULL, 10) != uid)
        return 0;
    strncpy(name, login, name_size - 1);
    name[name_size - 1] = '\0';
    return 1;
}

int find_user_by_uid(uid_t uid, char *name, size_t name_size)
{
    FILE *f = fopen("/etc/passwd", "r");
    char line[4096];

    if (!f)
        return 84;
    while (fgets(line, sizeof(line), f))
        if (user_uid_match(line, uid, name, name_size)) {
            fclose(f);
            return 0;
        }
    fclose(f);
    return 84;
}

static int group_gid_match(char *line, const char *name, gid_t *gid)
{
    char *save = NULL;
    char *group = strtok_r(line, ":", &save);
    char *x = strtok_r(NULL, ":", &save);
    char *gid_s = strtok_r(NULL, ":", &save);

    (void)x;
    if (!group || !gid_s || strcmp(group, name) != 0)
        return 0;
    *gid = (gid_t)strtoul(gid_s, NULL, 10);
    return 1;
}

int find_group_by_name(const char *name, gid_t *gid)
{
    FILE *f = fopen("/etc/group", "r");
    char line[4096];

    if (!f)
        return 84;
    while (fgets(line, sizeof(line), f))
        if (group_gid_match(line, name, gid)) {
            fclose(f);
            return 0;
        }
    fclose(f);
    return 84;
}

static int member_list_has_user(char *members, const char *user)
{
    char *save = NULL;
    char *member = NULL;

    if (!members || members[0] == '\0')
        return 0;
    member = strtok_r(members, ",\n", &save);
    while (member) {
        if (strcmp(member, user) == 0)
            return 1;
        member = strtok_r(NULL, ",\n", &save);
    }
    return 0;
}

static int match_group_membership(FILE *f, const char *user, gid_t group_gid)
{
    char line[4096];
    char *save = NULL;
    char *name = NULL;
    char *x = NULL;
    char *gid_s = NULL;
    char *members = NULL;

    while (fgets(line, sizeof(line), f)) {
        save = NULL;
        name = strtok_r(line, ":", &save);
        x = strtok_r(NULL, ":", &save);
        gid_s = strtok_r(NULL, ":", &save);
        members = strtok_r(NULL, ":", &save);
        (void)name;
        (void)x;
        if (!gid_s || (gid_t)strtoul(gid_s, NULL, 10) != group_gid)
            continue;
        return member_list_has_user(members, user);
    }
    return 0;
}

int is_user_in_group_gid(const char *user, gid_t group_gid)
{
    FILE *f = fopen("/etc/group", "r");
    int found = 0;

    if (!f)
        return 0;
    found = match_group_membership(f, user, group_gid);
    fclose(f);
    return found;
}

int is_user_in_group_name(const char *user, const char *group_name)
{
    gid_t group_gid = 0;
    gid_t user_gid = 0;
    uid_t user_uid = 0;

    if (find_group_by_name(group_name, &group_gid) != 0)
        return 0;
    if (find_user_by_name(user, &user_uid, &user_gid) != 0)
        return 0;
    if (user_gid == group_gid)
        return 1;
    return is_user_in_group_gid(user, group_gid);
}
