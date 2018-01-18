# Constructeur


> Notes de [cette lecture](https://www.coursera.org/learn/programmation-orientee-objet-cpp/lecture/GOTPn/constructeurs-introduction)

Le constructeur est un méthode qui est invoquée automatiquement lors de la declaratión d'un objet. Il est chargée de l'initialisation des attributs de l'objet.

Pour déclarer un constructeur, il suffit de déclarer un méthode qui a le même nom de la classe.

Cette méthode peut recevoir si nécessaire des paramètres.

```
Rectangle(double h, double L)
{
	hauteur = h;
	largeur = L;
}
```

Les différences des constructeurs par les otres méthodes:

* pas de type de retour;
* même nom que la classe;
* invoquées automatiquement;

Pour passer les paramètres, il suffit de mettre entre parenthèses les valeurs comme arguments:

```
Rectangle r(12.5, 7.0);
```

## Liste d'initialisatión

Le but de la liste d'initialisatión est d'appeler les constructeurs des attributs que sont objéts et d'initialiser les otres attibuts qui ne sont pas des objets.
Nous allons mettre la liste d'initialisatión entre le êntete du constructeur, qui a le nom et les paramètres, et la définition du constructeur.
La liste commence par deux points ":" et pour chaque attribut, nous allons avoir le nom de l'attribute suivi de l'appel du constructeur correspondant à chacun des attributs, suivi d'un virgule.

Par exemple:

```
class RectangleColore {

public:
	RectangleColore(double h, double L, Couleur c)
	: rectangle(h, L), couleur(c)
	{}

private:
	Rectangle rectangle;
	Couleur couleur;
}
```

L'utilisatión de la liste d'initialisatión est trés recomendée. Elle permet d'eviter de faire des copies des objets lors de l'initialisatión de l'instance de la classe.

*******




