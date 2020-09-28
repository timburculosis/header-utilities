#ifndef NJOY_UTILITY_ELEMENT_TYPE
#define NJOY_UTILITY_ELEMENT_TYPE

// system includes

// other includes

namespace njoy {
namespace utility {

  /**
   *  @brief An alias to a parameter type's nested element_type alias
   */
  template< typename T >
  using element_type = typename std::decay_t<T>::element_type;

} // utility namespace
} // njoy namespace

#endif
