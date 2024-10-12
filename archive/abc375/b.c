// stdioのみmalloc不使用オーガニック縛り
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <math.h>  // この問題、縛り無理ゲーで草
#include <stdio.h>

int med3(int x, int y, int z) {
    if (x < y)
        if (y < z)
            return y;
        else if (z < x)
            return x;
        else
            return z;
    else if (z < y)
        return y;
    else if (x < z)
        return x;
    else
        return z;
}
void quicksort(int a[], int left, int right) {
    if (left < right) {
        int i = left, j = right;
        int tmp, pivot = med3(a[i], a[i + (j - i) / 2], a[j]);
        while (1) {
            while (a[i] < pivot)
                i++;
            while (pivot < a[j])
                j--;
            if (i >= j)
                break;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
        quicksort(a, left, i - 1);
        quicksort(a, j + 1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    static double x[300000], y[300000];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i + 1], &y[i + 1]);
    }

    double ans = 0;
    for (int i = 0; i < n + 2; i++) {
        double dx = x[i] - x[i + 1];
        double dy = y[i] - y[i + 1];
        double x = dx * dx + dy * dy;
        ans += sqrt(x);
    }
    printf("%lf\n", ans);

    return 0;
}