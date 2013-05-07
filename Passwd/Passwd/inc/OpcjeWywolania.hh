#ifndef OPCJEWYWOLANIA_HH
#define OPCJEWYWOLANIA_HH

#include <iostream>
#include <string>

enum TypSortowania { TS_WgNazwisk , 
                     TS_WgLoginow ,  
                     TS_WgIdUzytkownika 
                   };

inline
std::ostream& operator << (std::ostream& StrmWy, TypSortowania  TSort)
{
  const char *TabNapisow[] = { "TS_WgNazwisk", "TS_WgLoginow", "TS_WgIdUzytkownika" };
  StrmWy << TabNapisow[TSort];
  return StrmWy;
}

enum TypSzukania {
  TSz_NajwiekszyId  ,
  TSz_Login         ,
  TSz_IdUzytkownika 
};


inline
std::ostream& operator << (std::ostream& StrmWy, TypSzukania  TSzukania)
{
  const char *TabNapisow[] = 
            { "TSz_NajwiekszyId", "TSz_Login", "TSz_IdUzytkownika" };

  StrmWy << TabNapisow[TSzukania];
  return StrmWy;
}




class OpcjeWywolania {
  public:
   OpcjeWywolania(): _RodzajSortowania(TS_WgNazwisk), _IdUzytkownika(-1)
      { }
 
   const std::string& WezLogin() const { return _Login; }

   int WezIdUzytkownika() const { return _IdUzytkownika; }

   TypSzukania JakSzukac() const 
    {  if (_IdUzytkownika != -1) return TSz_IdUzytkownika; 
       if (!_Login.empty()) return TSz_Login;
       return TSz_NajwiekszyId;
    }   

  TypSortowania JakSortowac() const { return _RodzajSortowania; }

   void ZmienTypSortowania( TypSortowania  RodzajSort)
                          { _RodzajSortowania = RodzajSort; }

   void ZmienIdUzytkownika(int Id) { _IdUzytkownika = Id; }

   void ZmienLogin( const char* sLogin ) {  _Login = sLogin; }

  private:
   TypSortowania   _RodzajSortowania;
   int             _IdUzytkownika;
  std::string     _Login;

};


#endif