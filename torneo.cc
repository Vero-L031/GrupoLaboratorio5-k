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
bool AgregarEquipo(Torneo& torneo, const Equipo e);
void BuscarEquipo(const Torneo& torneo, const std::string& nombre);
bool EliminarEquipo(Torneo& torneo, const std::string& nombre);
void MostrarEquipo(const Torneo& torneo);

//Menu
void mostrarMenu();

//función principal
int main(){
    Torneo torneo;
    int opcion;
    
    do{
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();
        
        switch (opcion) {
            case 1: {
                Equipo e;
                AgregarEquipo(torneo, e);
                break;
            }
            case 2: {
                std::string nombre;
                BuscarEquipo(torneo, nombre);
                break;
            }
            case 3: {
                std::string nombre;
                EliminarEquipo(torneo, nombre);
                break;
            }
            case 4:
                MostrarEquipo(torneo);
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

bool ValidarEquipo(const Equipo& e){
    return false;
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
