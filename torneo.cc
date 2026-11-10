#include <iostream>
#include <set>
#include <string>
//Struct
struct Equipo {
    std::string nombre;
    std::string pais;
    int ranking;
};

//Ordena por nombre y evita duplicados
struct ComparadorNombre {
    bool operator()(const Equipo& a, const Equipo& b) const {
        return a.nombre < b.nombre;
    }
};

using Torneo = std::set<Equipo, ComparadorNombre>;

//Validacion
bool ValidarEquipo(const Equipo& e);

//decalarión de funciones
bool AgregarEquipo(Torneo& Torneo, const Equipo e);
void BuscarEquipo(const Torneo& torneo, const std::string& nombre);
bool EliminarEquipo(Torneo& torneo, const std::string& nombre);
void MostrarEquipos(const Torneo& torneo);


//Menu
void mostrarMenu();

//función principal
int main(){
    Torneo torneo;



    return 0;
}

bool ValidarEquipo(const Equipo& e){
    
    return false;
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
}bool EliminarEquipo(Torneo& torneo, const std::string& nombre) {
  // El set compara solo por nombre, así que basta un Equipo de búsqueda
  Equipo equipo_buscado{nombre, "", 0};

  auto it = torneo.find(equipo_buscado);

  // si no existe, find devuelve end() y no se puede borrar
  if (it == torneo.end()) {
    return false;
  }

  torneo.erase(it);
  return true;
