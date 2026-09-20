# Neon Salvage

**Neon Salvage** es un proyecto de videojuego 2D de acción y exploración desarrollado con **Godot 4** sobre Linux.  
El proyecto está pensado tanto como videojuego como ejercicio de ingeniería de software, integrando lógica de alto nivel en **GDScript** con módulos nativos escritos en **C++** y una biblioteca algorítmica en **C**.

> **Estado actual:** proyecto en fase inicial de diseño y configuración. Las características descritas aquí representan el alcance previsto del proyecto y se irán implementando por etapas.

---

## Concepto

El jugador explora una estación espacial averiada, recupera componentes tecnológicos, administra recursos y se enfrenta a drones hostiles.

El objetivo general de cada partida es avanzar por distintos sectores de la estación, conseguir recursos, mejorar el equipamiento y finalmente restaurar el reactor principal.

### Bucle principal

1. Entrar a un sector de la estación.
2. Explorar habitaciones conectadas.
3. Combatir o evitar enemigos.
4. Recolectar metal, circuitos y celdas de energía.
5. Regresar a una zona segura.
6. Comprar mejoras.
7. Desbloquear nuevos sectores.
8. Restaurar el reactor principal.

---

## Objetivos técnicos

Además del desarrollo del videojuego, Neon Salvage busca practicar conceptos de ingeniería y programación de sistemas:

- Desarrollo de videojuegos con Godot 4.
- Arquitectura modular.
- Programación orientada a objetos.
- Integración de varios lenguajes.
- Programación nativa con C y C++.
- Uso de GDExtension.
- Algoritmos de generación procedural.
- Pathfinding e inteligencia artificial.
- Manejo de memoria y estructuras de datos.
- Compilación y linking en Linux.
- Pruebas unitarias y de integración.
- Profiling y optimización.
- Control de versiones con Git.

---

## Tecnologías

| Tecnología | Uso previsto |
|---|---|
| **Godot 4.x** | Motor principal del videojuego |
| **GDScript** | Gameplay, UI, escenas y lógica de alto nivel |
| **C++** | Extensiones nativas mediante GDExtension |
| **C** | Biblioteca algorítmica independiente |
| **godot-cpp** | Enlace entre C++ y Godot |
| **CMake / SCons** | Compilación de código nativo |
| **GCC / Clang** | Compiladores en Linux |
| **GDB** | Depuración de código nativo |
| **Git / GitHub** | Control de versiones |

---

## Arquitectura

La idea principal es mantener responsabilidades claramente separadas entre los distintos lenguajes.

```text
Godot / GDScript
        |
        v
GDExtension / C++
        |
        v
Biblioteca C
(neon_core)
```

### GDScript

Se utilizará principalmente para:

- Movimiento del jugador.
- Armas y proyectiles.
- Sistema de daño y vida.
- Inventario.
- Mejoras.
- Interfaz de usuario.
- Menús.
- Audio.
- Gestión de escenas.
- Guardado y carga de partida.

### C++

C++ funcionará como capa nativa y como puente entre Godot y la biblioteca escrita en C.

Módulos previstos:

- `NativeNavigator`: pathfinding y navegación.
- `ThreatAnalyzer`: análisis de posiciones y amenazas.
- `SectorGenerator`: adaptación de la generación procedural hacia Godot.
- Herramientas de benchmark para comparar implementaciones nativas con GDScript.

### C

La biblioteca `neon_core` será independiente de Godot y contendrá algoritmos reutilizables.

Funciones previstas:

- Generador pseudoaleatorio determinista.
- Generación de sectores a partir de una semilla.
- Utilidades matemáticas.
- Distancias sobre rejilla.
- Estructuras simples para representar habitaciones y posiciones.

La biblioteca C **no dependerá de headers de Godot**.  
Esto permitirá probarla por separado y mantener una frontera clara entre el motor y la lógica algorítmica.

---

## Mecánicas previstas

### Jugador

- Movimiento en ocho direcciones.
- Sistema de vida.
- Energía.
- Disparo.
- Interacción con objetos.
- Recolección de recursos.

### Combate

- Proyectiles.
- Daño.
- Cooldowns.
- Diferentes tipos de enemigos.
- IA con estados como:

```text
Idle -> Patrol -> Chase -> Attack
```

### Recursos

El jugador podrá recolectar, entre otros:

- Metal.
- Circuitos.
- Celdas de energía.

Estos recursos se utilizarán para comprar mejoras.

### Mejoras

Entre las mejoras planeadas se encuentran:

- Velocidad de movimiento.
- Daño.
- Energía.
- Capacidad de inventario.

### Generación procedural

Los sectores de la estación se generarán utilizando una **seed**.

Una misma seed deberá producir el mismo layout, permitiendo pruebas reproducibles y eventualmente sistemas de replay o desafíos compartidos.

---

## Estructura prevista del proyecto

```text
NeonSalvage/
├── godot/
│   ├── project.godot
│   ├── scenes/
│   │   ├── player/
│   │   ├── enemies/
│   │   ├── world/
│   │   └── ui/
│   ├── scripts/
│   ├── assets/
│   └── native/
│       └── neon_native.gdextension
│
├── native/
│   ├── cpp/
│   │   ├── include/
│   │   └── src/
│   │
│   ├── c/
│   │   ├── include/
│   │   │   └── neon_core.h
│   │   ├── src/
│   │   │   └── neon_core.c
│   │   └── tests/
│   │
│   └── CMakeLists.txt
│
├── docs/
│   ├── architecture.md
│   └── test-plan.md
│
├── .gitignore
└── README.md
```

Esta estructura puede cambiar a medida que evolucione el proyecto.

---

## Entorno de desarrollo

El proyecto está orientado inicialmente a **Linux x86_64**, especialmente Ubuntu 24.04 LTS o distribuciones compatibles.

### Dependencias de desarrollo

En Ubuntu se pueden instalar las herramientas principales con:

```bash
sudo apt update

sudo apt install -y \
    build-essential \
    cmake \
    ninja-build \
    git \
    gcc \
    g++ \
    gdb \
    clang \
    clang-format \
    pkg-config
```

También será necesario instalar:

- Godot 4.x.
- `godot-cpp` para el desarrollo de GDExtension.

---

## Clonar el repositorio

```bash
git clone https://github.com/victorjulioch777-ui/NeonSalvage.git
cd NeonSalvage
```

Las instrucciones de compilación de los módulos nativos se agregarán cuando la primera versión de `neon_core` y la GDExtension estén incorporadas al repositorio.

---

## Primer objetivo técnico

Antes de desarrollar sistemas grandes de gameplay, el primer hito será validar toda la comunicación entre lenguajes:

```text
Godot -> GDScript -> C++ -> C
```

La primera prueba deberá:

1. Ejecutarse desde una escena de Godot.
2. Invocar una clase implementada en C++ mediante GDExtension.
3. Hacer que C++ llame a una función de la biblioteca C.
4. Retornar el resultado a Godot.
5. Mostrar el resultado en pantalla.

Este hito permitirá comprobar que la arquitectura funciona de extremo a extremo antes de añadir más complejidad.

---

## NativeLab

El proyecto incluirá una escena técnica llamada `NativeLab.tscn`.

Su objetivo será probar los módulos escritos en C y C++ de forma independiente al gameplay principal.

Entre las herramientas planeadas:

- Introducir una seed.
- Generar un sector.
- Visualizar habitaciones generadas.
- Ejecutar pathfinding.
- Mostrar tiempos de ejecución.
- Comparar GDScript y C++ en operaciones seleccionadas.

---

## MVP

El primer MVP de Neon Salvage tendrá como objetivo ofrecer una partida corta pero completa.

Características previstas:

- Movimiento del jugador.
- Sistema de disparos.
- Dos tipos de enemigos.
- HUD de vida y energía.
- Tres recursos recolectables.
- Inventario.
- Mejoras.
- Generación procedural basada en seed.
- Guardado local.
- Integración funcional entre Godot, C++ y C.
- Condición de victoria y derrota.

La duración objetivo inicial de una partida será de aproximadamente **10 a 15 minutos**.

---

## Roadmap

### Fase 0 — Setup

- Crear estructura del proyecto.
- Configurar Godot.
- Configurar Git.
- Preparar toolchain de C/C++.

### Fase 1 — Vertical slice

- Movimiento.
- Cámara.
- Disparo.
- Un enemigo.
- HUD básico.

### Fase 2 — Biblioteca C

- Crear `neon_core`.
- Implementar RNG determinista.
- Implementar estructuras básicas.
- Crear pruebas unitarias.

### Fase 3 — GDExtension

- Integrar `godot-cpp`.
- Crear clases C++ visibles desde Godot.
- Conectar C++ con `neon_core`.

### Fase 4 — Sistemas de juego

- Inventario.
- Recursos.
- Mejoras.
- Guardado.
- Nuevos enemigos.

### Fase 5 — Contenido

- Nuevos sectores.
- Audio.
- Efectos.
- Eventos.
- Condición final de victoria.

### Fase 6 — QA y optimización

- Pruebas.
- Profiling.
- Corrección de errores.
- Optimización.
- Build final para Linux.

---

## Pruebas

El proyecto buscará incorporar varios niveles de pruebas.

### Biblioteca C

- RNG determinista.
- Distancias.
- Límites de generación.
- Casos inválidos.

### Integración

- Godot puede cargar la extensión.
- GDScript puede llamar código C++.
- C++ puede llamar correctamente a C.
- Los datos pueden regresar a Godot sin corrupción.

### Gameplay

- Movimiento y colisiones.
- Combate.
- Inventario.
- Guardado y carga.
- Condiciones de victoria y derrota.

### Rendimiento

Se realizarán pruebas con diferentes cantidades de agentes para evaluar sistemas como pathfinding y análisis espacial.

---

## Metas de rendimiento

Objetivos iniciales:

- 60 FPS durante gameplay normal.
- Resolución de referencia: 1920x1080.
- Inicio rápido del juego.
- Ausencia de errores críticos durante sesiones de prueba.
- Compilación reproducible del código nativo desde terminal.

---

## Alcance

Neon Salvage busca ser ambicioso desde el punto de vista técnico, pero deliberadamente moderado en contenido y arte.

No forman parte del primer alcance:

- Multijugador online.
- Mundo abierto.
- 3D avanzado.
- Editor de niveles propio.
- Sistema de mods.
- Grandes cantidades de armas o enemigos.
- Reescrituras innecesarias del motor en C++.

La prioridad es construir sistemas sólidos y comprender su funcionamiento.

---

## Plataforma inicial

El desarrollo se realizará principalmente para:

- **Sistema operativo:** Linux
- **Arquitectura:** x86_64
- **Motor:** Godot 4.x
- **Renderizado:** 2D

En el futuro se podrá evaluar la exportación a otras plataformas.

---

## Estado del proyecto

🚧 **En desarrollo**

Actualmente el proyecto se encuentra en sus primeras etapas.

El siguiente objetivo es construir la base del proyecto y lograr el primer puente funcional:

```text
Godot -> C++ -> C
```

---

## Autor

Desarrollado por **Victor Julio Chavarria** como proyecto personal y de aprendizaje en desarrollo de videojuegos, C, C++ y arquitectura de software.
