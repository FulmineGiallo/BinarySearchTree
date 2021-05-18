
namespace lasd
{

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
  if(insert == nullptr)
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
  delete Detach(FindPointerTo(root, val));
}

// Min
template<typename Data>
const Data& BST<Data>::Min() const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un MIN in un albero vuoto.");
  else
    return FindPointerToMin(root)->element;
}

// MinNRemove
template<typename Data>
const Data& BST<Data>::MinNRemove()
{
  if(root != nullptr)
    return DataNDelete(DetachMin(root));
  else
    throw std::length_error("Non puoi rimuovere da un albero vuoto");
}

// RemoveMin
template<typename Data>
void BST<Data>::RemoveMin()
{
  if(root != nullptr)
    delete DetachMin(root);
  else
    throw std::length_error("Non puoi rimuovere da un albero vuoto");

}

// Max
template<typename Data>
const Data& BST<Data>::Max() const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un MAX in un albero vuoto.");
  else
  {
    return FindPointerToMax(root)->element;
  }

}

// MaxNRemove
template<typename Data>
const Data& BST<Data>::MaxNRemove()
{
  if(root != nullptr)
    return DataNDelete(DetachMax(root));
  else
    throw std::length_error("Non puoi rimuovere da un albero vuoto");
}

// RemoveMax
template<typename Data>
void BST<Data>::RemoveMax()
{
  if(root != nullptr)
    delete DetachMax(root);
  else
    throw std::length_error("Non puoi rimuovere da un albero vuoto");

}

// Predecessor
template<typename Data>
const Data& BST<Data>::Predecessor(const Data& val) const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un Predecessor in un albero vuoto.");
  else
  {
    NodeLnk *pre = FindPointerToPredecessor(root, val);
    if(pre == nullptr)
       throw std::length_error("Non esiste un Predecessor");
    else
      return pre->element;
  }


}

// PredecessorNRemove
template<typename Data>
const Data& BST<Data>::PredecessorNRemove(const Data& val){
  const Data& pre = Predecessor(val);
  Remove(pre);
  return pre;
}

// RemovePredecessor
template<typename Data>
void BST<Data>::RemovePredecessor(const Data& val){
  const Data& pre = Predecessor(val);
   Remove(pre);
}

// Successor
template<typename Data>
const Data& BST<Data>::Successor(const Data& val) const
{
  if(BinaryTreeLnk<Data>::Empty())
     throw std::length_error("Non esiste un Successor in un albero vuoto.");
  else
  {
    NodeLnk *pre = FindPointerToSuccessor(root, val);
    if(pre == nullptr)
       throw std::length_error("Non esiste un Successor");
    else
      return pre->element;
  }
}

// SuccessorNRemove
template<typename Data>
const Data& BST<Data>::SuccessorNRemove(const Data& val)
{
  const Data& suc = Successor(val);
  Remove(suc);
  return suc;
}

// RemoveSuccessor
template<typename Data>
void BST<Data>::RemoveSuccessor(const Data& val){
  const Data& suc = Successor(val);
  Remove(suc);
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
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& nodo) const noexcept
{
  if(nodo != nullptr)
  {
    if(nodo->left != nullptr)
      return FindPointerToMin(nodo->left);
  }
  return nodo;
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& nodo) const noexcept
{
  if(nodo != nullptr)
  {
    if(nodo->right != nullptr)
      return FindPointerToMax(nodo->right);
  }
  return nodo;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerToMin(NodeLnk*& nodo) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(nodo));
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerToMax(NodeLnk*& nodo) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(nodo));
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerTo(NodeLnk*& nodo,const Data& element) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(nodo,element));
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerToPredecessor(NodeLnk*& nodo, const Data& val) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(nodo, val));
}
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*&  BST<Data>::FindPointerToSuccessor(NodeLnk*& nodo, const Data& val) noexcept
{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(nodo, val));
}

/* ************************************************************************** */

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& nodo, const Data& val) const noexcept
{
    NodeLnk* const* pre = nullptr;
    NodeLnk* const* cur = &nodo;
    while(*cur != nullptr){
      if(val > (*cur)->element){
        pre = cur;
        cur = &((*cur)->right);
      }
      else{
        cur = &((*cur)->left);
      }
    }
    if(pre == nullptr)
      return *cur;
    else
      return *pre;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& nodo, const Data& val)  const noexcept
{
   NodeLnk* const* suc = nullptr;
   NodeLnk* const* cur = &nodo;
   while(*cur != nullptr)
   {
     if(val >= (*cur)->element){
       cur = &((*cur)->right);
     }
     else{
       suc = cur;
       cur = &((*cur)->left);
     }
   }
   if(suc == nullptr)
     return *cur;
   return *suc;

}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& root) noexcept
{
  if(root != nullptr){
    if(root->left == nullptr){
      return SkipOnRight(root);
    }
    else if(root->right == nullptr){
      return SkipOnLeft(root);
    }
    else{
      NodeLnk* massimo = DetachMax(root->left);
      std::swap(root->element, massimo->element);
      return massimo;
    }
  }
  return nullptr;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::SkipOnRight(NodeLnk*& nodo) noexcept
{
  NodeLnk* rig = nullptr;
  if(nodo != nullptr)
  {
    std::swap(rig, nodo->right);
    std::swap(rig, nodo);
    --size;
  }
  return rig;
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::SkipOnLeft(NodeLnk*& nodo) noexcept
{
  NodeLnk* left = nullptr;
  if(nodo != nullptr)
  {
    std::swap(left, nodo->left);
    std::swap(left, nodo);
    --size;
  }
  return left;
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& nodo) noexcept
{
  return SkipOnLeft(FindPointerToMax(nodo));
}
template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& nodo) noexcept
{
  return SkipOnRight(FindPointerToMin(nodo));
}
template<typename Data>
Data BST<Data>::DataNDelete(NodeLnk* nodo)
{
  Data valore {};
  std::swap(valore, nodo->element);
  delete nodo;
  return valore;
}
}
