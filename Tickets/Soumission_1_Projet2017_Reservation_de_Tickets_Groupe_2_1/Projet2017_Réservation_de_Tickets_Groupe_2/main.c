#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include"Structures.h"


int main()
{

        int nbrbrine=0;
        nbrbrine=NBR_TRIB;// création d'une variable qui permettrea à la fonction malloc le nombre de place à réserver dans la mémoire.
        struct ensembleDeTribune OPS;
        struct Personne newP;
        struct Tribune T;

        OPS.TT=NULL;//on initialise le pointeur à zéro
        OPS.TT = (struct Tribune*)malloc(nbrbrine * sizeof(struct Tribune));//on réserve de l'espace dans la mémoire

        int i;
        int utilisateur_gestionnaire;
        int Nbre;
        int x;
        int y;
        int boucleAFFICHEUR;
        int choix;
        char chaine[10];
        char chainebis [10];
        char cont [4];//boucle pour recommencer
        int MOITIE,ensemble,boucleCava,boucleWarr;

        initensembledestribune(&OPS);//gère tribune,on initialise les tribunes à zéro en leur affectant la lettre \0 à la première lettre
        telecharger_Tribunes(&OPS);//gère tribune

        do{
        do{
        printf("-----MENU PRINCIPAL-----\n\nEtes vous utilisateur ou gestionnaire?\n");
        printf("1. Gestionnaire\n2. Utilisateur\n");
        scanf("%d", &utilisateur_gestionnaire);
        while(getchar()!='\n');
        }while(utilisateur_gestionnaire!=1 && utilisateur_gestionnaire!=2);

        switch(utilisateur_gestionnaire)
        {
        case 1:
            printTribune(&OPS);//gère tribune
            printf("il y a %d tribunes par defaut voulez vous en ajouter une?\n",getListSize_TRIBUNES(&OPS));
            PROGLOOOPTribuneEnplus(&OPS);
            printf("Nous avons maintenant %d tribunes dans le stade\n",getListSize_TRIBUNES(&OPS));
            break;

        case 2:


        ensemble=getListSize_TRIBUNES(&OPS);
        MOITIE=ensemble/2;

        printf("\n\nBienvenue au match final de la NBA!\n");
        printf("\n      -----(1)-----\n");
        printf("       __________\n");
        printf("       |  ____  |\n");
        printf("       |  |__|  |\n");
        printf("       |___WW___|\n");
        printf("           ||\n");
        printf("           ||\n");
        printf("           ||\n");
        printf("       ____||____\n");

        for(boucleAFFICHEUR=2;boucleAFFICHEUR<(ensemble-1);boucleAFFICHEUR=boucleAFFICHEUR+2)
        {
            printf("    //|          |//\n    //|          |//\n(%d) //|          |// (%d)\n    //|          |//\n    //|          |//\n",(boucleAFFICHEUR),(boucleAFFICHEUR+1));
        }

        printf("       __________\n");
        printf("           ||\n");
        printf("           ||\n");
        printf("           ||\n");
        printf("        ___||___\n");
        printf("       |   MM   |\n");
        printf("       |  |__|  |\n");
        printf("       |________|\n");
        printf("\n      -----(%d)-----\n",ensemble);

        printf("\n \t Quelle equipe supportez-vous?\n\n");
        printf("1.Cavaliers de Cleveland\n2.Warriors de Golden State \n (Tappez 1 ou 2)\nVotre choix: ");
        fgets(chaine,sizeof chaine,stdin);
        sscanf(chaine,"%d",&choix);

        switch(choix)
        {
        case 1 :
                    printf("-*-*-*-Supporter des Cavaliers-*-*-*-\n");
                    for(boucleCava=0;boucleCava<MOITIE;boucleCava++)
                    {
                        printf("\n%s\n",OPS.TT[boucleCava].NOMTRIBUNE);
                        printf("---------\n");
                        printf("Places restantes: %d\n",OPS.TT[boucleCava].nombre_de_place);
                        printf("Prix de la place: %d %c",OPS.TT[boucleCava].prix,36);
                        printf("\n");
                    }

                    printf("\n Vous avez le choix parmis les tribunes allant de 1 a %d \n",MOITIE);
                    printf("Quelle tribune choisissez-vous? ");
                    scanf("%d",&x);
                    newP.numero_tribune=x;
                    if(x>0 && x<=MOITIE)
                    {
                        initT(&T);
                        telecharger_reservations(&T);
                        while(getchar()!='\n');

                        printf("\n\nRentrez vos informations:\n");

                        printf("Nom : ");
                        fgets(newP.nom,STR_SIZE,stdin);
                        newP.nom[strlen(newP.nom)-1]= '\0';

                        printf("Prenom : ");
                        fgets(newP.prenom,STR_SIZE,stdin);
                        newP.prenom[strlen(newP.prenom)-1]= '\0';

                        printf("Numero de telephone : ");
                        fgets(newP.telephone,taille,stdin);
                        newP.telephone[strlen(newP.telephone)-1]= '\0';

                        do{
                        printf("Date de naissance(DD/MM/YYYY): ");
                        scanf("%d/%d/%d",&newP.birthdate.d,&newP.birthdate.m,&newP.birthdate.y);
                        }while((newP.birthdate.d>31) || (newP.birthdate.d<0)||
                        (newP.birthdate.m>12) || (newP.birthdate.m<0)||
                        (newP.birthdate.y>2017) || (newP.birthdate.y<1900));

                        printf("combien de ticket desirez-vous ?\n");
                        scanf("%d",&Nbre);

                        newP.nombre_tickets=Nbre;
                        addPersonne(&T,newP);

                        save_reservations(&T);

                        printf("\n\n");
                        printf("Personnes inscrites\n");
                        printf("-------------------\n");

                        i = 0;
                        while(T.p[i].nom[0] != '\0')
                        {
                            printf("Nom: %s\n",T.p[i].nom);
                            printf("Prenom: %s\n",T.p[i].prenom);
                            printf("Numero telephone: %s\n",T.p[i].telephone);
                            printf("Date de naissance: %.2d/%.2d/%.4d\n",T.p[i].birthdate.d,T.p[i].birthdate.m,T.p[i].birthdate.y);
                            printf("Tribune %d\n",T.p[i].numero_tribune);
                            printf("Places reservees: %d\n",T.p[i].nombre_tickets);
                            printf("\n\n");

                            i++;
                        }

                        if(Nbre<OPS.TT[x-1].nombre_de_place)//le if vérifie si il y a encore des place disponibles dans les tribunes
                        {
                            printf("Place restante dans la tribune: %d",OPS.TT[x-1].nombre_de_place-Nbre);
                            OPS.TT[x-1].nombre_de_place=OPS.TT[x-1].nombre_de_place-Nbre;
                            saveTRIBUNE(&OPS);//on sauvegarde la tribune après la modification du nombre de place
                            printf("\n");
                            fgets (chainebis, sizeof chainebis, stdin);
                            sscanf(chainebis,"%s",cont);
                        }
                        else{printf("pas assez de place");}

                    }
                else
                {
                    printf("Desole, cette tribune n'est pas reservee aux supporter des Cavaliers!\n");
                    fgets (chainebis, sizeof chainebis, stdin);
                    sscanf(chainebis,"%s",cont);
                }
            break;

        case 2 :    printf("-*-*-*-Supporter des Warriors-*-*-*-\n");

                    for(boucleWarr=MOITIE;boucleWarr<ensemble;boucleWarr++)
                    {
                        printf("\n%s\n",OPS.TT[boucleWarr].NOMTRIBUNE);
                        printf("---------\n");
                        printf("Places restantes: %d\n",OPS.TT[boucleWarr].nombre_de_place);
                        printf("Prix de la place: %d %c",OPS.TT[boucleWarr].prix,36);
                        printf("\n");
                    }

                    printf("\n Vous avez le choix parmis les tribunes allant de %d a %d\n",MOITIE+1,ensemble);
                    printf("Quelle tribune choisissez-vous? ");
                    scanf("%d",&y);
                    newP.numero_tribune=y;
                    if(MOITIE<y && y<=ensemble)
                    {
                        initT(&T);
                        telecharger_reservations(&T);
                        while(getchar()!='\n');
                        printf("\n\nRentrez vos informations:\n");

                        printf("Nom : ");
                        fgets(newP.nom,STR_SIZE,stdin);
                        newP.nom[strlen(newP.nom)-1]= '\0';

                        printf("Prenom : ");
                        fgets(newP.prenom,STR_SIZE,stdin);
                        newP.prenom[strlen(newP.prenom)-1]= '\0';

                        printf("Numero de telephone : ");
                        fgets(newP.telephone,taille,stdin);
                        newP.telephone[strlen(newP.telephone)-1]= '\0';

                        do{
                        printf("Date de naissance(DD/MM/YYYY): ");
                        scanf("%d/%d/%d",&newP.birthdate.d,&newP.birthdate.m,&newP.birthdate.y);
                        }while((newP.birthdate.d>31) || (newP.birthdate.d<0)||
                        (newP.birthdate.m>12) || (newP.birthdate.m<0)||
                        (newP.birthdate.y>2017) || (newP.birthdate.y<1900));

                        printf("combien de ticket desirez-vous ?\n");
                        scanf("%d",&Nbre);

                        newP.nombre_tickets=Nbre;
                        addPersonne(&T,newP);

                        save_reservations(&T);

                        printf("\n\n");
                        printf("Personnes inscrites\n");
                        printf("-------------------\n");

                        i = 0;
                        while(T.p[i].nom[0] != '\0')
                        {
                            printf("Nom: %s\n",T.p[i].nom);
                            printf("Prenom: %s\n",T.p[i].prenom);
                            printf("Numero telephone: %s\n",T.p[i].telephone);
                            printf("Date de naissance: %.2d/%.2d/%.4d\n",T.p[i].birthdate.d,T.p[i].birthdate.m,T.p[i].birthdate.y);
                            printf("Tribune %d\n",T.p[i].numero_tribune);
                            printf("Places reservees: %d\n",T.p[i].nombre_tickets);
                            printf("\n\n");

                            i++;
                        }

                        if(Nbre<OPS.TT[y-1].nombre_de_place)
                        {
                        printf("Place restante dans la tribune: %d",OPS.TT[y-1].nombre_de_place-Nbre);
                        OPS.TT[y-1].nombre_de_place=OPS.TT[y-1].nombre_de_place-Nbre;
                        saveTRIBUNE(&OPS);
                        printf("\n");
                        fgets (chainebis, sizeof chainebis, stdin);
                        sscanf(chainebis,"%s",cont);
                        }
                        else{printf("pas assez de place");}
                    }

                        else
                    {
                                printf("Desole, cette tribune n'est pas reservee aux supporter des Warriors!\n");
                                fgets (chainebis, sizeof chainebis, stdin);
                                sscanf(chainebis,"%s",cont);
                    }

            break;


            default : printf("Choix incorrect!");//default switch principal
    }


        break;
        }
        printf("\nVoulez-vous revenir au menu principal? (oui/non)\n");
        fgets (chainebis, sizeof chainebis, stdin);
        sscanf(chainebis,"%s",cont);

    }while ((strcmp(cont,"oui") == 0) || (strcmp(cont,"Oui")==0));


free(OPS.TT);// on libère la place réservé
return 0;
}





