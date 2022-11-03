//
// Created by Xiaoyuan Liu on 11/5/20.
// Edited by Songwen Zhao on 11/01/22.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <unordered_map>

#include "client.h"

Servers::Servers(json &config):
    config(config),
    rand_e(std::chrono::system_clock::now().time_since_epoch().count()) {
    initSchemaProvidersMaps();
    initProviders();
}

Servers::~Servers() {
    for (auto& p: providers) delete p.second;
}

void Servers::initSchemaProvidersMaps() {
    json& tables_config = this->config["tables"];
    for (auto& e: tables_config) {
        auto name = e.at("name").get<std::string>();
        auto schema_loc = e.at("schema").get<std::string>();
        std::ifstream schema_istream(schema_loc);
        json schema_json;
        schema_istream >> schema_json;
        Schema schema(schema_json[name]["schema"]);
        this->table_schema_map.insert_or_assign(name, schema);
        std::vector<std::string> providers_name;
        for (auto& p: e.at("providers")) providers_name.emplace_back(p.get<std::string>());
        this->table_providers_map[name] = providers_name;
    }
}

void Servers::initProviders() {
    json& providers_config = this->config["servers"];
    for (auto& el: providers_config.items()) {
        const std::string& provider_name = el.key();
        json provider_config = el.value();
        Provider* provider = new LocalProvider(provider_name, provider_config);
        provider->servers = this;
        this->providers[provider_name] = provider;
    }
}

Schema& Servers::getSchemaByTableName(const std::string& table_name) {
    return table_schema_map.at(table_name);
}

std::string Servers::selectProvider(const std::string& table_name) {
    std::vector<std::string>& related_providers = table_providers_map.at(table_name);
    std::uniform_int_distribution<unsigned> rand_u(0, related_providers.size()-1);
    return related_providers.at(rand_u(this->rand_e));
}

std::string Servers::runQuery(const Query &q) {
    return this->providers[selectProvider(q.concerned_table)]->runQuery(q, true);
}

std::string exec_SQL(Servers& s, std::string SQL) {
    Query q = Query(SQL);
    return s.runQuery(q);
}

void start_interactive_client(json config) {
    Servers servers(config); // json config file is for initiating the server/providers
    /*std::cout << "Start Interactive Mode" << std::endl;
    std::string command;
    std::cout << "> ";
    while (std::getline(std::cin, command)) {
        if (command.size() < 2) {
            std::cout << "> ";
            continue;
        }
        if (command.find("EXIT") != std::string::npos) {
            std::cout << "Thank you for using Mock Database. Exiting" << std::endl;
            return;
        }
        std::string result = exec_SQL(servers, command);
        std::cout << result << std::endl << std::endl << "> ";
    }*/
}

void process_batch_sql(json config, std::istream& fin) {
    Servers servers(config);
    std::cout << "Start Batch Processing Mode" << std::endl;
    std::string command;
    while (std::getline(fin, command)) {
        std::cout << "> " << command << std::endl;
        if (command.find("EXIT") != std::string::npos) return;  // different from interactive mode
        std::string result = exec_SQL(servers, command);
        std::cout << result << std::endl << std::endl << "> ";
    }
}
