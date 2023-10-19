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

void test_lire_entier(); //TEST 1 : S'assurer que le nombre de colonne sélectionné par l'utilisateur est entre 1 et 20.
void test_plateau_init(); //TEST 2 : S'assurer que les valeurs dans le tableau sont aléatoires et qu'elles sont en dessous de 35.
void test_nim_jouer_tour(); //TEST 3 : S'assurer qu'on peut soustraire le nombre de pièces dans la colonne que l'utilisateur a indiqué.
void test_plateau_supprimer_colonne(); //TEST 4 : S'assurer qu'on supprime la colonne "col_a_supprimer" du plateau; on devra donc copier les valeurs de toutes les colonnes suivantes du plateau d’une position vers la gauche.
void test_plateau_defragmenter(); //TEST 5 : Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne". Le nombre de colonnes restant est retourné. 
void test_nim_choix_ia_aleatoire(); //TEST 6 : Fonction qui effectue un jeu aléatoire en choisissant au hasard une colonne, puis au hasard le nombre de pièces à jouer de cette colonne. 
#endif