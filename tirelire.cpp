#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

class Tirelire {
    
public:
    double getMontant();
    void afficher();
    void secouer();
    void remplir(double);
    void vider();
    void puiser(double);
    bool montant_suffisant(double, double &);
    double calculerSolde(double);
    
private:
    double montant;
};

double Tirelire::getMontant() {
    return montant;
}

void Tirelire::afficher() {
    if (montant <= 0.0) {
        cout << "Vous etes sans le sou.\n";
    } else {
        cout  << "Vous avez : "
        << montant
        << " euros dans votre tirelire.\n";
    }
}

void Tirelire::secouer() {
    if (montant > 0.0) {
        cout << "Bing bing\n";
    }
}

void Tirelire::remplir(double value) {
    montant += max(0.0, value);
}

void Tirelire::vider() {
    montant = 0.0;
}

void Tirelire::puiser(double value) {
    montant -= min(montant, max(value, 0.0));
}

bool Tirelire::montant_suffisant(double budget, double &solde) {
    if (budget <= 0.0) {
        solde = montant;
        return true;
    }
    solde = ((budget - montant) >= 0.0) ? (budget - montant) : (montant - budget);
    return (montant >= budget);
}



/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
    Tirelire piggy;
    
    piggy.vider();
    piggy.secouer();
    piggy.afficher();
    
    piggy.puiser(20.0);
    piggy.secouer();
    piggy.afficher();
    
    piggy.remplir(550.0);
    piggy.secouer();
    piggy.afficher();
    
    piggy.puiser(10.0);
    piggy.puiser(5.0);
    piggy.afficher();
    
    cout << endl;
    
    // le budget de vos vacances de rève.
    double budget;
    
    cout << "Donnez le budget de vos vacances : ";
    cin >> budget;
    
    // ce qui resterait dans la tirelire après les
    // vacances
    double solde(0.0);
    
    if (piggy.montant_suffisant(budget, solde)) {
        cout << "Vous êtes assez riche pour partir en vacances !"
        << endl
        << "Il vous restera " << solde << " euros"
        << " à la rentrée." << endl << endl;
        piggy.puiser(budget);
    } else {
        cout << "Il vous manque " << solde << " euros"
        << " pour partir en vacances !" << endl << endl;
    }
    return 0;
}
