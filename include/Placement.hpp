#pragma once

#include <unordered_map>
#include <vector>
#include "DataPoint.hpp"

namespace PlaceDataLib
{

    class Placement
    {
    public:
        ///////////////////////
        //   Constructors    //
        ///////////////////////
        Placement(std::vector<dataFormat> dataFormats);

        ///////////////////////
        // GETTERS / SETTERS //
        ///////////////////////
        //template <dataFormat format, typename T = typename TypeSelector<format>::type>
        //bool setData(T data)
        //{
        //    return dataPoints.emplace(format,data);
        //}

        ///////////////////////
        // PUBLIC  FUNCTIONS //
        ///////////////////////
        //template <dataFormat format, typename RT = typename TypeSelector<format>::type>
        //RT getDataForFormat()
        //{
        //    if (dataPoints.find(format) != dataPoints.end())
        //    {
        //        return static_cast<FormattedDataPoint<format>>(dataPoints.at(format));
        //    }
        //}

    private:
        ///////////////////////
        // PRIVATE MEMBERS   //
        ///////////////////////
        std::unordered_map<dataFormat, std::unique_ptr<DataPoint>> dataPoints;
    };
} // End Namespace