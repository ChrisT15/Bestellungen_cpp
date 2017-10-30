class Artikel : public Objekt
{
	//Artikel erbt name und nummer von Objekt
	//hier ist name der Artikelname und nummer die Artikelnummer
	private:
		//Preis eines Artikels
		string preis;
	public:
		
		//Konstruktor
		Artikel()
		{
			name="";
			nummer="";
			preis="";
		}
		
		//Konstruktor
		Artikel(string _name,string _nummer,string _preis)
		{
			name=_name;
			nummer=_nummer;
			preis=_preis;			
		}

		string get_preis()
		{
			return preis;
		}
		
		//Ausgabe aller Informationen eines Artikels
		string print()
		{
			string output="";
			if(nummer.compare("") != 0)
			{
				output = output + "Artikelnummer: " + nummer;
			}
			if(name.compare("") != 0)
			{
				output = output + " Name: " + name;
			}
			if(preis.compare("") != 0)
			{
				output = output + " Preis: " + preis;
			}
				return output;
			
		}
		
		//alle Daten eines Artikels werden in einen string geschrieben und durch ein @ getrennt
		string daten_speichern()
		{
			string output="";
			output = output + name + "@";
			output = output + preis + "@";
			output = output + nummer;
			return output;
		}		
		
};
