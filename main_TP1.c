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

//TEST PARTIE 1
int main (void) {
    printf("\n");
    printf("******************Premier test********************\n");
    test_lire_entier(); 
    printf("\n");
    printf("*****************Deuxième test*********************\n");
    test_plateau_init(); 
    printf("\n");
    printf("*****************Troisième test********************\n");
    test_nim_jouer_tour(); 
    printf("\n");
    printf("*****************Quatrième test********************\n");
    test_plateau_supprimer_colonne(); 
    printf("\n");
    printf("*****************Cinquième test*********************\n");
    test_plateau_defragmenter(); 
    printf("\n");
    printf("*****************Sixième test*********************\n");
    test_nim_choix_ia_aleatoire(); 

//TEST PARTIE 2
    printf("\n");
    printf("*****************Treizième test*********************\n");
    test_inverser_tab_bits();  
    printf("\n");
    printf("*****************Quatorzième test*********************\n");
    test_codage_dec2bin();  
    printf("\n");
    printf("*******************Quinzième test*********************\n");
    test_afficher_tab_bits();  
    printf("\n");
    printf("*******************Seizième test*********************\n");
    test_codage_bin2dec();
    printf("\n");
    printf("*******************Dixseptième test*********************\n");
    test_construire_mat_binaire();
    printf("\n");
    printf("\n");
    printf("*******************Dixhuitième test*********************\n");
    test_sommes_mat_binaire();
    printf("\n");
    printf("*******************Dix-neuvième test*********************\n");
    test_position_premier_impaire();
    printf("\n");

    //Fonctions pour que le programme fonctionne
    //lire_entier(MINIMUM_BORNE, MAXIMUM_BORNE);
    //void plateau_init(int plateau[], int nb_colonnes);
    //int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);
    //void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);
    //int plateau_defragmenter(int plateau[], int nb_colonnes);
    return 0;
}