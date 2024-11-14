//
//  BST.cpp
//  Lab 5 Search Through A Database
//
//  Created by Joseph Mi, Nov 13
#include "BST.h"

#include "Employee.h"

BST::BST(string order_) {
  root = NULL;
  order = order_;
}

BST::~BST() {
  delete root;
}

// newEmployee is a pointer to a dynamically allocated Employee. Insert it
// according to the value of "order" of the binary search tree.
void BST::insert(Employee* newEmployee) {
  if (!root) {
    root = newEmployee;
    return;
  }

  Employee *current = root;
  Employee *parent = nullptr;

  while (current) {
    parent = current;

    if (order == "name" || order == "Name") {
      if (newEmployee->getName() < current->getName()) {
        current = current->getLeft();
      } else {
        current = current->getRight();
      }
    }

    else if (order == "id"  || order == "ID") {
      if (newEmployee->getID() < current->getID()) {
        current = current->getLeft();
      } else {
        current = current->getRight();
      }
    }

    else if (order == "age" || order == "Age") {
      if (newEmployee->getAge() < current->getAge()) {
        current = current->getLeft();
      } else {
        current = current->getRight();
      }
    }

    // now onto setting
    if (order == "name" || order == "Name") {
      if (newEmployee->getName() < parent->getName()) {
        parent->setLeft(newEmployee);
      } else {
        current->setRight(newEmployee);
      }
    }

    else if (order == "id" || order == "ID") {
      if (newEmployee->getID() < parent->getID()) {
        parent->setLeft(newEmployee);
      } else {
        current->setRight(newEmployee);
      }
    }

    if (order == "age" || order == "Age") {
      if (newEmployee->getAge() < parent->getAge()) {
        parent->setLeft(newEmployee);
      } else {
        current->setRight(newEmployee);
      }
    }
  }
}

// print the Employees in the tree according its order
// Doesn't print anything if nothing is found
void BST::printInOrder() {
  if (!root) return;
  

  // now traverse all the way to last layer left and then right and then up

}

// search for an employee with a particular ID
// return NULL
Employee* BST::searchID(int ID) {
  // if (root == nullptr) {
  //   return nullptr;
  // }

  Employee *current = root;

  while (current) {
    int val = current->getID();
    if (ID == val) {
      return current;
    } else if (ID < val) {
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }

  return NULL;
}

// search for employees within the age range
// Doesn't print anything if nothing is found
void BST::searchAgeRange(double lowAge, double highAge) {
  if (!root) return;


}

// Search for employees with names having the same prefix in the firstName +
// secondName If available, it prints them in order of their names in
// alphabetical order
// Doesn't print anything if nothing is found
void BST::autocomplete(string prefix) {

}
