# Retail-Sim
Program created in C++ for data structures course II of UWB.

Simulates a media/film retail store. 

Simply run main.cpp. Or if on Linux, put all files in a folder and do: g++ *.cpp

Preliminary design:
The design for this project was to recreate a retail store as best as possible. A retail store design to open to extension and adaptable to various kinds of retail store contexts. The main implementation was to implement a media film store. For the design, we wanted to open this design for all kinds of items a retail store can sell, ideally. We designed it so that various components, such as the client(s), store, command parser, inventory, and the logic, were all seperated, but fitted together in a way that made sense. We wanted to achieve a small main.cpp file. Lastly, each component uses some kind of data structure to store and edit data (for example, using a hash table to lookup a client ID number). 

**Design UML**:

![alt text](http://i1142.photobucket.com/albums/n612/jetset773/A4%20UML%20Diagram_0001_zpsngnykqra.png)
