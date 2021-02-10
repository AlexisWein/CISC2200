#ifndef __BSTNODE_H__
#define __BSTNODE_H__

namespace ds {

template <typename E> class BSTNode {
private:
  E it;
  BSTNode *lc;
  BSTNode *rc;

public:
  BSTNode(E e, BSTNode *l = nullptr, BSTNode *r = nullptr)
      : it(e), lc(l), rc(r) {}
  ~BSTNode() {}
  E &element() { return it; }
  void setElement(const E &e) { it = e; }
  inline BSTNode *left() const { return lc; }
  void setLeft(BSTNode<E> *b) { lc = (BSTNode *)b; }
  inline BSTNode *right() const { return rc; }
  void setRight(BSTNode<E> *b) { rc = (BSTNode *)b; }
  bool isLeaf() { return (lc == nullptr) && (rc == nullptr); }
};

} // namespace ds

#endif // __BSTNODE_H__