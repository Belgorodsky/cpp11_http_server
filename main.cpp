#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <server.hpp>
#include <boost/program_options.hpp>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	try
	{
		namespace po = boost::program_options;
		po::options_description desc("Available options");
		desc.add_options()
			("help", "help message")
			("host,h", po::value<std::string>()->default_value("127.0.0.1"), "http server address")
			("port,p", po::value<std::string>()->required(), "http server port")
			("directory,d", po::value<std::string>()->required(), "root directory of server")
		;

		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);

		if (vm.count("help")) {
			std::cout << desc << "\n";
			return 0;
		}
		
		if (daemon(0, 0) == -1)
		{
			std::cout << "daemon error" << std::endl;
			return 1;
		}

		// Initialise the server.
		http::server::server s(
			vm["host"].as<std::string>(),
			vm["port"].as<std::string>(),
			vm["directory"].as<std::string>()
		);

		// Run the server until stopped.
		s.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception: " << e.what() << "\n";
		return 1;
	}

	return 0;
}
