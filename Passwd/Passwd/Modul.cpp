#include "inc/OpcjeWywolania.hh"

using namespace std;

void PrzetworzListe_Uzytkownikow_i_Grupy(const OpcjeWywolania& Opcje)
 {
  cout << endl;
  cout << "Wywolanie przetwarzania listy uzytkownikow." << endl << endl;
  cout << "  Rodzaj sortowania: " << Opcje.JakSortowac() << endl;
  cout << "    Rodzaj szukania: " << Opcje.JakSzukac() << endl;
  cout << endl;
  cout << "              Login: \"" << Opcje.WezLogin() << "\"" << endl;                 
  cout << "                 Id: " << Opcje.WezIdUzytkownika() << endl;                   
  cout << endl;  
 }