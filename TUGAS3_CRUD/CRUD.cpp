#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

struct data_mhs {
  int no;
  string nama;
  string nim;
  string tgl_lhr;
  string matkul;
};

int jlh_mhs = 0;
struct data_mhs mahasiswa[125];


void create();
void read();
void update();
void remove();

int main() {
  while (true) {
  	printf("\n===============================");
    printf("\n  Program CRUD Data Mahasiswa  ");
    printf("\n===============================\n");
    printf("1. Tambah data mahasiswa\n");
    printf("2. Tampilkan data mahasiswa\n");
    printf("3. Update data mahasiswa\n");
    printf("4. Hapus data mahasiswa\n");
    printf("5. Keluar\n");
    printf("===============================\n");

    int pil;
    printf("Pilihan [1-6]: ");
    scanf("%d", &pil);
    printf("\n");
    switch (pil) {
      case 1:
	    create();
        break;
      case 2:
        read();
        break;
      case 3:
        update();
        break;
      case 4:
        remove();
        break;
      default:
        return 0;
    }
  }
}


void new_data(int no) {
  printf("\n===============================\n");
  printf("       Isi Data Mahasiswa     ");
  printf("\n===============================\n");
  fflush(stdin);
  printf("Nama              : ");
  getline(cin, mahasiswa[no].nama);
  
  printf("NIM               : ");
  getline(cin, mahasiswa[no].nim);
  
  printf("Tanggal Lahir     : ");
  getline(cin, mahasiswa[no].tgl_lhr);

  printf("Mata Kuliah       : ");
  getline(cin, mahasiswa[no].matkul);
  
  printf("===============================\n");
}

void create() {
  new_data(jlh_mhs);
  mahasiswa[jlh_mhs].no = jlh_mhs + 1;
  jlh_mhs++;
}

void read() {
  printf("\n===============================\n");
  printf("         Data Mahasiswa        ");
  printf("\n===============================\n");
  puts("+-------------------------------------------------------+");
  puts("| No  | Nama\t| NIM\t| Tgl Lahir\t| Mata Kuliah\t|");
  puts("+-------------------------------------------------------+");

  for (int i = 0; i < jlh_mhs; i++) {
    if(!mahasiswa[i].no)
      continue;
    printf("| %d   | %s\t| %s\t| %s\t| %s\t\t|\n", mahasiswa[i].no, mahasiswa[i].nama.c_str(), mahasiswa[i].nim.c_str(), mahasiswa[i].tgl_lhr.c_str(), mahasiswa[i].matkul.c_str());
  }
  puts("+-------------------------------------------------------+\n");
}

void update() {
  printf("\n===============================\n");
  printf("     Perbarui Data Mahasiswa     ");
  printf("\n===============================\n");
  int no;
  printf("Nomor mahasiswa: ");
  cin >> no;
  new_data(no - 1);
}

void remove() {
  printf("\n===============================\n");
  printf("      Hapus Data Mahasiswa     ");
  printf("\n===============================\n");
  int no;
  printf("Nomor mahasiswa: ");
  cin >> no;
  no--;
  mahasiswa[no].no = 0;
  mahasiswa[no].nama = "";
  mahasiswa[no].nim = "";
  mahasiswa[no].tgl_lhr = "";
  mahasiswa[no].matkul = "";
  printf("\n===============================\n");
}
