INRA-Test.cpp
=============

Code du Robot en version C++


Pour compiler le code cucumber, voici les commandes à taper : 
    cmake -E make_directory build-test
    cmake -E chdir build-test cmake ..
    cmake --build build-test

Pour exécuter le code : 

    build-test/RobotSteps > /dev/null &
    cucumber -s features/MaFeature.feature
