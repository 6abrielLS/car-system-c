#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<locale.h>
struct carro
{
	char marca[20], modelo[20], cor[20], tipoDirecao[20];
	int km, anoFab, qtdPortas;
	float precoCarro;
};
typedef struct carro CAR;

int CadCarro(CAR c[50], int vet)
{
	if(vet == 50)
		printf("Nao há espaço para cadastrar novos carros");
	else
	{
		printf("\nCadastro de carros");
		
		fflush(stdin);
		printf("\n\nMarca do carro: ");
		gets(c[vet].marca);
		
		fflush(stdin);
		printf("Modelo: ");
		gets(c[vet].modelo);
		
		fflush(stdin);
		printf("Cor do carro: ");
		gets(c[vet].cor);
		
		printf("Ano de fabricação: ");
	    scanf("%d", &c[vet].anoFab);	
		
		printf("Km rodados: ");
		scanf("%d", &c[vet].km);
		
		fflush(stdin);
		printf("Tipo de direção: ");
		gets(c[vet].tipoDirecao);
		
		printf("Quantidade de portas: ");
		scanf("%d", &c[vet].qtdPortas);	
		
		printf("Valor do carro: ");
		scanf("%f", &c[vet].precoCarro);
 	
  		vet++;
	}
	return vet;
};

void pesquisarFaixaPreco(CAR c[50], int vet) 
{
	int encontrou = 0;
    float valorMin, valorMax;
    printf("\nPesquisar faixa de preço");
    
    printf("\n\nValor mínimo: ");
    scanf("%f", &valorMin);
    
    printf("Valor máximo: ");
    scanf("%f", &valorMax);
    
    for(int i = 0; i < vet; i++)
    {
        if ((c[i].precoCarro >= valorMin) && (c[i].precoCarro <= valorMax))
        {
            printf("\nMarca: %s \nModelo: %s \nCor: %s \nValor: %.2f\n", c[i].marca, c[i].modelo, c[i].cor, c[i].precoCarro);
            
			encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("\nNenhum carro encontrado nessa faixa de preço!");
    }
}

void pesquisarModelo(CAR c[50], int vet)
{
	char buscaModelo[20];
	int encontrou = 0;
	printf("\nPesquisa por modelo do carro");
	fflush(stdin);
	printf("\n\nModelo: ");
	gets(buscaModelo);
	
	for(int i = 0; i < vet; i++)
	{
		if(strcmp(c[i].modelo, buscaModelo) == 0)
		{
			printf("\nMarca: %s \nModelo: %s \nCor: %s \nValor: %.2f\n", c[i].marca,c[i].modelo, c[i].cor, c[i].precoCarro);
			
			encontrou = 1;
		}	
	}
	if(!encontrou)
		printf("\nNenhum modelo de carro encontrado!");
}

void pesquisarKm(CAR c[50], int vet)
{
	int buscaKm;
	int encontrou = 0;
	printf("\nPesquisa por KM rodados");
	printf("\n\nKm rodados: ");
	scanf("%d", &buscaKm);
	
	for(int i = 0; i < vet; i++)
	{
		if(c[i].km <= buscaKm)
		{
			printf("\nMarca: %s \nModelo: %s \nCor: %s \nKm rodados: %d \nValor: %.2f\n", 
			c[i].marca, c[i].modelo, c[i].cor, c[i].km, c[i].precoCarro);
			
			encontrou = 1;
		}
	}
	
    if (!encontrou)
        printf("\nNenhum carro corresponde a essa quilometragem!");
	
}

void pesquisaAnoCorValor(CAR c[50], int vet)
{
	int buscaAno, encontrou = 0;
	char buscaCor[20];
	float buscaValor;
	
	printf("\nPesquisa por ano, cor e valor do carro");
	printf("\n\nAno: ");
	scanf("%d", &buscaAno);
	fflush(stdin);
	printf("Cor: ");
	gets(buscaCor);
	printf("Valor: ");
	scanf("%f", &buscaValor);
	
	for(int i = 0; i < vet; i++)
	{
		if((c[i].anoFab <= buscaAno) && (strcmp(c[i].cor, buscaCor) == 0) && (c[i].precoCarro <= buscaValor))
		{
			printf("\nMarca: %s \nModelo: %s \nAno: %d \nCor: %s \nValor: %.2f\n", 
			c[i].marca, c[i].modelo,c[i].anoFab, c[i].cor, c[i].precoCarro);
			
			encontrou = 1;
		}
	}
	if(!encontrou)
		printf("\nA busca não retornou resultados!");
}

void pesquisaLivre(CAR c[50], int vet)
{
	char buscaMarca[20], buscaModelo[20], buscaCor[20], buscaTipoDirecao[20], encontrou = 0;
	int buscaAnoFab, buscaKm, buscaQtdPortas;
	float buscaPrecoCarro;
		
		printf("\nPesquisa livre");
		fflush(stdin);
		printf("\n\nMarca do carro: ");
		gets(buscaMarca);
		
		fflush(stdin);
		printf("Modelo: ");
		gets(buscaModelo);
		
		fflush(stdin);
		printf("Cor do carro: ");
		gets(buscaCor);
		
		printf("Ano de fabricação: ");
	    scanf("%d", &buscaAnoFab);	
		
		printf("Km rodados: ");
		scanf("%d", &buscaKm);
		
		fflush(stdin);
		printf("Tipo de direção: ");
		gets(buscaTipoDirecao);
		
		printf("Quantidade de portas: ");
		scanf("%d", &buscaQtdPortas);	
		
		printf("Valor do carro: ");
		scanf("%f", &buscaPrecoCarro);
		
		for(int i = 0; i < vet; i++ )
		{
			if((strcmp(c[i].marca, buscaMarca) == 0) && (strcmp(c[i].modelo, buscaModelo) == 0) && 
			(strcmp(c[i].cor, buscaCor) == 0) && (c[i].anoFab <= buscaAnoFab) && (c[i].km <= buscaKm) && 
			(strcmp(c[i].tipoDirecao, buscaTipoDirecao) == 0) && (c[i].qtdPortas <= buscaQtdPortas) && 
			(c[i].precoCarro <= buscaPrecoCarro))
			{
				printf("\nMarca: %s \nModelo: %s \nCor: %s \nAno: %d \nKm rodados: %d \nDireção: %s \nNº de portas: %d \nValor: %.2f\n", 
				c[i].marca, c[i].modelo, c[i].cor, c[i].anoFab, c[i].km, c[i].tipoDirecao, c[i].qtdPortas, c[i].precoCarro);
				
				encontrou = 1;	
			}
		}
		if(!encontrou)
			printf("\nA busca não retornou resultados!");
}

int main()
{
	setlocale(LC_ALL, "");
	CAR c[50];
	int vet = 0, opcao;
	
	printf("Bem vindo ao sistema de cadastro e consulta de carros!\n");
	do
	{
		printf("\nSelecione a operação que deseja realizar:");
		
		printf("\n1 - Cadastrar novo carro");
		printf("\n2 - Pesquisar por faixa de preço");
		printf("\n3 - Pesquisar por modelo");
		printf("\n4 - Pesquisar por KM rodados");
		printf("\n5 - Pesquisa por ano, cor e valor");
		printf("\n6 - Pesquisa livre");
		printf("\n7 - Sair");
		fflush(stdin);
		printf("\nOpção: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1: vet = CadCarro(c, vet);
			break;
			
			case 2: pesquisarFaixaPreco(c, vet);
			break;
		
			case 3: pesquisarModelo(c, vet);
			break;
		
			case 4: pesquisarKm(c, vet); 
			break;
		
			case 5: pesquisaAnoCorValor(c, vet);
			break;
			
			case 6: pesquisaLivre(c, vet);
			break;
			
			default:
			break;
		}
	}while(opcao != 7);
	
	if(opcao == 7)
		printf("\nSistema encerrado.\n");
	
	
}