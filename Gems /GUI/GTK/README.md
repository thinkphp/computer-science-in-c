### GTK 

GTK is a widget toolkit. Each user interface created by GTK consists of widgets. This is implemented in C using GObject, an object-oriented framework for C. Widgets are organized in a hierarchy. The window widget is the main container. The user interface is then built by adding buttons, drop-down menus, input fields, and other widgets to the window


### Usage

Step 1: Install GTKmm Development Libraries
```
sudo apt-get update
sudo apt-get install libgtkmm-3.0-dev

```

Step 2: Save the Code to a File

```
Save the provided code to a file named app.cpp.

```

Step 3: Compile the code

```
g++ app.cpp -o app `pkg-config gtkmm-3.0 --cflags --libs`
```

Step 4: Run the Application

```
./app

```
