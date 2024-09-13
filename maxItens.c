#include "funcionalidades.h"

void resolucaoMochila(elemento* elementos, int qtd, int pesoMax){
    int soma=0, i=0;

    while(soma<pesoMax && i<qtd){
        soma += elementos[i].peso;
        elementos[i].entrou = 1;
        i++;
    }

    if(soma>pesoMax){
        soma -= elementos[i-1].peso;
        elementos[i-1].entrou = 0;
    }
}

int main(){
    FILE *arq = fopen("knapPI_1_100_1000_1", "r");
    int qtd, pesoMax;
    infoMochila(arq, &qtd, &pesoMax);
    elemento *elementos = (elemento *)calloc(qtd, sizeof(elemento));
    leituraPesoValor(arq, elementos, qtd);

    fclose(arq);

    ordenaPeso(elementos, 0, qtd-1);
    resolucaoMochila(elementos, qtd, pesoMax);
    ordenaPosicao(elementos, 0, qtd-1);

    output(elementos, qtd);

    free(elementos);

    return 0;
}