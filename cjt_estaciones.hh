/** @file cjt_estaciones.hh
    @brief Especificacion de la clase cjt_estaciones
*/

#ifndef CJT_ESTACIONES_HH
#define CJT_ESTACIONES_HH


#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif

#include "BinTree.hh"
#include "Estacion.hh"

using namespace std;

class cjt_estaciones
{
private:
    // !SI ACTUALIZO UNA ESTACION GUARDADA PREVIAMENTE EN UN MAP, TENGO QUE ACTUALIZAR EL MAP? SIIII
    map<string/*id estacion*/, Estacion> conj_estaciones;
    //map<string, /*id estacion*/ int /*total de bicis en la estacion*/> total_estaciones;
    BinTree<string> bicing;
    int capacidad_total;


    /** @brief calcula el num de nodos, y el numero de plazas vacias que tiene b
     *  \pre n = 0
     *  \post devuelve el numero de nodos del bintree, n pasa a ser el numero de plazas vacias de b
    */
    double plazas_vacias(const BinTree<string>& b, double& n) const;

    /** @brief leer un bintree en preorden
     *  \pre <em>cierto<\em>
     * \post devuelve el BinTree correspondiente
     */
    BinTree<string> leer_arbol(int& capacidad);
   
public:
    // Constructores
    /** @brief constructora por defecto
     * \pre <em>cierto<\em>
     * \post devuelve un cjt_estaciones con map vacio, lee un bintree en preorden
    */
    cjt_estaciones();

    // Modificadores

    /** @brief actualiza el valor de la capacidad total del conjunto de estaciones
     * \pre <em>cierto<\em>
     * \post añade/quita num a la capacidad total 
    */
    void modifica_capacidad_total(int num);

    /** @brief actualiza la estacion guardada en el map con valor id_estacion
     *  \pre id_estacion pertenece a una estacion
     *  \post el valor del map con clave id_estacion se actualiza por e
    */
   void actualizar_valor_map_estacion(const string& id_estacion, const Estacion& e);

    // Consultores

    /** @brief devuelve la estacion con el coeficiente de desocupacion mayor
     * \pre n = 0
     * \post calcula la estacion con coeficiente de desocupacion mayor, en caso que haya dos con el mismo devuelve la estacion
     * con el id menor. Deja en n dicho coeficiente. Deja dicha estacion en r
    */
    void coef_des(const BinTree<string>& b, double& n, Estacion& r) const;

    /** @brief devuelve el arbol del parametro implicito
     * \pre p.i. inicializado
     * \post devuelve el BinTree del p.i.
    */
    BinTree<string> consultar_arbol() const;

    /** @brief devuelve la estacion asignada a id
     * \pre id corresponde a una estacion
     * \post devuelve la estacion correspondiente al id
    */
   Estacion consulta_estacion(const string id) const;

    /** @brief consulta si existe la estacion
     * \pre <em>cierto<\em>
     * \post devuelve true si existe la estacion
     */
    bool existe_estacion(const string& estacion) const;

    /** @brief Devuelve el numero total de plazas libres
     * \pre <em>cierto<\em>
     * \post devuelve el total de plazas libres
     */
    int plazas_libres() const;

    // Lectura y escritura
};
#endif