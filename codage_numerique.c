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
    while (i < CODAGE_NB_BITS) {
        resultat[i] = 0;
        i++;
    }
    if (compteur <= CODAGE_NB_BITS) {
        inverser_tab_bits(resultat, CODAGE_NB_BITS);
        return CODAGE_NB_BITS; 
    }
    return 0;
}


/*******************************************************************************/
/*                           afficher_tabs_bits                                */
/*******************************************************************************/

void afficher_tab_bits(const int tab_bits[], int nb_bits) {
    for (int i = 0; i < nb_bits; i++) {
        printf("%d ", tab_bits[i]);
    }
}

/*******************************************************************************/
/*                               codage_bin2dec                                */
/*******************************************************************************/

int codage_bin2dec(const int tab_bits[]) {
    int valeur = 0;
    int exposant = 1;
    for (int i = 0; i < CODAGE_NB_BITS; i++) {
        if (tab_bits[i] == 1) {
            for (int j = 0; j < CODAGE_NB_BITS - i - 1; j++) {
                exposant = exposant * 2;
            }
            valeur = valeur + exposant;
            exposant = 1; 
        }
    }
    return valeur;
}
