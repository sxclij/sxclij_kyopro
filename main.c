#include <stdio.h>

#define ntable_size 1000000

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define input_int(x) \
    int x;           \
    scanf("%d", &x);

typedef struct t_node {
    int value;
} t_node;

static t_node* ntable[ntable_size];

unsigned int ntable_xorshift(unsigned int x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}
t_node* ntable_get(int key) {
    unsigned int i = ntable_xorshift(key);
    return ntable[i % ntable_size];
}
void ntable_set(int key, t_node* value) {
    unsigned int i = ntable_xorshift(key);
    ntable[i % ntable_size] = value;
}

int main() {
    fflush(stdout);
    return 0;
}
