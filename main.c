#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 80

void echangerLettre(char * ptrLettre1, char * ptrLettre2)
{
    char temp;
    temp = *ptrLettre1;
    *ptrLettre1 = *ptrLettre2;
    *ptrLettre2 = temp;

}

void inverserMot(char * ptrDebutMot, char * ptrFinMot)
{
    while(ptrDebutMot <= ptrFinMot)
    {
        echangerLettre(ptrDebutMot, ptrFinMot);
        ptrDebutMot++;
        ptrFinMot--;
    }
}

void verlanWeshDiabolique(char * buffer)
{
    char * ptr = buffer;
    while(*buffer != '\0') //Pour que buffer pointe sur le dernier caractère du mot
    {
        while(*buffer != ' ')
        {
            buffer++;
        }
        inverserMot(ptr, buffer);
        ptr = buffer;


    }
}

int main()
{
    char phrase[BUFFER_SIZE];
    char phrase2[BUFFER_SIZE] = "Je suis beau";

    /*do
    {
        puts("Votre phrase");
        gets(phrase);
        printf("Votre phrase :");
        printf("%s\n", phrase);
        puts("OK ? (o/n)");
    }while('o' != getchar());
    */

    puts("Votre phrase en verlan wesh diabolique : ");
    verlanWeshDiabolique(phrase2);
    printf("%s\n", phrase2);
    return 0;
}
