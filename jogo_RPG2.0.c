#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct atributos
{
	float forca;
	float constituicao;
	float agilidade;
	float destreza;
} ATRIBUTO;

typedef struct armadura
{
	char nome[20];
	float defesa;
} ARMADURA;

typedef struct arma
{
	char nome[20];
	float dano;
	int categoria;
} ARMA;

typedef struct magia
{
	char nome[20];
	float dano;
	int categoria;
} MAGIA;

typedef struct equipamentos
{
	ARMA arma;
	ARMADURA armadura;
} EQUIPAMENTO;

typedef struct personagem
{
	char nome[50];
	float pv;
	EQUIPAMENTO equipamento;
	ATRIBUTO atributo;
 	MAGIA magia;
} PERSONAGEM;

typedef struct inimigo
{
	char nome[20];
	float pv;
	float dano;
	float defesa;
	float agilidade;
} IN;

IN ini1 = {"Martin Klebba", 10, 10, 3, 5};
IN ini2 = {"THE ROCK REBAIXADO", 20, 10, 5, 2};
IN ini3 = {"GIMLI", 11, 12, 2, 4};
IN ini4 = {"CARECADOIDO", 20, 18, 8, 1};
IN ini5 = {"ASPIRANTE",15, 19, 10, 7};
IN ini6 = {"vin diesel", 25, 25, 10, 9};

IN inimigo;
ARMA arma;
PERSONAGEM personagem;

void dano_arma();
void ataque();
void defender();
void pocao();
void pontos_vida();
void premiacao_nivel_1();
void premiacao_nivel_2();
void premiacao_arma_1();

int main()
{
	srand(time(NULL));
	int opc, voltar, escolha, inicio = 1;
	int inialeatorio, i = 0, j = 0;
	int escolha_premiacao_1, escolha_premiacao_2;
	float pontos;
	int escolha_primeira_arma, escolha_armadura, pa, p;
	while(inicio == 1)
	{
		printf("-------------------\n------- MENU ------\n-------------------\n");
		printf("Digite opcao 1, 2 ou 3:\n");
		printf("1- Comecar o jogo.\n2- Contar a historia.\n3- Fechar o jogo.\n");
		scanf("%d", &opc);
	
		switch(opc)
		{
			case 1:
				system("cls");
				printf("Digite o nome do seu personagem: ");
				fflush(stdin);
				gets(personagem.nome);
	
				do
				{
				printf("Voce tem 20 pontos para distribuir entre os atributos:\nFORCA\tCONSTITUICAO\tAGILIDADE\tDESTREZA\n\n");
	
					printf("FORCA: ");
					scanf("%f", &personagem.atributo.forca);
					printf("CONSTITUICAO: ");
					scanf("%f", &personagem.atributo.constituicao);
					printf("AGILIDADE: ");
					scanf("%f", &personagem.atributo.agilidade);
					printf("DESTREZA: ");
					scanf("%f", &personagem.atributo.destreza);
					pontos = personagem.atributo.agilidade + personagem.atributo.constituicao + personagem.atributo.destreza + personagem.atributo.forca;
					if(pontos > 20 || pontos < 20)
					{
						printf("Voce so tem 20 pontos para distribuir, Distribua os pontos dos atributos novamente.\n\n");
						system("pause");
						system("cls");
					}
				}
				while(pontos != 20);
				personagem.pv = 0;
	
				pontos_vida(&personagem.atributo.constituicao, &personagem.pv);
				printf("Pontos de vida: %.f\n\n", personagem.pv);
				
				do
				{
					printf("A hora de escolher a sua arma e comecar a sua jornada chegou...\n");
					printf("Voce tem tres opcoes de armas: \n1.Rapieira: Arma leve\n2.Claymore: Arma media\n3.Machado: Arma pesada\n\nDigite respectivamente 1,2 ou 3: ");
					scanf("%i",&escolha_primeira_arma);
		
					if(escolha_primeira_arma == 1)
					{
						strcpy(personagem.equipamento.arma.nome, "Rapieira");
						personagem.equipamento.arma.categoria = 1;
						arma = personagem.equipamento.arma;
					}
					else if(escolha_primeira_arma == 2)
					{
						strcpy(personagem.equipamento.arma.nome, "Claymore");
						personagem.equipamento.arma.categoria = 1;
						arma = personagem.equipamento.arma;
					}
					else if(escolha_primeira_arma == 3)
					{
						strcpy(personagem.equipamento.arma.nome, "Machado");
						personagem.equipamento.arma.categoria = 2;
						arma = personagem.equipamento.arma;
					}
					else
					{
						printf("Resposta invalida\n\n");
						system("pause");
					}
				}while(escolha_primeira_arma > 3 || escolha_primeira_arma < 1);
				
				do
				{
					printf("\nMomento de escolher a armadura\n");
					printf("Escolha uma das 3 opcoes:\n1-cota-malha\n2- Armadura de ferro\n3- Colete\n\nDigite respectivamente 1,2 ou 3: ");
					scanf("%i", &escolha_armadura);
		
					if(escolha_armadura == 1)
					{
						strcpy(personagem.equipamento.armadura.nome, "cota-malha");
						personagem.equipamento.armadura.defesa = 2 + 1.5*personagem.atributo.constituicao;
					}
					else if(escolha_armadura == 2)
					{
						strcpy(personagem.equipamento.armadura.nome, "Armadura de ferro");
						personagem.equipamento.armadura.defesa = 3 + 1.5*personagem.atributo.constituicao;
					}
					else if(escolha_armadura == 3)
					{
						strcpy(personagem.equipamento.armadura.nome, "Colete");
						personagem.equipamento.armadura.defesa = 4 + 1.5*personagem.atributo.constituicao;
					} 
					else
					{
						printf("Resposta invalida\n\n");
						system("pause");
					}
				}while(escolha_armadura > 3 || escolha_armadura < 1);
	
				//printf("\n\n%s, %.1f\n\n", personagem.equipamento.armadura.nome, personagem.equipamento.armadura.defesa);
				
				//combate 1
				pa = 0;
				p = 0;
				system("pause");
				system("cls");
				printf("PRIMEIRO COMBATE\n");
				inialeatorio = rand() % 3 + 1;
				switch(inialeatorio)
				{
					case 1:
						inimigo = ini1;
						break;
					case 2:
						inimigo = ini2;
						break;
					case 3:
					inimigo = ini3;
						break;
				}
				while(personagem.pv > 0 && inimigo.pv > 0)
				{
					dano_arma(&arma.categoria, &arma.dano, &personagem.atributo.forca, &personagem.atributo.destreza);
					
					if(personagem.atributo.agilidade > inimigo.agilidade)
					{
						//turno personagem
						do
						{
							voltar = 0;
							if(i == 1)
							{
								personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
								i = 0;
							}
							
							printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n4- USAR MAGIA\n");
							scanf("%d", &escolha);
							switch(escolha)
							{
								
								case 1:
									ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu ataque\n", personagem.nome);
									printf("Ponto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);
									system("color F");	
									break;
								case 2:
									defender(&personagem.equipamento.armadura.defesa);
									printf("%s escolheu defender\n", personagem.nome);
									printf("Valor da defesa por um round: %f\n\n", personagem.equipamento.armadura.defesa);
								 system("color F");
									i++;
									break;
								case 3:
									if(pa < 3)
									{
										pocao(&personagem.pv);
										printf("%s escolheu usar pocao\n", personagem.nome);
										printf("Ponto de vida de %s: %f\n", personagem.nome, personagem.pv);
									system("color F");
										pa++;
									}
									else
									{
										voltar = 1;
										printf("Pocao ja foi usada 3 vezes, escolha outra acao\n");
									}
									break;	
								default:
									printf("Resposta invalida\n\n");
									system("pause");
									break;
                                  case 4:
                                  ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu usar magia\n voce lanca uma bola de fogo", personagem.nome);
									printf("\nPonto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);
									system("color F");	
									break;
									
							}
						}
						while(escolha > 4 || escolha < 1 || voltar == 1);
										
						//turno oponente
						if(p < 3)
						{
							escolha = rand() % 3 + 1;
						}
						else
						{
							escolha = rand() % 2 + 1;
						}
				
						if(j == 1)
						{
							inimigo.defesa = inimigo.defesa / 2;
							j = 0;
						}
						switch(escolha)
						{
							case 1:
								ataque(&inimigo.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
								printf("%s escolheu ataque\n", inimigo.nome);
								system("color 4");
								break;
							case 2:
								defender(&inimigo.defesa);
								printf("%s escolheu defender\n", inimigo.nome);
								system("color 4");
								j++;
								break;
							case 3:
								pocao(&inimigo.pv);
								printf("%s escolheu usar pocao\n", inimigo.nome);
								system("color 4");
								p++;
								break;	
						}	
					}
					else
					{
						//turno oponente
						if(p < 3){
							escolha = rand() % 3 + 1;
						}else{
							escolha = rand() % 2 + 1;
						}
						if(j == 1)
						{
							inimigo.defesa = inimigo.defesa / 2;
							j = 0;
						}
						switch(escolha)
						{
							case 1:
								ataque(&inimigo.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
								printf("%s escolheu ataque\n", inimigo.nome);
								system("color 4");
								break;
							case 2:
								defender(&inimigo.defesa);
								printf("%s escolheu defender\n", inimigo.nome);
								system("color 4");
								j++;
								break;
							case 3:
								pocao(&inimigo.pv);
								printf("%s escolheu usar pocao\n", inimigo.nome);
								system("color 4");
								p++;
								break;	
						}
						//turno personagem
						do
						{
							voltar = 0;
							printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n");
							scanf("%d", &escolha);
							
							if(i == 1)
							{
								personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
								i = 0;
							}
							switch(escolha)
							{
								case 1:
									ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu ataque\n", personagem.nome);
									printf("Ponto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);							
									system("color F");
									break;   
								case 2:							
									defender(&personagem.equipamento.armadura.defesa);
									printf("%s escolheu defender\n", personagem.nome);
									printf("Valor da defesa por um round: %f\n\n", personagem.equipamento.armadura.defesa);
								system("color F");
									i++;
									break;
								case 3:
									if(pa < 3){
										pocao(&personagem.pv);
										printf("%s escolheu usar pocao\n", personagem.nome);
										printf("Ponto de vida de %s: %f\n", personagem.nome, personagem.pv);
									system("color F");
										pa++;
									}else{
										voltar = 1;
										printf("Pocao ja foi usada 3 vezes, escolha outra acao\n");
									}
									break;	
								default:
									printf("Resposta invalida\n\n");
									system("color F");
									system("pause");
									break;
							}
						}
						while(escolha > 3 || escolha < 1 || pa > 3);
					}
				
				}
				if(personagem.pv <= 0)
				{
					system("cls");
					printf("-------------------\n----GAME OVER---\n-------------------\n\n");
					system("pause");
					system("cls");
					system("color F");
					break;
				}
				do
				{
					system("pause");
					system("color F");
					system("cls");
					printf("Voce conseguiu vencer ao primeiro combate, agora eh a hora de escolher a recompensa:\n\n1.SUBIR 1 NIVEL,voce ganha mais 5 pontos de atributos.\n2.Mais vida.\n3.Arma nova.");
					scanf("%i",&escolha_premiacao_1);
				
					if(escolha_premiacao_1 == 1)
					{
						premiacao_nivel_1(&personagem.atributo.forca, &personagem.atributo.constituicao, &personagem.atributo.agilidade, &personagem.atributo.destreza);
					}
					else if(escolha_premiacao_1 == 2)
					{
						personagem.pv = personagem.pv + personagem.atributo.constituicao;	
					}
					else if(escolha_premiacao_1 == 3)
					{	
						do
						{
							printf("\nVoce tem 3 opcoes de armas melhores para escolher:\n");
							printf("Voce tem tres opcoes de armas: \n1.martelo do chapolin: Arma leve\n2.lamina oculta: Arma leve\n3.foice do hidan: Arma pesada\n\nDigite respectivamente 1,2 ou 3: ");
							scanf("%i",&escolha);
						
							if(escolha == 1)
							{
								strcpy(personagem.equipamento.arma.nome, "martelo do chapolin");
								personagem.equipamento.arma.categoria = 1;
								arma = personagem.equipamento.arma;
							}
							else if(escolha == 2)
							{
								strcpy(personagem.equipamento.arma.nome, "lamina oculta");
								personagem.equipamento.arma.categoria = 1;
								arma = personagem.equipamento.arma;
							}
							else if(escolha == 3)
							{
								strcpy(personagem.equipamento.arma.nome, "foice do hidan");
								personagem.equipamento.arma.categoria = 2;
								arma = personagem.equipamento.arma;
							}
							else
							{
							printf("Resposta invalida,tente novamente.\n\n");
							system("pause");
							}
						}while(escolha > 3 || escolha < 1);
					}
					else
					{
						printf("Resposta invalida,tente novamente.\n\n");
						system("pause");
					}
				}while(escolha_premiacao_1 < 1 || escolha_premiacao_1 > 3);
				
				//combate 2
				pa = 0;
				p = 0;
				system("pause");
				system("cls");
				printf("SEGUNDO COMBATE\n");
				
				inialeatorio = rand() % 2 + 1;
				switch(inialeatorio)
				{
					case 1:
						inimigo = ini4;
						break;
					case 2:
						inimigo = ini5;
						break;
				}
				while(personagem.pv > 0 && inimigo.pv > 0)
				{
					dano_arma(&arma.categoria, &arma.dano, &personagem.atributo.forca, &personagem.atributo.destreza);
					if(escolha_premiacao_1 == 3){
						arma.dano += 4;
					}
										
					if(personagem.atributo.agilidade > inimigo.agilidade)
					{
						//turno personagem
						do
						{
							voltar = 0;
							if(i == 1)
							{
								personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
								i = 0;
							}
							printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n4- USAR MAGIA\n");
							scanf("%d", &escolha);
							switch(escolha)
							{
								case 1:
									ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu ataque\n", personagem.nome);
									printf("Ponto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);	
									system("color F");
									break;
								case 2:
									defender(&personagem.equipamento.armadura.defesa);
									printf("%s escolheu defender\n", personagem.nome);
									printf("Valor da defesa por um round: %f\n\n", personagem.equipamento.armadura.defesa);
									i++;
									system("color F");
									break;
								case 3:
									if(pa < 3)
									{
										pocao(&personagem.pv);
										printf("%s escolheu usar pocao\n", personagem.nome);
										printf("Ponto de vida de %s: %f\n", personagem.nome, personagem.pv);
										system("color F");
										pa++;
									}
									else
									{
										voltar = 1;
										printf("Pocao ja foi usada 3 vezes, escolha outra acao\n");
								system("color F");
							}
									break;	
								default:
									printf("Resposta invalida\n\n");
									system("pause");
								system("color F");
									break;
								case 4:
                                  ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu usar magia\n voce lanca uma bola de fogo", personagem.nome);
									printf("\nPonto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);
									system("color F");	
									break;
									
							}
						}
						while(escolha > 4 || escolha < 1 || voltar == 1);
											
						//turno oponente
						if(p < 3)
						{
							escolha = rand() % 3 + 1;
						}
						else
						{
							escolha = rand() % 2 + 1;
						}
				
						if(j == 1)
						{
							inimigo.defesa = inimigo.defesa / 2;
							j = 0;
						}
						switch(escolha)
						{
							case 1:
								ataque(&inimigo.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
								printf("%s escolheu ataque\n", inimigo.nome);
								system("color 4");
								break;
							case 2:
								defender(&inimigo.defesa);
								printf("%s escolheu defender\n", inimigo.nome);
                           system("color 4");
							j++;
								break;
							case 3:
								pocao(&inimigo.pv);
								printf("%s escolheu usar pocao\n", inimigo.nome);
								system("color 4");
								p++;
								break;	
						}
						
					}
					else
					{
						//turno oponente
						if(p < 3)
						{
							escolha = rand() % 3 + 1;
						}
						else
						{
							escolha = rand() % 2 + 1;
						}
						if(j == 1)
						{
							inimigo.defesa = inimigo.defesa / 2;
							j = 0;
						}
						switch(escolha)
						{
							case 1:
								ataque(&inimigo.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
								printf("%s escolheu ataque\n", inimigo.nome);
								system("color 4");
								break;
							case 2:
								defender(&inimigo.defesa);
								printf("%s escolheu defender\n", inimigo.nome);
								system("color 4");
								j++;
								break;
							case 3:
								pocao(&inimigo.pv);
								printf("%s escolheu usar pocao\n", inimigo.nome);
								system("color 4");
								p++;
								break;	
						}
						//turno personagem
						do
						{
							voltar = 0;
							printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n");
							scanf("%d", &escolha);
							
							if(i == 1)
							{
								personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
								i = 0;
							}
							switch(escolha)
							{
								case 1:
									ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu ataque\n", personagem.nome);
									printf("Ponto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);							
								system("color F");
									break;   
								case 2:							
									defender(&personagem.equipamento.armadura.defesa);
									printf("%s escolheu defender\n", personagem.nome);
									printf("Valor da defesa por um round: %f\n", personagem.equipamento.armadura.defesa);
									system("color F");
									i++;
									break;
								case 3:
									if(pa < 3)
									{
										pocao(&personagem.pv);
										printf("%s escolheu usar pocao\n", personagem.nome);
										printf("Ponto de vida de %s: %f\n", personagem.nome, personagem.pv);
									system("color F");
										pa++;
									}
									else
									{
										voltar = 1;
										printf("Pocao ja foi usada 3 vezes, escolha outra acao\n");
									}
									break;	
								default:
									printf("Resposta invalida\n\n");
									system("pause");
									break;
							}
						}
						while(escolha > 3 || escolha < 1 || voltar == 1);
					}
				}
				
				if(personagem.pv <= 0)
				{
					system("color F");
					system("cls");
					printf("-------------------\n----GAME OVER---\n-------------------\n\n");
					system("pause");
					system("cls");
					
					break;
				}
				
				do
				{
					system("color F");
					system("pause");
					system("cls");
					printf("Voce conseguiu vencer ao segundo combate,agora eh a hora de escolher a recompensa:\n\n1.SUBIR 2 NIVEIS,voce ganha mais 10 pontos de atributos.\n2.Mais vida.\n3.Armadura nova.");
					scanf("%i",&escolha_premiacao_2);
				
					if(escolha_premiacao_2 == 1)
					{
						premiacao_nivel_2(&personagem.atributo.forca, &personagem.atributo.constituicao, &personagem.atributo.agilidade, &personagem.atributo.destreza);
					}
					else if(escolha_premiacao_2 == 2)
					{
						personagem.pv = personagem.pv + personagem.atributo.constituicao;	
					}
					else if(escolha_premiacao_2 == 3)
					{
						do
						{	
							system("color F");
							printf("\nVoce tem 3 opcoes de armaduras melhores para escolher:\n");
							printf("\n1.armadura espectral\n2.armadura assasina\n3. Armadura das Valquirias\n\ndigite respectivamente 1,2 ou 3: ");
							scanf("%i",&escolha_armadura);
						
							if(escolha_armadura == 1)
							{
								strcpy(personagem.equipamento.armadura.nome, "armadura espectral");
								personagem.equipamento.armadura.defesa = 5 + 1.5*personagem.atributo.constituicao;
							}
							else if(escolha_armadura == 2)
							{
								strcpy(personagem.equipamento.armadura.nome, "armadura assasina");
								personagem.equipamento.armadura.defesa = 6 + 1.5*personagem.atributo.constituicao;
							}
							else if(escolha_armadura == 3)
							{
								strcpy(personagem.equipamento.armadura.nome, "Armadura das Valquírias");
								personagem.equipamento.armadura.defesa = 7 + 1.5*personagem.atributo.constituicao;
							} 		
							else
							{
								printf("Resposta invalida\n\n");
								system("pause");
							}
						}while(escolha_armadura > 3 || escolha_armadura < 1);
					}
					else
					{
						printf("Resposta invalida,tente novamente.\n\n");
						system("pause");
					}
				}while(escolha_premiacao_2 < 1 || escolha_premiacao_2 > 3);
				
				//combate 3
				pa = 0;
				p = 0;
				system("pause");
				system("cls");
				printf("TERCEIRO COMBATE\n");
				
				inimigo = ini6;
					
				while(personagem.pv > 0 && inimigo.pv > 0)
				{
					dano_arma(&arma.categoria, &arma.dano, &personagem.atributo.forca, &personagem.atributo.destreza);
										
					if(personagem.atributo.agilidade > inimigo.agilidade)
					{
						//turno personagem
						do
						{
							voltar = 0;
							if(i == 1)
							{
								personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
								i = 0;
							}
							printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n4- USAR MAGIA");
							scanf("%d", &escolha);
							switch(escolha)
							{
								case 1:
									ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu ataque\n", personagem.nome);
									printf("Ponto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);	
								system("color F");
									break;
								case 2:
									defender(&personagem.equipamento.armadura.defesa);
									printf("%s escolheu defender\n", personagem.nome);
									printf("Valor da defesa por um round: %f\n", personagem.equipamento.armadura.defesa);
									i++;
									system("color F");
									break;
								case 3:
									if(pa < 3)
									{
										pocao(&personagem.pv);
										printf("%s escolheu usar pocao\n", personagem.nome);
										printf("Ponto de vida de %s: %f\n", personagem.nome, personagem.pv);
										system("color F");
										pa++;
									}
									else
									{
										printf("Pocao ja foi usada 3 vezes, escolha outra acao\n");
									system("color F");
										voltar = 1;
									}
									break;	
								default:
									printf("Resposta invalida\n\n");
									system("pause");
								system("color F");
									break;
									case 4:
                                  ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu usar magia\n voce lanca uma bola de fogo", personagem.nome);
									printf("\nPonto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);
									system("color F");	
									break;
							}
						}
						while(escolha > 4 || escolha < 1 || voltar == 1);
											
						//turno oponente
						if(p < 3)
						{
							escolha = rand() % 3 + 1;
						}
						else
						{
							escolha = rand() % 2 + 1;
						}
				
						if(j == 1)
						{
							inimigo.defesa = inimigo.defesa / 2;
							j = 0;
						}
						switch(escolha)
						{
							case 1:
								ataque(&inimigo.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
								printf("%s escolheu ataque\n", inimigo.nome);
								break;
							case 2:
								defender(&inimigo.defesa);
								printf("%s escolheu defender\n", inimigo.nome);
								j++;
								break;
							case 3:
								pocao(&inimigo.pv);
								printf("%s escolheu usar pocao\n", inimigo.nome);
								p++;
								break;	
						}
						
					}
					else
					{
						//turno oponente
						if(p < 3)
						{
							escolha = rand() % 3 + 1;
						}
						else
						{
							escolha = rand() % 2 + 1;
						}
						if(j == 1)
						{
							inimigo.defesa = inimigo.defesa / 2;
							j = 0;
						}
						switch(escolha)
						{
							case 1:
								ataque(&inimigo.dano, &personagem.equipamento.armadura.defesa, &personagem.pv);
								printf("%s escolheu ataque\n", inimigo.nome);
							system("color 4");
								break;
							case 2:
								defender(&inimigo.defesa);
								printf("%s escolheu defender\n", inimigo.nome);
								j++;
							system("color 4");
								break;
							case 3:
								pocao(&inimigo.pv);
								printf("%s escolheu usar pocao\n", inimigo.nome);
								p++;
								system("color 4");
								break;	
						}
						//turno personagem
						do
						{
							voltar = 0;
							printf("\nEscolha a sua acao:\n1- ATACAR\n2- DEFENDER\n3- USAR POCAO\n");
							scanf("%d", &escolha);
							
							if(i == 1)
							{
								personagem.equipamento.armadura.defesa = personagem.equipamento.armadura.defesa / 2;
								i = 0;
							}
							switch(escolha)
							{
								case 1:
									ataque(&arma.dano, &inimigo.defesa, &inimigo.pv);
									printf("%s escolheu ataque\n", personagem.nome);
									printf("Ponto de vida de %s: %f\nPonto de vida do inimigo %s: %f\n\n", personagem.nome, personagem.pv, inimigo.nome, inimigo.pv);							
								system("color F");
									break;   
								case 2:							
									defender(&personagem.equipamento.armadura.defesa);
									printf("%s escolheu defender\n", personagem.nome);
									printf("Valor da defesa por um round: %f\n", personagem.equipamento.armadura.defesa);
									i++;
									system("color F");
									break;
								case 3:
									if(pa < 3)
									{
										pocao(&personagem.pv);
										printf("%s escolheu usar pocao\n", personagem.nome);
										printf("Ponto de vida de %s: %f\n", personagem.nome, personagem.pv);
										system("color F");
										pa++;
									}
									else
									{
										printf("Pocao ja foi usada 3 vezes, escolha outra acao\n");
										voltar = 1;
									}
									break;	
								default:
									printf("Resposta invalida\n\n");
									system("pause");
									break;
							}
						}
						while(escolha > 3 || escolha < 1 || voltar == 1);
					}
				}
				
				if(personagem.pv <= 0)
				{
					system("color F");
					system("pause");
					system("cls");
					printf("-------------------\n----GAME OVER---\n-------------------\n\n");
					system("pause");
					system("cls");
					break;
				}
				system("color F");
				system("pause");
				system("cls");
				printf("-------------------\n--VOCE VENCEU--\n-------------------\n\n");
				printf("parabens! Voces derrotou todos os inimigos da tarvena \n");
				system("pause");
				system("cls");
			
				break;
	
			case 2:
				printf("Voce vai a uma taverna para beber no seu dia folga, quando de repente uma briga comeca e todo mundo do local comeca a brigar tambem.Voce, ainda sobrio e incomodado com a situacao, tenta apaziguar a briga, porem, voce esbarra em uma gangue e eles partem pra cima de voce querendo brigar.\n\n ");
				system("pause");
				system("cls");	
				break;
	
			case 3:
				printf("Obrigado por jogar nossa aventura ate a proxima, Encerrando o Game...");
				inicio = 0;
				break;
	
			default:
				printf("Valor invalido\n\n");
				system("pause");
				system("cls");	
		}
	
	}
	return 0;
}

void premiacao_nivel_2(float* forca, float* consti, float* agilit, float* destre)
{
	float f,c,a,d,pontos = 0;
	while(pontos != 10)
	{
		printf("vc tem 10 pontos de atributos para serem distribuidos.\n");
		printf("FORCA: ");
		scanf("%f", &f);
		printf("CONSTITUICAO: ");
		scanf("%f", &c);
		printf("AGILIDADE: ");
		scanf("%f", &a);
		printf("DESTREZA: ");
		scanf("%f", &d);
		pontos = f + c + a + d;
		if(pontos > 10 || pontos < 10)
		{
			printf("Distribua os pontos dos atributos novamente.\n\n");
			system("pause");
			system("cls");
		}
	}		
	*forca = *forca + f;
	*consti = *consti + c;
	*agilit = *agilit + a;
	*destre = *destre  + d;
}

void premiacao_nivel_1(float* forca, float* consti, float* agilit, float* destre)
{
	float f,c,a,d,pontos;
	
	while(pontos != 5)
{
		printf("vc tem 5 pontos de atributos para serem distribuidos.\n");
		printf("FORCA: ");
		scanf("%f", &f);
		printf("CONSTITUICAO: ");
		scanf("%f", &c);
		printf("AGILIDADE: ");
		scanf("%f", &a);
		printf("DESTREZA: ");
		scanf("%f", &d);
		pontos = f + c + a + d;
		if(pontos > 5 || pontos < 5)
		{
			printf("Distribua os pontos dos atributos novamente.\n\n");
			system("pause");
			system("cls");
		}
	}		
	*forca = *forca + f;
	*consti = *consti + c;
	*agilit = *agilit + a;
	*destre = *destre  + d;
}

void dano_arma(int *categoria, float *dano, float *forca, float *destre)
{
	srand(time(NULL));
	float dado_4 = rand() % 4 + 1, dado1_6 = rand() % 6 + 1, dado2_6 = rand() % 6 + 1, dado_12 = rand() % 12 + 1;
	if(*categoria == 2)
	{
		*dano = dado_12 + *forca * 1.5 + 7;
	}
	else if(*categoria == 1)
	{
		*dano = dado1_6 + dado2_6 + dado_4 + *destre + 3;
		
	}
}

void pontos_vida(float* consta, float* pv)
{
	srand(time(NULL));
	float dado_1 = rand() % 6 + 1, dado_2 = rand() % 6 + 1 , dado_3 = rand() % 6 + 1;
	
	*pv =  dado_1 + dado_2 + dado_3 + (*consta);
}

void ataque(float *arma_jogador, float *armadura_oponente, float *pv_oponente)
{                                                          
	float dano;
	dano = *arma_jogador - *armadura_oponente;

	*pv_oponente = *pv_oponente - dano;	
}

void defender(float *defesa)
{
	*defesa = 2 * *defesa;
}

void pocao(float *pv)
{
	srand(time(NULL));
	int dado_1 = rand() % 6 + 1, dado_2 = rand() % 6 + 1 , dado_3 = rand() % 6 + 1;
	*pv = *pv + dado_1 + dado_2 + dado_3;
}

