/** @file program.cc
 * @brief Archivo principal
 * @mainpage -------
 *
 */

#ifndef NO_DIAGRAM
#include <iostream>
#endif

#include "cjt_estaciones.hh"
#include "Bicicleta.hh"
#include "Estacion.hh"
#include "cjt_bicis.hh"

using namespace std;

int main()
{

    string operacion;
    cjt_estaciones e;
    cjt_bicis b;
    cin >> operacion;
    while (operacion != "fin")
    {
        if (operacion == "alta_bici" or operacion == "ab")
        {
            string id_bici, id_est;
            cin >> id_bici >> id_est;
            cout << "#ab "<< id_bici << ' '  << id_est << endl;
            if (b.existe_bici(id_bici))
                cout << "error: la bici ya existe" << endl;
            else if (not e.existe_estacion(id_est))
                cout << "error: la estacion no existe" << endl;
            else
            {
                Estacion auxe = e.consulta_estacion(id_est);
                if (auxe.estacion_llena())
                    cout << "error: la bici no cabe" << endl;
                else
                {
                    b.alta_bici(id_bici, id_est);
                    auxe.afegir_bici(id_bici); 
                    e.actualizar_valor_map_estacion(id_est, auxe);
                    e.modifica_capacidad_total(-1);
                }
            }
        }
        else if (operacion == "baja_bici" or operacion == "bb")
        {
            string id_bici;
            cin >> id_bici;
            cout << "#bb "<< id_bici << endl;
            if (not b.existe_bici(id_bici))
                cout << "error: la bici no existe" << endl;
            else
                b.baja_bici(id_bici, e);
        }
        else if (operacion == "estacion_bici" or operacion == "eb")
        {
            string id_bici;
            cin >> id_bici;
            cout << "#eb " << id_bici << endl;
            if (not b.existe_bici(id_bici))
                cout << "error: la bici no existe" << endl;
            else
                b.imprime_estacion(id_bici);
        }
        else if (operacion == "viajes_bici" or operacion == "vb")
        {
            string id_bici;
            cin >> id_bici;
            cout << "#vb "<< id_bici << endl;
            if (not b.existe_bici(id_bici))
                cout << "error: la bici no existe" << endl;
            else
            {
                b.devuelve_bicicleta(id_bici).imprime_viajes();
            }
            /**
             * TODOS: escribir viajes que ha hecho bici(no modifica nada)
             */
        }
        else if (operacion == "mover_bici" or operacion == "mb")
        {
            string id_bici, id_estacion;
            cin >> id_bici >> id_estacion;
            cout << "#mb "<< id_bici << ' ' << id_estacion << endl;
            if (not b.existe_bici(id_bici))
                cout << "error: la bici no existe" << endl;
            else if (not e.existe_estacion(id_estacion))
                cout << "error: la estacion no existe" << endl;
            else if (id_estacion == b.devuelve_bicicleta(id_bici).consulta_estacion())
                cout << "error: la bici ya esta en el sitio" << endl;
            else if (e.consulta_estacion(id_estacion).estacion_llena())
                cout << "error: la bici no cabe" << endl;
            else
            {
                b.cambiar_de_estacion(id_bici, id_estacion, e);
                /**
                 * TODOS: mover bici de e1 a e2. Vigilar los 70000 errores que puede haber. modificar parametros bicicleta (est actual y viajes), estacion(set), total_bicis modifica???, cjt_estaciones modifica????
                 */
            }
        }
        else if (operacion == "bicis_estacion" or operacion == "be")
        {
            string id_estacion;
            cin >> id_estacion;
            cout << "#be " << id_estacion << endl;
            if (not e.existe_estacion(id_estacion))
                cout << "error: la estacion no existe" << endl;
            else
            {
                Estacion auxe = e.consulta_estacion(id_estacion);
                auxe.bicis_en_estacion();
            }
            /**
             * TODOS: set.size();
             */
        }
        else if (operacion == "modificar_capacidad" or operacion == "mc")
        {
            string id_estacion;
            int num;
            cin >> id_estacion >> num;
            cout << "#mc " << id_estacion << ' ' << num << endl;
            if (not e.existe_estacion(id_estacion))
                cout << "error: la estacion no existe" << endl;
            else
            {
                Estacion auxe = e.consulta_estacion(id_estacion);
                if (num < auxe.total_bicis())
                    cout << "error: capacidad insuficiente" << endl;
                else
                {
                    int n = num - auxe.max_estacion();
                    auxe.aumentar_capacidad(num);
                    e.modifica_capacidad_total(n);
                    e.actualizar_valor_map_estacion(id_estacion, auxe);
                    /**
                     * TODOS: modifica max_bicis estacion
                     */
                }
            }
        }
        else if (operacion == "plazas_libres" or operacion == "pl")
        {
            cout << "#pl" << endl << e.plazas_libres() << endl;
        }
        
        else if (operacion == "subir_bicis" or operacion == "sb")
        {
            cout << "#sb" << endl;
            b.reestructurar_ubicacion(e, e.consultar_arbol());
        }
        /*else if (operacion == "a"){
            BinTree<string> arbol = e.consultar_arbol();
            cout << arbol.value() << arbol.left().value() << arbol.right().value() << endl;
            vector<pair<string, pair<string, string>>> v;
            e.nodos(arbol, v);
            for (int i = 0; i < v.size(); ++i)
            cout << v[i].first << "   " << v[i].second.first << "   " << v[i].second.second << endl;
        }*/
        else if (operacion == "asignar_estacion" or operacion == "ae")
        {
            string id_bici;
            cin >> id_bici;
            cout << "#ae " << id_bici << endl;
            if (b.existe_bici(id_bici)) cout << "error: la bici ya existe" << endl;
            else if (e.plazas_libres() == 0) cout << "error: no hay plazas libres" << endl;
            else {
                double n = 0;
                Estacion auxe(0, "np");
                e.coef_des(e.consultar_arbol(), n, auxe);
                cout << auxe.identificador_estacion() << endl;
                b.alta_bici(id_bici, auxe.identificador_estacion());
                auxe.afegir_bici(id_bici); 
                e.modifica_capacidad_total(-1);
                e.actualizar_valor_map_estacion(auxe.identificador_estacion(), auxe);
            }

        }

        cin >> operacion;
    }
    
}
