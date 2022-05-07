#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include "DataPoint.hpp"

namespace PlaceDataLib
{

    class Placement
    {
    public:
        ///////////////////////
        //   Constructors    //
        ///////////////////////
        Placement() { }
        //Placement(std::vector<dataFormat> dataFormats) { }

        ///////////////////////
        // GETTERS / SETTERS //
        ///////////////////////
        template <dataFormat format, typename T = typename TypeSelector<format>::type>
        bool setData(FormattedDataPoint<format> data)
        {
            return dataPoints.emplace(format,std::make_unique<FormattedDataPoint<format>>(data)).second;
        }

        ///////////////////////
        // PUBLIC  FUNCTIONS //
        ///////////////////////
        template <dataFormat format, typename RT = typename TypeSelector<format>::type>
        std::optional<RT> getDataFromFormat()
        {
            if (dataPoints.find(format) != dataPoints.end())
            {
                return *dynamic_cast<FormattedDataPoint<format>*>(dataPoints.at(format).get());
            }
            return std::nullopt;
        }
        
    private:
        ///////////////////////
        // PRIVATE MEMBERS   //
        ///////////////////////
        std::unordered_map<dataFormat, std::unique_ptr<DataPoint>> dataPoints;
    };
} // End Namespace