#ifndef COMMANDE
#define COMMANDE

#include <vector>
#include <ostream>
#include "produit.h"
#include "client.h"

namespace magasin{
	enum class Status{
		delivered,
		not_delivered
	};
	class Command{
	public:
		Command(person::Client client, std::vector<Product> cart, Status status);
		void validate();
		void update_command_status();  // nok
		friend std::ostream& operator<< (std::ostream& os, const Command& command);
	private:
		person::Client _client;
		std::vector<Product> _cart;
		Status _status;
	};
}

#endif