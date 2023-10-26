# Class diagram

```mermaid
---
Title: Class diagram
---
classDiagram
    class Coordinate {
        <<struct>>
        + x: int
        + y: int
    }
    
    class PlayerController {
        +start()
        -Player
        -Field
        +changeField()
        +playerMove()
        +playerDecreaseHP()
        +playerIncreaseHP()
        +triggerEvent(Coordinate)
        #canMove()
    }
    
    namespace MVC {
        class FieldView {
            -Field
            +renderField
        }
        class PlayerView {
            -Player
            +renderPlayer()
        }
        class Observable {
            +addObserver(Observer)
            +notifyObservers()
            -Observer[]
        }
        class IObserver {
            <<interface>>
            +update()
        }
    }
    class Player {
        -name
        -HP: unsigned
        -Coordinate
        +setName(name)
        +getName()
        +setHP(unsigned HP)
        +getHP()
        +bool isDead()
        +bool isAlive()
        +setX(int x_)
        +getX()
        +setY(int y_)
        +getY()
    }

    class Directions {
        <<enumeration>>
        Up, Right, Down, Left
    }
    namespace Fields {
        class FieldCreator {
            +getFieldForLevel(int level)
        }
        class FieldCell {
            -occupied
            -*Event
            +isOccupied()
            +setOccupied()
            +removeOccupied()
            +getEvent()
            +setEvent()
        }
        class Field {

            -FieldCell[][]
            -start: Coordinate
            -finish: Coordinate
            -width
            -height
            +getWidth()
            +getHeight()
            +getStart() -> Coordinate
            +getFinish() -> Coordinate
            +getFieldCell()
            +validateCoordinate()
            +validateSize()
        }
    }
    namespace Events {
        class IEvent {
            <<interface>>
            handle(EventTarget)
            *IEvent clone()
        }
        class EventTarget {
            <<struct>>
            PlayerController&
            Player&
            Field&
            Coordinate
        }

        class TrapEvent {
            -damage
        }
        class HealEvent {
            -healHP
        }
        class TeleportEvent {
            -teleportCoordinate
        }
        class EventFactory {
            +getTrapEvent()
            +getHealEvent()
            +getTeleportEvent()
        }
    }
    Player --|> Observable
    IObserver "*" -- "*" Observable: notifyUpdate()
    PlayerView ..|> IObserver
    PlayerView o-- "1" Player
    PlayerController o--> "1" Player
    Field "1" *-- "1..*" FieldCell
    PlayerController *-- "1" Field
    FieldCell *-- IEvent
    IEvent <|.. TrapEvent
    IEvent <|.. HealEvent
    IEvent <|.. TeleportEvent
    IEvent --> EventTarget

    FieldCreator --> EventFactory: gets Event
    EventFactory ..> IEvent
    Field <.. FieldCreator

%%    TrapEvent --> PlayerController: playerDecreaseHP()
%%    HealEvent --> PlayerController: playerIncreaseHP()
%%    TeleportEvent --> PlayerController: playerMove()
    
%%    PlayerController "triggerEvent" -->"handle()" IEvent: 
    EventTarget o--> PlayerController
    FieldView o-- Field
    FieldView ..|> IObserver
    Observable <|-- Field

```
