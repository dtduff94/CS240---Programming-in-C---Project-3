/*
 * functions that convert between int, quaternary, and vigesimal numbers
 * 
 * project: hw3
 * name: Daniel Duff 
 * date: 06/24/19
 * file: itox.c
 * notes:
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "itox.h"

/* function converts int n to a quaternary string in the
   hexstring array */
void itoq(char quaternaryStr[], int n) {
  char qdigits[4] = {'0', '1', '2', '3'};

  const int size1 = sizeof(int) * 4 + 1;
  int qspot = size1 - 1;
  
  while (qspot >= 0) {
    quaternaryStr[qspot] = qdigits[n % 4];
    n /= 4;
    qspot -= 1;
  }
  quaternaryStr[size1] = '\0';
}

/* function converts a quaternary string to its int value  */
int qtoi(char quaternaryStr[]) {
  int n = 0;
  int power = 0;
  int len = strlen(quaternaryStr) - 1;
  
  while (len >= 0) {
    n = n + (quaternaryStr[len] - '0') * pow(4, power);
    len -= 1;
    power += 1;
  }
  return n;
}

/* function converts int n to a vigesimal string in the
   hexstring array */
void itov(char vigesimalStr[], int n) {
  char vdigits[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  
  const int size2 = sizeof(int) * 2 + 1;
  int vspot = size2 - 1;

  while (vspot >= 0) {
    vigesimalStr[vspot] = vdigits[n % 20];
    n /= 20;
    vspot -= 1;
  }
  vigesimalStr[size2] = '\0';
}

/* function converts a vigesimal string to its int value  */
int vtoi(char vigesimalStr[]) {
  int n = 0;
  int power = 0;
  int len = strlen(vigesimalStr) - 1;

  while (len > 0) {
    if (vigesimalStr[len] == 'A') {
      vigesimalStr[len] = '10';
    }
    if (vigesimalStr[len] == 'B') {
      vigesimalStr[len] = '11';
    }
    if (vigesimalStr[len] == 'C') {
      vigesimalStr[len] = '12';
    }
    if (vigesimalStr[len] == 'D') {
      vigesimalStr[len] = '13';
    }
    if (vigesimalStr[len] == 'E') {
      vigesimalStr[len] = '14';
    }
    if (vigesimalStr[len] == 'F') {
      vigesimalStr[len] = '15';
    }
    if (vigesimalStr[len] == 'G') {
      vigesimalStr[len] = '16';
    }
    if (vigesimalStr[len] == 'H') {
      vigesimalStr[len] = '17';
    }
    if (vigesimalStr[len] == 'I') {
      vigesimalStr[len] = '18';
    }
    if (vigesimalStr[len] == 'J') {
      vigesimalStr[len] = '19';
    }
    n = n + (vigesimalStr[len] - '0') * pow(20, power);
    len -= 1;
    power += 1;
  }
  return n;
}
