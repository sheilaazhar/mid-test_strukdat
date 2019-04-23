/*
Nama		: Sheila Azhar Almufarida
NPM			: 140810180001
Kelas		: A
Tanggal		: 23 April 2019
Nama Program: Soal 1 UTS
Deskripsi	: Untuk mencetak data tim Sepakbola
*/
#include <iostream>

using namespace std;

struct SepakbolaList{
	int no;
	char tim[10];
	char daerah[15];
	int gol;
	SepakbolaList* next;
};

typedef SepakbolaList* pointer;
typedef pointer List;

void CreateList(List& First){
	First=NULL;
}

void CreateElmt(pointer& pBaru){
	pBaru=new SepakbolaList;
	cout<<"No. Daftar	: "; cin>>pBaru->no;
	cout<<"Nama Tim	: "; cin>>pBaru->tim;
	cout<<"Asal Daerah	: "; cin>>pBaru->daerah;
	cout<<endl;
	pBaru->next=NULL;
}

void UpdateGol(pointer& pBaru){
	pBaru=new SepakbolaList;
	cout<<"Jumlah Gol "<<pBaru->tim<<" : "; cin>>pBaru->gol;
}

void insertFirst(List& First, pointer pBaru){
	if(First==NULL)
		First=pBaru;
		else{
			pBaru->next=First;
			First=pBaru;
		}
}

void tranversal(List First){
	pointer pBantu;
	pBantu=First;
	cout<<"		DATA PENDAFTAR				"<<endl;
	cout<<"=================================================="<<endl;
	cout<<"No. Daftar"<<"	"<<"Tim"<<"		"<<"Asal Daerah"<<endl;
	cout<<"=================================================="<<endl;
	while(pBantu != NULL){
		cout<<pBantu->no<<"		"<<pBantu->tim<<"		"<<pBantu->daerah<<endl;
		pBantu=pBantu->next;
	}
}

void UpdateTraversal(List First){
	pointer pBantu;
	pBantu=First;
	cout<<"=================================================="<<endl;
	cout<<"No. Daftar"<<"	"<<"Tim"<<"		"<<"Gol"<<endl;
	cout<<"=================================================="<<endl;
	while(pBantu != NULL){
		cout<<pBantu->no<<"		"<<pBantu->tim<<"		"<<pBantu->gol<<endl;
		pBantu=pBantu->next;
	}
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	if(First==NULL){
		First=pBaru;
	}
	else{
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

main(){
	pointer p;
	List UTS01;
	int n;
	
	CreateList(UTS01);
	cout<<"Jumlah Tim	: "; cin>>n;
	cout<<endl;
	for(int i=0; i<n; i++){
		CreateElmt(p);
		insertLast(UTS01, p);
	}
	system("cls");
	tranversal(UTS01);
	system("pause");
	
	cout<<"Update Jumlah Gol"<<endl;
	for(int i=0; i<n; i++){
		UpdateGol(p);
		insertLast(UTS01, p);
	}
	system("cls");
	UpdateTraversal(UTS01);
}
