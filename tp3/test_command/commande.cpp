#include "commande.h"

namespace magasin{
	Command::Command(int id, person::Client client, std::vector<Product> cart, Status status): _id(id), _client(client), _cart(cart), _status(status) {}

	int Command::id() const{
		return _id;
	}

	Status Command::status() const{
		return _status;
	}
	
	person::Client Command::client() const{
		return _client;
	}

	void Command::update_status(const Status status){
		_status = status;
	}
	
	std::ostream& operator<< (std::ostream& os, const Command& command){
		os << command.client();
		if( static_cast<int>(command.status()) == 0 ){
			os << "Delivered" << std::endl;
		}
		else{
			os << "Not delivered" << std::endl;
		}
		return os;
	}
}