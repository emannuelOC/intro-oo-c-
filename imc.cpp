#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

class Patient {
    
public:
    void init(double, double);
    void afficher();
    double poids();
    double taille();
    double imc();
    
private:
    double poids_, taille_;
};

void Patient::init(double p, double t) {
    if (p <= 0.0 || t <= 0.0) {
        poids_ = 0.0;
        taille_ = 0.0;
    } else {
        poids_ = p;
        taille_ = t;
    }
}

void Patient::afficher() {
    cout  << "Patient : "
    << poids_
    << " kg pour "
    << taille_
    << " m\n";
}

double Patient::poids() {
    return poids_;
}

double Patient::taille() {
    return taille_;
}

double Patient::imc() {
    if (taille_ == 0.0) {
        return 0.0;
    }
    return poids_ / (taille_ * taille_);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
    Patient quidam;
    double poids, taille;
    do {
        cout << "Entrez un poids (kg) et une taille (m) : ";
        cin >> poids >> taille;
        quidam.init(poids, taille);
        quidam.afficher();
        cout << "IMC : " << quidam.imc() << endl;
    } while (poids * taille != 0.0);
    return 0;
}
