/*******************************************************************************/
/*  NIM.H                                                                      */
/*  Ce module contient les fonctions nec�ssaires � l'impl�mantation du jeu NIM */
/*******************************************************************************/
#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_
#define NIM_H_

/*******************************************************************************/
/*                   D�CLARATION DES LIBRAIRIES                                */
/*******************************************************************************/

#include "codage_numerique.h"
#include "m_distributions.h"
#include "m_distributions.h"
#include<stdio.h>
#include<stdlib.h>

/*******************************************************************************/
/*                    D�CLARATION DES CONSTANTES                               */
/*******************************************************************************/

#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pi�ces par colonne
#define TRUE   1
#define FALSE  0

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

void plateau_init(int plateau[], int nb_colonnes); //Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aléatoire de pièces entre 1 et 35. 
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces); //La fonction sassure que le jeu est valide et renvoie Vrai si le jeu désiré a pu sappliquer à la configuration actuelle du jeu. 
void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer); //Supprime la colonne "col_a_supprimer" du plateau. 
int plateau_defragmenter(int plateau[], int nb_colonnes); //Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne". 
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces); //Fonction qui effectue un jeu aléatoire en choisissant au hasard une colonne, puis au hasard le nombre de pièces à jouer de cette colonne. 
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int * choix_colonne, int * choix_nb_pieces); //Fonction qui détermine quel doit être le jeu de l'ordinateur. 
void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]); //Construit la matrice binaire nécessaire à l'algorithme de choix de jeu de l'ordinateur.
void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]); //Calcule les sommes des colonnes d'une matrice binaire de taille "nb_lignes" * CODAGE_NB_BITS. 
int position_premier_impaire(const int tab[]); //Recherche la première valeur impaire d'un tableau tab et retourne son indice.

#endif