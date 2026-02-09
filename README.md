# Analizador Lexico en C usando Flex con GUI

Este proyecto consiste en el desarrollo de un analizador lexico basico utilizando Flex y el lenguaje C, junto a una interfaz grafica sencilla para facilitar las pruebas del analizador.

El objetivo principal del proyecto es comprender como funciona la etapa de analisis lexico dentro de un compilador, es decir, como un programa puede leer un texto y dividirlo en diferentes tokens como palabras clave, identificadores, numeros, operadores y delimitadores.

Para hacerlo mas practico y facil de probar, el analizador no se ejecuta solamente por consola, sino que se conecta a una interfaz grafica donde el usuario puede escribir codigo de prueba y observar como el analizador reconoce cada componente.

## Que hace el analizador

El analizador lexico es capaz de reconocer:
- Palabras reservadas como begin, end, var y print
- Identificadores
- Numeros
- Operadores
- Delimitadores

Cada uno de estos elementos es procesado segun las reglas definidas en el archivo lexer.l.

## Tecnologias utilizadas

- Lenguaje C
- Flex
- GTK 3 para la interfaz grafica
- MSYS2 como entorno de desarrollo en Windows

## Como se ejecuta el proyecto

Primero se genera el analizador lexico y se compila:

```bash
flex lexer.l
gcc lex.yy.c -o simplelex

Luego se compila la interfaz grafica:

```bash
gcc gui.c -o gui `pkg-config --cflags --libs gtk+-3.0`

Una vez ejecutada la aplicacion grafica, se puede introducir texto y analizarlo de forma visual

## Ejemplo de prueba

Codigo que puedes probar en el analizador:

begin
    var x = 5;
    print x;
end


## Nota final 
La interfaz GUI es sencilla y funcional ya que no se priorizo tanto la forma visual sino mas bien el funcionamiento del analizador lexico, cualquier cosa puede estar sujetas a cambios/mejoras.

## Repositorio GitHub

Todo el proyecto tambien se puede consultar en GitHub:

https://github.com/W1lderJz/Compiladores--2-21-0179--AnalizadorLexico-C-GUI
