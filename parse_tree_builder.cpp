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

void ParseTreeBuilder::SetDeclID(const std::string& id) {
    m_dcl_id = id;
}

void ParseTreeBuilder::SetDeclIVal(const int val) {
    m_decl_ival = val;
}

void ParseTreeBuilder::SetDeclDVal(const double val) {
    m_decl_dval = val;
}

void ParseTreeBuilder::SaveIntDecl() {
    m_des -> SaveIntDecl (m_dcl_id, m_decl_ival);
    m_dcl_id.clear();
    m_decl_ival = 0;
} 

void ParseTreeBuilder::SaveDoubleDecl() {
    m_des -> SaveDoubleDecl (m_dcl_id, m_decl_dval);
    m_dcl_id.clear();
    m_decl_dval = 0;
} 
