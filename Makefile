# Makefile pour le projet POO
# Gestion des enseignants et des UE

# Compilateur et flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Dossiers
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Fichiers sources communs
ENSEIGNANT_SRCS = $(SRC_DIR)/Enseignant.cpp $(SRC_DIR)/Professeur.cpp \
                  $(SRC_DIR)/MaitreConference.cpp $(SRC_DIR)/Autre.cpp

COURS_SRCS = $(SRC_DIR)/Cm.cpp $(SRC_DIR)/Td.cpp $(SRC_DIR)/Tp.cpp

UE_SRCS = $(SRC_DIR)/UE.cpp $(COURS_SRCS) $(SRC_DIR)/Enseignant.cpp $(SRC_DIR)/Professeur.cpp

# Fichiers objets
ENSEIGNANT_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(ENSEIGNANT_SRCS))
COURS_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(COURS_SRCS))
UE_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(UE_SRCS))

# Exécutables
TEST_ENSEIGNANT = $(BIN_DIR)/test_enseignant
TEST_UE = $(BIN_DIR)/test_ue
TEST_ASSOCIATIONS = $(BIN_DIR)/test_associations

# Cible par défaut
.PHONY: all
all: $(TEST_ENSEIGNANT) $(TEST_UE) $(TEST_ASSOCIATIONS)

# Compilation du test des enseignants
$(TEST_ENSEIGNANT): $(SRC_DIR)/test_enseignant.cpp $(ENSEIGNANT_OBJS)
	@echo "Compilation de test_enseignant..."
	$(CXX) $(CXXFLAGS) -o $@ $< $(ENSEIGNANT_OBJS)
	@echo "✓ test_enseignant compilé avec succès!"

# Compilation du test des UE
$(TEST_UE): $(SRC_DIR)/test_ue.cpp $(UE_OBJS)
	@echo "Compilation de test_ue..."
	$(CXX) $(CXXFLAGS) -o $@ $< $(UE_OBJS)
	@echo "✓ test_ue compilé avec succès!"

# Compilation du test des associations
$(TEST_ASSOCIATIONS): $(SRC_DIR)/test_associations.cpp
	@echo "Compilation de test_associations..."
	$(CXX) $(CXXFLAGS) -o $@ $< \
		$(SRC_DIR)/Semestre.cpp $(SRC_DIR)/Intervention.cpp $(SRC_DIR)/Inscription.cpp \
		$(SRC_DIR)/Enseignant.cpp $(SRC_DIR)/Professeur.cpp $(SRC_DIR)/MaitreConference.cpp \
		$(SRC_DIR)/UE.cpp $(SRC_DIR)/Cm.cpp $(SRC_DIR)/Td.cpp $(SRC_DIR)/Tp.cpp
	@echo "✓ test_associations compilé avec succès!"

# Règle générique pour compiler les fichiers objets
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	@echo "Compilation de $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Créer le dossier bin s'il n'existe pas
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Nettoyer les fichiers compilés
.PHONY: clean
clean:
	@echo "Nettoyage des fichiers compilés..."
	rm -f $(BIN_DIR)/*.o $(TEST_ENSEIGNANT) $(TEST_UE) $(TEST_ASSOCIATIONS)
	@echo "✓ Nettoyage terminé!"

# Nettoyer complètement (y compris le dossier bin)
.PHONY: distclean
distclean: clean
	@echo "Nettoyage complet..."
	rm -rf $(BIN_DIR)
	@echo "✓ Nettoyage complet terminé!"

# Exécuter les tests
.PHONY: test
test: all
	@echo ""
	@echo "=== Exécution de test_enseignant ==="
	./$(TEST_ENSEIGNANT)
	@echo ""
	@echo "=== Exécution de test_ue ==="
	./$(TEST_UE)
	@echo ""
	@echo "=== Exécution de test_associations ==="
	./$(TEST_ASSOCIATIONS)

# Afficher l'aide
.PHONY: help
help:
	@echo "Makefile du projet POO"
	@echo ""
	@echo "Cibles disponibles:"
	@echo "  all          - Compile tous les exécutables (par défaut)"
	@echo "  test_enseignant - Compile uniquement le test des enseignants"
	@echo "  test_ue      - Compile uniquement le test des UE"
	@echo "  test         - Compile et exécute tous les tests"
	@echo "  clean        - Supprime les fichiers compilés"
	@echo "  distclean    - Supprime tous les fichiers générés"
	@echo "  help         - Affiche cette aide"
	@echo ""
	@echo "Exemple d'utilisation:"
	@echo "  make         - Compile tout"
	@echo "  make clean   - Nettoie"
	@echo "  make test    - Compile et exécute les tests"
