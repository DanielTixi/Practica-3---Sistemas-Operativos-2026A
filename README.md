title: Proceso Hijo que enliste los procesos del sistema
authors: Emily Morales, Vanessa Paucar, Karen Tapia, Emily Vargas y Daniel Tixicuro.

format:
html:
 toc: true
    title-block-banner: "#2c3e50"
    title-block-banner-color: "white"
    include-in-header:
      text: |
        <style>
        .quarto-title-block .quarto-title-banner {
          background-image: url("./Imagenes/logo.png");
          background-repeat: no-repeat;
          background-position: right 10px center;
          background-size: 60px;
        }

        #TOC {
          font-size: 12px;
          max-width: 200px;
          line-height: 1.1;
        }
        
        #TOC .toc-title {
          font-size: 10px;
          color: #888;
        }

        main h1 {
          font-size: 40px;
          text-transform: lowercase;
        }
        </style>
---
# Parte 3.3.1 de procesos hijos que enlisten los procesos del sistema usando system

## ¿QUÉ SE REALIZO?
En lenguaje C dentro de la maquina virtual,  se realizo el programa que tiene como función una  llamada al sistema `fork()`, con la cual se generó un proceso hijo . Con esto el programa permite que el proceso hijo lleve a cabo una tarea concreta  del sistema antes de que se acabe la ejecución del programa.

## Funciones utilizadas en el programa
*Fork/ bifurcación:* Dentro del programa existen dos hilos en los que sucede la ejecución.  `fork()`identifica en proceso estamos ubicados, si en el proceso padre o en el proceso hijo.
*Uso de system():* Dentro del proceso hijo se empleó la siguiente función `system("ps -f")`, la función llama al interpretador de comandos con el objetivo de ejecutar `ps`, que tiene como función enlistar los procesos del sistema de manera detallada.
*Sincronización:* `wait(NULL)` se encuentra dentro del proceso padre con el objetivo que espere a que su hijo termine y muestre todo al usuario, el padre no puede acar si su hijo aun no acaba.

## Resultados del ejecutable
Al ejecutar `./programa_ejecutable`, el programa mostró exitosamente:
1. El programa se ejecutó con exito.
2. La tabla completa de procesos del sistema Linux (WSL).
3. Al finalizar el proceso el padre muestra un mensaje de finalizado.
![Texto descriptivo de la imagen](resultado.png)
