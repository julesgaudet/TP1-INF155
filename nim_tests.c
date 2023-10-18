/*******************************************************************************/
/*                   DÉSACTIVATION ALERTES NON PERTINENTES                     */
/*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 

/*******************************************************************************/
/*                   D�CLARATION DES LIBRAIRIES                                */
/*******************************************************************************/

#include "nim_io.h"
#include "nim_tests.h"
#include "nim.h"
#include <stdio.h>

/*******************************************************************************/
/*                    D�CLARATION DES TESTS                                    */
/*******************************************************************************/

void test_lire_entier() {
    int val = lire_entier(1, 20);
    printf("Voici la valeur entre 1 et 20 : %d\n", val);
}

void test_plateau_init() {
    int plateau[20];
    plateau_init(plateau, 20);
    for (int i = 0; i < 20; i++) {
        printf("%d ", plateau[i]);
    }
    printf("\n");
}

void test_nim_jouer_tour() {
    int plateau[20];
    plateau[19] = 30;
    printf("Nombre de jetons avant : 30\n");
    nim_jouer_tour(plateau, 20, 19, 6);
    printf("Nombre de jetons après : %d\n", plateau[19]);
}

void test_plateau_supprimer_colonne() {
    int plateau[20];
    plateau_init(plateau, 20);
    printf("Plateau avant suppression : ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", plateau[i]);
    }
    printf("\n");
    plateau_supprimer_colonne(plateau, 20, 1);
    printf("Plateau après suppression : ");
    for (int i = 0; i < 19; i++) { 
        printf("%d ", plateau[i]);
    }
    printf("\n");
}

void test_plateau_defragmenter() {
    int plateau[5] = {1,0,0,0,5};
    int x = plateau_defragmenter(plateau, 5);
    printf("Le nombre de zéro enlevé : %d\n", x);
}

void test_nim_choix_ia_aleatoire() {
    
}
