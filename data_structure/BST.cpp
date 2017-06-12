/*
 * BST.cpp
 * this is just a binary search tree program.
 * this includes create, insert, search ,delete..
 *
 * Created on: June 6, 2017
 * Author: bv_user
 */

#include <iostream>
using namespace std;

struct item{
	int key;
	item* p = NULL;
	item* left = NULL;
	item* right = NULL;
};

void insert(item* root, int num){
	if(root==NULL)
		return;
	while(1){
		if(num>root->key)
			if(root->right==NULL){//lookahead child
				item* ins = new item;
				ins->key = num;
				ins->p = root;
				root->right = ins;
				return;
			}else
				root = root->right;
		else
			if(root->left==NULL){
				item* ins = new item;
				ins->key = num;
				ins->p = root;
				root->left = ins;
				return;
			}else
				root = root->left;
	}
}
item* create(int* arr, int num){
	item* root = new item;
	root->key = arr[0];
	for(int i=1; i<num; i++){
		insert(root, arr[i]);
	}
	return root;
}

void traversal(item* root){
	if(root==NULL)
		return;
	traversal(root->left);
	cout<<root->key<<'\t';
	traversal(root->right);
}

bool delete_item(item* root, int num){
	while(root!=NULL){
		if(root->key==num){
			if(root->left==NULL){
				if(root->right==NULL){ // have no child
					if(root->p!=NULL){ // not root
						if(root->p->left==root)
							root->p->left = NULL;
						else
							root->p->right = NULL;
					}
					delete root;
					return true;
				}else{  // only have right child
					if(root->p->left==root){
						root->p->left = root->right;
						root->right->p = root->p;
					}else{
						root->p->right = root->right;
						root->right->p = root->p;
					}
					delete root;
					return true;
				}
			}else{
				if(root->right==NULL){ // only have left child
					if(root->p->left==root){
						root->p->left = root->left;
						root->left->p = root->p;
					}else{
						root->p->right = root->left;
						root->left->p = root->p;
					}
					delete root;
					return true;
				}else{ // have both left and right child
					item* l_max = root->left;
					while(l_max->right!=NULL){
						l_max = l_max->right;
					}
					root->key = l_max->key;
					if(delete_item(l_max, l_max->key))
						return true;
				}
			}


		}
		if(num>root->key)
			root = root->right;
		else
			root = root->left;
	}
	cout<< "can not find:" << num;
	return false;
}

void delete_all(item* root, int* arr, int num){
	for(int i=0; i<num; i++){
		traversal(root);
		if(delete_item(root, arr[i]))
			cout<<"delete success:"<<arr[i]<<endl;
		else
			cout<<"delete failure:"<<arr[i]<<endl;
	}
}

int main(){
	int arr[] = {12, 23, 4, 5, 8, 14, 9, 22, 15, 8};
	int num = sizeof(arr)/sizeof(int);
	item* root = create(arr,num);
	//traversal(root);
	delete_all(root, arr, num);
	return 0;
}


