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

    md_srand(PLATEAU_MAX_PIECES);
    for (int i = 0; i < nb_colonnes; i++) {
        plateau[i] = rand() % PLATEAU_MAX_PIECES;
        while (plateau[i] == 0) {
            plateau[i] = rand() % PLATEAU_MAX_PIECES;
        }
    }
}

/*******************************************************************************/
/*                                nim_jouer_tour                               */
/*******************************************************************************/

int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces) {
    if (nb_pieces <= plateau[colonne] && colonne <= nb_colonnes) {
        plateau[colonne] = plateau[colonne] - nb_pieces;
        return TRUE;
    }
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
    md_srand(nb_colonnes);
    *choix_colonne = rand() % nb_colonnes;
    md_srand(PLATEAU_MAX_PIECES);
    *choix_nb_pieces = rand() % PLATEAU_MAX_PIECES;
    plateau[*choix_colonne] = *choix_nb_pieces; //Je ne sais pas comment faire ici
}
