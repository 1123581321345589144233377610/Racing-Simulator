cmake_minimum_required(VERSION 3.20)

project(my_lib)

set(dll_files AirRace.cpp AirTransport.cpp Boots.cpp Broom.cpp Camel.cpp Centaur.cpp Eagle.cpp FastCamel.cpp LandAirRace.cpp LandRace.cpp LandTransport.cpp MagicCarpet.cpp Race.cpp Transport.cpp)

add_library(my_lib SHARED ${dll_files})
