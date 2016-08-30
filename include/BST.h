#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <exception>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

namespace myalgo {
template<typename KeyT,typename ValueT>
class BST {
	
	private :
		
		struct node
		{
			KeyT key;
			ValueT value;
			node* left;
			node* right;
		};
		
		node* m_root;
	
	
	public :
	
	BST():m_root(NULL){};
	
	~BST() 
	{
		this->free(m_root);
	}
	
	node* CreateNode(KeyT key,ValueT value)
	{
		node* ptr = new node;
		ptr->key = key;
		ptr->value = value;
		ptr->left = ptr->right = NULL;
	}
	
	void insert(KeyT key,ValueT value)
	{
		node* n = CreateNode(key,value);
		m_root = insert_helper(m_root,n);
	}
	
	void print()
	{
		this->print_helper(this->m_root,0);
	}
	
	ValueT find_helper(node* ptr,KeyT key)
	{
		if(key < ptr->key )
			return find_helper(ptr->left,key);
		else if(key > ptr->key )
			return find_helper(ptr->right,key);
		else
			return ptr->value;
		
		return false;
	}
	
	ValueT find(KeyT key)
	{
		return find_helper(m_root,key);
	}
	
	void Delete(KeyT key)
	{
		
		this->delete_helper(m_root,key);
	}
	
	private :
	
	node* delete_helper(node* ptr,KeyT key)
	{
		if(ptr == NULL)
			return ptr;
		else if( key < ptr->key)
			ptr->left = delete_helper(ptr->left,key);
		else if( key > ptr->key)
			ptr->right = delete_helper(ptr->right,key);
		else
		{
		
			if(ptr->left == NULL && ptr->right == NULL)
			{
				delete ptr;
				ptr = NULL;
			}
			else if( ptr->left == NULL)
			{
				node* temp = ptr;
				ptr = ptr->right;
				delete temp;
				temp = NULL;
			}
			else if( ptr->right == NULL)
			{
				node* temp = ptr;
				ptr = ptr->left;
				delete temp;
				temp = NULL;
			}
			else
			{
				node* minimum = min(ptr->right);
				ptr->key = minimum->key;
				ptr->value = minimum->value;
				ptr->right = delete_helper(ptr->right,minimum->key);
			}
		}
		return ptr;
	}
	
	node* min(node* ptr)
	{
		while(ptr->left != NULL)
		{
			ptr = ptr->left;
		}
		return ptr;
	}
	
	node* insert_helper(node* ptr,node* n)
	{
		if(ptr == NULL)
			return n;
		else if(n->key <= ptr->key)
			ptr->left = insert_helper(ptr->left,n);
		else 
			ptr->right = insert_helper(ptr->right,n);
		return ptr;	
	}
	
	void print_helper(node* ptr,int indend)
	{
		if(ptr == NULL)	return;
		print_helper(ptr->right,indend+1);
		for(int i = 0; i < indend ;i++)
		cout<<"*";
		cout <<"["<<ptr->key<<":"<<ptr->value<<"]"<<endl;
		print_helper(ptr->left,indend+1);
	}
	
	void free(node* ptr)
	{
		if(ptr == NULL)	return;
		free(ptr->left);
		free(ptr->right);
		delete ptr;
	}

	};//end of BST

} //end of myalgo
#endif
