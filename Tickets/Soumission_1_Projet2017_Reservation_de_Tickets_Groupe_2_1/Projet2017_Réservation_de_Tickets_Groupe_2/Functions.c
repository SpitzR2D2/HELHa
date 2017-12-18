#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"Structures.h"

void telecharger_Tribunes(struct ensembleDeTribune *Ticket)
{
    struct Tribune newT;
    char str[STR_SIZE];
    int list_Size,i;
    FILE *f;
    f = fopen("TRIBUNE.data","r");
    if(f != NULL){
    fgets(str, STR_SIZE, f);
    if(strcmp(str,"### Tribune ###\n") == 0){  //Fonction de comparaison pour voir si la premiere ligne est bien ### Tribune ###\n


		   fgets(str,STR_SIZE,f);//NBR
           fscanf(f,"%d",&list_Size);//le 6 ds notre cas
           while(getc(f)!='\n');
           fgets(str,STR_SIZE,f);//data

           for(i = 0; i <list_Size; i++){ //Boucle pour recuperer toutes les données des tribunes

                fgets(str,STR_SIZE,f);// on enregistre le #

                fgets(newT.NOMTRIBUNE,STR_SIZE,f);
                newT.NOMTRIBUNE[strlen(newT.NOMTRIBUNE)-1]= '\0'; // Pour supprimer la case réservée au \n


                fgets(str,STR_SIZE,f);
                sscanf(str,"%d",&newT.nombre_de_place);

                fgets(str,STR_SIZE,f);
                sscanf(str,"%d",&newT.prix);

                fgets(str,STR_SIZE,f);// on enregistre le #

                addTribune(Ticket,newT);}

        }
        else{
            printf("Invalid File! - New list created!\n");
        }
        fclose(f);
    }
    else{
        printf("No List with such name! - New list created!\n");
    }

}

void PROGLOOOPTribuneEnplus(struct ensembleDeTribune *cL)
{   int quit,sel;
 struct Tribune newT;
    quit = 0;
    while(!quit){      // inverse la valeur du boolean
        printf("\n1 - TRIBUNE EN PLUS\n");
        printf("2 - AFFICHER TOUTES LES TRIBUNES\n");
        printf("3 - SAUVEGARDER LES TRIBUNES DANS LE FICHIER\n");
        printf("4 - TERMINER\n");
        printf("\nSelection: ");
        scanf("%d",&sel);
        while(getchar()!='\n');
        switch(sel){
        case 1:

            printf("\n\n");
            printf("AJOUT DE TRIBUNE\n");
            printf("---------------\n");

            printf("NOM DE LA TRIBUNE: ");
            fgets(newT.NOMTRIBUNE,STR_SIZE,stdin);
            newT.NOMTRIBUNE[strlen(newT.NOMTRIBUNE)-1]= '\0';


            printf("NOMBRE DE PLACES: ");
            scanf("%d",&newT.nombre_de_place);
            while(getchar()!='\n');

            printf("PRIX DE LA PLACE ");
            scanf("%d",&newT.nombre_de_place);
            while(getchar()!='\n');

            addTribune(cL,newT);
            break;
        case 2:
            printTribune(cL);
            break;
        case 3:
            saveTRIBUNE(cL);
            initensembledestribune(cL);
            telecharger_Tribunes(cL);
            break;

        case 4:
            if((getListSize_TRIBUNES(cL)%2==0) && getListSize_TRIBUNES(cL)>=4)
            {
            quit = 1;
            break;
            }
            else{printf("Non il faut un nombre pair de tribunes et un stade comporte au minimum quatre tribunes!");}
        }
        }
}

void initensembledestribune(struct ensembleDeTribune *cL){

    int i;

    for(i = 0; i < NBR_TRIB; i++){

        cL->TT[i].NOMTRIBUNE[0] = '\0';

    }
}


void initT(struct Tribune *T){

    int i;

   for(i = 0; i < PERSONNE_NBR; i++){

        T->p[i].nom[0] = '\0';  //On initialise a zero les personnes

   }
}

void addPersonne(struct Tribune *T, struct Personne newP){
    int i=1;

    if(T->p[PERSONNE_NBR-1].nom[0] != '\0')
    {
        printf("ERROR - Tribune remplie!\n");
    }
    else if(T->p[0].nom[0] == '\0')
    {
        T->p[0] = newP;
    }
    else
    {
        for(i = PERSONNE_NBR-2 ; i >= 0 ; i--)
        {
            if(T->p[i].nom[0] != '\0')
            {
                if(strcmp(newP.nom,T->p[i].nom) >= 0)
                {
                    T->p[i+1] = newP;
                    break;
                }
                else
                {
                    T->p[i+1] = T->p[i];
                    if(i==0)
                    {
                        T->p[i] = newP;
                    }
                }
            }
        }
   }
}


void addTribune(struct ensembleDeTribune *cL, struct Tribune newT){
    int i;
    if(cL->TT[NBR_TRIB-1].NOMTRIBUNE[0] != '\0')
    {
        printf("ERROR - NOMBRE TRIBUNE MAX ATTEINTE!\n");
    }
    else if(cL->TT[0].NOMTRIBUNE[0] == '\0')
    {
        cL->TT[0] = newT;
    }
    else
    {
        for(i = NBR_TRIB-2 ; i >= 0 ; i--)
        {
            if(cL->TT[i].NOMTRIBUNE[0] != '\0')
            {
                if(strcmp(newT.NOMTRIBUNE,cL->TT[i].NOMTRIBUNE) >= 0)
                {
                    cL->TT[i+1] = newT;
                    break;
                }
                else
                {
                    cL->TT[i+1] = cL->TT[i];
                    if(i==0)
                    {
                        cL->TT[i] = newT;
                    }
                }
            }
        }
    }
}


void printTribune(struct ensembleDeTribune *cL){//affichage des tribunes
    int i;

    i = 0;
    while(cL->TT[i].NOMTRIBUNE[0] != '\0'){
        printf("NOM DE LA TRIBUNE: %s\n",cL->TT[i].NOMTRIBUNE);

        printf("NOMBRE DE PLACES DISPONIBLE: %.2d\n",cL->TT[i].nombre_de_place);

        printf("PRIX: %.2d\n\n",cL->TT[i].prix);
        i++;
    }


}

void saveTRIBUNE(struct ensembleDeTribune *cL){
    int list_Size;
    FILE *f;

    printf("\n\n");
    printf("Saving Contact List\n");
    printf("-------------------\n");

    f = fopen("TRIBUNE.data","w");
    if(f != NULL){
        fprintf(f,"### Tribune ###\n## Nbr ##\n");
        list_Size = getListSize_TRIBUNES(cL);
        fprintf(f,"%d\n",list_Size);
        fprintf(f,"## Data ##\n");
        recordTribune(cL,f);
        fclose(f);
        printf("Done!");
    }
    else{

        printf("Error - Impossible to save List!\n");
    }
}

void recordTribune(struct ensembleDeTribune *cL, FILE *f){
    int i;

    i = 0;
    while(cL->TT[i].NOMTRIBUNE[0] != '\0')
    {
        fprintf(f,"#\n");
        fprintf(f,"%s\n",cL->TT[i].NOMTRIBUNE);
        fprintf(f,"%.2d\n",cL->TT[i].nombre_de_place);
        fprintf(f,"%.2d\n#\n",cL->TT[i].prix);
        i++;
    }
}
int getListSize_TRIBUNES(struct ensembleDeTribune *cL){
    int i;

    for(i = 0; i < NBR_TRIB; i++){
        if(cL->TT[i].NOMTRIBUNE[0] == '\0'){
            break;
        }
    }
    return i++;
}

int getListSize_RESERVATIONS(struct Tribune *T){
    int i;

    for(i = 0; i < PERSONNE_NBR; i++){
        if(T->p[i].nom[0] == '\0'){
            break;
        }
    }
    return i++;
}

void telecharger_reservations(struct Tribune *T)
{

    struct Personne newP;
    char str[STR_SIZE];
    int list_Size,i;
    FILE *f;
    f = fopen("DONNEES_UTILISATEURS.txt","r");
    if(f != NULL)
    {
        fgets(str, STR_SIZE, f);
        if(strcmp(str,"Tickets pour le match de finale de la NBA - CAVALIERS de Cleveland - WARRIORS de Golden State\n") == 0)
        {

		   fgets(str,STR_SIZE,f);// enregistre le #
		   fgets(str,STR_SIZE,f);
           sscanf(str,"Nombre de reservations: %d",&list_Size);

           for(i = 0; i <list_Size; i++)
            {

                fgets(str,STR_SIZE,f);// on enregistre le #

                fgets(str,STR_SIZE,f);
                sscanf(str,"%s",newP.nom);

                fgets(str,STR_SIZE,f);
                sscanf(str,"%s",newP.prenom);

                fgets(str,STR_SIZE,f);
                sscanf(str,"%s",newP.telephone);

                fgets(str,STR_SIZE,f);
                sscanf(str,"%d/%d/%d",&newP.birthdate.d,&newP.birthdate.m,&newP.birthdate.y);

                fgets(str,STR_SIZE,f);
                sscanf(str,"%d",&newP.numero_tribune);

                fgets(str,STR_SIZE,f);
                sscanf(str,"%d",&newP.nombre_tickets);

                addPersonne(T,newP);
            }

        }
        else{
            printf("Invalid File! - New list created!\n");
        }
        fclose(f);
    }
    else
    {
        printf("No List with such name! - New list created!\n");
    }

}

void save_reservations(struct Tribune *T)
{
    int list_Size;

    FILE *f;
    f = fopen("DONNEES_UTILISATEURS.txt","w");
    if(f != NULL)
        {
            printf("\nvous etes dans le fichier\n");
            fprintf(f,"Tickets pour le match de finale de la NBA - CAVALIERS de Cleveland - WARRIORS de Golden State\n#\n");
            list_Size = getListSize_RESERVATIONS(T);
            fprintf(f,"Nombre de reservations: %d\n",list_Size);
            record_Reservation(T, f);

        }
    fclose(f);
}

void record_Reservation(struct Tribune *T, FILE *f){
    int i;

    i = 0;
    while(T->p[i].nom[0] != '\0')
    {
        fprintf(f,"#\n");
        fprintf(f,"%s\n",T->p[i].nom);
        fprintf(f,"%s\n",T->p[i].prenom);
        fprintf(f,"%s\n",T->p[i].telephone);
        fprintf(f,"%d/%d/%d\n",T->p[i].birthdate.d,T->p[i].birthdate.m,T->p[i].birthdate.y);
        fprintf(f,"%d\n",T->p[i].numero_tribune);
        fprintf(f,"%d\n",T->p[i].nombre_tickets);

        i++;
    }
}
