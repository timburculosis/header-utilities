template< typename R, typename=void >
struct is_range : std::false_type { };

template< typename R >
struct is_range< R,
  void_t<
    decltype( std::begin( std::declval< R& >() ) ),
    decltype( std::end  ( std::declval< R& >() ) )
             >  > : std::true_type {
};
