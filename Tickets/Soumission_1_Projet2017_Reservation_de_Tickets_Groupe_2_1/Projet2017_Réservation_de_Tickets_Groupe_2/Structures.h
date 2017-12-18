#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#define STR_SIZE 100
#define taille 25
#define PERSONNE_NBR 100
#define TAILLENOMTRIBUNE 50
#define NBR_TRIB 21

struct Date{

int d;
int m;
int y;

};

struct Personne {


    char nom[STR_SIZE]; //demande le nom : la taille en paramètre
    char prenom[STR_SIZE];// demande le prenom : la taille en paramètre
    char telephone[STR_SIZE]; // demande le numéro telephone : taille en paramètre
    struct Date birthdate; // fait appel a la structure date
    int nombre_tickets;
    int numero_tribune;

};

struct Tribune {

int nombre_de_place;
int prix;
struct Personne p[PERSONNE_NBR];
char NOMTRIBUNE[STR_SIZE];

};

struct ensembleDeTribune{
    struct Tribune *TT;//pointeur vers la structure tribune
    char listNAME[STR_SIZE];
};
//déclaration des fonctions

void initensembledestribune(struct ensembleDeTribune *cL);
void initT (struct Tribune *T);
void telecharger_Tribunes(struct ensembleDeTribune *Ticket);
void telecharger_reservations(struct Tribune *T);
void PROGLOOOPTribuneEnplus(struct ensembleDeTribune *cL);
void printTribune(struct ensembleDeTribune *cL);
void addTribune(struct ensembleDeTribune *cL, struct Tribune newT);
void addPersonne (struct Tribune *T, struct Personne newP);
void recordTribune(struct ensembleDeTribune *cL, FILE *f);
void record_Reservation(struct Tribune *T, FILE *f);
int getListSize_TRIBUNES(struct ensembleDeTribune *cL);
int getListSize_RESERVATIONS(struct Tribune *T);
void saveTRIBUNE(struct ensembleDeTribune *cL);
void save_reservations(struct Tribune *T);

#endif // STRUCTURES_H_INCLUDED
