<a id="fr"></a>

<div align="center">
  <a href="#en">🇬🇧 English</a> · 
  <a href="#fr">🇫🇷 français</a>
</div>

# Tile Twister

_“Regardez ces tuiles. On dirait des trucs anciens” — Jumanji_

## Introduction du sujet

2048 est un jeu de réflexion créé en mars 2014 par le développeur
indépendant italien **Gabriele Cirulli** et publié en ligne sous licence libre via GitHub le **9 mars 2014**. Sur une grille, des tuiles numérotées attendaient
patiemment d'être fusionnées. Chaque joueur vise le chiffre : **2048**. Mais
derrière ce nombre se cache bien plus qu'une simple somme mathématique. C’est un défi stratégique où chaque mouvement compte, où la planification et la patience sont aussi cruciales que la réflexion.

## Étape 1 : logique de jeu

D'abord, plongeons dans l’univers du code pour implémenter les règles du jeu
à l’aide des classes. Nous découvrirons les secrets de la bibliothèque
standard et de ses containers. Grâce à la programmation orientée objet,
architecturez votre projet et le structurer en plusieurs fichiers pour une gestion plus claire et modulaire.

Pour démarrer le jeu, initialiser une grille de jeu vide de **4x4** et générer deux tuiles aléatoires de valeur **2** ou **4**. Ensuite, permettre à l'utilisateur de déplacer les tuiles horizontalement (gauche/droite) et verticalement (haut/bas) en utilisant les touches du clavier. Fusionner les tuiles de même valeur lorsqu'elles entreront en collision après un déplacement, et générer une nouvelle tuile aléatoire après chaque déplacement valide. Le jeu détectera la fin lorsque la grille sera pleine sans aucun mouvement valide.

Créer des situations de jeu et observer les événements (haut/bas/gauche/droite) comparant les résultats obtenus avec ceux attendus pour tester l'intégrité du jeu.

## Étape 2 : SDL

Donner vie à notre projet, le transformant de l'abstrait vers le visuel tout en
conservant son essence et ses fonctionnalités d'origine – **un relooking
numérique bien mérité !**

Pour la partie graphique, nous mettons en place un moteur de rendu simple,
incluant une **classe Window** pour initialiser la SDL et créer une fenêtre avec
des paramètres. Utiliser une classe abstraite **GameObject** pour représenter
les éléments affichés à l’écran avec des coordonnées et une taille, permettant l'affichage sous forme géométrique ou par image SDL.

Réutiliser la logique du jeu pour afficher la grille avec des graphismes pour les tuiles, et permettre à l'utilisateur d'interagir avec le clavier pour déplacer les tuiles. Ajouter une animation sur les mouvements des tuiles pour une expérience visuelle immersive.

Bien sûr, nous n'oublierons pas l'importance des tests d'intégration pour éviter les régressions tout au long du développement. Nous les mettrons en place avec autant d'enthousiasme qu'un détective traquant les bugs, assurant
ainsi la solidité et la fiabilité de notre création.

## Pour aller plus loin…

Afin de rendre le jeu plus “fun” :
-​ Ajouter une animation de mouvement des tuiles
-​ Permettre sauvegarde/chargement de partie
-​ Objectif différent (atteindre 1024, 8192)
-​ Tuiles spéciales (bloquées, bonus)

## Compétences visées
-​ Installer et configurer son environnement de travail en fonction du
projet.
-​ Développer des interfaces utilisateur
-​ Développer des composants métier
-​ Contribuer à la gestion d'un projet informatique
-​ Analyser les besoins et maquetter une application
-​ Définir l'architecture logicielle d'une application
-​ Préparer et exécuter les plans de tests d'une application

## Rendu
Votre travail est évalué en présentation avec un support et une revue de code. Le slide doit être composé de :
- De l’organisation de votre équipe
- De vos problèmes rencontrés ainsi que les solutions apportées
- La démonstration jouable de votre jeu
Le projet est à rendre sur https://github.com/prenom-nom/TileTwister

## Base de connaissances

-​ [Tutoriel STL](https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-standard-template-library#c_stl)

-​ [Jeu du 2048](https://jeu2048.fr/)

-​ [Cours de C++ avancé](https://cplusplus.com/doc/tutorial/)

-​ [Tutoriel SDL](https://zestedesavoir.com/tutoriels/1014/utiliser-la-sdl-en-langage-c/)

<a id="en"></a>

<div align="center">
  <a href="#en">🇬🇧 English</a> · 
  <a href="#fr">🇫🇷 français</a>
</div>

# Tile Twister

_"Look at these tiles. They look like ancient stuff" — Jumanji_

## Subject Introduction

2048 is a puzzle game created in March 2014 by independent Italian developer
**Gabriele Cirulli** and published online under an open source license via GitHub on **March 9, 2014**. On a grid, numbered tiles waited patiently to be merged. Each player aims for the number: **2048**. But behind this number lies much more than a simple mathematical sum. It is a strategic challenge where every move counts, where planning and patience are as crucial as reflection.

## Step 1: Game Logic

First, let's dive into the world of code to implement the game rules using classes. We will discover the secrets of the standard library and its containers. Through object-oriented programming, architect your project and structure it across multiple files for clearer and more modular management.

To start the game, initialize an empty **4x4** game grid and generate two random tiles with values of **2** or **4**. Then, allow the user to move tiles horizontally (left/right) and vertically (up/down) using keyboard controls. Merge tiles of the same value when they collide after a movement, and generate a new random tile after each valid movement. The game detects the end when the grid is full with no valid moves available.

Create game scenarios and observe events (up/down/left/right) by comparing the results obtained with the expected results to test the integrity of the game.

## Step 2: SDL

Bring our project to life, transforming it from abstract to visual while preserving its essence and original functionality – **a well-deserved digital makeover!**

For the graphical part, we set up a simple rendering engine, including a **Window class** to initialize SDL and create a window with parameters. Use an abstract **GameObject** class to represent elements displayed on screen with coordinates and size, allowing display in geometric form or via SDL image.

Reuse the game logic to display the grid with graphics for the tiles, and allow the user to interact with the keyboard to move tiles. Add animation to the tile movements for an immersive visual experience.

Of course, we won't forget the importance of integration tests to avoid regressions throughout development. We will implement them with as much enthusiasm as a detective hunting bugs, thus ensuring the solidity and reliability of our creation.

## Going Further…

To make the game more "fun":
- Add tile movement animation
- Allow game save/load functionality
- Different objective (reach 1024, 8192)
- Special tiles (blocked, bonus)

## Skills Targeted
- Install and configure your work environment according to the project.
- Develop user interfaces
- Develop business components
- Contribute to the management of an IT project
- Analyze needs and prototype an application
- Define the software architecture of an application
- Prepare and execute application test plans

## Deliverable
Your work is evaluated in a presentation with supporting materials and code review. The presentation should include:
- Your team organization
- Your encountered problems and the solutions provided
- A playable demonstration of your game
The project should be submitted to https://github.com/prenom-nom/TileTwister

## Knowledge Base

- [STL Tutorial](https://www.cplusplus.com/reference/stl/)

- [2048 Game](https://play2048.co/)

- [Advanced C++ Course](https://cplusplus.com/doc/tutorial/)

- [SDL Tutorial](https://lazyfoo.net/tutorials/SDL/)