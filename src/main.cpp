/*
PROJETO: CHAR STRING
DESCRICAO: MEXENDO COM AS VARIAVEIS DO STRING E CHAR
AUTOR: EDUARDO DOS SANTOS BABETTO
DATA: 09/10/2026
VERSAO: 0.1
*/

#include <Arduino.h>
#include <string.h> //* strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> //*atoi

void textChar();
void textoString();

void setup() {
  Serial.begin(9600);
  Serial.println();
  textChar();
  textoString();
}

void loop() {
  
}

void textChar(){
  //*texto literal
  //* Use const char* quando o texto nao sera alterado
  const char cidade[] = "Sao Paulo";
  Serial.println(cidade);

  //*Descobrindo o tamanho o texto
  //*strlen conta quantos caracteres antes do '\0'
  int tamanhoTextoCidade = strlen(cidade);
  Serial.println(tamanhoTextoCidade);

  //* Descobrindo o tamanho ocupado
  //* o sizeof() retornara um byte a mais que o comprimento por causa do '\0'
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoVariavelCidade);

  //* o caractere \0 e colocado automaticamente quando escrveres
  //* um texto entre " ".
  char vetorTexto[] = {'T','H','i','a','g','o','\0'};
  Serial.println(vetorTexto);

  //*Comparar texto
  const char* cidade1 = "Sao Caetano";
  const char* cidade2 = "Sao Caetano";

  if(strcmp(cidade1, cidade2)==0){
    Serial.println("Os textos  sao iguais");
  }
  else {
    Serial.println("Os textos sao diferentes");
  }

  //* strcmp analiza a ordem lexica das palavras, se a primeira palavra vem antes
  //* que a segunda o valor retornado sera menor que zero, se a primeira vem apos
  //* a segunda o retorno sera maior que zero

  //!=======================
  //!Texto editavel com char[]
  //!=======================

  char nomeAluno[20] = "Thiagp";
  Serial.println(nomeAluno);
  
  //* Alterando caracteres indiviualmente
  nomeAluno[5] = 'o';
  Serial.println(nomeAluno);

  //* Copiando outro texto para dentro do vetor
  //! Cuidado: o vetor precisa ter espaco suficiente

  strcpy(nomeAluno,"Felipe");
  Serial.println(nomeAluno);

  //* Concatenando de texto ao final
  char frase[40] = "Ola ";
  strcat(frase, "Mundo!");
  Serial.println(frase);

  //* Procurando um caractere no texto
  //* Frase "Ola Mundo!"
  char* posicaoLetra = strchr(frase,'M');

  if(posicaoLetra != NULL){
    Serial.print("Letra encontrada: ");
    Serial.println(posicaoLetra);
  }
  else{
    Serial.println("Letra nao encontrada");
  }

  //* Convertendo texto numerico para inteiro
  char idadeTexto[] = "45"; // 52,52, \0
  int idade = atoi(idadeTexto);
  Serial.println(idade);

  //* Montando texto
  char buffer[20];
  char* local ="Sala de aula";
  float temperatura = 26.4;
  int umidade = 58;
  //* \n mudanca de linha
  //* \r retorno ao comeco da linha
  //*snprintf monta o texto dentro de um vetor de char
  //! Sala de aula | Temp.: | Umid.: 58%
  snprintf(buffer,sizeof(buffer),"%s | Temp: %.1f | Umid: %d %% \n\r", local, temperatura, umidade); 

  Serial.print(buffer);
  Serial.printf("O tamanho do buffer eh %lu \n\r", sizeof(buffer));
  //* snprintf monta um texto dentro de um vetor de char
  //* Sintaxe: snprintf(variavelOndeSeraMontadoOTexto, tamanhoMaximoDoTexto, TextoComFormatacao, ItensDeFormado)
  //* Isso eh muito util quando depois voce quer:
  //* -salvar o texto em uma variavel
  //* -mandar para um display
  //* -Imprimir na serial
  //* -Enviar por MQTT (IoT)
  //*
  //* ESPECIFICADORES
  //* 
  //* %d ou %i -int
  //* %u -unsigned int
  //* %ld -long
  //* %lu -unsigned long
  //* %f -float
  //* %e -notacao cientifica
  //* %g -float, formato mais curto
  //* %c -char
  //* %s -char* (string)
  //* %x ou %X -Hexadecimal minusculo/maisculo
  //* %o -octal
  //* %p -ponteiro
  //* %% -o proprio %
  //*
  //*
  //* Flag, largura, e precisao
  //* %5d -imprime com largura minima de 5 alinhado a direita [    3] [  100] [100000]
  //* %-4d -imprime com largura minima de 4, alinhando a esquerda [3   ] [100 ] [1234567]
  //* %03d -completa com zeros a esquerda, [003]
  //* %+d -sempre mostra o sinal [+3] [-3]
  //* %.2f -2 casas decimais num float 
  //* %4.2f -largura minima 4 a direita com 2 casas decimais
  //* %02X -hexadecimal com 2 digitos [0F] [3A] 
  //* %#x -imprime o prefixo 0x [0x2a] [0xF]
  //* %.3s -somente os 3 primeiros caracteres da String
  //* %*d -largura passada como argumento ex: snprintf(buffer, sizeof(buffer), "numero %*d", largura, numero)
  //* Serial.print(buffer) -> [  9]

}

void textoString(){
  //* ============================================
  //* USANDO String
  //* ============================================
  
  String nome = "Thiago";
  String curso = "Logica de programacao";
  String mensagem = "Ola";

  //* Concatenando String
  mensagem = mensagem + "," + "! Bem-Vindo ao curso de " + curso + ".";

  Serial.println(mensagem);

//* Tamanho da String
int tamanhoMensagem = mensagem.length();
Serial.print("Tamanho da String em letras: ");
Serial.println(tamanhoMensagem);

//* Acessando um caractere em uma posicao especifica 
char primeiraLetra = mensagem.charAt(0);
Serial.print("Primeira letra: ");
Serial.println(primeiraLetra);

//*Tambem e possivel acessar em colchetes
char segundaLetra = mensagem[1];
Serial.println(segundaLetra);


//* Procurando um texto dentro da string
int posicaoTextoProcurado = mensagem.indexOf("curso");
Serial.println(posicaoTextoProcurado);


//* Extraindo um texto dentro da String
int inicioNomeCurso = posicaoTextoProcurado + 9; //* posicao da palavra curso +9 caracteres
Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem-1)); //* -1 tira o ponto final

//* Substituindo um texto dentro da String
mensagem.replace("Ola,",("Oi, tudo bem? "));
Serial.println(mensagem);

//* Convertendo para maiusculas
mensagem.toUpperCase();
Serial.println(mensagem);

//* Convertendo tudo para minusculas
mensagem.toLowerCase();
Serial.println(mensagem);

//* Convertendo texto numerico para inteiro
String textoNumero ="123";
int numero = textoNumero.toInt();
Serial.println(numero * 2);

//* Verificando se a String esta vazia
String textoVazio = "";
if(textoVazio.length() == 0) Serial.println("O texto esta vazio");

//* Convertendo String para const char*
//* e util quando alguma biblioteca espera texto estilo C
const char* textoComoChar = mensagem.c_str();
Serial.println(textoComoChar);



}