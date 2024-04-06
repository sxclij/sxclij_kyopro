#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define hashtable_size 100000000

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

static int32_t hashtable[hashtable_size];
uint32_t hash(int32_t a) {
    uint32_t x = 114514 + a;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return x;
}
int32_t* hashtable_find(int32_t key) {
    return &hashtable[hash(key) % hashtable_size];
}

struct task {
    int32_t score;
    int32_t x;
    int32_t y;
};

int main() {
}