//File created on 04/22/2015 10:15 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Implementation with definitions for Jukebox.h
// Name: Jukebox.cpp
#include "Jukebox.h"

//***************************************************************************************************************************************************************************************
//Constructors & destructor
//***************************************************************************************************************************************************************************************
//
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: Jukebox
//Task: Default constructor
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Jukebox::Jukebox()
{
	albumList;

	fileMenu.setMenuHeading("*** FILE ***");
	albumAddMenu.setMenuHeading("** Add Album **");
	albumDelMenu.setMenuHeading("** Remove Album **");
	printMenu.setMenuHeading("*** PRINT ***");
	playMenu.setMenuHeading("*** PLAY ***");
	runMenu.setMenuHeading("*** JUKEBOX ***");

	playlist;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: Jukebox
//Task: Initiate data members
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Jukebox::Jukebox(vector<Album> pAlbumList, Menu pFileMenu, Menu pAlbumAddMenu, Menu pAlbumDelMenu, Menu pPrintMenu, Menu pPlayMenu, Menu pRunMenu, Queue pPlaylist)
{
	albumList = pAlbumList;
	fileMenu = pFileMenu;
	albumAddMenu = pAlbumAddMenu;
	albumDelMenu = pAlbumDelMenu;
	printMenu = pPrintMenu;
	playMenu = pPlayMenu;
	runMenu = pRunMenu;
	playlist = pPlaylist;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: ~Album
//Task: Destructor
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Jukebox::~Jukebox()
{
}
//_______________________________________________________________________________________________________________________________________________________________________________________


//***************************************************************************************************************************************************************************************
//Member function definitions
//***************************************************************************************************************************************************************************************
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: addAlbum
//Task: Adds album
//Input: 
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Jukebox::addAlbum(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";					//primitive screen flush
	cout << albumAddMenu.getMenuHeading() << endl << endl;					//print heading of menu item

	Album tmpAlbum;
	string tmpName;
	cout << "Please enter appropriate information below:\n"
		 << "Album name: ";
	cin.ignore();
	getline(cin, tmpName);													//get user input: album name
	tmpAlbum.setName(tmpName);												//set album name

	bool again = false;
	do{
		string tmpTitle, tmpArtist;
		int tmpHour, tmpMin, tmpSec;
		
		cout << "Song Title: ";
		getline(cin, tmpTitle);												//user input: song title
		cout << "Artist Name: ";
		getline(cin, tmpArtist);											//user input: artist
		cout << "hours: ";
		cin >> tmpHour;														//user input: hours
		cout << "minutes: ";
		cin >> tmpMin;														//user input: minutes
		cout << "seconds: ";
		cin >> tmpSec;														//user input: seconds

		Time tmpLength;														//set time values
		tmpLength.setHours(tmpHour);
		tmpLength.setMinutes(tmpMin);
		tmpLength.setSeconds(tmpSec);
		Song tmpSong;														//set song info
		tmpSong.setTitle(tmpTitle);
		tmpSong.setArtist(tmpArtist);
		tmpSong.setTime(tmpLength);
		
		tmpAlbum.addSong(tmpSong);											//add song to album

		char yOrN;
		cout << "Another song? (Y/N)";
		cin >> yOrN;
		if (yOrN == 'y' || yOrN == 'Y'){
			cout << endl;
			cin.ignore();
			again = true;
		}
		else{
			again = false;
		}
	} while (again);

	albumList.push_back(tmpAlbum);											//add album to album vector
	cout << endl << " " << tmpAlbum.getName() << " added!" << endl << endl;
	
	cout << "Press enter for main menu...";									//continue when user is ready
	cin.ignore();
	cin.get();
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: removeAlbum
//Task: Searches for and removes album
//Input: 
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Jukebox::removeAlbum(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";					//-
	cout << albumDelMenu.getMenuHeading() << endl << endl;					//-

	string albumName;
	cout << "Which album would you like to remove? " << endl;
	cout << "Album name: ";
	cin >> albumName;														//user input: album name to search for
	
	vector<Album>::iterator it = find_if(albumList.begin(), albumList.end(), [albumName](const Album &a1){return a1.getName() == albumName; });	//iterate with lambda
	if (it != albumList.end()){												//if corresponding album object was found
		albumList.erase(it);												//	erase it
		cout << " " << albumName << " has been removed!" << endl;	
	}
	else{
		cout << "Error: Couldn't remove " << albumName << " from album list" << endl;
	}
	
	cout << "Press enter for main menu...";									//-
	cin.ignore();
	cin.get();
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: file
//Task: Handles opening from-, and saving to, file
//Input: 
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Jukebox::file(){
	if (fileMenu.getMenuItem().empty()){									//if filemenu doesn't have any items (first run through): add appropriate menu items with evailability
		fileMenu.addItem("Open", true);											//	open is available from start
		fileMenu.addItem("Save", false);										//	save is not available until there is something to save (ie: open has been called)
		fileMenu.addItem("Back to main menu", true);							//	backing out is available from start
	}

	const string fileName = "jukebox.txt";										//file name is decided (load if available, if not: create file)
	bool again = true;
	do{
		fileMenu.printMenuItems();												//print menu items from file menu
		switch (fileMenu.getMenuchoice())										//allow user to choose between items 
		{
		case '1':{																//(scope is a bit ill-formed, but wth let's just roll like this)
					//Open
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";		//flush
					int i = 0;
					fstream inFile(fileName, ios::in);							//open file
					while (inFile.peek() != EOF){								//read entire file
						if (i == 0){											//clear in case it's filled
							albumList.clear();												
							i++;
						}
						Album tmpAlbum;
						inFile >> tmpAlbum;										//read into temporary album
						albumList.push_back(tmpAlbum);							//add temp to album list

						string tmpString = " ''" + tmpAlbum.getName() + "''";
						cout << setw(54) << left << tmpString << setw(15) << right << "\t ...added[OK]" << endl;	//user feedback
					}
					inFile.close();												//close file
					
					//enable ''save'' 
					if (!(fileMenu.getEnabled("Save"))){						//if save menu isn't available yet: make it so from here on out
						fileMenu.setEnabled("Save", true);
					}

					cout << endl << "Press Enter for file menu...";				//-
					cin.ignore();
					cin.get();
		}
			break;
		case '2':{
					 if (fileMenu.getEnabled("Save")){
						 //Save
						 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
						 fstream outFile(fileName, ios::out);					//open file
						 for (auto idx : albumList){							//iterate through album vector
							 outFile << idx;
							 cout << " " << idx.getName() << " saved" << endl;	//write to file
						 }
						 outFile.close();										//close file
					 }
					 else{
						 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
							  << endl << "Menu not available. Please use ''Open'', then try again." << endl;
					 }

					 cout << endl << "Press Enter for file menu...";			//-
					 cin.ignore();
					 cin.get();
		}
			break;
		case '3':	//Back to main menu
		case 'q':
		case 'Q':
		case 'e':
		case 'E': again = false;
		}
	} while (again);
	

}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: print
//Task: Handles printing of different items in different formats
//Input: 
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Jukebox::print(){
	if (printMenu.getMenuItem().empty()){																				//-
		printMenu.addItem("Print one album", true);
		printMenu.addItem("Print all sorted by album name", true);
		printMenu.addItem("Print all sorted by album total time", true);
		printMenu.addItem("Print simple sorted by album name", true);
		printMenu.addItem("Print simple sorted by album total time", true);
		printMenu.addItem("Back to main menu", true);
	}
	
	bool again = true;
	do{
		printMenu.printMenuItems();																						//-
		switch (printMenu.getMenuchoice())																				//-
		{
		case '1':{	//Print album to screen. All Album info.
					 string albumName;
					 cout << "Album name: ";
					 cin.ignore();
					 getline(cin, albumName);																			//-

					 vector<Album>::iterator it = find_if(albumList.begin(), albumList.end(), [albumName](const Album &a1){return a1.getName() == albumName; });	//-
					 if (it != albumList.end()){																		//-
						 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"													//flush
							 << "Please view " << albumName << "'s contents below:" << endl << endl;					//user feedback to help orient
						 Sleep(1500);																					//give time to read feedback

						 cout << endl << " " << it->getName() << endl;													//print album name
						 int num = 1;
						 for (auto idx : it->getSonglist()){															//iterate through album's songlist
							 cout << " " << setw(2) << right << num << ". "												//print album information (songs)
								 << setw(50) << left << idx.getTitle() 
								 << setw(15) << idx.getArtist()
								 << setw(5) << it->getFormatedTime(idx.getTime()) << endl;								//format time as HH:MM:SS (really as (M)M:SS)
							 num++;
						 }
					 }
					 else{
						 cout << "Album not available!" << endl;
					 }

					 cout << endl << "Press Enter for print menu...";													//-
					 cin.ignore();
					 cin.get();
		}
			break;
		case '2':{	//Print all albums sorted alphabetically. All Album info.
					 vector<Album> alphabeticalAlbumList = albumList;													//copy albumlist to avoid reorganizing original
					 sort(alphabeticalAlbumList.begin(), alphabeticalAlbumList.end(), compareNames);					//use sort algorithm to sort by name (case sensitive)

					 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"											//-
						 << "Please view all albums and their contents sorted alphabetically by name below:" << endl << endl;	//-
					 Sleep(2000);																						//-
					 int albumCounter = 0;
					 for (auto idx : alphabeticalAlbumList){															//iterate through newly sorted album list
						 cout << endl << " " << idx.getName() << endl;													//print album name
						 Sleep(500);																					// followed by short pause
						 albumCounter++;

						 int num = 1;
						 for (auto idx2 : idx.getSonglist()){															//-
							cout << " " << setw(2) << right << num << ". "												//-
								 << setw(50) << left << idx2.getTitle() << "\t"
								 << setw(15) << idx2.getArtist() << "\t"
								 << setw(5) << idx.getFormatedTime(idx2.getTime()) << endl;								//
							num++;
						 }

						 if (albumCounter < alphabeticalAlbumList.size()){												//simulate loading because juke boxes are old skool
							 cout << endl;
							 for (int i = 0; i < 3; i++){
								 Sleep(500);
								 cout << " .";																			//print 3 dots every half second
								 if (i == 2){
									 Sleep(500);
								 }
							 }
							 cout << endl;
						 } 
					 }

					 cout << endl << "Press Enter for print menu...";													//-
					 cin.ignore();
					 cin.get();
		}
			break;
		case '3':{	//Print all albums sorted by total length for each album. Longest first. All album info.
					 vector<Album> lengthWiseAlbumList = albumList;														//-
					 sort(lengthWiseAlbumList.begin(), lengthWiseAlbumList.end());										//sort by size using '<' overload 
					 reverse(lengthWiseAlbumList.begin(), lengthWiseAlbumList.end());									//reverse order to get longest first
					 
					 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"											//-
						 << "Please view all albums and their entire contents sorted by total length below:" << endl << endl;	//-
					 Sleep(2000);
					 int albumCounter = 0;

					 for (auto idx : lengthWiseAlbumList){																//-
						 cout << endl << " " << idx.getName() << endl;
						 Sleep(500);
						 albumCounter++;

						 int num = 1;
						 for (auto idx2 : idx.getSonglist()){															//-
							 cout << " " << setw(2) << right << num << ". "
								 << setw(50) << left << idx2.getTitle() << "\t"
								 << setw(15) << idx2.getArtist() << "\t"
								 << setw(5) << idx.getFormatedTime(idx2.getTime()) << endl;								//-
							 num++;
						 }
						 if (albumCounter < lengthWiseAlbumList.size()){												//-
							 cout << endl;
							 for (int i = 0; i < 3; i++){
								 Sleep(500);
								 cout << " .";																			//-
								 if (i == 2){
									 Sleep(500);
								 }
							 }
							 cout << endl;
						 }
					 }

					 cout << endl << "Press Enter for print menu...";													//-
					 cin.ignore();
					 cin.get();
		}
			break;
		case '4':{	//Print all albums sorted alphabetically. use for_each() due to oddly specific (but good) detail in requirements specification. Only names.
					 vector<Album> alphabeticalAlbumList = albumList;													//-
					 sort(alphabeticalAlbumList.begin(), alphabeticalAlbumList.end(), compareNames);					//-

					 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"												//-
						 << "Please view all albums sorted alphabetically by name below:" << endl << endl;				//-
					 Sleep(1500);
					 int num = 1; 
					 for_each(alphabeticalAlbumList.begin(), alphabeticalAlbumList.end(), [&num](Album const &album){	//for each album in newly sorted list
						 cout << " " << setw(2) << num << ". " << album.getName() << endl;								//	print album name
						 num++;																							//(index sent through lambda's capture list. might be frowned upon)
					 }); 
				
					 cout << endl << "Press Enter for print menu...";													//-
					 cin.ignore();
					 cin.get();
		}
			break;
		case '5':{	//Print all albums sorted by total length for each album. Longest first. Name and total length.
					 vector<Album> lengthWiseAlbumList = albumList;														//-
					 sort(lengthWiseAlbumList.begin(), lengthWiseAlbumList.end());										//- 
					 reverse(lengthWiseAlbumList.begin(), lengthWiseAlbumList.end());									//-

					 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"												//-
						 << "Please view all albums sorted by total length below:" << endl << endl;						//-
					 Sleep(1500);
					 int num = 1;
					 for (auto idx : lengthWiseAlbumList){																//-
						 Time tmpTime;
						 for (auto idx2 : idx.getSonglist()){															//iterate through song list
							 tmpTime = tmpTime + idx2.getTime();														//	add times together to get total album length
						 }

						 cout << " " << num << ". " << setw(40) << left << idx.getName() << "\t" << setw(8) << idx.getFormatedTime(tmpTime) << endl;	//print name and total length
						 num++;
					 }

					 cout << endl << "Press Enter for print menu...";
					 cin.ignore();
					 cin.get();
		}
			break;
		case '6':	//Back to main menu
		case 'q':
		case 'Q':
		case 'e':
		case 'E': again = false;
		}
	} while (again);


}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: play
//Task: Calls submenu play
//Input: 
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Jukebox::play(){
	if (playMenu.getMenuItem().empty()){																				//
		playMenu.addItem("Create playlist", true);
		playMenu.addItem("Play playlist", false);
		playMenu.addItem("Randomized playlist", true);
		playMenu.addItem("Back to main menu", true);
	}
	
	bool again = true;
	do{
		playMenu.printMenuItems();																						//
		switch (fileMenu.getMenuchoice())																				//
		{
		case '1':{	// *Create playlist/que from album songs
					//numerated list with all available songs on screen
					 vector<Song> tmpSongList;																			//use temporary song list  
					 int num = 1;
					 for (auto idx : albumList){																		//
						 for (auto idx2 : idx.getSonglist()){															//
							 cout << " " << setw(2) << right << num << ". "
								 << setw(50) << left << idx2.getTitle() << "\t"
								 << setw(15) << idx2.getArtist() << "\t"
								 << setw(5) << idx.getFormatedTime(idx2.getTime()) << endl;
							 num++;
							 tmpSongList.push_back(idx2);																//add all songs together into a single song list
						 }
					 }

					 //let user choose songs by inputing number
					 cout << endl << "Song numbers: ";
					 string tmpString;
					 cin.ignore();
					 getline(cin, tmpString);																			//user input: song indexes

					 //add choosen songs to playlist
					 Queue tmpQue;																						//use temporary que to avoid fiddling with original
					 stringstream ss(tmpString);																		//use stringstream to manipulate user input
					 int index = 0;
					 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"												//-
						  << "Adding songs..." << endl << endl;															//-
					 while (ss >> index){																				//write user input into proper indexes
						 Song tmpSong = tmpSongList[index - 1];															//user input needs to be offset by one
						 tmpQue.enque(tmpSong);																			//add to temporary queue

						 cout << " " << setw(2) << right << index << ". "												//user feedback
							  << setw(50) << left << tmpSong.getTitle()
							  << setw(20) << right << "...added[OK]" << endl;

						 if (ss.peek() == ',' || ss.peek() == ' '){														//skip over separators (commas and white space)
							 ss.ignore();
						 }
					 }

					 playlist = tmpQue;																					//refresh playlist in case it has already been used

					 if (!(playMenu.getEnabled("Play playlist"))){
						 playMenu.setEnabled("Play playlist", true);
					 }

					 cout << endl << "Press Enter for play menu...";													//-
					 cin.ignore();
					 cin.get();
		}
			break;
		case '2':{	// *Play songs in playlist/que
					 if (playMenu.getEnabled("Play playlist")){															//-
						 Song tmpSong;																					//-
						 Queue tmpQue;																					//-
						 tmpQue = playlist;																				//copy playlist to temporary que

						 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
						 cout << endl << " Playing..." << endl << endl;
						 while (tmpQue.deque(tmpSong)){																	//empty temporary que while playing songs
							 cout << setw(50) << left << tmpSong.getTitle() << setw(15) << tmpSong.getArtist();			//print song title and artist
							 Sleep(500);																				//simulate playing by printing next song every few seconds
							 cout << setw(5) << right << ".";															//print some dots to indicate playing as a continuous process
							 for (int i = 0; i < 2; i++){
								 Sleep(500);
								 cout << " .";
								 if (i == 2){
									 Sleep(500);
								 }
							 }
							 Sleep(500);
							 cout << " [OK]";																			//done playing current song
							 Sleep(500);
							 cout << endl;
						 }
					 }
					 else{
						 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
							  << "Menu choice not availiable!" << endl
							  << "Please use ''Create playlist'' or ''Randomized playlist'', then try again." << endl << endl;
					 }

					 cout << endl << "Press Enter for play menu...";					//-
					 cin.ignore();
					 cin.get();
		}
			break;
		case '3':{	// *Randomize a playlist
					//create a playlist consisting of all songs from all albums in the jukebox
					 vector<Song> tmpSongList;
					 for (auto idx : albumList){																		//iterate through albums
						 for (auto idx2 : idx.getSonglist()){															//iterate through songs of each album
							 tmpSongList.push_back(idx2);																//store in song list vector
						 }
					 }
					 
					 //get user input: allow user to choose the amount of songs to use for playlist
					 int amountOfSongs = 0;
					 bool tooLarge = false;
					 do{
						 cout << "Amount of songs to use: ";
						 cin >> amountOfSongs;
						 if (amountOfSongs > tmpSongList.size()){
							 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\n\n"
								  << "Sorry! The amount of songs in the playlist is smaller than what you requested to use. Please try again." << endl
								 << "The playlist has " << tmpSongList.size() << " songs in it." << endl << endl;
							 tooLarge = true;
						 }
						 else{
							 tooLarge = false;
						 }
					 } while (tooLarge);
					 
 
					 //choose songs on random from available songs. no duplicates.
					 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
						 << "Adding randomly selected songs..." << endl << endl;										//-

					 Song tmpSong;
					 Queue tmpQue;
					 int index = (tmpSongList.size() - 1);																//get size and arrange index from it. 
					 for (int i = 0; i < amountOfSongs; i++){									
						 random_shuffle(tmpSongList.begin(), tmpSongList.end());										//shuffle temporary list
						 tmpSong = tmpSongList[index];																	//get last element
						 tmpQue.enque(tmpSong);																			//add element to playlist

						 cout << " " << setw(50) << left << tmpSong.getTitle()											//-
							 << setw(20) << right << "...added[OK]" << endl;

						 tmpSongList.erase(tmpSongList.end()-1);														//remove element from temporary list to avoid duplicates.
						 index--;
					 }
					 
					 playlist = tmpQue;																					//-
					 if (!(playMenu.getEnabled("Play playlist"))){
						 playMenu.setEnabled("Play playlist", true);
					 }

					 cout << endl << "Press Enter for play menu...";													//-
					 cin.ignore();
					 cin.get();
		}
			break;
		case '4':
		case 'q':
		case 'Q':
		case 'e':
		case 'E': again = false;
		}
	} while (again);

}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: run
//Task: public function in which the program runs
//Input: 
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Jukebox::run(){
	if (runMenu.getMenuItem().empty()){																						//if program just started, add menu items
		runMenu.addItem("File...", true);
		runMenu.addItem("Add an album", false);
		runMenu.addItem("Delete an album", false);
		runMenu.addItem("Print...", false);
		runMenu.addItem("Play...", false);
		runMenu.addItem("Exit", true);
	}
	
	bool again = true;
	do{
		runMenu.printMenuItems();
		switch (runMenu.getMenuchoice())
		{
		case '1': file();																									//call file to load and or write file with albums 

			if (!(runMenu.getEnabled("Add an album"))){																		//if first run through, enable rest of run menu items
				runMenu.setEnabled("Add an album", true);	
			}
			if (!(runMenu.getEnabled("Delete an album"))){
				runMenu.setEnabled("Delete an album", true);
			}
			if (!(runMenu.getEnabled("Print..."))){
				runMenu.setEnabled("Print...", true);
			}
			if (!(runMenu.getEnabled("Play..."))){
				runMenu.setEnabled("Play...", true);
			}
			
			break;
		case '2': if (runMenu.getEnabled("Add an album")){																	//if enabled, perform call to add an album
					  addAlbum();
		}
				  else{
					  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
						   << "Currently unable to add albums . Please use ''File...'', then try again." << endl;
					  cout << "Press Enter for menu...";
					  cin.ignore();
					  cin.get();
				  }
			break;
		case '3':if (runMenu.getEnabled("Delete an album")){																//if enabled, perform call to delete an album
					 removeAlbum();
		}
				 else{
					 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
						  << "Currently unable to delete albums. Please use ''File...'', then try again." << endl;
					 cout << "Press Enter for menu...";
					 cin.ignore();
					 cin.get();
				 }
			break;
		case '4': if (runMenu.getEnabled("Print...")){																		//if enabled, go into print submenu
					  print();
		}
				  else{
					  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					       << "Print Menu not available. Please use ''File...'', then try again." << endl;
					  cout << "Press Enter for menu...";
					  cin.ignore();
					  cin.get();
				  }
			break;
		case '5': if (runMenu.getEnabled("Play...")){																		//if enabled, go into play submenu
					  play();
		}
				  else{
					  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					       << "Play Menu not available. Please use ''File...'', then try again." << endl;
					  cout << "Press Enter for menu...";
					  cin.ignore();
					  cin.get();
				  }
			break;
		case '6':  
		case 'q':
		case 'Q':
		case 'e':
		case 'E': again = false;
		}
	} while (again);


}
//_______________________________________________________________________________________________________________________________________________________________________________________







//***************************************************************************************************************************************************************************************
