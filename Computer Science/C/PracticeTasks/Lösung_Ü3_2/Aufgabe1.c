#include <stdio.h>
#include <stdlib.h>


int event_loop() {
    char buffer = 'x';  // Deklaration und Initialisiserung 

    while (1) {  // Endlosschleife, wird mittels break beendet

        printf("\n***\nBitte eine Zahl zwischen 1 und 3 wählen. \'x\' beendet das Programm.\n***\n");  
        fflush(stdin);  // Sicherstellen, dass der Standardinput leer ist
        scanf("%c", &buffer);
    
        if (buffer == 'x' || buffer == 'X') {
            break;  // beendet das Programm
        }
        
        const int num = atoi(&buffer);  // wandelt die als character eingelesene Zahl in eine Integer um
        if (num < 1 || num > 3) {
            printf("\nFehler, Sie müssen eine Zahl zwischen 1 und 3 wählen!\n");
            continue;  // bei einer falschen Eingabe wird die Schleife erneut ausgeführt und nach Input gefragt
        }

        printf("\n***\nIhr Wahl: %d\n***\n", num);  // beendet die Schleife nicht, da diese nur mit x beendet wird
    } 
    return 0;
}

int main() {
    return event_loop();
}