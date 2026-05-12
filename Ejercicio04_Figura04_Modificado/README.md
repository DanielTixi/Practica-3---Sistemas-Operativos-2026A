---
title: "3.1.4 Modificación Proceso padre y tres procesos hijos"
authors: Vanessa Paucar
format:
  html:
    embed-resources: true
    theme: cozy
    toc: true
    title-block-banner: "#2c3e50"
    title-block-banner-color: "white"
---

# Modificación ejercicio 4

## Cambio de valor leido.
Para hacer que cada hijo realice una acción diferente, se usa el valor del contador _pid_ por _i_ en el _switch(i)_, 
de esta forma en la variable _i_ se hereda el valor específico que tenía en el momento del _fork()_ para asignar
tareas únicas a cada proceso hijo.

## Control de errores
Se implementa una verificación la cual gestiona fallos en la creacion de procesos por parte del núcleo del sistema, 
por medio del condicional if, _if (pid == -1)_.

## Uso de _getpid()_
Se implementa la función _getpid()_ para asignar a cada proceso un identificador único a cada tarea.

## Tareas en los procesos hijos
1. **Hijo 1**: Realiza por medio de un _for_ una sumatoria de los 15 primeros números acumulados(1 al 15).
2. **Hijo 2**: Realiza el calculo de las potencias de 5 para demostrar el procesamiento de ciclos diferentes.
3. **Hijo 3**: Ejecuta el comando _ls -l_ para visualizar los archivos que contiene la carpeta donde se ejecuta el
 archivo .c y ver que permisos proporciona cada archivo.

## Salida de Ejecucion

![](../Imagenes/Ejecucion_Ejercicio04.png){fig-align="center" width="1500x"}
