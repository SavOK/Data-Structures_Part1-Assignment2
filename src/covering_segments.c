#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Segment {
    long start;
    long end;
};

void print_segments( const struct Segment *segments, size_t size); 

int compareSegment (const void * a, const void * b);

/*!
 * \brief Covering segments by points
 *
 * For given set of N segments  {[a_1,b_1],[a_2,b_2],...,[a_n,b_n]} with integer coordinates on a line, 
 * Calculates the minimum number M of points and (their coordinates) such that each segment contains at least one point. 
 *
 * \param[in] segments __Sorted__ array of segments (Segment*)
 * \param[in] N number of segments in array (long)
 * \param[out] points pointer to the array where points will be stored (long**)
 * \param[out] Npoints pointer to number of points (long*)
 *
 * \return size of the points array </br>
 * __IMPORTANT__ Array of segments should be sorted in increasing order based on the end of point of segment
 * */
size_t optimal_points(const struct Segment *segments, long N, 
        long* *points, long *Npoints ); 

int main() {
    long N, i, Npoints;

    int K = scanf("%ld", &N);

    struct Segment *segments = 
        (struct Segment*) malloc(sizeof(struct Segment) * N);
    if (!segments) {
        fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while ( i <  N) {
        scanf("%ld %ld", &segments[i].start, &segments[i].end);
        i++;
    }

    long *points = (long*) malloc (sizeof(long) * 1);
    if (!points) {
        fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }
    
    //Sort segments
    qsort (segments, N, sizeof(struct Segment), &compareSegment);

    optimal_points ( segments, N, &points,  &Npoints);

    printf("%ld\n", Npoints);
    for (i = 0; i < Npoints; ++i) {
        printf("%ld ", points[i]);
    }
    printf("\n");

    free(segments);
    segments = NULL;
    free(points);
    points = NULL;
    return 0;
}

void print_segments(const struct Segment *segments, size_t size) {    
    for (long i = 0; i < size; ++i){
        printf("%ld %ld\n", segments[i].start, segments[i].end);
    }
    return;
}

int compareSegment (const void * a, const void * b) {
    const struct Segment *A = a;
    const struct Segment *B = b;
    if ( A->end < B->end) return -1;
    if ( A->end > B->end) return 1;
    if ( A->end == B->end) {
        if ( A->start > B->start) return 1;
        if ( A->start < B->start) return -1;
        return 0;
    }
}

size_t optimal_points(const struct Segment *segments, long N, 
        long* *points, long *Npoints ) {

    size_t asize = 1024;
    long curr = 0;
    *points = (long*) realloc(*points, sizeof(long) * asize);
    if (!(*points)) {
        fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
        exit(EXIT_FAILURE);
    }
    (*points)[curr] = segments[0].end;
    for ( long i = 0; i < N; ++i) {
        if ( segments[i].start > (*points)[curr] ) {
            if (curr + 1 == asize) { // +2 insure extra space for last addition
                asize += 1024;
                *points = (long*) realloc(*points, sizeof(long) * asize);    
                if (!(*points)) {
                    fprintf(stderr, "CANNOT ALLOCATE MEMORY\n");
                    exit(EXIT_FAILURE);
                }
            }
            (*points)[++curr] = segments[i].end;
        }
    }
    *Npoints = curr+1;

    return asize;
}
