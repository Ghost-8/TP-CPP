#include "commande.h"

namespace magasin{
	Command::Command(person::Client client, std::vector<Product> cart, Status status): _client(client), _cart(cart), _status(status) {}

	int Command::id_client() const{
		return _client.id();
	}

	/*std::vector<Product> Command::cart() const{
		return _cart;
	}*/

	void Command::update_status(Status status){
		_status = status;
	}

	std::ostream& operator<< (std::ostream& os, const Command& command){
		os << command._client;
		if( static_cast<int>(command._status) == 0 ){
			os << "Delivered" << std::endl;
		}
		else{
			os << "Not delivered" << std::endl;
		}
		return os;
	}
}