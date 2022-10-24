#include <stdio.h>
#include <stdlib.h>     // rand() et srand()
#include <time.h>       // time()

#define SIZE 20
#define MIN -20
#define MAX 20

// void fill_tab_from_stdin(int *tab_int);
// void fill_tab_rng(int *tab_int);
void fill_tab(int *tab);
void fill_tab_stdin(int * tab);
void fill_tab_rng(int *tab);
// Renvoie la longueur du tableau modifié
int get_positive_nb_from_tab(int *tab, int *tab_pos);
int get_negative_nb_from_tab(int *tab, int *tab_neg);

void display_tab(int *tab, int size);

int get_positive_nb_from_tab(int *tab, int *tab_pos) {
    int tot_positive = 0;
    for (int i = 0 ; i < SIZE ; i++) {
        if (tab[i] > 0) {
            tab_pos[tot_positive++] = tab[i];
        }
    }
    return tot_positive;
}
int get_negative_nb_from_tab(int *tab, int *tab_pos) {
    int tot_negative = 0;
    for (int i = 0 ; i < SIZE ; i++) {
        if (tab[i] < 0) {
            tab_pos[tot_negative++] = tab[i];
        }
    }
    return tot_negative;
}


void display_tab(int * tab, int size) {
    printf("Displaying tab of size %d\n", size);
    for (int i = 0 ; i < size ; i++) {
        printf("%d->%d\n", i+1, tab[i]);
    }
}

void fill_tab_rng(int *tab) {
    int random = 0; 
    srand(time(NULL));

    for (int i = 0 ; i < SIZE ; i++) {
        random = (rand() % SIZE*2 + 1) + MIN;
        tab[i] = random;
    }
}

void fill_tab_stdin(int *tab) {
    for (int i = 0 ; i < SIZE ; i++) {
        int nb = 0;
        printf("Enter a value between %d and %d\n", MIN, MAX);
        do {
            scanf("%d", &nb);
            if (nb < MIN && nb > MAX) {
                printf("ERR\n");
            }
        } while(nb < MIN && nb > MAX);
        tab[i] = nb;
    }
}
void fill_tab(int * tab) {
    int choice = 0;
    printf("1: randomly, else: by hand\nchoice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        fill_tab_rng(tab);
    }else{
        fill_tab_stdin(tab);
    }
}

int main() {
    int tab_int[SIZE];
    int tab_pos[SIZE];
    int tab_neg[SIZE];

    // Remplissage du tableau
    fill_tab(tab_int);

    // Récupération des nombres positives et négatives dans tab_pos/neg
    int size_positive = get_positive_nb_from_tab(tab_int, tab_pos);
    int size_negative = get_negative_nb_from_tab(tab_int, tab_neg);

    // Affichage
    display_tab(tab_pos, size_positive);
    display_tab(tab_neg, size_negative);

    return 0;
}