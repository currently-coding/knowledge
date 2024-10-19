#include <assert.h>

unsigned long long greatest_common_factor(unsigned long long z1, unsigned long long z2) {
    if (z1 == z2) {
        /*
        Wenn beide Zahlen gleich groß sind, ist der größte gemeinsam Teiler gefunden
        und z1 wird zurückgegeben
        */
        return z1; 
    } else if (z1 < z2) {
        /*
        Wenn eine Zahl größer als die andere ist, ist der ggT noch nicht gefunden worden. 
        Gibt es keinen, dann läuft die Rechnung weiter, bis beide Zahlen 1 sind. 
        */
        return greatest_common_factor(z2, z2 - z1);  // beendet die Funktion und ruft sich selbst wieder auf
    } else {
        return greatest_common_factor(z1 - z2, z2);
    }   
}

int main() {
    /*
    assert() prüft, ob der Rückgabewert der Funktion mit dem Vergleichswert übereinstimmt
    Wenn das Programm ohne Warnung durchläuft wurden alle Tests bestanden 
    */
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