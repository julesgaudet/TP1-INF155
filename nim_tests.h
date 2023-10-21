/*******************************************************************************/
/*  NIM_TESTS.H                                                                */
/*  Ce module contient les fonctions tests nec�ssaires � l'impl�mantation du 
jeu NIM */
/*******************************************************************************/

/*******************************************************************************/
/*                   D�CLARATION DES LIBRAIRIES                                */
/*******************************************************************************/

#ifndef NIM_TESTS_H
#define NIM_TESTS_H

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

//Partie 1
void test_lire_entier(); //TEST 1 : S'assurer que le nombre de colonne sélectionné par l'utilisateur est entre 1 et 20.
void test_plateau_init(); //TEST 2 : S'assurer que les valeurs dans le tableau sont aléatoires et qu'elles sont en dessous de 35.
void test_nim_jouer_tour(); //TEST 3 : S'assurer qu'on peut soustraire le nombre de pièces dans la colonne que l'utilisateur a indiqué.
void test_plateau_supprimer_colonne(); //TEST 4 : S'assurer qu'on supprime la colonne "col_a_supprimer" du plateau.
void test_plateau_defragmenter(); //TEST 5 : S'assurer qu'on supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne".  
void test_nim_choix_ia_aleatoire(); //TEST 6 : S'assurer qu'il effectue un jeu aléatoire en choisissant au hasard une colonne, puis au hasard le nombre de pièces à jouer de cette colonne. 

//Partie 2
void test_inverser_tab_bits(); //TEST 13 : S'assurer qu'il fait un inversement avec le nombre de bits.
void test_codage_dec2bin(); //TEST 14 : S'assurer qu'un nombre décimal est traduit en binaire.
void test_afficher_tab_bits();//TEST 15 : Afficher le tableau.
void test_codage_bin2dec(); //TEST 16 : S'assurer qu'un nombre binaire est traduit en décimale.
void test_construire_mat_binaire(); //TEST 17 : S'assurer qu'il la matrice binaire nécessaire à l'algorithme de choix de jeu de l'ordinateur. 
void test_sommes_mat_binaire(); //TEST 18 : S'assurer que ça calcule les sommes des colonnes d'une matrice binaire de taille "nb_lignes" * CODAGE_NB_BITS. 
void test_position_premier_impaire(); //TEST 19 : S'assurer que ça retourne le premier nombre impaire dans le tableau.

#endif