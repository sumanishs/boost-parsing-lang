/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 

#include "langreader.hpp"
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>

#include <iostream>
#include <fstream>
#include <string>

using namespace boost::spirit;

bool 
LangReader::Read(std::string& filename){

    typedef std::string::iterator base_iterator_type;
    typedef lex::lexertl::token< base_iterator_type, boost::mpl::vector<unsigned int, std::string> > token_type;
    typedef lex::lexertl::actor_lexer<token_type> lexer_type;
    typedef lang_tokens<lexer_type> lang_tokens;
    typedef lang_tokens::iterator_type iterator_type;
    typedef lang_grammar<iterator_type, lang_tokens::lexer_def> lang_grammar;

    if(!m_des){
        m_des = new Design();
    }

    if(!m_ptb){
        m_ptb = new ParseTreeBuilder(m_des);
    } 
    
    lang_tokens tokens;                                 // Our lexer
    lang_grammar grammar(tokens, m_ptb);                  // Our parser

    std::ifstream inFile;
    inFile.open(filename.c_str());
    if(inFile.fail()){
        std::cout << "Cannot open file to read...." << std::endl;
        return false;
    }

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str(strStream.str());
    str.pop_back();
    std::cout << "File content:\n" << str << std::endl;
    inFile.close();

    std::string::iterator it = str.begin();
    iterator_type iter = tokens.begin(it, str.end());
    iterator_type end = tokens.end();

    std::string ws("WS");
    bool r = qi::phrase_parse(iter, end, grammar, qi::in_state(ws)[tokens.self]);

    if (r && iter == end)
    {
        std::cout << "-------------------------\n";
        std::cout << "Parsing succeeded\n";
        std::cout << "-------------------------\n";
        m_des -> DumpDesign();
        return true;
    }
    else
    {
        std::cout << "-------------------------\n";
        std::cout << "Parsing failed\n";
        std::cout << "-------------------------\n";
        return false;
    }
}
