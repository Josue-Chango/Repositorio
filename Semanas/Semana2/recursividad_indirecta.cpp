#include <iostream>

int fivonaci(int n);

int fivonaci_pares(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return fivonaci(n) + fivonaci_pares(n - 1);
    }
}

int fivonaci_impares(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return fivonaci(n) + fivonaci_impares(n - 1);
    }
}

int fivonaci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fivonaci_pares(n - 1) + fivonaci_impares(n - 2);
    }
}

