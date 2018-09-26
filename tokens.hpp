/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 
#define BOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <iostream>
#include <fstream>
#include <string>

using namespace boost::spirit;
using boost::phoenix::val;

enum token_ids
{
    ID_INT_CONSTANT = 1000,
    ID_DOUBLE_CONSTANT,
    ID_DOUBLE_EXP_CONSTANT,
    ID_STRING_CONSTANT,    
    ID_IDENTIFIER,
    ID_WHITE_SPACE,
    ID_INT_T,
    ID_DOUBLE_T,
    ID_SEMICOLON_T,
    ID_EQUAL_T,
};

template <typename Lexer>
struct lang_tokens : lex::lexer<Lexer>
{
    lang_tokens()
    {
        identifier      = "[a-zA-Z_&][a-zA-Z_0-9\\\.\\\-\\\[\\\]$]*";
        string_constant = "[\\\"][a-zA-Z0-9_\\\.\\\-\\\[\\\]$ :'\\\<\\\>\\\{\\\}\\\*=\\\/\\\\,()]*[\\\"]";        
        int_constant    = "[0-9\\\-][0-9]*";
        double_constant = "[0-9]+\\\.[0-9]+";
        double_exp_constant = "[0-9]+e-[0-9]+";
        int_            = "int";
        double_         = "double";
        semicolon_      = "[;]";
        equal_          = "[=]";

        //white_space     = "[ \\t]+";

        this->self = lex::token_def<>('(') | ')' | '{' | '}' | ':' | '"' | '"' | ',';

        this->self.add
            (int_constant, ID_INT_CONSTANT)
            (double_constant, ID_DOUBLE_CONSTANT)
            (double_exp_constant, ID_DOUBLE_EXP_CONSTANT)
            (string_constant, ID_STRING_CONSTANT)
            (int_,  ID_INT_T)
            (double_, ID_DOUBLE_T)
            (semicolon_, ID_SEMICOLON_T)
            (equal_, ID_EQUAL_T)
            (identifier, ID_IDENTIFIER)
        ;
        //this-> self += white_space [lex::_pass = lex::pass_flags::pass_ignore]; // Need to tokenize but space not
        //white_space.id(ID_WHITE_SPACE);                                         // required in as token in parser
                                                                                // grammar                                                                            
        this->self("WS") 
            =   lex::token_def<>("[ \\t\\n]+") 
            |   "\\/\\*[^*]*\\*+([^/*][^*]*\\*+)*\\/"
            |   "#[^\\n]*"
            ;
    }

    lex::token_def<std::string> identifier,  double_exp_constant , string_constant;
    lex::token_def<int> int_constant;
    lex::token_def<double> double_constant;
    lex::token_def<std::string> int_, double_;

    lex::token_def<std::string> semicolon_, equal_;

    //lex::token_def<lex::omit> white_space;
};
