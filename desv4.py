# -*- coding: utf-8 -*-
"""
Created on Fri Mar 31 04:45:32 2017

@author: Riris
"""

#======================================================================================
# Membuat Fungsi Untuk Mengubah Data Binary ke String
#======================================================================================
def binaryToString(b=None):
    return ''.join([chr(int(b[x:x+8], 2)) for x in range(0,len(b),8)])    

#======================================================================================
# Membuat Fungsi Untuk Mengubah Data String ke binary
#======================================================================================   
def stringToBinary(string):
    return  ''.join(format(ord(x), 'b').zfill(8) for x in string)

#======================================================================================
# Membuat Fungsi Untuk Mengubah Data Hexa ke binary -> ngga dipakai juga
#======================================================================================    
def hexToBinary():
    "{0:0b}".format(int('5f',16))
    return None 
#====================================================================================
# INT to Binary
#====================================================================================
def intToBinary(x):
    return '{0:08b}'.format(x)

#=====================================================================================
# Inisialisasi Tabel - Tabel Yang dibutuhkan Untuk DES
#=====================================================================================   
def inisialisasi():
    ip = [58,50,42,34,26,18,10,2,
        60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,
        64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,
        59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,
        63,55,47,39,31,23,15,7]
              
    pc1 = [57,49,41,33,25,17,9,
         1,58,50,42,34,26,18,
         10,2,59,51,43,35,27,
         19,11,3,60,52,44,36,
         63,55,47,39,31,23,15,
         7,62,54,46,38,30,22,
         14,6,61,53,45,37,29,
         21,13,5,28,20,12,4]
         
    pc2 = [14,17,11,24,1,5,
         3,28,15,6,21,10,
         23,19,12,4,26,8,
         16,7,27,20,13,2,
         41,52,31,37,47,55,
         30,40,51,45,33,48,
         44,49,39,56,34,53,
         46,42,50,36,29,32]
         
    expansion = [32,1,2,3,4,5,
       4,5,6,7,8,9,
       8,9,10,11,12,13,
       12,13,14,15,16,17,
       16,17,18,19,20,21,
       20,21,22,23,24,25,
       24,25,26,27,28,29,
       28,29,30,31,32,1]
       
    sboxes = { 
     0: [[14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
            [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
            [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
            [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 ]],
     1: [[15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
             [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
             [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
             [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 ]],
     2: [[10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
             [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
             [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
             [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 ]],
     3: [[7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
             [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
             [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
             [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 ]],
     4: [[2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
             [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
             [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
             [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 ]],
     5: [[ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
             [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
             [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
             [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 ]],
     6: [[4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
             [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
             [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
             [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]],
     7: [[13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
             [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
             [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
             [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]]
     }
     
    p_box = [ 16, 7, 20, 21,
      29, 12, 28, 17,
      1, 15, 23, 26,
      5, 18, 31, 10,
      2 , 8, 24, 14,
      32, 27, 3, 9,
      19, 13, 30, 6,
      22, 11, 4, 25 ]
      
    left_rotations = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]
    
    ip_inv = [40, 8, 48, 16, 56, 24, 64, 32,
          39, 7, 47, 15, 55, 23, 63, 31,
          38, 6, 46, 14, 54, 22, 62, 30,
          37, 5, 45, 13, 53, 21, 61, 29,
          36, 4, 44, 12, 52, 20, 60, 28,
          35, 3, 43, 11, 51, 19, 59, 27,
          34, 2, 42, 10, 50, 18, 58, 26,
          33, 1, 41, 9, 49, 17, 57, 25]
          
    return ip, pc1, pc2, expansion, sboxes, p_box, left_rotations, ip_inv
#=============================================================================
# Fungsi untuk Initial Permutation pada counter (plaintext) 
# karena input plaintext diganti dg counter
# data counter per blok , indek ke (IP-1) 
# dimasukkan ke temp , dr temp dibagi jadi 2, 0-x, x- selesai
#=============================================================================        
def IP(i):
    temp_L0_R0 = ''            
    for x in range(len(ip)):
        temp_L0_R0 += bin_data[i][ip[x]-1]
    return temp_L0_R0[:len(ip)/2], temp_L0_R0[len(ip)/2:]

#===========================================================================
# Permutation KEY
# generate key nya dimasukkan ke temp, 
# dipecah jadi 2,  C dan D
#===========================================================================    
def PC1():  
    temp_C_D = ''
    for x in range(len(pc1)):
        temp_C_D += bin_key[pc1[x]-1]
    return temp_C_D[:len(pc1)/2], temp_C_D[len(pc1)/2:]

#===========================================================================
# Fungsi untuk left Shifting pada Key
# C dan D digeser sebanyak x bit ke kiri
# alu hadil iterasi distuka lagi
#===========================================================================    
def left_shift(C0,D0):
    for x in left_rotations:
        C0 = C0[x:]+C0[:x]
        D0 = D0[x:]+D0[:x]    
        Key.append(PC2(C0,D0))
    return None

#===========================================================================
# Permutation KEY kedua sehingga bisa menghasilkan 16 Key
#===========================================================================    
def PC2(L, R):         
    K0 = L+R         
    K = ''                    
    for x in range(len(pc2)):
        K += K0[pc2[x]-1]
    return K
#===========================================================================
# Ekspansi data sesuai tabel E yang sebelumnya 32 bit menjadi 48 bit
# index ke yg dimau di tabel ekspansi dimasukkan EKS sementara
#===========================================================================
def EXPANSI(E0):
    Eks = ''                    
    for x in range(len(expansion)):
        Eks += E0[expansion[x]-1]
    return Eks

#===========================================================================
# Fungsi untuk XOR 2 blok data
#===========================================================================
def XOR(X, Z):
    c = int(X,2)^int(Z,2)
    c = "{0:0b}".format(c)
    return c

#===========================================================================
# Fungsi untuk S box, sesuai dengan tabe S box
# A dipecah2 tiap 6 bit
# a untuk mendapatkan bit awal dan bit terakhir
# b untuk mendapatkan bit tengah
# matris A1 dipetakan ke S0 dst, diambil nilai, baris a kolom b
# seiap nilainya dimasukkan ke B
#===========================================================================    
def SBOXES(A):    
    count = 0
    B = ''
    for x in range(0,len(A),6):
        a = int(A[x]+A[x+5],2)
        b = int(A[x+1:x+5],2)
        B += "{0:0b}".format(sboxes[count][a][b]).zfill(4)
        count += 1 
    return B
# ==========================================================================
# Fungsi untuk P Box
# memutasikan bit vektor Bi menggunakan tabel P-Box, 
# ==========================================================================
def P_BOX(B):
    PB = ''                    
    for x in range(len(p_box)):
        PB += B[p_box[x]-1]
    return PB
# ==========================================================================
# Fungsi untuk Invers Initial Permutation
# ==========================================================================   
def IP_INV(X):   
    chiper = ''                    
    for x in range(len(ip_inv)):
        chiper += X[ip_inv[x]-1]
    return chiper 

# ==============================================================================
# Fungsi DES 
# Data diubah berdasarkan inisial permutation
# Data di pecah menjadi 2, kanan dan kiri. 
# key dilakukan permutasi, dan dipecah menjadi 2
# ==============================================================================    
def DES():
    L0, R0 = IP(i)
    Right.append(R0)
    C0, D0 = PC1()
    left_shift(C0, D0)
            
    for x in range(16):    
        E = EXPANSI(Right[x])
        # Hasil E di xor dengan key dg tempate 48 bit, disimpan di matrix A
        # sebanyak 16 kali
        A = XOR(E,Key[x]).zfill(48)
        # hasil matrix A dimasukkan ke S BOX menjadi matrix B1
        B = SBOXES(A)
        # memutasi nilai B dengan tabel P Box
        PB = P_BOX(B)
        #  hasil PB di xor kan dengan LO untuk nilai ke 0
        if x == 0:
            Right.append(XOR(L0,PB).zfill(32))
        # untuk niai 1 <= i <= 16 menggunakan right
        else:
            Right.append(XOR(Right[x-1],PB).zfill(32))

#=================================================================================
# Fungsi untuk memanggil fungsi DES dan untuk XOR hasil enkripsi lalu menyimpan 
# hasil tiap blok
#==================================================================================        
def enkripsi(bin_counter):
    
    dummy = bin_data[i]
    bin_data[i] = bin_counter
    
    DES()
    # xor plaintext dengan hasil invers dengan tabel invers
    dummy = XOR(dummy,IP_INV(Right[16]+Right[15])).zfill(64)
    # simpan per blok
    hasil.append(dummy)
    return IP_INV(Right[16]+Right[15])
    
if __name__ == '__main__':

#====================================================================================
# Memanggil Tabel - Tabel Yang Telah diinisialisasikan
#===================================================================================
    ip, pc1, pc2, expansion, sboxes, p_box, left_rotations, ip_inv=inisialisasi()
    
# ====================================================================================
# inisialisasi pilihan Awal
# ===================================================================================
    pilihan = '1'
# ===================================================================================
# Memasukkan pilihan, Terdapat 2 Pilihan yaitu Enkripsi dan Dekripsi.
# Memasukkan Text yang akan diolah beserta ekstensi filenya (*txt)
#====================================================================================   
    pilihan = raw_input("Tekan 1 untuk eksripsi atau 2 untuk dekripsi : ")
    file_data = raw_input("Masukkan nama file dan ekstensinya : ")
# =================================================================================
# Membaca Data text uang akan dioah
# ================================================================================
    with open(file_data, 'rb') as file:
        data = file.read()
# ==================================================================================
#  Mengubah Data yang dibaca dari String menjadi Binary
# ==================================================================================
    bin_data = ''
    data = [data[i:i+8] for i in range(0, len(data), 8) ]
    bin_data = [stringToBinary(x) for x in data]

# =================================================================================
# Mendeklarasikan Key yang digunakan dan mengubah menjadi binary 
# ================================================================================      
    key = 'tug45K1J'
    bin_key = stringToBinary(key)      

# ================================================================================
# Membuat Counter berdasarkan banyaknya Blok mulai 0 sampai blok terakhir
# ==================================================================================    
    counter = []    
    for i in range(len(bin_data)):
        counter.append(i)
#===================================================================================
# Mengubah Counter menjadi binary.
#==================================================================================
    bin_counter=''
    bin_counter = ['00000000000000000000000000000000000000000000000000000000' + intToBinary(x) for x in counter]

# =================================================================================
# Memanggil fungsi untuk Enkripsi binary counter dan generate Key
# ================================================================================
    hasil = []   
    for i in range(len(bin_data)):
        Key = []
        Right = []        
        bin_counter[i] = enkripsi(bin_counter[i])        

# =================================================================================
# Menulis hasil Enkripsi ke dalam File
# Caranya dengan mengconcate binary hasil xor 
# mengubah hasil menjadi string
# ==================================================================================            
    if pilihan == '1' :
        hasil = ''.join(binaryToString(x) for x in hasil)
        print hasil
        with open('hasil.txt', 'wb') as f:
            data = f.write(hasil)

# ==================================================================================
# Jika pilihan untuk dekripsi, mambaca data hasi enkripsi, 
# lalu mengubah menjadi binary
# ==================================================================================
    elif pilihan == '2':
        hasil = ''.join(binaryToString(x) for x in hasil)        
        print hasil
