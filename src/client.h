//
// Created by Xiaoyuan Liu on 11/5/20.
// Edited by Songwen Zhao on 11/01/22.
//

#ifndef MULTIPARTY_DATABASE_CLIENT_H
#define MULTIPARTY_DATABASE_CLIENT_H

#include <iostream>
#include <string>
#include <random>

#include "json.hpp"

using json=nlohmann::json;

#include "database.h"
#include "provider.h"

class Servers { 
public:
    json config;
    std::unordered_map<std::string, Schema> table_schema_map;
    std::unordered_map<std::string, std::vector<std::string> > table_providers_map;
    std::unordered_map<std::string, Provider*> providers;
    std::default_random_engine rand_e;

    explicit Servers(json& config);
    ~Servers();
    void initSchemaProvidersMaps();
    void initProviders();
    Schema& getSchemaByTableName(const std::string& table_name);
    std::string selectProvider(const std::string& table_name);
    std::string runQuery(const Query& q);
};

std::string exec_SQL(Servers& s, std::string SQL);

void start_interactive_client(json config);
void process_batch_sql(json config, std::istream& fin);

#endif //MULTIPARTY_DATABASE_CLIENT_H
