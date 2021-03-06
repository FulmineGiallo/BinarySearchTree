
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../iterator/iterator.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../stack/lst/stacklst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: virtual public InOrderMappableContainer<Data>,
                  virtual public InOrderFoldableContainer<Data>,
                  virtual public BreadthMappableContainer<Data>,
                  virtual public BreadthFoldableContainer<Data>{ // Must extend InOrder/BreadthMappableContainer<Data> and InOrder/BreadthFoldableContainer<Data>

private:

  // ...

protected:

   //using BreadthMappableContainer<Data>::size;
   using InOrderMappableContainer<Data>::size;

public:

  struct Node {

  private:

    // ...

  protected:

    // Comparison operators
    // type operator==(argument) specifiers;
    // Comparison of abstract types is possible, but should not be visible.
    bool operator==(const Node&) const noexcept;

    // type operator!=(argument) specifiers;
    // Comparison of abstract types is possible, but should not be visible.
    bool operator!=(const Node&) const noexcept;

  public:

     friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~Node() specifiers
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument);
    // Copy assignment of abstract types should not be possible.
    Node& operator=(const Node&) = delete;

    // Move assignment
    // type operator=(argument);
    // Move assignment of abstract types should not be possible.
    Node& operator=(Node&&) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers;
    // Mutable access to the element (concrete function should not throw exceptions)
    virtual Data& Element() noexcept = 0;

    // type Element() specifiers;
    // Immutable access to the element (concrete function should not throw exceptions)
    virtual const Data& Element() const noexcept = 0;

    // type IsLeaf() specifiers;
    // (concrete function should not throw exceptions)
    virtual bool IsLeaf() const noexcept = 0;

    // type HasLeftChild() specifiers;
    // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0;


    // type HasRightChild() specifiers;
    // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0;

    // type LeftChild() specifiers;
    // (concrete function must throw std::out_of_range when not existent)
    virtual Node& LeftChild() const = 0;

    // type RightChild() specifiers;
    // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild() const = 0;

  };

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  // Copy assignment of abstract types should not be possible.
  BinaryTree& operator=(const BinaryTree&) = delete;

  // Move assignment
  // type operator=(argument);
  // Move assignment of abstract types should not be possible.
  BinaryTree& operator=(BinaryTree&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // Comparison of abstract binary tree is possible.
  bool operator==(const BinaryTree&) const noexcept;

  // type operator!=(argument) specifiers;
  // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions
  // type Root() specifiers;
  // (concrete function must throw std::length_error when empty)
  virtual Node& Root() const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
  using typename MappableContainer<Data>::MapFunctor;

  // type MapPreOrder(arguments) specifiers;
  // Override MappableContainer member
  void MapPreOrder(const MapFunctor fun, void* v) override;

  // type MapPostOrder(arguments) specifiers;
  // Override MappableContainer member
  void MapPostOrder(const MapFunctor fun, void* v) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
  using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldPreOrder(arguments) specifiers;
  // Override FoldableContainer member
  void FoldPreOrder(const FoldFunctor fun, const void* v, void* v2) const override;

  // type FoldPostOrder(arguments) specifiers;
  // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor fun , const void* v, void* v2) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)
  // type MapInOrder(arguments) specifiers;
  // Override InOrderMappableContainer member
  void MapInOrder(const MapFunctor fun, void* v) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)
  // type FoldInOrder(arguments) specifiers;
  // Override InOrderFoldableContainer member
  void FoldInOrder(const FoldFunctor fun, const void* v, void* v2) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)
  // type MapBreadth(arguments) specifiers;
  // Override BreadthMappableContainer member
  void MapBreadth(const MapFunctor fun, void* v) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)
  // type FoldBreadth(arguments) specifiers;
  // Override BreadthFoldableContainer member
  void FoldBreadth(const FoldFunctor fun, const void* v, void* v2) const override;

protected:

  // Auxiliary member functions (for MappableContainer)
  // type MapPreOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree
  void MapPreOrder(const MapFunctor, void*, Node&);

  // type MapPostOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree
  void MapPostOrder(const MapFunctor, void*, Node&);

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)
  // type FoldPreOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree
  void FoldPreOrder(const FoldFunctor, const void*, void*, const Node&) const;

  // type FoldPostOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree
  void FoldPostOrder(const FoldFunctor, const void*, void*, const Node&) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)
  // type MapInOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree
  void MapInOrder(const MapFunctor, void*, Node&);

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)
  // type FoldInOrder(arguments) specifiers;
  // Accessory function executing from one node of the tree
  void FoldInOrder(const FoldFunctor, const void*, void*, const Node&) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)
  // type MapBreadth(arguments) specifiers;
  // Accessory function executing from one node of the tree
  void MapBreadth(const MapFunctor, void*, Node&);

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)
  // type FoldBreadth(arguments) specifiers;
  // Accessory function executing from one node of the tree
  void FoldBreadth(const FoldFunctor, const void*, void*, Node&) const;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  typename BinaryTree<Data>::Node *node = nullptr;
  StackLst<typename BinaryTree<Data>::Node*> stack;

protected:

  // ...

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers;
  // An iterator over a given binary tree
  BTPreOrderIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(const BTPreOrderIterator<Data>&);

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator<Data>& operator=(const BTPreOrderIterator<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator<Data>& operator=(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPreOrderIterator<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BTPreOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  // type operator*() specifiers;
  // (throw std::out_of_range when terminated)
  Data& operator*() const override;

  // type Terminated() specifiers;
  // (should not throw exceptions)
  bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  // type operator++() specifiers;
  // (throw std::out_of_range when terminated)
  BTPreOrderIterator& operator++() override;

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  typename BinaryTree<Data>::Node *node = nullptr;
  StackLst<typename BinaryTree<Data>::Node*> stack;

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers;
  // An iterator over a given binary tree
  BTPostOrderIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(const BTPostOrderIterator&);

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
  ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPostOrderIterator&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BTPostOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  // type operator*() specifiers;
  // (throw std::out_of_range when terminated)
  Data& operator*() const override;

  // type Terminated() specifiers;
  // (should not throw exceptions)
  bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  // type operator++() specifiers;
  // (throw std::out_of_range when terminated)
  BTPostOrderIterator& operator++() override;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  typename BinaryTree<Data>::Node *node = nullptr;
  StackLst<typename BinaryTree<Data>::Node*> stack;

protected:

  // ...

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers;
  // An iterator over a given binary tree
  BTInOrderIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(const BTInOrderIterator&);

  // Move constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
  ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTInOrderIterator&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BTInOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  // type operator*() specifiers;
  // (throw std::out_of_range when terminated)
  Data& operator*() const override;

  // type Terminated() specifiers;
  // (should not throw exceptions)
  bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  // type operator++() specifiers;
  // (throw std::out_of_range when terminated)
  BTInOrderIterator& operator++() override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  typename BinaryTree<Data>::Node *node = nullptr;
  QueueLst<typename BinaryTree<Data>::Node*> queue;

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers;
  // An iterator over a given binary tree
  BTBreadthIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator (const BTBreadthIterator&);

  // Move constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator (BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
  ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(const BTBreadthIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTBreadthIterator<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator!=(const BTBreadthIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)
  // type operator*() specifiers;
  // (throw std::out_of_range when terminated)
  Data& operator*() const override;

  // type Terminated() specifiers;
  // (should not throw exceptions)
  bool Terminated() const noexcept override;


  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)
  // type operator++() specifiers;
  // (throw std::out_of_range when terminated)
  BTBreadthIterator& operator++() override;

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
