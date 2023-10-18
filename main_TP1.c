/*******************************************************************************/
/*                   DÉSACTIVATION ALERTES NON PERTINENTES                     */
/*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 

/*******************************************************************************/
/*                   D�CLARATION DES LIBRAIRIES                                */
/*******************************************************************************/

#include "nim.h"
#include "nim_io.h"
#include "nim_tests.h"

/*******************************************************************************/
/*                   D�CLARATION DES CONSTANTES                                */
/*******************************************************************************/

#define MINIMUM_BORNE 1
#define MAXIMUM_BORNE 20

/*******************************************************************************/
/*                   D�CLARATION DE FONCTION                                   */
/*******************************************************************************/

int lire_entier(int min, int max); 

/*******************************************************************************/
/*                   D�CLARATION DE MAIN                                       */
/*******************************************************************************/

int main (void) {
    printf("\n");
    printf("******************Premier test********************\n");
    test_lire_entier(); //TEST 1
    printf("\n");
    printf("*****************Deuxième test*********************\n");
    test_plateau_init(); //TEST 2
    printf("\n");
    printf("*****************Troisième test********************\n");
    test_nim_jouer_tour(); //TEST 3
    printf("\n");
    printf("*****************Quatrième test********************\n");
    test_plateau_supprimer_colonne(); //TEST 4
    printf("\n");
    printf("*****************Cinquième test*********************\n");
    test_plateau_defragmenter(); //TEST 5

    //Fonctions pour que le programme fonctionne
    //lire_entier(MINIMUM_BORNE, MAXIMUM_BORNE);
    //void plateau_init(int plateau[], int nb_colonnes);
    //int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);
    //void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);
    //int plateau_defragmenter(int plateau[], int nb_colonnes);
    return 0;
}