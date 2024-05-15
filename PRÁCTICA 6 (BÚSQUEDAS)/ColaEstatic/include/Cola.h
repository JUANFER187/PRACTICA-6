#ifndef COLA_H
#define COLA_H
#include <iostream>

const int TAM=100;

//***************************Definicion de la clase persona*************************
//**********************************************************************************
class persona
{
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    float promedioGeneral;
public:
    persona();
    persona(std::string n, std::string c, int ma, float pg);
    std::string getNombre() const { return nombre; }
    std::string getCarrera() const { return carrera; }
    int getMateriasAprobadas() const { return materiasAprobadas; }
    float getPromedioGeneral() const { return promedioGeneral; }

    void operator=(const persona& x);
    friend std::ostream& operator<<( std::ostream& o, const persona& p);
    friend std::istream& operator>>( std::istream& i, persona& p);
    persona& operator[](int index);

    bool operator==(const persona&p) const {
        return p.nombre==nombre && p.carrera==carrera && p.materiasAprobadas==materiasAprobadas && p.promedioGeneral==promedioGeneral;
    }

    bool operator<(const persona& p) const {
        return nombre < p.nombre;
    }

    bool operator>(const persona& p) const {
        return nombre > p.nombre;
    }

    bool operator<=(const persona& p) const {
        return nombre <= p.nombre;
    }

    bool operator>=(const persona& p) const {
        return nombre >= p.nombre;
    }
};
//***************************************************************************************



//****************************Definicion de la clase la****************************
//***********************************************************************************
class Cola
{
private:
    persona datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(persona& elem, int pos);
public:
    Cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend std::ostream& operator<<(std::ostream & o, Cola& L);
    friend std::istream& operator>>(std::istream & i, Cola& L);
    persona& operator[](int index);
    void enqueue(persona& elem);
    persona& dequeue();
    int busquedaLineal(const std::string& nombre);
    int busquedaBinaria(const persona& elem);

};
//*************************************************************************************

#endif // COLA_H
