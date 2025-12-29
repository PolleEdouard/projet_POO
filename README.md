# Projet POO - Gestion d'Enseignants et d'UE

Projet de Programmation Orientée Objet en C++ pour la gestion des enseignants et des unités d'enseignement (UE).

## 📁 Structure du projet

```
projet_POO/
├── src/             # Fichiers sources (.cpp)
├── include/         # Fichiers headers (.hpp)
├── bin/             # Exécutables et fichiers objets
├── docs/            # Documentation (PDF, UML)
├── README.md        # Ce fichier
├── Makefile         # Fichier de compilation automatisée
└── .gitignore       # Fichiers à ignorer par git
```

## 🏗️ Architecture des classes

### Hiérarchie Enseignant
- **Enseignant** (classe abstraite) - Classe de base avec attributs communs
  - **Professeur** - 192 heures dues par an
  - **MaitreConference** - 192 heures dues par an
  - **Autre** - 384 heures dues par an

### Classes de cours
- **Cm** - Cours Magistraux (coefficient 1.5)
- **Td** - Travaux Dirigés (coefficient 1.0)
- **Tp** - Travaux Pratiques (coefficient 2/3)

### Classe UE
- **UE** - Unité d'Enseignement avec calcul ETD (Équivalent Temps Didactique)

## 🔧 Compilation

### Avec Makefile (recommandé)

```bash
# Compiler tout le projet
make all

# Compiler et nettoyer
make clean all

# Compiler uniquement le test des enseignants
make test_enseignant

# Compiler uniquement le test des UE
make test_ue

# Nettoyer les binaires
make clean
```

### Avec GCC manuellement

#### Compiler le test des enseignants
```bash
g++ -std=c++17 -Iinclude -o bin/test_enseignant \
    src/test_enseignant.cpp \
    src/Enseignant.cpp \
    src/Professeur.cpp \
    src/MaitreConference.cpp \
    src/Autre.cpp
```

#### Compiler le test des UE
```bash
g++ -std=c++17 -Iinclude -o bin/test_ue \
    src/test_ue.cpp \
    src/UE.cpp \
    src/Cm.cpp \
    src/Td.cpp \
    src/Tp.cpp \
    src/Enseignant.cpp \
    src/Professeur.cpp
```

#### Compiler en deux étapes (objets puis exécutable)
```bash
# Compiler les fichiers objets
g++ -std=c++17 -Iinclude -c src/Enseignant.cpp -o bin/Enseignant.o
g++ -std=c++17 -Iinclude -c src/Professeur.cpp -o bin/Professeur.o
g++ -std=c++17 -Iinclude -c src/MaitreConference.cpp -o bin/MaitreConference.o
g++ -std=c++17 -Iinclude -c src/Autre.cpp -o bin/Autre.o

# Lier pour créer l'exécutable
g++ -std=c++17 -o bin/test_enseignant \
    src/test_enseignant.cpp \
    bin/Enseignant.o \
    bin/Professeur.o \
    bin/MaitreConference.o \
    bin/Autre.o
```

## ▶️ Exécution

```bash
# Exécuter le test des enseignants
./bin/test_enseignant

# Exécuter le test des UE
./bin/test_ue
```

## 📊 Exemple de sortie

### Test Enseignant
```
=== Test de la hiérarchie des classes Enseignant ===

1. Professeur:
   Nom: Dupont Jean
   ID: 1001
   Heures dues: 192h
   Heures calculées: 192h

2. Maître de Conférence:
   Nom: Martin Marie
   ID: 1002
   Heures dues: 192h
   Heures calculées: 192h

3. Autre:
   Nom: Durand Pierre
   ID: 1003
   Heures dues: 384h
   Heures calculées: 384h
```

### Test UE
```
COÛT TOTAL ETD: 130.00 heures

Vérification du calcul:
  (20×1×1.5) + (30×2×1.0) + (20×3×0.667)
  = 30 + 60 + 40 = 130.00h
✓ Calcul correct!
```

## 💡 Utilisation dans votre code

```cpp
#include "Professeur.hpp"
#include "UE.hpp"

// Créer un enseignant
Professeur prof("Martin", "Sophie", "10 Rue des Sciences", 1001);

// Créer une UE
UE ue("Programmation C++",
      20.0, 1,    // 20h de CM pour 1 groupe
      30.0, 2,    // 30h de TD pour 2 groupes
      20.0, 3,    // 20h de TP pour 3 groupes
      &prof);     // Enseignant responsable

// Calculer le coût ETD
double coutTotal = ue.calculerCoutTotalETD();
std::cout << "Coût ETD: " << coutTotal << "h" << std::endl;
```

## 📝 Formule de calcul ETD

**ETD = Heures × Groupes × Coefficient**

Coefficients :
- CM : 1.5
- TD : 1.0
- TP : 2/3 (≈ 0.667)

## ⚙️ Configuration VS Code

Le projet inclut une configuration VS Code partagée dans `.vscode/` pour que tous les membres de l'équipe aient IntelliSense fonctionnel.

**Premiers pas :**
1. Ouvrez le projet dans VS Code
2. Installez l'extension **C/C++** (ms-vscode.cpptools)
3. Rechargez la fenêtre : `Ctrl+Shift+P` → "Reload Window"

Les erreurs `'XXX.hpp' file not found` disparaîtront automatiquement !

Plus de détails dans [.vscode/README.md](.vscode/README.md)

## 🛠️ Prérequis

- Compilateur C++ compatible C++17 (g++, clang++)
- Make (optionnel, pour utiliser le Makefile)

## 📄 Documentation

La documentation complète du projet se trouve dans le dossier `docs/` :
- `Projet_APOO_2025_2026.pdf` - Énoncé du projet
- `UML.drawio` - Diagramme UML du projet

## 👤 Auteur

Projet réalisé dans le cadre du cours de Programmation Orientée Objet.
