// stdioのみmalloc不使用オーガニック縛り
#include <stdio.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

struct task {
    int x;
    int y;
    char color;
};

int main() {
    int n;
    static char a[3000][3000];
    static struct task task[9000000];
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    int task_size = 0;
    for (int i = 1; i < n / 2 + 1; i++) {
        for (int j = i; j < n + 1 - i + 1; j++) {
            for (int k = i; k < n + 1 - i + 1; k++) {
                task[task_size++] = (struct task){.x = k - 1, .y = n + 1 - j - 1, .color = a[j - 1][k - 1]};
            }
        }
        for (int j = 0; j < task_size; j++) {
            a[task[j].x][task[j].y] = task[j].color;
        }
        task_size = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
}