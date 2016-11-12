#include<stdlib.h>
#include<stdio.h>

/** structure de la cellule
    contient l'information et un pointeur sur
    l'element suivant
*/
typedef struct element
{
    int val;
    struct element* suivant;
}Element;

/** Strcture de controle
    contient un pointeur sur la tete de file,
    un pointeur sur la queue,
    et le nombre d'element de la file.
*/
typedef struct file
{
    Element* tete;
    Element* queue;
    int nbElem;
}File;

/**fonction qui retourne une file vide initialisé*/
File *initialiser()
{
    File *file = (File*)malloc(sizeof(File));
    file->tete = NULL;
    file->nbElem = 0;
    return file;
}

/** Fonction qui teste si la file est vide et retourne 0*/
int estVide(File *maFile)
{
    if(maFile->nbElem == 0)
        return 1;
    return 0;
}

/**Emfiler dans la queue;*/
File* emfiler(File * maFile,int donnee)
{
    Element *nouvelElem = (Element*)malloc(sizeof(Element));
    if(nouvelElem)
    {
        nouvelElem->val = donnee;
        nouvelElem->suivant=NULL;
        //Si la file est vide;
        if(maFile->tete == NULL)
        {
            //la tete et la queure de la file doivent pointer sur le nouvel element;
            maFile->tete = maFile->queue = nouvelElem;
            maFile->nbElem++;
            return ((File*)maFile);
        }
        //Sinon
        maFile->queue->suivant = nouvelElem;
        maFile->queue = nouvelElem;
        maFile->nbElem++;
        return ((File*)maFile);
    }
}

/**Fonction pour defiler une file;
//Supprimer de la tete de la file;
    Si elle defile l'element, elle retourne 1,
    0 Sinon.
*/
int defiler(File* maFile)
{
    if(maFile->tete == NULL)
    {
        printf("\nLa file est vide.\n");
        return 0;
    }
    Element *temporaire;
    temporaire = maFile->tete;
    maFile->tete = maFile->tete->suivant;
    free(temporaire);
    maFile->nbElem--;
    return 1;
}

/** Fonction qui cree une file et la remplie
    avec n elements saisient par l'utilisateur. */
File* creer_file(File *f,int n)
{
	int i,val;
	for(i=1;i<=n;i++)
    	{
    		printf("\n\t => Entrez un element:");
    		scanf("%d",&val);
    		emfiler(f,val);
		}
		return((File*)f);
}

/*
void afficher(File maFile)
{
    if (&maFile == NULL)
    {
        printf("La File est vide\n\n");
        exit(EXIT_FAILURE);
    }
    Element *tete = maFile.tete;
    while (tete != NULL)
    {
        printf("%d\n", tete->val);
        tete = tete->suivant;
    }
    printf("\n");
}*/

/**Fonction qui retourne la taille de la file; */
int taille(File* maFile)
{
    return ((int)maFile->nbElem);
}

/**Fonction qui affiche la file,
    defile, affiche, puis enfile dans la queue */
void afficher(File* maFile)
{
    int ind=0,var; // indice de l'element

    if(maFile->tete == NULL)
        printf("\n\t => la file est vide!! \n");
    for(ind = 0;ind < taille(maFile);ind++)
    {
        printf("\n\t => element %d: %d",ind+1,maFile->tete->val);
        maFile = emfiler(maFile,maFile->tete->val);
        defiler(maFile);
    }
}

/**Fonction qui raz une file **/
void razFile(File* maFile)
{
    while(!estVide(maFile))
        defiler(maFile);
}

/** Fonction qui cherche un element dans la file
    defile, teste, et enfile dans la fin de la file.
*/
int recherche(File* maFile, int elem)
{
    if(estVide(maFile))
    {
        printf("\nLa file est vide.\n");
        return ((int)-1);
    }
    int ind=0,var;
    for(ind = 0;ind < taille(maFile);ind++)
    {
        if(maFile->tete->val == elem)
            return ((int)1);
        var = maFile->tete->val;
        defiler(maFile);
        maFile = emfiler(maFile,var);
    }
    /**Retourner 0 si l'element n'est pas trouvé */
    return ((int)0);
}

/** fonction qui retourne le maximum */
int max(File* maFile)
{
    int M = maFile->tete->val,ind,var;
    for(ind = 0;ind < taille(maFile);ind++)
    {
        if(maFile->tete->val > M)
        {
            M = maFile->tete->val;
        }
        var = maFile->tete->val;
        defiler(maFile);
        maFile = emfiler(maFile,var);
    }
    return((int)M);
}

/** Fonction qui retourne le min */
int min(File* maFile)
{
    int m = maFile->tete->val,ind,var;
    for(ind = 0;ind < taille(maFile);ind++)
    {
        if(maFile->tete->val < m)
        {
            m = maFile->tete->val;
        }
        var = maFile->tete->val;
        defiler(maFile);
        maFile = emfiler(maFile,var);
    }
    return((int)m);
}

/** Fonction qui retourne la somme des element de la file */
int Somme(File* maFile)
{
    int s = 0,ind,var;
    for(ind = 0;ind < taille(maFile);ind++)
    {
        var = maFile->tete->val;
        defiler(maFile);
        s += var;
        maFile = emfiler(maFile,var);
    }
    return ((int)s);
}

/** Fonction qui retourne le produit des element de la file */
int Produit(File* maFile)
{
    int p = 1,ind,var;
    for(ind = 0;ind < taille(maFile);ind++)
    {
        var = maFile->tete->val;
        defiler(maFile);
        p *= var;
        maFile = emfiler(maFile,var);
    }
    return ((int)p);
}

int main()
{
	File *f;
	f=initialiser();

	int val,rep,n;

    printf("\n\t*****************************************************\n");
	printf("\t|                       MENU                        |\n" );
	printf("\t*****************************************************\n\n");
	printf("\t*    1---> Tester si la file est vide.               *\n");
	printf("\t*    2---> Razer la file.                            *\n");
    printf("\t*    3---> Affichage  de la file.                    *\n");
    printf("\t*    4---> Acceder a la tete de la file.             *\n");
    printf("\t*    5---> Emfiler.                                  *\n");
    printf("\t*    6---> Creer une file.                           *\n");
    printf("\t*    7---> Defiler.                                  *\n");
    printf("\t*    8---> Taille de la file.                        *\n");
    printf("\t*    9---> Rechercher un element dans la file.       *\n");
    printf("\t*    10---> Trouver le max de la file.               *\n");
    printf("\t*    11---> Trouver le min de la file.               *\n");
    printf("\t*    12---> La somme des elements de la file.        *\n");
    printf("\t*    13---> Le produit des elements de la file.      *\n");
    printf("\t*    14---> Quitter.                                 *\n");
	printf("\t******************************************************\n");
    printf("\n\t Votre choix =>  ");
	scanf("%d",&rep);
     do
    {
        switch(rep)
        {
        case 1:
            if(estVide(f)==1)
            printf("\n\t => La file est vide.\n");
            else printf("\n\t => La file n'est pas vide.\n");
            break;
        case 2:
            razFile(f);
            printf("\n\t => La file est maintenant vide.\n");
            break;
        case 3:
            afficher(f);
            break;
        case 4:
            if(!estVide(f))
                printf("\n\t => La tete de la file est : %d\n",f->tete->val);
            else printf("\n\t => La file est vide.\n");
            break;
        case 5:
            printf("\n\tDonner un entier : ");
            scanf("%d",&val);
            f=emfiler(f,val);
            afficher(f);
            break;
        case 6:
            printf("\n\t\tEntrez une taille: ");
            scanf("%d",&n);
            razFile(f);
            f=creer_file(f,n);
            afficher(f);
            break;
        case 7:
            defiler(f);
            afficher(f);
            break;
        case 8:
            printf("\n\t => La taille de votre file est : %d.\n",taille(f));
            break;
        case 9:
            printf("\n\tDonner un element a chercher : ");
            scanf("%d",&val);
            if(recherche(f,val) == 1)   printf("\n\tL'element a ete trouve.\n");
            else printf("\n\tL'element n'a pas ete trouve.\n");
            break;
        case 10:
            if(!estVide(f))
                printf("\n\tLe maximum de la file est : %d.\n",max(f));
            else printf("\n\t => La file est vide.\n");
            break;
        case 11:
            if(!estVide(f))
                printf("\n\tLe minimum de la file est : %d.\n",min(f));
            else printf("\n\t => La file est vide.\n");
            break;
        case 12:
            if(!estVide(f))
            {
                printf("\n\tLa somme de elements de la file est : %d.\n",Somme(f));
                afficher(f);
            }
            else printf("\n\t => La file est vide.\n");
            break;
        case 13:
            if(!estVide(f))
            {
                printf("\n\tLe produit de elements de la file est : %d.\n",Produit(f));
                afficher(f);
            }
            else printf("\n\t => La file est vide.\n");
            break;
        case 14 :
            printf("\t---------------------------------------------------\n");
            printf("\t                   Merci                  \n" );
            printf("\t---------------------------------------------------\n\n");
            return 0;
            default: printf("\n\t => Choix incorrect\n");
        }
            printf("\n\t => ");
            system("pause");
            system("cls");
    printf("\n\t*****************************************************\n");
	printf("\t|                       MENU                        |\n" );
	printf("\t*****************************************************\n\n");
	printf("\t*    1---> Tester si la file est vide.               *\n");
	printf("\t*    2---> Razer la file.                            *\n");
    printf("\t*    3---> Affichage  de la file.                    *\n");
    printf("\t*    4---> Acceder a la tete de la file.             *\n");
    printf("\t*    5---> Emfiler.                                  *\n");
    printf("\t*    6---> Creer une file.                           *\n");
    printf("\t*    7---> Defiler.                                  *\n");
    printf("\t*    8---> Taille de la file.                        *\n");
    printf("\t*    9---> Rechercher un element dans la file.       *\n");
    printf("\t*    10---> Trouver le max de la file.               *\n");
    printf("\t*    11---> Trouver le min de la file.               *\n");
    printf("\t*    12---> La somme des elements de la file.        *\n");
    printf("\t*    13---> Le produit des elements de la file.      *\n");
    printf("\t*    14---> Quitter.                                 *\n");
	printf("\t******************************************************\n");
    printf("\n\t Votre choix =>  ");
	scanf("%d",&rep);
}while((rep!=14));
    system("pause");
}
