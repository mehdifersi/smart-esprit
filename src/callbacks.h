#include <gtk/gtk.h>


void
on_image15_notify                      (GObject         *gobject,
                                        GParamSpec      *arg1,
                                        gpointer         user_data);

void
on_wbutton_ajout_valid_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_wbutton_suppr_valid_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_wbutton_suppr_back_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_acc_modifier_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_acc_actu_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_acc_decnx_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_acc_supprim_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_acc_recherche_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_acc_ajout_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_wbutton_consulter_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_wbutton_modif_valid_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_rec_back_clicked             (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_wbutton_modif_back_clicked          (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_wbutton_recherche_back_clicked      (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_wbutton_recherche_affich_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_radiobutton_ajout_resto_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ajout_heber_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_wbutton_rechercher_back_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_wbutton_espacerec_back_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_wbutton_modifier_back_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);




void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_wbutton_cherch_serv_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_cherch_niv_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_cherch_sat_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
