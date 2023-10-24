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

/*******************************************************************************/
/*                             plateau_defragmenter                            */
/*******************************************************************************/

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

/*******************************************************************************/
/*                          nim_choix_ia_aleatoire                             */
/*******************************************************************************/

void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces) {
    unsigned int seed = md_srand_interne();
    *choix_colonne = rand() % nb_colonnes;
    *choix_nb_pieces = plateau[*choix_colonne] - (rand() % plateau[*choix_colonne]);
}

/*******************************************************************************/
/*                                  nim_choix_ia                               */
/*******************************************************************************/

//CE CODE NE FONCTIONNE PAS

void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int *choix_colonne, int *choix_nb_pieces) {
    int matrice[nb_colonnes][CODAGE_NB_BITS];
    int sommes[CODAGE_NB_BITS];

    if (niveau == 0) {
        nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
    } 
    else if (niveau == 1) {
        unsigned int seed = md_srand_interne();
        int valeur = rand() % 2;
        if (valeur == 0) {
            niveau = 2; 
        } else if (valeur == 1) {
            nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
        }

        //Il y a une erreur dans le niveau 2; ca ne marche pas
        if (niveau == 2) {
            construire_mat_binaire(plateau, nb_colonnes, matrice);
            sommes_mat_binaire(matrice, nb_colonnes, sommes);
            int positionValeurImpaire = position_premier_impaire(sommes);
            if (positionValeurImpaire == -1) {
                nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
            } 
            else {
                for (int j = positionValeurImpaire; j < CODAGE_NB_BITS; j++) {
                    if (matrice[*choix_colonne][j] == 1) {
                        matrice[*choix_colonne][j] = 0;
                    }
                    else {
                        matrice[*choix_colonne][j] = 1;
                    }
                    int valeurDecimale = codage_bin2dec(matrice[*choix_colonne]);
                    sommes[*choix_colonne] = sommes[*choix_colonne] - valeurDecimale;
                }
            }
        }
    }
}


/*******************************************************************************/
/*                         construire_mat_binaire                              */
/*******************************************************************************/

void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]) {
    for (int i = 0; i < nb_colonnes; i++) {
        codage_dec2bin(plateau[i], matrice[i]);
    }
}

/*******************************************************************************/
/*                              sommes_mat_binaire                             */
/*******************************************************************************/

void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]) {
    for (int j = 0; j < CODAGE_NB_BITS; j++) {
        sommes[j] = 0; 
    }
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < CODAGE_NB_BITS; j++) {
            sommes[j] = sommes[j] + matrice[i][j];
        }
    }
}

/*******************************************************************************/
/*                        position_premier_impaire                             */
/*******************************************************************************/

int position_premier_impaire(const int tab[]) {
    for (int i = 0; i < CODAGE_NB_BITS; i++) {
        if ((tab[i] % 2) == 1) {
            return i;
        }
    }
    return -1;
}



