#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \brief Calculates number of change coin 
 * */
long get_change(long n) {
    long dime, nickel, cent;
    long rest;
    dime = n / 10;
    nickel = (n - dime * 10) / 5;
    cent = n - dime * 10 - nickel * 5;
    return dime + nickel + cent;
}

int main() {
    long n = 0; 
    char buffer[100];
    fgets(buffer, 100, stdin);
    n = atol(buffer);
    printf("%d\n", get_change(n));
    return 0;
}
