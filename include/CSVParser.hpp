#pragma once
#include "Data.hpp"
#include "Placement.hpp"
#include <concepts>

namespace PlaceDataLib
{
    //maybe change to a static function? or just a function?
    namespace CSVParser
    {
        Data parsePlaceCSV(std::string filepath, std::unordered_map<dataFormat, bool (*)(Placement)> rules);
    }
    
} // End Namespace