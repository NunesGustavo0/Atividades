#include <stdio.h>
#include <stdlib.h>

struct Vetor{
    int x;
    int y;
    int z;

};
int main(){
    struct Vetor r[2];
    int i, soma1, soma2, soma3;

    for(i=1; i<3; i++){
        printf("Insira os valores do vetor%d\n", i);
        scanf("%d %d %d", &r[i].x, &r[i].y, &r[i].z);
    }
    soma1 = r[1].x * r[1].y * r[1].z;
    soma2 = r[2].x * r[2].y * r[2].z;
    soma3 = soma1 + soma2;

    printf("Soma1: %d\n", soma1);
    printf("Soma2: %d\n", soma2);
    printf("Soma3: %d\n", soma3);

}
