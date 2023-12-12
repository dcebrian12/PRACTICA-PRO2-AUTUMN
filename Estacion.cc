#include "Estacion.hh"
#include "cjt_bicis.hh"


Estacion::Estacion(int max, const string id)
{
    id_estacion = id;
    max_bicis = max;
    bicis_estacion = set<string>();
    plazas_nodos = make_pair(0, 0);
}

bool Estacion::estacion_llena() const
{
    return max_bicis == bicis_estacion.size();
}

string Estacion::identificador_estacion() const
{
    return id_estacion;
}

int Estacion::max_estacion() const
{
    return max_bicis;
}

void Estacion::afegir_bici(const string& id_bici)
{
    bicis_estacion.insert(id_bici);

}

void Estacion::borrar_bici(const string& id_bici)
{
    bicis_estacion.erase(id_bici);
}

void Estacion::bicis_en_estacion() const{
    set<string>::iterator it = bicis_estacion.begin();
    for (; it != bicis_estacion.end(); ++it)
        cout << *it << endl;
    
}

void Estacion::aumentar_capacidad(const int num){
    if (num >= bicis_estacion.size())
        max_bicis = num;
}

int Estacion::total_bicis() const{
    return bicis_estacion.size();
}

string Estacion::idbici_menor() const{
    set<string>::const_iterator it = bicis_estacion.begin();
    return *it;
}

bool Estacion::estacion_vacia() const{
    return bicis_estacion.size() == 0;
}

void Estacion::modifica_nodos_plazas(const int n, const double p){
    plazas_nodos.first = n;
    plazas_nodos.second = p;
}

pair<int, double> Estacion::consultar_nodos_plazas() const{
    return plazas_nodos;
}
