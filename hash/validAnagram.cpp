#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char,int>cantAparicionesS; //Guardo el caracter como clave y la cantidad de veces que aparece como valor
       if(s.length() != t.length()) return false; 
        for(int i = 0; i < s.length(); i++){
            cantAparicionesS[s[i]] += 1;
        }       
        for(int i = 0; i < s.length(); i++){
            cantAparicionesS[t[i]] -= 1;
            if(cantAparicionesS[t[i]] < 0){
                return false;
            }
        }       
        return true;
    }

};

/* Otra opcion valida:
    bool isAnagram(string s, string t) {
       unordered_map<char,int>cantAparicionesS; //Guardo el caracter como clave y la cantidad de veces que aparece como valor
       if(s.length() != t.length()) return false; 
        for(char c : s){
            cantAparicionesS[c] ++;
        }
        for(char c : s){
            cantAparicionesS[c] --;
            if(cantAparicionesS[c] < 0){
                return false;
            }
        }               
        return true;
    }
*/



