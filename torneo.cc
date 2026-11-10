#include <iostream>
#include <set>
#include <string>

// Struct
struct Equipo {
    std::string nombre;
    std::string pais;
    int ranking;
};

// Ordena por nombre y evita duplicados
struct ComparadorNombre {
    bool operator()(const Equipo& a, const Equipo& b) const {
        return a.nombre < b.nombre;
    }
};

using Torneo = std::set<Equipo, ComparadorNombre>;

// Validacion
bool ValidarEquipo(const Equipo& e);

// Declaracion de funciones
bool AgregarEquipo(Torneo& torneo, const Equipo& e);
void BuscarEquipo(const Torneo& torneo, const std::string& nombre);
bool EliminarEquipo(Torneo& torneo, const std::string& nombre);
void MostrarEquipos(const Torneo& torneo);

// Menu
void mostrarMenu();

// Funcion principal
int main() {
    Torneo torneo;
    int opcion = 0;

    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1: {
                Equipo e;
                std::cout << "Nombre del equipo: ";
                std::getline(std::cin, e.nombre);
                std::cout << "Pais de origen: ";
                std::getline(std::cin, e.pais);
                std::cout << "Posicion en el ranking mundial: ";
                std::cin >> e.ranking;
                std::cin.ignore();

                if (!ValidarEquipo(e)) {
                    std::cout << "Datos invalidos: el nombre no puede estar vacio "
                                 "y el ranking debe ser positivo.\n";
                } else if (AgregarEquipo(torneo, e)) {
                    std::cout << "Equipo registrado correctamente.\n";
                } else {
                    std::cout << "Ya existe un equipo con el nombre \""
                              << e.nombre << "\".\n";
                }
                break;
            }
            case 2: {
                std::string nombre;
                std::cout << "Nombre del equipo a buscar: ";
                std::getline(std::cin, nombre);
                BuscarEquipo(torneo, nombre);
                break;
            }
            case 3: {
                std::string nombre;
                std::cout << "Nombre del equipo a eliminar: ";
                std::getline(std::cin, nombre);
                if (EliminarEquipo(torneo, nombre)) {
                    std::cout << "Equipo eliminado del torneo.\n";
                } else {
                    std::cout << "No existe un equipo con el nombre \""
                              << nombre << "\".\n";
                }
                break;
            }
            case 4:
                MostrarEquipos(torneo);
                break;
            case 0:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}

bool ValidarEquipo(const Equipo& e) {
    return !e.nombre.empty() && e.ranking > 0;
}

bool AgregarEquipo(Torneo& torneo, const Equipo& e) {
    // insert devuelve un par: .second es true si se insertó
    // y false si el nombre ya existía
    return torneo.insert(e).second;
}

void BuscarEquipo(const Torneo& torneo, const std::string& nombre) {
    Equipo criterioBusqueda{nombre, "", 0};
    auto iterador = torneo.find(criterioBusqueda);
    if (iterador != torneo.end()) {
        std::cout << "\n[Equipo Encontrado]\n";
        std::cout << " * Pais: " << iterador->pais << "\n";
        std::cout << " * Ranking Mundial: " << iterador->ranking << "\n";
    } else {
        std::cout << "No se encontro ningun equipo con el nombre \"" << nombre << "\".\n";
    }
}

void mostrarMenu() {
    std::cout << "\nMENU DEL TORNEO \n";
    std::cout << "1. Agregar Equipo\n";
    std::cout << "2. Buscar Equipo \n";
    std::cout << "3. Eliminar Equipo \n";
    std::cout << "4. Mostrar Equipos\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

void MostrarEquipos(const Torneo& torneo) {
  // si el torneo está vacio, se reporta y sale de una vez
  if (torneo.empty()) {
    std::cout << "no hay equipos registrados.\n";
    return;
  }

  std::cout << "\nEquipos (orden alfabetico)\n";
  std::cout << "Total de equipos: " << torneo.size() << "\n";

  // recorrido de elementos e impresion de sus atributos
  for (auto it = torneo.begin(); it != torneo.end(); ++it) {
    std::cout << it->nombre << " - " << it->pais
              << " - Ranking: " << it->ranking << "\n";
  }
}

bool EliminarEquipo(Torneo& torneo, const std::string& nombre) {
  // el set compara solo por nombre asi que basta un equipo de búsqueda
  Equipo equipo_buscado{nombre, "", 0};

  auto it = torneo.find(equipo_buscado);

  if (it == torneo.end()) {
    return false;
  }

  torneo.erase(it);
  return true;
}