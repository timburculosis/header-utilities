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
