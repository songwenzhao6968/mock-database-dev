//
// Created by Xiaoyuan Liu on 11/21/20.
// Edited by Songwen Zhao on 11/02/22.
//

# include <iostream>
# include <fstream>

# include "provider.h"

Provider::Provider(std::string name, json &provider_config): type(BASIC_PROVIDER), name(name) {}

Provider::~Provider() {}

LocalProvider::LocalProvider(std::string name, json &provider_config):
    Provider(name, provider_config) {
    this->type = LOCAL_PROVIDER;
    json local_config = provider_config["local_config"];
    // load tables
    auto database_file_loc = local_config["database_file_loc"].get<std::string>();
    std::ifstream database_file_stream(database_file_loc);
    json database_json;
    database_file_stream >> database_json;
    for (auto& el: database_json.items()) {
        std::string table_name = el.key();
        managed_tables[table_name] = new Table(el.value());
        this->db.addTable(table_name, managed_tables[table_name]);
    }
}

LocalProvider::~LocalProvider() {
    for (auto& t: managed_tables) delete t.second;
}

std::string LocalProvider::runQuery(const Query& q, bool is_master) {
    std::string local_result = this->db.runQuery(q);
    if (is_master) {
        std::string final_result;
        final_result = local_result; // TODO: send the query to other provider and aggregate the result
        return final_result;
    } else {
        return local_result;
    }
}