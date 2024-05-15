#include "Cola.h"

persona::persona(){
    nombre="Juanito";
    carrera="Turismo";
    materiasAprobadas=13;
    promedioGeneral=7.8;
}

persona::persona(std::string n, std::string c, int ma, float pg): nombre(n), carrera(c), materiasAprobadas(ma), promedioGeneral(pg) {}
void persona::operator=(const persona& x)
{
    nombre=x.nombre;
    carrera=x.carrera;
    materiasAprobadas=x.materiasAprobadas;
    promedioGeneral=x.promedioGeneral;
}

std::ostream& operator<<(std::ostream & o, const persona& p)
{
    o << "Nombre: " << p.getNombre() << "\t Carrera: " << p.getCarrera() << "\t Materias aprobadas: " << p.getMateriasAprobadas() << "\t Promedio: " << p.getPromedioGeneral() << std::endl;
    return o;
}

std::istream& operator>>(std::istream & i, persona& p)
{
    std::cout << "\nInserta nombre: ";
    i >> p.nombre;
    std::cout << "\nInserta carrera: ";
    std::cin.ignore();
    i >> p.carrera;
    std::cout << "\nInserta cantidad de materias aprobadas: ";
    i >> p.materiasAprobadas;
    std::cout << "\nInserta promedio general: ";
    i >> p.promedioGeneral;

    return i;
}

bool Cola::vacia()const
{
    if(ult==-1)
        return true;
    return false;
}
bool Cola::llena()const
{
    if(ult==TAM-1)
        return true;
    return false;
}

int Cola::ultimo()const
{
    return ult;
}

std::ostream& operator<<(std::ostream & o, Cola& L)
{
    int i=0;
    std::cout<<"\n";
    while(i<=L.ultimo())
    {
        o<<L.datos[i];
        i++;
    }
    return o;
}
std::istream& operator>>(std::istream & i, Cola& L)
{
    int j=0;
    std::cout<<"\n";
    while(j<=L.ultimo())
    {
        i>>L.datos[j];
        j++;
    }
    return i;
}

persona& Cola::operator[](int index)
{
    if (index < 0 || index > ult)
    {
        // Manejar el caso cuando el índice esté fuera de rango
        throw std::out_of_range("Índice fuera de rango en la cola");
    }

    return datos[index];
}

void Cola::enqueue(persona& elem)
{
    inserta(elem,0);
}

persona& Cola::dequeue()
{
    if(vacia()){
        std::cout<<"\n La cola esta vacia"<<std::endl;
    }
    ult--;
    return datos[ult+1];
}

bool Cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i] = datos[i+1];
        i++;
    }
    ult--;
    return false;
}

int Cola::inserta(persona& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        std::cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}

int Cola::busquedaLineal(const std::string& nombre) {
    if (vacia()) {
        return -1;
    }
    for (int i = 0; i <= ult; i++) {
        if (datos[i].getNombre() == nombre) {
            return i;
        }
    }
    return -1;
}

 int Cola::busquedaBinaria(const persona& elem) {
    int i = 0, j = ult;
    while (i <= j) {
        int medio = (i + j) / 2;

        if (elem == datos[medio])
            return medio;

        if (elem < datos[medio])
            j = medio - 1;
        else
            i = medio + 1;
    }
    return -1;
}
