/*
 * File:   CnjOrdInt.cpp
 * Author: alan.calderon
 *
 * Created on 5 de agosto de 2015, 05:37 PM
 */

#include "CnjOrdInt.h"

CnjOrdInt::CnjOrdInt():inicio(0) {
}

CnjOrdInt::CnjOrdInt(const CnjOrdInt& orig) {
  NdoInt* p = orig.inicio;
  if (p == 0)
      inicio = 0;
  else {
      inicio = new NdoInt(orig.inicio->dato);
      p = p->sgt;
      NdoInt* ultimo = inicio;
      while(p != 0){ // mientras no se acabe orig.
          ultimo->sgt = new NdoInt(p->dato);
          p = p->sgt;
          ultimo = ultimo->sgt;
      }
  }
}

CnjOrdInt::~CnjOrdInt() {
  NdoInt* p = inicio;
  NdoInt* q = 0;
  while (p != 0) {
      q = p->sgt;
      delete p;
      p = q;
  }
}

bool CnjOrdInt::insertarOrd(int x) {

}

bool CnjOrdInt::eliminar(int x) {
  bool rsl = false;
  NdoInt* p = inicio;
  NdoInt* ant = 0;
  if ( inicio != 0 && inicio->dato <= x )
      if ( inicio->dato == x ){
          p = inicio->sgt;
          delete inicio;
          inicio = p;
      } else {
          while(p != 0){ // hay que buscar a x
              if (p->dato == x){
                  rsl = true;
                  p = 0;
              } else { // hay que seguir buscando
                  if (p->dato < x){
                      ant = p;
                      p = p->sgt;
                  } else p = 0; // no está y no nada que eliminar
              }
          }
          if (rsl){ // sí hay que eliminar en medio o al final
              p = ant->sgt->sgt;
              delete ant->sgt;
              ant->sgt = p;
          }
      }
  return rsl;
}

bool CnjOrdInt::buscar(int x) const {
  bool rsl = false;
  NdoInt* p = inicio;
  while(p != 0){
      if (p->dato == x){ // ya se encontró x en *this
          rsl = true;
          p = 0;
      } else { // todavía no se encuentra pero puede que esté más adelante
          if (p->dato < x)
              p = p->sgt;
          else // se concluye que x no está en *this
              p = 0;
      }
  }
  return rsl;
}

CnjOrdInt& CnjOrdInt::operator+(const CnjOrdInt& b) const {
}

CnjOrdInt& CnjOrdInt::operator*(const CnjOrdInt& b) const {

}

CnjOrdInt& CnjOrdInt::operator-(const CnjOrdInt& b) const {
}

CnjOrdInt& CnjOrdInt::operator/(const CnjOrdInt& b) const {
}

string CnjOrdInt::aHil() {
  stringstream fs;
  NdoInt* p = inicio;

  while(p != nullptr){
    fs << p->dato << ',';
    p = p->sgt;
  }
  return fs.str();
}
