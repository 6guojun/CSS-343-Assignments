#include "store.h"
#include "transactionFactory.h"
#include "movieFactory.h"
using namespace std;
//------------------------------Constructor------------------------------------
Store::Store() {

}
//------------------------------buildClients()---------------------------------
// Takes an inputstream as a parameter and uses it to build a client database
//-----------------------------------------------------------------------------
void Store::buildClients(istream &input) {
	string tempLine = "";
	Client* temp;
	while (!input.eof()) {
		getline(input, tempLine);
		if (input.eof()) {
			break;
		}
		temp = new Client(tempLine);
		clientList.insert(temp);
	}

}
//------------------------------buildMovie--()---------------------------------
// Takes an input file stream as a parameter and uses it to build
// a movie database
//-----------------------------------------------------------------------------
void Store::buildMovies(ifstream & movieData) {
	while (movieData.good()) {
		char type = '~';
		string str;
		getline(movieData, str);
		if (str != "") {
			type = str[0];
			if(type == 'C' || type == 'D' || type == 'F') {
				Movie *ptr = movieFactory::buildMovie(str);
				movies.find(type)->second.insert(ptr);
			}else{
				cout << "Error: Invalid Type of Movie '" << type << "'" <<
																		endl;
			}
		}
	}
}
//------------------------------buildMovie()-----------------------------------
// Takes an input file stream as a parameter and uses it to build
// a transaction database
//-----------------------------------------------------------------------------
void Store::buildTransactions(ifstream & transactionData) {
	while (transactionData.good()) {
		string str;
		getline(transactionData, str);
		if (str != "") {
			Transaction* ptr = TransactionFactory::buildTransaction(str);
			if (ptr != nullptr) {
				transactionLog.push(ptr);
			}
		}
	}
}

//------------------------------startDay()-------------------------------------
// processes all the transactions
//-----------------------------------------------------------------------------
void Store::startDay() {
	while (!transactionLog.empty()) {
		Transaction* ptr = transactionLog.front();
		TransactionFactory::doTransaction(ptr, this);   	
		delete ptr;
		transactionLog.pop();
	}
}

//------------------------------showInventory----------------------------------
// displays inventory
//-----------------------------------------------------------------------------
void Store::showInventory() const{
	cout<< endl << "Store Invertory" << endl;
	cout << movies.find('F')->second;
	cout << movies.find('D')->second;
	cout << movies.find('C')->second;

}

//------------------------------borrowItem--------------------------------------
//processes an item that is being borrowed
//-----------------------------------------------------------------------------
void Store::borrowItem(Borrow* action) {
	Movie* retrieved = nullptr;
	Movie* movieComparison = makeMovie(action);
	if (movieComparison != nullptr) {
		movies.find(action->getMovieType())->second.retrieve
				(*movieComparison, retrieved);
		Client* temp = new Client(action->getClientID());
		Client* retrievedClient = nullptr;
		clientList.findClient(temp, retrievedClient);
		if (retrievedClient == nullptr) {
			cout << "Error: Client" << action->getClientID() << " Not Found"
				 << endl;
		}
		if (retrieved == nullptr) {
			cout << "Error: Movie Not Found" << endl;
		}
		if (retrieved != nullptr && retrievedClient != NULL) {
			bool ableToBorrow = retrieved->decreaseStock();
			if (ableToBorrow) {
				retrievedClient->borrowItem(retrieved);
				retrievedClient->insertIntoLog(action);
				//transactionLog.push(action);
			}
			else {
				cout << "Error: No More Copies Of '" <<
					 movieComparison->getTitle() << "' available"  << endl;
			}
		}
		delete temp;
		delete movieComparison;
	}
}
//------------------------------returnItem-------------------------------------
//processes an item that is being returned
//-----------------------------------------------------------------------------
void Store::returnItem(Return* action) {
	Movie* retrieved = nullptr;
	Movie* movieComparison = makeMovie(action);
	if (movieComparison != nullptr) {
		movies.find(action->getMovieType())->second.retrieve
				 (*movieComparison, retrieved);
		Client* temp = new Client(action->getClientID());
		Client* retrievedClient = nullptr;
		clientList.findClient(temp, retrievedClient);
		if (retrievedClient == nullptr) {
			cout << "Error: Client" << action->getClientID() << " Not "
					 "Found" << endl;
		}
		if (retrieved == nullptr) {
			cout << "Error: Movie Not Found" << endl;
		}
		if (retrieved != nullptr && retrievedClient != NULL) {
			bool hasBeenBorrowed = retrievedClient->returnItem(retrieved);
			if (hasBeenBorrowed) {
				retrieved->increaseStock();
				retrievedClient->insertIntoLog(action);
				//transactionLog.push(action);
			}
			else {
				cout << "Error: Item was not borrowed" << endl;
			}
		}
		delete temp;
		delete movieComparison;
	}
}
//----------------------------displayCustomerHistory---------------------------
//displays a customer's transactional history with a store
//-----------------------------------------------------------------------------
void Store::displayCustomerHistory(int clientID) {
	Client* retrievedClient = nullptr;
	Client* temp = new Client(clientID);
	clientList.findClient(temp, retrievedClient);
	if (retrievedClient == nullptr) {
		cout << "Error: Client" << clientID << " Not Found" << endl;
	}
	else {
		retrievedClient->displayLog();
	}
	delete temp;
}
//----------------------------makeMovie----------------------------------------
//creates a movie to be used to find the movie a customer may want to borrow
//or return to the store
//-----------------------------------------------------------------------------
Movie* Store::makeMovie(Interactions* action) { // makes a movie that can be
//  used by
// the bintree to see if it contains the movie
	int clientId = action->getClientID();
	char typeOfMovie = action->getMovieType();
	Movie* newMovie;
	switch (typeOfMovie) {
		case 'F': {
			int yrReleased;
			string movieData = action->getMovieData();
			int commaPos = movieData.find(", ");
			string title = movieData.substr(1,commaPos-1);
			string yrReleasedString = movieData.substr(commaPos + 1,
													   movieData.length() + 1);
			istringstream ss(yrReleasedString);
			ss >> yrReleased;
			newMovie = new Comedy(title,yrReleased);

		}
			break;
		case 'C': {
			int releaseMonth;
			int releaseYear;
			string firstName;
			string lastName;
			string movieData = action->getMovieData();
			istringstream ss(movieData);
			ss >> releaseMonth >> releaseYear >> firstName >> lastName;
			newMovie = new Classics(releaseMonth, releaseYear, lastName,
									firstName);
		}
			break;
		case 'D': {
			string movieData = action->getMovieData();
			int commaPos = movieData.find(",");
			string director = movieData.substr(1, commaPos - 1);
			string title = movieData.substr(commaPos + 2, movieData.length
					() - 1);
			newMovie = new Drama(title, director);
		}
			break;
		default:
			cout << "Error: Invalid Type of Movie '" << typeOfMovie << "'"
				 << endl;
			return nullptr;

	}
	return newMovie;
}
