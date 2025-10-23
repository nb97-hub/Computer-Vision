# Setup [Windows VSCode OPENCV CMAKE CPP]
This is a guide intended to provide a fast and reliable setup for getting started in 2025 with OpenCV library in a C++ environment using VSCode on Windows.
### 1. Download VSCode either from the [VSCode official website](https://code.visualstudio.com/download) or directly from the [Microsoft Store](https://apps.microsoft.com/detail/XP9KHM4BK9FZ7Q?hl=it-IT&gl=IT&ocid=pdpshare).

### 2. Install the C/C++ VSCode extensions from Microsoft.
- Extensions IDs: *ms-vscode.cpptools*, *ms-vscode.cpptools-extension-pack*.

### 3. Install a C/C++ compiler.
My suggestion is to use the Microsoft Visual C++ (MSVC) compiler since it is the same the OpenCV library is compile with. Here some evergreen instructions on how to do so:
- Open VSCode.
- Open the command palette (*ctrl + shift + p*).
- Select "Welcome: Open Walkthrough".
- Select "Get started with C++ Development".
- Follow the instructions provided in the "Set up your C++ Environment" to install the MSVC compiler.

### 4. Download and Install the OpenCV library on your laptop.
- Go to  [OpenCV releases page](https://opencv.org/releases/)
- Choose a OpenCV version and click on the Windows logo underneath it.
- Once downloaded, execute the installer. The only job of this is installer is to extract the library. Please extract it in a "simple" path (for example: C:\cpp-libs\opencv).
- After extraction, create a new environment variable for the OpenCV build folder called "OpenCV_DIR" (for example **OpenCV_DIR = C:\cpp-libs\opencv\build**).
- Moreover add the OpenCV binary directory to the system's PATH environment variable (for example **C:\cpp-libs\opencv\build\x64\vc16\bin** AND **C:\cpp-libs\opencv\build\x64\vc16\lib**).
- Please check these enviroment variables have been correctly updated or the OpenCV linking and usage will fail.

### 6. Have a look at the source files.
- In the **CMakeLists.txt** check the OpenCV_DIR Path, change if you want the project name and everything else you need to let your code compile successfully.
- In the **main.cpp** you are free to insert your code. My suggestion is to keep everything as it is the first time, since this is only an example to set up you environment and check that everything is ok.
- Upload your *.jpg* image.

### 7. Download and Install CMake on your laptop.
- Go to [CMake download page](https://cmake.org/download/)
- Locate te *Binary Distribution* tab and download the "Windows x64 Installer".
- Once the download has finished, launch the installer and complete the installation.
- Then open again VSCode and install these extensions: *ms-vscode.cmake-tools* and *twxs.cmake*.
- Open the command palette (*ctrl + shift + p*).
- Look for the "CMake: Configure" and select the compiler that best fit you architecture (probably *x86_amd64*).

### 8. Build your configuration and compile the OpenCV-C++ application.
- With the last operation, CMake should have created a .\build\ folder for you. If not you can execute this command from your VSCode Terminal: *cmake -B .\build\\*.
- Now your CMake is ready to build your code compiling it against the OpenCV lib following the configuration present in the build folder. To do so you can click on the "Build" button (the one with a gear close to it) in the VSCode's window lower bar or you can just type in the terminal: *cmake --build .\build\\*.

### 9. Execute the program.
- If you did everything good so far, you can now run your code. To do so press the PLAY button in the VSCode's window lower bar or type in the terminal: *.\build\Debug\\{Project_Name}.exe*.

### 10. Enjoy the Development of your C++ OpenCV application on VSCode for Windows :)