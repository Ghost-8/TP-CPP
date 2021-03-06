#include "commande.h"

namespace magasin{
	Command::Command(int id, person::Client client, Status status): _id(id), _client(client), _status(status) {}

	int Command::id() const{
		return _id;
	}

	Status Command::status() const{
		return _status;
	}
	
	person::Client Command::client() const{
		return _client;
	}

	std::vector<magasin::Product> Command::cart() const{
		return _client.cart();
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

	std::vector<magasin::Command>::iterator find_command(std::vector<magasin::Command>& container, const magasin::Command& command){
		auto it = std::find_if(container.begin(), container.end(), [command](const magasin::Command& obj){ return command.id() == obj.id(); });
		return it;
	}

	std::vector<magasin::Command>::iterator find_command(std::vector<magasin::Command>& container, const int id_command){
		auto it = std::find_if(container.begin(), container.end(), [id_command](const magasin::Command& obj){ return id_command == obj.id(); });
		return it;
	}
}