
#include <iostream>


/*
  We'll see Nodes only for internal use!
  External users must ignore Nodes existence for a better
    information hidyng implementation!  
*/
struct Node
{
  Node* left; 
  Node* right; 
  Node* parent;
  int key_value; 

  const Node& operator=(const Node& temp) {
    left = temp.left;
    right = temp.right; 
    parent = temp.parent; 
    key_value = temp.key_value; 
    return temp;
  }
 
  bool operator>(const Node& temp) const {
    return key_value > temp.key_value; 
  }

  bool operator<(const Node& temp) const {
    return key_value < temp.key_value; 
  }

  bool operator==(const Node& temp) const {
    return key_value == temp.key_value; 
  }


};


class Tree
{

public: 

  Node* root; 

  // PRIVATE INSERTION
  void  pr_ins(const int &k,  Node* leaf);

  // PRIVATE DELETION
  void  pr_del(const int &k, Node* leaf);


  // PRIVATE SEARCH
  Node* pr_src(const int &key, Node* leaf);

  // PRIVATE SUCCESSOR
  Node* pr_suc(const Node* leaf);

  // PRIVATE PREDECESSOR
  Node* pr_prd(const Node* leaf);


  // PRIVATE INORDER VISIT
  void  pr_Inorder(const Node* leaf)const;

  // PRIVATE POSTORDER VISIT
  void  pr_Postorder(const Node* leaf)const;

  // PRIVATE PREORDER VISIT
  void  pr_Preorder(const Node* leaf)const;


  /*
    For max and min we'll use two different function  
      'cause we both want to return nodes and values 
      in different situation
  */

  // PRIVATE MINIMUM
  
  int pr_min( Node* leaf)const;

  Node* pr_min_node( Node* leaf)const;

  // PRIVATE MAXIMUM
  int pr_max( Node* leaf)const;

  Node* pr_max_node( Node* leaf)const;

  // PRIVATE GET PARENT
  Node* pr_get_parent(const Node* leaf);
 


public:

  // NO-PARAMETER-CONSTRUCTOR 
  Tree();

  // INSERTION
  void  ins(const int &key); 

  // DELETION
  void  del(const int &key); 
  
  //SEARCH
  Node* src(const int &key) ;  

  // SUCCESSOR
  Node* suc(const int key);
  
  // PREDECESSOR
  Node* prd(const int key) ;

  // MINUMUM
  int min()const; 

  // MAXIMUM
  int max()const; 

  // INORDER VISIT
  void Inorder()const;

  // POSTORDER VISIT
  void Postorder()const;

  // PREORDER VISIT
  void Preorder()const;

  
  /*
    Also for parent we bot may want return values or nodes
  */
  int get_parent(const int &key);

};



