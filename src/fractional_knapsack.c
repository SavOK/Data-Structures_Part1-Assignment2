#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Item {
    long value;
    long weight;
    double unit_weight;
} Item;

void print_items ( const struct Item * items, size_t size ){
    for (long i = 0; i < size; ++i)
        printf("%ld %ld %6.4f\n", items[i].value, items[i].weight, items[i].unit_weight );
}

int compareItems (const void * a, const void * b);

double get_optimal_value(long capacity, const struct Item *items,  size_t n); 

int main() {

    long N, capacity, i;

    int K = scanf("%ld %ld", &N, &capacity);

    struct Item *items = (struct Item*) malloc(sizeof(struct Item) * N);

    i = 0;
    while ( i <  N) {
        scanf("%ld %ld", &items[i].value, &items[i].weight);
        items[i].unit_weight =(double) items[i].value/items[i].weight;
        i++;
    }

    qsort (items, N, sizeof(struct Item), compareItems);

    double opt_value = get_optimal_value( capacity, items, N);

    printf("%10.4f\n", opt_value); 
    free(items);
    items = NULL;
    return 0;
}

int compareItems (const void * a, const void * b) {
    const struct Item *A = a;
    const struct Item *B = b;
    if ( A->unit_weight <  B->unit_weight ) return -1;
    if ( A->unit_weight > B->unit_weight ) return 1;
    if ( A->unit_weight == B->unit_weight ) {
        if ( A -> weight > B->weight ) return 1; //prefer heaver items
        if ( A -> weight < B->weight ) return -1;  
        return 0;
    }
}

double get_optimal_value(long capacity, const struct Item *items,  size_t n) {
    double total_value = 0.0;
    long rest = capacity;
    const struct Item *curr_item;
    for ( long i = n; i != 0 && rest > 0; i--) {
        curr_item = items + (i - 1);
        if ( curr_item->weight > rest ) {
            total_value += (double) rest * curr_item->unit_weight;
            break;
        } 
        rest -= curr_item->weight;
        total_value += curr_item->value;
    }
    return total_value;
}

