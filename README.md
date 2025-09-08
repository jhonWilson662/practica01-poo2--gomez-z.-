# como compilar proyecto en C++
ingresar al repositorio y descarguar los archivos en cpp que contiene un programa escrito en *C++*.  
Las instrucciones sirven tanto para **Linux** como para **Windows**.
## Requisitos
- Tener instalado un compilador que soporte **C++17**:
  - En **Linux**: suele venir con `g++`.
  - En **Windows**: se puede usar **MinGW** o instalar `g++` con herramientas como [MSYS2](https://www.msys2.org/).
##  Cómo compilar

### En Linux
1. Abre la terminal en la carpeta donde está el archivo `archivo.cpp`.
2. Escribe el siguiente comando:
- Para practica01_time.cpp:
  -g++ -std=gnu++17 -O2 -Wall practica01_time.cpp -o time_app
  -Para practica01_shape.cpp:
  -g++ -std=gnu++17 -O2 -Wall practica01_shape.cpp -o shape_app

### En windows
1. Abre PowerShell o la terminal de MinGW en la carpeta donde está archivo.cpp.
2. Ejecuta el siguiente comando:
Para practica01_time.cpp:
g++ -std=gnu++17 -O2 -Wall practica01_time.cpp -o time_app.exe
Para practica01_shape.cpp:
g++ -std=gnu++17 -O2 -Wall practica01_shape.cpp -o shape_app.exe
