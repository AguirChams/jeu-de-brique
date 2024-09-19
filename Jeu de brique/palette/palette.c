#include <stdio.h>
#include <stdlib.h>

#define gauche 0
#define droite 1

// Structure d'un noeud de la liste chaînée (représentant une position de la palette)
typedef struct noeud {
    int ligne;
    int colonne;
    struct noeud *suivant;
} t_noeud;

// Structure de la palette
typedef struct {
    t_noeud *tete;
    t_noeud *queue;
    int direction;
} t_palette;

// Fonction pour créer un nœud
t_noeud* creer_noeud(int ligne, int colonne) {
    t_noeud* nv_noeud = (t_noeud*)malloc(sizeof(t_noeud));
    nv_noeud->ligne = ligne;
    nv_noeud->colonne = colonne;
    nv_noeud->suivant = NULL;
    return nv_noeud;
}

// Fonction pour initialiser la palette
t_palette* init_palette(int ligne, int colonne_depart, int taille) {
    t_palette* palette = (t_palette*)malloc(sizeof(t_palette));
    palette->tete = NULL;
    palette->queue = NULL;
    palette->direction = droite;

    // Créer les nœuds de la palette à partir de la colonne de départ
    for (int i = 0; i < taille; i++) {
        t_noeud* nv_noeud = creer_noeud(ligne, colonne_depart + i);
        if (palette->tete == NULL) {
            palette->tete = nv_noeud;
            palette->queue = nv_noeud;
        } else {
            palette->queue->suivant = nv_noeud;
            palette->queue = nv_noeud;
        }
    }
    return palette;
}

// Fonction pour déplacer la palette
void deplacer_palette(t_palette* palette, int direction, int taille, int taille_grille) {
    palette->direction = direction;
    
    if (direction == droite) {
        // Ajouter un nœud à droite
        int nouvelle_colonne = palette->queue->colonne + 1;
        if (nouvelle_colonne < taille_grille) {
            t_noeud* nv_noeud = creer_noeud(palette->queue->ligne, nouvelle_colonne);
            palette->queue->suivant = nv_noeud;
            palette->queue = nv_noeud;

            // Supprimer le premier nœud à gauche
            t_noeud* temp = palette->tete;
            palette->tete = palette->tete->suivant;
            free(temp);
        }
    } else if (direction == gauche) {
        // Ajouter un nœud à gauche
        int nouvelle_colonne = palette->tete->colonne - 1;
        if (nouvelle_colonne >= 0) {
            t_noeud* nv_noeud = creer_noeud(palette->tete->ligne, nouvelle_colonne);
            nv_noeud->suivant = palette->tete;
            palette->tete = nv_noeud;

            // Supprimer le dernier nœud à droite
            t_noeud* temp = palette->tete;
            while (temp->suivant != palette->queue) {
                temp = temp->suivant;
            }
            free(palette->queue);
            palette->queue = temp;
            palette->queue->suivant = NULL;
        }
    }
}

// Fonction pour afficher la palette
void afficher_palette(t_palette* palette) {
    t_noeud* temp = palette->tete;
    while (temp != NULL) {
        printf("(%d,%d) ", temp->ligne, temp->colonne);
        temp = temp->suivant;
    }
    printf("\n");
}

// Fonction pour libérer la mémoire de la palette
void liberer_palette(t_palette* palette) {
    t_noeud* temp = palette->tete;
    while (temp != NULL) {
        t_noeud* a_supprimer = temp;
        temp = temp->suivant;
        free(a_supprimer);
    }
    free(palette);
}

// Exemple d'utilisation
int main() {
    // Initialisation de la palette sur la ligne 5, colonne de départ 3, taille 4
    t_palette* palette = init_palette(5, 3, 4);

    // Afficher la palette initiale
    afficher_palette(palette);

    // Déplacer la palette vers la droite
    deplacer_palette(palette, droite, 4, 10);
    afficher_palette(palette);

    // Déplacer la palette vers la gauche
    deplacer_palette(palette, gauche, 4, 10);
    afficher_palette(palette);

    // Libérer la mémoire
    liberer_palette(palette);

    return 0;
}
