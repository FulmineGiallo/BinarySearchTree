
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"
#include "bst/bst.hpp"
#include "vector/vector.hpp"
#include "binarytree/lnk/binarytreelnk.hpp"
/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
  lasdtest(); // To call in the menu of your library test!
  lasd::BST<int> search;
  search.Insert(3);
  search.Insert(1);
  search.Insert(4);
  search.Insert(0);
  search.Insert(2);
  search.Insert(5);

  std::cout << "Predecessor :" << search.Predecessor(1);
  std::cout << "PredecessorNRemove :" << search.Predecessor(4);
  // lasd::Vector<int> vec(5);
  // vec[0] = 1;
  // vec[1] = 2;
  // vec[2] = 3;
  // vec[3] = 4;
  // vec[4] = 5;
  // lasd::BinaryTreeLnk<int> tree(vec);
  // tree.Root()->left = nullptr;

  return 0;
}
