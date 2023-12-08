/** @file cjt_bicis.hh
    @brief Especificacion de la clase cjt_bicis
*/

#ifndef CJT_BICIS_HH
#define CJT_BICIS_HH


#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif

#include "cjt_estaciones.hh"
#include "Bicicleta.hh"


using namespace std;

class cjt_bicis
{
private:
   map<string /*id bici*/, Bicicleta> total_bicis;

public:
    // Constructores
    /** @brief constructora por defecto
     * \pre <em>cierto<\em>
     * \post devuelve 
    */
    cjt_bicis();
 
    // Modificadores

    /** @brief la estacion de id_bici pasa a ser id_estacion
     *  \pre id_bici pertenece a una bicicleta, 
     *  id_estacion pertenece a una estacion diferente a la que esta id_bici
     * \post la estacion actual de id_bici es id_estacion
    */
    void cambiar_de_estacion(const string id_bici, const string id_estacion, cjt_estaciones& e);

    /** @brief añade la bici al total de bicis
     * \pre el parametro esta inicializado, bici no existe
     * \post se añade bici y el id de su estacion a total_bicis
     */
    void afegir_bici_total(const string bici, const string estacion);

    /** @brief borra la bici al total de bicis
     * \pre el parametro esta inicializado, bici existe
     * \post se borra bici y el id de su estacion a total_bicis
     */
    void borrar_bici_total(const string bici);

    /** @brief dar de alta una bici
     *  \pre bici no existe, id_estacion existe
     *  \post bici pasa a estar en la estacion determinada por id_estacion, se aumenta el total de bicis
    */  
    void alta_bici(const string bici, const string id_estacion);

    /** @brief dar de baja una bici
     *  \pre bici no existe
     *  \post bici desaparece del sistema; se decrementa el numero total de bicis, bicis desaparece de su estacion correspondiente
    */ 
    void baja_bici(const string id_bici, cjt_estaciones& e);

    /** @brief actualiza la bicicleta guarda en el map con valor id_bici
     *  \pre id_bici pertenece a una bici
     *  \post el valor del map con clave id_bici se actualiza por b
    */
   void actualizar_valor_map_bicicleta(string id_bici, Bicicleta b);

   /** @brief mueve las bicis hacia la primera opcion
    * \pre <em>cierto<\em>
    * \post llena cada estacion con bicis de sus predecesoras de la manera mas equlibriada posible
   */
    void reestructurar_ubicacion(cjt_estaciones& e, const BinTree<string>& c);

    /** @brief la estacion de id_bici pasa a ser id_estacion sin contar el viaje
     *  \pre id_bici pertenece a una bicicleta, 
     *  id_estacion pertenece a una estacion diferente a la que esta id_bici
     * \post la estacion actual de id_bici es id_estacion, el viaje no cuenta
    */
    void subir_bicis(const string id_bici, Estacion& antigua, Estacion& nueva, cjt_estaciones &e);


    // Consultores

    /** @brief devuelve la bicicleta correspondiente al id
     *  \pre id pertenece a una bicicleta
     *  \post devuelve la bicicleta asociada a id
    */
    Bicicleta devuelve_bicicleta(const string& id) const;

    /** @brief consulta si existe la bicicleta
     * \pre <em>cierto<\em>
     * \post devuelve true si existe la bicicleta
     */
    bool existe_bici(const string& bicicleta) const;

    // Lectura y escritura
    /** @brief imprime el id de la estacion correspondiente al id_bici
     *  \pre <em>cierto<\em>
     *  \post imprime el id de la estacion asociada al identificador de la bici
    */
    void imprime_estacion(const string& id_bici) const;
};
#endif