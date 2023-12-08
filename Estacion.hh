
/** @file Estacion.hh
    @brief Especificacion de la clase Estacion
*/

#ifndef ESTACION_HH
#define ESTACION_HH

#ifndef NO_DIAGRAM
#include <set>
#include <string>
#endif

using namespace std;

class Estacion
{
private:

    string id_estacion;
    int max_bicis;                
    set<string> bicis_estacion;

public:
    // Constructores
    /** @brief Constructora por defecto
        \pre <em>cierto<\em>
        \post se crea una estacion con max_bicis = max y identificador id
    */
    Estacion(int max, const string id);

    // Modificadores

    /** @brief aumenta la capacidad maxima del p.i
     * \pre p.i inicializado, max_num es > 0 y >= que max bicis del p.i
     * \post se actualiza el valor de max_bicis del p.i por por max_num
    */
   void aumentar_capacidad(const int max_num);

    /** @brief añade la bici a la estacion
     * \pre <em>cierto<\em>
     * \post se añade la bicicleta a la estacion
     */
    void afegir_bici(const string& id_bici);

    /** @brief Borra una bicicleta de la estacion
        \pre id_bici existe
        \post la bicicleta no es encuentra en el parametro implicito
    */
    void borrar_bici(const string& id_bici);

    // Consultores

    /** @brief retorna la bici con el id mas pequeño
     *  \pre hay minimo una bicicleta en el p.i.
     * \post devuelve la bici con el id mas pequeño
    */  
    string idbici_menor() const;

    /** @brief devuelve el numero de bicis que se encuentran en la estacion
     *  \pre <em>cierto<\em>
     *  \post devuelve el total de bicis del p.i.
    */
   int total_bicis() const;

    /** @brief Consulta si la estacion esta llena
        \pre:<em>cierto</em>
        \post: devuelve true si la estacion esta llena, false si no lo esta
    */
    bool estacion_llena() const;

    /** @brief Consulta si la estacion esta vacia
        \pre:<em>cierto</em>
        \post: devuelve true si la estacion esta vacia, false si no lo esta
    */
    bool estacion_vacia() const;

    /** @brief Consulta el identificador del parametro implicito
        \pre <em>cierto<\em>
        \post Devuelve el identificador del parametro implicito
    */
    string identificador_estacion() const;

    /** @brief Consulta el tamaño maximo del parametro implicito
        \pre El parametro implicito esta inicializado
        \post Devuelve el maximo de bicicletas del parametro implicito
    */
    int max_estacion() const;

    // Lectura y escritura

    /** @brief imprime el id de las bicis en estacion
     *  \pre el p.i. esta inicializado
     *  \post se muestra por pantalla las bicis que hay en estacion por orden alfabetico
     */
    void bicis_en_estacion() const;

};
#endif