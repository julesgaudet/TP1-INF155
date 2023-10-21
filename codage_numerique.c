/*******************************************************************************/
/*                   DÉSACTIVATION ALERTES NON PERTINENTES                     */
/*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 

/*******************************************************************************/
/*                   D�CLARATION DES LIBRAIRIES                                */
/*******************************************************************************/

#include "codage_numerique.h"
#include<stdio.h>
#include<stdlib.h>

/*******************************************************************************/
/*                             inverser_tab_bits                               */
/*******************************************************************************/

int inverser_tab_bits(int tab_bits[], int nb_bits) {
    if (nb_bits <= CODAGE_NB_BITS) {
        int tableauTemporaire[nb_bits];
        for (int i = 0; i < nb_bits; i++) {
            tableauTemporaire[i] = tab_bits[nb_bits - i - 1];
        }
        for (int i = 0; i < nb_bits; i++) {
            tab_bits[i] = tableauTemporaire[i];
        }
        return 1;
    }
    return 0;
}

/*******************************************************************************/
/*                               codage_dec2bin                                */
/*******************************************************************************/

int codage_dec2bin(int nombre, int resultat[]) {
    int compteur = 0;
    int i = 0;
     while (nombre != 0 && i < CODAGE_NB_BITS) {  
        resultat[i] = nombre % 2;
        compteur++;
        i++;
        nombre /= 2;
    }
    if (nombre == 0 && compteur <= CODAGE_NB_BITS) {
        int tableauTemporaire[compteur];
        for (int y = 0; y < compteur; y++) {
            tableauTemporaire[y] = resultat[compteur - 1 - y];
        }
        for (int z = 0; z < compteur; z++) {
            resultat[z] = tableauTemporaire[z];
        }
        return compteur;
    } 
    return 0;
}

/*******************************************************************************/
/*                           afficher_tabs_bits                                */
/*******************************************************************************/

void afficher_tab_bits(const int tab_bits[], int nb_bits) {
    printf("Tableau : ");
    for (int i = 0; i < nb_bits; i++) {
        printf("%d ", tab_bits[i]);
    }
}