#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

//Dados do jogador
typedef struct jogador{

	//status básico
	char nome[50];
	int pv;
	int forca;
	int constituicao;
	int agilidade;
	int destreza;
	int arma;
	int armadura;
	int nivel;

}Jogador;

Jogador jogador;

//Dados do inimigo
typedef struct inimigo{

	//nivel 1=a
	char nomea;
	int agia;
	int danoa;
	int pva;
	int defesaa;

	//nivel 2=b
	char nomeb;
	int agib;
	int danob;
	int pvb;
	int defesab;

	//nivel 3=c
	char nomec;
	int agic;
	int danoc;
	int pvc;
	int defesac;


}Inimigo;

Inimigo  inimigo;

//funçao cadastro inimigo
void CadastroInimigo(){

	//nivel 1
    inimigo.agia= 1;
    inimigo.danoa= 3;
     inimigo.defesaa= 1;
     inimigo.pva= 100;

	//nivel 2
     inimigo.agib= 3;
     inimigo.danob= 5;
     inimigo.defesab=2;
     inimigo.pvb= 150;

    //nivel 3
     inimigo.agic= 5;
     inimigo.danoc= 8;
     inimigo.defesac=3;
    inimigo.pvc= 200;

}

//Função linha de asterisco
char Linha()
{
	int k;
	for(k = 0; k < 20; k++)
		printf("*");
}


//função arma
void Equipamentos(){
	setlocale(LC_ALL, "Portuguese");

	char opc2;//para selecionar arma
	char opc3;//para selecionar armadura
	int d12 = rand( ) %13+1;
	int d4 = rand( ) %5+1;
	int d42 = rand( ) %5+1;
	int d6 = rand( ) %7+1;

	printf("\t* Arma *\n");

	printf("A) Rapieira(leve)     B) Claymore(pesada)     C) Machado(pesada)\n");
    printf("   ATQ: 5               ATQ:  8                  ATQ: 10 \n");
    printf("   AGL: +2               AGL: -1                   AGL: +1  \n");

	printf("\nESCOLHA: ");
	scanf("%s", &opc2);
	switch (opc2){

		case 'a':
		case 'A':
		case 'b':
		case 'B':

	        jogador.arma = 10+jogador.destreza+d6+d4+d42;
		    break;

		case 'c':
		case 'C':
	
		

			jogador.arma= 15+(1.5*jogador.forca)+d12;
			break;


			default:
				printf("Invalido, tente novamente");
				break;
	}
	printf("\n");

	Linha();

	printf("\n\t* Armadura *\n");

	printf("A) Armadura cota-malha    B) Armadura de ferro\n"); 
    printf("   DEF: 1                 DEF: 2  \n");
    printf("   AGL: +2                AGL: 0 \n");

	printf("\nESCOLHA: ");
	scanf("%s", &opc3);

	switch(opc3){

		case 'a':
        case 'A':

        	jogador.armadura= 2+jogador.constituicao;
        	break;

        case 'b' :
  	    case 'B' :

  	    	jogador.armadura= 3+jogador.constituicao;
  	    	break;

  	    default:
				printf("Invalido, tente novamente");
				break;	
	}

}
//Função Cadastro do jogador
void Cadastrojogador(){

	system("cls");

	Linha();

	printf("\n\t* Status Basico *\n");

	printf("Informe seu nome: ");
	scanf("%s", &jogador.nome);
	fflush(stdin);

	printf("\n");

    Linha();

    printf("\n\t* Atributos *\n");

    printf("Nota: ");
    printf("A soma dos atributos deve ser igual a 20 pontos\n");

    printf("Informe a forca: ");
    scanf("%d", &jogador.forca);

    printf("Informe a constiticao: ");
    scanf("%d", &jogador.constituicao);

    printf("Informe a agilidade: ");
    scanf("%d", &jogador.agilidade);

    printf("Informe a destreza: ");
    scanf("%d", &jogador.destreza);

    Linha();

    printf("\n");

    Equipamentos();

    printf("\n");

    system("cls");

}


//função level up

void Nivel(){

	printf("Parabens! voce completou o desefio e subiu de nível!\n");

	jogador.nivel= jogador.nivel+1;

	printf("* Nivel %d *", jogador.nivel);

	jogador.pv= jogador.pv + jogador.constituicao;

	printf("Aqui esta o seu premio: %d pv", jogador.pv);

}

void EscolhaInimigo1(){
		setlocale(LC_ALL, "Portuguese");
	Inimigo inimigo;

	char escolha;
	printf("Escolha o seu inimigo: ");

	printf("\nA- Martin Klebba\t B-THE ROCK REBAIXADO\t C- GIMLI");

	printf("\nESCOLHA: ");
	scanf("%s", &escolha);

	switch(escolha){

		case 'a' :
		case 'A' :
			break;

		case 'b' :
		case 'B' :
			break;

		case 'c' :
		case 'C' :
			break;
			
	}
}

void EscolhaInimigo2(){
		setlocale(LC_ALL, "Portuguese");
	Inimigo inimigo;

	char escolha2;

	printf("Escolha o seu inimigo: ");

	printf("\nA- ASPIRANTE\t B- CARECADOIDO");

	printf("\nESCOLHA: ");
	scanf("%s", &escolha2);

	switch(escolha2){

		case 'a' :
		case 'A' :
		break;

		case 'b' :
		case 'B' :
		 break;

		    default:
		    	printf("invalido! ");

	}
}


void Turno1()
{
	Inimigo inimigo;

	Jogador jogador;

	jogador.pv = 20;

	int opcad;
	srand((unsigned)time(NULL)); 
	int opc;
	int dano;
	int danoj;
	int pocao=0;
	int v1,v2,v3;
	int defesao;
	int defesaj;
	int defender=0;
	int d1,d2;

	do
	{
		if(jogador.agilidade > inimigo.agia)
		{
			printf("Voce comeca\n");

			//turno jogador
			printf("0- Atacar\t1- Defender\t2-  Pocao\n");
			printf("\nESCOLHA: ");
			scanf("%d", &opc);

			switch(opc)
			{

			case 0 :

			danoj= jogador.forca- inimigo.defesaa;
			if(danoj > 0)
			{
				inimigo.pva= inimigo.pva;
			}

			else
			{
				inimigo.pva= inimigo.pva - danoj;
			}

			break;

			case 1 :

			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;

			case 2 :

			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;	

				if(defesao == 1)
				{
					inimigo.defesaa=inimigo.defesaa/2;
					defesao = 0;
				}
			default: 

			printf("Invalido\n");

			break;

			} //fim turno jogador


			//turno inimigo
			opcad= rand () %3;

			switch(opcad)
			{

				case 0 : 

				printf("Voce foi atacado!\n");
			    dano= inimigo.danoa- jogador.armadura;

			    if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}

				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;

				case 1 :

				printf("Inimigo usou escudo!\n");
				inimigo.defesaa= inimigo.defesaa*2;
				defesao = 1;
				inimigo.defesaa=inimigo.defesaa+rand()%6+rand()%6+rand()%6+2;
				break;

				case 2:
				printf("Inimigo se curou!\n");
				inimigo.pva=inimigo.pva+rand()%6+rand()%6+rand()%6+3;
				break;

				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}


			}//fim turno inimigo
		}

		else
		{
			printf("O inimigo começa\n");

			//turno inimigo
			opcad= rand () %3;

			switch(opcad)
			{

				case 0 : 

				printf("Voce foi atacado!\n");

				dano= inimigo.danoa- jogador.armadura;

				if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}

				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;

				case 1 :

				printf("Inimigo usou escudo!\n");
				inimigo.defesaa= inimigo.defesaa*2;
				defesao=1;
				inimigo.defesaa=inimigo.defesaa+rand()%6+rand()%6+rand()%6+2;
				break;

				case 2:
				printf("Inimigo se curou!\n");
				inimigo.pva=inimigo.pva+rand()%6+rand()%6+rand()%6+3;
				break;

				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}

			}//fim turno inimigo

			//turno jogador
			printf("0- Atacar\t1- Defender\t2-  Pocao\t");
			printf("\nESCOLHA: ");
			scanf("%d", &opc);

			switch(opc)
			{

			case 0 :

			danoj= jogador.forca- inimigo.defesaa;
			if(danoj < 0)
			{
				inimigo.pva= inimigo.pva;
			}

			else
			{
				inimigo.pva= inimigo.pva - danoj;
			}

			break;

			case 1 :

			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;

			case 2 :

			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;

			break;	
				if(defesao == 1)
				{
					inimigo.defesaa=inimigo.defesaa/2;
					defesao = 0;inimigo;
				}
			default: 

			printf("Invalido");

			break;
			} //fim turno jogador

		}

	} while(jogador.pv > 1 && inimigo.pva > 1);//fim do while

}//fim batalha 1

void Turno2()
{


	Inimigo inimigo;

	Jogador jogador;

	jogador.pv = 10;

	int opcad;
	srand((unsigned)time(NULL)); 
	int opc;
	int dano;
	int danoj;
	int pocao=0;
	int v1,v2,v3;
	int defesao;
	int defesaj;
	int defender=0;
	int d1,d2;

	do
	{
		if(jogador.agilidade >inimigo.agib)
		{
			printf("Voce comeca\n");

			//turno jogador
			printf("0- Atacar\t1- Defender\t2-  Pocao\n");
			printf("ESCOLHA: ");
			scanf("%d", &opc);

			switch(opc)
			{

			case 0 :

			danoj= jogador.forca- inimigo.defesab;
			if(danoj < 0)
			{
				inimigo.pvb= inimigo.pvb;
			}

			else
			{
				inimigo.pvb= inimigo.pvb - danoj;
			}

			break;

			case 1 :

			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;

			case 2 :

			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;	

				if(defesao == 1)
				{
					inimigo.defesab=inimigo.defesab/2;
					defesao = 0;
				}
			default: 

			printf("Invalido\n");

			break;

			} //fim turno jogador


			//turno inimigo
			opcad= rand () %3;

			switch(opcad)
			{

				case 0 : 

				printf("Voce foi atacado!\n");
			    dano= inimigo.danob- jogador.armadura;

			    if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}

				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;

				case 1 :

				printf("O inimigo usou escudo!\n");
				inimigo.defesab= inimigo.defesab*2;
				defesao = 1;
				inimigo.defesab=inimigo.defesab+rand()%6+rand()%6+rand()%6+2;
				break;

				case 2:
				printf("O inimigo se curou!\n");
				inimigo.pvb=inimigo.pvb+rand()%6+rand()%6+rand()%6+3;
				break;

				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}


			}//fim turno inimigo
		}

		else
		{
			printf("O inimigo começa\n");

			//turno inimigo
			opcad= rand () %3;

			switch(opcad)
			{

				case 0 : 

				printf("Voce foi atacado!\n");

				dano= inimigo.danob- jogador.armadura;

				if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}

				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;

				case 1 :

				printf("O inimigo usou escudo!\n");
				inimigo.defesab= inimigo.defesab*2;
				defesao=1;
				inimigo.defesab=inimigo.defesab+rand()%6+rand()%6+rand()%6+2;
				break;

				case 2:
				printf("O inimigo se curou!\n");
				inimigo.pvb=inimigo.pvb+rand()%6+rand()%6+rand()%6+3;
				break;

				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}

			}//fim turno inimigo

			//turno jogador
			printf("0- Atacar\t1- Defender\t2-  Pocao");
			printf("ESCOLHA: ");
			scanf("%d", &opc);

			switch(opc)
			{

			case 0 :

			danoj= jogador.forca-inimigo.defesab;
			if(danoj < 0)
			{
				inimigo.pvb= inimigo.pvb;
			}

			else
			{
				inimigo.pvb= inimigo.pvb - danoj;
			}

			break;

			case 1 :

			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;

			case 2 :

			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;

			break;	
				if(defesao == 1)
				{
					inimigo.defesab=inimigo.defesab/2;
					defesao = 0;
				}
			default: 

			printf("Invalido");

			break;
			} //fim turno jogador

		}

	} while(jogador.pv > 1 && inimigo.pvb > 1);//fim do while

}//fim batalha 5

void Turno3()
{


	Inimigo inimigo;

	Jogador jogador;

	jogador.pv = 10;

	int opcad;
	srand((unsigned)time(NULL)); 
	int opc;
	int dano;
	int danoj;
	int pocao=0;
	int v1,v2,v3;
	int defesao;
	int defesaj;
	int defender=0;
	int d1,d2;

	do
	{
		if(jogador.agilidade > inimigo.agic)
		{
			printf("Voce comeca\n");

			//turno jogador
			printf("0- Atacar\t1- Defender\t2-  Pocao\n");
			printf("ESCOLHA: ");
			scanf("%d", &opc);

			switch(opc)
			{

			case 0 :

			danoj= jogador.forca- inimigo.defesac;
			if(danoj < 0)
			{
				inimigo.pvc= inimigo.pvc;
			}

			else
			{
				inimigo.pvc= inimigo.pvc - danoj;
			}

			break;

			case 1 :

			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;

			case 2 :

			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;	

				if(defesao == 1)
				{
					inimigo.defesac=inimigo.defesac/2;
					defesao = 0;
				}
			default: 

			printf("Invalido\n");

			break;

			} //fim turno jogador


			//turno inimigo
			opcad= rand () %3;

			switch(opcad)
			{

				case 0 : 

				printf("Voce foi atacado!\n");
			    dano= inimigo.danoc- jogador.armadura;

			    if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}

				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;

				case 1 :

				printf("O inimigo usou escudo!\n");
				inimigo.defesac= inimigo.defesac*2;
				defesao = 1;
				inimigo.defesac=inimigo.defesac+rand()%6+rand()%6+rand()%6+2;
				break;

				case 2:
				printf("O inimigo se curou!\n");
				inimigo.pvc=inimigo.pvc+rand()%6+rand()%6+rand()%6+3;
				break;

				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}


			}//fim turno inimigo
		}

		else
		{
			printf("O inimigo começa\n");

			//turno inimigo
			opcad= rand () %3;

			switch(opcad)
			{

				case 0 : 

				printf("Voce foi atacado!\n");

				dano= inimigo.danob- jogador.armadura;

				if(dano < 0)
				{
					jogador.pv= jogador.pv;
				}

				else
				{
					jogador.pv= jogador.pv - dano;
				}
				break;

				case 1 :

				printf("O inimigo usou escudo!\n");
				inimigo.defesac= inimigo.defesac*2;
				defesao=1;
				inimigo.defesac=inimigo.defesac+rand()%6+rand()%6+rand()%6+2;
				break;

				case 2:
				printf("O inimigo se curou!\n");
				inimigo.pvc=inimigo.pvc+rand()%6+rand()%6+rand()%6+3;
				break;

				if(defesaj == 1)
				{
					jogador.armadura=jogador.armadura/2;
					defesaj = 0;
				}

			}//fim turno inimigo

			//turno jogador
			printf("0- Atacar\t1- Defender\t2-  Pocao");
			printf("ESCOLHA: ");
			scanf("%d", &opc);

			switch(opc)
			{

			case 0 :

			danoj= jogador.forca- inimigo.defesac;
			if(danoj < 0)
			{
				inimigo.pvc= inimigo.pvc;
			}

			else
			{
				inimigo.pvc= inimigo.pvc - danoj;
			}

			break;

			case 1 :

			jogador.armadura= jogador.armadura*2;
			defesaj=1;
			if(defender !=2){
				d1=rand()%6;
				d2=rand()%6;
				jogador.armadura=jogador.armadura+d1+d2+2;
				printf("Você defendeu!\n",d1+d2+2);
				defender++;
			} else 
			{
			 	  printf("Escudos esgotados!\n");	
			}
			break;

			case 2 :

			if(pocao != 3)
						{
							v1=rand()%6;
							v2=rand()%6;
							v3=rand()%6;
							jogador.pv=jogador.pv+v1+v2+v3+3;
							printf("Voce recuperou %i de PV\n", v1+v2+v3+3);
							pocao++;
						}else
						{
							printf("Droga, as pocoes esgotaram!\n");
						}
						break;

			break;	
				if(defesao == 1)
				{
					inimigo.defesac=inimigo.defesac/2;
					defesao = 0;
				}
			default: 

			printf("Invalido");

			break;
			} //fim turno jogador

		}

	} while(jogador.pv > 1 && inimigo.pvc > 1);//fim do while

}//fim batalha 6

void Batalhas()
{
	printf("* Desafio 1 *\n");

	EscolhaInimigo1();

	Turno1();
		if (jogador.forca > inimigo.pva)
	{
		Nivel();
		printf("\n");

		printf("* Desafio 2 *\n");
		EscolhaInimigo2();
		Turno2();

		if(jogador.pv > inimigo.pvb)
		{
			Nivel();
			printf("\n");

			printf("* Desafio 3 *\n");
			printf(" Voce chegou ao nivel final, derrote o vin diesel!");

			Turno3();

			if(jogador.pv > 1)
			{
				printf("Parabens! Voce completou o jogo\n");
			}

			else
			{
				printf("Derrota\n");
			}
		}

		else
		{
				printf("Derrota\n");
		}
	}
	else
	{
		printf("Derrota\n");
	}
	system("pause");
	system("cls");
}

//**

int main()
{
	int escolha;

	for(;;){

		//menu();
		printf("Voce vai a uma taverna para beber no seu dia folga, quando de repente uma briga comeca e todo mundo do local comeca a brigar tambem.Voce, ainda sobrio e incomodado com a situacao, tenta apaziguar a briga, porem, voce esbarra em uma gangue e eles partem pra cima de voce querendo brigar.\n\nAperte 1 para comecar o jogo ou 2 para sair: ");
		scanf("%d", &escolha);
		

		if(escolha == 2){

			break;
		}

		else{

			switch(escolha){

				case 1:

					Cadastrojogador();

					Batalhas();

					break;

				default:

				printf("Invalido, tente novamente! ");

				break;	

			}
		}
	}
}