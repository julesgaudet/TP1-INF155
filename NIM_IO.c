/*******************************************************************************/
/*                   DÉSACTIVATION ALERTES NON PERTINENTES                     */
/*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 

/*******************************************************************************/
/*                   D�CLARATION DES LIBRAIRIES                                */
/*******************************************************************************/

#include "nim_io.h"
#include<stdio.h>
#include<stdlib.h>

/*******************************************************************************/
/*                                  LIRE ENTIER                                */
/*******************************************************************************/

int lire_entier(int min, int max) {
    int val;
    printf("Veuillez saisir un entier : ");
    scanf("%d", &val);
    while (val < min || val > max) {
        while (getchar() != '\n');
        printf("Veuillez saisir un entier valide entre %d et %d : ", min, max);
        scanf("%d", &val);
    }
    return val;
}