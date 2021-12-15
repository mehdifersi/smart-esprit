
#include <gtk/gtk.h>
typedef struct {
	int jour;
	int mois;
	int annee;
	}date;
typedef struct {
	char id[20];
	char idrec[20];
	char type[200];
	char reclame[200];
	char satif[20];
	int note;
	char deg[20];
	date date;
	
	}reclamation;
enum
{
EID,
EIDREC,
ERECLAME,
ENOTE,
EDEG,
ETYPE,
EDATE,
};

//ajout de reclamation 
void ajout_rec(reclamation rec);
//modifier une reclamation
void modifier(reclamation rec);
//supprimer une reclamation
void supprimer(reclamation rec);
//affichage du service le plus reclamé
void affiche_service_plus_reclame(reclamation rec);
//verifier si une reclamation existe dans un fichier 
int verif(reclamation rec);
//afficher la liste des reclamations
void afficher_rec(GtkWidget *liste);

int idExist(char id[]) ;

void vider(GtkWidget *liste);


void chercher_rec(GtkWidget *liste,char identif[]);

int username_exist(char username[]);
void afficher_niveau(GtkWidget *liste, char ch22[200]);
void afficher_service(GtkWidget *liste, char ch11[200]);
void afficher_satif(GtkWidget *liste, char ch33[200]);
reclamation find11(char id[200]);

