#include<stdlib.h>
#include<stdio.h>
#include <conio.h>
#include<iostream>

using namespace std;

struct node {
	int data;
	struct node * kanan, * kiri;
};


void tambah(node ** pohon, int val)
{
    node *temp = NULL;
    if(!(*pohon))
    {
        temp = (node *)malloc(sizeof(node));
        temp->kiri = temp->kanan = NULL;
        temp->data = val;
        *pohon = temp;
        return;
    }

    if(val < (*pohon)->data)
    {
        tambah(&(*pohon)->kiri, val);
    }
    else if(val > (*pohon)->data)
    {
        tambah(&(*pohon)->kanan, val);
    }

}

void delpohon(node* pohon)
{
    if (pohon == NULL) return;
    
        delpohon(pohon->kiri);
        delpohon(pohon->kanan);
        delete (pohon);
    
}

void hapuspohon(node** node_ref)  
{  
    delpohon(*node_ref);  
    *node_ref = NULL;  
}  

void preorder(node * pohon)
{
    if (pohon)
    {
        printf("%d ",pohon->data);
        preorder(pohon->kiri);
        preorder(pohon->kanan);
    }

}

void inorder(node * pohon)
{
    if (pohon)
    {
        inorder(pohon->kiri);
        printf("%d ",pohon->data);
        inorder(pohon->kanan);
    }
}

void postorder(node * pohon)
{
    if (pohon)
    {
        postorder(pohon->kiri);
        postorder(pohon->kanan);
        printf("%d ",pohon->data);
    }
}

node* cari(node ** pohon, int val)
{
    if(!(*pohon))
    {
        return NULL;
    }

   if(val < (*pohon)->data)
    {
        printf("%d ", (*pohon)->data);
        cari(&((*pohon)->kiri), val);
    }
    else if(val > (*pohon)->data)
    {
        printf("%d ", (*pohon)->data);
        cari(&((*pohon)->kanan), val);
        
    }
    else if(val == (*pohon)->data)
    {
        return *pohon;
    }
} 

struct node * minValueNode(struct node* node){
   struct node* current = node;
   while (current && current->kiri != NULL)
      current = current->kiri;
   return current;
}

struct node* hapusNode(struct node* root, int data){
   if (root == NULL) return root;
      if (data < root->data)
         root->kiri = hapusNode(root->kiri, data);
      else if (data > root->data)
         root->kanan = hapusNode(root->kanan, data);
   else{
      if (root->kiri == NULL){
         struct node *temp = root->kanan;
         free(root);
         return temp;
      }
      else if (root->kanan == NULL){
         struct node *temp = root->kiri;
         free(root);
         return temp;
      }
      struct node* temp = minValueNode(root->kanan);
      root->data = temp->data;
      root->kanan = hapusNode(root->kanan, temp->data);
   }
   return root;
}

int maxValue(struct node* node) 
{    
    struct node* current = node; 
    while (current->kanan != NULL)  
        current = current->kanan; 
      
    return (current->data); 
} 

int minValue(struct node* node) {
	struct node* current = node;  
	
	while (current->kiri != NULL) {  
		current = current->kiri;
	}  
	
	return(current->data);  
}  

main()
{
	int angka;
	char menu, scr='y';
    node *root;
    node *temp;

    root = NULL;
    tambah(&root, 71);
    tambah(&root, 44);
    tambah(&root, 81);
    tambah(&root, 28);
    tambah(&root, 78);
    tambah(&root, 89);
    tambah(&root, 17);
    tambah(&root, 91);
    
	while(scr == 'y' || scr =='Y') {
		system("cls"); 
		
		cout<<"====================PROGRAM BINARY SEARCH TREE====================="<<endl;
		cout<<"============Dibuat oleh Gilang Chandra S. (1910512023)============="<<endl;
		
		cout<<"1. Tambah Angka"<<endl;
    	cout<<"2. Cari Angka"<<endl;
    	cout<<"3. Hapus Angka"<<endl;
    	cout<<"4. Reset BST"<<endl;
    	cout<<"5. Lihat BST (Pre-Order)"<<endl;
    	cout<<"6. Lihat BST (In-Order)"<<endl;
    	cout<<"7. Lihat BST (Post-Order)"<<endl;
    	cout<<"8. Lihat Angka Terbesar"<<endl;
    	cout<<"9. Lihat Angka Terkecil"<<endl<<endl;
    	cout<<"Pilihan Menu : ";
    	cin>>menu;
    	
    	 fflush(stdin); 
    	
    	if(menu == '1') {
    		cout<<"Masukkan angka: ";
    		cin>>angka;
    		tambah(&root, angka);
			cout<<"Angka berhasil ditambahkan!";
			getch();
		}
		else if(menu == '2') {
    		cout<<"Masukkan angka: ";
    		cin>>angka;
    		
    		cout<<endl<<"Simpul yang dilewati : ";
			temp = cari(&root, angka);
			if (temp) {
				printf("\nDITEMUKAN = %d\n", temp->data);
				getch();
			}
			else {
				printf("\nTIDAK DITEMUKAN!\n");
				getch();
			}
		}
		else if(menu == '3') {
			cout<<"Masukkan angka : ";
    		cin>>angka;
    		
    		cout<<endl<<"Simpul yang dilewati : ";
    		temp = cari(&root, angka);
    		if (temp) {
				root = hapusNode(root, angka);
				cout<<"\nAngka berhasil dihapus!";
				getch();
			}
			else {
				printf("\nAngka tidak ada dalam BST!");
				getch();
			}
		}	
		else if(menu == '4') {
			delpohon(root);
			root = NULL;
			cout<<"BST berhasil di-reset!";
			getch();
		}	
		else if(menu == '5') {
			if(root==NULL) {
				cout<<"Data kosong!";
    			getch();
			}
			
			else {
				printf("BST diurutkan dengan Pre-Order\n");
    			preorder(root);
    			getch();
			}
    		
		}
		else if(menu == '6') {
			if(root==NULL) {
				cout<<"Data kosong!";
    			getch();
			}
			
			else {
				printf("BST diurutkan dengan In-Order\n");
    			inorder(root);
    			getch();
			}
    		
		}
		else if(menu == '7') {
			if(root==NULL) {
				cout<<"Data kosong!";
    			getch();
			}
			
			else {
				printf("BST diurutkan dengan Post-Order\n");
    			postorder(root);
    			getch();
			}
    		
		}
		else if(menu == '8') {
			if(root==NULL) {
				cout<<"Data kosong!";
    			getch();
			}
			else {
    			cout << "Angka terbesar dalam BST adalah " << maxValue(root); 
				getch();
			}
		}
		else if(menu == '9') {
			if(root==NULL) {
				cout<<"Data kosong!";
    			getch();
			}
			else {
    			cout << "Angka terkecil dalam BST adalah " << minValue(root); 
				getch();
			}
		}
	}
}

