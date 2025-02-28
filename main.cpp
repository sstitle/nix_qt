#include <spdlog/spdlog.h>
#include <unordered_map>
#include <string>
#include <boost/program_options.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  // Define and parse command-line options
  boost::program_options::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("lang", boost::program_options::value<std::string>()->default_value("en"), "set language (en, es, fr)");

  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
  }

  std::string lang = vm["lang"].as<std::string>();

  // Create a hash map for greetings
  std::unordered_map<std::string, std::string> greetings;
  greetings["en"] = "Hello from Nix + C++!";
  greetings["es"] = "¡Hola desde Nix + C++!";
  greetings["fr"] = "Bonjour de Nix + C++!";

  // Log the greeting based on the selected language
  if (greetings.find(lang) != greetings.end()) {
    spdlog::info(greetings[lang]);
  } else {
    spdlog::info("Language not supported. Defaulting to English.");
    spdlog::info(greetings["en"]);
  }
}
