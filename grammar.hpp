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
#include "parse_tree_builder.hpp"

using namespace boost::spirit;
using namespace boost::phoenix;

template <typename Iterator, typename Lexer>
struct lang_grammar 
  : qi::grammar<Iterator, qi::in_state_skipper<Lexer> >
{

    template <typename TokenDef>
    lang_grammar(TokenDef const& tok, ParseTreeBuilder* a_ptb)
      : lang_grammar::base_type(start), m_ptb(a_ptb)
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
        int_decls   = tok.int_ >> tok.identifier [SetDeclID(m_ptb)] >> -int_init_val >>  tok.semicolon_ [SaveIntDecl(m_ptb)];
        int_init_val = tok.equal_ >> tok.int_constant [SetDeclIVal(m_ptb)];
        
        double_decls   = tok.double_ >> tok.identifier [SetDeclID(m_ptb)] >> -double_init_val >> tok.semicolon_ [SaveDoubleDecl(m_ptb)];
        double_init_val = tok.equal_ >> tok.double_constant [SetDeclDVal(m_ptb)];
    }
    qi::rule<Iterator, qi::in_state_skipper<Lexer> > start, statements, var_decls, int_decls, double_decls, int_init_val, double_init_val;

    ParseTreeBuilder*   m_ptb;
};
