# TUGAS 1 IMPLEMENTASI DES dengan message padding CTR

## *KIJ F Kelompok 8:*
- 51141000076 M. Faishal Ilham 
- *5114100092 Kharisma Monika D.P.*

## PENDAHULUAN
DES (Data Encryption Standard) algoritma adalah algoritma enkripsi yang paling banyak digunakan di dunia. DES bekerja pada bit, atau angka biner - 0 dan 1 untuk komputer digital. Setiap kelompok empat bit membuat sebuah heksadesimal, atau basis 16, nomor. Biner "0001" adalah sama dengan jumlah heksadesimal "1", biner "1000" adalah sama dengan jumlah heksadesimal "8", "1001" adalah sama dengan jumlah heksadesimal "9", "1010" adalah sama dengan jumlah heksadesimal "A", dan "1111" adalah sama dengan jumlah heksadesimal "F".
DES bekerja dengan mengenkripsi kelompok 64 bit pesan, yang sama dengan 16 angka heksadesimal. Untuk melakukan enkripsi, DES menggunakan "kunci" di mana juga ternyata panjangnya 16 angka heksadesimal. Namun, setiap bit kunci 8 diabaikan dalam algoritma DES, sehingga ukuran kunci yang efektif adalah 56 bit. 
Sebagai contoh, jika kita mengambil pesan plaintext "8787878787878787", dan mengenkripsi dengan kunci DES "0E329232EA6D0D73", hasilnya adalah ciphertext "0000000000000000". Jika ciphertext tersebut didekripsi dengan rahasia DES kunci "0E329232EA6D0D73" yang sama, hasilnya adalah plaintext asli "8787878787878787"
 
## LANGKAH - LANGKAH
- Mengubah plaintext dan key menjadi bentuk biner
- Lakukan Initial Permutation (IP) pada bit plaintext menggunakan tabel IP (Initial Permutation)
- Generate kunci yang akan digunakanuntuk mengenkripsi plaintext dengan menggunakan tabel permutasi kompresi PC-1.
  pada langkah ini terjadi kompresi dengan membuang 1 bit masing-masing blok kunci dari 64 bit menjadi 56 bit.
- Lakukan pergeseran kiri (Left Shift) pada C0 dan D0, sebanyak 1 atau 2 kali berdasarkan kali putaran yang ada pada tabel putaran
- Setiap hasil putaran digabungkan kembali menjadi CiDi dan diinput kedalam tabel Permutation Compression 2 (PC-2) dan terjadi kompresi data CiDi 56 bit menjadi CiDi 48 bit.
- meng-ekspansi data Ri-1 32 bit menjadi Ri 48 bit sebanyak 16 kali putaran dengan nilai perputaran 1<= i <=16 menggunakan Tabel Ekspansi (E).
- Hasil E(Ri-1) kemudian di XOR dengan Ki dan menghasilkan Vektor Matriks Ai.
- A1 akan dimasukan ke dalam S-Box dan menghasilkan output B1
- B1 kemudian akan dipermutasikan lagi dengan tabel P-Box dan menghasilkan nilai PB1 yang kemudian di XOR-kan dengan L0 dan menghasilkan nilai R1. Nilai R1 ini digunakan untuk melanjutkan iterasi ke-2
- memutasikan bit vektor Bi menggunakan tabel P-Box, kemudian dikelompokkan menjadi 4 blok dimana tiap-tiap blok memiliki 32 bit data.
- Hasil P(Bi) kemudian di XOR kan dengan Li-1 untuk mendapatkan nilai Ri.
  Sedangkan nilai Li sendiri diperoleh dari Nilai Ri-1 untuk nilai 1 <= i <= 16.
- menggabungkan R16 dengan L16 kemudian dipermutasikan untuk terakhir kali dengan tabel Invers Initial Permutasi(IP-1).

## Referensi yang dipakai :
- http://octarapribadi.blogspot.co.id/2012/10/contoh-enkripsi-dengan-algoritma-des.html
- http://dhost.info/pasjagor/des/start.php?id=i1

