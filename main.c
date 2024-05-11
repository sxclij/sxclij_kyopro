#pragma GCC optimize("O3")
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define hashtable_size (1 << 27)

#define dx          \
    (int64_t[]) {   \
        0, 1, 0, -1 \
    }
#define dy          \
    (int64_t[]) {   \
        1, 0, -1, 0 \
    }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

struct hashtable {
    uint64_t key;
    int64_t value;
} ;
struct node {
    int64_t score;
    int64_t x;
    int64_t y;
};
static struct hashtable hashtable[hashtable_size];
static struct node nodes[50000];
static struct node* nodes_end = nodes;

uint64_t xorshift64(int64_t x) {
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
    return x;
}
int64_t* hashtable_find(int64_t key) {
    uint64_t hash = key + 114514;
    while (1) {
        hash = xorshift64(hash);
        struct hashtable* table_ptr = &hashtable[hash % hashtable_size];
        if (table_ptr->key == 0)
            table_ptr->key = key;
        if (table_ptr->key == key)
            return &table_ptr->value;
    }
}

struct node nodes_pop() {
    return *(--nodes_end);
}
void nodes_push(struct node node) {
    *(nodes_end++) = node;
}

int main() {
}