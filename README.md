Header Utilities
======================
A single header distilling a subset of the NJOY utility library for use with 
header-only libraries.

Minimal Example
----------------

```c++
#include <iostream>
#include <vector>
#include "header-utilities.hpp"

using namespace njoy::utility;

int main(){

std::unique_ptr<int> myUnique;
std::shared_ptr<int> myShared;
std::vector<int> myVector{};
std::vector<int>::iterator myIterator = myVector.begin();

if ( is_unique_ptr< decltype(myUnique) >::value ){
  std::cout << "myUnique is an instantiation of the unique_ptr template" << std::endl;
}

if ( not is_unique_ptr< decltype(myShared) >::value ){
  std::cout << "myShared is not an instantiation of the shared_ptr template" << std::endl;
}

if ( not is_shared_ptr< decltype(myUnique) >::value ){
  std::cout << "myUnique is not an instantiation of the shared_ptr template" << std::endl;
}

if ( is_shared_ptr< decltype(myShared) >::value ){
  std::cout << "myShared is an instantiation of the shared_ptr template" << std::endl;
}

if ( is_smart_ptr< decltype(myUnique) >::value ){
  std::cout << "myUnique is an instantiation of a standard library smart pointer template" << std::endl;
}

if ( is_smart_ptr< decltype(myShared) >::value ){
  std::cout << "myShared is an instantiation of a standard library smart pointer template" << std::endl;
}

if ( is_container< decltype(myVector) >::value ){
  std::cout << "myVector is a container type" << std::endl;
}

if ( not is_container< decltype(myIterator) >::value ){
  std::cout << "myIterator is not a container type" << std::endl;
}

if ( not is_iterator< decltype(myVector) >::value ){
  std::cout << "myVector is not an iterator type" << std::endl;
}

if ( is_iterator< decltype(myIterator) >::value ){
  std::cout << "myIterator is an iterator type" << std::endl;
}

auto f = []( std::vector<int>&& v ){};

/* can't compile */
// f( myVector );

/* can compile */
f( copy(myVector) );

}
```
