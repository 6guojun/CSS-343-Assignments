

#include "classics.h"
#include "HashTable.h"
#include "store.h"
using namespace std;


int main() {
	ifstream transactionText("data4commands.txt");
	ifstream clientText("customers.txt");
    ifstream movieText("data4movies.txt");
	Store newStore;
    newStore.buildMovies(movieText);
	newStore.buildTransactions(transactionText);
    newStore.buildClients(clientText);
	newStore.startDay();
	return 0;
}
