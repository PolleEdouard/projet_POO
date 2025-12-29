# Projet POO - Gestion Universitaire
# Makefile simplifié

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Sources
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/GestionFichiers.cpp \
          $(SRC_DIR)/Enseignant.cpp \
          $(SRC_DIR)/Professeur.cpp \
          $(SRC_DIR)/MaitreConference.cpp \
          $(SRC_DIR)/Autre.cpp \
          $(SRC_DIR)/UE.cpp \
          $(SRC_DIR)/Cm.cpp \
          $(SRC_DIR)/Td.cpp \
          $(SRC_DIR)/Tp.cpp \
          $(SRC_DIR)/Departement.cpp \
          $(SRC_DIR)/Diplome.cpp \
          $(SRC_DIR)/Semestre.cpp \
          $(SRC_DIR)/Inscription.cpp \
          $(SRC_DIR)/Intervention.cpp

# Exécutable
TARGET = $(BIN_DIR)/gestion_universitaire

# Cible par défaut
.PHONY: all
all: $(TARGET)

# Compilation
$(TARGET): $(SOURCES) | $(BIN_DIR)
	@echo "Compilation..."
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)
	@echo "Compilation terminée: $(TARGET)"

# Créer le dossier bin
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Nettoyer
.PHONY: clean
clean:
	@echo "Nettoyage..."
	rm -rf $(BIN_DIR)
	@echo "Nettoyage terminé"

# Exécuter
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Aide
.PHONY: help
help:
	@echo "Makefile - Projet Gestion Universitaire"
	@echo ""
	@echo "Cibles disponibles:"
	@echo "  make        - Compiler le projet"
	@echo "  make run    - Compiler et exécuter"
	@echo "  make clean  - Nettoyer les fichiers compilés"
	@echo "  make help   - Afficher cette aide"
