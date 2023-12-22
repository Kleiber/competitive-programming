# C++ Standard Template Library (STL)

1. **vector**: Arreglo de tamaño dinámico.
2. **string**: Cadena de tamaño dinámico.
3. **pair**: Dupla o par de objetos.
4. **bitset**: Arreglo de bits(0 o 1), optimizado para eficiencia.
4. **set**: Conjunto ordenado de elementos
5. **map**: Conjunto ordenado de elementos y valores asociados.
6. **stringstream**: Flujo de datos
7. **queue**: Cola

```c++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>

#include <set>
#include <map>
 
#include <queue>
#include <stack>
 
#include <cstdio>
#include <cmath>  
#include <cstdlib>
 
using namespace std;

int main()
{
 
    return 0;
}
```

## Vector

Declaración de los vectores:

```
vector <tipo> V;  // vacío
vector <tipo> V(n);  // n elementos, constructor del tipo
vector <tipo> V(n, aux); // n elementos iguales a aux
vector <tipo> W = V;  // se pueden asignar vectores
```

Ejemplos:
```c++
vector <double> aux;   // vacío, es mejor utilizar double que float
vector <int> x(10, 3);   // 10 elementos iguales a 3
vector < vector <int> > y(15, x);  // matriz de 15x10, elementos iguales a 3
```

Acceso a elementos y tamaño del vector:
```
V[ind]  // elemento ind de V, igual que los arreglos normales
int tam = V.size(); // tamaño del vector
```

Ejemplo:
```c++
for(int i=0; i<aux.size(); i++) {
  // muestra los elementos de aux
  cout<<aux[i]<<endl;
}
```

Agregar  elementos:
```
V.push_back(aux);  //coloca aux al final de V
V.insert(V.begin() + ind, aux); //inserta aux en el índice ind de V
```
 
Eliminar elementos:
```
V.erase(V.begin() + ind); //elimina el elemento V[ind]
V.clear();   //elimina todos los elementos de V
```

Ejemplo:
```c++
vector <int> nums;
int n;
cin>>n;
nums.push_back(n);
```

## Algorithm I

Mínimo o máximo:
```
min(a, b) // Devuelve el mínimo o máximo de a y b, para cualquier tipo de dato
max(a, b) // que tenga definido el operador < (int, string, vector, string, …)
```

Intercambio de valores:
```
swap(a, b); // equivale a: aux=a;
            //               a=b;
            //             b=aux;
```

Ordenamiento:
```
sort(V.begin(), V.end()); // ordena a V en orden creciente.
sort(V.rbegin(), V.rend()); // ordena a V en orden decreciente.
```
 
Invertir orden:
```
reverse(V.begin(), V.end()); // cambia V[i] por V[V.size() – i - 1]
```

## String

Declaración:
```
string s = "";  //cadena vacía
string s(n, ch);  //n caracteres ch
string s = aux;  //asignación de valores
```

Ejemplo:
```c++
string cad(10, 'a');
string x = "hola";
```

Acceso a caracteres:
```
char ch = s[ind];
```

Tamaño de la cadena:
```
int tam = s.size();
```

Concatenación:
```
s = s + aux;
s = aux + s;
```

Encontrar una subcadena:
```
int pos = s.find(aux);  // devuelve el índice de s en el que empieza aux
int pos = s.find(aux, ind); // devuelve el primer índice >= ind
// ambas retornan -1 si no encuentran a aux
```

Inserción:
```
s.insert(ind, aux);   // inserta a la cadena aux en el índice ind
```
 
Eliminación:
```
s.erase(ind, n);   // elimina n caracteres empezando en el índice ind
s.clear();   // borra toda la cadena
```

## Stringstream

`Input String Stream (istringstream):` Permiten extraer datos(int, string, char, bool) de un flujos de entrada(string)

```c++
string fecha = "domingo 16 de septiembre de 2007";

istringstream is(fecha);
int dd, yyyy;
string dia, mes, aux;
 
is>>dia>>dd>>aux>>mes>>aux>>yyyy;
```
 
`Output String Stream (ostringstream):` Permiten formar un flujo de salida a partir de datos.

```c++
int dd=16, yyyy=2007;
string dia="domingo", mes="septiembre", aux="de";
 
ostringstream os;
os<<dia<<" "<<dd<<" "<<aux<<" "<<mes<<" "<<aux<<" "<<yyyy;
 
string fecha=os.str();
```

## Pair

Declaración:

```
pair <tipo1, tipo2> x;
```

Ejemplo:

```c++
pair <int, int> x;   // pair de enteros
pair <string, string> x;  // pair de string
pair < pair<int, int>, int > x  // pair de cualquier tipo
```

Ingreso de valores:
```
pair <int, int> x;
int a=5, b=10;
x = make_pair(a, b);
```
 
Acceso a elementos:
```
x.first   // retorna el primer elemento
x.second   // segundo elemento
```

## Algorithm II

Function sort sobrecargada:
 
```
sort(x.begin(), x.end(), orden);
```
 
Donde orden es una funcion booleana que recibe 2 elementos de x y devuelve el resultado de la comparación entre ellos:

```
bool orden(tipo a, tipo b) {
  si a debe ser menor que b return 1;
  return 0;
}
```
 
En otras palabras “orden” sustituye al operador `<` usado por defecto.

Ejemplo:

```c++
Ordenar puntos (x, y)en un vector < pair <int, int> > según:
x creciente, y creciente
y creciente, x creciente
```

## Set

Contiene elementos sin repeticiones, ordenados ascendentemente.
 
Declaración:
```
set <tipo> x   // conjunto vacio
```

Insercion:
```
x.insert(a); // inserta a en el set
```
 
Numero de elementos:
```
x.size();
```

Eliminar elementos:  
```
x.erase(a);
```
 
Para recorrer el set se requiere del uso de iteradores:
```
set <int> x;
 
x.insert(10);
x.insert(3);
x.insert(5);
 
set <int> :: iterator it;
 
for(it=x.begin(); it!=x.end(); it++)
     cout<<(*it)<<endl;
```

Encontrar un elemento:
```
 x.find(aux)  // retorna el iterador que apunta al elemento aux
              // o x.end() si aux no pertenece a x
```

Ejemplo:

```c++
if(S.find(aux) == S.end()) cout<<“No existe”<<endl;
else cout<<“Si existe”<<endl
```

Pasar los elementos a un vector:
``` 
vector <tipo> v(x.begin(), x.end());   // se crea el vector v con los elementos del set x
```

Complejidad:

```
Buscar -> O(logn)
Insertar -> O(logn)
Borrar -> O(logn)
```

## Map

Analogo al vector pero no se accede a los elementos mediante un índice sino mediante un valor cualquiera(entero, vector, string, pair…).
 
Declaracion:
```
map <tipo1, tipo2> M;  tipo1 es el tipo de la “llave”,
tipo2 es el tipo de los elementos
```
 
Ejm:
```
map <string, int> M;

M["uno"]=1;
M["dos"]=2;

cout<<"uno + dos = "<<M["uno"] + M["dos"]<<endl;
cout<<"cero = "<<M["cero"]<<endl;
```

Recorrer todo el map:
```
map <string, int> :: iterator it;

for(it=M.begin(); it!=M.end(); it++)
  cout<<it->first<<" "<<it->second<<endl;
```
 
*Los elementos se guardan ordenados al igual que en el set, el acceso es en O(logn)
 
Pasar los elementos a un vector:
```
vector < pair <tipo1, tipo2> > v(M.begin(), M.end());
```

## Queue
```c++
struct nodo
{
    int ind, dist;
    nodo() {}
    nodo(int n1, int n2)
    {
           ind = n1;
           dist = n2;
     }
};
```

Declaración:
```
queue <nodo> Q;
```

Métodos:
```
Q.push(q);           // Añadir un elemento al final de la cola
nodo q = Q.front();  // Obtener el elemento del frente
Q.pop();             // Borrar el elemento del frente
Q.empty();           // 0 si la cola esta vacía, 1 si tiene algún elemento
```

## priority_queue

```c++
struct nodo
{
    int ind, dist;
    nodo() {}
    nodo(int n1, int n2)
    {
           ind = n1;
           dist = n2;
     }
};
bool operator <(nodo a, nodo b)
{
    return a.dist > b.dist;
}
```

Declaración:
```
priority_queue <nodo> Q;
```

Métodos:
```
Q.push(q);         // Añadir un elemento al final de la cola
nodo q = Q.top();  // Obtener el elemento con mayor prioridad (menor distancia)
Q.pop();           // Borrar el elemento del frente
```
                           
                          Q.empty();         // 0 si la cola esta vacía, 1 si tiene algún elemento

                          
