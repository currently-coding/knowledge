#include <stdio.h>
#include <assert.h>

unsigned int modulo_rec(unsigned int x, unsigned int n){
    if (x == n) {
        return 0; 
    }
    else if (x < n) {
        return x;
    }
    else {
        return modulo_rec(x - n, n); 
    }
}

int main(){
    assert(modulo_rec(2, 2) == 0); 
    assert(modulo_rec(12, 10) == 2); 
    assert(modulo_rec(65, 9) == 2); 
    assert(modulo_rec(23, 68) == 23); 
    assert(modulo_rec(0, 0) == 0); 
}