#pragma GCC optimize("O3")
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define hashtable_size (1 << 27)

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

struct node {
    int32_t score;
    int32_t x;
    int32_t y;
};
static struct node nodes[50000];
static struct node* nodes_end = nodes;
struct node nodes_pop() {
    return *(--nodes_end);
}
void nodes_push(struct node node) {
    *(nodes_end++) = node;
}

int main() {
}