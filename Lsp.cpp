#include <iostream>
#include <queue>
#include <conio.h>
#define max 5
using namespace std;

queue<int> cart;
string item_list[] = {"Bodrex Tablet","Mylanta Sirup","Ever E250 Kapsul","Siladex Sirup","Hufagrip Sirup",
		      "Imboost Force Tablet","Combantrin Sirup","Vitacimin Tablet","Promag Tablet","Diapet Kapsul"};
int item_price[] = {9000,42000,75500,26000,19000,50000,28000,20000,10000,5000};

void push()
{
	int push;
	if(cart.size() == max)
	{
		system("cls");
		cout << "* Keranjang Penuh ! *" << endl;
	}else
	{
		cout << ">> Masukkan barang : ";
		cin >> push;
		cart.push(push);
		if(push >= 1 && push <= 10)
		{
			cout << "* Barang baru telah ditambahkan ke keranjang *" << endl;	
		}else
		{
			cart.pop();
			cout << "Pilihan barang tidak tersedia !" << endl;
		}
	}
}

void pop()
{
	if(cart.empty())
	{
		system("cls");
		cout << "* Keranjang Kosong !*" << endl;
	}else
	{
		cout << "* " << item_list[cart.front()-1] << " telah dihapus dari keranjang *" << endl;
		cart.pop();
	}
}

void clear()
{
	while(!cart.empty())
	{
		cart.pop();
	}
	cout << "* Keranjang Dikosongkan *";
}

void show (queue <int> cart)
{
	if (cart.empty())
	{
    		return;
	}else
	{
		int x = cart.front();
		cart.pop();
		cout << "- " << item_list [x-1] << endl;
		show (cart);
		cart.push(x);
	}
}

void checkout()
{
	int pay;
	if(cart.empty())
	{
		cout << "============================================\n";
		cout << "* Keranjang Masih Kosong ! *" << endl;
		cout << "============================================\n";
	}else
	{
		cout << "============================================\n";
		cout << item_list[cart.front()-1] << "\t[Rp. " << item_price[cart.front()-1] << "]" << endl;
		cout << "============================================\n";
		cout << ">> Masukkan uang anda : ";
		cin >> pay;
		if(pay < item_price[cart.front()-1])
		{
			cout << "============================================\n";
			cout << "Uang tidak mencukupi !" << endl;
			cout << "============================================\n";
		}else if(pay >= item_price[cart.front()-1])
		{
			cout << "============================================\n";
			cout << "kembalian : Rp. " << pay - item_price[cart.front()-1] << endl;
			cout << "============================================\n";
			cart.pop();
		}
	}
}

int main()
{
	int choose;
	
	do
	{
		cout << "============================================\n";
		cout << "\t     APOTEK NDONING SEHAT" << endl;
		cout << "============================================\n";
		cout << endl;
		cout << "List Barang : " << endl;
		for(int i = 0; i < 10; i++)
		{
			cout << i+1 << ". " << item_list[i] << "\t[Rp. " << item_price[i] << "]" << endl;
		}
		cout << "============================================\n";
		cout << "\n1). Tambah Barang Ke Keranjang";
		cout << "\n2). Hapus Barang Dari Keranjang";
		cout << "\n3). Kosongkan Keranjang";
		cout << "\n4). Cek Keranjang";
		cout << "\n5). Checkout";
		cout << "\n6). Keluar Program\n";
		cout << "\n>> Masukkan pilihan : ";
        cout << "";
        cin >> choose;
		switch(choose)
		{
			case 1 :
				push();
				getch();
				break;
				
			case 2 :
				pop();
				getch();
				break;
				
			case 3 :
				clear();
				getch();
				break;
				
			case 4 :
				system("cls");
				cout << "List barang di keranjang : " << endl;
				show(cart);
				getch();
				break;
				
			case 5 :
				system("cls");
				checkout();
				getch();
				break;
				
			case 6 :
				system("cls");
				cout << "========================================================\n";
    				cout << "  TERIMA KASIH TELAH BERKUNJUNG KE  APOTEK NDONING SEHAT !" << endl;
    				cout << "========================================================\n";
				getch();
				break;
			
			default:
				system("cls");
				cout << "Pilihan Tidak Tersedia !";
				getch();
				break;	
		}
		system("cls");		
	} while (choose != 6);
}