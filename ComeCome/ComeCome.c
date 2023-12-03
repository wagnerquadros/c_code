#include <stdio.h>
#include <stdlib.h>
#include "ComeCome.h"
#include "mapa.c"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

int ehDirecao(char direcao){
    return direcao == 'a' ||
        direcao == 'w' ||
        direcao == 's' ||
        direcao == 'd';
}


void move(char direcao){
    
    if(!ehDirecao(direcao))
            return;
        
    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao) {
        case 'a':
            proximoy--;
            break;
        case 'w':
            proximox--;
            break;
        case 's':
            proximox++;
            break;
        case 'd':
            proximoy++;
            break;
    }

    if(!ehValida(&m, proximox, proximoy))
        return;
    if(!ehVazia(&m, proximox, proximoy))
        return;
    
    andaNoMapa(&m, heroi.x, heroi.y, proximox, proximoy);

    heroi.x = proximox;
    heroi.y =proximoy; 
    
}

int main(){
    
    leMapa(&m);
    encontraMapa(&m, &heroi, '@');
    
    do{
        imprimeMapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while(!acabou());

    liberaMapa(&m);
}