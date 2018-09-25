/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/bind.hpp>

#include <utility>
#include <string>

#include "tokens.hpp"
#include "functors.hpp"

using namespace boost::spirit;
using namespace boost::phoenix;
typedef void value_type;

template <typename Iterator, typename Lexer>
struct lang_grammar 
  : qi::grammar<Iterator, qi::in_state_skipper<Lexer> >
{

    template <typename TokenDef>
    lang_grammar(TokenDef const& tok)
      : lang_grammar::base_type(start)
    {
        typedef void value_type;

        using boost::spirit::_val;
		using boost::spirit::_1;
		using boost::spirit::_2;
		using boost::spirit::_3;
		using boost::spirit::_4;
        
        start       = +var_decls;
        var_decls   = int_decls      
                     | double_decls
                     ; 
        int_decls   = int_decl_stmt_ >> tok.semicolon_;
        int_decl_stmt_  = tok.int_ >> tok.identifier;

        double_decls   = tok.double_  >> tok.identifier >> tok.semicolon_;
    }
    qi::rule<Iterator, qi::in_state_skipper<Lexer> > start, statements, var_decls, int_decls, double_decls;
    qi::rule<Iterator, std::pair<std::string, std::string>(), qi::in_state_skipper<Lexer> >  int_decl_stmt_, double_decl_stmt_;
};
