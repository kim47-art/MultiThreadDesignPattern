#include <functional>

class scoped_guard
{
    std::function< void() > f ;
public :
    explicit scoped_guard( std::function< void () > f )
        : f(f) { }

    scoped_guard( scoped_guard const & ) = delete ;
    void operator = ( scoped_guard const & ) = delete ;


    ~scoped_guard()
    { f() ; }

} ;