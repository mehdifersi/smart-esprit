#include "Reclamation.h" 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 


/*void affiche_service_plus_reclame(char file[])
{ 
FILE *f; 
reclamation rec; 
int r,h; 
f=fopen(file,"r"); 
if(f !=NULL)
{
 while(fscanf( f, "%s %s %d/%d/%d %s %d\n", rec.username, rec.id_rec, rec.daterec.jour, rec.daterec.mois, rec.daterec.annee, rec.service, rec.note ) != EOF )
{ 

if(strcmp(rec.service,"restauration")==0)
}
r++; 
} 
else if(strcmp(rec.service,"hebergement")==0)
{
h++; 
} 
}  
if (h>r)
{ 
printf("\n le service le plus reclame est : hebergemeent "); 
} 

else 
{ 
printf("\n le service le plus reclame est : restauration "); 
} 
fclose(f); 
} 
else 
{ 
printf( "file doesn't exist or already open."); 
} 
} 
*/


//fonction ajout
void ajout_rec(reclamation rec)
{
FILE *f; 
f = fopen("reclamation.txt", "a+"); 
if(f!=NULL)
{ 
fprintf(f,"%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, rec.note,rec.reclame, rec.deg, rec.date.jour, rec.date.mois, rec.date.annee); 
} 

fclose(f); 
} 

//fonction modifier
void modifier_rec(reclamation recl) 
{
FILE *f;
FILE *f1; 
reclamation rec; 
f=fopen("reclamation.txt","r"); 
f1=fopen("reclamation1.txt", "w"); 
if( f != NULL)
{ 
 
while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, &rec.note,rec.reclame, rec.deg, &rec.date.jour, &rec.date.mois, &rec.date.annee) !=EOF)
{ 
if(strcmp(recl.idrec, rec.idrec)==0)
{ 
fprintf( f1, "%s %s %s %d %s %s %d %d %d \n",recl.id, recl.idrec, recl.type, recl.note,recl.reclame, recl.deg, recl.date.jour, recl.date.mois, recl.date.annee); 
} 
else 
{ 
fprintf( f1, "%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, rec.note,rec.reclame, rec.deg, rec.date.jour, rec.date.mois, rec.date.annee); 
} 
} 
fclose(f); 
fclose(f1); 
remove("reclamation.txt"); 
rename("reclamation1.txt", "reclamation.txt");  
} 
}

void supprimer_rec(char id[]) 
{ 
FILE *f; 
FILE *f1; 
reclamation rec; 
f=fopen("reclamation.txt","r"); 
f1=fopen("reclamation1.txt", "w"); 
if(f != NULL)
{ 
if(idExist(id) == 1)
{ 

while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, &rec.note,rec.reclame, rec.deg, &rec.date.jour, &rec.date.mois, &rec.date.annee)!= EOF)
{ 
	if(strcmp(rec.idrec,id)!=0) 
{ 
	fprintf(f1,"%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, rec.note,rec.reclame, rec.deg, rec.date.jour, rec.date.mois, rec.date.annee);  
} 
} 
fclose(f); 
fclose(f1); 
remove("reclamation.txt"); 
rename("reclamation1.txt", "reclamation.txt"); 
} 
}
}


int chercher(char id[]) 
{ 
int trouve=-1; 
FILE *f=NULL; 
reclamation rec2; 
f=fopen("reclamation.txt","r"); 

if(f!=NULL) 
{ 
while(fscanf( f, " id= %s \t idrec= %s \t  type= %s \t note= %d \t reclame= %s \t deg= %s \t date : %d /  %d /  %d  \n",rec2.id, rec2.idrec, rec2.type, &rec2.note,rec2.reclame, rec2.deg, &rec2.date.jour, &rec2.date.mois, &rec2.date.annee) != EOF )
{ 
if((strcmp(rec2.idrec, id)==0))
{ 
trouve=1; 
} 
} 
fclose(f); 
} 

return (trouve); 
} 

int idExist(char id[])
{
    reclamation rec ;
    FILE *f;
	int x=0;
    f = fopen("reclamation.txt","r");
    if(f != NULL){
        while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, &rec.note,rec.reclame, rec.deg, &rec.date.jour, &rec.date.mois, &rec.date.annee) != EOF)
        {
            if(strcmp(rec.idrec,id) == 0)
            {
                    x=1;
		
		
            }
        }}
	
    fclose(f);
return x;
}

enum
{
USERNAME,
ID_REC,
TYPE,
DATE,
NOTE,
DEGREE, 
RECLAME,
COLUMNS,

};
void chercher_rec(GtkWidget *liste,char identif[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int j,m,a;int ch_note;
char ch_id[100],ch_user[100],ch_type[100],ch_date[100],ch_degree[100],ch_reclame[100];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("USERNAME",renderer,"text",USERNAME,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("IDENTIFIANT",renderer,"text",ID_REC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("NOTE",renderer,"text",NOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DEGREE",renderer,"text",DEGREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);

FILE *f=NULL;
f=fopen("reclamation.txt","r");
if(f!=NULL)
{
f=fopen("reclamation.txt","a+");
while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",ch_user,ch_id,ch_type,&ch_note,ch_reclame,ch_degree,&j,&m,&a)!=EOF)
{
if (strcmp(identif,ch_id)==0)
{
sprintf(ch_date,"%d/%d/%d",j,m,a);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,USERNAME,ch_user,ID_REC,ch_id,TYPE,ch_type,DATE,ch_date,NOTE,ch_note,DEGREE,ch_degree,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

void vider(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int j,m,a;
char ch_i[100],ch_u[100],ch_s[100],ch_n[100],ch[100],ch_niv[100],ch_sat[100];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("USERNAME",renderer,"text",USERNAME,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("IDENTIFIANT",renderer,"text",ID_REC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("NOTE",renderer,"text",NOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DEGREE",renderer,"text",DEGREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

void afficher_rec(GtkWidget *liste) 
{ 

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int j,m,a; int ch_note;
char ch_id[100],ch_user[100],ch_type[100],ch_date[100],ch_degree[100],ch_reclame[100];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("USERNAME",renderer,"text",USERNAME,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("IDENTIFIANT",renderer,"text",ID_REC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("NOTE",renderer,"text",NOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DEGREE",renderer,"text",DEGREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);

FILE *f=NULL;
f=fopen("reclamation.txt","r");
if(f!=NULL)
{
f=fopen("reclamation.txt","a+");
while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",ch_user,ch_id,ch_type,&ch_note,ch_reclame,ch_degree,&j,&m,&a)!=EOF)
{


sprintf(ch_date,"%d/%d/%d",j,m,a);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,USERNAME,ch_user,ID_REC,ch_id,TYPE,ch_type,DATE,ch_date,NOTE,ch_note,DEGREE,ch_degree,-1);
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
} 




int username_exist(char username[])
{
    reclamation rec ;
    FILE *f;
int b=0;
    f = fopen("reclamation.txt","r");
    if(f != NULL){
        while(fscanf(f," id= %s \t idrec= %s \t  type= %s \t note= %d \t reclame= %s \t deg= %s \t date : %d /  %d /  %d  \n",rec.id, rec.idrec, rec.type, &rec.note,rec.reclame, rec.deg, &rec.date.jour, &rec.date.mois, &rec.date.annee)!= EOF)
        {
            //if(strcmp(rec.idrec,rec) == 0)
            {
                    b=1;
            }
        }
}
    fclose(f);
return b;
}
int chercher_id (reclamation *r, char id[])
{
    reclamation rec ;
    FILE *f;
int b=0;
    f = fopen("reclamation.txt","r");
    if(f != NULL){
        while(fscanf(f," id= %s \t idrec= %s \t  type= %s \t note= %d \t reclame= %s \t deg= %s \t date : %d /  %d /  %d  \n",rec.id, rec.idrec, rec.type, &rec.note,rec.reclame, rec.deg, &rec.date.jour, &rec.date.mois, &rec.date.annee) != EOF)
        {
            if(strcmp(rec.idrec,id) == 0)
            {
		*r=rec;
                    b=1;
            }
        }
}
    fclose(f);
return b;
}

void afficher_service(GtkWidget *liste, char ch11[200])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int j,m,a;int ch_note;
char ch_id[100],ch_user[100],ch_type[100],ch_date[100],ch_degree[100],ch_reclame[100];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("USERNAME",renderer,"text",USERNAME,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("IDENTIFIANT",renderer,"text",ID_REC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("NOTE",renderer,"text",NOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DEGREE",renderer,"text",DEGREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
FILE *f=NULL;
f=fopen("reclamation.txt","r");
if(f!=NULL)
{
f=fopen("reclamation.txt","a+");
while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",ch_user,ch_id,ch_type,&ch_note,ch_reclame,ch_degree,&j,&m,&a)!=EOF)
{


sprintf(ch_date,"%d/%d/%d",j,m,a);
if (strcmp(ch11,ch_type)==0)
{

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,USERNAME,ch_user,ID_REC,ch_id,TYPE,ch_type,DATE,ch_date,NOTE,ch_note,DEGREE,ch_degree,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

void afficher_niveau(GtkWidget *liste, char ch22[200])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int j,m,a;int ch_note;
char ch_id[100],ch_user[100],ch_type[100],ch_date[100],ch_degree[100],ch_reclame[100];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("USERNAME",renderer,"text",USERNAME,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("IDENTIFIANT",renderer,"text",ID_REC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("NOTE",renderer,"text",NOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DEGREE",renderer,"text",DEGREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
FILE *f=NULL;
f=fopen("reclamation.txt","r");
if(f!=NULL)
{
f=fopen("reclamation.txt","a+");
while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",ch_user,ch_id,ch_type,&ch_note,ch_reclame,ch_degree,&j,&m,&a)!=EOF)
{


sprintf(ch_date,"%d/%d/%d",j,m,a);
if (strcmp(ch22,ch_degree)==0)
{

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,USERNAME,ch_user,ID_REC,ch_id,TYPE,ch_type,DATE,ch_date,NOTE,ch_note,DEGREE,ch_degree,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

void afficher_satif(GtkWidget *liste, char ch33[200])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
int j,m,a;
char ch_i[100],ch_u[100],ch_s[100],ch_n[100],ch[100],ch_niv[100],ch_sat[100];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("IDENTIFIANT",renderer,"text",ID_REC,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("USERNAME",renderer,"text",USERNAME,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("RECLAMATION",renderer,"text",NOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DEGREE",renderer,"text",DEGREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f=NULL;
f=fopen("reclamation.txt","r");
if(f!=NULL)
{
f=fopen("reclamation.txt","a+");
while(fscanf(f,"%s %s %d/%d/%d %s %s %s %s \n",ch_u,ch_i,&j,&m,&a,ch_s,ch_niv,ch_n,ch_sat)!=EOF)
{


sprintf(ch,"%d/%d/%d",j,m,a);
if (strcmp(ch33,ch_sat)==0)
{

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,USERNAME,ch_u,ID_REC,ch_i,DATE,ch,TYPE,ch_s,DEGREE,ch_niv,NOTE,ch_n,RECLAME,ch_sat,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}














//find//
reclamation find11(char id[])
{
    reclamation rec;
reclamation a;
    FILE *f;
    f = fopen("reclamation.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, &rec.note,rec.reclame, rec.deg, &rec.date.jour, &rec.date.mois, &rec.date.annee)!= EOF)
{
        	if(strcmp(rec.idrec,id) == 0){
       		     a=rec;
			printf("%s",a.id);
			printf("%s",a.idrec);
        	}
    	}
}

    fclose(f);
  return a;  
}


void supprimer244(reclamation p)
{

FILE *f, *g;
reclamation rec;
f=fopen("reclamation.txt","r");
g=fopen("reclamation50.txt","w");

if (f==NULL || g==NULL)
{
return;
}

else 
{
		while(fscanf(f,"%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, &rec.note,rec.reclame, rec.deg, &rec.date.jour, &rec.date.mois, &rec.date.annee)!=EOF)
{
						if  (  (strcmp(p.id,rec.id)!=0 )|| (strcmp(rec.idrec,p.idrec)!=0 )||( strcmp(rec.type,p.type)!=0) || (strcmp(rec.deg,p.deg)!=0)  || (rec.note!=p.note) )

				fprintf(g,"%s %s %s %d %s %s %d %d %d \n",rec.id, rec.idrec, rec.type, rec.note,rec.reclame, rec.deg, rec.date.jour, rec.date.mois, rec.date.annee);

}


fclose(f);
fclose(g);
remove("reclamation.txt");
rename("reclamation50.txt","reclamation.txt");

}
}

