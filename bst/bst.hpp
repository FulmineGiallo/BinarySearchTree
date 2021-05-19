
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public BinaryTreeLnk<Data>  { // Must extend BinaryTreeLnk<Data>

private:

  // ...

protected:

  using typename BinaryTreeLnk<Data>::NodeLnk;
  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  // ...

public:

  // Default constructor
  // BST() specifiers;
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers;
  // A bst obtained from a LinearContainer
  BST(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;
  BST(const BST&);

  // Move constructor
  // BST(argument) specifiers;
  BST(BST&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;
  ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BST& operator=(const BST<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BST& operator=(BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BST<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BST<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers;
  // Copy of the value
  void Insert(const Data&);

  // type Insert(argument) specifiers;
  // Move of the value
  void Insert(Data&&) noexcept;

  // type Remove(argument) specifiers;
  void Remove(const Data);

  // type Min(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  const Data& Min() const;

  // type MinNRemove(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  Data MinNRemove();

  // type RemoveMin(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  void RemoveMin();

  // type Max(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  const Data& Max() const;

  // type MaxNRemove(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  Data MaxNRemove();

  // type RemoveMax(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  void RemoveMax();

  // type Predecessor(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  const Data& Predecessor(const Data&) const;

  // type PredecessorNRemove(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  Data PredecessorNRemove(const Data&);

  // type RemovePredecessor(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  void RemovePredecessor(const Data&);

  // type Successor(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  const Data& Successor(const Data&) const;

  // type SuccessorNRemove(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  Data SuccessorNRemove(const Data&);

  // type RemoveSuccessor(argument) specifiers;
  // (concrete function must throw std::length_error when empty)
  void RemoveSuccessor(const Data&);

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers;
  // Override TestableContainer member
  bool Exists(const Data&) const noexcept override;

protected:

  // Auxiliary member functions
  // Data DataNDelete(NodeLnk*);


  NodeLnk*  Detach(NodeLnk*&) noexcept;
  NodeLnk* DetachMin(NodeLnk*&) noexcept;
  NodeLnk*  DetachMax(NodeLnk*&) noexcept;

  NodeLnk*  SkipOnLeft(NodeLnk*&)  noexcept;
  NodeLnk* SkipOnRight(NodeLnk*&) noexcept;

  /* FIND POINTER TO MIN */
  NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept;
  NodeLnk* const& FindPointerToMin(NodeLnk* const&)  const noexcept;
  /* FIND POINTER TO MAX */
  NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept;
  NodeLnk* const& FindPointerToMax(NodeLnk* const&)  const noexcept;
  /* FIND POINTER TO*/
  NodeLnk* const& FindPointerTo(NodeLnk* const&, const Data&)  const noexcept;
  NodeLnk*& FindPointerTo(NodeLnk*&, const Data&) noexcept;
  /* FIND POINTER TO Predecessor */
  NodeLnk* const& FindPointerToPredecessor(NodeLnk* const&, const Data&) const noexcept;
  NodeLnk*& FindPointerToPredecessor(NodeLnk*&, const Data&) noexcept;
  /* FIND POINTER TO Successor */
  NodeLnk* const& FindPointerToSuccessor(NodeLnk* const&,const Data&) const noexcept;
  NodeLnk*& FindPointerToSuccessor(NodeLnk*&, const Data&) noexcept;


};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
