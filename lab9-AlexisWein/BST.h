#ifndef __BST_H__
#define __BST_H__

#include "BSTNode.h"
#include <iostream>
#include <vector>

namespace ds {

template <typename E> class BST {
private:
  BSTNode<E> *root; // Root of the BST

  void clear(BSTNode<E> *root) {
    if (root == NULL)
      return;
    clear(root->left());
    clear(root->right());
    delete root;
  }

  BSTNode<E> *insertHelp(BSTNode<E> *root, E e) {
    if (root == NULL)
      return new BSTNode<E>(e);
    if (e < root->element())
      root->setLeft(insertHelp(root->left(), e));
    else
      root->setRight(insertHelp(root->right(), e));
    return root;
  }

  void simplePrintHelp(BSTNode<E> *root) const {
    if (root == NULL)
      return;
    std::cout << root->element();
    simplePrintHelp(root->left());
    simplePrintHelp(root->right());
  }

  BSTNode<E> *getmin(BSTNode<E> *root){
    if(root->left() == NULL)
      return root;
    else
      return getmin(root->left());    
  }

  BSTNode<E> *deletemin(BSTNode<E> *root){
    if(root->left() == NULL)      //found min
      return root->right();
    else
    {
      root->setLeft(deletemin(root->left()));
      return root;
    }
  }

  E findhelp(BSTNode<E> *root, const E e) const{
    if (root == NULL)
      return false; // Empty tree
    if (e < root->element())
      return findhelp(root->left(), e); // Check left
    else if (e > root->element())
      return findhelp(root->right(), e); // Check right
    else if (e == root->element())
      return root->element(); // Found it
    else                      //the number to be found is not in the BST
      return false;
  }

  //E removehelp(BSTNode<E> *root, const E e){
  BSTNode<E> *removehelp(BSTNode<E> *root, const E e){
    if (root == NULL)
      return root;                      // k is not in tree
    else if (e < root->element())
      root->setLeft(removehelp(root->left(), e));
      //return root->setLeft(removehelp(root->left(), e));
    else if (e > root->element())
      root->setRight(removehelp(root->right(), e));
      //return root->setRight(removehelp(root->right(), e));
    else                          // Found: remove it
    {
      BSTNode<E>* temp = root;
      if (root->left() == NULL)     // Only a right child
      {
        root = root->right();         //  so point to right
        delete temp;
      }
      else if (root->right() == NULL)     // Only a left child 
      {
        root = root->left(); // so point to left
        delete temp;
      }
      else      // Both children are non-empty
      {
        BSTNode<E>* temp = getmin(root->right());
        root->setElement(temp->element());
        root->setElement(temp->element());
        root->setRight(deletemin(root->right()));
        delete temp;
      }
    }
    return root;
  }

public:
  BST() : root(NULL) {}
  ~BST() { clear(root); }

  void simplePrint() const {
    // print using preorder traversal
    simplePrintHelp(root);
  }

  void insert(const E e) { root = insertHelp(root, e); }

  bool find(E e) const;
  void remove(const E e);
  void printLevelByLevel() const;
};

template <typename E> bool BST<E>::find(E e) const {
  // TODO: return true if `e` is in the binary search tree
  return findhelp(root, e);
}

template <typename E> void BST<E>::remove(const E e) {
  // TODO: remove `e` from the binary search tree; do nothing if `e` is not in
  // the tree
  E temp = findhelp(root, e);
  //std::cout << "Remove test" << std::endl;                         //debugging statement
  if (temp != NULL)
  {
    //std::cout << "Remove if statement test" << std::endl;          //debugging statement
    removehelp(root, e);
  }
}

template <typename E> void BST<E>::printLevelByLevel() const {
  // TODO: print the binary search tree level by level, from top to bottom and
  // left to right; do not print space between values
  if(root == NULL)
    return;
  std::vector<BSTNode<E> *> q;
  q.push_back(root);
  //std::cout << "root test: " << root->element() << std::endl;             //debugging statement


  //int sizeTest = q.size();
  //std::cout << "sizeTest before loop: " << sizeTest << std::endl;         //debugging statement
  while(!q.empty())
  {
    //std::cout << "sizeTest: " << sizeTest << std::endl;
    std::cout << "While loop test" << std::endl;
    int size = q.size();
    //std::cout << "int size test: " << size << std::endl;
    for(int i = 0; i <= size - 1; i++)
    {
      BSTNode<E>* node = q.front();
      std::cout << "node test: " << node->element();
      std::cout << node->element();
      q.erase(q.begin());
      if(node->left() != NULL)
        q.push_back(node->left());
      if(node->right() != NULL)
        q.push_back(node->right());
    }
    //sizeTest--;
  }
}

} // namespace ds

#endif // __BST_H__