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
bool AgregarEquipo(Torneo& torneo, const Equipo& e);
void BuscarEquipo(const Torneo& torneo, const std::string& nombre);
bool EliminarEquipo(Torneo& torneo, const std::string& nombre);
void MostrarEquipo(const Torneo& torneo);

//Menu
void mostrarMenu();

//función principal
int main(){
    Torneo torneo;



    return 0;
}

bool ValidarEquipo(const Equipo& e){
    return !e.nombre.empty() && !e.pais.empty() && e.ranking > 0;
}

bool AgregarEquipo(Torneo& torneo, const Equipo& e){
    if(!ValidarEquipo(e)){
        std::cout << "Datos invalidos: el nombre del equipo no puede estar vacío, el país no puede estar vacío y el ranking debe ser mayor que 0.\n";
        // No se insertó debido a validación fallida
        return false; 
    }
    auto resultado = torneo.insert(e);
    if (!resultado.second) {
        std::cout << "El equipo ya existe en el torneo con el nombre: " << e.nombre << ".\n";
        // No se insertó debido a duplicado
        return false; 
    }
    std::cout << "Equipo agregado correctamente: " << e.nombre << " de " << e.pais << " con ranking " << e.ranking << ".\n";
    // Se insertó correctamente
    return true; 
}