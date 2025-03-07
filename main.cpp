#include <spdlog/spdlog.h>
#include <unordered_map>
#include <string>
#include <boost/program_options.hpp>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

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

    // Create the main window
    QWidget window;
    QVBoxLayout layout(&window);

    // Create a label to display the greeting
    QLabel label;
    label.setAlignment(Qt::AlignCenter);
    layout.addWidget(&label);

    // Function to update the greeting
    auto updateGreeting = [&](const std::string& selectedLang) {
        if (greetings.find(selectedLang) != greetings.end()) {
            label.setText(QString::fromStdString(greetings[selectedLang]));
        } else {
            spdlog::info("Language not supported. Defaulting to English.");
            label.setText(QString::fromStdString(greetings["en"]));
        }
    };

    // Create buttons for each language
    QPushButton buttonEn("English");
    QPushButton buttonEs("Spanish");
    QPushButton buttonFr("French");

    layout.addWidget(&buttonEn);
    layout.addWidget(&buttonEs);
    layout.addWidget(&buttonFr);

    // Connect buttons to update the greeting
    QObject::connect(&buttonEn, &QPushButton::clicked, [&]() { updateGreeting("en"); });
    QObject::connect(&buttonEs, &QPushButton::clicked, [&]() { updateGreeting("es"); });
    QObject::connect(&buttonFr, &QPushButton::clicked, [&]() { updateGreeting("fr"); });

    // Set initial greeting
    updateGreeting(lang);

    // Show the window
    window.resize(400, 300);
    window.show();

    return app.exec();
}
