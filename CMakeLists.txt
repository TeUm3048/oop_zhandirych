cmake_minimum_required(VERSION 3.26)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP
        src/PlayerView/PlayerView.h
        src/PlayerView/PlayerView.cpp
        src/PlayerController/PlayerController.h
        src/IObserver/IObserver.cpp
        src/IObserver/IObserver.h
        src/Observable/Observable.cpp
        src/Observable/Observable.h
        src/Player/Player.cpp
        src/Player/Player.h
        src/PlayerController/PlayerController.cpp
        src/PlayerController/PlayerController.h
        src/PlayerView/PlayerView.cpp
        src/PlayerView/PlayerView.h
        src/main.cpp
        src/FieldCell/FieldCell.cpp
        src/FieldCell/FieldCell.h
        src/Field/Field.cpp
        src/Field/Field.h
        src/Coordinate/Coordinate.h
        src/Events/IEvent/IEvent.h
        src/Events/HealEvent/HealEvent.cpp
        src/Events/HealEvent/HealEvent.h
        src/Events/TeleportEvent/TeleportEvent.cpp
        src/Events/TeleportEvent/TeleportEvent.h
        src/Events/IEvent/EventTarget.h)
