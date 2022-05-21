cmake_minimum_required(VERSION 3.10)

project(Game)

add_executable(
    main 
    src/Engine/AssetManager.cpp
    src/Engine/BoxCollider.cpp
    src/Engine/C_Animation.cpp
    src/Engine/C_Sprite.cpp
    src/Engine/Game.cpp
    src/Engine/Input.cpp
    src/Engine/PhysicSystem.cpp
    src/Engine/RigidBody.cpp
    src/Engine/StateMachine.cpp
    src/Engine/Transform.cpp
    src/GameOverState/GameOverState.cpp
    src/GameState/Background.cpp
    src/GameState/Chest.cpp
    src/GameState/GameHUD.cpp
    src/GameState/GameState.cpp
    src/GameState/Level.cpp
    src/GameState/Mushroom.cpp
    src/GameState/Pickup.cpp
    src/GameState/Player.cpp
    src/GameState/PlayerMovement.cpp
    src/GameState/Terrain.cpp
    src/GameState/TileMapParser.cpp
    src/json/jsoncpp.cpp
    src/main.cpp
    src/MenuState/ChoseCharacterState.cpp
    src/MenuState/ChoseLevelState.cpp
    src/MenuState/MenuState.cpp
    src/MenuState/TutorialState.cpp
    src/Utility/Animation.cpp
    src/Utility/Bitmask.cpp
    src/Utility/Button.cpp
    src/Utility/Sprite.cpp
    src/Utility/SpriteSheet.cpp
)

set_target_properties(main PROPERTIES CXX_STANDARD 17)

target_include_directories(main PRIVATE include)

# SFML
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics.a)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libsfml-audio.a)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libsfml-system.a)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libsfml-window.a)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libsfml-main.a)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libsfml-network.a)







