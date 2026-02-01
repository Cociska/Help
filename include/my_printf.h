/*
** EPITECH PROJECT, 2025
** my_printf.h
** File description:
** including
*/

#ifndef MY_PRINTF_
    #define MY_PRINTF_

typedef struct ieee754_double {
    unsigned long long nb_bits;
    int sign_bit;
    int exponent_bits;
    unsigned long long mantisse_bits;
    char *hex_base;
    int hex_shift;
    int hex_bits;
    char power_letter;
    char *hexa_indicator;
} ieee754_t;

int my_put_float(double nb, int prec, int cap);
int my_put_hex(int nb, int cap);
int my_put_nbr_uint(unsigned int nb);
int my_put_oct(int nb);
int my_printf(const char *format, ...);
int my_put_pointer(unsigned long nb);
int my_isinf(double nb);
int my_isnan(double nb);
int my_put_float_sci(double nb, int cap);
int my_put_ieee(double nb, int cap);
int my_put_bin(int nb, int cap, int alt);

#endif /* MY_PRINTF_ */
