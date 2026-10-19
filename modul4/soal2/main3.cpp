#include "Singlylist2.h"

int main() {
    List L;
    address P, Prec;
    createList(L);

    
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    deleteFirst(L, P);      
    dealokasi(P);

    deleteLast(L, P);       
    dealokasi(P);

    Prec = L.First;         
    deleteAfter(Prec, P);   
    dealokasi(P);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    cout << endl;
    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    return 0;
}
