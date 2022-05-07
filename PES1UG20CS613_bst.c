// Name: Vivian Rodriguez
// SRN: PES1UG20CS613
#include "bst.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
*/

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst -> root = NULL;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
void insert(bst_t *tree, int key, int *count_ptr)
{
     tree->root=(node_t*)malloc(sizeof(node_t));
	     
      if(tree->root == NULL)  
    {  
        
        tree->root->key = key;  
        tree->root->left = NULL;  
        tree->root->right = NULL;  
    } 
    else   
    {   
        node_t *temp = (node_t*)malloc(sizeof(node_t));
		temp->left=temp->right=NULL;
        node_t *p;
        node_t *q;   
        temp->key = key;
        q=NULL;
		p=tree->root;
        while(p!=NULL) //find the node pos to attach
		{
			q=p;
			if(temp->key<p->key)	
				{
                    p=p->left;
                    (*count_ptr)++;
                }
			else
				{
                    p=p->right;
                    (*count_ptr)++; 
                }
		}
		if(temp->key<q->key) //attach the new node
			{
                q->left=temp;
                (*count_ptr)++;
            }
		else
			{
                q->right=temp;	
                (*count_ptr)++;    
            }
    }
}

// Delete key from the BST
// Replaces node with in-order successor
static node_t* del_node(node_t *r,int ele, int *c)
{
	
    node_t* temp;
    node_t *p;
	if(r==NULL) {
         (*c)++;
         return r;
    }
	else if(ele<r->key)
		{
            
            r->left=del_node(r->left,ele,&c);
            (*c)++;

        }
	else if(ele>r->key)
		{
            r->right=del_node(r->right,ele,&c);
            (*c)++;
        }
	else
	{
		if(r->left==NULL)
		{
			(*c)++;
            temp=r->right;
			free(r);
			return temp;
			
		}
		else if(r->right==NULL)
		{
			(*c)++;
            temp=r->left;
			free(r);
			return temp;
		}
		else
		{
			p=r->right;
			while(p->left!=NULL) //inorder successor
			{
				p=p->left;
			}
			r->key=p->key;
			r->right=del_node(r->right,p->key,&c);
            (*c)++;
		}
	}
	return r;
}
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    int c;
    tree->root=del_node(tree->root,ele,&c);
    
}

// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr)
{
    int f,c;
    f = -1;
    node_t *find;
    if (find == NULL || find->key == key)
       {
           
           f = find->key;
       }
    
    // Key is greater than root's key
    if (find->key < key)
       {
           
            search(find->right, key, &count_ptr);
            (*count_ptr)++;
       }    
 
    // Key is smaller than root's key
       search(find->left, key, &count_ptr);
       (*count_ptr)++;

    return f;    


}

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    node_t *p= tree->root;
	while(p->right!=NULL)
	{
		p=p->right;
        (*count_ptr)++;
	}
	return p->key;
}

// Deletes all the elements of the bst
static void free_tree(node_t *node)
{
    if(node==NULL)return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}
void free_bst(bst_t *bst) 
{
    free_tree(bst->root);
    free(bst);
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
    free_tree(bst->root);
}
