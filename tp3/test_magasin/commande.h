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
		Command(int id, person::Client client, Status status);
		int id() const;
		person::Client client() const;
		Status status() const;
		void update_status(Status status);
	private:
		int _id;
		person::Client _client;
		Status _status;
	};
	std::ostream& operator<< (std::ostream& os, const Command& command);
	std::vector<magasin::Command>::iterator find_command(std::vector<magasin::Command>& container, const magasin::Command& command);
	std::vector<magasin::Command>::iterator find_command(std::vector<magasin::Command>& container, const int id_command);
}

#endif