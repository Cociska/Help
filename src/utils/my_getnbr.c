/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    if (str[0] == '-' || str[0] == '+') {
        if (str[0] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
        return -1;
    for (; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        res = res * 10 + (str[i] - '0');
    }
    return res * sign;
}
