#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
        L.first=NULL;
        L.last=NULL;

    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    //-------------your code here-------------
    P = new elmlist;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;

    //----------------------------------------
    return P;
}

void dealokasi(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    P = NULL;
    delete P;

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
	if (First(L) == NULL && Last(L) == NULL)
    {
        First(L) = P;
        Last(L) = P;
        Next(P) = P;
        Prev(P) = P;
    }
    else
    {
        Next(P) = L.first;
        Prev(P) = L.last;
        L.last->next = L.first;
        Next(Last(L)) = P;
        L.first = P;
        if (First(L)->next == Last(L))
        {
            Prev(Last(L)) = P;
        }
        L.first = P;
        L.last->next = L.first;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (First(L) == NULL && Last(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        Prev(P) = Prev(Last(L));
        Next(Prev(Last(L))) = P;
        L.last = P;
        Next(P) = First(L);
        Prev(L.first) = L.last;

    }

    //----------------------------------------
}

address findElm(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P;
    //-------------your code here-------------
    if (L.first != NULL)
    {
        P=L.first;
        while(Next(P) != L.first && Info(P).ID != x.ID)
            P = Next(P);

        if(P->info.ID == x.ID)
            return P;
        else
            return NULL;
    }
    else
    {
        return NULL;
    }

    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(L.first->next != L.last && L.first != NULL)
    {
        P = L.first;
        L.first = Next(P);
        L.first->prev = L.last;
        Next(L.last) = L.first;
        P->next = NULL;
        P->prev = NULL;
    }
    else
    {
        cout << "KOSONG";
        P = L.first;
        P->next = NULL;
        P->prev = NULL;
        L.first = NULL;
        L.last = NULL;
    }


    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    address Q;
    if (L.last == L.first)
    {
        deleteFirst(L,P);
    }
    else
    {
        P = L.last;
        Q = P->prev;
        Q->next = L.first;
        Last(L) = Q;
        Prev(First(L)) = Q;
    }


    //----------------------------------------
}

void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if (Prec == L.last)
       {insertLast(L,P);
       }
    else if (Prec == L.first)
        {insertFirst(L,P);}
    else
    {
        if (Prec->next == L.last)
            insertLast(L,P);
        else
        {

            Prec->next->prev = P;
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next = P;
            P->next = NULL;
            P->prev = NULL;
        }
    }

    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
 if (Prec != NULL)
    {
        P = Next(Prec);
        if (P == L.last)
        {
            deleteLast(L,P);
            cout << "KOSONG";
        }
        else if (P == L.first)
            deleteFirst(L,P);

    }
    else
    {
        cout << "KOSONG";
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
    }

    //----------------------------------------
}

