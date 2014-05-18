
#include "BST.h"

/****************************************/
/*           CONSTRUCTOR                */
/****************************************/

Tree::Tree()
{
  root = NULL; 
}



/****************************************/
/*             PREDECESSOR              */
/****************************************/


Node* Tree::prd(const int key)
{
  return  pr_prd(src(key));
}


Node* Tree::pr_prd(const Node* leaf)

{

  if(leaf->left!=NULL)
    return pr_max_node(leaf->left);

  else{
    Node* P = pr_get_parent(leaf);
    while(P!=NULL && leaf==P->left){
      leaf = P;
      P = pr_get_parent(P);
    }
    return P;
  }  
}




/****************************************/
/*             SUCCESSOR                */
/****************************************/

Node* Tree::suc(const int key)
{
  return  pr_suc(src(key));
}


Node* Tree::pr_suc(const Node* leaf)
{

  if(leaf->right!=NULL)
    return pr_min_node(leaf->right);

  else{
    Node* P = pr_get_parent(leaf);
    while(P!=NULL && leaf==P->right){
      leaf = P;
      P = pr_get_parent(P);
    }
    return P;
  }  
}

/****************************************/
/*             INSERT                   */
/****************************************/

void Tree::ins(const int &key)
{
  std::cout << " INS " << std::endl;
  if(root!=NULL)
    pr_ins(key, root);
  else if(root==NULL)
    {
      root = new Node;
      root->left = NULL;
      root->right = NULL; 
      root->parent = NULL; 
      root->key_value = key;
    }  

  std::cout << " Insert Key  " << key << std::endl;
  std::cout << " END INS " << std::endl;


}

void Tree::pr_ins(const int &key,  Node* leaf)
{
  std::cout << " PR_INS " << std::endl;

  if(key < leaf->key_value)
    {
      std::cout << " Left " << std::endl;

      if(leaf->left!=NULL){
	std::cout << " left aaaaaaaa" << std::endl;
	pr_ins(key, leaf->left);}

      else if(leaf->left == NULL){
	std::cout << " left bbbbbbbb"  << std::endl;
	leaf->left=new Node;
	leaf->left->key_value=key;
	leaf->left->left=NULL;   
	leaf->left->right=NULL; 
	leaf->left->parent = leaf;
      }  
    }


  else if(key > leaf->key_value)
    {
      std::cout << " Right " << std::endl;

      if(leaf->right!=NULL){
	std::cout << " Right aaaaaaaa" << std::endl;
	pr_ins(key, leaf->right);}


      else if(leaf->right==NULL){
	std::cout << " Right bbbbbbbb" << std::endl;
	leaf->right=new Node;
	leaf->right->key_value=key;
	leaf->right->left=NULL;  
	leaf->right->right=NULL; 
	leaf->right->parent = leaf;
      }
    }
  std::cout << " END PR_INS " << std::endl;
}



/****************************************/
/*             DELETE                   */
/****************************************/

void Tree::del(const int &key)
{
  return pr_del(key, root);
}

void Tree::pr_del(const int &k, Node* leaf)
{
  if(leaf!=NULL)
    {

      if(k<leaf->key_value){
        pr_del(k, leaf->left);
      }// END IF<

      if(k>leaf->key_value){
        pr_del(k, leaf->right);
      }//END IF>

    
      if(k==leaf->key_value){

	/*
	  Case 1: if both children of leaf are NULL 
	  I just delete it.
	*/
	if(leaf->right == NULL && leaf->left == NULL){ 
	  std::cout << " CASE 1 " << std::endl;
	  // If leaf is the left child of its father
	  if(leaf==pr_get_parent(leaf)->left)
	    {
	      std::cout << " leaf is the left child of its father " << std::endl;
	      std::cout << pr_get_parent(leaf)->key_value << std::endl; 
	      pr_get_parent(leaf)->left = NULL;
	    }
	  // If leaf is the right child of its father
	  else  if(leaf==pr_get_parent(leaf)->right)
	    {
	      std::cout << " leaf is the right child of its father " << std::endl;
	      std::cout << pr_get_parent(leaf)->key_value; 
	      pr_get_parent(leaf)->right = NULL;
	      std::cout << " NULL " << std::endl;
	    }
	  std::cout << " delete leaf " << std::endl;
	  delete leaf;
	  std::cout << " after delete leaf "<< std::endl;
	}// END CASE 1

     
	/*
	  Case 2: leaf has just one child
	*/

	// If the right child is not NULL
	else if(leaf->right!=NULL && leaf->left==NULL){
	  std::cout << " CASE 2.1 " << std::endl;
	  // And leaf is the left child
	  if(leaf==pr_get_parent(leaf)->left)
	    // I connect parent's left child with leaf's right child
	    pr_get_parent(leaf)->left=leaf->right; 
	  // Or And leaf is the right child
	  if(leaf==pr_get_parent(leaf)->right)
	    // I connect parent's right child with leaf's right child
	    pr_get_parent(leaf)->right=leaf->right; 
	  delete leaf;
	}// END FIRST IF CASE 2


	// If the left child is not NULL
	else if(leaf->left!=NULL && leaf->right == NULL){
	  std::cout << " CASE 2.2 " << std::endl;
	  // And leaf is the left child
	  if(leaf==pr_get_parent(leaf)->left)
	    // I connect parent's left child with leaf's left child
	    pr_get_parent(leaf)->left=leaf->left;
	  // Or And leaf is the right child
	  if(leaf==pr_get_parent(leaf)->right)
	    // I connect parent's right child with leaf's left child   
	    pr_get_parent(leaf)->right=leaf->left;
	}// END SECOND IF CASE 2  
  

	/*
	  Case 3: both of leaf's children aren't NULL, so I have to find leaf's successor and:
	  -connect leaf's successor's right child ( it can only have right child, otherwise it wouldn't
	  be leaf's actual successor) with leaf's successor's parent
	  -swap leaf and successor ( successor's leaf's left and right child 
	  can be successor's children)
	  -delete leaf
	*/

	else  if(leaf->left!=NULL && leaf->right!=NULL){
	  std::cout << " CASE 3 " << std::endl;

	  Node* temp = pr_suc(leaf);
	  std::cout << temp->key_value << std::endl; 

	  //connect leaf's successor's right child with leaf's successor's parent
          pr_get_parent(temp)->left = temp->right;

	  std::cout << temp->key_value << std::endl; 

	  leaf->key_value = temp->key_value;

	  std::cout << temp->key_value << std::endl;      

	  delete temp;     

	}// END CASE 3  
  
      }//END IF ==


    }// END   if(leaf!=NULL)
  
}// END FUNCTION


/****************************************/
/*             SEARCH                   */
/****************************************/


Node* Tree::src(const int &key)
{
  return pr_src(key, root);
}


Node* Tree::pr_src(const int &key,  Node* leaf)
{
  std::cout << " src " << std::endl;
  if(leaf!=NULL){

    if(leaf->key_value == key)
      return leaf; 

    else if(key < leaf->key_value){
      std::cout << " src left " << std::endl;
      return pr_src(key, leaf->left);}

    else if(key > leaf->key_value){
      std::cout << " src right " << std::endl;
      return pr_src(key, leaf->right);} 
  }
  
  return NULL; 
}


/****************************************/
/*            MAX MIN                   */
/****************************************/


int Tree::max()const
{
  return pr_max(root);
}

/****************************************/

int Tree::pr_max(Node* leaf)const
{
  Node* temp1 = leaf;
  Node* temp2 = temp1;  
  while(temp1!=NULL)
    {
      temp2 = temp1;    
      temp1=temp1->right;
    }
  return temp2->key_value; 
}

/****************************************/

Node* Tree::pr_max_node( Node* leaf)const
{
  Node* temp1 = leaf;
  Node* temp2 = temp1;  
  while(temp1!=NULL)
    {
      temp2 = temp1;    
      temp1=temp1->right;
    }
  return temp2; 
}

/****************************************/
/****************************************/

int Tree::min()const
{
  return pr_min(root);
}

/****************************************/

int Tree::pr_min( Node* leaf)const
{
  Node* temp1 = leaf;
  Node* temp2 = temp1; 
  while(temp1!=NULL){
    temp2=temp1; 
    temp1=temp1->left;
  }
  return temp2->key_value; 
}

/****************************************/

Node* Tree::pr_min_node(Node* leaf)const
{
  Node* temp1 = leaf;
  Node* temp2 = temp1; 
  while(temp1!=NULL){
    temp2=temp1; 
    temp1=temp1->left;
  }
  return temp2; 
}



/****************************************/
/*            INORDER                   */
/****************************************/

void Tree::Inorder()const
{
  pr_Inorder(root);
}

void Tree::pr_Inorder(const Node* leaf)const 
{
  if(leaf!=NULL){
    pr_Inorder(leaf->left);
    std::cout << leaf->key_value << std::endl;
    pr_Inorder(leaf->right);
  }
}


/****************************************/
/*            PREORDER                  */
/****************************************/

void Tree::Preorder()const
{
  pr_Preorder(root);
}

void Tree::pr_Preorder(const Node* leaf)const
{
  if(leaf!=NULL){
    std::cout << leaf->key_value << std::endl;
    pr_Preorder(leaf->left);
    pr_Preorder(leaf->right);
  }
}


/****************************************/
/*           POSTORDER                  */
/****************************************/

void Tree::Postorder()const
{
  pr_Postorder(root);
}

void Tree::pr_Postorder(const Node* leaf)const
{
  if(leaf!=NULL){
    pr_Postorder(leaf->left);
    pr_Postorder(leaf->right);
    std::cout << leaf->key_value << std::endl;
  }
}


/****************************************/
/*           GET PARENT                 */
/****************************************/


int Tree::get_parent(const int &key)
{ 
  std::cout << " get_parent 1" << std::endl;
  return src(key)->parent->key_value;
}


Node* Tree::pr_get_parent(const Node* leaf)
{
  std::cout << " pr_get_parent 1 " << std::endl;
  return src(leaf->key_value)->parent;
}
 
