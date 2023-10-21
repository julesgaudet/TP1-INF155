/*******************************************************************************/
/*  NIM_TESTS.H                                                                */
/*  Ce module contient la fonction qui permet de créer un algorithme puissant  */
/* qui rajoute de la difficulté au jeu                                         */
/*******************************************************************************/

#ifndef CODAGE_NUMERIQUE_H
#define CODAGE_NUMERIQUE_H

/*******************************************************************************/
/*                    D�CLARATION DES CONSTANTES                               */
/*******************************************************************************/

#define CODAGE_NB_BITS 8

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

int inverser_tab_bits(int tab_bits[], int nb_bits); //Fonction qui inverse les "nb_bits/2" premières valeurs d'un tableau de bits: le premier bit devient la dernier (et inversement), le deuxième devient l'avant dernier,.
int codage_dec2bin(int nombre, int resultat[]); //Traduit un nombre décimal en binaire.
void afficher_tab_bits(const int tab_bits[], int nb_bits); //Affiche un tableau contenant des bits à l'écran. 

#endif