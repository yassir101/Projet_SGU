# Projet SGU — Système de Gestion des Urgences
_________________________________________________________________________

## Collaboration sur la branche "dev"

Ce projet est développé en équipe dans le cadre du module de CPP.  
Toutes les contributions doivent être faites sur la branche `dev`.  
La branche `main` est réservée à la version stable finale du projet.

---

## 1. Clonage du projet

Fork le projet sur Github (fork `main` et `dev`)

Ouvrez un terminal et entrez :

```bash
git clone https://github.com/[votre-nom-utilisateur]/Projet_SGU.git
cd Projet_SGU
```

---

## 2. Travailler sur la branche "dev"

Avant toute modification, assurez-vous d’être sur la bonne branche :

```bash
git checkout dev
git pull origin dev
```

---

## 3. Ajouter ou modifier du code

Créez un nouveau fichier ou modifiez ceux déjà présents :

```bash
touch src/mon_module.cpp
echo "// début du code" > src/mon_module.cpp
```

---

## 4. Ajouter et valider les changements

```bash
git add .
git commit -m "Ajout du module mon_module"
```

---

## 5. Pousser sur la branche "dev"

```bash
git push origin dev
```

⚠️ Si une erreur `non-fast-forward` s’affiche :

```bash
git pull origin dev     # récupère les modifications distantes
# Résolvez les conflits si nécessaire
git push origin dev     # pousse vos changements après résolution
```

---

## 6. Mettre à jour votre dépôt local

Avant chaque session de travail, pensez à récupérer les dernières modifications :

```bash
git checkout dev
git pull origin dev
```

---

## Utilisation avec Visual Studio Code (VScode / VSCodium)

### 📂 Ouvrir le projet

Dans un terminal :

```bash
code Projet_SGU/
# ou si vous êtes déjà dans le dossier
code .
```
*Si c'est VSCodium utilisez codium au lieu de code*

*Si la commande `code` ne fonctionne pas :*  
`Ctrl+Shift+P` → `Install 'code' command in PATH`

---

### ✏️ Créer ou modifier un fichier

- Dans l’explorateur (à gauche), clic droit sur `src/` → *Nouveau fichier*
- Tapez `urgence.cpp`, par exemple
- Éditez et sauvegardez avec `Ctrl+S`

---

### 💻 Utiliser le terminal intégré

- `Ctrl + \`` pour l’ouvrir
- Vous pouvez y taper :

```bash
git checkout dev
git pull origin dev
git add .
git commit -m "Ajout ou modification"
git push origin dev
```

---

### 🔌 Extensions utiles

- **C/C++** — Microsoft
- **GitLens** — Historique Git visuel
- **Doxygen Documentation Generator**
- **CMake Tools** — Si vous utilisez CMake pour la compilation

---

## ⚠️ Règles importantes

- Ne poussez **jamais** directement sur la branche `main`
- Travaillez **exclusivement** sur `dev`
- Communiquez avec le groupe si vous faites de grosses modifications
- Utilisez des **messages de commit clairs et descriptifs**

---

## 🗂️ Organisation du dépôt

```bash
Projet_SGU/
├── src/         -> code source principal
├── include/     -> fichiers d’en-tête (.h)
├── test/        -> tests unitaires
├── docs/        -> documentation Doxygen
├── data/        -> données éventuelles
├── build/       -> répertoire de compilation
├── README.md    -> ce fichier
└── .gitignore   -> fichiers ignorés par Git
```

---

## 👥 Auteurs

- Ankoudy Yassir  
- Cheikh Tourad Wedou  
- Duquesnoy Samuel  
- Guissou Dakisaglogo  

---

Bon code à tous 🚀
