#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*KILLIAN HOUARD BTS-1*/

int main()
{
    char str [200];

    char swap; // variable d'échange
    int indiceFinDuMot = 0; //repère pour chaque fin de mot

    //quelques variables de stockage

    int stock = 0;
    int stock2 = 0;
    int stock3 = 0;

    //un indice

    int i = 0;


    int nbMot = -1; // pour compter les mots sauf le premier/dernier

    //Récupération de la prase de l'utilisateur
    puts("Saisissez une phrase : \n");
    gets(str);
    puts("--------------RESULTAT-------------");



    /*-------- Nombre de mot - 2 --------*/ //On traite le premier et le dernier à part

    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            nbMot++;
        }
        i++;
    }

    /*-------- PREMIER MOT-----------*/


    if(nbMot + 2 != 1)
    {
        //Compte le nombre de caractère dans un mot
        while(str[indiceFinDuMot] != ' ')
        {
            indiceFinDuMot++;
        }
        stock2 = indiceFinDuMot; // au cas ou il n'y ait que deux mots

        indiceFinDuMot--; //On enlève l'espace
        stock = indiceFinDuMot;

        for (int i = 0; i < indiceFinDuMot; i++, indiceFinDuMot--)
        {
            swap = str[i];
            str[i] = str[indiceFinDuMot];
            str[indiceFinDuMot] = swap;
        }

        indiceFinDuMot = stock + 2; // Indice de la premiere lettre du prochain mot

    }
    else
    {
        //au cas ou il n'y ait qu'un seul mot
        for (int i = 0; i < indiceFinDuMot; i++, indiceFinDuMot--)
        {
            swap = str[i];
            str[i] = str[indiceFinDuMot];
            str[indiceFinDuMot] = swap;
            nbMot = -1; //Pour éviter de faire les prochains traitement
        }
    }


    /*-------- BOUCLE POUR LES MOTS ENTRE LE PREMIER ET LE DERNIER MOT----------*/
    i = 0;
    stock2 = indiceFinDuMot - 1; // l'espace avant le prochain mot (le deuxième)
    while((i < nbMot) && (str[indiceFinDuMot] != '\0'))
    {
        while(str[indiceFinDuMot] != ' ')
        {
            indiceFinDuMot++;                //La boucle s'arrete à l'éspace après le mot
        }

        stock3 = indiceFinDuMot;  //sauvegarde de l'indice avant le traitement

        //inversion du mot
        for (int i = stock2; i < indiceFinDuMot + 1; i++, indiceFinDuMot--)
        {
            swap = str[i];
            str[i] = str[indiceFinDuMot];
            str[indiceFinDuMot] = swap;
        }


        indiceFinDuMot = stock3 + 1; // On ajoute l'espace pour ne pas le traiter
        stock2 = indiceFinDuMot-1;  // On stock l'indice de l'espace avant le prochain mot
        i++;
    }


    /*-------- DERNIER MOT-----------*/

    //compte le nombre de lettre du dernier mot
    while(str[indiceFinDuMot] != '\0')   //On cherche la fin de la chaîne
    {
        indiceFinDuMot++;
    }

    if(str[indiceFinDuMot] == '\0') // verifi si fin du mot
    {
        indiceFinDuMot--; //indice de la dernière lettre du dernier mot

        for (int i = stock2 + 1; i < indiceFinDuMot + 1; i++, indiceFinDuMot--)
        {
            swap = str[i];
            str[i] = str[indiceFinDuMot];
            str[indiceFinDuMot] = swap;
        }


    }


    printf("%s\n\n", str); //Affichage du résultat de la chaine en verlan


    return 0;

}
