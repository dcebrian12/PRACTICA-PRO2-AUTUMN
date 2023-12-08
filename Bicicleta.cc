#include "Bicicleta.hh"
#include "cjt_estaciones.hh"


Bicicleta::Bicicleta(){
    id_bici = "NP";
    est_actual = "NP";
    viajes = vector<pair<string, string>>();
}

Bicicleta::Bicicleta(const string& id, const string& estacion){
    id_bici = id;
    est_actual = estacion;
    viajes = vector<pair<string, string>>();
}

string Bicicleta::consulta_estacion() const{
    return est_actual;
}

void Bicicleta::mod_bici(const string& id, const string& ide){
    id_bici = id;
    est_actual = ide;
}


void Bicicleta::imprime_viajes() const{
    for (int i = 0; i < viajes.size(); ++i){
        cout << viajes[i].first << ' ' << viajes[i].second << endl;;
    }
}

void Bicicleta::actualiza_viajes(const pair<string,string>& viaje) {
    viajes.push_back(viaje);
}

void Bicicleta::actualiza_estacion(const string& id_estacion){
    pair<string, string> p;
    p.first = est_actual;
    p.second = id_estacion;
    actualiza_viajes(p);
    est_actual = id_estacion;
}

