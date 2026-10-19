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

### 1. ...

```C++
source code guided 1
```
penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
