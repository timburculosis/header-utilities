template< typename R, typename=void >
struct isRange : std::false_type { };

template< typename R >
struct isRange< R,
  void_t<
    decltype( std::begin( std::declval< R >() ) ),
    decltype( std::end  ( std::declval< R >() ) )
             >  > : std::true_type {
};
