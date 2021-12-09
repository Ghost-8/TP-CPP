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
		Command(int id, person::Client client, std::vector<Product> cart, Status status);
		int id() const;
		person::Client client() const;
		void update_status(Status status);
		friend std::ostream& operator<< (std::ostream& os, const Command& command);
	private:
		int _id;
		person::Client _client;
		std::vector<Product> _cart;
		Status _status;
	};
}

#endif