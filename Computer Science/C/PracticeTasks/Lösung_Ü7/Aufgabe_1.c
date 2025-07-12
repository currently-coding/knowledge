
#include <stdio.h>

void cross(unsigned int size){
    char x = 'x';
    char emptySpace = ' ';

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(j == i) {  
                printf("%c", x);
            }
            else if(j == (size - 1 - i)) {
                printf("%c", x);
            }
            else {
                printf("%c", emptySpace); 
            }
        }
        printf("\n"); 
    }
}

int main(){
    cross(10); 
}