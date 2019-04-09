# ISLR System (C++)

---

<p align="center"><b>Sistema de Calculo sobre el Impuesto Sobre la Renta (ISLR)</b><br>Software desarrollado en lenguaje C++, con el IDE DEV C++.</p>

---

## ***Introducción***

Programa que determine un monto aproximado a pagar de Impuesto sobre la Renta (ISLR) en base a la unida tributaria (UT) del país.

## ***Instrucciones***
1. Descarga el repositorio, en el encontaras el archivo ***ISLRSystem***.
2. Ejecuta tu IDE deseado, se sugiere [Dev C++](https://sourceforge.net/projects/orwelldevcpp/).
3. Abre el archivo ***ISLRSystem*** anteriormente mencionado con el IDE.
4. Compila y corre el programa.
5. Sigue las instrucciones indicadas en el programa para la correcta operación del mismo.

## ***Especificaciones***
Una empresa requiere, un programa que determine un monto aproximado a pagar de Impuesto sobre la Renta (ISLR) en base a la unida tributaria (UT) del país. Una Unidad Tributaria a la fecha es de ***Bs. 300***, y se sabe que toda persona natural que gane menos de ***32.000 unidades tributarias*** no pagará impuesto. Adicionalmente, en caso de tener que pagar impuesto, el fisco reconoce las cargas familiares, es decir se rebajará por cada carga familiar ***500 unidades tributarias***, siendo considerado la persona natural como una de esas cargas.

El cálculo del impuesto será en base a los siguientes criterios:

<p align="center"><img src="https://i.ibb.co/BfkbwzQ/table.png"></p>

Nota: Luego de determinar el porcentaje a ser aplicado, se deberá hacer el descuento indicado de UT, para luego si establecer el monto definitivo de impuesto a pagar.

Conociendo para cada persona natural, su cédula de identidad, remuneración total al año y las cargas familiares adicionales a él, se requiere un programa en C que emita los siguientes reportes:

* Para cada Persona Natural , un reporte resumen que contenga:

  * Cédula de Identidad del Contribuyente.
  * Total de Remuneraciones al año.
  * Número de cargas Familiares incluyendo al contribuyente.
  * Tasa de Impuesto a Pagar.
  * Monto a Pagar de ISLR.
  
* Al final del Día.

  * Cantidad de contribuyentes que no pagaron impuesto.
  * Cantidad de contribuyentes que pagaron impuesto por cada tasa.
  * El Monto Total de Remuneraciones de los Contribuyentes.
  * El monto Total de los Descuentos Otorgados de UT.
  * La Cédula y el Monto del contribuyente que pagó más impuesto.
  * La Cédula y el Monto del contribuyente que pagó menos impuesto.
  * El Monto Total de ISLR.
  * El Promedio de Pago de todos los contribuyentes que pagaron ISLR.
  
 El programa deberá efectuar todas las validaciones requeridas, desplegar mensajes de error, hacer uso de programación estructurada, utilizando funciones void y no void, así como pase de parámetros por valor y por referencia.
 
 ## ***Views***
 
 ### *Inicio*
<p align="center"><img src="https://i.ibb.co/PQJHkjn/Imagen1.png"></p>
 
 ### *Cálculo*
 <p align="center"><img src="https://i.ibb.co/PDKFzcn/Imagen2.png"></p>
 
 ### *Fin del Dia*
 <p align="center"><img src="https://i.ibb.co/Pj2gcmx/Imagen3.png"></p>
 
## ***Creditos***

Proyecto realizado por
* [Marcos De Andrade](https://github.com/MarcosDeAndrade)

## ***Licencia***

[MIT](https://github.com/MarcosDeAndrade/PacMan/blob/master/LICENSE)

&nbsp;

<p align="center">✌️</p>
<p align="center">
<sub><sup>A project by <a href="https://github.com/MarcosDeAndrade">Marcos De Andrade</a><br>Copyright (c) 2018</sup></sub></p>

 
