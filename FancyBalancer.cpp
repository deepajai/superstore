#include "FancyBalancer.h"
#include <typeinfo>
#include <iostream>

#include <string>
    string starting[] = { "(", "{", "[" };
    string ending[] = { ")", "}", "]" };
    int el_count = 3;


FancyBalancer::FancyBalancer() {

}

bool is_valid_for_current_starting_parent(string el, string parent) {
    cout << "*" <<  el << ", " << parent << " | " << endl ;
    int policy = true;
    if( "[" == el && !(parent == "")) {
            if( parent == "{" or parent == "(" or parent == "[" )
               policy = false;
    }
    if( "{" == el ) {
            if(parent == "(" or parent == "{")
               policy = false;
    }
    if( "(" == el ) {
            if( parent == "[" or parent == "(" )
               policy = false;
    }
    cout << policy << endl ;
    return policy;
}

bool is_valid_for_current_closing_parent(string el, string parent) {
    int policy = false;
    if( "]" == el ) {
            if( parent == "[" )
               policy = true;
    }
    if( "}" == el ) {
            if(parent == "{" )
               policy = true;
    }
    if( ")" == el ) {
            if( parent == "(" )
               policy = true;
    }
    return policy;
}


bool is_starting (string c) {
    for(int i = 0 ; i < el_count; i++) {
        if(starting[i] == c)
            return true;
    }
    return false;
}


bool is_closing (string c) {
    for(int i = 0 ; i < el_count; i++) {
        if(ending[i] == c)
            return true;
    }
    return false;
}


bool is_valid_el ( string elem) {
    return (is_starting(elem) or is_closing(elem));
}




bool FancyBalancer::parseString(string str)
{
    FancyStack<char> stk(5);
    FancyStack<char> open_chars_list(3);
    FancyStack<char> close_chars_list(3);

    char op[]  = {'[', '{', '('};
    char cl[]  = { ']', '}', ')'};
    string valid_decendents_list[3] = {"{", "(", "(", };

    open_chars_list.addall(op, 3);
    close_chars_list.addall(cl, 3);
    int i = 0;

    while(i < str.length()){

        char current_el = str[i];

        if(open_chars_list.inArray(current_el))
        {
            if(stk.isEmpty()) {
                stk.push(current_el);
            } else {
                string current_char_as_string;
                current_char_as_string.insert(0, 1, current_el);
                //cout << current_char_as_string << endl << endl ;
                int loc = valid_decendents_list[(open_chars_list.firstIndexOf(stk.top()))].find(current_char_as_string, 0 );
                if(loc == string::npos ) {
                    return false; //cout << "Invalid char caught !" << endl;
                } else {
                    stk.push(current_el);
                }
            }
        } else if(close_chars_list.inArray(current_el)){
            if(stk.isEmpty()) {
                 //cout << "Invalid char caught !" << endl;
                 return false;
            } else {
                if(close_chars_list.getByIndex(open_chars_list.findByValue(stk.top())) == current_el)
                    stk.pop();
                else
                    //cout << "Invalid char caught !" << endl;
                    return false;
            }

        }
        i++;
    }

    if( stk.isEmpty()) {
        return true; //cout << "Valid expression found !" << endl;
    } else {
        return false; //cout << "expression is invalid !" << endl;
    }

}

bool FancyBalancer::isValidHTML(string str)
{
    FancyStack<string> stk(5);
    FancyStack<string> open_chars_list(3);
    FancyStack<string> close_chars_list(3);



    string op[]  = {"<html>", "<head>", "<body>", "<h1>", "<h2>"};
    string cl[]  = {"</html>", "</head>", "</body>", "</h1>", "</h2>"};
    string valid_decendents_list[] = {"<h1><h2><head><body>", "", "<h1><h2>", "<h1><h2>", "<h1><h2>" };

    open_chars_list.addall(op, 3);
    close_chars_list.addall(cl, 3);
    int i = 0;
    int j = 0;
    while(i < str.length()){

        while(str[i] != '>' ) { i++; continue;  }
        i++;

        string current_el = str.substr(j, i-j );
        cout << "value of i is " << i  << " " << current_el << endl  ;


        if(open_chars_list.inArray(current_el))
        {
            if(stk.isEmpty()) {
                stk.push(current_el);
            } else {
                cout << stk.top() << ", ";
                int loc = valid_decendents_list[(open_chars_list.firstIndexOf(stk.top()))].find(current_el, 0 );
                if(loc == string::npos ) {
                    //return false;
                    cout << "Invalid char caught !" << endl;
                } else {
                    stk.push(current_el);
                }
            }
        } else if(close_chars_list.inArray(current_el)){
            if(stk.isEmpty()) {
                 cout << "Invalid char caught !" << endl;
                 //return false;
            } else {
                if(close_chars_list.getByIndex(open_chars_list.findByValue(stk.top())) == current_el)
                    stk.pop();
                else
                    cout << "Invalid char caught !" << endl;
                    //return false;
            }

        }
        j = i;
    }
    stk.print();
    if( stk.isEmpty()) {
        //return true;
        cout << "Valid expression found !" << endl;
    } else {
        //return false;
        cout << "expression is invalid !" << endl;
    }

}




//template class FancySet<int>;
