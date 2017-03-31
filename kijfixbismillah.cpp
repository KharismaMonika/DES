#include<stdio.h>
#include<conio.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>

using namespace std;

int IP[64] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
			   62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
               57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
			   61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
			 };
			  
int PC1[56] = {57, 49, 41, 33, 25, 17, 19, 1, 58, 50, 42, 34, 26, 18,
			   10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
			   63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 45, 38, 30, 22,
			   14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
			  };

int PC2[48] = {14, 17, 11, 24, 1, 5,
		 	   3, 28, 15, 6, 21, 10,
		 	   23, 19, 12, 4, 26, 8,
		 	   16, 7, 27, 20, 13, 2,
		 	   41, 52, 31, 37, 47, 55,
		 	   30, 40, 51, 45, 33, 48,
		 	   44, 49, 39, 56, 34, 53,
		 	   46, 42, 50, 36, 29, 32
			  };

int etbl[48] = {32, 1, 2, 3, 4, 5,
			    4, 5, 6, 7, 8, 9,
			    8, 9, 10, 11, 12, 13,
			    12, 13, 14, 15, 16, 17,
			    16, 17, 18, 19, 20, 21,
			    20, 21, 22, 23, 24, 25,
			    24, 25, 26, 27, 28, 29,
			    28, 29, 30, 31, 32, 1
			   };		  

int sbox1[4][16] = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
				    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
				    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
				    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
				   };

int sbox2[4][16] = {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
				    {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
				    {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
				    {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
				   };

int sbox3[4][16] = {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
				    {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
				    {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
				    {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
				   };

int sbox4[4][16] = {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
				    {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
				    {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
				    {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
				   };

int sbox5[4][16] = {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
				    {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 15},
				    {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
				    {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
				   };

int sbox6[4][16] = {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
				    {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
				    {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
				    {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
				   };

int sbox7[4][16] = {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
				    {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
				    {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
				    {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
				   };

int sbox8[4][16] = {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
				    {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
				    {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
				    {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
				   };

int pbox[32] = {16, 7, 20, 21,
                29, 12, 28, 17,
                1, 15, 23, 26,
                5, 18, 31, 10,
                2, 8, 24, 14,
                32, 27, 3, 9,
                19, 13, 30, 6,
                22, 11, 4, 25
				};

int IP1[64] =  {40, 8, 48, 16, 56, 24, 64, 32,
                39, 7, 47, 15, 55, 23, 63, 31,
                38, 6, 46, 14, 54, 22, 62, 30,
                37, 5, 45, 13, 53, 21, 61, 29,
                36, 4, 44, 12, 52, 20, 60, 28,
                35, 3, 43, 11, 51, 19, 59, 27,
                34, 2, 42, 10, 50, 18, 58, 26,
                33, 1, 41, 9, 49, 17, 57, 25};

string ptext;
string key;

int main()
{
	int loop=8,i;
	int counter[8]={0,0,0,0,0,0,0,0};
	double hasil1=0;
	
	printf("Masukkan kata yang ingin dienkripsi : ");
	cin >> ptext;
//	scanf("%[^\n]c",ptext);
	cout << "Kata yang dimasukkan:" << ptext;
	printf ("\n");
	hasil1 = sizeof(ptext)/8;
	ceil(hasil1);
	cout << hasil1;
	printf("Masukkan key yang ingin digunakan : ");
	cin >> key;
	cout << "Key yang dimasukkan:" << key;
	printf ("\n");
	
	int j;
	int arr1[64];
	int arr3[64];
	int m[8][8];
	int z[8][8];
	int arr2[64];
	int n[8][8];
	int kawn=0;
	
	//Konversi dari ASCII ke biner utk plaintext
	for (j=0; j<8; j++)
	{
		for(i=0; i<8; i++)
    	{	    		
        	z[j][i]=counter[j]%2;
        	counter[j] = counter[j]/2;        	
    	}
 
    	int top, bottom;
 
    	for(bottom=0,top =7; bottom<8; bottom++,top--)
    	{
//        	cout<<z[j][top];
        	arr3[kawn]=z[j][top];
        	kawn = kawn+1;
    	}
	}
	
	for (j=0; j<8; j++)
	{
		for(i=0; i<8; i++)
    	{	    		
        	m[j][i]=ptext[j]%2;
        	ptext[j] = ptext[j]/2;        	
    	}
 
    	int top, bottom;
 
    	for(bottom=0,top =7; bottom<8; bottom++,top--)
    	{
//        	cout<<m[j][top];
        	arr3[kawn]=m[j][top];
        	kawn = kawn+1;
    	}
	}
	
	kawn = 0;
	
//	Konversi dari ASCII ke biner untuk key
	for (j=0; j<8; j++)
	{
		for(i=0; i<8; i++)
    	{	
    		
        	n[j][i]=key[j]%2;
        	key[j] = key[j]/2;
    	}
 
    	int top, bottom;
 
    	for(bottom=0,top =7; bottom<8; bottom++,top--)
    	{
        	//cout<<n[j][top];
        	arr2[kawn]=n[j][top];
        	kawn = kawn+1;
    	}
	}
	
	kawn = 0;
	
	cout << "Biner plaintext : \t";
	for (j=0; j<8; j++)
	{
		for (i=0; i<8; i++)
		{
			cout << arr1[kawn];
			kawn++;	
		}
		printf(" ");		
	}
	cout << "\n";
	kawn = 0;
	
	cout << "Biner key : \t";
	for (j=0; j<8; j++)
	{
		for (i=0; i<8; i++)
		{
			cout << arr2[kawn];
			kawn++;	
		}
		printf(" ");		
	}	
	printf ("\n");
	
	kawn = 0;
	
	int tampung[64];
	int test=0;
	int start;
//	Permutasi tabel IP
	for (j=0; j<64; j++)
	{
		start=0;	
		for (i=0; i<64; i++)
		{
			start++;
			if(IP[j]==start)
			{
				tampung[j]=arr3[i];
			}
		}
	}
	
//	Permutasi tabel PC1
	int hitung2=0;
	int tampung2[56];
	for (j=0; j<64; j++)
	{
		start=0;	
		for (i=0; i<64; i++)
		{
			start++;
			if(PC1[j]==start)
			{
				tampung2[j]=arr2[i];
				hitung2++;
			}
		}
	}
	
	cout << "\n";
	cout << "Hasil permutasi PC1 : ";
	kawn=0;
	for (j=0; j<8; j++)
	{
		for (i=0; i<7; i++)
		{
			cout << tampung2[kawn];
			kawn++;	
		}
		printf(" ");		
	}
	
	cout << "\n";
//	Pemisahan untuk biner split
	int shift1[2][28];
	kawn=0;
	for (i=0; i<2; i++)
	{
		for (j=0; j<28; j++)
		{
			shift1[i][j]=tampung2[kawn];
			kawn++;
		}
	}
	
	cout << "Permutasi PC1 displit : ";
	for (i=0; i<2; i++)
	{
		for (j=0; j<28; j++)
		{
			cout << shift1[i][j];
			kawn++;
		}
		cout << " ";
	}
	
	int k=0;
	int go=0;
	int shiftres1[16][28];
	int shiftres2[16][28];
	int shiftemp[1][28];
	
//	Shifting split biner pertama
	for (i=1; i<=16; i++)
	{
		if (i==1)
		{
			if (i==1 || i==2 || i==9 || i==16)
			{
				for (j=0; j<28; j++)
				{
					if (j==0)
					{
						shiftres1[i-1][28-1]=shift1[i-1][j];	
					}
					else
					{
						shiftres1[i-1][j-1]=shift1[i-1][j];
					}
				}
			}
		}
		else
		{
			if (i==2 || i==9 || i==16)
			{
				for (j=0; j<28; j++)
				{
					if (j==0)
					{
						shiftres1[i-1][28-1]=shiftres1[i-2][j];	
					}
					else
					{
						shiftres1[i-1][j-1]=shiftres1[i-2][j];
					}
				}
			}
			else
			{
				for (k=1; k<=2; k++)
				{
					if(k==2)
					{
						for (j=0; j<28; j++)
						{
							if (j==0)
							{
								shiftres1[i-1][28-1]=shiftemp[1][j];	
							}
							else
							{
								shiftres1[i-1][j-1]=shiftemp[1][j];
							}
						}	
					}
					else 
					{
						for (j=0; j<28; j++)
						{
							if (j==0)
							{
								shiftemp[1][28-1]=shiftres1[i-2][j];	
							}
							else
							{
								shiftemp[1][j-1]=shiftres1[i-2][j];
							}
						}	
					}		
				}
			}
		}	
	}
	
//	Shifting split biner kedua
	for (i=1; i<=16; i++)
	{
		if (i==1)
		{
			if (i==1 || i==2 || i==9 || i==16)
			{
				for (j=0; j<28; j++)
				{
					if (j==0)
					{
						shiftres2[i-1][28-1]=shift1[i+0][j];	
					}
					else
					{
						shiftres2[i-1][j-1]=shift1[i+0][j];
					}
				}
			}
		}
		else
		{
			if (i==2 || i==9 || i==16)
			{
				for (j=0; j<28; j++)
				{
					if (j==0)
					{
						shiftres2[i-1][28-1]=shiftres2[i-2][j];	
					}
					else
					{
						shiftres2[i-1][j-1]=shiftres2[i-2][j];
					}
				}
			}
			else
			{
				for (k=1; k<=2; k++)
				{
					if(k==2)
					{
						for (j=0; j<28; j++)
						{
							if (j==0)
							{
								shiftres2[i-1][28-1]=shiftemp[1][j];	
							}
							else
							{
								shiftres2[i-1][j-1]=shiftemp[1][j];
							}
						}	
					}
					else 
					{
						for (j=0; j<28; j++)
						{
							if (j==0)
							{
								shiftemp[1][28-1]=shiftres2[i-2][j];	
							}
							else
							{
								shiftemp[1][j-1]=shiftres2[i-2][j];
							}
						}	
					}		
				}
			}
		}	
	}
	
//	Penggabungan split biner menjadi 1
	int shiftgbg[16][56];
	for (i=0; i<16; i++)
	{
		kawn=0;
		for (j=1; j<=2; j++)
		{
			for (k=0; k<28; k++)
			{
				if (j==2)
				{
					shiftgbg[i][kawn]=shiftres2[i][k];
				}
				else 
				{
					shiftgbg[i][kawn]=shiftres1[i][k];
				}	
				kawn++;			
			}
		}
	}
	
//	Key dari tabel PC2
	int newkey[16][48];
	for (k=0; k<16; k++)
	{
		for (j=0; j<56; j++)
		{
			start=0;	
			for (i=0; i<56; i++)
			{
				start++;
				if(PC2[j]==start)
				{
					newkey[k][j]=shiftgbg[k][i];
					hitung2++;
				}
			}
		}
	}
	
//	Permutasi plain text di split
	int plainmut[2][32];
	kawn=0;
	for (i=0; i<2; i++)
	{
		for (j=0; j<32; j++)
		{
			plainmut[i][j]=tampung[kawn];
			kawn++;
		}
	}
	
	cout << "\n\n";
	cout << "Hasil permutasi plaintext : ";
	for (i=0; i<2; i++)
	{
		for (j=0; j<32; j++)
		{
			cout << plainmut[i][j];
		}cout << " ";
	}
	
	cout << "\n\n";
	
	int duar;
	int tampungplain[48];
	int xor1[16][48];
	int xortemp[8][6];
	int xortempbyg1[8][2];
	int xortempbyg2[8][4];
	int tanda1;
	int tanda2;
	int temp1[8];
	int temp2[8];
	int b1[32];
	int c,o;
	int nambah;
	int pb1[32];
	int xor2[32];
	int R1[16][32];
	for (duar=0; duar<16; duar++)
	{
		if (duar==0)
		{
			hitung2=0;
			for (j=0; j<48; j++)
			{
				start=0;	
				for (i=0; i<48; i++)
				{
					start++;
					
					if(etbl[j]==start)
					{
						tampungplain[j]=plainmut[1][i];
				
						for (k=i; k<48; k++)
						{
							if(etbl[k]==start)
							{
								tampungplain[k]=plainmut[1][i];
							}
						}
						
					}
				}	
			}
			
			for (i=0; i<32; i++)
			{
				R1[duar][i]=plainmut[1][i];
			}
			
			for (j=0; j<48; j++)
			{
				if ((tampungplain[j]==0 && newkey[duar][j]==0) || (tampungplain[j]==1 && newkey[duar][j]==1) )
				{
					xor1[duar][j]=0;
				}
				else if ((tampungplain[j]==0 && newkey[duar][j]==1) || (tampungplain[j]==1 && newkey[duar][j]==0))
				{
					xor1[duar][j]=1;
				}
			}
			
			kawn=0;
			for (i=0; i<8; i++)
			{
				for (j=0; j<6; j++)
				{
					xortemp[i][j] = xor1[duar][kawn];
					kawn++;
				}
			}
			
			for (i=0; i<8; i++)
			{
				tanda1=0;
				tanda2=0;
				for (j=0; j<6; j++)
				{
					if (j==0 || j==6-1)
					{
						xortempbyg1[i][tanda1]=xortemp[i][j];
						tanda1++;
					}
					else
					{
						xortempbyg2[i][tanda2]=xortemp[i][j];
						tanda2++;
					}
				}
			}
			 
			for (i=0; i<8; i++)
			{
				temp1[i]=0;
				for(int j=0; j<2; j++)
				{
					temp1[i] += pow(2,1-j) * xortempbyg1[i][j];
				}	
			}
			
			for (i=0; i<8; i++)
			{
				temp2[i]=0;
				for(int j=0; j<4; j++)
				{
					temp2[i] += pow(2,3-j) * xortempbyg2[i][j];
				}	
			}
			
			o=0;
			nambah=0;
			for (i=0; i<8; i++)
			{
				if (i==0)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox1[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox1[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
								
							}
						}
					}	
				}
				else if (i==1)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox2[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox2[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==2)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox3[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox3[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==3)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox4[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox4[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==4)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox5[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox5[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==5)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox6[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox6[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}
				}
				else if (i==6)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox7[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox7[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==7)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox8[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox8[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
			}
			
			for (j=0; j<32; j++)
			{
				start=0;	
				for (i=0; i<32; i++)
				{
					if(pbox[j]==start)
					{
						pb1[j]=b1[i];
					}
					start++;
				}
			}
			
			for (j=0; j<32; j++)
			{
				if ((pb1[j]==0 && plainmut[duar][j]==0) || (pb1[j]==1 && plainmut[duar][j]==1) )
				{
					xor2[j]=0;
				}
				else if ((pb1[j]==0 && plainmut[duar][j]==1) || (pb1[j]==1 && plainmut[duar][j]==0))
				{
					xor2[j]=1;
				}
			}
			
			for (i=0; i<32; i++)
			{
				R1[duar+1][i]=xor2[i];
			}	
		}
		else 
		{
			hitung2=0;
			for (j=0; j<48; j++)
			{
				start=0;	
				for (i=0; i<48; i++)
				{
					start++;
					
					if(etbl[j]==start)
					{
						tampungplain[j]=R1[duar][i];
				
						for (k=i; k<48; k++)
						{
							if(etbl[k]==start)
							{
								tampungplain[k]=R1[duar][i];
							}
						}
						
					}
				}	
			}
			
			for (j=0; j<48; j++)
			{
				if ((tampungplain[j]==0 && newkey[duar][j]==0) || (tampungplain[j]==1 && newkey[duar][j]==1) )
				{
					xor1[duar][j]=0;
				}
				else if ((tampungplain[j]==0 && newkey[duar][j]==1) || (tampungplain[j]==1 && newkey[duar][j]==0))
				{
					xor1[duar][j]=1;
				}
			}
			
			kawn=0;
			for (i=0; i<8; i++)
			{
				for (j=0; j<6; j++)
				{
					xortemp[i][j] = xor1[duar][kawn];
					kawn++;
				}
			}
			
			for (i=0; i<8; i++)
			{
				tanda1=0;
				tanda2=0;
				for (j=0; j<6; j++)
				{
					if (j==0 || j==6-1)
					{
						xortempbyg1[i][tanda1]=xortemp[i][j];
						tanda1++;
					}
					else
					{
						xortempbyg2[i][tanda2]=xortemp[i][j];
						tanda2++;
					}
				}
			}
			 
			for (i=0; i<8; i++)
			{
				temp1[i]=0;
				for(int j=0; j<2; j++)
				{
					temp1[i] += pow(2,1-j) * xortempbyg1[i][j];
				}	
			}
			
			for (i=0; i<8; i++)
			{
				temp2[i]=0;
				for(int j=0; j<4; j++)
				{
					temp2[i] += pow(2,3-j) * xortempbyg2[i][j];
				}	
			}
			
			o=0;
			nambah=0;
			for (i=0; i<8; i++)
			{
				if (i==0)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox1[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox1[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
								
							}
						}
					}	
				}
				else if (i==1)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox2[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox2[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==2)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox3[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox3[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==3)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox4[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox4[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==4)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox5[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox5[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==5)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox6[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox6[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}
				}
				else if (i==6)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox7[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox7[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
				else if (i==7)
				{
					for (j=0; j<4; j++)
					{
						for (k=0; k<16; k++)
						{
							if (temp1[i]==j && temp2[i]==k)
							{
//									cout << "INI DIA" << sbox8[j][k];
									for (c = 3; c >= 0; c--)
									{
										o = sbox8[j][k] >> c;
									 
									    if (o & 1)
									    {
									    	b1[nambah]=1;
											nambah++;	
									    }
									    else
									    {
									    	b1[nambah]=0;
											nambah++;	
									    }
									}	
							}
						}
					}	
				}
			}
			
			for (j=0; j<32; j++)
			{
				start=0;	
				for (i=0; i<32; i++)
				{
					if(pbox[j]==start)
					{
						pb1[j]=b1[i];
					}
					start++;
				}
			}
			
			for (j=0; j<32; j++)
			{
				if ((pb1[j]==0 && R1[duar-1][j]==0) || (pb1[j]==1 && R1[duar-1][j]==1) )
				{
					xor2[j]=0;
				}
				else if ((pb1[j]==0 && R1[duar-1][j]==1) || (pb1[j]==1 && R1[duar-1][j]==0))
				{
					xor2[j]=1;
				}
			}
			
			for (i=0; i<32; i++)
			{
				R1[duar+1][i]=xor2[i];
			}	
		}	
	}
	
	cout << "\n";
	for (i=0; i<16; i++)
	{
		for (j=0; j<32; j++)
		{
			cout << R1[i][j];
		}cout << "\n";
	}
	
	int thelast[64];
	for (i=0; i<1; i++)
	{
		start=0;
		for (j=0; j<32; j++)
		{
			thelast[start]=R1[15][j];
			start++;
		}
		for (k=0; k<32; k++)
		{
			thelast[start]=R1[14][k];
			start++;
		}
	}
	
	int akhirtampung[64];
	for (j=0; j<64; j++)
	{
		start=0;	
		for (i=0; i<64; i++)
		{
			start++;
			if(IP1[j]==start)
			{
				akhirtampung[j]=thelast[i];
			}
		}
	}
	
	cout << "\n";
	for (i=0; i<64; i++)
	{
		cout << thelast[i];
	}
	cout << "\n";
	for (i=0; i<64; i++)
	{
		cout << akhirtampung[i];
	}
	
	int sblmslsai[64];
	for (i=0; i<64; i++)
	{
		if ((akhirtampung[i]==0 && arr1[i]==0) || (akhirtampung[i]==1 && arr1[i]==1) )
		{
			sblmslsai[i]=0;
		}
		else if ((akhirtampung[i]==0 && arr1[i]==1) || (akhirtampung[i]==1 && arr1[i]==0))
		{
			sblmslsai[i]=1;
		}
	}
	cout << "\n";
	start=0;
	int hasil[8][8];
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			hasil[i][j]=sblmslsai[start];
			start++;
		}
	}
	
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			cout << hasil[i][j];
		}cout << " ";
	}
	
	start=0;
	char encip[64];
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			encip[start]=hasil[i][j];
			start++;
		}
	}
	cout << "\n";
	
	int akhir[8];
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			akhir[i] += pow(2,7-j) * hasil[i][j];
		}
	}
	
	char g;
	for (i=0; i<8; i++)
	{
		g = akhir[i];
		printf("%c",g);
	}
		
	return 0;
		
}
