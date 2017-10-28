#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

#define N 100010

extern int part(int* a, int left, int right);
extern int solve(int* a, int left, int right, int middle);
extern int random_part(int* a, int left, int right);
int number[N];

int main(int argc, char *argv[])
{
    int i = 0, j = 0, k = 0, total, question;
    int left = 0, right = 0, middle = 0;
    int temp[N];
    scanf("%d%d", &total, &question);
    for (i = 1; i != total + 1; ++i)
        scanf("%d", &number[i]);
    for (i = 0; i != question; ++i)
    {
        scanf("%d%d%d", &left, &right, &middle);
        for (j = left; j != right + 1; ++j)
            temp[j - left + 1] = number[j];
        printf("%d\n", solve(temp, 1, right - left + 1, middle));
    }
    return 0;
}


int part(int* a, int left, int right)
{
    int x = a[right], i = left - 1, j = 0;
    int temp = 0;
    for (j = left; j < right; ++j)
    {
        if (a[j] <= x)
        {
            ++i;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = temp;
    return i + 1;
}
int solve(int* a, int left, int right, int middle)
{
    int q = 0, k = 0;
    if (left == right)
        return a[left];
    q = random_part(a, left, right);
    k = q - left + 1;
    if (middle == k)
        return a[q];
    if (middle < k)
        return solve(a, left, q - 1, middle);
    return solve(a, q + 1, right, middle - k);
}
int random_part(int* a, int left, int right)
{
    int temp, i;
    i = rand() % (right - left + 1) + left;
    temp = a[i];
    a[i] = a[right];
    a[right] = temp;
    return part(a, left, right);
}
