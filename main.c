#include "include/my.h"
#include "include/my_printf.h"
#include <stddef.h>
#include <stdio.h>

int main(void);

static void test_my_put_float_sci(void)
{
    double nums[] = {0.0, -0.0, 1.0, -1.0, 12345.6789, -12345.6789,
                     0.0001234, -0.0001234, 987654321.0, -987654321.0};
    for (int i = 0; i < 10; i++) {
        printf("expected my_put_float_sci(%f, 0) = ", nums[i]);
        my_putchar('\n');
        printf("%e\n", nums[i]);
        my_printf("actual   my_put_float_sci(%f, 0) = ", nums[i]);
        my_printf("%e\n", nums[i]);
        my_putchar('\n');
    }
}

static void test_my_put_hex(void)
{
    int nums[] = {0, 10, 255, -10, -255, 4095, -4095};
    for (int i = 0; i < 7; i++) {
        printf("expected my_put_hex(%d, 0) = ", nums[i]);
        my_putchar('\n');
        printf("%x\n", nums[i]);
        my_printf("actual   my_put_hex(%d, 0) = ", nums[i]);
        my_printf("%x\n", nums[i]);
        my_putchar('\n');

        printf("expected my_put_hex(%d, 1) = ", nums[i]);
        my_putchar('\n');
        printf("%X\n", nums[i]);
        my_printf("actual   my_put_hex(%d, 1) = ", nums[i]);
        my_printf("%X\n", nums[i]);
        my_putchar('\n');
    }
}

static void test_my_put_ieee(void)
{
    double nums[] = {0.0 / 0.0, -2.5, 0.0, -0.0, 1.0, -1.0, 12345.6789, -12345.6789,
                     0.0001234, -0.0001234, 987654321.0, -987654321.0};
    for (int i = 0; i < 10; i++) {
        printf("expected my_put_ieee(%f) = %a", nums[i], nums[i]);
        my_putchar('\n');
        my_printf("actual   my_put_ieee(%f) = ", nums[i]);
        my_put_ieee(nums[i], 0);
        my_putchar('\n');
    }
}

static void test_my_put_octal(void)
{
    int nums[] = {0, 8, 64, -8, -64, 512, -512};
    for (int i = 0; i < 7; i++) {
        printf("expected my_put_octal(%d) = ", nums[i]);
        my_putchar('\n');
        printf("%o\n", nums[i]);
        my_printf("actual   my_put_octal(%d) = ", nums[i]);
        my_printf("%o\n", nums[i]);
        my_putchar('\n');
    }
}

static void test_my_put_bin(void)
{
    int nums[] = {0, 1, 2, 3, 4, 5, 10, 255, -1, -255};
    for (int i = 0; i < 10; i++) {
        printf("expected my_put_bin(%d) = %b", nums[i], nums[i]);
        my_putchar('\n');
        my_printf("actual   my_put_bin(%d) = ", nums[i]);
        my_put_bin(nums[i], 0, 0);
        my_putchar('\n');
    }
}

void test_my_put_pointer(void)
{
    void *ptrs[] = {NULL, (void *)0x1234, (void *)0xabcdef, (void *)0x0,
                    (void *)0x7fffffff, (void *)0x80000000};
    for (int i = 0; i < 6; i++) {
        printf("expected my_put_pointer(%p) = ", ptrs[i]);
        my_putchar('\n');
        printf("%p\n", ptrs[i]);
        my_printf("actual   my_put_pointer(%p) = ", ptrs[i]);
        my_printf("%p\n", ptrs[i]);
        my_putchar('\n');
    }
}

void test_my_put_float_fixed(void)
{
    double nums[] = {0.0, -0.0, 1.0, -1.0, 12345.6789, -12345.6789,
                     0.0001234, -0.0001234, 987654321.0, -987654321.0};
    for (int i = 0; i < 10; i++) {
        printf("expected my_put_float_fixed(%f) = ", nums[i]);
        my_putchar('\n');
        printf("%f\n", nums[i]);
        my_printf("actual   my_put_float_fixed(%f) = ", nums[i]);
        my_printf("%f\n", nums[i]);
        my_putchar('\n');
    }
}

void test_my_put_unsigned_nbr(void)
{
    unsigned int nums[] = {0, 1, 42, 255, 65535, 4294967295U};
    for (int i = 0; i < 6; i++) {
        printf("expected my_put_unsigned_nbr(%u) = ", nums[i]);
        my_putchar('\n');
        printf("%u\n", nums[i]);
        my_printf("actual   my_put_unsigned_nbr(%u) = ", nums[i]);
        my_printf("%u\n", nums[i]);
        my_putchar('\n');
    }
}

void extreme_case_tests(void)
{
    {
        /* Header */
        printf("----- Extreme case tests -----\n");
        my_printf("----- Extreme case tests -----\n");

        /* Floating point extremes */
        double nan = 0.0/0.0;
        double inf = 1.0/0.0;
        double ninf = -1.0/0.0;
        double dbmax = 1.7976931348623157e308;    /* approx DBL_MAX */
        double dbmin = -1.7976931348623157e308;
        double denorm = 5e-324;                  /* a subnormal (denormal) value */

        double fext[] = { nan, inf, ninf, dbmax, dbmin, denorm, -denorm };
        for (int i = 0; i < (int)(sizeof(fext)/sizeof(fext[0])); i++) {
            printf("expected float extreme (%d) = ", i);
            my_putchar('\n');
            printf("%%f: %f\n%%e: %e\n%%g: %g\n", fext[i], fext[i], fext[i]);

            my_printf("actual   float extreme (%d) = ", i);
            my_putchar('\n');
            my_printf("%f\n", fext[i]);
            my_printf("%e\n", fext[i]);
            my_printf("%g\n", fext[i]);

            /* IEEE754 bytes */
            printf("expected ieee754 bytes: ");
            my_putchar('\n');
            {
                unsigned char *p = (unsigned char *)&fext[i];
                for (size_t j = 0; j < sizeof(double); j++)
                    printf("%02x", p[sizeof(double) - 1 - j]);
                printf("\n");
            }
            my_printf("actual   ieee754 bytes: ");
            my_put_ieee(fext[i], 0);
            my_putchar('\n');
        }

        /* Integer extremes */
        int imax = 2147483647;
        int imin = -2147483648;
        long long llmax = 9223372036854775807LL;
        long long llmin = (-9223372036854775807LL - 1LL);
        unsigned int umax = 4294967295U;
        unsigned long long ullmax = 18446744073709551615ULL;

        printf("expected int max/min: ");
        my_putchar('\n');
        printf("%d %d\n", imax, imin);
        my_printf("actual   int max/min: ");
        my_putchar('\n');
        my_printf("%d %d\n", imax, imin);

        printf("expected long long max/min: ");
        my_putchar('\n');
        printf("%lld %lld\n", llmax, llmin);
        my_printf("actual   long long max/min: ");
        my_putchar('\n');
        my_printf("%lld %lld\n", llmax, llmin);

        printf("expected unsigned max: ");
        my_putchar('\n');
        printf("%u %llu\n", umax, ullmax);
        my_printf("actual   unsigned max: ");
        my_putchar('\n');
        my_printf("%u %llu\n", umax, ullmax);

        /* Binary / hex / octal extremes */
        int bnums[] = { 0, 1, -1, 255, -255, 2147483647, -2147483648 };
        for (int i = 0; i < (int)(sizeof(bnums)/sizeof(bnums[0])); i++) {
            printf("expected formats for %d:\n", bnums[i]);
            printf("  hex: %x %X\n  octal: %o\n", bnums[i], bnums[i], bnums[i]);
            {
                unsigned int n = (unsigned int)bnums[i];
                char buf[33];
                buf[32] = '\0';
                for (int j = 31; j >= 0; j--) {
                    buf[j] = (n & 1) ? '1' : '0';
                    n >>= 1;
                }
                printf("  binary: %s\n", buf);
            }

            my_printf("actual   formats for %d:\n", bnums[i]);
            my_printf("  hex: %x %X\n  octal: %o\n", bnums[i], bnums[i], bnums[i]);
            my_printf("  binary: ");
            my_put_bin(bnums[i], 0, 0);
            my_putchar('\n');
        }

        /* Pointer edge cases and mixed formatting */
        void *ptrs[] = { NULL, (void *)&main };
        for (int i = 0; i < (int)(sizeof(ptrs)/sizeof(ptrs[0])); i++) {
            printf("expected pointer %d: %p\n", i, ptrs[i]);
            my_printf("actual   pointer %d: %p\n", i, ptrs[i]);
        }

        printf("expected mixed format: %s %d %f %p %x\n", "extreme", imin, inf, (void *)&main, 255);
        my_printf("actual   mixed format: %s %d %f %p %x\n", "extreme", imin, inf, (void *)&main, 255);

        /* final separator */
        printf("----- End extreme case tests -----\n");
        my_printf("----- End extreme case tests -----\n");
    }
}

int main(void)
{
    test_my_put_float_sci();
    test_my_put_hex();
    test_my_put_ieee();
    test_my_put_octal();
    test_my_put_bin();
    test_my_put_pointer();
    test_my_put_float_fixed();
    test_my_put_unsigned_nbr();
    return 0;
}