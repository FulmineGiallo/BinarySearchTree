
namespace lasd {

/* ************************************************************************** */

template<typename Data>
BST<Data>::BST(const LinearContainer<Data>& container)
{
  for(unsigned long i = 0; i < container.Size(); i++)
    Insert(container[i]);

}

// Copy constructor
template<typename Data>
BST<Data>::BST(const BST<Data>& tree):BinaryTreeLnk<Data>::BinaryTreeLnk(tree) {}

// Move constructor
template<typename Data>
BST<Data>::BST(BST<Data>&& tree) noexcept : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(tree)) {}

// Copy assignment
template<typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& tree)
{
  BinaryTreeLnk<Data>::operator=(tree);
  return *this;
}

// Move assignment
template<typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& tree) noexcept
{
  BinaryTreeLnk<Data>::operator=(std::move(tree));
  return *this;
}


// Operator == DONE
template<typename Data>
bool BST<Data>::operator==(const BST<Data>& tree) const noexcept
{
  if(size != tree.size)
    return false;
  if(size == 0)
    return true;
  else
  {
    BTInOrderIterator<Data> it1(*this);
    BTInOrderIterator<Data> it2(tree);
    bool ret = false;
    ret = true;
    while(!it1.Terminated() && ret)
    {
      if(*it1 != *it2)
        ret = false;
      ++it1;
      ++it2;
    }
    return ret;
  }
}

// Operator !=
template<typename Data>
bool BST<Data>::operator!=(const BST<Data>& tree) const noexcept
{
  return !(*this == tree);
}

// Insert (Copy)
template<typename Data>
void BST<Data>::Insert(const Data& val)
{
  NodeLnk*& insert = FindPointerTo(root, val);
  if(insert == nullptr)
  {
    insert = new typename BinaryTreeLnk<Data>::NodeLnk(val);
    size++;
  }
}

// Insert (Move)
template<typename Data>
void BST<Data>::Insert(Data&& val) noexcept
{
  NodeLnk*& insert = FindPointerTo(root, val);
  if(&(insert) == nullptr)
  {
    insert = new typename BinaryTreeLnk<Data>::NodeLnk();
    insert->Element() = std::move(val);
    size++;
  }
}

// Remove
template<typename Data>
void BST<Data>::Remove(const Data val)
{

}

// Min
template<typename Data>
const Data& BST<Data>::Min() const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un MIN in un albero vuoto.");
  else
  {
    
  }
}

// MinNRemove
template<typename Data>
Data& BST<Data>::MinNRemove()
{
  Min();
}

// RemoveMin
template<typename Data>
void BST<Data>::RemoveMin()
{
  Min();
}

// Max
template<typename Data>
const Data& BST<Data>::Max() const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un MAX in un albero vuoto.");
}

// MaxNRemove
template<typename Data>
Data& BST<Data>::MaxNRemove()
{

}

// RemoveMax
template<typename Data>
void BST<Data>::RemoveMax()
{

}

// Predecessor
template<typename Data>
const Data& BST<Data>::Predecessor(const Data& val) const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un Predecessor in un albero vuoto.");
}

// PredecessorNRemove
template<typename Data>
Data& BST<Data>::PredecessorNRemove(const Data& val){

}

// RemovePredecessor
template<typename Data>
void BST<Data>::RemovePredecessor(const Data& val){

}

// Successor
template<typename Data>
const Data& BST<Data>::Successor(const Data& val) const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un Successor in un albero vuoto.");
}

// SuccessorNRemove
template<typename Data>
Data& BST<Data>::SuccessorNRemove(const Data& val){

}

// RemoveSuccessor
template<typename Data>
void BST<Data>::RemoveSuccessor(const Data& val){

}

// Exists
template<typename Data>
bool BST<Data>::Exists(const Data& val) const noexcept
{
    return (FindPointerTo(root, val) != nullptr);
}

//FindPointerTo
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& nodo,const Data& element) const noexcept
{
  /*
   Element > nodo.Element(); --> cerco a destra
   Element < nodo.Element(); --> cerco a sinistra
   Per usare il FindPointerTo nell'insert, questo metodo, deve restuire il nodo dove dopo, posso attaccare un altro nodo.
   Per usare il FindPointerTo nell'remove, questo metodo, se è diverso da nullptr, allora elimino, altrimenti nulla.
  */
  if(nodo != nullptr)
  {
    if(element != nodo->element)
    {
      if(element < nodo->element)
        return FindPointerTo(nodo->left, element);
      if(element > nodo->element)
        return FindPointerTo(nodo->right, element);
    }
  }
  return nodo;

}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerTo(NodeLnk* const& nodo,const Data& element) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(nodo,element));
}

/* ************************************************************************** */
// template <typename Data>
// typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& nodo)
// {
//   // NodeLnk* ret = nodo;
//   //
//   // if(ret->HasLeftChild())
//   //     ret = FindPointerToMin(nodo->LeftChild());
//   // return ret;
// }
// template <typename Data>
// typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& nodo)
// {
//   // NodeLnk* ret = nodo;
//   //
//   // if(ret->HasRightChild())
//   //     ret = FindPointerToMin(nodo->RightChild());
//   // return ret;
// }
// template<typename Data>
// typename BinaryTreeLnk<Data>::NodeLnk& BST<Data>::FindPointerToPredecessor(const NodeLnk root, const Data& item)
// {
//   // static NodeLnk* ret = nullptr;
//   // if(root->Element() < item){
//   //   if(root->HasRightChild()) ret = FindPointerToPredecessor(root->RightChild(), item);
//   //   if(ret == nullptr) ret = root;
//   // }
//   // if(root->Element() > item){
//   //   if(root->HasLeftChild()) ret = FindPointerToPredecessor(root->LeftChild(), item);
//   // }
//   // return ret;
// }
//
// template<typename Data>
// typename BinaryTreeLnk<Data>::NodeLnk& BST<Data>::FindPointerToSuccessor(const NodeLnk root, const Data& item){
//   // static NodeLnk* ret = nullptr;
//   // if(root->Element() > item){
//   //   if(root->HasLeftChild()) ret = FindPointerToSuccessor(root->LeftChild(), item);
//   //   if(ret == nullptr) ret = root;
//   // }
//   // if(root->Element() < item){
//   //   if(root->HasRightChild()) ret = FindPointerToSuccessor(root->RightChild(), item);
//   // }
//   // return ret;
// }
}
