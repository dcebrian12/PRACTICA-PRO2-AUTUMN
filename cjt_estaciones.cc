#include "cjt_estaciones.hh"
#include "BinTree.hh"
#include "Estacion.hh"

cjt_estaciones::cjt_estaciones()
{

    conj_estaciones = map<string, Estacion>();
    bicing = leer_arbol(capacidad_total);
}

bool cjt_estaciones::existe_estacion(const string& estacion) const
{
    return conj_estaciones.find(estacion) != conj_estaciones.end();
}

Estacion cjt_estaciones::consulta_estacion(const string id) const
{
    return (conj_estaciones.find(id))->second;
}

BinTree<string> cjt_estaciones::leer_arbol(int& capacidad)
{
    string id_est;
    int max_bicis;

    cin >> id_est;

    if (id_est == "#") return BinTree<string>();
    else {
        cin >> max_bicis;
        capacidad += max_bicis;
        Estacion estacion(max_bicis, id_est);
        conj_estaciones.insert(make_pair(id_est, estacion));
        BinTree<string> izq = leer_arbol(capacidad);
        BinTree<string> der = leer_arbol(capacidad);
        return BinTree<string>(id_est, izq, der);
    }
}

int cjt_estaciones::plazas_libres() const
{
    return capacidad_total;
}

void cjt_estaciones::actualizar_valor_map_estacion(const string& id_estacion, const Estacion& e)
{
    map<string, Estacion>::iterator it = conj_estaciones.find(id_estacion);
    it->second = e;
}


BinTree<string> cjt_estaciones::consultar_arbol() const
{
    return bicing;
}


void cjt_estaciones::transforma_arbol(const BinTree<string>& b, const string& top, BinTree<string>& f)
{
    if (not b.empty())
    {
        if (b.value() == top)
            f = b;
        else
        {
            transforma_arbol(b.left(), top, f);
            transforma_arbol(b.right(), top, f);
        }
    }
}

double cjt_estaciones::plazas_vacias(const BinTree<string>& b, double& n) const{
    double x;
    if (b.empty()) x = 0;
    else {
        Estacion auxe = consulta_estacion(b.value());
        n += auxe.max_estacion() - auxe.total_bicis();
        x = plazas_vacias(b.left(), n) + plazas_vacias(b.right(), n) + 1;
    }
    return x;
}

Estacion cjt_estaciones::coef_des(const BinTree<string>& b, double &n) const
{
    Estacion f(0, "NP");
    map<string, Estacion>::const_iterator it = conj_estaciones.begin();
    BinTree<string> a = BinTree<string>();
    for (; it != conj_estaciones.end(); ++it){
        string aux = it->first;
        transforma_arbol(b, aux, a);
        double num = 0;
        double c = plazas_vacias(a, num);
        c = num/c;
        if (c > n) {
            n = c;
            f = it->second;
        }
        else if (c == n){
            if (it->first < f.identificador_estacion()) {
                n = c;
                f = it->second;
            }
        }
    }

    return f;
}

void cjt_estaciones::modifica_capacidad_total(int num){
   capacidad_total += num;
}
