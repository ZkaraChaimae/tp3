#include<stdlib.h>
#include<stdio.h>

//La structure de notre pile;
typedef struct element
{
    int donnee; // La donnée que notre pile stockera;
    struct element *precedent; // Pointeur vers l'élément précédent de la pile;
}Element;

//La structure de controle de la pile;
typedef struct Pile
{
    Element *premier;
    int nbElem;
}Pile;

//fonction qui retourne une pile vide initialisé
Pile *initialiser()
{
    Pile *pile = (Pile*)malloc(sizeof(Pile));
    pile->premier = NULL;
    pile->nbElem = 0;
    return pile;
}

//fonction qu retourne la taille de la pile;
int taillePile(Pile *maPile)
{
    return ((int)maPile->nbElem);
}

//fonction qui teste si la pile est vide;
int EstVide(Pile maPile)
{
    if(maPile.premier == NULL)  return 1;
    return 0;
}

//Empiler un element dans la pile
Pile* Pile_push(Pile * maPile,int valeur)
{
    Element *nouveauElem = (Element*)malloc(sizeof(Element));
    if(nouveauElem)
    {
        nouveauElem -> donnee = valeur;
        nouveauElem -> precedent = maPile->premier;
        maPile->premier = nouveauElem;
        maPile->nbElem++;
        return ((Pile*)maPile);
    }
}

//fonction qui retourne l'element dépilé;
int Pile_pop(Pile *maPile)
{
    if( (maPile == NULL) || (maPile -> premier == NULL) )
        exit(EXIT_FAILURE);
    int nb = maPile->premier->donnee;
    Element *elem_a_depiler = maPile -> premier;
    maPile->premier = maPile->premier->precedent;
    maPile->nbElem--;
    free(elem_a_depiler);
    return ((int)nb);
}

//Fonction qui raze une pile;
void razePile(Pile *maPile)
{
    while(maPile->premier)
        Pile_pop(maPile);
}

//Fonction qui accede au sommet de la pile;
int Sommet(Pile* maPile)
{
    return ((int)maPile->premier->donnee);
}

/*
void afficher(Pile maPile)
{
    if (&maPile == NULL)
    {
        printf("La pile est vide\n\n");
        exit(EXIT_FAILURE);
    }
    Element *tete = maPile.premier;
    while (tete != NULL)
    {
        printf("%d\n", tete->donnee);
        tete = tete->precedent;
    }
    printf("\n");
}*/

Pile* afficher(Pile *p)
{
    int ind=1;
    Pile *tmp;
    tmp=initialiser();
    // si la pile est vide j'affiche un message
    if(p->premier == NULL)
    {
        printf("\n\t votre pile est vide \n");
        return((Pile*)p);
    }
    // tant que la pile contient des elements
    while(p->premier)
    {
        // afficher le sommet
        printf("\n\t => element %d: %d",ind,p->premier->donnee);
        // empiler le sommet dans la pile temponte
        tmp=Pile_push(tmp,p->premier->donnee);
        // depiler la pile p pour pouvoir afficher le nv sommet
        Pile_pop(p);
        ind++;
    }

    // remmetre les element depiler dans la pile p
    while(tmp->premier)
    {
        p=Pile_push(p,tmp->premier->donnee);
        Pile_pop(tmp);
    }
    return((Pile*)p);

}

//fonction qui cherche un element dans une pile;
int recherche(Pile *maPile,int val)
{
    if(EstVide(*maPile))
        return ((int)0);
    int trouve = 0;
    Pile *tmp;
    tmp=initialiser();
    while(maPile->premier)
    {
        if(maPile->premier->donnee == val)
        {
            trouve = 1;
            break;
        }
        tmp=Pile_push(tmp,maPile->premier->donnee);
        Pile_pop(maPile);
    }
    while(tmp->premier)
    {
        maPile=Pile_push(maPile,tmp->premier->donnee);
        Pile_pop(tmp);
    }
    return ((int)trouve);
}

//fonction qui retourne le max et le min d'une pile;
void max_min(Pile* maPile,int *max,int *min)
{
    if(EstVide(*maPile))
    {
        printf("La pile est vide.\n");
        exit(EXIT_FAILURE);
    }
    *max = *min = (int)maPile->premier->donnee;
    Pile *tmp;
    tmp=initialiser();
    while(maPile->premier)
    {
        if(maPile ->premier ->donnee > *max)
            *max = maPile ->premier ->donnee;
        if(*min > maPile ->premier ->donnee)
            *min = maPile ->premier ->donnee;
        tmp=Pile_push(tmp,maPile->premier->donnee);
        Pile_pop(maPile);
    }
    while(tmp->premier)
    {
        maPile=Pile_push(maPile,tmp->premier->donnee);
        Pile_pop(tmp);
    }
}

//fonction qui retourne la somme des elements de la pile;
int Somme(Pile *maPile)
{
    if(EstVide(*maPile))
    {
        printf("La pile est vide.\n");
        exit(EXIT_FAILURE);
    }
    int somme = 0;
    Pile *tmp;
    tmp = initialiser();
    while(maPile->premier)
    {
        somme += maPile->premier->donnee;
        tmp = Pile_push(tmp,maPile->premier->donnee);
        Pile_pop(maPile);
    }
    while(tmp->premier)
    {
        maPile = Pile_push(maPile,tmp->premier->donnee);
        Pile_pop(tmp);
    }
    return ((int)somme);
}

//fonction qui retourne le produit des elements de la pile;
int Produit(Pile *maPile)
{
    if(EstVide(*maPile))
    {
        printf("La pile est vide.\n");
        exit(EXIT_FAILURE);
    }
    int produit = 1;
    Pile *tmp;
    tmp = initialiser();
    while(maPile->premier)
    {
        produit *= maPile->premier->donnee;
        tmp = Pile_push(tmp,maPile->premier->donnee);
        Pile_pop(maPile);
    }
    while(tmp->premier)
    {
        maPile = Pile_push(maPile,tmp->premier->donnee);
        Pile_pop(tmp);
    }
    return ((int)produit);
}

int main()
{
	Pile *p;

	p=initialiser(p);
	int val,rep,n;
    printf("\n\t*****************************************************\n");
    printf("\t|                       MENU                        |\n" );
    printf("\t*****************************************************\n\n");
    printf("\t*    1) Tester si une pile est vide              *\n");
    printf("\t*    2) Razer une pile                           *\n");
    printf("\t*    3) Affichage  d'une pile                    *\n");
    printf("\t*    4) Acceder a la tete de la pile             *\n");
    printf("\t*    5) Empiler                                  *\n");
    printf("\t*    6) La somme des elements de la pile         *\n");
    printf("\t*    7) Le produit des elements de la pile       *\n");
    printf("\t*    8) Depiler                                  *\n");
    printf("\t*    9) Taille de la pile                        *\n");
    printf("\t*    10) Quitter                                  *\n");
    printf("\t*****************************************************\n");
    printf("\n\t Votre choix =>  ");
	scanf("%d",&rep);
    do
    {
        switch(rep)
        {
            case 1 : if(EstVide(*p)) printf("\n\t => La pile est vide\n");
                     else printf("\n\t => la pile n'est pas vide");
					 break;
            case 2 : razePile(p);
			         break;
            case 3 : afficher(p);
                     break;
            case 4 :;
                    if(!EstVide(*p))
                        printf("\n\t =>La tete de la pile est: %d",p->premier->donnee);
			         break;
            case 5 : printf("\n\t => Donner une valeur: ");
	                 scanf("%d",&val);
	                 p=Pile_push(p,val);
	                 afficher(p);
			         break;
			case 6 : printf("\n\t\tLa somme des elements de notre pile est %d : ",Somme(p));
			         break;
            case 7 : printf("\n\t\tLe produit des elements de notre pile est %d : ",Produit(p));
			         break;
            case 8 : val = Pile_pop(p);
                     printf("\n\t\tL'element qui a ete depile est : %d\n",val);
                     afficher(p);
		             break;
            case 9 : printf("\n\t => La taille de la pile est %d\n",taillePile(p));
                     break;
            case 10 : printf("\t---------------------------------------------------\n");
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
        printf("\t*    1) Tester si une pile est vide              *\n");
        printf("\t*    2) Razer une pile                           *\n");
        printf("\t*    3) Affichage  d'une pile                    *\n");
        printf("\t*    4) Acceder a la tete de la pile             *\n");
        printf("\t*    5) Empiler                                  *\n");
        printf("\t*    6) La somme des elements de la pile         *\n");
        printf("\t*    7) Le produit des elements de la pile       *\n");
        printf("\t*    8) Depiler                                  *\n");
        printf("\t*    9) Taille de la pile                        *\n");
        printf("\t*    10) Quitter                                  *\n");
        printf("\t*****************************************************\n");
        printf("\n\t Votre choix =>  ");
        scanf("%d",&rep);
    }while((rep!=10));

    return 0;
}
