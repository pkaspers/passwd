#ifndef OPCJEWYWOLANIA_HH
#define OPCJEWYWOLANIA_HH

#include <iostream>
#include <string>

/*!
 * \brief Definiuje zbiór wartości określających rodzaje sortowania
 *
 * Niniejszy typ jest zestawieniem wartości, które reprezentują
 * poszczególne rodzaje sortowania listy użytkowników.
 */
enum TypSortowania { TS_WgNazwisk /*! Sortowanie wg nazwisk, imion i loginow */, 
                     TS_WgLoginow /*! Sortowanie wg loginów */,  
                     TS_WgIdUzytkownika /*! Sortowanie wg identyfikatorów użytkowników */
                   };

/*!
 * \brief Wyświetla nazwę symbolu typu TypSortowania
 *
 * Przekształca na tekst i wyświetla w takiej postaci nazwę podanego elementu
 * typu TypSortowania.
 * \param[in,out] StrmWy - strumień wyjściowy, do którego jest wpisywany tekst
 *                         odpowiadający danemu elementowi typu TypSortowania.
 * \param[in] TSort - element typu TypSortowania, dla którego odpowiadający
 *                        mu tekst ma zostać wpisany do strumienia wyjściowego.
 * \return Strumień wyjściowy, który przekazany jest jako pierwszy parametr.
 */
inline
std::ostream& operator << (std::ostream& StrmWy, TypSortowania  TSort)
{
  const char *TabNapisow[] = { "TS_WgNazwisk", "TS_WgLoginow", "TS_WgIdUzytkownika" };
  StrmWy << TabNapisow[TSort];
  return StrmWy;
}

/*!
 * \brief Definiuje zbiór wartości określających kryteria wyszukiwania użytkownika
 *
 * Niniejszy typ jest zestawieniem wartości, które reprezentują
 * poszczególne sposoby wyszukiwania użytkownika.
 */
enum TypSzukania {
  TSz_NajwiekszyId  /*! Wyszukiwany jest użytkownik, o największym Id */,
  TSz_Login         /*! Wyszukiwany jest użytkownik o zadanym loginie */,
  TSz_IdUzytkownika /*! Wyszukiwany jest użytkownik o zadanym identyfikatorze */
};


/*!
 * \brief Wyświetla nazwę symbolu typu TypSzukania
 *
 * Przekształca na tekst i wyświetla w takiej postaci nazwę podanego elementu
 * typu TypSzukania.
 * \param[in,out] StrmWy - strumień wyjściowy, do którego jest wpisywany tekst
 *                         odpowiadający danemu elementowi typu TypSzukania.
 * \param[in] TSzukania - element typu TypSzukania, dla którego odpowiadający
 *                        mu tekst ma zostać wpisany do strumienia wyjściowego.
 * \return Strumień wyjściowy, który przekazany jest jako pierwszy parametr.
 */
inline
std::ostream& operator << (std::ostream& StrmWy, TypSzukania  TSzukania)
{
  const char *TabNapisow[] = 
            { "TSz_NajwiekszyId", "TSz_Login", "TSz_IdUzytkownika" };

  StrmWy << TabNapisow[TSzukania];
  return StrmWy;
}




/*!
 * \brief Moduje zbiór wartości opcji wywołania programu
 *
 * Modeluje zbiór wartości opcji, z którymi może zostać
 * wyowłany program. Udostępnia odpowiedni interfejs,
 * który pozwala odczytać wartości opcji.
 */
class OpcjeWywolania {
  public:
   /*!
    * \brief Inicjalizuje domyślne wartości dla poszczególnych pól
    *
    * Inicjalizuje obiekt w następujący sposób:
    *  \li rodzaj sortowania - wg nazwisk
    *  \li rodzaj szukania - użytkownik o największej liczbie grup
    */
   OpcjeWywolania(): _RodzajSortowania(TS_WgNazwisk), _IdUzytkownika(-1)
      { }
 
   /*!
    * \brief Udostępnia login użytkownika
    *
    * Udostępnia login użytkownika. Jest to zawartość pola 
    * \link OpcjeWywolania::_Login _Login\endlink. Zawartość tego pola
    * jest istotna, gdy zostanie wybrane szukanie wg loginu.
    */ 
   const std::string& WezLogin() const { return _Login; }

   /*!
    * \brief Udostępnia identyfikator użytkownika
    *
    * Udostępnia login identyfikator użytkownika. Jest to zawartość pola 
    * \link OpcjeWywolania::_IdUzytkownika _IdUzytkownika\endlink. Zawartość tego pola
    * jest istotna, gdy zostanie wybrane szukanie wg ID użytkownika. 
    */
   int WezIdUzytkownika() const { return _IdUzytkownika; }

   /*!
    * \brief Zwraca identyfikator rodzaju szukania
    *
    * Zwaraca wartość, która informuje jakiego typu szukanie 
    * ma być zrealizowane.
    */
   TypSzukania JakSzukac() const 
    {  if (_IdUzytkownika != -1) return TSz_IdUzytkownika; 
       if (!_Login.empty()) return TSz_Login;
       return TSz_NajwiekszyId;
    }   

  /*!
   * \brief Zwraca identyfikator rodzaju sortowania
   *
   * Zwraca identyfikator określający rodzaj sortowania listy
   * użytkowników.
   */
  TypSortowania JakSortowac() const { return _RodzajSortowania; }

  /*!
   * \brief Zmienia informacje o rodzaju sortowania
   *
   *  Zmienia ustawienia rodzaju sortowania, które ma być wykonane.
   *  \param[in] RodzajSort - nowa wartość identyfikatora sortowania.
   *
   *  \post Do pola \link OpcjeWywolania::_RodzajSortowania _RodzajSortowania\endlink
   *        zostaje wpisana nowa wartość identyfikatora sortowania.
   */
   void ZmienTypSortowania( TypSortowania  RodzajSort)
                          { _RodzajSortowania = RodzajSort; }

  /*!
   * \brief Zmienia Id użytkownika, który ma być znaleziony
   *
   *   Zmienia Id użytkownika, który ma być znaleziony.
   *   \param[in] Id - nowa wartość identyfikatora użykownika.
   *
   *  \post Do pola \link OpcjeWywolania::_IdUzytkownika _IdUzytkownika\endlink
   *        zostaje wpisana nowa wartość identyfikatora uzytkownika, który
   *        ma zostać znaleziony w liście wszystkich użytkowników.
   */
   void ZmienIdUzytkownika(int Id) { _IdUzytkownika = Id; }

  /*!
   * \brief Zmienia login użytkownika, który ma być znaleziony
   *
   *   Zmienia login użytkownika, który ma być znaleziony.
   *   \param[in] sLogin - nowy login użykownika.
   *
   *  \post Do pola \link OpcjeWywolania::_Login _Login\endlink
   *        zostaje wpisana nowy login uzytkownika.
   *        Użytkownik o tym loginie 
   *        ma zostać znaleziony w liście wszystkich użytkowników.
   */  
   void ZmienLogin( const char* sLogin ) {  _Login = sLogin; }

  private:
  /*!
   * \brief Rodzaj sortowania listy użytkowników
   *
   * Przechowuje identyfikator sortowania określający sposób
   * sortowania listy użytkowników.
   */
   TypSortowania   _RodzajSortowania;
  /*!
   * \brief Identyfikator użytkownika
   *
   * Przechowuje wartość identyfikatora uzytkownika, który
   * ma zostać znaleziony w liście wszystkich użytkowników.
   * Jeżeli pole ma wartość -1, to zakłada się, że nie zawiera
   * ono żadnego identyfikatora.
   */
   int             _IdUzytkownika;
  /*!
   * \brief Login użytkownika
   *
   *  Przechowuje login uzytkownika.
   *  Użytkownik o tym loginie 
   *  ma zostać znaleziony w liście wszystkich użytkowników.
   *  Jeżeli pole zawiera napis pusty, to tym samym nie zawiera
   *  żadnego loginu.
   */
  std::string     _Login;

};


#endif
