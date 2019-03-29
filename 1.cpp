#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node* parent;
	node(int value){
		data=value;
		left=NULL;
		right=NULL;
		parent=NULL;
	}
};
class BST{
public:
	node* root;
	BST(){
		root=NULL;
	}
	void insertHelper(int value){
		insert(root,value);
	}
	void insert(node* curr,int value){
		//Base case if curr is NULL ,insert there
		if(root==NULL){
			 root =new node(value) ;                                                                      
			return;
		}
		//Else compare the curr data with value
		else if (value  <  curr->data){
		//if curr data > value ==> move right and call insert
			if(curr->left==NULL){
					curr->left=new node(value);
					curr->left->parent=curr;}
			else
				insert(curr->left,value);
		}
		else{	
		//else move right and call insert
			if(curr->right==NULL){
				curr->right=new node(value);
				curr->right->parent=curr;}	
			else
				insert(curr->right,value);
		}
		
	}
	void displayHelper(){
		display(root);cout<<endl;
	}
	void display(node * curr){
		if (curr == NULL) return;
		//display left
		display(curr->left);
		//display current
		cout<<curr->data<<",";
		//display right
		display(curr->right);
	}
	node* searchHelper(int no){
	return search(root,no);
	}
	node* search(node * curr, int value){
			if (curr == NULL || curr->data == value) return curr;
			else if (value < curr->data)
				//search for number in left
				return search(curr->left,value);
				//search number in right
			else 
				return search(curr->right,value);
	}
	int count(){
		int cou=0;cou=count2(root,cou);return cou;
	}
	int count2(node * curr,int i){
		
		if (curr == NULL) {return i;}
		else{	
			i=count2(curr->left,i);
			i++;
			i=count2(curr->right,i);
		}
		return i;
	}
	int height(node * curr){
		
		if (curr == NULL) {
			return 0;
		}
		int l=height(curr->left);
		int r=height(curr->right);
		if(l>r)
			return 1+l;
		else
		{
			return 1+r;
		}
		
	}
	int range_search_Helper(int a,int b){
		int cou=0;
		cout<<"Number between K1 and K2 : ";
		cou=range_search(root,a,b,0);cout<<"Number of node between K1 and K2 :";return cou;
	}
	int range_search(node * curr,int k1, int k2,int i){
		if (curr == NULL) return i;
		//display left
		i= range_search(curr->left,k1,k2,i);
		if(curr->data>=k1 && curr->data<=k2){
		//display current
		i++;
		cout<<curr->data<<",";
		}
		//display right
		i= range_search(curr->right,k1,k2,i);
		return i;
	}
	void print2DUtil(node*root, int space){  
        // Base case  
        if (root == NULL){ 
            return ; }  
        // Increase distance between levels  
        space += 5;  
        // Process right child first  
        print2DUtil(root->right, space);  
    	// Print current node after space  
        // count  
        cout<<endl;  
        for (int i = 5; i < space; i++)  
            cout<<" ";  
        cout<<root->data<<"\n";  
    	// Process left child  
        print2DUtil(root->left, space);  
	}  
	// Wrapper over print2DUtil()  
	void print2D(){
		// Pass initial space count as 0
		if (root == NULL){ 
           cout<<"NULL"<<endl; return;
		} 	  
		print2DUtil(root, 0);  
		cout << endl;
	}
};


int main(){
    BST bst1;
    bst1.insertHelper(4);
    bst1.insertHelper(2);
    bst1.insertHelper(3);
    bst1.insertHelper(1);
	bst1.insertHelper(6);
    bst1.insertHelper(5);
    bst1.insertHelper(7);
	bst1.insertHelper(8);
	bst1.displayHelper();
    if(bst1.searchHelper(3) != NULL){
        cout << endl << bst1.searchHelper(3)->data << endl;
    }
	bst1.print2D();
	cout<<"Total number of nodes : "<<bst1.count()<<endl;
	cout<<bst1.range_search_Helper(2,6)<<endl;
	cout<<"Height ;"<<bst1.height(bst1.root)<<endl;
}
