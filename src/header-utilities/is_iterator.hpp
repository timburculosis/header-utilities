/** 
 * @brief 
 * A metaprogram leveraging SFINAE to deduce whether a parameter 
 * type is an iterator */
template< typename T, typename = void >
struct is_iterator : std::false_type{};

template< typename T >
struct is_iterator< T, void_t< iterator_category<T> > > : std::true_type{};
