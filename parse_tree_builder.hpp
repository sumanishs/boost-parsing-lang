/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 

#ifndef __PARSE_TREE_BUILDER_HPP__
#define __PARSE_TREE_BUILDER_HPP__
#include "design.hpp"


class ParseTreeBuilder {

    public:
        ParseTreeBuilder(Design* a_des);
        ~ParseTreeBuilder();
        void PrintStr(const std::string& str);
        void PrintInt(const int& i);
        void PrintDouble(const double& d);

    private:

        Design* m_des;

};
#endif
