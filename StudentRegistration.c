#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 3
#define TAM 100

typedef struct{
    int chamada, faltas;
    float nota1, nota2, media;
    char nome[TAM], email[TAM], situacao[TAM], matricula[TAM];
}alunos;

int main(){
    system("cls");

    alunos dados[n]; 
    int i, j = 0, escolha = 0, escolha1 = 0, escolha2 = 0, escolha3 = 0, pos = -1, chamada_buscar = 0, nums_matricula;
    char nome_buscar[TAM], matricula_buscar[TAM], menu[3];

    while(escolha != 4){
        printf("0 - Cadastrar \n1 - Buscar \n2 - Excluir \n3 - Ver Cadastrados \n4 - Sair \nEscolha uma Opcao: ");
        scanf("%d", &escolha);
        fflush(stdin);

        //MENU PRINCIPAL
        switch (escolha){
        case 0:
            if(j < n){
                for(j; j < n; j++){
                    system("cls");

                    printf("Digte o Nome do Aluno %d: ", j+1);
                    gets(dados[j].nome);
                    fflush(stdin);

                    printf("\nDigite o E-mail de %s: ", dados[j].nome);
                    gets(dados[j].email);
                    fflush(stdin);

                    printf("\nDigite o numero da Chamada: ");
                    scanf("%d", &dados[j].chamada);
                    fflush(stdin);

                    printf("\nDigite a nota da Avaliacao 1: ");
                    scanf("%f", &dados[j].nota1);
                    fflush(stdin);

                    printf("\nDigite a nota da Avaliacao 2: ");
                    scanf("%f", &dados[j].nota2);
                    fflush(stdin);

                    printf("\nDigite o numero de faltas: ");
                    scanf("%d", &dados[j].faltas);
                    fflush(stdin);

                    nums_matricula = rand() % 1000;

                    sprintf(dados[j].matricula, "12411BCC%03d", nums_matricula);
                    dados[j].media = (dados[j].nota1 + dados[j].nota2) / 2;

                    if(dados[j].media >= 6 && dados[j].faltas <= 10){
                        strcpy(dados[j].situacao, "APROVADO!");
                    }else{
                        strcpy(dados[j].situacao, "REPROVADO!");
                    }
                    
                    system("cls");

                    if(j < 2){
                        printf("0 - Continuar \n1 - Parar \nDeseja cadastrar mais alunos? ");
                        scanf("%d", &escolha1);
                        fflush(stdin);

                        if(escolha1 == 1){
                            j++;
                            system("cls");
                            break;
                        }
                    }

                }
            }else{
                    system("cls");
                    printf("Limite maximo de alunos atingido!\n\n");
                }
            break;
        
        case 1:
            if(j == 0){
                system("cls");
                printf("Nao ha alunos cadastrados ainda!\n\n\n");
                break;
            }
            printf("\n\n0 - Nome \n1 - Matricula \n2 - Numero da chamada \nEscolha uma opcao para buscar: ");
            scanf("%d", &escolha2);
            fflush(stdin);

            //MENU DE BUSCA
            switch (escolha2){
            case 0:
                pos = -1;
                while(pos == -1){
                    printf("\nInsira o nome do aluno: ");
                    gets(nome_buscar);
                    fflush(stdin);

                    for (i = 0; i < n; i++){
                        if(!strcmp(dados[i].nome, nome_buscar)){
                            pos = i;
                            system("cls");
                            printf("\nDados do aluno %s:\n", dados[pos].nome);
                            printf("\nE-mail: %s \nMatricula: %s \nChamada: %d \nNota 1 : %.2f \nNota 2: %.2f \nMedia: %.2f \nFaltas: %d \nSituacao: %s\n\n", dados[pos].email, dados[pos].matricula, dados[pos].chamada, dados[pos].nota1, dados[pos].nota2, dados[pos].media, dados[pos].faltas, dados[pos].situacao);
                            
                            printf("\n\nPressione Qualquer Tecla para Voltar ao Menu\n");
                            system("cls");
                            gets(menu);
                            break;
                        }
                    }

                    if(pos != -1){
                        break;
                    }
                    
                    system("cls");
                    printf("Aluno não encontrado, tente novamente!");
                }

                break;
                
            case 1:
                pos = -1;
                while(pos == -1){
                    printf("\nInsira a matrícula: ");
                    gets(matricula_buscar);
                    fflush(stdin);

                    for (i = 0; i < n; i++){
                        if(!strcmp(dados[i].matricula, matricula_buscar)){
                            pos = i;
                            system("cls");
                            printf("\nDados do aluno %s:\n", dados[pos].nome);
                            printf("\nE-mail: %s \nMatricula: %s \nChamada: %d \nNota 1 : %.2f \nNota 2: %.2f \nMedia: %.2f \nFaltas: %d \nSituacao: %s\n\n", dados[pos].email, dados[pos].matricula, dados[pos].chamada, dados[pos].nota1, dados[pos].nota2, dados[pos].media, dados[pos].faltas, dados[pos].situacao);
                            
                            printf("\n\nPressione Qualquer Tecla para Voltar ao Menu\n");
                            gets(menu);
                            system("cls");
                            break;
                        }
                        
                    }
                    
                    if(pos != -1){
                        break;
                    }

                    system("cls");
                    printf("Aluno não encontrado, tente novamente!");
                }

                break;
                
            case 2:
                pos = -1;
                while(pos == -1){
                    printf("\nDigite o numero da chamada: ");
                    scanf("%d", &chamada_buscar);
                    fflush(stdin);

                    for(i = 0; i < n; i++){
                        if(chamada_buscar == dados[i].chamada){
                            pos = i;
                            system("cls");
                            printf("\nDados do aluno %s:\n", dados[pos].nome);
                            printf("\nE-mail: %s \nMatricula: %s \nChamada: %d \nNota 1 : %.2f \nNota 2: %.2f \nMedia: %.2f \nFaltas: %d \nSituacao: %s\n\n", dados[pos].email, dados[pos].matricula, dados[pos].chamada, dados[pos].nota1, dados[pos].nota2, dados[pos].media, dados[pos].faltas, dados[pos].situacao);
                                
                            printf("\n\nPressione Qualquer Tecla para Voltar ao Menu\n");
                            gets(menu);
                            system("cls");
                            break;
                        }
                    }

                    if(pos != -1){
                        break;
                    }

                    system("cls");
                    printf("Aluno nao encontrado, tente novamente! ");
                }

                break;

            default:
                printf("Opcao invalida, tente novamente! ");
                break;

            }

            break;

        case 2:
            if(j == 0){
                system("cls");
                printf("Nao ha alunos cadastrados ainda!\n\n");
                break;
            }

            system("cls");
            printf("Deseja excluir por: \n0 - Nome \n1 - Matricula \n2 - Chamada \nEscolha uma opcao: ");
            scanf("%d", &escolha3);
            fflush(stdin);

            //MENU DE EXLCUSAO
            switch (escolha3){
            case 0:
                pos = -1;

                while(pos == -1){
                    printf("\nInsira o nome do aluno: ");
                    gets(nome_buscar);
                    fflush(stdin);

                    for (i = 0; i < n; i++){
                        if(!strcmp(dados[i].nome, nome_buscar)){
                            pos = i;

                            dados[pos].nome[0] = '\0';
                            dados[pos].email[0] = '\0';
                            dados[pos].situacao[0] = '\0';
                            dados[pos].matricula[0] = '\0';
                            dados[pos].chamada = 0;
                            dados[pos].nota1 = 0;
                            dados[pos].nota2 = 0;
                            dados[pos].media = 0;

                            j--;

                            system("cls");
                            printf("Aluno excluido com sucesso!\n\n");
                            break;
                        }
                    }
                    

                    if(pos != -1){
                        break;
                    }

                    system("cls");
                    printf("Aluno nao encontrado, tente novamente!");

                }

                break;

            case 1:
                pos = -1;

                while(pos == -1){
                    printf("\nInsira a matrícula: ");
                    gets(matricula_buscar);
                    fflush(stdin);

                    for (i = 0; i < n; i++){
                        if(!strcmp(dados[i].matricula, matricula_buscar)){
                            pos = i;

                            dados[pos].nome[0] = '\0';
                            dados[pos].email[0] = '\0';
                            dados[pos].situacao[0] = '\0';
                            dados[pos].matricula[0] = '\0';
                            dados[pos].chamada = 0;
                            dados[pos].nota1 = 0;
                            dados[pos].nota2 = 0;
                            dados[pos].media = 0;

                            j--;

                            system("cls");
                            printf("Aluno excluido com sucesso!\n\n");
                            break;
                        }
                    }

                    if(pos != -1){
                        break;
                    }

                    system("cls");
                    printf("Aluno nao encontrado, tente novamente!");
                }

                break;

            case 2:
                pos = -1;

                while(pos == -1){
                    printf("\nInsira o numero da chamada: ");
                    scanf("%d", &chamada_buscar);
                    fflush(stdin);

                    for (i = 0; i < n; i++){
                        if(chamada_buscar == dados[i].chamada){
                            pos = i;

                            dados[pos].nome[0] = '\0';
                            dados[pos].email[0] = '\0';
                            dados[pos].situacao[0] = '\0';
                            dados[pos].matricula[0] = '\0';
                            dados[pos].chamada = 0;
                            dados[pos].nota1 = 0;
                            dados[pos].nota2 = 0;
                            dados[pos].media = 0;

                            j--;

                            system("cls");
                            printf("Aluno excluido com sucesso!\n\n");
                            break;
                        }
                    }

                    if(pos != -1){
                        break;
                    }

                    system("cls");
                    printf("Aluno nao encontrado, tente novamente!");
                }

                break;
            
            default:
                printf("\nOpcao invalida, tente novamente! ");
                break;
            }

        break;

        case 3:
            system("cls");
            printf("Alunos cadastrados: %d", j);

            for(i = 0; i < j; i++){
                printf("\n\nAluno %d:",i+1);
                printf("\n\nNome: %s \nE-mail: %s \nMatricula: %s \nChamada: %d \nNota 1 : %.2f \nNota 2: %.2f \nMedia: %.2f \nFaltas: %d \nSituacao: %s\n\n", dados[i].nome, dados[i].email, dados[i].matricula, dados[i].chamada, dados[i].nota1, dados[i].nota2, dados[i].media, dados[i].faltas, dados[i].situacao);
            }

            printf("\n\nPressione Qualquer Tecla para Voltar ao Menu\n");
            gets(menu);
            system("cls");
            
            break;

        case 4:
            printf("\nObrigado!");
            break;

        default:
            printf("\nOpcao invalida, tente novamente! ");
            break;

        }
    }
}