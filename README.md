# Projet POO - Système de Gestion Universitaire

Projet C++ de gestion des enseignants, UE et départements avec persistance CSV.

## Structure du projet

```
projet_POO/
├── src/             # Fichiers sources (.cpp)
├── include/         # Fichiers headers (.hpp)
├── bin/             # Exécutables et fichiers objets
├── data/            # Données CSV (générées automatiquement)
├── docs/            # Documentation
├── README.md
├── Makefile
└── .gitignore
```

## Architecture

### Hiérarchie Enseignant

- **Enseignant** (classe abstraite)
  - **Professeur** (192h/an)
  - **MaitreConference** (192h/an)
  - **Autre** (384h/an)

### Classes métier

- **UE** - Unité d'enseignement avec CM/TD/TP
- **Departement** - Gère enseignants et UE
- **Intervention** - Association enseignant-UE
- **Semestre**, **Diplome**, **Inscription**

### Persistance

- **GestionFichiers** - Sauvegarde/chargement CSV

## Compilation

```bash
# Compiler
make

# Nettoyer
make clean

# Recompiler
make clean all
```

## Exécution

```bash
./bin/gestion_universitaire
```

L'application charge automatiquement les données depuis `data/` au démarrage.

## Utilisation

L'interface propose :

1. Saisir enseignants, UE, départements
2. Enregistrer interventions
3. Afficher charges et taux d'encadrement
4. Sauvegarder/charger données

## Prérequis

- g++ avec support C++17
- make

## Auteur

Abdellou--Genestier Renaud
Lafarge Baptiste
Dussot--Clary Ambre
