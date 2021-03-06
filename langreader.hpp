/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 

#include <iostream>
#include <string>

#include "grammar.hpp"
#include "design.hpp"
#include "parse_tree_builder.hpp"


class LangReader {

    public:
        LangReader():m_des(0), m_ptb(0) {}
        ~LangReader() {}

        bool Read(std::string& filename);

    private:
        Design* m_des;
        ParseTreeBuilder* m_ptb;
};

