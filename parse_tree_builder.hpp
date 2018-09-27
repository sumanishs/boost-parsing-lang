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
#include <stack>

class ParseTreeBuilder {
    
    private:
        enum KEY_WORD_TYPES {
            KEY_INVALID = -1,
            KEY_INT = 0,
            KEY_DOUBLE,
        } last_decl_key;
    

    public:
        ParseTreeBuilder(Design* a_des);
        ~ParseTreeBuilder();
        void PrintStr(const std::string& str);
        void PrintInt(const int& i);
        void PrintDouble(const double& d);
        void SetDeclID(const std::string& id);
        void SetDeclIVal(const int val);
        void SetDeclDVal(const double val);
        void SaveIntDecl();
        void SaveDoubleDecl();

    private:

        Design* m_des;
        std::string m_dcl_id;
        int m_decl_ival;
        double m_decl_dval;
        std::stack<std::string> m_decl_stack;
};
#endif
