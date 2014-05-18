#include <iostream>
#include "BST.cpp"


int main()
{

  std::cout << "======INSERTION====== " << std::endl;


  std::cout << " /******************************/ " << std::endl;
  std::cout << " T CREATION " << std::endl;

  Tree T;

  std::cout << " /******************************/ " << std::endl;
  std::cout << " T INSERTION 6 " << std::endl;
  T.ins(6);

  std::cout << " /******************************/ " << std::endl;
  std::cout << " T INSERTION 4 " << std::endl;
  T.ins(4);

  std::cout << " /******************************/ " << std::endl;
  std::cout << " T INSERTION 7 " << std::endl;

  T.ins(7);

  std::cout << " /******************************/ " << std::endl;
  std::cout << " T INSERTION 5 " << std::endl;

  T.ins(5);

  std::cout << " /******************************/ " << std::endl;
  std::cout << " T INSERTION 8 " << std::endl;

  T.ins(8);

  std::cout << " /******************************/ " << std::endl;
  std::cout << " T INSERTION 3 " << std::endl;

  T.ins(3);

  std::cout << " /******************************/ " << std::endl;






  std::cout << "======ASSERTION====== " << std::endl;


  std::cout << " T.root->key_value " << std::endl;
  std::cout << T.root->key_value << std::endl;

  std::cout << " T.root->left->key_value " << std::endl;
  std::cout << T.root->left->key_value << std::endl;

  std::cout << " T.root->right->key_value " << std::endl;
  std::cout << T.root->right->key_value << std::endl;

  std::cout << " T.root->left->parent->key_value " << std::endl;
  std::cout << T.root->left->parent->key_value << std::endl;

  std::cout << " T.root->right->parent->key_value " << std::endl;
  std::cout << T.root->right->parent->key_value << std::endl;



  std::cout << "======INORDER VISIT====== " << std::endl;

  T.Inorder();




  std::cout << "======GET PARENT====== " << std::endl;

  std::cout << " T.get_parent(3) " << std::endl;
  std::cout << T.get_parent(3) << std::endl;

  std::cout << " T.pr_get_parent(T.src(3))->left->key_value " << std::endl;
  std::cout << T.pr_get_parent(T.src(3))->left->key_value <<std::endl;

  std::cout << " T.pr_get_parent(T.src(3))->right->key_value " << std::endl;
  std::cout << T.pr_get_parent(T.src(3))->right->key_value <<std::endl;



  std::cout << "======SEARCH====== " << std::endl;

  std::cout << " if(T.src(7)!=NULL) " << std::endl;
  if(T.src(7)!=NULL)
    std::cout << " FOUND " << std::endl;

  std::cout << " if(T.src(3)!=NULL) " << std::endl;
  if(T.src(3)!=NULL)
    std::cout << " FOUND " << std::endl;



  std::cout << "======SUCCESSOR====== " << std::endl;


    std::cout << "T.suc(4)->key_value" << std::endl;

    std::cout << T.suc(4)->key_value << std::endl;


    std::cout << "T.suc(5)->key_value" << std::endl;

    std::cout << T.suc(5)->key_value << std::endl;


    std::cout << "T.suc(7)->key_value" << std::endl;

    std::cout << T.suc(7)->key_value << std::endl;


    std::cout << "T.suc(3)->key_value" << std::endl;

    std::cout << T.suc(3)->key_value << std::endl;



  std::cout << "======PREDECESSOR====== " << std::endl;


    std::cout << "T.prd(6)->key_value" << std::endl;

    std::cout << T.prd(6)->key_value << std::endl;



    std::cout << " insertion of 20 , 10 , 15, 13, 14, 9 " << std::endl;

  T.ins(20);

  T.ins(10);

  T.ins(15);

  T.ins(13);

  T.ins(14);

  T.ins(9);

  std::cout << " Inorder " << std::endl; 

  T.Inorder();

  std::cout << " Preorder " << std::endl; 

  T.Preorder();



  std::cout << "======DELETE====== " << std::endl;

  std::cout << " delete 10 " << std::endl;

  T.del(10);

  std::cout << " Inorder " << std::endl;

  T.Inorder();

  std::cout << " delete 9 " << std::endl;

  T.del(9);

  std::cout << " main after delete " << std::endl;

  T.Inorder();

  std::cout << " delete 15 " << std::endl;

  T.del(15);

  T.Inorder();

  std::cout << " deleting root " << std::endl;

  T.del(6);

  T.Inorder();


}

