# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
A. Singly Linked List
Singly linked list adalah struktur data yang digunakan untuk menyimpan kumpulan data yang saling terhubung satu sama lain. Setiap data/node memiliki alamat yang mengarah ke data/node berikutnya. Struktur data ini bersifat dinamis, sehingga data dapat ditambah atau dihapus sesuai kebutuhan [1].

Dalam singly linked list, setiap node hanya memiliki satu pointer untuk menunjukkan alamat node selanjutnya. Pointer First digunakan untuk menunjukkan node pertama, sedangkan node terakhir akan menunjuk ke Nil yang menandakan bahwa tidak ada node berikutnya.

#### 1. Node (ElmList)
satu node berisi info untuk data dan next untuk alamat node sesudahnya.
#### 2. Pointer First dan Nil
First menunjuk node pertama. Saat First bernilai Nil, list kosong.

### B. Pointer, Alokasi Memori Dinamis, dan ADT<br/>
Pointer adalah variabel yang digunakan untuk menyimpan alamat memori dari variabel lain [2]. Dalam C++, new digunakan untuk membuat ruang memori baru saat program berjalan, sedangkan delete digunakan untuk menghapus ruang memori yang sudah tidak diperlukan [2]. Pada linked list, keduanya digunakan untuk membuat dan menghapus node.

ADT (Abstract Data Type) adalah konsep yang menggabungkan jenis data dengan operasi yang bisa dilakukan pada data tersebut. Pada modul ini, ADT terdiri dari infotype, address, ElmList, dan List, serta beberapa fungsi dan prosedur untuk mengatur data dalam linked list.
#### 1. Alokasi dan dealokasi
alokasi digunakan untuk membuat node baru dengan new, mengisi data pada bagian info, dan mengatur next agar menunjuk ke Nil. Sementara itu, dealokasi digunakan untuk menghapus node yang sudah tidak dibutuhkan menggunakan delete.

#### 2. Penyisipan.
insertFirst digunakan untuk menambahkan node baru di awal list. Caranya dengan menghubungkan node baru ke node pertama yang lama, kemudian menjadikan node baru sebagai First.

#### 3.Penghapusan.
deleteFirst digunakan untuk menghapus node pertama, deleteLast untuk menghapus node terakhir, dan deleteAfter untuk menghapus node yang berada setelah node yang ditunjuk oleh Prec.

## Guided 

### 1. list.h

```C++

#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; // mendefinisikan alias address sebagai pointer ke struct node

struct node { // node untuk isi dari linked list
    dataMahasiswa isidata;
    address next;
};

struct linkedList { // ini linked listnya
    address first;
};

// semua function & procedure yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void delList(linkedList &list);

#endif
```
File list.h berfungsi untuk mendeklarasikan struktur data mahasiswa, node, dan linked list, serta fungsi dan prosedur yang digunakan untuk mengelola data mahasiswa, seperti menambah, menampilkan, menghitung, dan menghapus data.

### 2. list.cpp

```C++

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
```
File list.cpp berisi proses dari fungsi dan prosedur untuk mengelola data mahasiswa menggunakan singly linked list. Kode ini digunakan untuk membuat list, menambahkan data di awal, tengah, atau akhir, menampilkan data, menghitung jumlah node, serta menghapus satu atau seluruh data mahasiswa.

### 3. main.cpp

```C++

#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211100014", 21);
    nodeC = alokasi("Rizal", "2311100029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);

    // Hapus node setelah nodeC, yaitu nodeD
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    delList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;

    return 0;
}
```
File main.cpp digunakan untuk menjalankan program linked list yang berisi data mahasiswa. Pada kode ini, data mahasiswa ditambahkan ke dalam list menggunakan insertFirst, insertLast, dan insertAfter. Setelah itu, program menampilkan data dan menghitung jumlah node, lalu melakukan penghapusan data menggunakan delFirst, delLast, dan delAfter. Terakhir, seluruh data dihapus menggunakan delList untuk memastikan list kembali kosong.

## Unguided 

### 1. (Buatlah ADT Singly Linked list di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”. Kemudian buat program utama didalam file “main.cpp”.)

```Singlylist.h
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

```Singlylist.cpp
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```

```main.cpp
#include "Singlylist.h"
#include "Singlylist.cpp"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertFirst(L, P2);
    P3 = alokasi(8);  insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![soal1](https://github.com/daffaarief55-glitch/109082500192_Daffa-Arief-Wicaksono4/blob/main/modul4/outputu_ungided/soal1.png?raw=true)

File SinglyList.h berisi deklarasi struktur data dan fungsi, SinglyList.cpp berisi proses dari setiap fungsi, sedangkan main.cpp digunakan untuk menjalankan program dengan memasukkan dan menampilkan data. Data dimasukkan ke bagian awal list, sehingga urutan angka yang ditampilkan menjadi terbalik dari urutan saat dimasukkan.

### 2. (isi dengan soal unguided 2)

```Singlylist2.h
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```


```Singlylist2.cpp
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First->next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

int nbList(List L) {
    int n = 0;
    address P = L.First;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}
```

```main3.cpp
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
```

### Output Unguided 2 :

##### Output 
![soal2.png](https://github.com/daffaarief55-glitch/109082500192_Daffa-Arief-Wicaksono4/blob/main/modul4/outputu_ungided/soal2.png?raw=true)

Ketiga file tersebut untuk menjalankan program singly linked list. File .h digunakan untuk mendefinisikan struktur data dan fungsi yang dibutuhkan, file .cpp berisi kode untuk menjalankan fungsi-fungsi tersebut, sedangkan main.cpp digunakan untuk menjalankan program. Program ini dapat menambahkan dan menghapus data, menampilkan isi list, menghitung jumlah node, serta menghapus semua data hingga list menjadi kosong.





## Kesimpulan
1. Singly linked list merupakan struktur data yang setiap node-nya saling terhubung menggunakan pointer next, sedangkan First digunakan untuk menunjuk node pertama.
2. insertFirst berfungsi untuk menambahkan node di bagian awal list, sehingga urutan data yang ditampilkan menjadi terbalik dari urutan saat dimasukkan.
3. deleteFirst, deleteLast, dan deleteAfter digunakan untuk menghapus node berdasarkan posisinya, sedangkan dealokasi berfungsi untuk membebaskan memori node yang sudah dihapus.
4. nbList digunakan untuk menghitung jumlah node dalam list, sedangkan deleteList berfungsi untuk menghapus semua node hingga list menjadi kosong.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
