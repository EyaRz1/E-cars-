#include <windows.h>
#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

typedef struct voiture {
	char marque[10];
	char couleur[10];
	char modele[10];
	int annee;
	float prix;
	char etat[15];
	struct voiture *suivant;
}voiture ;
typedef voiture* ptrvoiture;

typedef struct client {
	char nom[10];
	char prenom[10];
	int identifiant;
} client;
typedef client* ptrclient;


void affiche_description(ptrvoiture voiture) {
	printf("////////////DESCRIPTION////////////\n\n");
	printf("la marque : %s\n",voiture->marque);
	printf("la couleur : %s\n",voiture->couleur);
	printf("le modele  :%s\n",voiture->modele);
	printf("annee  : %d\n",voiture->annee);
	printf("prix  : %f\n",voiture->prix);
	printf("etat  : %s\n",voiture->etat);
	
}

void cata(ptrvoiture voiture) {
	int i=0;
	ptrvoiture p=voiture;
	while(p) {
		i++;
		printf("\nvoiture %d :",i);
		affiche_description(p);
		p=p->suivant;
		
	}	
}


int choix(ptrvoiture voiture) {
	int num;
	cata(voiture);
	printf("quel est votre choix ?");
	printf("donnez le numero de la voiture choisie\n");
	scanf("%d",&num);
	return num;
}

void modif_description(ptrvoiture voiture) {
	int n,d;
	float f;
	char s[10];
	printf("qu'est ce que vous voulez changer ?/n/n");
	printf("1) la marque\n");
	printf("2) la couleur\n");
	printf("3) le modele\n");
	printf("4) l'annee\n");
	printf("5) le prix\n");
	scanf("%d",&n);
	switch (n) {
		case 1:printf("nouvelle marque   :  ");
		       scanf("%s",s); 
		       strcpy(voiture->marque,s);
		       break;
		case 2 :printf("nouvelle couleur   :  ");
		        scanf("%s",s); 
		       strcpy(voiture->couleur, s);
		       break;
		case 3: printf("nouveau modele   :  ");
		        scanf("%s",s);
		        strcpy(voiture->modele,s);
		        break;
		case 4: printf("nouvelle annee   :  ");
		       scanf("%d",&d); 
		       voiture->annee=d;
		       break;
		case 5:printf("nouveau prix   :  ");
		         scanf("%f",&f); 
		        voiture->prix=f;
		        break;
		default: 
		printf("invalide\n");
		break;
	}
}





char* consulter_etat(ptrvoiture voiture) {
	printf("cette voiture est : %s",voiture->etat);
	return voiture->etat;
}


void modif_etat(ptrvoiture voiture) {
	int etat;
	consulter_etat(voiture);
	printf("veillez inserer le nouveau etat : \n");
	printf("cliquer 1 pour disponisble \n");
	printf("cliquer 2 pour indisponible \n");
	printf("cliquer  pour en panne \n");
	scanf("%d",&etat);
	switch (etat) {
		case 1:strcpy(voiture->etat,"disponible");
		break;
		case 2:strcpy(voiture->etat, "indisponible");
		break;
		case 3:strcpy(voiture->etat, "en panne");
		break;
		default:
			printf("invalide\n");
			break;
	}
	
}


int payer_location(float montant, ptrclient cli) {
	int a, o ;
	int chiffre;
	printf("Souhaitez-vous payer maintenant en ligne ou sur place lors de la prise de la voiture ?\n ");
    printf("1) en ligne\n");
    printf("2) sur place\n");
    scanf("%d",&a);
    switch (a) {
    	case 1 : printf("connexion a la passerelle de paiement ....\n");
    	         printf("donnez les 4 derniers chiffres de votre carte bancaire\n ");
    	         scanf("%d",&chiffre);
    	         
    	         printf("vous confirmez le paiement ?\n");
    	         printf("1) oui\n");
    	         printf("2) non \n");
    	         scanf("%d",&o);
    	         switch (o) { 
    	               case 2 : printf("vous avez annule le paiement\n");
    	                        return 0;
    	                        break ;
    	                case 1 : printf("vous avez confirme le paiement\n");
    	                         printf("paiement reussi \n ");
    	                         printf("////////// VOICI VOTRE RECU DE PAIEMENT /////////////\n");
    	                         time_t t=time(NULL);
    	                         struct tm *tm =localtime(&t);
                                 char date[20];
                                 strftime(date,20,"%Y-%m-%d %H:%M:%S", tm);
    	                         printf("NOM  :%s\n",cli->nom);
    	                         printf("PRENOM  :%s\n",cli->prenom);
    	                         printf("IDENTIFIANT  :%d\n",cli->identifiant);
    	                         printf("A PAYE UN MONTANT DE :%f\n",montant);
    	                         printf("DATE DE PAIEMENT : %s\n",date);
    	                         printf("Apportez s'il vous plait ce recu lors de la prise de la voiture.");
    	                          return 1; break;
    	                default: printf("invalide\n");
    	                return 0;
    	                break;
				 }               break ;
				 
		case 2 : printf("Assurez vous d'apporter un montant de : %f",montant);
		         printf("a notre etablissement situe a Rades Plage et merci \n ");
				 return 1 ;break;
		default: printf("invalide\n"); return 0 ;
		break;		 
    	
	}
  
}

ptrvoiture ajouter_voiture(ptrvoiture catalogue, char* marque, char* couleur, char* modele, int annee, float prix, char* etat) {
    ptrvoiture nouvelle_voiture = malloc(sizeof(voiture));
    strcpy(nouvelle_voiture->marque, marque);
    strcpy(nouvelle_voiture->couleur, couleur);
    strcpy(nouvelle_voiture->modele, modele);
    nouvelle_voiture->annee = annee;
    nouvelle_voiture->prix = prix;
    strcpy(nouvelle_voiture->etat, etat);
    nouvelle_voiture->suivant = NULL;

    if (catalogue == NULL) {
        return nouvelle_voiture;
    } else {
        ptrvoiture p = catalogue;
        while (p->suivant != NULL) {
            p = p->suivant;
        }
        p->suivant = nouvelle_voiture;
        return catalogue;
    }
}

ptrvoiture telecharger_catalogue() {
    ptrvoiture catalogue = NULL;
    char chaine[256];
    FILE* f = fopen("./catalogue.txt", "r");

    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier en mode lecture\n");
        return NULL;
    }

    while (fgets(chaine, sizeof(chaine), f) != NULL) {
        char mots[10][20];
        int i = 0;
        char* token = strtok(chaine, " \t\n");
        while (token != NULL && i < 10) {
            strcpy(mots[i], token);
            i++;
            token = strtok(NULL, " \t\n");
        }
            catalogue = ajouter_voiture(catalogue, mots[0], mots[1], mots[2], atoi(mots[3]), atof(mots[4]), mots[5]);
    }
    fclose(f);
    return catalogue;
}
   

void louer(ptrclient client,ptrvoiture catalogue) {
	int choice,nombre,j; int i=0; float montant;
	ptrvoiture p=catalogue;
	ptrvoiture choixvoit=NULL;
	printf("\nchoisissez la voiture\n");
	choice=choix(catalogue);
	char* etat;
	while( p &&  i != choice-1) {
		i++; 
		p=p->suivant;
	}
	choixvoit=p;
	etat=consulter_etat(choixvoit);
	if (strcmp(etat,"disponible")==0) {
	printf("\nCombien de jours souhaitez-vous louer cette voiture ?\n");
	scanf("%d",&nombre);
	time_t n;
    time(&n);
    struct tm* date_location = localtime(&n);
	printf("a partir du quel jour? (jj/mm/aaaa)\n");
	scanf("%d/%d/%d",&date_location->tm_mday, &date_location->tm_mon +1, &date_location->tm_year);
	montant=nombre*(choixvoit->prix);
	printf("le montant sera %f\n",montant);
	FILE* f=fopen("./hist jour.txt","a");
	if (f==NULL) {
		printf("\nimpossible d'ouvrir le fichier en mode ajout");
		return;
	}
	fprintf(f,"DATE DE LOCATION %d/%d/%d\n",date_location->tm_mday, date_location->tm_mon +1, date_location->tm_year);
	fprintf(f,"CLIENT:%s %s %d\n",client->nom,client->prenom,client->identifiant);
	fprintf(f,"VOITURE/ %s %s %s %d\n",choixvoit->marque,choixvoit->modele,choixvoit->couleur,choixvoit->annee);
	fprintf(f,"MONTANT: %f\n",montant);
	fprintf(f,"//////////////////////////\n");
	fclose(f);
} else {
	printf("la voiture n'est pas disponible pour le moment.\n");
}
 j=payer_location(montant, client);
 strcpy(choixvoit->etat,"indisponible");
 
}




void ajouter_fichier(ptrvoiture catalogue) {
	ptrvoiture p;
	FILE* f=fopen("./catalogue.txt","w");
	if (f== NULL) {
		printf("/nimpossible d'ouvrir le fichier en mode ecriture");
		return ;
	}
	p=catalogue;
	while (p) {
		fprintf(f, "%s %s %s %d %f %s\n",p->marque, p->couleur, p->modele, p->annee, p->prix, p->etat);
	    p=p->suivant;
	} fclose(f);
}


ptrvoiture supprimer_voiture(ptrvoiture catalogue) {
	ptrvoiture p,l;
	ptrvoiture prec=NULL;
	int i=0;
	char marque[10];
	char couleur[10];
	char modele[10];
	int annee;
	printf("donner la marque de la voiture a supprimer\n");
	scanf("%s",marque);
	printf("donner la couleur de la voiture a supprimer\n");
	scanf("%s",couleur);
	printf("donner le modele de la voiture a supprimer\n");
	scanf("%s",modele);
	printf("donner l'annee de la voiture a supprimer\n");
	scanf("%d",&annee);
	l=catalogue;
	while (l) {
		i++;
		if (strcmp(l->marque,marque)==0 &&strcmp(l->couleur,couleur)==0 && strcmp(l->modele,modele)==0 &&l->annee==annee)
		{ if (prec==NULL) {
			catalogue=l->suivant;
		} else {
			prec->suivant=l->suivant;
		}
		free(l);
		printf("suppression reussi");
		return catalogue;
		}
		prec=l;
		l=l->suivant;
	}
	printf("voiture introuvable");
	return catalogue; }
	
	void reclamation(ptrvoiture voiture) {
		printf("etat voiture avant %s\n",voiture->etat);
		strcpy(voiture->etat, "panne");
		printf("etat voiture apres %s\n",voiture->etat);
		printf("\nreclamation bien enregistree\n"); }
	
	
	void retour(ptrvoiture voiture) {
		printf("etat voiture avant %s\n",voiture->etat);
		strcpy(voiture->etat, "disponible");
		printf("etat voiture apres %s\n",voiture->etat);
	}
	
	
	int jours_rest(ptrvoiture voiture, ptrclient client) {
		time_t tawa ;
		int sec,jours;
		time(&tawa);
		struct tm date_retour = {0};
		printf("Donnez la date de retour prévue (jj/mm/aaaa)\n");
        scanf("%d/%d/%d",&date_retour.tm_mday,&date_retour.tm_mon, &date_retour.tm_year);
		time_t date_retour_timestamp=mktime(&date_retour);
		sec= difftime(date_retour_timestamp,tawa);
		jours= sec/(24*60*60);
		return jours;
	}
	void update_fichier(ptrvoiture catalogue) {
		ptrvoiture p;
		FILE* f=fopen("./catalogue.txt", "w");
		if (f==NULL) {
			printf("\nimpossible d'ouvrir le fichier en mode ecriture.");
		     return ;}
		p=catalogue;
		while (p !=NULL) {
			fprintf(f, "%s %s %s %d %f %s\n",p->marque,p->couleur,p->modele,p->annee,p->prix,p->etat);
			p=p->suivant;
		} fclose(f);
		}
	
ptrvoiture testchoix(ptrvoiture catalogue) {
    int choix;
     int i = 1;
    ptrvoiture voitureChoisie = NULL;
    printf("Voici le catalogue de nos voitures.\n");
    cata(catalogue);
    printf("Entrez le numero de la voiture choisie :\n");
    scanf("%d", &choix);
    ptrvoiture p = catalogue;

    while (p != NULL) {
        if (i==choix) {
            voitureChoisie = p;
            break;
        }
        i++;
        p = p->suivant;
    } if (voitureChoisie == NULL) {
        printf("Voiture non trouvée.\n");
    }

    return voitureChoisie;
}


	

int main() {
ptrclient client=malloc(sizeof(client));
ptrvoiture catalogue, catalogue1,v;
FILE* f;
char ligne[256];
char marque[10];
	char couleur[10];
	char modele[10];
	int annee;
	float prix;
	char etat[15];
int ey,nbr_voit;	
 MessageBox(NULL,"Bienvenue dans mon application de location de voitures. Souhaitez-vous poursuivre ?","E-cars", MB_OK);
 printf("////////////////////////CONNEXION////////////////////////\n");
 printf("donnez votre nom\n");
 scanf("%s",client->nom);
 printf("donnez votre prenom\n");
 scanf("%s",client->prenom);
 printf("donnez votre identifiant (c'est un nombre)\n");
 scanf("%d",&client->identifiant);
 printf("Bonjour %s %s\n",client->nom,client->prenom);
 printf("\nvoici le menu\n");
 do {
 
 
 printf("\n\n//////////////////// MENU ////////////////////\n\n\n\n");
 printf("1) Afficher le catalogue\n");
 printf("2) Ajouter une voiture\n");
 printf("3) Supprimer une voiture\n");
 printf("4) Louer une voiture\n");
 printf("5) retourner une voiture\n");
 printf("6) Ajouter une reclamation\n");
 printf("7) Afficher les jours restants de ta location\n");
 printf("8)afficher l'historique de location journalire \n");
 printf("9) modifier la description d'une voiture\n");
 printf("10) Quitter\n");
 printf("////////////////////////////////////////n");
 printf("quel est votre choix ?\n");
 scanf("%d",&ey);
 switch (ey) {
 	case 1 : catalogue=telecharger_catalogue() ;
 	         cata(catalogue) ;
 	         while(catalogue != NULL) {
                 ptrvoiture p=catalogue;
                 catalogue=catalogue->suivant;
                 free(p);
    }system("PAUSE");
system("CLS");
 	        break;
 	case 2 : catalogue= telecharger_catalogue();
 	        printf("donnez la marque de la nouvelle voiture\n");
	scanf("%s",marque);
	printf("donnez la couleur de la nouvelle voiture\n");
	scanf("%s",couleur);
	printf("donnez le modele de la nouvelle voiture\n");
	scanf("%s",modele);
	printf("donnez l'annee de la nouvelle voiture\n");
	scanf("%d",&annee);
	printf("donnez le prix de la nouvelle voiture\n");
	scanf("%f",&prix);
	printf("donnez l'etat' de la nouvelle voiture\n");
	scanf("%s",etat);
 	         catalogue1=ajouter_voiture(catalogue,marque,couleur,modele,annee,prix,etat);
 	         ajouter_fichier(catalogue1);
 	         printf("voiture ajoutee !");
 	         system("PAUSE");
system("CLS");
 	        break;
 	case 3 : catalogue= telecharger_catalogue();
 	         catalogue1=supprimer_voiture(catalogue);
 	         update_fichier(catalogue1);
 	         system("PAUSE");
system("CLS");
 	         break;
 	case 4: catalogue= telecharger_catalogue();
 	        louer(client,catalogue);
 	        update_fichier(catalogue);
 	        system("PAUSE");
system("CLS");
 	        break;
 	case 5 :catalogue= telecharger_catalogue();
 	       v=testchoix(catalogue);
 	       retour(v);
 	       update_fichier(catalogue);
 	       system("PAUSE");
system("CLS");
 	       break;
 	case 6 :printf("voici le catalogue de nos voitures choisissez celle que voulez reclamer\n");
	        catalogue= telecharger_catalogue();
	        
	        v=testchoix(catalogue);
 	        reclamation(v);
 	        update_fichier(catalogue);
 	        system("PAUSE");
system("CLS");
 	        break;
 	    
 	case 7 :catalogue= telecharger_catalogue();
 	        printf("jours restants : %d\n",jours_rest(testchoix(catalogue),client));
 	        system("PAUSE");
system("CLS");
 	        break;
 	       
 	case 8 : f=fopen("./hist jour.txt","r");
 	        if (f==NULL) {
			printf("\nimpossible d'ouvrir le fichier en mode lecture.");
		     return -1;}
		     while (fgets(ligne,256,f) !=NULL) {
		     	printf("%s",ligne);
		     	
			 }fclose(f);
			 system("PAUSE");
system("CLS");
			 break ;
	case 9: catalogue= telecharger_catalogue();
 	       v=testchoix(catalogue);
 	       modif_description(v);
 	       update_fichier(catalogue);
 	       system("PAUSE");
        system("CLS");
 	       break;
 	       
	case 10 : break;
	default: printf("invalide ! reessayer !\n");
	         break;
 } 
}while(ey !=10);
free(client);
return 0 ;
  }
