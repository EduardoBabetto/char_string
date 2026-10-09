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