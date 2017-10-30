#include<iostream>
#include "objekt.h"
#include "person.h"
#include "artikel.h"
#include "bestellung.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>

void personen_daten_eingabe(fstream& personen_db)
{
	//Ein fstream Objekt ist nicht kopierbar
	string vorname;
	string nachname;
	string strasse;
	string wohnort;
	string kundennummer;
	string cmp;
	//Zeilenumbruch abfangen
	getline(cin,cmp);
	
	cout<<"Geben Sie den Vornamen der Person ein"<<endl;
	getline(cin,vorname);
	cout<<"Geben Sie den Nachnamen der Person ein"<<endl;
	getline(cin,nachname);
	cout<<"Geben Sie die Strasse der Person ein"<<endl;
	getline(cin,strasse);
	cout<<"Geben Sie den Wohnort der Person ein"<<endl;
	getline(cin,wohnort);
	cout<<"Geben Sie die Kundennummer der Person ein"<<endl;
	getline(cin,kundennummer);

	Person p = Person(vorname,nachname,strasse,wohnort,kundennummer);
	//Daten einer Person werden in die Datei "personen_db.txt" geschrieben	
	personen_db<<p.daten_speichern()<<endl;
}

void artikel_daten_eingabe(fstream& artikel_db)
{
	//Daten einer Person werden in einer Datei gespeichert
	//Ein fstream Objekt ist nicht kopierbar
	string name;
	string nummer;
	string preis;
	string tmp;
	//Zeilenumbruch abfangen
	getline(cin,tmp);
	
	cout<<"Geben Sie den Namen des Artikels ein"<<endl;
	getline(cin,name);
	cout<<"Geben Sie den Preis des Artikels ein"<<endl;
	getline(cin,preis);
	cout<<"Geben Sie die Nummer des Artikels ein"<<endl;
	getline(cin,nummer);
		
	Artikel a = Artikel(name,nummer,preis);
	//Daten des Artikels werden in die Datei "artikel_db.txt" geschrieben
	artikel_db<<a.daten_speichern()<<endl;
}

void suche_person(fstream& personen_db)
{
	/*Nach Eingabe eines Nachnames und Vornamens werden in einer Datei alle Personen
	gesucht, auf welche die eingegebenen Daten zutreffen */
	vector<Person> personen_liste;
	string line;
	//die Datei "personen_db.txt" wird Zeile fuer Zeile gelesen
	while(getline(personen_db,line))
	{
		stringstream sline(line);
		vector<string> data;
		string item;
		/*jede Zeile wird in Bestandteile zerlegt, die durch ein @ getrennt werden,
		und die einzelnen Bestandteile werden in data gespeichert */
		//data enthalt also alle Daten einer Person, die in "personen_db.txt" gespeichert wurden
		while(getline(sline,item,'@'))
		{
			data.push_back(item);
		}
		
		
		
		Person p = Person(data[0],data[1],data[2],data[3],data[4]);
		//jede Person, fuer die Daten in "personen_db.txt" vorhanden sind, wird in dem vector personen_liste gespeichert
		personen_liste.push_back(p);
	}
		
		string vorn;
		string nachn;
		string tmp;
		//Zeilenumbruch abfangen
		getline(cin,tmp);
		cout<<"Geben Sie den Vornamen der zu suchenden Person ein"<<endl;
		getline(cin,vorn);
		cout<<"Geben Sie den Nachnamen der zu suchenden Person ein"<<endl;
		getline(cin,nachn);
		
		/*Wenn Vorname und Nachname angegeben wurden, werden alle Personen gesucht, welche diesen Vornamen 
		und diesen Nachnamen hat */
		if(vorn.compare("") != 0 && nachn.compare("") != 0)
		{
			for(vector<Person>::iterator it=personen_liste.begin();it != personen_liste.end();it++)
			{
				if(it->get_vorname().compare(vorn) == 0 && it->get_name().compare(nachn) == 0 )
					cout<<it->print()<<endl;
			}
		}
		
		/*Wenn nur der Vorname angegeben wurde, werden alle Personen gesucht, welche diesen Vornamen haben */
		if(vorn.compare("") != 0 && nachn.compare("") == 0)
		{
			for(vector<Person>::iterator it=personen_liste.begin();it != personen_liste.end();it++)
			{
				if(it->get_vorname().compare(vorn) == 0)
					cout<<it->print()<<endl;
			}
		}
		
		/*Wenn nur der Nachname angegeben wurde, werden alle Personen gesucht, welche diesen Nachnamen haben*/
		if(vorn.compare("") == 0 && nachn.compare("") != 0)
		{
			for(vector<Person>::iterator it=personen_liste.begin();it != personen_liste.end();it++)
			{
				if(it->get_name().compare(nachn) == 0)
					cout<<it->print()<<endl;
			}
		}
		
		/* Wenn weder Vorname noch Nachname angegeben wurden, werden alle Personen angezeigt */
		if(vorn.compare("") == 0 && nachn.compare("") == 0)
		{
			for(vector<Person>::iterator it=personen_liste.begin();it != personen_liste.end();it++)
			{
					cout<<it->print()<<endl;
			}
		}
}

void suche_artikel(fstream& artikel_db)
{
	//Nach Eingabe eines Artikelnamens werden in einer Datei alle Artikel gesucht, welche diesen Artikelnamen besitzen
	vector<Artikel> artikel_liste;
	string line;
	//die Datei "artikel_db.txt" wird Zeile fuer Zeile gelesen
	while(getline(artikel_db,line))
	{
		stringstream sline(line);
		vector<string> data;
		string item;
		/* jede gelesene Zeile wird in Bestandteile zerlegt, welche durch ein @ getrennt werden,
		und diese Bestandteile werden in data gespeichert */
		while(getline(sline,item,'@'))
		{
			data.push_back(item);
		}
		
		
		//Artikel mit den Daten aus data wird angelegt
		Artikel a = Artikel(data[0],data[2],data[1]);
		//Artikel mit den Daten aus data wird zu artikel_liste hinzugefuegt
		artikel_liste.push_back(a);
	}
		
		string name;
		string tmp;
		//Zeilenumbruch abfangen
		getline(cin,tmp);
		cout<<"Geben Sie den Namen des zu suchenden Artikels ein"<<endl;
		getline(cin,name);
		cout<<"Name: "+ name<<endl;
		
		//Wenn der Name eines Artikel angegeben wird, werden alle Artikel gesucht, welche diesen Namen haben
		if(name.compare("") != 0)
		{
			for(vector<Artikel>::iterator it=artikel_liste.begin();it != artikel_liste.end();it++)
			{
				if(it->get_name().compare(name) == 0)
					cout<<it->print()<<endl;
			}
		}
		//Wenn der Name eines Artikels nicht angegeben wird, werden alle Artikel angezeigt
		else
		{
			for(vector<Artikel>::iterator it=artikel_liste.begin();it != artikel_liste.end();it++)
			{
					cout<<it->print()<<endl;
			}
		}
		
}
	
void bestellung_speichern(fstream& personen_db,fstream& artikel_db,fstream& bestellungen_db)
{
	/* Nach Eingabe der Kundennummer der Person, welche eine Betellung ausfuehrt, der Artikelnummer des Artikels,
	der bestellt wird, und der Anzahl, wie oft der Artikel bestellt wird, werden diese Daten in einer Datei gespeichert */
	string befehl;
	string kundennummer;
	string tmp;
	//Zeilenumbruch abfangen
	getline(cin,tmp);
	/*Man hat die Moeglichkeit direkt eine Kundennummer einzugeben oder zuerst eine Kundennummer von einer Person
	zu suchen und dann erst die Kundennummer einzugeben */
	cout<<"Moechten Sie eine Kundennummer eingeben (Eingabe: 'ke') oder eine Person suchen (Eingabe: 'sup')?"<<endl;
	getline(cin,befehl);
	if(befehl.compare("ke") == 0)
	{
		cout<<"Geben Sie jetzt die Kundennummer einer Person ein"<<endl;
		getline(cin,kundennummer);
	}
	if(befehl.compare("sup") == 0)
	{
		suche_person(personen_db);
		cout<<"Geben Sie jetzt die Kundennummer einer Person ein"<<endl;
		getline(cin,kundennummer);
	}
	
	string artikelnummer;
	/*Man hat die Moeglichekeit direkt die Artikelnummer eines Artikels anzugeben oder zuerst eine Artikelnummer
	eines Artikels zu lesen und dann die Artikelnummer einzugeben */
	cout<<"Moechten Sie eine Artikelnummer eingeben (Eingabe: 'ae') oder eine Person suchen (Eingabe: 'sua')?"<<endl;
	getline(cin,befehl);
	if(befehl.compare("ae") == 0)
	{
		cout<<"Geben Sie jetzt die Artikelnummer eines Artikels ein"<<endl;
		getline(cin,artikelnummer);
	}
	if(befehl.compare("sua") == 0)
	{
		suche_artikel(artikel_db);
		cout<<"Geben Sie jetzt die Artikelnummer eines Artikels ein"<<endl;
		getline(cin,artikelnummer);
	}
	
	//in anzahl wird gespeichert welche Anzahl des Artikels bestellt wird
	string anzahl;
	cout<<"Welche Anzahl dieses Artiekls soll bestellt werden?"<<endl;
	getline(cin,anzahl);
		
	//die Kundennummer der Person, die bestellt, die Artikelnummer des Artikels, der bestellt wird, und die Anzahl
	/*des Artikels, werden in der Datei "bestellungen_db.txt" gespeichert. Um die Informationen zu trennen, wird 
	zwischen ihnen ein @ eingefuegt */
	string bestellung = kundennummer + "@" + artikelnummer + "@" + anzahl;
	bestellungen_db<<bestellung<<endl;
	
	
}

void bestellungen_person(fstream& personen_db,fstream& artikel_db,fstream& bestellungen_db)
{
	/*Nach Eingabe einer Kundennummer, werden alle Bestellungen in einer Datenbank gesucht, welche
	der Kunde mit dieser Kundennummer bestellt hat */
	string befehl;
	string preis;
	string kundennummer; 
	string anzahl;
	string tmp;
	float summe=0;
	
	
	//die Datei "artikel_db" wird Zeile fuer Zeile gelesen
	vector<Artikel> artikel_liste;
	string line;
	while(getline(artikel_db,line))
	{
		/*jede Zeile wird in Bestandteile zerlegt, die durch ein @ getrennt werden,
		und diese Bestandteile werden in data gespeichert */
		stringstream sline(line);
		vector<string> data;
		string item;
		while(getline(sline,item,'@'))
		{
			data.push_back(item);
		}
		
		
		
		Artikel a = Artikel(data[0],data[2],data[1]);
		//der Artikel a, welcher alle Informationen aus data enthaelt wird, wird zu artikel_liste hinzugefuegt
		artikel_liste.push_back(a);
	}
	//Zeilenumbruch abfangen
	getline(cin,tmp);
	/*Man hat die Moeglichkeit zu entscheiden, ob man direkt eine Kundennummer eingeben moechte oder ob man zuerst
	die Kundennummer einer Person sucht und die Kundennummer dann eingbit */
	cout<<"Moechten Sie eine Kundennummer eingaben (Eingabe: 'ke') oder eine Person suchen (Eingabe: 'sup')"<<endl;
	getline(cin,befehl);
	if(befehl.compare("ke") == 0)
	{
		cout<<"Geben Sie die Kundennummer ein"<<endl;	
		getline(cin,kundennummer);		
	}
	if(befehl.compare("sup") == 0)
	{
		suche_person(personen_db);
		cout<<"Geben Sie die Kundennummer ein"<<endl;	
		getline(cin,kundennummer);	
	}
	
	vector<Bestellung> bestellungen_liste;
	//die Datei "bestellungen_db.txt" wird Zeile fuer Zeile gelesen
	while(getline(bestellungen_db,line))
	{
		/*jede Zeile wird in Bestandteile zerlegt, die durch ein @ getrennt werden,
		und diese Bestandteile werden in data gespeichert */
		stringstream sline(line);
		vector<string> data;
		string item;
		while(getline(sline,item,'@'))
		{
			data.push_back(item);
		}
		
		
		
		Bestellung b = Bestellung(data[0],data[1],data[2]);
		//die Bestellung b, welche alle Informationen aus data enthaelt, wird in bestellungen_liste gespeichert
		bestellungen_liste.push_back(b);
	}
	
	/*in bestellungen_pro_person werden diejenigen Bestellungen gespeichert, die von der Person bestellt wurde,
	dessen Kundennummer kundennummer ist */
	vector<Bestellung> bestellungen_pro_person;
	for(vector<Bestellung>::iterator it=bestellungen_liste.begin();it != bestellungen_liste.end();it++)
	{
		if(it->get_kundennummer().compare(kundennummer) == 0)
		{
			bestellungen_pro_person.push_back(*it);
		}
	}
	
	//fuer jede Bestellung in bestellungen_pro_person werden Name und Preis des bestellten Artikels ermittelt
	//ausserdem wird der Gesamtpreis fuer jede Bestellung sowie die Preissumme aller Bestellungen aus bestellungen_pro_person ermittelt 
	for(vector<Bestellung>::iterator it=bestellungen_pro_person.begin(); it != bestellungen_pro_person.end();it++)
	{
		string artikelnummer = it->get_artikelnummer();
		string artikelname;
			
		//Artikelname und Preis werden aus artikel_liste gelesen	
		for(vector<Artikel>::iterator it2=artikel_liste.begin();it2 != artikel_liste.end();it2++)
		{
			if(it2->get_nummer().compare(artikelnummer) == 0)
			{
				artikelname=it2->get_name();
				preis=it2->get_preis();
			}
		}
		
		//preis wird in float konvertiert
		float preisf;	
		stringstream preisfs;
		preisfs<<preis;
		preisfs>>preisf;
			
		//anzahl wird in float umgewandelt
		string anzahl = it->get_anzahl();
		float anzahlf;
		stringstream anzahlfs;
		anzahlfs<<anzahl;
		anzahlfs>>anzahlf;
		
		//Gesamtpreis wird ermittelt	
		float gesamtpreis = preisf*anzahlf;
		//die Kosten aller Bestellungen einer Person werden ermittelt
		summe += gesamtpreis;

		//alle Informationen zur Bestellung werden ermittelt	
		cout<<"Artikelname: " + artikelname + " Anzahl: " + anzahl + " Einzelpreis: " + preis + " Gesamtpreis: "<<gesamtpreis<<endl;
			
		

	}
	cout<<"Summe: "<<summe<<endl;
	
	
	
}

void bestellungen_artikel(fstream& personen_db,fstream& artikel_db,fstream& bestellungen_db)
{
	/* Nach Eingabe einer Artikelnummer, werden alle Bestellungen gesucht, in welchen der Artikel mit dieser Artikelnummer
	bestellt wurde*/
	string befehl;
	string artikelnummer;
	string kundennummer;
	string preis;
	string gesamtpreis;
	string anzahl;
	string kundenname;
	string tmp;
	float summe=0;

	/*da moeglicherweise spaeter eine Artikelnummer gesucht wird, wird die Datei "artikel_db" moeglicherweise zweimal gelesen
	Weil bei dem zweiten Lesen dort angefangen wird, wo beim ersten Lesen Schluss war, wird die Datei "artikel_db" beim 
	zweiten Lesen nicht vollstaendig oder gar nicht gelesen. Aus diesem Grund wird hier ein neues ifstream-Objekt angelegt */
	ifstream artikel_db_file("artikel_db.txt");
	vector<Artikel> artikel_liste;
	string line;
	//die Datei "artikel_db.txt" wird Zeile fuer Zeile gelesen
	while(getline(artikel_db_file,line))
	{
		/*jede Zeile wird in Bestandteile zerlegt, welche durch ein @ getrennt werden,
		und diese Bestandteile werden in data gespeichert */
		stringstream sline(line);
		vector<string> data;
		string item;
		while(getline(sline,item,'@'))
		{
			data.push_back(item);
		}
		
		
		Artikel a = Artikel(data[0],data[2],data[1]);
		//der Artikel a, welcher alle Informationen aus data enthaelt, wird in artikel_liste gespeichert
		artikel_liste.push_back(a);
	}	

	//Zeilenumbruch abfangen
	getline(cin,tmp);
	/*Man kann auswaehlen, ob man direkt eine Artikelnummer eingibt oder ob man zuerst die Artikelnummer eines Artikels
	suchen laesst und dann die Artikelnummer eingibt*/
	cout<<"Moechten Sie die Artikelnummer eingeben (Eingabe:'ae') oder moechten Sie einen Artikel suchen (Eingabe 'sua')"<<endl;
	getline(cin,befehl);
	if(befehl.compare("ae") == 0)
	{
		cout<<"Geben Sie jetzt die Artikelnummer ein"<<endl;
		getline(cin,artikelnummer);	
	}
	if(befehl.compare("sua") == 0)
	{
		suche_artikel(artikel_db);
		cout<<"Geben Sie jetzt die Artikelnummer ein"<<endl;
		getline(cin,artikelnummer);	
	}
	
	vector<Person> personen_liste;
	//die Datein "personen_db.txt" wird Zeile fuer Zeile gelesen
	while(getline(personen_db,line))
	{
		/*jede Zeile wird in Bestandteile zerlegt, welche durch ein @ getrennt werden,
		und diese Bestandteile werden in data gespeichert */
		stringstream sline(line);
		vector<string> data;
		string item;
		while(getline(sline,item,'@'))
		{
			data.push_back(item);
		}
		
		
		
		Person p = Person(data[0],data[1],data[2],data[3],data[4]);
		//die Person p, welche alle Informationen aus data enthaelt, wird in personen_liste gespeichert
		personen_liste.push_back(p);
	}
	
	
	
	//der Preis des ausgewaehlten Artikels wird ermittelt
	for(vector<Artikel>::iterator it=artikel_liste.begin();it != artikel_liste.end();it++)
	{
		if(it->get_nummer().compare(artikelnummer) == 0)
		{
			preis = it->get_preis();
		}
	}	
	
	vector<Bestellung> bestellungen_liste;
	//die Datei "bestellungen_db.txt" wird Zeile fuer Zeile gelesen
	while(getline(bestellungen_db,line))
	{
		/*jede Zeile wird in Bestandteile zerlegt, welche durch ein @ getrennt sind,
		und diese Bestandteile werden in data gespeichert */
		stringstream sline(line);
		vector<string> data;
		string item;
		while(getline(sline,item,'@'))
		{
			data.push_back(item);
		}
		
		
		
		Bestellung b = Bestellung(data[0],data[1],data[2]);
		//die Bestellung b, welche alle Informationen aus data enthaelt, wird in bestellungen_liste gespeichert
		bestellungen_liste.push_back(b);
	}
	
	//in bestellungen_pro_artikel werden alle Bestellungen gespeichert, in welchen der ausgewaehlte Artikel bestellt wurde
	vector<Bestellung> bestellungen_pro_artikel;
	for(vector<Bestellung>::iterator it=bestellungen_liste.begin();it != bestellungen_liste.end();it++)
	{
		if(it->get_artikelnummer().compare(artikelnummer) == 0)
		{
			bestellungen_pro_artikel.push_back(*it);
		}
	}
	
	/*fuer jede Bestellung in bestellungen_pro_artikel wird der Name des Kunden, der die Bestellung vorgenommen hat,
	ermittelt. Ausserdem wird der Gesamtpreis  und die Anzahl jeder Bestellung und die Preissumme aller Bestellungen aus bestellung_pro_artikel ermittelt */
	for(vector<Bestellung>::iterator it=bestellungen_pro_artikel.begin();it != bestellungen_pro_artikel.end();it++)
	{
		kundennummer=it->get_kundennummer();
		anzahl=it->get_anzahl();
		
		for(vector<Person>::iterator it2=personen_liste.begin();it2 != personen_liste.end();it2++)
		{
			if(it2->get_nummer().compare(kundennummer) == 0)
			{
				kundenname = it2->get_name() + " " + it2->get_vorname();	
			}
		}
		
		//preis wird in float umgewandelt
		float preisf;	
		stringstream preisfs;
		preisfs<<preis;
		preisfs>>preisf;
			
		//anzahl wird in float umgewandelt
		string anzahl = it->get_anzahl();
		float anzahlf;
		stringstream anzahlfs;
		anzahlfs<<anzahl;
		anzahlfs>>anzahlf;
		
		//Gesamtpreis wird bestimmt
		float gesamtpreis = anzahlf*preisf;
		//Summe aller Bestellungen wird ermittelt
		summe += gesamtpreis;
		cout<<"Kundenname: " + kundenname + " Anzahl: " + anzahl+ " Einzelpreis: " + preis + " Gesamtpreis: "<<gesamtpreis<<endl;
	}
	cout<<"Summe: "<<summe<<endl;
	
}

int main()
{
	
	while(true)
	{
		//es wird solange ein Befehl eingelesen bis durch den Befehl "exit" abgebrochen wird
		
		//die Datei "personen_db" enthaelt alle Informationen zu den Kunden
		fstream personen_db;		
		//in personen_db soll Text hinten eingefuegt werden und gelesen werden
		personen_db.open("personen_db.txt",ios::app | ios::in);

		//die Datei "artikel_db" enthaelt alle Informationen zu den Artikeln
		fstream artikel_db;
		//in personen_db soll Text hinten eingefuegt werden und gelesen werden
		artikel_db.open("artikel_db.txt",ios::app | ios::in);
		
		//die Datei "bestellungen_db" enthaelt alle Informationen zu den Bestellungen
		fstream bestellungen_db;
		//in bestellungen.db sollen Text hinten eingefuegt werden und gelesen werden
		bestellungen_db.open("bestellungen_db.txt",ios::app | ios::in);
		
		string befehl="";
	
		cout<<"Befehle: "<<endl;
		cout<<"sp: eine Person speichern"<<endl;
		cout<<"sup: eine Person suchen"<<endl;
		cout<<"sa: einen Artikel speichern"<<endl;
		cout<<"sua: einen Artikel suchen"<<endl;
		cout<<"sb: eine Bestellung speichern"<<endl;
		cout<<"bp: Bestellungen pro Person anzeigen"<<endl;
		cout<<"ba: Bestellungen pro Artikel anzeigen"<<endl;
		cout<<"exit: Programm beenden"<<endl;
		cout<<endl;
		cout<<"Geben Sie einen Befehl ein!"<<endl;
		cin>>befehl;
		//Programm wird abgebrochen
		if(befehl.compare("exit") == 0)
			break;
		//Person wird gespeichert
		if(befehl.compare("sp") == 0)
		{
			personen_daten_eingabe(personen_db);
		}
		//Person wird gesucht
		if(befehl.compare("sup") == 0)
		{
			suche_person(personen_db);
		}
		//Artikel wird gespeichertn
		if(befehl.compare("sa") == 0)
		{
			artikel_daten_eingabe(artikel_db);
		}
		//Artikel wird gesucht
		if(befehl.compare("sua") ==0)
		{
			suche_artikel(artikel_db);
		}
		//Bestellung wird gespeichert
		if(befehl.compare("sb") == 0)
		{
			bestellung_speichern(personen_db,artikel_db,bestellungen_db);
		}
		//alle Bestellungen, die ein Kunde ausgefuehrt hat, werden aufgelistet
		if(befehl.compare("bp") == 0)
		{
			bestellungen_person(personen_db,artikel_db,bestellungen_db);
		}
		//alle Bestellungen eines Artikels werden aufgelistet
		if(befehl.compare("ba") == 0)
		{
			bestellungen_artikel(personen_db,artikel_db,bestellungen_db);
		}
		
		//Dateien werden geschlossen
		artikel_db.close();
		personen_db.close();
		bestellungen_db.close();
	}
	return 0;
}
