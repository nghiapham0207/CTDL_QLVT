#include <iostream>
#include <fstream>
#include <string.h>
#include "function.h"

using namespace std;

//Son

int CountM = 0;

struct Material{
	char code[11];
	char name[26];
	char type[11];
	char amount[9];
	Material(){
		code[0] = '\0';
		name[0] = '\0';
		type[0] = '\0';
		amount[0] = '\0';
	}
};

struct NameMats{
	char code[11];
	char name[26];
	unsigned long long  revenue;
	NameMats(){
		code[0] = '\0';
		name[0] = '\0';
		revenue = 0;
	}
	
	bool operator > (const struct NameMats &other){
		return (this->revenue > other.revenue);
	}
	
	bool operator < (const struct NameMats &other){
		return (this->revenue < other.revenue);
	}
	
};

struct Node	{			//AVL tree
	
	char key[11];
	Material info;
	Node *left;
	Node *right;

};
typedef struct Node *NODER;

//====Functions====//


void Initalize(NODER &root, int &CountM){
	CountM = 0;
	root = NULL;
}


int treeLevel(NODER root) {
	if (root == NULL)
		return -1;
	return 1 + max(treeLevel(root->left), treeLevel(root->right));
}
NODER rotateR(NODER y) { 
												//				y
						 						//			   / \	
 												//			  x   T4
												//		     / \	
												//          z   p
												//         / \
												//         T1 T2
	NODER x=y->left;
	NODER p=x->right;
	y->left=p;
	x->right=y;
	return x;
} 

NODER rotateL(NODER y) { 
	NODER x = y->right;
	NODER p = x->left;
	y->right = p;
	x->left = y;
	return x; 
} 


void remove3(NODER &rp, NODER &r){
	if(r->left!=NULL)
		remove3(rp, r->left);
	else{
		strcpy(rp->key, r->key);
		rp->info=r->info;
		rp=r;
		r=rp->right;
	}
}
NODER deleteNode(NODER root, char key[]) { 
	if (root == NULL)
		return root;
	else{
		if (strcmp(key, root->key)<0)
			root->left = deleteNode(root->left, key);
		else{
			if (strcmp(key, root->key)>0)
				root->right = deleteNode(root->right, key);
			else
			{	//tim thay node can xoa rp
				NODER rp = root;
				if (rp->right == NULL)root = rp->left;
				else 
					if (rp->left == NULL)root = rp->right;
					else
						remove3(rp, rp->right);
				delete rp;
			}
		}
	}
	if (root == NULL) 
		return root; 
	//can bang cay
	if (abs(treeLevel(root->left) - treeLevel(root->right)) > 1) {
		//
		if (treeLevel(root->left) > treeLevel(root->right)) {
			Node *q = root->left;
			//trái trái
			if (treeLevel(q->left) >= treeLevel(q->right)) {
				return rotateR(root);
			}
			else {
				//trái phai
				root->left = rotateL(root->left);
				return rotateR(root);
			}
		}
		else {
			Node *q = root->right;
			//phai? phai?
			if (treeLevel(q->right) >= treeLevel(q->left)) {
				return rotateL(root);
			}
			else {
				//phai? trái
				root->right = rotateR(root->right);
				return rotateL(root);
			}
		}
	}
	return root;
}

NODER newNode(char key[], Material a){  
    NODER node = new Node; 
    strcpy(node->key,key);
	strcpy(node->info.code,a.code);
	strcpy(node->info.name,a.name);
	strcpy(node->info.type,a.type);
	strcpy(node->info.amount,a.amount);
	node->right = NULL;
	node->left = NULL;
	return node;  
} 

NODER Insert(NODER root, char key[], Material a){ 
	if (root == NULL)
		return newNode(key, a);
	else{
		if (strcmp(key, root->key) < 0)
			root->left = Insert(root->left, key, a);
		else
			root->right = Insert(root->right, key, a);
	}
	//can bang cay
	if (abs(treeLevel(root->left) - treeLevel(root->right)) > 1){
		//
		if (treeLevel(root->left) > treeLevel(root->right)){
			Node *q = root->left;
			//trái trái
			if (treeLevel(q->left) >= treeLevel(q->right)){
				return rotateR(root);
			}
			else{
				//trái phai
				root->left = rotateL(root->left);
				return rotateR(root);
			}
		}
		else{
			Node *q = root->right;
			//phai phai?
			if (treeLevel(q->right) >= treeLevel(q->left)) {
				return rotateL(root);
			}
			else {
				//phai trái
				root->right = rotateR(root->right);
				return rotateL(root);
			}
		}
	}
	return root;
} 
	
NODER Search(NODER &root, char x[11]){
	NODER p;
	p = root ;
	while(p != NULL && strcmp(p->key, x) != 0){
		if(strcmp(p->key, x) < 0)
			p = p->right;
		else if(strcmp(p->key, x) > 0)
		 	 p = p->left;		 	
	}
	return p;
}	


void Qsort(NameMats info[], int left, int right ){
	NameMats mid = info[(left + right) / 2];
	int i = left, j = right;
	do{
		while(strcmp(info[i].name, mid.name) < 0)
			i++;
		while(strcmp(info[j].name, mid.name) > 0)
			j--;
		if(i <= j){
			if(i < j){
				NameMats tmp;
				tmp = info[i];
				info[i] = info[j];
				info[j] = tmp;
			}
			i++; j--;
		}
	} while(i<=j);
	if(left < j)
		Qsort(info,left,j);
	if(right > i)
		Qsort(info,i,right);
}


//===save and load====//

void saveNode(NODER &tree, ofstream &outMat){
	if(tree != NULL){
		saveNode(tree->left,outMat);
		outMat << tree->info.code <<endl;
		outMat << tree->info.name <<endl;
		outMat << tree->info.type <<endl;
		outMat << tree->info.amount <<endl;
		saveNode(tree->right,outMat);
	}
	else
		return;
}	

void saveMat(NODER &tree, int &nMat){
	ofstream outMat;
	outMat.open("data/listmaterial.txt", ios::out);
	outMat << nMat << endl;
	saveNode(tree, outMat);
	outMat.close();
}

void loadFile(NODER &tree, int &CountM){
	Initalize(tree, CountM);
	ifstream inMat;
	inMat.open("data/listmaterial.txt",ios::in);
	inMat >> CountM;
	inMat.ignore();
	for(int i = 0; i < CountM; i++){
		Material tmp;
		inMat.getline(tmp.code,sizeof(tmp.code));
		inMat.getline(tmp.name, sizeof(tmp.name));
		inMat.getline(tmp.type, sizeof(tmp.type));
		inMat.getline(tmp.amount, sizeof(tmp.amount));
		tree = Insert(tree,tmp.code,tmp);
	}	
	inMat.close();
}
					

