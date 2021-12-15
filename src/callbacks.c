#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Reclamation.h"
int x =1;
int choix[] ={0,0};
void
on_image15_notify                      (GObject         *gobject,
                                        GParamSpec      *arg1,
                                        gpointer         user_data)
{

}


void
on_wbutton_ajout_valid_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *mentry_ajout_user;
GtkWidget *mentry_ajout_id;
GtkWidget *calendargca;
GtkWidget *radiobutton_ajout_heber;
GtkWidget *radiobutton_ajout_resto;
GtkWidget *spin1;
GtkWidget *mentry_ajout_rec;
GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *b;
GtkWidget *oui;
GtkWidget *ajouter;
char texte[200];
char texte1[200];
char texte2[200];
int an,m,j;
reclamation rec;


oui = lookup_widget(objet_graphique, "checkbutton1") ;

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(oui)))
{strcpy(rec.satif,"Oui");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(oui))==0)
{strcpy(rec.satif,"Non");}


b = lookup_widget(objet_graphique, "mcomboboxentry_urgence") ;
strcpy(rec.deg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(b)));
ajouter=lookup_widget(objet_graphique,"espace_reclamation");
calendargca = lookup_widget(ajouter,"calendar1");
gtk_calendar_get_date(GTK_CALENDAR(calendargca),&an,&m,&j);
rec.date.jour=j;
rec.date.mois=m+1;
rec.date.annee=an;
mentry_ajout_user = lookup_widget(objet_graphique,"mentry_ajout_user");
mentry_ajout_id = lookup_widget(objet_graphique,"mentry_ajout_id");

strcpy(rec.id,gtk_entry_get_text(GTK_ENTRY(mentry_ajout_user)));
strcpy(rec.idrec,gtk_entry_get_text(GTK_ENTRY(mentry_ajout_id)));

radiobutton_ajout_heber = lookup_widget(objet_graphique,"radiobutton_ajout_heber");
radiobutton_ajout_resto = lookup_widget(objet_graphique,"radiobutton_ajout_resto");
mentry_ajout_rec = lookup_widget(objet_graphique,"mentry_ajout_rec");




/*rec.date_rec.jours = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_ajout_jour));
rec.date_rec.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_ajout_mois));
rec.date_rec.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_ajout_ann));*/

if (x==1) 
	strcpy(rec.type,"restauration");

if(x==2) 
	strcpy(rec.type,"hebergement"); 
spin1= lookup_widget(objet_graphique,"spinbutton1");

rec.note = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin1));

strcpy(rec.reclame,gtk_entry_get_text(GTK_ENTRY(mentry_ajout_rec)));   

printf("%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, rec.note,rec.reclame, rec.deg, rec.date.jour, rec.date.mois, rec.date.annee);

                if(idExist(rec.idrec)==1)
{
		sprintf(texte1,"❌  cet ID existe deja!");
		output1 = lookup_widget(objet_graphique,"labelm_id");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output1),texte1);
}
         
       

else
{
ajout_rec(rec);	
sprintf(texte,"");
		output = lookup_widget(objet_graphique,"labelm_user");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
sprintf(texte1,"");
		output1 = lookup_widget(objet_graphique,"labelm_id");
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output1),texte1);

sprintf(texte2," ✔️ votre réclamation a été bien envoyée ");
		output2 = lookup_widget(objet_graphique,"labelm_rec");
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output2, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output2),texte2);




}
}






void
on_wbutton_suppr_valid_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *input;
	GtkWidget *output;
	char id[20];
	char texte[100];

	input = lookup_widget(objet_graphique,"mentry_suppr_id");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
	if(idExist(id))
             {
		supprimer_rec(id);		
		sprintf(texte,"✔️ Votre suppression à été effectué avec succés\n");
		output = lookup_widget(objet_graphique,"labelmessage");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
		
		
	   }
	else{
		sprintf(texte,"❌ Cet id n'existe pas\n");
		output = lookup_widget(objet_graphique,"labelmessage");
		GdkColor color;
		gdk_color_parse ("#ff250d", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);	
	} 


}


void
on_wbutton_suppr_back_clicked          (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *acceuil;
supprimer=lookup_widget(objet_graphique,"supprimer");
acceuil =create_acceuil ();
gtk_widget_show(acceuil);
gtk_widget_destroy(supprimer);
GtkWidget *treeview1;
treeview1=lookup_widget(acceuil,"treeview1");
afficher_rec(treeview1);
}


void
on_button_acc_modifier_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifier_rec;
GtkWidget *acceuil;
acceuil=lookup_widget(objet_graphique,"acceuil");
modifier_rec= create_modifier_rec ();
gtk_widget_show(modifier_rec);
gtk_widget_destroy(acceuil);
}


void
on_button_acc_actu_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *acceuil,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet_graphique,"acceuil");
acceuil=create_acceuil();

gtk_widget_show(acceuil);

gtk_widget_hide(w1);
treeview1=lookup_widget(acceuil,"treeview1");

vider(treeview1);
afficher_rec(treeview1);

}


void
on_button_acc_decnx_clicked            (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_acc_supprim_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *acceuil;
acceuil=lookup_widget(objet_graphique,"acceuil");
supprimer =create_supprimer ();
gtk_widget_show(supprimer);
gtk_widget_destroy(acceuil);
}


void
on_button_acc_recherche_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rechercher;
GtkWidget *acceuil;
acceuil=lookup_widget(objet_graphique,"acceuil");
rechercher= create_rechercher ();
gtk_widget_show(rechercher);
gtk_widget_destroy(acceuil);
}


void
on_button_acc_ajout_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_reclamation;
GtkWidget *acceuil;
acceuil=lookup_widget(objet_graphique,"acceuil");
espace_reclamation= create_espace_reclamation ();
gtk_widget_show(espace_reclamation);
gtk_widget_destroy(acceuil);
}


void
on_wbutton_consulter_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wentry_ajout_user;
GtkWidget *wentry_ajout_id;
GtkWidget *spinbutton_ajout_jour;
GtkWidget *spinbutton_ajout_mois;
GtkWidget *spinbutton_ajout_ann;
GtkWidget *radiobutton_ajout_heber;
GtkWidget *radiobutton_ajout_resto,*output;
GtkWidget *wentry_ajout_rec;
GtkWidget *mz_spinbutton2;
GtkWidget *satifoui;
GtkWidget *b;
reclamation rec;
char id[20];
char texte[100];
char idrec[200];

satifoui = lookup_widget(objet_graphique, "checkbuttonmodif") ;
b = lookup_widget(objet_graphique, "wcomboboxentry_niveaum") ;
wentry_ajout_user = lookup_widget(objet_graphique,"mentry_modif_user");
wentry_ajout_id = lookup_widget(objet_graphique,"mentry_modif_id");
spinbutton_ajout_jour = lookup_widget(objet_graphique,"spinbutton_modif_jour");
spinbutton_ajout_mois = lookup_widget(objet_graphique,"spinbutton_modif_mois");
spinbutton_ajout_ann = lookup_widget(objet_graphique,"spinbutton_modif_ann");
radiobutton_ajout_heber = lookup_widget(objet_graphique,"radiobutton_modif_heber");
radiobutton_ajout_resto = lookup_widget(objet_graphique,"radiobutton_modif_resto");
wentry_ajout_rec = lookup_widget(objet_graphique,"mentry_modif_rec");
reclamation r;
mz_spinbutton2 = lookup_widget(objet_graphique,"mz_spinbutton2");



strcpy(idrec,gtk_entry_get_text(GTK_ENTRY(wentry_ajout_id)));

if (idExist(idrec)==1)
{ 	r=find11(idrec);

gtk_entry_set_text(GTK_ENTRY(wentry_ajout_id ),r.idrec);
gtk_entry_set_text(GTK_ENTRY(wentry_ajout_user),r.id);
gtk_entry_set_text(GTK_ENTRY(wentry_ajout_rec ),r.reclame);

if( strcmp(r.type,"restauration")==0)
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (radiobutton_ajout_resto),TRUE);
}
else 
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (radiobutton_ajout_heber),TRUE);
}

if(strcmp(r.satif,"Oui")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(satifoui),TRUE);}
else 
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(satifoui),FALSE);}

gtk_spin_button_set_value(spinbutton_ajout_jour,r.date.jour);
gtk_spin_button_set_value(spinbutton_ajout_mois,r.date.mois);
gtk_spin_button_set_value(spinbutton_ajout_ann,r.date.annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mz_spinbutton2),r.note);
int i=0;
char n[200][200]={"restauration","hebergement"};

while((i<5)&&(strcmp(n[i],r.type)!=0))
{i=i+1;}
gtk_combo_box_set_active(GTK_COMBO_BOX(b),i);


sprintf(texte,"");
output=lookup_widget(objet_graphique,"labelm_modif");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(output),texte);

}
else
{
sprintf(texte,"❌ Cet ID existe dèja");
output=lookup_widget(objet_graphique,"labelm_modif");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(output),texte);


}
}


void
on_wbutton_modif_valid_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *wentry_ajout_user;
GtkWidget *wentry_ajout_id;
GtkWidget *spinbutton_ajout_jour;
GtkWidget *spinbutton_ajout_mois;
GtkWidget *spinbutton_ajout_ann;
GtkWidget *radiobutton_ajout_heber;
GtkWidget *radiobutton_ajout_resto,*output;
GtkWidget *wentry_ajout_rec;
GtkWidget *satifoui,*mz_spinbutton2;
GtkWidget *b;
reclamation rec;
char id[20];
char texte[100];

satifoui = lookup_widget(objet_graphique, "checkbuttonmodif") ;

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(satifoui)))
{strcpy(rec.satif,"Oui");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(satifoui))==0)
{strcpy(rec.satif,"Non");}

b = lookup_widget(objet_graphique, "wcomboboxentry_niveaum") ;
strcpy(rec.deg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(b)));

wentry_ajout_user = lookup_widget(objet_graphique,"mentry_modif_user");
wentry_ajout_id = lookup_widget(objet_graphique,"mentry_modif_id");
spinbutton_ajout_jour = lookup_widget(objet_graphique,"spinbutton_modif_jour");
spinbutton_ajout_mois = lookup_widget(objet_graphique,"spinbutton_modif_mois");
spinbutton_ajout_ann = lookup_widget(objet_graphique,"spinbutton_modif_ann");
radiobutton_ajout_heber = lookup_widget(objet_graphique,"radiobutton_modif_heber");
radiobutton_ajout_resto = lookup_widget(objet_graphique,"radiobutton_modif_resto");
wentry_ajout_rec = lookup_widget(objet_graphique,"mentry_modif_rec");
mz_spinbutton2 = lookup_widget(objet_graphique,"mz_spinbutton2");


strcpy(rec.id,gtk_entry_get_text(GTK_ENTRY(wentry_ajout_user)));
strcpy(rec.idrec,gtk_entry_get_text(GTK_ENTRY(wentry_ajout_id)));
strcpy(rec.reclame,gtk_entry_get_text(GTK_ENTRY(wentry_ajout_rec)));

rec.date.jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_ajout_jour));
rec.date.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_ajout_mois));
rec.date.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_ajout_ann));

if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (radiobutton_ajout_resto))) 
	strcpy(rec.type,"restauration");

if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (radiobutton_ajout_heber))) 
	strcpy(rec.type,"hebergement"); 

rec.note = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mz_spinbutton2));


if(idExist(rec.idrec))
             {
		modifier_rec(rec);		
		sprintf(texte,"✔️ Votre réclamation à été modifié avec succés\n");
		output = lookup_widget(objet_graphique,"labelm_modif");
		GdkColor color;
		gdk_color_parse ("#40e61a", &color);
		gtk_widget_modify_fg (output, GTK_STATE_NORMAL, &color);
    		gtk_label_set_text(GTK_LABEL(output),texte);
		
		
	   }}

/*GtkWidget *modifierw;
GtkWidget *acceuil;
modifierw=lookup_widget(objet_graphique,"modifier_rec");
acceuil =create_acceuil ();
gtk_widget_show(acceuil);
gtk_widget_destroy(modifier_rec);
}*/




void
on_button_rec_back_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_reclamation;
GtkWidget *acceuil;
espace_reclamation=lookup_widget(objet_graphique,"espace_reclamation");
acceuil =create_acceuil ();
gtk_widget_show(acceuil);
gtk_widget_destroy(espace_reclamation);
GtkWidget *treeview1;
treeview1=lookup_widget(acceuil,"treeview1");
afficher_rec(treeview1);

}


void
on_wbutton_modif_back_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifier_rec;
GtkWidget *acceuil;
modifier_rec=lookup_widget(objet_graphique,"modifier_rec");
acceuil =create_acceuil ();
gtk_widget_show(acceuil);
gtk_widget_destroy(modifier_rec);
GtkWidget *treeview1;
treeview1=lookup_widget(acceuil,"treeview1");
afficher_rec(treeview1);
}


void
on_wbutton_recherche_back_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rechercher;
GtkWidget *acceuil;
rechercher=lookup_widget(objet_graphique,"rechercher");
acceuil =create_acceuil ();
gtk_widget_show(acceuil);
gtk_widget_destroy(rechercher);
GtkWidget *treeview1;
treeview1=lookup_widget(acceuil,"treeview1");
afficher_rec(treeview1);
}


void
on_wbutton_recherche_affich_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *idrec, *treeview, *w1 ,*fenetre_chercher;
char identif[100];
idrec=lookup_widget(objet_graphique,"mentry_rechercher_id");
strcpy(identif,gtk_entry_get_text(GTK_ENTRY(idrec)));

w1= lookup_widget(objet_graphique,"rechercher");
fenetre_chercher=create_rechercher();
gtk_widget_show(fenetre_chercher);
gtk_widget_hide(w1);

treeview=lookup_widget(fenetre_chercher,"treeview2");
vider(treeview);
chercher_rec(treeview,identif);
}
void
on_radiobutton_ajout_resto_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobutton_ajout_heber_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}







void
on_wbutton_rechercher_back_clicked     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rechercher;
GtkWidget *acceuil;
rechercher=lookup_widget(objet_graphique,"rechercher");
acceuil =create_acceuil ();
gtk_widget_show(acceuil);
gtk_widget_destroy(rechercher);
GtkWidget *treeview1;
treeview1=lookup_widget(acceuil,"treeview1");
afficher_rec(treeview1);
}




void
on_wbutton_espacerec_back_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_reclamation;
GtkWidget *acceuil;
espace_reclamation=lookup_widget(objet_graphique,"espace_reclamation");
acceuil =create_acceuil ();
gtk_widget_show(acceuil);
gtk_widget_destroy(espace_reclamation);
GtkWidget *treeview1;
treeview1=lookup_widget(acceuil,"treeview1");
afficher_rec(treeview1);
}


void
on_wbutton_modifier_back_clicked       (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifier_rec;
GtkWidget *acceuil;
modifier_rec=lookup_widget(objet_graphique,"modifier_rec");
acceuil =create_acceuil ();
gtk_widget_show(acceuil);
gtk_widget_destroy(modifier_rec);
GtkWidget *treeview1;
treeview1=lookup_widget(acceuil,"treeview1");
afficher_rec(treeview1);
}








void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
char ch[200];
GtkTreeIter iter;
gchar *USERNAME;
gchar *IDREC;
gchar *TYPE;
gchar *DATE;
int NOTE;
gchar *DEGREE;
gchar *SATIF;
reclamation r;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&USERNAME,1,&IDREC,2,&TYPE,3,&DATE,4,&NOTE,5,&DEGREE,-1);
strcpy(r.id,USERNAME);
strcpy(r.idrec,IDREC);
strcpy(r.type,TYPE);
strcpy(r.deg,DEGREE);
r.note=NOTE;



supprimer244(r);
afficher_rec(treeview);
}
}


void
on_wbutton_cherch_serv_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *resto, *heber,*treeview3,*rechercher;
char ch[200];
resto = lookup_widget(objet_graphique,"wradiobutton_resto_r");
heber = lookup_widget(objet_graphique,"wradiobutton_heber_r");
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(resto)))
{
strcpy (ch,"restauration");
}
else if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(heber)))
strcpy (ch,"hebergement");
rechercher=lookup_widget(objet_graphique,"rechercher");
treeview3=lookup_widget(objet_graphique,"treeview3");
vider(treeview3);
afficher_service(treeview3,ch);
}



void
on_button_cherch_niv_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *deg1, *deg2,*deg3,*treeview4,*rechercher;
char ch[200];
deg1 = lookup_widget(objet_graphique,"wradiobutton_n1");
deg2 = lookup_widget(objet_graphique,"wradiobutton_n2");
deg3 = lookup_widget(objet_graphique,"wradiobutton_n3");

if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(deg1)))
{
strcpy (ch,"tres_urgent");
}
else if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(deg2)))
strcpy (ch,"pas_vraiment");

else if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(deg3)))
strcpy (ch,"cest_pas_urgent");


rechercher=lookup_widget(objet_graphique,"rechercher");
treeview4=lookup_widget(objet_graphique,"treeview4");
vider(treeview4);
afficher_niveau(treeview4,ch);
}





void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{char ch[200];
GtkTreeIter iter;
gchar *USERNAME;
gchar *IDREC;
gchar *TYPE;
gchar *DATE;
int NOTE;
gchar *DEGREE;
gchar *SATIF;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&USERNAME,1,&IDREC,2,&TYPE,3,&DATE,4,&NOTE,5,&DEGREE,-1);




//supprimer_rec(ch);
afficher_rec(treeview);

}
}

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{char ch[200];
GtkTreeIter iter;
gchar *USERNAME;
gchar *IDREC;
gchar *TYPE;
gchar *DATE;
int NOTE;
gchar *DEGREE;
gchar *SATIF;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&USERNAME,1,&IDREC,2,&TYPE,3,&DATE,4,&NOTE,5,&DEGREE,-1);




//supprimer_rec(ch);
afficher_rec(treeview);

}}

