# Tarea 2
#### Principios de Sistemas Operativos
Julio Rojas - 2015

Jose Paulo Yock - 2015018215


## Introducción: 

La siguiente tarea consiste en realizar un servidor web implementado en el lenguaje C, mediante la implementacion de hilos "pre-thread" y procesos "pre-fork". Ademas el web server debe ser capaz de procesar consultas utilizando el protocolo de mensajes HTTP/1.1 el cual tambien debe ser implementado en el lenguaje C.

La siguiente tarea tienen la intencion de comprender el funcionamiento de tanto hilos como procesos en el Sistema Operativo Linux.

## Ambiente de desarrollo: 

Para realizar esta tarea se utilizaron varios lenguajes de programación, tales como, C y Python.
En C se implementaron las dos maneras del webServer "pre-fork" y "pre-thread", un cliente HTTP para realizar consultas al servidor y la implementacion del protocolo HTTP. Y en Python se implementó un programa para medir el server en caracteristicas de estrés, además de otro cliente para realizar consultas HTTP.
Además de los lenguajes, se utilizaron algunas bibliotecas como en el caso de C la PTHREAD, para hacer uso de los hilos en modo kernel implementados. Por otro lado, en Python, se utilizó Threading y subprocess para realizar el cliente de estrés, ademas de utilizar pyCurl para implementar el cliente HTTP.

## Estructuras de datos usadas y funciones: 

Para realizar esta tarea, se utilizaron algunas estructuras, como un arreglo de hilos para recibir clientes.
Entre las funciones utilizadas, las más importantes son: la que se utiliza para crear el socket del server, la que se encarga de realizar el binding al puerto específico y la que hace que el socket comience a escuchar a sus clientes.
Además de estos, se tiene un módulo del cuál se encarga de discriminar el puerto y asignar el protocolo de respuesta correcto.
En el módulo implementado para la prueba de estrés, se programó una función la cuál consiste en ejecutar el binario específicado.

## Instrucciones para ejecutar el programa: 

Para ejecutar alguno de los servers se debe ejecutar

```sh
$ ./prethread-webserver -p [puerto] -n [cantidad de hilos] -w [path raiz del recurso] 
//en el caso de los hilos

$ ./preforked-webserver -p [puerto] -n [cantidad de hilos] -w [path raiz del recurso] 
//en el caso de los procesos
```
Con estos comandos se pone a correr el server.

Los puertos posibles son:

- 2020, 2021 para FTP
- 2025 para SMTP
- 2053 para DNS
- 2023 para TELNET
- 2022 para SSH
- 8080 para HTTP
- 2161 para SNMP
- Cualquier otro, HTTP

Para ejecutar el cliente HTTP en C:

```sh
$ ./httpClient -i [IP] -u [RECURSO] -p [PUERTO]
```
En el caso del cliente HTTP para Python, se debe ejecutar:

```sh
$ python3 httpClient.py -i [IP] -u [RECURSO] -p [PUERTO]
```

## Actividades realizadas por estudiante: 

Este es un resumen de las bitácoras de cada estudiante ( estilo timesheet) en términos del tiempo invertido para una actividad específica que impactó directamente el desarrollo del trabajo, de manera breve (no más de una línea) se describe lo que se realizó, la cantidad de horas invertidas y la fecha en la que se realizó. Se deben sumar las horas invertidas por cada estudiante, sean concientes a la hora de realizar esto el profesor determinará si los reportes están acordes al producto entregado.

## Comentarios finales (estado del programa):

Los servidores funcionan en su totalidad, se parsea correctamente el mensaje HTTP y se responde correctamente el recurso a los clientes. Ademas el servidor es capas de ejecutar un programa si es utilizado el metodo POST y de retornar lo que este programa imprima por el estandar output.
Ambos clientes implementados tambien funcionan correctamente.
El programa encargado de estresar el servidor funciona correctamente.

## Conclusiones:

El protocolo HTTP sigue una serie de reglas muy simples, lo cual lo hace facil de comprender y aplicar.


## Bibliografía:

* List of HTTP status codes. (2017, September 9). In Wikipedia, The Free Encyclopedia. Retrieved 8 September 2017
, from https://en.wikipedia.org/w/index.php?title=List_of_HTTP_status_codes
&oldid=799671481

* HTTP Messages. (2017). Mozilla Developer Network. Retrieved 3 September 2017, from https://developer.mozilla.org/es/docs/Web/HTTP/Messages