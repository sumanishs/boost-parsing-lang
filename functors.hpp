/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 
#ifndef __FUNCTORS__
#define __FUNCTORS__

#include <boost/spirit/include/qi.hpp>

#include <iostream>
#include <utility>
#include "parse_tree_builder.hpp"

struct PrintStr {
    void operator()(const std::string& str, qi::unused_type, qi::unused_type ) const{
        //std::cout << str;
        m_ptb -> PrintStr(str);
    }
    PrintStr(ParseTreeBuilder* a_ptb):m_ptb(a_ptb) { }
    ParseTreeBuilder* m_ptb;
};

struct PrintInt {
    void operator()(const int& i, qi::unused_type, qi::unused_type ) const{
        //std::cout << i;
        m_ptb -> PrintInt(i);
    }
    PrintInt(ParseTreeBuilder* a_ptb):m_ptb(a_ptb) { }
    ParseTreeBuilder* m_ptb;
};

struct PrintDouble {
    void operator()(const double& d, qi::unused_type, qi::unused_type ) const{
        //std::cout << d;
        m_ptb -> PrintDouble(d);
    }
    PrintDouble(ParseTreeBuilder* a_ptb):m_ptb(a_ptb) { }
    ParseTreeBuilder* m_ptb;
};

struct SetDeclID {
        void operator()(const std::string& id, qi::unused_type, qi::unused_type) const {
            //std::cout << id;
            m_ptb -> SetDeclID(id);
        }
        SetDeclID(ParseTreeBuilder* a_ptb):m_ptb(a_ptb) { }
        ParseTreeBuilder* m_ptb;
};

struct SetDeclIVal {
        void operator() (const int& val, qi::unused_type, qi::unused_type ) const {
            //std::cout << val;
            m_ptb -> SetDeclIVal(val);
        }
        SetDeclIVal(ParseTreeBuilder* a_ptb):m_ptb(a_ptb) { }
        ParseTreeBuilder* m_ptb;
};

struct SetDeclDVal {
        void operator() (const double& val, qi::unused_type, qi::unused_type ) const {
            //std::cout << val;
            m_ptb -> SetDeclDVal(val);
        }
        SetDeclDVal(ParseTreeBuilder* a_ptb):m_ptb(a_ptb) { }
        ParseTreeBuilder* m_ptb;
};

struct SaveIntDecl {
        void operator() (const std::string& str, qi::unused_type, qi::unused_type) const {
            //std::cout << str;
            m_ptb -> SaveIntDecl();
        }
        SaveIntDecl(ParseTreeBuilder* a_ptb):m_ptb(a_ptb) { }
        ParseTreeBuilder* m_ptb;
};

struct SaveDoubleDecl {
        void operator() (const std::string& str, qi::unused_type, qi::unused_type) const {
            //std::cout << str;
            m_ptb -> SaveDoubleDecl();
        }
        SaveDoubleDecl(ParseTreeBuilder* a_ptb):m_ptb(a_ptb) { }
        ParseTreeBuilder* m_ptb;
};

#endif

