/*
** EPITECH PROJECT, 2025
** my_sudo_80
** File description:
** main
*/

#include "../include/my_sudo.h"

static void print_not_allowed(const char *user)
{
    write(2, user, strlen(user));
    write(2, " is not in the my_sudoers file.\n", 32);
}

static int load_current_user(char *name, uid_t *uid, gid_t *gid)
{
    *uid = getuid();
    if (find_user_by_uid(*uid, name, 256) != 0)
        return 84;
    if (find_user_by_name(name, uid, gid) != 0)
        return 84;
    return 0;
}

static int resolve_target(const options_t *opt, uid_t *uid, gid_t *gid)
{
    *uid = 0;
    *gid = 0;
    if (opt->user) {
        if (find_user_by_name(opt->user, uid, gid) != 0)
            return 84;
    }
    if (opt->group) {
        if (find_group_by_name(opt->group, gid) != 0)
            return 84;
    }
    return 0;
}

static int run_command(parsed_t *p)
{
    uid_t uid = 0;
    gid_t gid = 0;

    if (resolve_target(&p->options, &uid, &gid) != 0)
        return 84;
    if (setgid(gid) != 0 || setuid(uid) != 0)
        return 84;
    execvp(p->command[0], p->command);
    return 84;
}

static int auth_current_user(void)
{
    char username[256];

    if (getuid() == 0)
        return 0;
    if (find_user_by_uid(getuid(), username, sizeof(username)) != 0)
        return 84;
    return auth_user(username);
}

static int check_policy(void)
{
    char username[256];
    uid_t uid = 0;
    gid_t gid = 0;
    int allowed = 0;

    if (load_current_user(username, &uid, &gid) != 0)
        return 84;
    if (uid == 0)
        return 0;
    allowed = is_user_allowed(username, uid, gid);
    if (allowed == 84)
        return 84;
    if (allowed != 0)
        print_not_allowed(username);
    return allowed;
}

static int run_my_sudo(parsed_t *p)
{
    if (auth_current_user() != 0)
        return 84;
    if (check_policy() != 0)
        return 84;
    return run_command(p);
}

int main(int argc, char **argv)
{
    parsed_t p = parsing(argc, argv);

    if (p.options.h_flag) {
        print_help(1);
        return 0;
    }
    if (p.options.invalid || !p.command) {
        print_help(2);
        return 84;
    }
    return run_my_sudo(&p);
}
