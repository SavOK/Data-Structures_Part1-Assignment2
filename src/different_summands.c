#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \brief Pairwise distinct summands
 *
 * Calculates pairwise distinct summands (k_1, k_2, ...k_n) of integer N. 
 * such as k_1+k_2+..+k_n = N and k_1 < k_2 < ... < k_n
 *
 * \param[in] N (long)
 * \param[out] summands pointer to the array where summands are stored (long**)
 * \param[out[ Nsummads number of distinct summands
 * \return Total size of the array summands
 * */
size_t optimal_summands(long N, long* *summands, long *Nsummads ) {
    size_t asize= 1024;
    long rest = N;
    long curr = 0; 
    *summands = (long*) realloc(*summands, sizeof(long) * asize);
    if (!(*summands)) {
        fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }
    for (long i = 1; i < N ; ++i) { // can limit loop to sqrt(N) + 1 
        if ( rest - i > i ) {  // continue loop until subtraction less then i
            if (curr + 2 == asize) { // +2 insure extra space for last addition
                asize += 1024;
                *summands = (long*) realloc(*summands, sizeof(long) * asize);
                if (!(*summands)) {
                    fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
                    exit(EXIT_FAILURE);
                }
            }
            (*summands)[curr] = i;
            rest -= i;
            curr++;
        } else { // break loop
            (*summands)[curr] = rest; 
            curr++;
            *Nsummads = curr;
            return asize;
        }
    }
    *Nsummads = curr;
    return asize;
}

int main() {
    long n = 0; 
    char buffer[100];
    fgets(buffer, 100, stdin);
    n = atoi(buffer);
    if(n==1) {
        printf("1\n1\n");
        return 0;
    }
    long *summands = (long*) malloc(sizeof(long) * 1);
    if (!summands) {
        fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }
    long Nsum = 0;
    optimal_summands(n, &summands, &Nsum);
    printf("%ld\n", Nsum);
    for(long i = 0; i < Nsum; ++i) {
        printf("%ld ", summands[i]);
    }
    printf("\n");
    free(summands);
    summands = NULL;
    return 0;
}
