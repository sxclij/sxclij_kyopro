#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define hashtable_size 100000000

#define dx          \
    (int32_t[]) {   \
        0, 1, 0, -1 \
    }
#define dy          \
    (int32_t[]) {   \
        1, 0, -1, 0 \
    }
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
static struct task tasks[50000];
static struct task* tasks_end = tasks;
struct task tasks_pop() {
    return *(--tasks_end);
}
void tasks_push(struct task task) {
    *(tasks_end++) = task;
}


int main() {
}