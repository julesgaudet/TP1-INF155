/*******************************************************************************/
/*  NIM_TESTS.H                                                                */
/*  Ce module contient la fonction qui permet de s'assurer que le nombre de 
colonne sélectionné par l'utilisateur est entre 1 et 20*/
/*******************************************************************************/
#ifndef NIM_IO_H
#define NIM_IO_H

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

int lire_entier(int min, int max); //Demande à l'usager de saisir un entier entre les bornes "min" et "max" 
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select); //Affiche la configuration du plateau à l'écran. 
static int choisir_colonne(int plateau[], int nb_colonnes); //Permet de choisir une colonne du plateau de jeu avec les touches fléchées (gauche, droite) ou l’espace (‘ ‘). 
void tour_humain(int plateau[], int nb_colonnes); //Déclenche le tour de l'humain en demandant à l'usager de choisir la colonne (avec un appel à "choisir_colonne") et le nombre de pièces à retirer du plateau de jeu.
void tour_ia(int plateau[], int nb_colonnes, double difficulte); //Déclenche le tour de l'ordinateur. 
void demarrer_jeu(int niveau); //Fonction qui contrôle le jeu de nim: elle donne la main, tour à tour, à chacun des deux joueurs et déclare le gagnant une fois la partie terminée.

#endif