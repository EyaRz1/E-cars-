# E-cars-
Mon projet est une simple application cmd de location de voitures avec une simple interface en ligne de commande //(j'ai utilisée la bibliotheque Windows.h donc si vous utilisez un systeme linux ca va generer une erreur en raison de l'incompatibilité entre les bibliothèques ).
//Remarque : le code est dans main.c mais pour executer cliquez sur project1.exe

Il utilise des structures de données pour stocker les informations sur les voitures et les clients, et les fichiers "catalogue.txt" pour stocker les informations sur les voitures et "hist jour.txt" pour enregistrer l'historique journaliére des locations. (Vous trouverez ces fichiers ci-joint dans le répertoire du programme)

##EXECUTION:
lors de l'execution un messagebox va apparaitre (simplement pour donner à l'application une apparence plus authentique).Puis l'utilisation doit se connecter pour que le menu apparaisse.Le menu comporte 10 options :
         Afficher le catalogue
         Ajouter une voiture
         Supprimer une voiture
         Louer une voiture
         Retourner une voiture
         Ajouter une réclamation
         Afficher les jours restants de location
         Afficher l'historique de location quotidien
         Modifier la description d'une voiture
         Quitter

##Les structures:
j'ai utilisée 2 structures :une nommée voiture (c'est une liste chainée) ayant 7 champs : 
       marque
       couleur
       modele
       annee
       prix
       etat
       suivant ( pointeur qui pointe sur l'element suivant)
et aussi j'ai défini un pointeur sur voiture nommé ptrvoiture.

l'autre structure nommée client comportant 3 champs:
      nom
      prenom
      identifiant
et un pointeur sur client nommé ptrclient
       

##Voici toutes les fonctions et procedures que j'ai utilisée :


affiche_description(ptrvoiture voiture):Affiche la description d'une   voiture(marque/couleur/modele/annee/prix).

cata(ptrvoiture voiture):Affiche les descriptions de toutes les voitures dans le catalogue(a l'aide de la procedure affiche_description)

choix(ptrvoiture voiture):Demande à l'utilisateur de choisir une voiture en affichant le catalogue et retourne le numero de la voiture choisie

modif_description(ptrvoiture voiture):Permet à l'utilisateur de modifier les détails d'une voiture.

consulter_etat(ptrvoiture voiture):Affiche l'état actuel d'une voiture.

modif_etat(ptrvoiture voiture):Permet à l'utilisateur de modifier l'état d'une voiture.

payer_location(float montant, ptrclient cli):Gère le paiement de la location en ligne ou sur place.

ajouter_voiture(ptrvoiture catalogue, ...) : Ajoute une nouvelle voiture au catalogue.

telecharger_catalogue() : Télécharge le catalogue de voitures depuis le fichier "catalogue.txt".

louer(ptrclient client, ptrvoiture catalogue) : Permet au client de louer une voiture et enregistre les détails de la location dans le fichier "hist jour.txt".

ajouter_fichier(ptrvoiture catalogue) : Ajoute les détails du catalogue de voitures au fichier "catalogue.txt".

supprimer_voiture(ptrvoiture catalogue) : Supprime une voiture du catalogue.

reclamation(ptrvoiture voiture) :change l'état d'une voiture en "panne".

retour(ptrvoiture voiture) : Change l'état d'une voiture en "disponible" lorsqu'elle est retournée.

jours_rest(ptrvoiture voiture, ptrclient client) : Calcule les jours restants de la location.

update_fichier(ptrvoiture catalogue) : Met à jour le fichier "catalogue.txt" avec les informations actuelles du catalogue.

testchoix(ptrvoiture catalogue) : Permet à l'utilisateur de choisir une voiture parmi le catalogue.

