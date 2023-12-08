#include "cjt_bicis.hh"

cjt_bicis::cjt_bicis()
{
    total_bicis = map<string, Bicicleta>();
}

bool cjt_bicis::existe_bici(const string& bici) const
{
    return total_bicis.find(bici) != total_bicis.end();
}

void cjt_bicis::alta_bici(const string bici, const string id_estacion)
{
    Bicicleta bic(bici, id_estacion);
    total_bicis.insert(make_pair(bici, bic));
}

void cjt_bicis::baja_bici(const string id_bici, cjt_estaciones &e)
{
    Bicicleta aux = devuelve_bicicleta(id_bici);
    Estacion auxe = e.consulta_estacion(aux.consulta_estacion());
    auxe.borrar_bici(id_bici);
    e.actualizar_valor_map_estacion(aux.consulta_estacion(), auxe);
    total_bicis.erase(id_bici);
    e.modifica_capacidad_total(1);
}

void cjt_bicis::imprime_estacion(const string& id_bici) const
{
    Bicicleta aux = devuelve_bicicleta(id_bici);
    string a = aux.consulta_estacion();
    cout << a << endl;
}

Bicicleta cjt_bicis::devuelve_bicicleta(const string& id_bici) const
{
    return total_bicis.find(id_bici)->second;
}

void cjt_bicis::actualizar_valor_map_bicicleta(string id_bici, Bicicleta b)
{
    map<string, Bicicleta>::iterator it = total_bicis.find(id_bici);
    it->second = b;
}

void cjt_bicis::cambiar_de_estacion(const string id_bici, const string id_estacion, cjt_estaciones &e)
{
    Bicicleta aux = devuelve_bicicleta(id_bici);
    Estacion auxe = e.consulta_estacion(id_estacion);
    string est_antigua = aux.consulta_estacion();

    aux.actualiza_estacion(id_estacion);

    auxe.afegir_bici(id_bici); // añade la bici al set de bicis de la estacion nueva
    e.actualizar_valor_map_estacion(id_estacion, auxe);
    auxe = e.consulta_estacion(est_antigua);
    auxe.borrar_bici(id_bici); // borra la bici del set de bicis de la estacion antigua
    e.actualizar_valor_map_estacion(est_antigua, auxe);
    actualizar_valor_map_bicicleta(id_bici, aux);
}

void cjt_bicis::subir_bicis(const string id_bici, Estacion& antigua, Estacion& nueva, cjt_estaciones &e)
{
    Bicicleta aux = devuelve_bicicleta(id_bici);
    nueva.afegir_bici(id_bici);
    antigua.borrar_bici(id_bici);
    
    string id_ant = antigua.identificador_estacion();
    string id_nueva = nueva.identificador_estacion();

    aux.mod_bici(id_bici, id_nueva);

    actualizar_valor_map_bicicleta(id_bici, aux);
    e.actualizar_valor_map_estacion(id_ant, antigua);
    e.actualizar_valor_map_estacion(id_nueva, nueva);

}

void cjt_bicis::reestructurar_ubicacion(cjt_estaciones& e, const BinTree<string>& c){
    if (not c.left().empty() and not c.right().empty()){
        Estacion p = e.consulta_estacion(c.value());
        Estacion hleft = e.consulta_estacion(c.left().value());
        Estacion hright = e.consulta_estacion(c.right().value());

        bool acabar = p.estacion_llena();;
        while (not acabar)
        {
            if (not hleft.estacion_vacia() or not hright.estacion_vacia())
            {
                if (hleft.total_bicis() > hright.total_bicis())
                {
                    string aux = hleft.idbici_menor();
                    subir_bicis(aux, hleft, p, e);
                }
                else if (hright.total_bicis() > hleft.total_bicis())
                {
                    string aux = hright.idbici_menor();
                    subir_bicis(aux, hright, p, e);
                }
                else
                {
                    string aux1 = hleft.idbici_menor();
                    string aux2 = hright.idbici_menor();
                    if (aux1 < aux2)
                        subir_bicis(aux1, hleft, p, e);
                    else if (aux2 < aux1)
                        subir_bicis(aux2, hright, p, e);
                }
            }
            else acabar = true;

            if (p.estacion_llena())
                acabar = true;
        }
        reestructurar_ubicacion(e, c.left());
        reestructurar_ubicacion(e, c.right());
    }
 
}