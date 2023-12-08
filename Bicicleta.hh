/** @file Bicileta.hh
    @brief Especificacion de la clase Bicicleta
*/ 

#ifndef BICICLETA_HH
#define BICICLETA_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#endif

using namespace std;

class Bicicleta {
    private:
        string id_bici;
        vector<pair<string /*inicio*/, string /*destino*/>> viajes; //viajes.size() es el num de viajes que ha hecho
        string est_actual;

        /** @brief se actualiza los viajes hechos por el p.i
         * \pre la estacion existe, el p.i no se encuentra en estacion
         * \post se actualiza el parametro viajes del p.i
         */
        void actualiza_viajes(const pair<string,string>& viaje);

    public:

        //constructora

        /** @brief constructora vacia
         * \pre <em>cierto<\em>
         * \post crea una bicicleta con id y estacion NP
        */ 
       Bicicleta();
        /** @brief constructora por defecto
            \pre el id no existe en ninguna estacion
            \post se crea una bicicleta con identificador id
        */
        Bicicleta(const string& id, const string& estacion);
        
        //Modificadores

        /** @brief actualiza la estacion donde se encuentra el p.i.
        * \pre  <em>cierto<\em>
        * \post La bicicleta pasa a estar en id_estacion, se añade el viaje al total del p.i.
        */
        void actualiza_estacion(const string& id_estacion);

        /** @brief modificadora por defecto
         *  \pre id_bici no corresponde a ninguna bicicleta, ide corresponde a una estacion
         *  \post los parametros del p.i se actualizan
        */
        void mod_bici(const string &id_bici, const string& ide);
        
        //Consultores
        
        /** @brief consulta estacion
            \pre P.i. inicializado
            \post Devuelve la estacion donde se encuentra del parametro implicito
        */
        string consulta_estacion() const;

        //Lectura y escritura

        /** @brief escribe de viajes realizados
            \pre La bicicleta existe
            \post imprime los viajes realizados por el p.i.
        */
        void imprime_viajes() const;

};
#endif