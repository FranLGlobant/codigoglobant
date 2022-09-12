#include <iostream>
#include "json.hpp"
#include <map>
#include <string>
#include <any>
#include <regex>


using json = nlohmann::json;
using namespace nlohmann::literals;


std::map<std::string, std::any>  jsonparsetodict(json json_input) {

    std::map<std::string, std::any> returnjson;

    for (auto& el : json_input.items())
    {
        std::string key = el.key();
        key = key.erase(0, 1);
        key = std::regex_replace(key, std::regex("/"), ".");



        //numero flotante (no llegue a realizar implementacion del entero, lo siento)
        if (el.value().is_number()) {
            returnjson[key] = el.value().get<float>();
        }

        //boolean
        else if (el.value().is_boolean()) {
            //            std::cout << "Booleano! " << el.value().get<bool>() <<std::endl;
            returnjson[key] = el.value().get<bool>();
        }

        //null
        else if (el.value().is_null()) {
            //            std::cout << "nulo!" << std::endl;
            returnjson[key] = nullptr;
        }
        //string
        else {
            //            std::cout << "String! " <<el.value().get<std::string>()<< std::endl;
            returnjson[key] = el.value().get<std::string>();
        }



    }
    return returnjson;
}

std::map<std::string, std::any> jsonparse(std::string json_input) {


    json data = json::parse(json_input).flatten();

    std::map<std::string, std::any> returnjson = jsonparsetodict(data);

    return returnjson;
}



//funcion de impresion seca fea y hecha en 5 min

void printdict(const std::map<std::string, std::any> returnjson) {

    for (const auto& elem : returnjson)
    {
        std::cout << "" << elem.first;

        if (elem.second.type() == typeid(int))
            std::cout << " = " << std::any_cast<int>(elem.second);
        else if (elem.second.type() == typeid(std::string))
            std::cout << " = " << std::any_cast<std::string>(elem.second);
        else if (elem.second.type() == typeid(float))
            std::cout << " = " << std::any_cast<float>(elem.second);
        else if (elem.second.type() == typeid(bool))
            std::cout << " = " << std::boolalpha << std::any_cast<bool>(elem.second);
        else if (elem.second.type() == typeid(nullptr))
            std::cout << " = " << "nullptr";
        std::cout << "\n";
    }
}



int main(int argc, char* argv[]) {

    if (argc != 1) {
        std::cout << argv[1] << "\n";
        auto json = jsonparse(argv[1]);
        printdict(json);
    }
    else if (argc == 1) {
        std::cout << "primera prueba" << "\n";
        std::cout << R"({ "a": true, "b": { "b1": "hello", "b2": 3.5 }, "c": 3 })" << "\n";
        auto json = jsonparse(R"({ "a": true, "b": { "b1": "hello", "b2": 3.5 }, "c": 3 })");

        printdict(json);

        std::cout << "segunda prueba" << "\n";
        std::cout << R"({ "a": false, "b": { "b1": "hello", "b2": [3.5,"hola","esto","es","un array"] }, "c": -3 })" << "\n";
        json = jsonparse(R"({ "a": false, "b": { "b1": "hello", "b2": [3.5,"hola","esto","es","un array"] }, "c": -3 })");

        printdict(json);
    }


    return 0;
}
