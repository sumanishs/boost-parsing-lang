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


//namespace qi = boost::spirit::qi;

typedef void value_type;
struct PrintStr {
    void operator()(const std::string& str, qi::unused_type, qi::unused_type ) const{
        std::cout << str;
    }
    PrintStr(){ }
};

struct PrintInt {
    void operator()(const int& i, qi::unused_type, qi::unused_type ) const{
        std::cout << i;
    }
    PrintInt(){ }
};

struct PrintDouble {
    void operator()(const double& d, qi::unused_type, qi::unused_type ) const{
        std::cout << d;
    }
    PrintDouble(){ }
};

struct PrintPair {
    void operator()(const std::pair<std::string, std::string>& p, qi::unused_type, qi::unused_type) const {
        std::cout << p.first << " " << p.second;
    }
    PrintPair() {}
};
#endif

