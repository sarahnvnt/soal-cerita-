#include<iostream>
using namespace std;
 
struct data{
	char nama[100];
	char perm; 
	int no;
};

struct ElmtQueue{
	data info;
	ElmtQueue* next;
	ElmtQueue* prev;
};

typedef ElmtQueue* pointer;

struct Queue{
 	pointer Head; //depan
 	pointer Tail; //belakang
};

void createQueue(Queue& Q);
void createElment(Queue& pBaru);
void insertQueue(Queue& Q);
void deleteQueue(Queue& Q, pointer& pHapus);
void traversal(Queue Q);

main(){
 	Queue Q;
	pointer pBaru, pHapus;
 	int pilih;
 	createQueue(Q);
 do{
  	menu:
  	system("cls");
  	cout<<"=======PROGRAM ANTRIAN BANK====== "<<endl;
  	cout<<"=================================\n"<<endl;
  	cout<<" 1. Tambah Antrian "<<endl;
  	cout<<" 2. Panggilan Antrian "<<endl;
  	cout<<" 3. Lihat Daftar Antrian "<<endl;
  	cout<<" 4. Keluar"<<endl;
  	cout<<"\n================================"<<endl;
  	cout<<"Pilihan : ";
  	cin>>pilih;
  	switch(pilih){
  		case 1:
  			system("cls");
   			cout<<"======================================"<<endl;
		 	cout<<"\tTambahkan Antrian "<<endl;
   			cout<<"======================================"<<endl;
   			insertQueue(Q);
   			system("pause");
   			break;
  		case 2:
  			deleteQueue(Q,pHapus);
  		 	system("cls");
  		 	cout<<"======================================"<<endl;
	   		cout<<"\tAntrian "<<endl;
	   		cout<<"======================================"<<endl;
	   		traversal(Q);
	   		system("pause");
	   		break;
  		case 3:
			system("cls");
	   		cout<<"======================================"<<endl;
	   		cout<<"\tAntrian "<<endl;
	   		traversal(Q);
	   		system("pause");
	   		break;
 		case 4:
	   		system("cls");
	   		cout<<"\n\n\t\t\t\tTERIMAKASIH SUDAH DATANG"<<endl<<endl;
	   		system("pause");
	   		break;
	  		default:
	   		cout<<"\n\tKembali Ke Menu Pilihan?!!\n\n";
	   		system("pause");
	   		goto menu;
	   		
 			}
 }while(pilih != 0);
}

void createQueue(Queue& Q){
 	Q.Head = NULL;
 	Q.Tail = NULL;
}

void createElement(pointer& pBaru){
 	pBaru = new ElmtQueue;
 	char tmp[10];
 	cout<<"Nama Nasabah\t: ";
 	cin>>pBaru->info.nama;
 	cout<<"Jenis permintaan(A/B): ";
 	cin>>pBaru->info.perm;
 	cout<<"Nomor Antrian\t: ";
 	cin>>pBaru->info.no;
 
 	pBaru->next = NULL;
 	pBaru->prev = NULL;
}

void insertQueue(Queue& Q){
 	pointer pBaru, pBantu;
 	int ketemu = 0;
 	createElement(pBaru);
 	if(Q.Head == NULL){
  	Q.Head = pBaru;
  	Q.Tail = pBaru;
 }
 else{
 	pBantu = Q.Head;
  		if(Q.Head->info.no > pBaru->info.no){
  		pBaru->next = Q.Head;
		Q.Head->prev = pBaru;
		Q.Head = pBaru;
  		}
  		else{
   			while(ketemu == 0 && pBantu != NULL){
    			if(pBantu->info.no > pBaru->info.no){
     			ketemu = 1;
     			pBaru->next = pBantu;
     			pBaru->prev = pBantu->prev;
     			pBaru->next->prev = pBaru;
     			pBaru->prev->next = pBaru;
    			}
    			else
     			pBantu = pBantu->next;
   			}
   		if(ketemu == 0){
    		Q.Tail->next = pBaru;
    		pBaru->prev = Q.Tail;
    		Q.Tail = pBaru;
   		}
  		}
}	 
 cout<<endl<<pBaru->info.nama<<" Sudah Masuk kedalam Antrian"<<endl<<endl;
}

void deleteQueue(Queue& Q, pointer& pHapus){
	if(Q.Head == NULL){
 		pHapus = NULL;
 		cout<<"Antrian kosong";
 }
 else if(Q.Head == Q.Tail){
  	pHapus = Q.Head;
 	Q.Head = NULL;
  	Q.Tail = NULL;
 }
 else{
  pHapus = Q.Head;
  Q.Head = Q.Head->next;
  Q.Head->prev = NULL;
  pHapus->next = NULL;
 }
}

void traversal(Queue Q){
 	pointer pBantu;
 	int no=1;
 	pBantu = Q.Head; 
 	if(Q.Head == NULL){
 		cout<<"Antrian kosong";
 }
 else{
  	cout<<"==================================================================================="<<endl;
  	cout<<"No\tNama\t\tJenisPermintaan\t\tNo.Antrian"<<endl;
  	cout<<"==================================================================================="<<endl;
  	while(pBantu != NULL){
   		cout<<no<<"\t"<<pBantu->info.nama<<"\t\t"<<pBantu->info.perm<<"\t\t\t"<<pBantu->info.no<<endl;
   		pBantu = pBantu->next;
		no++;
  }
   cout<<"====================================================================================="<<endl;
 }
   cout<<endl;
}
