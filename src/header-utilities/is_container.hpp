/**
 * @brief 
 * A metaprogram leveraging SFINAE to deduce whether a parameter 
 * type is a container */
template< typename T, typename = void >
struct is_container : std::false_type{};

template< typename T >
struct is_container< T, void_t< iterator<T> > > : std::true_type{};
