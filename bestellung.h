class Bestellung
{
	private:
		//Kundennummer der Person, die bestellt hat
		string kundennummer;
		//Artikelnummer des Artikels, der bestellt wurde
		string artikelnummer;
		//Anzahl des bestellten Artikels
		string anzahl;
	public:
	
	//Konstruktor
	Bestellung()
	{
		kundennummer="";
		artikelnummer="";
		anzahl="";
	}
	
	//Konstruktor
	Bestellung(string knr,string anr,string anz)
	{
		kundennummer=knr;
		artikelnummer=anr;
		anzahl=anz;
	}	
		
	string get_kundennummer()
	{
		return kundennummer;
	}
	
	string get_artikelnummer()
	{
		return artikelnummer;
	}
	
	string get_anzahl()
	{
		return anzahl;
	}
	
	
	
};
