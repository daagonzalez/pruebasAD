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

}

CnjOrdInt::~CnjOrdInt() {

}

bool CnjOrdInt::insertarOrd(int x) {

}

bool CnjOrdInt::eliminar(int x) {

}

bool CnjOrdInt::buscar(int x) const {

}

CnjOrdInt& CnjOrdInt::operator+(const CnjOrdInt& b) const {
}

CnjOrdInt& CnjOrdInt::operator*(const CnjOrdInt& b) const {
  CnjOrdInt* cnj_nvo_ptr = new CnjOrdEnt();
  NodInt* p, q, ultimo;
  p = inicio;
  q = b.inicio;
  ultimo = 0;

  // algoritmo de matching
  while ((p != 0) && (q != 0)) {
      if (p->dato < q->dato) {
          p = p->sgt;
      } else if (q->dato < p->dato) {
          q = q->sgt;
      } else {
          if (ultimo == 0) {
              cnj_nvo_ptr->inicio = new NodInt(p->dato);
              ultimo = cnj_nvo_ptr->inicio;
          } else {
              ultimo->sgt = new NodInt(p->dato);
              ultimo = ultimo->sgt;
          }
          p = p->sgt;
          q = q->sgt;
      }
  }
  return *cnj_nvo_ptr;
}

CnjOrdInt& CnjOrdInt::operator-(const CnjOrdInt& b) const {
}

CnjOrdInt& CnjOrdInt::operator/(const CnjOrdInt& b) const {
}

string CnjOrdInt::aHil() {

}
