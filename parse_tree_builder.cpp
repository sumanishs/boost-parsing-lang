/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 

#include "parse_tree_builder.hpp"

ParseTreeBuilder::ParseTreeBuilder(Design*  a_des):m_des(a_des) {
    last_decl_key = KEY_INVALID;
}

ParseTreeBuilder::~ParseTreeBuilder() {}

void ParseTreeBuilder::PrintStr(const std::string& str) {
    std::cout << str;
}

void ParseTreeBuilder::PrintInt(const int& i) {
    std::cout << i;
}

void ParseTreeBuilder::PrintDouble(const double& d) {
    std::cout << d;
}

void ParseTreeBuilder::SaveIntDecl(const std::string& a_idecl) {
    last_decl_key = KEY_INT;
    m_des
    m_decl_stack.push(a_idecl);
} 
