#include <gtest/gtest.h>
#include "Placement.hpp"

TEST(Placement, storage_test)
{
    PlaceDataLib::Placement utplacement;
    utplacement.setData<PlaceDataLib::dataFormat::UNIXTIME>(1337);
    EXPECT_EQ(utplacement.getDataFromFormat<PlaceDataLib::dataFormat::UNIXTIME>(), 1337);

    PlaceDataLib::Placement uidplacement;
    uidplacement.setData<PlaceDataLib::dataFormat::USERID>("osugame");
    EXPECT_EQ(uidplacement.getDataFromFormat<PlaceDataLib::dataFormat::USERID>(), "osugame");
}