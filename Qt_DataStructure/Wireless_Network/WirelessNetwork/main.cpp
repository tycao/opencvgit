#include <cstdio>
#include <cmath>

//#define N 1005

constexpr int N = 1005;
int is[N][N];
typedef struct
{
    int x;
    int y;
    int state;
} Point;
int parent[N];
int find(int);
int un(int, int);

int main(int argc, char *argv[])
{
    int n;
    double d;
    int j = 0, k = 0, a, b;
    double temp = 0;
    char c;
    Point point[N];
    scanf("%d%lf", &n, &d);
    for (int i = 1; i < n + 1; ++i)
    {
        scanf("%d%d", &point[i].x, &point[i].y);
        point[i].state = 0;
    }
    for (int i = 0; i != N; ++i) parent[i] = -1;
    for (int i = 0; i != n + 1; ++i)
        for (j = 1, is[i][0] = 0, k = 1; j != n + 1; ++j)
        {
            temp = sqrt((point[i].x - point[j].x) * (point[i].x - point[j].x)
                        + (point[i].y - point[j].y) * (point[i].y - point[j].y));
            if (temp <= d)
            {
                is[i][k++] = j;
                is[i][0]++;
            }
        }
    while (scanf("\n%c", &c) != EOF)
    {
        if (c == 'O')
        {
            scanf("%d", &a);
            point[a].state = 1;
            for (int i = 0; i != is[a][0] + 1; ++i)
                if (point[is[a][i]].state)
                    un(a, is[a][i]);
        }
        if (c == 'S')
        {
            scanf("%d%d", &a, &b);
            if (a == b)
                printf("SUCCESS\n");
            else {
                if (find(a) == find(b))
                    printf("SUCCESS\n");
                else
                    printf("FAIL\n");
            }
        }
    }
    return 0;
}

int find(int key)
{
    int i, temp;
    for (i = key; parent[i] >= 0; i = parent[i]);
    while (key != i)
    {
        temp = parent[key];
        parent[key] = i;
        key = temp;
    }
    return i;
}
int un(int a, int b)
{
    int m = find(a);
    int temp;
    int n = find(b);
    if (m == n)
        return 0;
    temp = parent[m] + parent[n];
    parent[m] = n;
    parent[n] = temp;
    return 1;
}
