#ifndef TRANFAC
#define TRANFAC

#include "transactionFactory.h"
#include "Borrow.h"
#include "Inventory.h"
#include "History.h"
#include "Return.h"
#include "transaction.h"
#include "store.h"
using namespace std;
//--------------------------  class TransactionFactory ------------------------
// TransactionFactory ADT: A class used to hide information from the user
//
// Implementation and assumptions:
//   -- correctly formatted
//-----------------------------------------------------------------------------
class TransactionFactory {

public:
	TransactionFactory();
	~TransactionFactory();
	static Transaction* buildTransaction(string);
	static void doTransaction(Transaction * action,Store* );


};
#endif