/**********************************************************************/
/* Author: Sumanish <sumanish.cse.jgec@gmail.com>                     */
/* Modified By: Sumanish <sumanish.cse.jgec@gmail.com>                */
/*                                                                    */  
/* This source code can be downloaded, use, modify, distribute        */
/* freely with this headed intact. Please don't delete this header.   */
/**********************************************************************/ 

#include "design.hpp"

Design::Design() {}
Design::~Design() {}

void Design::SaveIntDecl(const std::string id, const int val) {
    int_decl_list.insert(std::pair<std::string, int>(id, val));
}

void Design::SaveDoubleDecl(const std::string id, const double val) {
    double_decl_list.insert(std::pair<std::string, double>(id, val));
}

void Design::DumpDesign(){
   std::cout << "Dumping whatever parsed...." << std::endl; 
   std::map<std::string, int>::iterator iti = int_decl_list.begin();
   for( ; iti != int_decl_list.end(); ++iti) 
        std::cout << "int " << iti -> first << " = " << iti -> second << ";" << std::endl; 
   
   std::map<std::string, double>::iterator itd = double_decl_list.begin();
   for( ; itd != double_decl_list.end(); ++itd) 
        std::cout << "double " << itd -> first << " = " << itd -> second << ";" << std::endl; 

    std::cout << std::endl;
}

