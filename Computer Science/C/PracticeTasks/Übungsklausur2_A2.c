#include <stdio.h>
#include <assert.h>

unsigned int maxevenrec(unsigned int arr[], int index, int size) {
    int evenValue_1 = 0;
    int evenValue_2 = 0;

    /*
    Wenn das Array komplett durchlaufen wurde, wird 0 zurückgegeben.
    0 ist in der letzten if-Abfrage, in der die Werte verglichen werden, 
    immer der kleinere Wert (wenn das Array nicht nur aus 0en besteht)
    */
    if(size == 0) {  // Abbruchbedingung  
        return 0;  
    }

    /* 
    Durch den rekursiven Aufruf wird das Array nicht per for-Schleife 
    durchlaufen, sondern es wird bei jedem Aufruf geprüft, ob das aktuelle Element 
    gerade ist.     
    */
    if(arr[index] %2 == 0) {
        evenValue_1 = arr[index];
    }

    /*
    Rekursiver Aufruf (siehe Extrablatt)
    Die Funktion ruft sich rekursiv auf bis die Abbruchbedingung (size == 0)
    erreicht und 0 zurückgegeben wird. Ab diesem Punkt wird die Funktion weiter durchlaufen
    und die vorherigen Aufrufe werden rückabgewickelt (siehe Dokument)
    */
    evenValue_2 = maxevenrec(arr, index + 1, size - 1);

    /*
    Von beiden Werten wird der größere zurückgegeben
    */
    if (evenValue_1 > evenValue_2) {
        return evenValue_1;
    }
    return evenValue_2;

}

int main(){
    unsigned int arr[15] = {1, 9, 5, 8, 8, 4, 2, 6, 5, 5, 11, 123, 222, 41, 0};

    assert(maxevenrec(arr, 0, sizeof(arr)/sizeof(int)) == 222); 

}
