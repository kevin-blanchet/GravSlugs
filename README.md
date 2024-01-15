# GravSlugs

- License GNU GPL-3.0 

## SETUP

1. Clone project : 
```
     git clone --recurse-submodules https://github.com/kevin-blanchet/GravSlugs.git 
```

2. Install vcpkg : [^1] 
```
    ./Dependencies/vcpkg/bootstrap-vcpkg.sh
```
```
    ./Dependencies/vcpkg/bootstrap-vcpkg.bat
```

3. Install vcpkg modules : [^2]
```
    ./Dependencies/vcpkg/vcpkg install
```

4. Build project : [^3]
```
    cmake -B build
```

## OTHERS

Notes : 

Pour le moment fonctionne mais tout en static lib. \
Faire les changements du CMake pour fonctionnement en dynamic lib. 


## About

GravSlugs is a school project to learn how to integrate physics in a 2D projects.
SFML2 is allowed for the graphical part, but tools like imgui or nlohmann/json are allowed
The engine and the game should not be in the same project to allow for easy reuse of the engine
Excerpt from the project description given by the school:
> Your mission is to create a two players game. Each player owns an avatar (tank, worms, plane,
> whatever). It's a turn by turn game. The aim of this game is to destroy the opponent avatar. Each
> avatar has a set of health point and at least two weapons and a gravitationnal object

The bulk of the game will be a worms-like gamelay.

## Credits

CMakeFiles.txt inspired by https://github.com/Nimeryon/WarTurtles.git

Project rules created by Lavigne Quentin and Oukrat Remi

Game created by Carricart Hugo, Pradel Hugo and Blanchet Kevin


[^1]: A executer depuis le terminal Git [Git bash here]
[^2]: A executer depuis le terminal Git [Git bash here]
[^3]: Assurez vous de bien avoir CMake dans le PATH Windows