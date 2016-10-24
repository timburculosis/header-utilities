#ifndef NJOY_HEADER_UTILITIES
#define NJOY_HEADER_UTILITIES

#include <fstream>
#include <iterator>
#include <memory>
#include <type_traits>

#include "Log.hpp"

namespace njoy{
namespace utility{

/**
 * @brief 
 * A alias template used for as a template type parameter to enable SFINAE
 *
 * @details
 * The void_t template is useful for implementing the so-called detection
 * idiom to provide rudimentary compile-time reflection in C++. See the 
 * is_iterator template later in this library for a simple executable example,
 * of the use of this template in pratice.
 *  */
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
template< typename T, typename = void >
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
template< typename T, typename = void >
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
template< typename T, typename = void >
struct is_iterator : std::false_type{};

template< typename T >
struct is_iterator< T, void_t< iterator_category<T> > > : std::true_type{};

/**
 * @brief 
 * A metaprogram leveraging SFINAE to deduce whether a parameter 
 * type is a container */
template< typename T, typename = void >
struct is_container : std::false_type{};

template< typename T >
struct is_container< T, void_t< iterator<T> > > : std::true_type{};

/** 
 * @brief A generic function to call to a parameter types copy ctor 
 * @details 
 * This function is convenient in conjunction with the idiom of always accepting
 * sink arguments by value (used throughout NJOY21 libraries). When passing
 * an l-value to such a function, the user can opt to either explicitly move
 * (using std::move) or explicitly copy (using utility::copy) the l-value.
 */
template< typename T >
T copy( const T& t ){ return t; }

/**
 * @brief
 * Dumps a line of text to screen, followed by cursor indicating the source of 
 * the error */
template< typename Iterator >
void echoErroneousLine( Iterator lineBegin, Iterator positionIterator,
			const Iterator& end, long lineNumber ){
  const auto lineEnd = std::find( positionIterator, end, '\n');
  const auto position = std::distance( lineBegin, positionIterator );
  Log::info( "Error while parsing line {}\n\n{}\n{}{}\n",
	     lineNumber,
	     std::string( lineBegin, lineEnd ),
	     std::string( position, '~' ), '^' );
}

/** @brief Copies the contents of a file to a string */
inline std::string
slurpFileToMemory( const std::string& path ){
  std::string sink;
  std::ifstream input( path, std::ios::in | std::ios::binary );
  if ( not input ){
    Log::error( "File could not opened for reading" );
    Log::info( "Specified file path: {}", path ); 
    Log::info( "Error while slurping file to memory" );
    throw std::runtime_error("input file could not be opened");
  }
  input.seekg( 0, std::ios::end );
  const auto file_size = input.tellg();
  input.seekg( 0, std::ios::beg );
  sink.resize( file_size / sizeof(char) );
  input.read( &( sink[ 0 ] ), file_size );
  return sink;
}

}
}

#endif
