# Tarea 2
#### Principios de Sistemas Operativos
Julio Rojas - 2015

José Paulo Yock - 2015018215


## Introducción: 

La siguiente tarea consiste en realizar un servidor web implementado en el lenguaje C, mediante la implementación de hilos "pre-thread" y procesos "pre-fork". Ademas el web server debe ser capaz de procesar consultas utilizando el protocolo de mensajes HTTP/1.1 el cual también debe ser implementado en el lenguaje C.

La siguiente tarea tienen la intención de comprender el funcionamiento de tanto hilos como procesos en el Sistema Operativo Linux.

## Ambiente de desarrollo: 

Para realizar esta tarea se utilizaron varios lenguajes de programación, tales como, C y Python.
En C se implementaron las dos maneras del webServer "pre-fork" y "pre-thread", un cliente HTTP para realizar consultas al servidor y la implementación del protocolo HTTP. Y en Python se implementó un programa para medir el server en características de estrés, además de otro cliente para realizar consultas HTTP.
Además de los lenguajes, se utilizaron algunas bibliotecas como en el caso de C la PTHREAD, para hacer uso de los hilos en modo kernel implementados. Por otro lado, en Python, se utilizó Threading y subprocess para realizar el cliente de estrés, ademas de utilizar pyCurl para implementar el cliente HTTP.

## Estructuras de datos usadas y funciones: 

Para realizar esta tarea, se utilizaron algunas estructuras, como un arreglo de hilos para recibir clientes.
Entre las funciones utilizadas, las más importantes son: la que se utiliza para crear el socket del server, la que se encarga de realizar el binding al puerto específico y la que hace que el socket comience a escuchar a sus clientes.
Además de estos, se tiene un módulo del cuál se encarga de discriminar el puerto y asignar el protocolo de respuesta correcto.
En el módulo implementado para la prueba de estrés, se programó una función la cuál consiste en ejecutar el binario especificado.

## Instrucciones para ejecutar el programa: 

Para ejecutar alguno de los servers se debe ejecutar

```sh
$ ./prethread-webserver -p [puerto] -n [cantidad de hilos] -w [path raíz del recurso] 
//en el caso de los hilos

$ ./preforked-webserver -p [puerto] -n [cantidad de hilos] -w [path raíz del recurso] 
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

### José Paulo Yock:

#### Viernes 1 de Setiembre (3:00pm - 9:00pm):
* Investigar sobre el protocolo HTTP
* Se establece el flujo que seguirá el protocolo

#### Sábado 2 de Setiembre (8:00pm - 9:00pm):
* Se definen los métodos a utilizar

#### Domingo 3 de Setiembre (12:00pm - 4:00pm):
* Se comienza a comprender el uso de los hilos ya implementados
* Se comprende la forma de los mensajes en el protocolo HTTP

#### Lunes 4 de Setiembre (6:00pm - 9:45pm):
* Se modifica el flujo del WebServer
* Se implementa el parser del mensaje request

#### Viernes 8 de Setiembre (3:00pm - 9:00pm):
* Se completa el método GET
* Se deja el método POST a medias

#### Sábado 11 de Setiembre (6:00pm - 11:00pm):
* Se presentan problemas con el parser el cual no logra obtener bien el body de un mensaje sin headers
* Se arregla el error del parser
* Se pasan parámetros al ejecutable utilizando método POST
* Se retorna la respuesta del método POST

#### Domingo 12 de Setiembre (11:00am - 3:00pm):
* Se completa el cliente HTTP en python3 utilizando pyCurl


## Comentarios finales (estado del programa):

Los servidores funcionan en su totalidad, se parsea correctamente el mensaje HTTP y se responde correctamente el recurso a los clientes. Ademas el servidor es capas de ejecutar un programa si es utilizado el método POST y de retornar lo que este programa imprima por el estandar output.
Ambos clientes implementados también funcionan correctamente.
El programa encargado de estresar el servidor funciona correctamente.

## Conclusiones:

El protocolo HTTP sigue una serie de reglas muy simples, lo cual lo hace facil de comprender y aplicar.


## Bibliografía:

* List of HTTP status codes. (2017, September 9). In Wikipedia, The Free Encyclopedia. Retrieved 8 September 2017
, from https://en.wikipedia.org/w/index.php?title=List_of_HTTP_status_codes
&oldid=799671481

* HTTP Messages. (2017). Mozilla Developer Network. Retrieved 3 September 2017, from https://developer.mozilla.org/es/docs/Web/HTTP/Messages