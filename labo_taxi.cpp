//---------------------------------------------------------
// Fichier      : labo_taxi.cpp
// Auteur       : Harun Ouweis & Hugo Germano
// Date         : 06.10.2022

// But          : Logiciel permettant de calculer le prix d'une course de taxi
//
// Remarque     : Second laboratoire de PRG1
//
// Modifs       :
//
// Compilateur  : 
//---------------------------------------------------------

#include    <cstdlib>      // EXIT_SUCCESS
#include    <iostream>     // cout et cin
#include    <limits>       //utilisé pour avoir les limites numériques (source: https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus)
#include    <iomanip>
#include    <cmath>

using namespace std;

int main() {
    //déclaration des constantes
    const double    PRISEENCHARGE = 5.00,
                    SUPPPARBAGAGE = 2.60,
                    TARIFMINJOUR  = 1.00,
                    TARIFMINNUIT  = 1.60;
    const int       DEBUTJOURNEE  = 8,
                    FINJOURNEE    = 20,
                    MINDISTANCE   = 0,
                    MAXDISTANCE   = 500,
                    MINNBRBAGAGE  = 0,
                    MAXNBRBAGAGE  = 4,
                    W             = 25;


    //déclaration des variables pour les saisies utilisateur
    int nbrBagage, distance, vitesse, depart;

    //fixe la précision à deux nombres après la virgule
    cout << fixed << setprecision(2);

    //affichage des tarifs à l'utilisateurs
    cout  << left << setw(W) << "Bonjour, ce programme permet de calculer le prix d'une course de taxi" << endl;
    cout  << left << setw(W) << "Voici les conditions" << endl;
    cout  << left << setw(W) << "====================" << endl;
    cout  << left << setw(W) << " - prise en charge  : " << PRISEENCHARGE << endl;
    cout  << left << setw(W) << " - supp par bagage  : " << SUPPPARBAGAGE << endl;
    cout  << left << setw(W) << " - tarif/min (jour) : " << TARIFMINJOUR << endl;
    cout  << left << setw(W) << " - tarif/min (nuit) : " << TARIFMINNUIT << endl;
    cout  << left << setw(W) << " - heures du jour   : " << "[" << DEBUTJOURNEE << "-"<< FINJOURNEE << "]" << endl << endl;
    //prix total par catégories
    double  totalBagages, prixDeCourse, prixTotal, tempsTrajet;


    //SAISIES UTILISATEURS
    cout << "Votre commande" <<endl
         << "=============="<< endl;

    //Bagages
    cout << "- nbre de bagage    [0 - 4] : ";
    cin >> nbrBagage;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (MINNBRBAGAGE <= nbrBagage and nbrBagage<= MAXNBRBAGAGE){
        totalBagages = nbrBagage * SUPPPARBAGAGE;
    }
    else {
        cout << "Votre valeur ne rentre pas dans l'intervalle donné" << endl;
        return (EXIT_FAILURE);
    }

    //Distance
    cout << "- distance [km]   [0 - 500] : ";
    cin >> distance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (MINDISTANCE > distance or distance >MAXDISTANCE){
        cout << "Votre valeur ne rentre pas dans l'intervalle donné" << endl;
        return (EXIT_FAILURE);
    }

    //Vitesse
    cout << "- vitesse [km/h] [50 - 120] : ";
    cin >> vitesse;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(50 <= vitesse and vitesse <= 120){
        tempsTrajet = (double(distance) / vitesse) * 60;
    }
    else {
        cout << "Votre valeur ne rentre pas dans l'intervalle donné" << endl;
        return (EXIT_FAILURE);
    }

    //Départ
    cout << "- depart           [0 - 23] : ";
    cin >> depart;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (0 > depart or depart > 23){
        cout << "Votre valeur ne rentre pas dans l'intervalle donné" << endl;
        return (EXIT_FAILURE);
    }

    //Test si jour ou nuit et calcul du prix de la course
    if (DEBUTJOURNEE <= depart and depart <= FINJOURNEE) {
        prixDeCourse = TARIFMINJOUR * tempsTrajet;
    }
    else { 
        prixDeCourse = TARIFMINNUIT * tempsTrajet;
    }

    //Calcul Total
    prixTotal = prixDeCourse + totalBagages + PRISEENCHARGE;


    //Afficher
    cout << endl;

    cout  << left << setw(W) << "Votre ticket" << endl;
    cout  << left << setw(W) << "============" << endl;
    cout  << left << setw(W) << " - prise en charge   : " << PRISEENCHARGE << endl;
    cout  << left << setw(W) << " - supp bagage       : " << totalBagages << endl;
    cout  << left << setw(W) << " - prix de la course : " << prixDeCourse << endl;
    cout  << left << setw(W) << "  TOTAL : " << prixTotal << endl << endl;

    //MESSAGE DE FIN
    cout <<"merci pour votre visite" << endl;
    cout << "Presser ENTER pour quitter";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return EXIT_SUCCESS;
}