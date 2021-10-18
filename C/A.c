#include <stdio.h>
#include <stdbool.h>

#define bool _Bool

int sign(int a)
{
    return (a > 0) - (a < 0);
}

int abs(int a)
{
    return (-1) * (a < 0) * a + (a >= 0) * a;
}

int min(int a, int b)
{
    return (a < b) * a + (a >= b) * b;
}

int max(int a, int b)
{
    return (a < b) * b + (a >= b) * a;
}

int mod(int a, int b)
{
    if (sign(a) * sign(b) >= 0) {
        return abs(a) % abs(b);
    }
    return abs(b) - abs(a) % abs(b);
}

bool func(int a, int b)
{
    if (abs(a + b + 10) + abs(a + b + 20) == 10) {
        return true;
    }
    return false;

}

void swap(int *a, int *b, int *ans)
{
    *ans = *a;
    *a = *b;
    *b = *ans;
}

int main(void)
{
    int i, j, l, ik, jk, lk, ans;
    scanf("%d %d %d", &i, &j, &l);
    for (int k = 1; k < 50; ++k) {
        ik = sign(i + 1) * abs(abs(k - 1 - j) - abs(i - l));
        jk = mod(j, 20) + max(mod(i, 20), min(j - k - 1, l - k - 1)) - 10;
        lk = mod((k - 1) * (i + 1) * (j + 2) * (l + 3), 20);
        if (func(ik, jk) == true) {
            printf("Yes\n%d %d %d %d\n", ik, jk, lk, k);
            return 0;
        }
        swap(&ik, &i, &ans);
        swap(&jk, &j, &ans);
        swap(&lk, &l, &ans);
    }
    printf("No\n%d %d %d 50\n", ik, jk, lk);
    return 0;
}
