#ifndef GESTIONFICHIERS_HPP
#define GESTIONFICHIERS_HPP

#include "Autre.hpp"
#include "Departement.hpp"
#include "Enseignant.hpp"
#include "MaitreConference.hpp"
#include "Professeur.hpp"
#include "UE.hpp"
#include <map>
#include <string>
#include <vector>

/**
 * @brief Classe pour gérer la persistance des données en fichiers CSV
 *
 * Permet de sauvegarder et charger les enseignants, UE et départements
 * avec reconstruction des liens entre objets.
 */
class GestionFichiers {
public:
  /**
   * @brief Sauvegarde une liste d'enseignants dans un fichier CSV
   * @param enseignants Liste des enseignants à sauvegarder
   * @param filename Nom du fichier (ex: "enseignants.csv")
   * @return true si succès, false sinon
   */
  static bool
  sauvegarderEnseignants(const std::vector<Enseignant *> &enseignants,
                         const std::string &filename);

  /**
   * @brief Sauvegarde une liste d'UE dans un fichier CSV
   * @param ues Liste des UE à sauvegarder
   * @param filename Nom du fichier (ex: "ues.csv")
   * @return true si succès, false sinon
   */
  static bool sauvegarderUEs(const std::vector<UE *> &ues,
                             const std::string &filename);

  /**
   * @brief Sauvegarde une liste de départements dans un fichier CSV
   * @param departements Liste des départements à sauvegarder
   * @param filename Nom du fichier (ex: "departements.csv")
   * @param mapEnseignants Map ID → Enseignant pour retrouver les IDs
   * @param mapUEs Map ID → UE pour retrouver les IDs
   * @return true si succès, false sinon
   */
  static bool
  sauvegarderDepartements(const std::vector<Departement *> &departements,
                          const std::string &filename,
                          const std::map<Enseignant *, int> &mapEnseignants,
                          const std::map<UE *, int> &mapUEs);

  /**
   * @brief Charge des enseignants depuis un fichier CSV
   * @param filename Nom du fichier
   * @param outMap Map de sortie ID → Enseignant* pour reconstruction
   * @return Liste des enseignants chargés (allocation dynamique!)
   */
  static std::vector<Enseignant *>
  chargerEnseignants(const std::string &filename,
                     std::map<int, Enseignant *> &outMap);

  /**
   * @brief Charge des UE depuis un fichier CSV
   * @param filename Nom du fichier
   * @param mapEnseignants Map ID → Enseignant pour restaurer responsable
   * @param outMap Map de sortie ID → UE* pour reconstruction
   * @return Liste des UE chargées (allocation dynamique!)
   */
  static std::vector<UE *>
  chargerUEs(const std::string &filename,
             const std::map<int, Enseignant *> &mapEnseignants,
             std::map<int, UE *> &outMap);

  /**
   * @brief Charge des départements depuis un fichier CSV
   * @param filename Nom du fichier
   * @param mapEnseignants Map ID → Enseignant pour restaurer enseignants
   * @param mapUEs Map ID → UE pour restaurer UE
   * @return Liste des départements chargés (allocation dynamique!)
   */
  static std::vector<Departement *>
  chargerDepartements(const std::string &filename,
                      const std::map<int, Enseignant *> &mapEnseignants,
                      const std::map<int, UE *> &mapUEs);

  /**
   * @brief Retourne le type d'un enseignant sous forme de chaîne
   */
  static std::string getTypeEnseignant(Enseignant *ens);

private:
  /**
   * @brief Découpe une chaîne selon un délimiteur
   */
  static std::vector<std::string> split(const std::string &str, char delimiter);

  /**
   * @brief Crée un enseignant selon son type
   */
  static Enseignant *creerEnseignant(const std::string &type,
                                     const std::string &nom,
                                     const std::string &prenom,
                                     const std::string &adresse, int id);
};

#endif
