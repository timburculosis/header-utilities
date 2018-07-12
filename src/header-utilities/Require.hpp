template< template< typename> class Concept,
          typename T,
          bool TF >
struct Require: std::enable_if_t< Concept< T >::value == TF, bool >;
