/**
 * @class Roman
 * @brief Header for Roman class.
 */

#ifndef ROMAN_H
#define ROMAN_H

#include <string>

class Roman {
   private:
      std::string romanStr;   /**< Roman numeral string */
   public:
      Roman();
      Roman(std::string);
      Roman(int);
      ~Roman();
      void SetRoman(std::string);
      void SetRoman(int);
      void SetRomanWithAD(int);
      std::string GetRoman() const;
      int GetInt() const; 
      int GetAD() const;

      Roman& operator+=(const Roman& ); 
      Roman operator++(int); 
      Roman operator--(int); 

};

#endif

