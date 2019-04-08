# SK_GameSaver_API
C++ API Game Saver and Loader
Created by Steven Kolankowski (kola93) in 2018.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

utility:
- Save game state to HDD/SSD
- Load game state from HDD/SSD
- Flexible structure
- Debug what is saved
- Error handling

User cases:
The User create their struct/class that inherit from ISerializeable
The User implements overridden Serialize() and Deserialize() functions with the data they want
The User create an object of the class GameSaver
The User run the function Save() to save the data into the file
The User create an object of the class GameSaver
The User run the function Load() to load the game variables into their empty struct/class


Example:
#include “GameSaver.h”
UserStruct m_userStructSave;
GameSaver GS_save("./SaveFolder/","MySavedFile",".bin");
GS_save.Save(m_userStruct);

GameSaver GS_load("./SaveFolder/","MySavedFile",".bin");
UserStruct m_userStructLoad; //empty structure
GS_load.Load(m_userStructLoad);

