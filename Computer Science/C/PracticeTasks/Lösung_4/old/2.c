#include <assert.h>

unsigned long long greatest_common_factor(unsigned long long n1, unsigned long long n2) {
    if (n1 == n2) {
        return n1;
    } else if (n1 < n2) {
        return greatest_common_factor(n2, n2 - n1);
    } else {
        return greatest_common_factor(n1 - n2, n2);
    }   
}

int main() {
    assert(greatest_common_factor(4, 4) == 4);
    assert(greatest_common_factor(4, 2) == 2);
    assert(greatest_common_factor(3, 6) == 3);
    assert(greatest_common_factor(4, 6) == 2);
    assert(greatest_common_factor(8, 32) == 8);
    assert(greatest_common_factor(162, 3480) == 6);
    assert(greatest_common_factor(16268, 3484208) == 28);
    assert(greatest_common_factor(1626856824, 348420812458) == 2);
    return 0;
}