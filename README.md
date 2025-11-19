# C++ Learning Project (CLP)

A teaching project designed to help students learn fundamental C++ concepts including:
- Classes and inheritance
- Structs
- Header files (.h) and implementation files (.cpp)
- Memory management with smart pointers
- Enums
- Components and composition
- Console input/output

## Project Structure

```
CLP_LearningProject/
│
├── Source/
│   ├── Public/                     # Header files (.h)
│   │   ├── Core/
│   │   │   ├── Game/
│   │   │   │   └── CLP_Game.h     # Main game class
│   │   │   └── Types/
│   │   │       └── CLP_EnumTypes.h # Enum definitions
│   │   │
│   │   ├── Character/
│   │   │   ├── CLP_CharacterBase.h # Base character class
│   │   │   ├── CLP_Hero.h          # Player class (inherits from CharacterBase)
│   │   │   └── CLP_Enemy.h         # Enemy class (inherits from CharacterBase)
│   │   │
│   │   └── Inventory/
│   │       ├── InventoryComponent/
│   │       │   └── CLP_InventoryComponent.h # Inventory management
│   │       └── ItemComponent/
│   │           ├── CLP_ItemComponent.h      # Item container struct
│   │           └── Items/
│   │               └── CLP_Items.h          # Item definitions
│   │
│   └── Private/                    # Implementation files (.cpp)
│       ├── Core/
│       │   └── Game/
│       │       ├── CLP_Main.cpp    # Entry point (main function)
│       │       └── CLP_Game.cpp    # Game implementation
│       │
│       ├── Character/
│       │   ├── CLP_CharacterBase.cpp
│       │   ├── CLP_Hero.cpp
│       │   └── CLP_Enemy.cpp
│       │
│       └── Inventory/
│           └── InventoryComponent/
│               └── CLP_InventoryComponent.cpp
│
├── CLP_LearningProject.sln          # Program Solution
└── README.md                        # This file
```