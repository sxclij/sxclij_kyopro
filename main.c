// stdioのみmalloc不使用オーガニック縛り
#include <stdio.h>

struct task {
    int x;
    int y;
    char color;
};

int main() {
    int n;
    scanf("%d", &n);

    static char a[3000][3000];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    static struct task task[9000];
    int task_size = 0;
    for (int i = 1; i < n / 2 + 1; i++) {
        for (int j = i; j < n + 1 - i + 1; j++) {
            for (int k = i; k < n + 1 - i + 1; k++) {
                task[task_size++] = (struct task){.x = k - 1, .y = n + 1 + j - 1, a[j - i][k - 1]};
            }
        }
        for(int j=0;j<task_size;j++) {
            a[task[j].x-1][task[j].y-1] = task[j].color;
        }
        task_size = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }
}