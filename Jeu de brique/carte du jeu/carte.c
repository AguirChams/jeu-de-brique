#include <stdio.h>
#include <stdlib.h>
#define VIDE 0
#define MUR 1
#define BRIQUE 2
typedef struct{
    int **hauteur;  // tab de pointeurs hauteur de la carte x*x
    int **largeur;  // tab de pointeurs largeur de la carte x*x
    int taille;   // Taille de la carte x*x
}t_carte;
// Création d'une carte
t_carte** creer_carte(int taille){
    int i,j;

 
    //creation d'un pointeur vers un tableau d'hauteur de taille x qui represente la grille
    int** hauteur = (int**) malloc(taille * sizeof(int*));
    //creation d'un pointeur vers un tableau de hauteur qui represente la ligne de la carte et qui doit etre de taille x
    for (i = 0; i < taille; i++) {
        hauteur[i] = (int*)malloc(taille * sizeof(int));
    }
    //remplissage de la carte avec des murs et des briques
    for(i=0; i< taille; i++){
        for(j=0; j<taille; j++){
            //initialisation des murs autour du bord
            if(i==0|| i==taille-1 || j==0|| j==taille-1){
                hauteur[i][j] = MUR;
            }else{
                hauteur[i][j] = VIDE;
            }
        }
    }
    return hauteur;
}
// recuperation d'un element de la carte
/*int recuperer_element(t_carte *carte, int x, int y){
    if(x<0 || x>=carte->taille || y<0 || y>=carte->taille){
        printf("Erreur : coordonnees invalides\n");
        return -1;
    }
    return carte->grille[x][y];
}
void mettre_a_jour_element(t_carte *carte, int x, int y, int nouvelle_valeur){
    if(x<0 || x>=carte->taille || y<0 || y>=carte->taille){
        printf("Erreur : coordonnees invalides\n");
        return;
    }
    carte->grille[x][y] = nouvelle_valeur;
}
void afficher_carte(t_carte *carte){
      int i, j;
        for (i = 0; i < carte->taille; i++) {
            for (j = 0; j < carte->taille; j++) {
                printf("%d ", carte->grille[i][j]);
            }
            printf("\n");
        }  
}
void liberer_carte(t_carte *carte){
    for(int i=0; i < carte->taille; i++){
        free(carte->grille[i]);
    }
    free(carte->grille);
    free(carte);
}*/
int main(){
    int taille=1;
    int** hauteur = creer_carte(taille);
    for(int i=0; i<taille; i++){
        for(int j=0; j<taille; j++){
            printf("%d ", hauteur[i][j]);
        }
        printf("\n");
    }
    /*mettre_a_jour_element(carte, 2, 2, BRIQUE);
    mettre_a_jour_element(carte, 4, 2, BRIQUE);
    afficher_carte(carte);
    liberer_carte(carte);*/
    return 0;
}


