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
    bool operador()(const Equipo& a, const Equipo& b) const {
        return a.nombre < b.nombre;
    }
};

using Torneo = set<Equipo, ComparadorNombre>;

//Validacion
bool ValidarEquipo(const Equipo& e);

//decalarión de funciones
bool AgregarEquipo(Torneo& Torneo, const Equipo e);
void BuscarEquipo(const Torneo& torne, const string& nombre);
bool EliminarEquipo(Torneo& torneo, const string& nombre);
void MostrarEquipo(const Torneo& torneo);

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