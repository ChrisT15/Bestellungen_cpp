#include "string.h"
using namespace std;

class Objekt
{
	protected:
		//Name eines Objekts
		string name;
		//Nummer eines Objekts
		string nummer;
	public:
		string get_name()
		{
			return name;
		}
		string get_nummer()
		{
			return nummer;
		}
		
		void set_name(string name_)
		{
			name=name_;
		}
		
		void set_nummer(string nummer_)
		{
			nummer=nummer_;
		}
		

};
