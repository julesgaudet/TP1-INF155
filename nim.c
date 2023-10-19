/*******************************************************************************/
/*                   DÉSACTIVATION ALERTES NON PERTINENTES                     */
/*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 

/*******************************************************************************/
/*                   D�CLARATION DES LIBRAIRIES                                */
/*******************************************************************************/

#include "nim.h"
#include<stdio.h>
#include<stdlib.h>
#include "nim_io.h"
#include "m_distributions.h"

/*******************************************************************************/
/*                                  plateau_init                               */
/*******************************************************************************/

void plateau_init(int plateau[], int nb_colonnes) {
    unsigned int seed = md_srand_interne();
    for (int i = 0; i < nb_colonnes; i++) {
        plateau[i] = rand() % PLATEAU_MAX_PIECES + 1;
    }
}
/*******************************************************************************/
/*                                nim_jouer_tour                               */
/*******************************************************************************/

int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces) {
    if (colonne >= 0 && colonne < nb_colonnes && nb_pieces <= plateau[colonne]) {
        plateau[colonne] = plateau[colonne] - nb_pieces;
        return TRUE;
    }
    return FALSE;
}

/*******************************************************************************/
/*                         plateau_supprimer_colonne                           */
/*******************************************************************************/


void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer) {
    for (int i = col_a_supprimer; i < nb_colonnes - 1; i++) {
        int temp = plateau[i];
        plateau[i] = plateau[i + 1];
        plateau[i+1] = temp;
    }
}

int plateau_defragmenter(int plateau[], int nb_colonnes) {
    int compteur = 0;
    int i = 0;  
    while (i < nb_colonnes) {
        if (plateau[i] == 0) {
            plateau_supprimer_colonne(plateau, nb_colonnes, i);
            nb_colonnes--;  
            compteur++;     
        } else {
            i++;
        }
    }
    return compteur;  
}

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces) {
    unsigned int seed = md_srand_interne();
    *choix_colonne = rand() % nb_colonnes;
    *choix_nb_pieces = plateau[*choix_colonne] - (rand() % plateau[*choix_colonne]);
}