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

//for deleting a tree, delete up to its last elements, then recursively traverse back up
void deleteTree(Employee *employee) {
  if (!employee) return;

  deleteTree(employee->getLeft());
  deleteTree(employee->getRight());

  delete employee;
  }

BST::~BST() {
  deleteTree(root);
}


////////// insert //////////
////////////////////////////
// newEmployee is a pointer to a dynamically allocated Employee. Insert it
// according to the value of "order" of the binary search tree.
void BST::insert(Employee* newEmployee) {
  if (!root) {
    root = newEmployee;
    return;
  }

  Employee* current = root;
  Employee* parent = nullptr;

  while (current) {
    parent = current;
    while (current) {
      parent = current;
      if (order == "name" || order == "Name") {
        current = (newEmployee->getName() < current->getName()) ? current->getLeft() : current->getRight();
      } else if (order == "id" || order == "ID") {
        // cant have same id
        if (newEmployee->getID() == current->getID()) {
          cout << "Error: ID already exists" << endl;
          return;
        }
        current = (newEmployee->getID() < current->getID()) ? current->getLeft() : current->getRight();
      } else if (order == "age" || order == "Age") {
        // make sure if age is equal, new emp is still lower
        current = (newEmployee->getAge() <= current->getAge()) ? current->getLeft() : current->getRight();
      }
    }
  }

  // onto setting
  if (order == "name" || order == "Name") {
    if (newEmployee->getName() < parent->getName()) {
      parent->setLeft(newEmployee);
    } else {
      parent->setRight(newEmployee);
    }
  } else if (order == "id" || order == "ID") {
    if (newEmployee->getID() < parent->getID()) {
      parent->setLeft(newEmployee);
    } else {
      parent->setRight(newEmployee);
    }
  } else if (order == "age" || order == "Age") {
    if (newEmployee->getAge() <= parent->getAge()) {
      parent->setLeft(newEmployee);
    } else {
      parent->setRight(newEmployee);
    }
  }
}


////////// print Order //////////
/////////////////////////////////
void printInOrderHelper(Employee *current, string order) {
  if (!current) return;

  printInOrderHelper(current->getLeft(), order);

  //not sure if I should print employee name, ID, or what
  if (order == "name" || order == "Name") {
      cout << current->getName() << endl;
  } else if (order == "id" || order == "ID") {
      cout << current->getID() << endl;
  } else if (order == "age" || order == "Age") {
      cout << current->getAge() << endl;
  }

  printInOrderHelper(current->getRight(), order);
}

// print the Employees in the tree according its order
// Doesn't print anything if nothing is found
void BST::printInOrder() {
  if (!root) return;

  // now traverse all the way to last layer left and then right and then up
  printInOrderHelper(root, order);
}

////////// searchID //////////
//////////////////////////////////
// search for an employee with a particular ID
// return NULL
Employee* BST::searchID(int ID) {
  if (root == NULL) {
    return NULL;
  }

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

  return NULL; //employee not found
}

////////// search age range //////////
//////////////////////////////////////
// will only work on tree ordered by age
void searchAgeRangeHelper(Employee *ATNode, int lowAge, int highAge) {
  if (ATNode == nullptr) return;

  // still need to check
  if (ATNode->getAge() >= lowAge) {
    searchAgeRangeHelper(ATNode->getLeft(), lowAge, highAge);
  }
  // if within
  if (ATNode->getAge() >= lowAge && ATNode->getAge() <= highAge) {
    cout << "Name: " << ATNode->getName() << endl
        << "ID: " << ATNode->getID() << endl
        << "Age: " << ATNode->getAge() << endl
        << "Salary: " << ATNode->getSalary() << endl; 
  }
  // still need to check even if we have found one
  if (ATNode->getAge() <= highAge) {
    searchAgeRangeHelper(ATNode->getRight(), lowAge, highAge);
  }
}

// search for employees within the age range
// Doesn't print anything if nothing is found
void BST::searchAgeRange(double lowAge, double highAge) {
  if (!root) return;

  searchAgeRangeHelper(root, lowAge, highAge);
}

////////// autocomplete //////////
//////////////////////////////////
//will only work if tree ordered by name
void automCompleteHelper(Employee *NTNode, string pre) {
  if (NTNode == nullptr) return;

  string name = NTNode->getName();
  int len = pre.size();

  if(name.substr(0,len) == pre) {
    cout << name << endl;
  }

  automCompleteHelper(NTNode->getLeft(), pre);
  automCompleteHelper(NTNode->getRight(), pre);
}
// Search for employees with names having the same prefix in the firstName +
// secondName If available, it prints them in order of their names in
// alphabetical order
// Doesn't print anything if nothing is found
void BST::autocomplete(string prefix) {
  if (!root) return;

  automCompleteHelper(root, prefix);
}
