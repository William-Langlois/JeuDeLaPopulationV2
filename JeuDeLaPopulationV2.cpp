#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; //biblioteques standards

float Taille_Max;//Initialisation du nombre de notes max par matière
float NB_etudiant_Max;//Initialisaton du nombre d'étudiant max
void Max();//Déclaration de la référence à la fonction permettant de définir les valeur des maximums initializer ci-dessus
void Ensemble_Note(int index);//Déclaration de la référence à la fonction permettant de renseigner toutes les notes d'un étudiant donné
void Affichage(int index);//Déclaration de la référence à la fonction permettant d'afficher toutes les notes d'un étudiant donné
float Moyenne(int index);//Déclaration de la référence à la fonction retournant la moyenne calculée d'un étudiant donné
void Afficher_Moyenne(int index);//Déclaration de la référence à la fonction permettant d'afficher la moyenne calculée d'un étudiant donné
void Afficher_Moyennes();//Déclaration de la référence à la fonction permettant d'afficher la moyenne de chaque étudiant
std::vector<std::vector<float>> Notes; //Déclaration d'un tableau permettant de stocker les notes des étudiant
//std::vector<float> moyenne;//Déclaration d'un tableau permettant de stocker les moyennes des étudiant (commenté car la moyenne est désormais calculée à la volée)
int taille;//Déclaration d'un entier contenant le nombre de note par matière entré par utilisateur
int nb_etudiant;//Déclaration d'un entier contenant le nombre d'étudiants entré par l'utilisateur

int main() {
    int j;//Déclaration entier incrémental x1
        Max();//Appel à la fonction permettant de renseigner les valeurs maximal du nombre d'étudiant et de note par matière
    do{
        cout<<"Quelle est le nombre de notes a saisir par matiere : "; //Demander le nombre de note à renseigner par matière
        cin>>taille;//Stocker la valeur entrée dans la variable prévu à cet effet
    }while(taille>Taille_Max);//Tant que le nombre de note par matière entré est supérieur au nombre de note par matière maximal
    do{
        cout<<"Quelle est le nombre d etudiants : ";//Demander le nombre d'étudiants
        cin>>nb_etudiant;//Stocker la valeur entrée dans la variable prévu à cet effet
    }while(nb_etudiant>NB_etudiant_Max);//Tant que le nombre d'étudiant choisi est supérieur au nombre d'étudiant maximal

    for(j=0;j<nb_etudiant;j++)//Pour chaque étudiant
    {
        Ensemble_Note(j);//Appel à la fonction permettant de renseigner l'ensemble des notes de l'étudiant
        Affichage(j);//Appel à la fonction permettant d'afficher l'ensemble des notes de l'étudiant
        Afficher_Moyenne(j);//Appel à la fonction permettant d'afficher la moyenne calculée de l'étudiant
    }//Fin pour tous les utilisateurs
    cout<<"\n";//Affichage d'un saut de ligne (pour la lisibilité)
    Afficher_Moyennes();//Affichage des moyennes de tous les étudiant
}

void Max()//Fonction permettant de définir les valeurs maximale autorisée du nombre de notes par matière et du nombre d'étudiant
{
    cout<<"Nombre de notes maximales par matiere ? ";//Demander le nombre de note maximal par matière
    cin>>Taille_Max;//Stocker la valeur entrée dans la variable prévue à cet effet
    cout<<"Quelle est le nombre d'etudiant maximum ? ";//Demander le nombre maximal d'étudiant
    cin>>NB_etudiant_Max;//Stocker la valeur entrée dans la variable prévue à cet effet
    //moyenne.resize(NB_etudiant_Max);//Redimenssionnement en mémoire en conséquence du tableau contenant les moyennes (commenté car les moyennes ne sont désormais plus stockée mais calculée à la volée)
    Notes.resize(Taille_Max,{NB_etudiant_Max});//Redimenssionnement en mémoire en conséquence du tableau contenant les notes des étudiants
}

void Ensemble_Note(int index)//Fonction permettant de renseigner les note d'un étudiant données
{
    for(int k=0;k<taille;++k)//Pour le nombre de note à renseigner
    {
    cout<<"Entrez note numero "<<k+1<<" : ";//Demande la note n°X
    cin>>Notes[k][index];//Stocker la valeur entrée dans l'emplacement correspondant à l'étudiant dans le tableau des notes
    }//Fin pour le nombre de note à renseigner
}

void Affichage(int index)//Fonction permettant d'afficher l'ensemble des note d'un étudiant donné
{
    string output = "Notes de l'etudiant : \n";//initialization de la chaine de caractère qui sera affichée à l'écran pour lister les notes de l'étudiant
    for(int k = 0 ; k<taille;++k)//Pour chaque note à renseigner
    {
       output+="Numero "+std::to_string(k+1)+" "+std::to_string(Notes[k][index])+"\n"; //On ajoute à la variable qui sera affichée : la note et un saut de ligne
    }//Fin pour chaque note à renseigner
    cout<<output;//On affiche les notes de l'étudiant
}

float Moyenne(int index)//Fonction retournant la moyenne calculée de l'étudiant
{
    float Total_Notes = 0;//Initialization d'un variable qui contiendra la somme totale des notes de l'étudiant (permettra de calculer la moyenne)
    for(int l = 0 ; l<taille;++l)//Pour le nombre de notes à renseigner
    {
        Total_Notes+=Notes[l][index];//On ajoute la variable contenant la somme totale la valeur de note qui est entrain d'être lu
    }//Fin pour le nombre de notes à renseigner
    return Total_Notes/taille;//On retourne la somme totale des notes de l'étudiant divisée par le nombre de note de l'étudiant
}

void Afficher_Moyenne(int index)//FOnction permettant d'afficher la moyenne calculée de l'étudiant
{
    cout<<"La moyenne de l etudiant "<<index+1<<" est "<<Moyenne(index)<<endl;//On affiche la moyenne de l'étudiant en appelant la fonction retournant la moyenne calculée de l'étudiant
}

void Afficher_Moyennes()//Fonction permettant d'afficher la moyenne des tous les étudiant
{
    for(int i=0;i<nb_etudiant;++i)//Pour chaque étudiant
    {
        Afficher_Moyenne(i);//Appeler la fonction permettant d'afficher la moyenne calculée de l'étudiant.
    }//Fin pour chaque étudiant
}
