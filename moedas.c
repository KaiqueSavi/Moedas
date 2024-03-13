#include <cs50.h>
#include <stdio.h>

int main (void)
{
    char resposta; //fazer novamente
    char inicio = get_char("Deseja começar?(y/n) "); //iniciar
    if(inicio=='y')
    {
    do {
    printf("----------\n");
    // moedas
    printf("Olá\n");
    printf("----\n");
    string x = get_string(" \n");
    float valor = get_float("Valor da compra?: "); //pede valor da compra
    float dinheiro = get_float("Dinheiro: "); //solicita dinheiro
    int moedas = 0;
    int notas = 0;
// moedas valores
    float moedas_a[6] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};
// notas valores
    float not_a[5] = {50.00, 20.00, 10.00, 5.00, 2.00};
// notas quantidade
    int rest_a[5] = {0, 0, 0, 0, 0};
// moedas quantidade
    int moedas_quanti[6] = {0, 0, 0, 0, 0, 0};
// inicio
    float faltante = valor - dinheiro; //caso falte dinheiro
    float t = dinheiro - valor; //troco
    printf("----------\n");
    printf("Mercadinho\n");
    printf("----------\n");
    if(dinheiro>valor)
    {
// subtração do troco
        do
        {
            printf("Valor do troco: %.2f", t);
            printf("\n");
        } while (t<=0.00);
// notas
            int k;
            for(k=0; k<5; k++)
            {
            while (t>=not_a[k]) {
                t-=not_a[k];
                notas++;
                rest_a[k]++;
            }
            }
// moedas
            int i;
            for(i=0; i<6; i++)
            {
            while (t >= moedas_a[i]) {
                t-= moedas_a[i];
                moedas++;
                moedas_quanti[i]++;
            }
            }
// troco das moedas e notas
        printf ("Você vai precisar de %i moeda(s), e %i nota(s).\n", moedas, notas);
        printf ("\n");
        printf ("Sendo elas:\n");
        printf("\n");
// quantidade das notas
            int o;
            for(o=0; o<5; o++)
            {
                if (rest_a[o]>0)
                {
                    printf("%i", rest_a[o]);
                    printf((" nota(s) de: R$%.2f"), not_a[o]);
                    printf(";\n");

                }
            }
// quantidade de moeda
            int p;
            for(p=1; p<6; p++)
            {
                if (moedas_quanti[p]>0)
                {
                    printf ("%i", moedas_quanti[p]);
                    printf (" moeda(s) de R$%.2f", moedas_a[p]);
                    printf(" centavos;\n");
                }
            }
// moedas de 1 REAL
                if (moedas_quanti[0]>0)
                {
                    printf ("%i", moedas_quanti[0]);
                    printf (" moeda(s) de R$%.2f", moedas_a[0]);
                    printf(" real");
                    printf(";\n");
                }
    }
// caso o valor da compra seja maior que a compra
    if(dinheiro<valor)
    {
        printf("Você não tem dinheiro suficiente.");
        printf("\n");
        printf("Faltam R$%.2f", faltante);
        printf(".");
        printf("\n");
        printf("\n");
    }
// loop para fazer novamente
    printf("-------------------------------------------\n");
    printf("Deseja realizar o processo novamente?(y/n) ");
        scanf("%c", &resposta);
        printf("\n");
  } while (resposta=='y');
//   agradecimento
    if(resposta=='n')
    {
        printf("---------------\n");
        printf("MUITO OBRIGADO!\n");
        printf("---------------\n");
    }
}
}
