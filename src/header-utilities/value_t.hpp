template< typename R,
          Require< true, is_range, std::decay_t< R > > = true >
struct value {
  using type = std::decay_t< decltype( *( std::declval< R >().begin() ) ) >;
};

template< typename R >
using value_t = typename value< R >::type;
