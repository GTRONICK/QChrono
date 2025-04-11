# QChrono
Simple Qt5 Chronometer

![image](https://github.com/user-attachments/assets/e2760631-bf0d-42da-9888-e6d912d85ea9)


QChrono, is a simple QT application that serves as a chronometer with lap capture. 

# How to Build

1. Download the source code and images.
2. Extract the files and run:
3. qmake TestJQ.pro
4. make all -j4
5. You will find a QChrono executable.

If this dont work, try using QTCreator and open the TestJQ.pro file. Configure the project, build, and launch in release mode.

# How to use

1. Click the Start button to start the chrono.
2. Click the Lap button, to save the current time in the lap viewer.
3. Click the Reset button, to reset the chrono.
4. Click the Clear Laps button, to clear the lap viewer.
5. Enter any text in the "Name..." line to add a custom name to each instance. This is useful for differentiate multiple instances
   running at the same time.
