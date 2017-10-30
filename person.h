
class Person : public Objekt
{
	//name und nummer werden von Objekt geerbt
	//name ist hier der Nachname einer Person
	//nummer ist hier die Kundennummer einer Person
	private:
		//Vorname einer Person
		string vorname;
		//Strasse einer Person
		string strasse;
		//Wohnort einer Person
		string wohnort;
	
	public:
	//Konstruktor
	Person()
	{
		vorname="";
		name="";
		strasse="";
		wohnort="";
		nummer="";
	}
	
	//Konstruktor
	Person(string vorn,string nachn,string str,string wohn,string kund)
	{
		vorname=vorn;
		name=nachn;
		strasse=str;
		wohnort=wohn;
		nummer=kund;
	}
	
	string get_vorname()
	{
		return vorname;
	}
		
	
	string get_strasse()
	{
		return strasse;
	}
		
	string get_wohnort()
	{
		return wohnort;
	}
	
	
	//Ausgabe aller Daten einer Person
	string print()
	{
		string output="";
		
		if(nummer.compare("") !=0)
			output = output + "Kundennummer: " + nummer;
		if(vorname.compare("") !=0)
			output = output + " Vorname: " + vorname;
		if(name.compare("") != 0)
			output = output + " Nachname: " + name;
		if(strasse.compare("") != 0)
			output = output + " Strasse: " + strasse;
		if(wohnort.compare("") != 0)
			output = output + " Wohnort: " + wohnort;
		return output;	
	}
	
	//alle Daten einer Person werden in einen string geschrieben und durch ein @ getrennt
	string daten_speichern()
	{
		string output="";
		output = output + vorname +"@";
		output = output + name +"@";
		output = output + strasse +"@";
		output = output + wohnort +"@";
		output = output  + nummer;
		return output;	
	}	
		
};
