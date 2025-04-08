Projet SGU — Système de Gestion des Urgences
============================================

Collaboration sur la branche "dev"
----------------------------------

Ce projet est développé en équipe dans le cadre du module de CPP. 
Toutes les contributions doivent être faites sur la branche `dev`. 
La branche `main` est réservée à la version stable finale du projet.

1. Clonage du projet
--------------------

Ouvrez un terminal et entrez :

    git clone https://github.com/yassir101/Projet_SGU.git
    cd Projet_SGU

2. Travailler sur la branche "dev"
----------------------------------

Avant toute modification, assurez-vous d'être sur la bonne branche :

    git checkout dev
    git pull origin dev

3. Ajouter ou modifier du code
------------------------------

Vous pouvez créer un nouveau fichier ou modifier ceux déjà présents.

    touch src/mon_module.cpp
    echo "// début du code" > src/mon_module.cpp     #pas forcément nécessaire

4. Ajouter et valider les changements
-------------------------------------

    git add .
    git commit -m "Ajout du module mon_module"

5. Pousser sur la branche "dev"
-------------------------------

    git push origin dev

6. Mettre à jour votre dépôt local
----------------------------------

Avant chaque nouvelle session de travail, pensez à récupérer les dernières modifications :

    git checkout dev
    git pull origin dev

Règles importantes
------------------

- Ne poussez **rien** directement sur la branche `main`.
- Travaillez **exclusivement sur `dev`**.
- Communiquez avec le groupe si vous faites de grosses modifications.
- Utilisez des messages de commit clairs et précis.

Organisation du dépôt
---------------------

    Projet_SGU/
    ├── src/         -> code source principal
    ├── include/     -> fichiers d’en-tête (.h)
    ├── test/        -> tests unitaires
    ├── docs/        -> documentation Doxygen
    ├── data/        -> données éventuelles
    ├── build/       -> répertoire de compilation
    ├── README.md    -> ce fichier
    └── .gitignore   -> fichiers ignorés par Git

Auteurs
-------

- Ankoudy Yassir
- Cheikh Tourad Wedou
- Duquesnoy Samuel
- Guissou Dakisaglogo

Bon code à tous 🚀

