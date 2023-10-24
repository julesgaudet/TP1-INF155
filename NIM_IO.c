/*******************************************************************************/
/*                   DÉSACTIVATION ALERTES NON PERTINENTES                     */
/*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 

/*******************************************************************************/
/*                   D�CLARATION DES LIBRAIRIES                                */
/*******************************************************************************/

#include "nim_io.h"
#include<stdio.h>
#include<stdlib.h>
#include "WinConsole.H"

/*******************************************************************************/
/*                                  LIRE ENTIER                                */
/*******************************************************************************/

int lire_entier(int min, int max) {
    int val;
    printf("Veuillez saisir un entier : ");
    scanf("%d", &val);
    while (val < min || val > max) {
        while (getchar() != '\n');
        printf("Veuillez saisir un entier valide entre %d et %d : ", min, max);
        scanf("%d", &val);
    }
    return val;
}

/*******************************************************************************/
/*                               plateau_afficher                              */
/*******************************************************************************/

void plateau_afficher(const int plateau[], int nb_colonnes, int col_select) {
    for (int i = 0; i < nb_colonnes; i++) {
        for (int j = 1; j < 36; j++) {
            if (i == 0) {
                gotoxy(i,j);
                printf("%d", i);
            }
            else if (plateau[nb_colonnes] <= j) {
                gotoxy(i,j);
                printf("*");
            }
        }      
    }  
}

/*void gotoxy(int ,int );		    //positions text cursor at (x, y) screen position*/

/*******************************************************************************/
/*                                   choisir_colonne                           */
/*******************************************************************************/


static int choisir_colonne(int plateau[], int nb_colonnes) {
    //À faire
}

/*******************************************************************************/
/*                                    tour_humain                              */
/*******************************************************************************/

void tour_humain(int plateau[], int nb_colonnes) {
    //À faire
}

/*******************************************************************************/
/*                                    tour_ia                                  */
/*******************************************************************************/

void tour_ia(int plateau[], int nb_colonnes, double difficulte) {
    //À faire
}

/*******************************************************************************/
/*                                   demarrer_jeu                              */
/*******************************************************************************/

void demarrer_jeu(int niveau) {
    //À faire
}