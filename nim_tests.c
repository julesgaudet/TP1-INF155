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
#include "codage_numerique.h"

/*******************************************************************************/
/*                               PARTIE 1                                      */
/*                         test_lire_entier                                    */
/*******************************************************************************/

void test_lire_entier() {
    int val = lire_entier(1, 20);
    printf("Voici la valeur entre 1 et 20 : %d\n", val);
}

/*******************************************************************************/
/*                         test_plateau_init                                   */
/*******************************************************************************/

void test_plateau_init() {
    int plateau[20];
    plateau_init(plateau, 20);
    for (int i = 0; i < 20; i++) {
        printf("%d ", plateau[i]);
    }
    printf("\n");
}

/*******************************************************************************/
/*                       test_nim_jouer_tour                                   */
/*******************************************************************************/

void test_nim_jouer_tour() {
    int plateau[20];
    plateau[19] = 30;
    printf("Nombre de jetons avant : 30\n");
    nim_jouer_tour(plateau, 20, 19, 6);
    printf("Nombre de jetons après : %d\n", plateau[19]);
}

/*******************************************************************************/
/*                    test_plateau_supprimer_colonne                           */
/*******************************************************************************/

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

/*******************************************************************************/
/*                    test_plateau_defragmenter                                */
/*******************************************************************************/

void test_plateau_defragmenter() {
    int plateau[5] = {1, 0, 0, 0, 5};
    int x = plateau_defragmenter(plateau, 5);
    printf("Le nombre de zéro enlevé : %d\n", x);
}

/*******************************************************************************/
/*                    test_nim_choix_ia_aleatoire                              */
/*******************************************************************************/

void test_nim_choix_ia_aleatoire() {
    const int plateau[5] = {1, 5, 5, 5, 5};
    int nb_colonnes = 5;
    int choix_colonne, choix_nb_pieces;
    nim_choix_ia_aleatoire(plateau, nb_colonnes, &choix_colonne, &choix_nb_pieces);
    printf("Voici le choix de colonne : %d\n", choix_colonne);
    printf("Voici le nouveau nombre de pièces : %d\n", choix_nb_pieces);
}

/*******************************************************************************/
/*                              test_nim_choix_ia                              */
/*******************************************************************************/

//CE CODE NE FONCTIONNE PAS

void test_nim_choix_ia() {
    int plateau[8] = {2, 6, 7, 14, 22, 4, 9, 13};
    int choix_colonne;
    int choix_nb_pieces;
    printf("Plateau initial : ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", plateau[i]);
    }
    printf("\n");
    printf("Niveau 2 :\n");
    nim_choix_ia(plateau, 8, 2, &choix_colonne, &choix_nb_pieces);
    printf("Choix de colonne : %d\n", choix_colonne);
    printf("Nombre de pièces à retirer : %d\n", choix_nb_pieces);
    printf("Plateau après les choix : ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", plateau[i]);
    }
    printf("\n");
}

/*******************************************************************************/
/*                               PARTIE 2                                      */
/*                        test_inverser_tab_bits                               */
/*******************************************************************************/

void test_inverser_tab_bits() {
    int tab[8] = {1, 1, 1, 1, 1, 0, 0, 0};
    printf("Matrice avant : 1 1 1 1 1 0 0 0\n");
    int nb_bits = inverser_tab_bits(tab, 8);
    printf("Résultat pour inversement matrice : %d\n", nb_bits);
    printf("Matrice après : ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

/*******************************************************************************/
/*                            test_codage_dec2bin                              */
/*******************************************************************************/

void test_codage_dec2bin() {
    int nombre = 3;
    int resultat[8];  
    int nb_bits = codage_dec2bin(nombre, resultat);
    printf("Nombre décimal : %d\n", nombre);
    printf("Le nombre de chiffre : %d bits\n", nb_bits);
    printf("Nombre binaire : ");
    for (int i = 0; i < nb_bits; i++) {  
        printf("%d ", resultat[i]);
    }
    printf("\n");
}

/*******************************************************************************/
/*                          test_afficher_tab_bits                             */
/*******************************************************************************/

void test_afficher_tab_bits() {
    printf("Afficher un tableau : ");
    int resultat[8] = {1, 1, 1, 1, 1, 0, 0, 0};
    afficher_tab_bits(resultat, CODAGE_NB_BITS);
    printf("\n");
}

/*******************************************************************************/
/*                             test_codage_bin2dec                             */
/*******************************************************************************/

void test_codage_bin2dec() {
    int resultat[8] = {1, 1, 1, 1, 1, 1, 1, 1} ;
    int valeur = codage_bin2dec(resultat);
    printf("Voici la valeur du tableau test : %d\n", valeur);
}

/*******************************************************************************/
/*                         test_construire_mat_binaire                         */
/*******************************************************************************/

void test_construire_mat_binaire() {
    int plateau[8] = {1, 5, 3, 34, 3, 23, 33, 12};
    int matrice[8][CODAGE_NB_BITS];
    printf("Avant conversion en binaire :\n");
    printf("Plateau : ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", plateau[i]);
    }
    printf("\n");
    construire_mat_binaire(plateau, 8, matrice);
    printf("\nAprès conversion en binaire :\n");
    for (int i = 0; i < 8; i++) {
        printf("colonne %d : ", i + 1);
        for (int j = 0; j < CODAGE_NB_BITS; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

/*******************************************************************************/
/*                            test_sommes_mat_binaire                          */
/*******************************************************************************/

void test_sommes_mat_binaire() {
    int matrice[3][CODAGE_NB_BITS] = {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1, 0, 0, 1}
    };

    int sommes[CODAGE_NB_BITS] = {0, 0, 0, 0, 0, 0, 0, 0};

    sommes_mat_binaire(matrice, 3, sommes);

    printf("Sommes des lignes de la matrice binaire :\n");
    for (int i = 0; i < CODAGE_NB_BITS; i++) {
        printf("%d ", sommes[i]);
    }
    printf("\n");
}

/*******************************************************************************/
/*                        test_position_premier_impaire                        */
/*******************************************************************************/

void test_position_premier_impaire() {
    int tableau1[CODAGE_NB_BITS] = {2, 4, 6, 8, 1, 10, 12, 14};
    int resultat1 = position_premier_impaire(tableau1);
    printf("Tableau 1 : ");
    for (int i = 0; i < CODAGE_NB_BITS; i++) {
        printf("%d ", tableau1[i]);
    }
    printf("\n");
    printf("Position du premier impair dans le tableau 1 : %d\n", resultat1);
}