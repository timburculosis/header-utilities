#ifndef NJOY_UTILITY_ITERATOR_CATEGORY
#define NJOY_UTILITY_ITERATOR_CATEGORY

// system includes

// other includes

namespace njoy {
namespace utility {

  /**
   *  @brief An alias to a parameter type's nested iterator_category alias
   *         (with special treament for pointers)
   */
  template< typename T >
  using iterator_category =
    typename std::iterator_traits< std::decay_t<T> >::iterator_category;

} // utility namespace
} // njoy namespace

#endif
