#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "viaturaLogin.h"



char* decodificadorSenha(char* senha){

    char auxiliar[30];
    int iFinal =0;
    char* senhaDescrip = (char *)calloc(30, sizeof(char));

    for (int i=0; senha[i] != '\0'; i++){

        if (65 <= senha[i] && senha[i] <= 90){

            if (senha[i] + 3 > 90){
                auxiliar[i] = senha[i] + 3 - 26;
            }
            else{
                auxiliar[i] = senha[i] + 3;
            }

        }
        else if (97 <= senha[i] && senha[i] <= 122){

            if (senha[i] + 3 > 122){
                auxiliar[i] = senha[i] + 3 - 26;
            }
            else{
                auxiliar[i] = senha[i] + 3;
            }

        }

        else if (48 <= senha[i] && senha[i] <= 57){
            auxiliar[i]= senha[i];
        }

       
        
        
    }    
    while (auxiliar[iFinal+1] != '\0'){
            iFinal++;
    }

    for (int i = 0; i <iFinal; i++) { 
        senhaDescrip[iFinal-1 - i] = auxiliar[i];
    }

    senhaDescrip[iFinal + 1] = '\0';
    //strcpy(senha, senhaDescrip);
    return senhaDescrip;
}

int main(){
    char senha[30];
    scanf("%s", senha);

    char* senhaDecodificada = decodificadorSenha(senha);
    printf(senhaDecodificada);



    free(senhaDecodificada);
    return 0;
}


/*
    Função de verificação usuário/senha;
    Entrada: Ponteiro para a fila de infomações dos policias / nome / 
    Saida: true se as credenciais estarem corretas e falso caso contrario;
*/

bool validarUsuario(char* usuario, char* senha, Policial *ptrPoI){

    char* senhaDecodificada = decodificadorSenha(senha);
    printf(senhaDecodificada);

    while(ptrPoI != NULL){

        if (strcmp(ptrPoI->nomeGuerra, usuario)){
            if (strcmp(ptrPoI->senha, senhaDecodificada)){
                return true;
            }
            else{
                return false;
            }
        }
        ptrPoI++;
    }
    return false;
}
