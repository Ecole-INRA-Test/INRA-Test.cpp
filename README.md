INRA-Test.cpp
=============

Code du Robot en version C++ 

Welcome to the INRA-Test.cpp wiki!

Cette page pr�sente les diff�rents outils et que nous avons utilis� durant l'�cole PEPI INRA. Nous pr�sentons �galement l'installation des outils tels que nous l'avons fait sur la VM. 

Outils utilis�s: 
* [CPPUNIT](http://sourceforge.net/apps/mediawiki/cppunit/index.php?title=Main_Page): framework de tests unitaires pour C++.
* [Google Mock](http://code.google.com/p/googlemock/): librairie google pour le mock. Peut s'utiliser avec CPPUNIT mais �galement avec d'autres framework de tests unitaires C++.
* [Cucumber-cpp](https://github.com/cucumber/cucumber-cpp): framework de tests fonctionnels pour C++.

### Installation de CPPUNIT 
Dans une console linux taper `sudo apt-get install libcppunit-dev`.

### Installation de Google Test
Dans une console linux taper `sudo apt-get install libgtest-dev`.

### Installation de Google Mock
* T�l�charger les sources [ici](http://code.google.com/p/googlemock/downloads/list)
* Placer le contenu du zip dans /home/username/
* Faire les commandes suivante dans le r�pertoire gmock-1.7.0:
```bash
mkdir build 
cd build
g++ -I../gtest/include -I../gtest -I../include -I.. -c ../gtest/src/gtest-all.cc
g++ -I../gtest/include -I../gtest -I../include -I.. -c ../src/gmock-all.cc
ar -rv libgmock.a gtest-all.o gmock-all.o
```
* Tester l'installation: depuis le r�pertoire test de votre projet, taper la commande
```bash
g++ -I/home/username/gmock-1.7.0/include/ TestRunner.cpp -L/home/username/gmock-1.7.0/build -lgmock -lpthread -lcppunit -o test 
```
NB: v�rifier que le r�pertoire /usr/lib/ contient les librairies libgmock et libgtest. A v�rifier �galement que les r�pertoires /usr/include/gmock/ et /usr/include/gtest/ sont pr�sents et qu'ils ne sont pas vide. 

### Installation de Cucumber-cpp
Il existe un tutoriel tr�s bien fait pour installer Cucumber-cpp sous Linux Ubuntu. Pour installer Cucumber-cpp rendez-vous [ici](https://github.com/rdammkoehler/CucumberCPPDemoProject). 

#### Compiler et ex�cuter un exemple Cucumber-cpp
Depuis la racine du projet C++, taper les commandes suivantes:
```bash
cmake -E make_directory build-test (si le dossier build-test n'existe pas) 
cmake -E chdir build-test cmake ..
cmake --build build-test
```
A cet instant vous devriez avoir le binaire du fichier C++ qui contient les step cucumber dans /build-test/.

Pour ex�cuter la suite de tests Cucumber, taper les commandes suivantes:
```bash
build-test/MonFichierStep > /dev/null &
cucumber -s features/maFeature.feature
```
