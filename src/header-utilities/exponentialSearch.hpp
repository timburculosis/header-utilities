#ifndef NJOY_UTILITY_EXPONENTIALSEARCH
#define NJOY_UTILITY_EXPONENTIALSEARCH

// system includes

// other includes

namespace njoy {
namespace utility {

  class ExponentialSearch {
    template< typename RandomAccessIterator,
  	    typename Value,
  	    typename Compare >
    static RandomAccessIterator apply( RandomAccessIterator left,
  				     RandomAccessIterator right,
  				     RandomAccessIterator end,
  				     Value&& value,
  				     Compare&& compare ){
      if ( left == right ){ return right; }
      const auto last = std::prev(right);
      return ( not compare( *last, value ) ) ?
        std::lower_bound( left,
  			right,
  			std::forward<Value>(value),
  			std::forward<Compare>(compare) ) :
        apply( right,
  	     right + std::min( end - right, 2 * (right - left) ),
  	     end,
  	     std::forward<Value>(value),
  	     std::forward<Compare>(compare) );
    }

  public:
    template< typename RandomAccessIterator,
  	    typename Value,
  	    typename Compare >
    RandomAccessIterator
    operator()( RandomAccessIterator begin,
  	      RandomAccessIterator end,
  	      Value&& value,
  	      Compare&& compare ) const {
      using difference_type =
        typename std::iterator_traits<RandomAccessIterator>::difference_type;

      return this->apply( begin,
  			begin + std::min( difference_type(8), end - begin ),
  			end,
  			std::forward<Value>(value),
  			std::forward<Compare>(compare) );
    }

    template< typename RandomAccessIterator, typename Value >
    RandomAccessIterator operator()( RandomAccessIterator begin,
  				   RandomAccessIterator end,
  				   Value&& value ) const {
      return (*this)( begin, end, std::forward<Value>(value), std::less<>{} );
    }
  };

  constexpr ExponentialSearch exponentialSearch{};

} // utility namespace
} // njoy namespace

#endif
