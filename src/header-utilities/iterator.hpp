#ifndef NJOY_UTILITY_ITERATOR
#define NJOY_UTILITY_ITERATOR

// system includes

// other includes

namespace njoy {
namespace utility {

  /**
   *  @brief An alias to a parameter type's nested iterator alias
   */
  template< typename T >
  using iterator = typename std::decay_t<T>::iterator;

} // utility namespace
} // njoy namespace

#endif
