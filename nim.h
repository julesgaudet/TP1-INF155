/*******************************************************************************/
/*  NIM.H                                                                      */
/*  Ce module contient les fonctions nec�ssaires � l'impl�mantation du jeu NIM */
/*******************************************************************************/
#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_
#define NIM_H_

#include "codage_numerique.h"
#include "m_distributions.h"
#include "m_distributions.h"
#include<stdio.h>
#include<stdlib.h>


#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pi�ces par colonne
#define TRUE   1
#define FALSE  0

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

void plateau_init(int plateau[], int nb_colonnes); //Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aléatoire de pièces entre 1 et PLATEAU_MAX_PIECES = 35. 
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces); //La fonction sassure que le jeu est valide et renvoie Vrai si le jeu désiré a pu sappliquer à la configuration actuelle du jeu. Pour être valide, la colonne doit exister et nombre de pièces retirées doit être <= au nombre de pièces actuellement présentes dans la colonne en question. 
void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer); //Supprime la colonne "col_a_supprimer" du plateau. Elle copie les valeurs de  les colonnes suivantes du plateau d’une position vers la gauche. 
int plateau_defragmenter(int plateau[], int nb_colonnes); //Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne". Le nombre de colonnes restant est retourné. 
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int * choix_colonne, int * choix_nb_pieces); //Fonction qui effectue un jeu aléatoire en choisissant au hasard une colonne, puis au hasard le nombre de pièces à jouer de cette colonne. 


#endif