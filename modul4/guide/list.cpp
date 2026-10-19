
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList list) {
    if (list.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedList &list) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    list.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */

    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;

    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */

    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &list, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */

    nodeBaru->next = list.first;
    list.first = nodeBaru;
}


void insertAfter(linkedList &list, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */

    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &list, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */

    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        address nodeBantu = list.first;

        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada di dalam list
void delFirst(linkedList &list) {
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus */

    address nodeHapus;

    if (isEmpty(list) == false) {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
};

void delLast(linkedList &list) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */

    address nodeHapus, nodePrev;

    if (isEmpty(list) == false) {
        nodeHapus = list.first;

        if (nodeHapus->next == Nil) {
            list.first->next = Nil;
            dealokasi(nodeHapus);
            list.first = Nil;
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }

            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong!" << endl;
    }
}




void delAfter(linkedList &list, address nodeHapus, address nodePrev) {
    /* I.S. list tidak kosong, alamat nodePrev adalah salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */

    if (isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedList list) {
    /* I.S. mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

    if (isEmpty(list)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = list.first;

        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;

            nodeBantu = nodeBantu->next;
        }
    }
}


// prosedur untuk menampilkan isi list


// function untuk menampilkan jumlah node di dalam list
int nbList(linkedList list) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list */

    int count = 0;
    address nodeBantu = list.first;

    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }

    return count;
}

// prosedur untuk menghapus list (menghapus semua node di dalam list)
void delList(linkedList &list) {
    /* I.S. list sudah ada
       F.S. menghapus semua node di dalam list */

    address nodeBantu, nodeHapus;
    nodeBantu = list.first;

    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }

    list.first = Nil;
    cout << "List sudah terhapus!" << endl;
}



