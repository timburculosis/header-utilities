#ifndef NJOY_HEADER_UTILITIES
#define NJOY_HEADER_UTILITIES

#include <iterator>
#include <memory>
#include <type_traits>

namespace njoy{
namespace utility{

/**
 * @brief 
 * A alias template used for as a template type parameter to enable SFINAE */
template< class... >
using void_t = void;

/** @brief An alias to a parameter type's nested element_type alias */
template< typename T >
using element_type = typename std::decay_t<T>::element_type;

/** 
 * @brief 
 * An alias to a parameter type's nested iterator_category alias 
 * (with special treament for pointers) */
template< typename T >
using iterator_category =
  typename std::iterator_traits< std::decay_t<T> >::iterator_category;

/** @brief An alias to a parameter type's nested iterator alias */
template< typename T >
using iterator = typename std::decay_t<T>::iterator;

/** 
 * @brief 
 * A metaprogram leveraging SFINAE to deduce whether a parameter type 
 * is an instantiation of the std::shared_ptr template */
template< typename T, typename = void_t<> >
struct is_shared_ptr : std::false_type{};

template< typename T >
struct is_shared_ptr< T, void_t< element_type<T> > > :
  std::integral_constant< bool, std::is_same
                                < std::decay_t<T>, 
                                  std::shared_ptr
                                  < element_type<T> > >::value >{};
/** 
 * @brief 
 * A metaprogram leveraging SFINAE to deduce whether a parameter type 
 * is an instantiation of the std::unique_ptr template */
template< typename T, typename = void_t<> >
struct is_unique_ptr : std::false_type{};

template< typename T >
struct is_unique_ptr< T, void_t< element_type<T> > > :
  std::integral_constant< bool, std::is_same
                                < std::decay_t<T>, 
                                  std::unique_ptr
                                  < element_type<T> > >::value >{};
/**
 * @brief 
 * A metaprogram which deduces whether a parameter type is an instantiation
 * of either the std::unique_ptr or std::shared_ptr template */
template< typename T >
struct is_smart_ptr :
  std::integral_constant< bool, is_unique_ptr<T>::value 
                                || is_shared_ptr<T>::value >{};

/** 
 * @brief 
 * A metaprogram leveraging SFINAE to deduce whether a parameter 
 * type is an iterator */
template< typename T, typename = void_t<> >
struct is_iterator : std::false_type{};

template< typename T >
struct is_iterator< T, void_t< iterator_category<T> > > : std::true_type{};

/**
 * @brief 
 * A metaprogram leveraging SFINAE to deduce whether a parameter 
 * type is a container */
template< typename T, typename = void_t<> >
struct is_container : std::false_type{};

template< typename T >
struct is_container< T, void_t< iterator<T> > > : std::true_type{};

/** @brief A generic function to call to a parameter types copy ctor */
template< typename T >
T copy( const T& t ){ return t; }

}
}

#endif
