/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 

#ifndef __DESIGN_HPP__
#define __DESIGN_HPP__
#include <iostream>
#include <string>
#include <map>
#include <utility>

class Design {

    public:
        Design();
        ~Design();
        void SaveIntDecl(const std::string id, const int val);
        void SaveDoubleDecl(const std::string id, const double val);

    public:
        void DumpDesign();
        
    private:
        std::map<std::string, int>  int_decl_list;
        std::map<std::string, double>  double_decl_list;

};
#endif
