template< typename T, typename = void >
constexpr bool is_dereferencable = false;

template< typename T >
constexpr bool is_dereferencable
               < T, void_t< decltype( *( std::declval<T>() ) ) > > = true;

template< typename T, std::enable_if_t< is_dereferencable<T>, bool > = true >
decltype(auto) dereference( T&& t ){ return *t; }

template< typename T,
          std::enable_if_t< not is_dereferencable<T>, bool > = true >
decltype(auto) dereference( T&& t ){ return t; }
