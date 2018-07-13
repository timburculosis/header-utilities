template< bool TF,
          template< typename...> class Concept,
          typename... T
         >
using Require = std::enable_if_t< Concept< T... >::value == TF, bool >;
