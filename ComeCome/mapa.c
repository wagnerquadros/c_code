#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void encontraMapa(MAPA* m, POSICAO* p, char c){
        //acha a posição do ComeCome
    for(int i =0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if (m->matriz[i][j]== c){
                p->x =i;
                p->y = j;
                break;
            }
        }
    }
}

void andaNoMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){

    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = '.';        
}

int ehValida(MAPA* m, int x, int y){
    if(x >= m->linhas)
        return 0;
    if(y >= m->colunas)
        return 0;

    return 1;
}

int ehVazia(MAPA* m, int x, int y){
    return m->matriz[x][y] == '.';
}

void liberaMapa(MAPA* m){
    for(int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void alocaMapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1));
    }
}

void leMapa(MAPA* m){
    FILE* f;
    f= fopen("D:\\c_code\\ComeCome\\mapa.txt", "r");
    if(f == 0){
        printf("Erro na leitura do mapa");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas) , &(m->colunas));

    alocaMapa(m);

    for(int i = 0; i < 5; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void imprimeMapa(MAPA* m){
    for(int i = 0; i < 5; i++){
        printf("%s\n", m->matriz[i]);
    }
}